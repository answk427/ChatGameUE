// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "ShootingBullet.generated.h"

UCLASS()
class ANDROIDGAME_API AShootingBullet : public AActor
{
	GENERATED_BODY()

	

public:	
	// Sets default values for this actor's properties
	AShootingBullet();

	
//	UPROPERTY(BlueprintReadWrite, BlueprintReadWrite)
//	UPaperSpriteComponent* MySprite;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FVector Direction;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	float Speed = 1.f;
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//	UFUNCTION()
//	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	void InitSpawnLocation(const FVector& SpawnLoc, const FVector& Dir, float NewSpeed);
//};
//
//inline void AShootingBullet::InitSpawnLocation(const FVector& SpawnLoc, const FVector& Dir, float NewSpeed)
//{
//	SetActorLocation(SpawnLoc);
//	Direction = Dir.GetSafeNormal();
//	Speed = NewSpeed;
};
