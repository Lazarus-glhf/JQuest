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
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FText GetObjectiveName() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsComplete() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual bool GetIsActive() const;

	UFUNCTION(BlueprintCallable)
	virtual void ActiveObjective();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ObjectiveName;

	void SetObjectiveName(FText name);

	FOnCompleted OnCompleted;
private:
	bool bIsActive;
};
