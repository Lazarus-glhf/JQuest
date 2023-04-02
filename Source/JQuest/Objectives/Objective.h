// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Objective.generated.h"

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

private:
	FName ObjectiveName;

	bool bIsActive;
};
