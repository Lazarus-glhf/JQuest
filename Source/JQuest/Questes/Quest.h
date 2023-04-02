// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JQuest/Objectives/ObjCollection.h"
#include "Quest.generated.h"

UCLASS()
class JQUEST_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBillboardComponent* Billboard;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UObjCollection* GetRootObjCollection() const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	UObjCollection* RootObjectiveCollection;
	
	virtual UObjCollection* ConstructRootObjectiveCollection();
	virtual void PopulateObjectives(UObjCollection* RootCollection);
};
