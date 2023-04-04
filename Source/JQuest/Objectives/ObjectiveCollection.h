// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "ObjectiveCollection.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API UObjectiveCollection : public UObjective
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	bool bOrderRequired;

	UPROPERTY(BlueprintReadWrite)
	TArray<UObjective*> Objectives;

	UFUNCTION()
	void CollectionOnCompleteEvent(UObjective* obj);

	/*
	 * 将 Objective 添加到 Array
	 * @param obj 添加的 Objective
	 */
	UFUNCTION(BlueprintCallable)
	void AddObjective(UObjective* obj);

	/*
	 * 当不需要按顺序时，直接遍历数组内的所有 Obj，并调用它们的 ActiveObjective()
	 * 当需要按顺序时，调用 HandleOrderRequired();
	 */
	virtual void ActiveObjective() override;

	virtual bool GetIsComplete() const override;
private:
	/* 查找 Objectives 中第一个未完成的 Obj */
	UObjective* FindNexIncompleteObjective();

	void HandleOrderRequired();
};