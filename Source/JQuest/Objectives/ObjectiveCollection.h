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
	 * �� Objective ��ӵ� Array
	 * @param obj ��ӵ� Objective
	 */
	UFUNCTION(BlueprintCallable)
	void AddObjective(UObjective* obj);

	/*
	 * ������Ҫ��˳��ʱ��ֱ�ӱ��������ڵ����� Obj�����������ǵ� ActiveObjective()
	 * ����Ҫ��˳��ʱ������ HandleOrderRequired();
	 */
	virtual void ActiveObjective() override;

	virtual bool GetIsComplete() const override;
private:
	/* ���� Objectives �е�һ��δ��ɵ� Obj */
	UObjective* FindNexIncompleteObjective();

	void HandleOrderRequired();
};