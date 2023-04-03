// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "ObjCollection.generated.h"

/**
 * 
 */
UCLASS()
class JQUEST_API UObjCollection : public UObjective
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	bool bOrderRequired;

	/*UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	FName ObjectiveName;*/

	UPROPERTY(BlueprintReadWrite)
	TArray<UObjective*> Objectives;

	UFUNCTION()
	void OnCompleteEvent(UObjective* obj);

	UFUNCTION(BlueprintCallable)
	void AddObjective(UObjective* obj);

	virtual void ActiveObjective() override;

	virtual bool GetIsComplete() const override;
private:
	UObjective* FindNexIncompleteObjective();

	void HandleOrderRequired();
};
