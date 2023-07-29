// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "StarForceCircle.generated.h"



UCLASS()
class ANDROIDGAME_API AStarForceCircle : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarForceCircle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* MiddleCircle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* MovableCircle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector OffsetVec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LimitX = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MiddleCircleRadius = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 1.f;

	bool CheckChance = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool CheckOverlap();

	float GetDiffCircles();

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintCallable)
	void StopCircle();
};
