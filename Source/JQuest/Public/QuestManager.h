// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JQuest/Objectives/ObjCollection.h"
#include "JQuest/Questes/Quest.h"
#include "QuestManager.generated.h"

UCLASS()
class JQUEST_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

	UPROPERTY()
	TArray<AActor*> Quests;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Quest UI")
	FText CurrentQuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Colleciton")
	UObjCollection* ObjCollection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
