// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReachBox.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBoxOverlapDelegate);

UCLASS()
class JQUEST_API AReachBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReachBox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* TargetBox;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool bFinished;
};
