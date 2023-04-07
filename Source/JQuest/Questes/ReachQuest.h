// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "ReachQuest.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API AReachQuest : public AQuest
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Manage Quest")
	TArray<UObjective*> QuestObjectives;

	// ��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	FText QuestName;

	// ��������ʱ
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	float QuestTime;

	UPROPERTY(BlueprintReadOnly)
	float QuestRunningTime;

	// �������
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	float QuestGrade;

	// ���շ���
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Grade")
	float FinalGrade = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Remove Quest")
	uint8 RemoveQuestIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest | Create ReachQuest")
	class AReachBox* QuestTrigger;

	// ���һ���ִ�Ŀ�ĵ����͵�����
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Create ReachQuest")
	void AddReachQuestObject();

	// ɾ���±�Ϊ RemoveQuestIndex ������
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Remove Quest")
	void RemoveQuestObject();

	UFUNCTION()
	void HandleQuestActiveEvent(UObjective* obj);

	UFUNCTION()
	void HandleQuestCompleteEvent();

private:
	// �����Ƿ������
	bool bIsQuestRunning = false;

	virtual void PopulateObjectives(UObjectiveCollection* RootCollection) override;

	virtual UObjectiveCollection* ConstructRootObjectiveCollection() override;
};