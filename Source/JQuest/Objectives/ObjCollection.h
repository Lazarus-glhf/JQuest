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

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UObjective* CurrentObj;

	UPROPERTY(BlueprintReadWrite)
	TArray<UObjective*> Objectives;
	/*
	 * �� Objective ��ӵ� Array
	 * @param obj ��ӵ� Objective
	 */
	UFUNCTION(BlueprintCallable)
	void AddObjective(UObjective* obj);

	UFUNCTION(BlueprintCallable)
	void CollectionOnCompleteEvent(UObjective* obj);
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
