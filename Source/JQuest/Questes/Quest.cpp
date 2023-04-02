// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "Components/BillboardComponent.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillBorad"));

}

UObjCollection* AQuest::GetRootObjCollection() const
{
	return RootObjectiveCollection;
}

void AQuest::PopulateObjectives(UObjCollection* RootCollection)
{
}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();

	RootObjectiveCollection = ConstructRootObjectiveCollection();
	PopulateObjectives(RootObjectiveCollection);

	// TODO Active Root Objectives
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::ActiveObjective()
{
}

UObjCollection* AQuest::ConstructRootObjectiveCollection()
{
	UObjCollection* UC = nullptr;
	return UC;
}


