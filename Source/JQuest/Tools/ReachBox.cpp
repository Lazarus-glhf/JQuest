// Fill out your copyright notice in the Description page of Project Settings.


#include "ReachBox.h"

#include "Components/BoxComponent.h"

// Sets default values
AReachBox::AReachBox()
	: bFinished(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TargetBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TargetBox"));
	TargetBox->SetBoxExtent(FVector(128, 128, 64));
	TargetBox->SetVisibility(true);
}

// Called when the game starts or when spawned
void AReachBox::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AReachBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
