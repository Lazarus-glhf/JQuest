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
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bOrderRequired;

	UPROPERTY(BlueprintReadWrite)
	TArray<UObjective*> Objectives;

	virtual void ActiveObjective() override;

private:
	UObjective* FindNexIncompleteObjective();
};
