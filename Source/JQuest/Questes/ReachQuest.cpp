// Fill out your copyright notice in the Description page of Project Settings.


#include "ReachQuest.h"
#include "JQuest/Objectives/ObjReachDestination.h"

void AReachQuest::BeginPlay()
{
	Super::BeginPlay();
}

void AReachQuest::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (QuestRunningTime > 0 && bIsQuestRunning)
	{
		QuestRunningTime -= DeltaSeconds;
	}
}

UObjectiveCollection* AReachQuest::ConstructRootObjectiveCollection()
{
	UObjectiveCollection* UC = NewObject<UObjectiveCollection>(this);

	UC->bOrderRequired = true;
	UC->ObjectiveName = FText(FText::FromString("Long way from home"));

	UC->ActiveQuestDelegate.BindUObject(this, &AReachQuest::HandleQuestActiveEvent);
	UC->CompleteQuestDelegate.BindUObject(this, &AReachQuest::HandleQuestCompleteEvent);

	return UC;
}

void AReachQuest::HandleQuestActiveEvent(UObjective* obj)
{
	bIsQuestRunning = true;
	CurrentObjName = obj->GetObjectiveName();
	QuestRunningTime = obj->TimeCount;
	QuestGrade = obj->ObjectiveGrade;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ("ReachQuest: Activate New Quest Called"));
}

void AReachQuest::HandleQuestCompleteEvent()
{
	bIsQuestRunning = false;
	if (QuestRunningTime > 0)
	{
		FinalGrade += QuestGrade;
	}
	if (RootObjectiveCollection->GetIsComplete())
	{
		CurrentObjName = FText::FromString("Quests Completed");
	}
}

void AReachQuest::AddReachQuestObject()
{
	UObjReachDestination* Obj = NewObject<UObjReachDestination>(this);

	Obj->SetObjectiveBaseProperty(QuestName, QuestTime, QuestGrade);
	Obj->DestinationBox = QuestTrigger;

	QuestObjectives.Add(Obj);
}

void AReachQuest::RemoveQuestObject()
{
	if (RemoveQuestIndex < QuestObjectives.Num())
	{
		QuestObjectives.RemoveAt(RemoveQuestIndex);
	}
}

void AReachQuest::PopulateObjectives(UObjectiveCollection* RootCollection)
{
	for (UObjective* Obj : QuestObjectives)
	{
		RootObjectiveCollection->AddObjective(Obj);
	}
}
