// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/TriggerVolume.h"
#include "MyBullet.generated.h"

UCLASS()
class ANDROIDGAME_API AMyBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBullet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* MyCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* MySprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 1.f;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
			
	void InitSpawnLocation(const FVector& SpawnLoc, const FVector& Dir, float NewSpeed);
	void InitOverlapped();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

