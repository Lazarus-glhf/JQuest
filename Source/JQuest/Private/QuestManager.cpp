// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(World, AQuest::StaticClass(), Quests);
	}
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

