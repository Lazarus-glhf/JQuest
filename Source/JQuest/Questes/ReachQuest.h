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

	// 任务名称
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	FText QuestName;

	// 完成任务计时
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	float QuestTime;

	UPROPERTY(BlueprintReadOnly)
	float QuestRunningTime;

	// 任务分数
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest")
	float QuestGrade;

	// 最终分数
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Grade")
	float FinalGrade = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Remove Quest")
	uint8 RemoveQuestIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manage Quest | Create Quest | Create ReachQuest")
	class AReachBox* QuestTrigger;

	// 添加一个抵达目的地类型的任务
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Create ReachQuest")
	void AddReachQuestObject();

	// 删除下标为 RemoveQuestIndex 的任务
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Remove Quest")
	void RemoveQuestObject();

	UFUNCTION()
	void HandleQuestActiveEvent(UObjective* obj);

	UFUNCTION()
	void HandleQuestCompleteEvent();

private:
	// 任务是否进行中
	bool bIsQuestRunning = false;

	virtual void PopulateObjectives(UObjectiveCollection* RootCollection) override;

	virtual UObjectiveCollection* ConstructRootObjectiveCollection() override;
};