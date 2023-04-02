// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompleted, UObjective*, obj);

/**
 * 
 */
UCLASS()
class JQUEST_API UObjective : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FName GetObjectiveName() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsComplete() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsActive() const;

	UFUNCTION(BlueprintCallable)
	virtual void ActiveObjective();

	void SetObjectiveName(FName name);

	FOnCompleted OnCompleted;
private:
	FName ObjectiveName;

	bool bIsActive;
};
