// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompleted, UObjective*, obj);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, config = Engine)
class JQUEST_API UObjective : public UObject
{
	GENERATED_BODY()

public:
	// 任务名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ObjectiveName;

	// 任务计时
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeCount;

	// 任务分数
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ObjectiveGrade;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetObjectiveName() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsComplete() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsActive() const;

	UFUNCTION(BlueprintCallable)
	virtual void ActiveObjective();

	/*
	 * @param name 任务名称
	 * @param Time 任务计时
	 * @param Grade 任务分数
	 */
	void SetObjectiveBaseProperty(FText Name, float Time, float Grade);

	FOnCompleted OnCompleted;
private:
	bool bIsActive;
};
