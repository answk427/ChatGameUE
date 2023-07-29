// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBullet.h"
#include "BulletSpawner.generated.h"

UCLASS()
class ANDROIDGAME_API ABulletSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	USceneComponent* SceneComp;
	// Sets default values for this actor's properties
	ABulletSpawner();

	TArray<AMyBullet*> Bullets;

	TSubclassOf<AMyBullet> BulletClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnBullet(const FVector& Loc, const FVector& Dir, float Speed);
	void RetrieveBullet(AMyBullet* Bullet);


	void StartCirclePattern(float Delay, float Speed, float MinRot, float MaxRot, float BulletCnt);

	void DelaySpawnBullet(const FVector& Loc, const FVector& Dir, float Speed, float Delay);
};

inline void ABulletSpawner::RetrieveBullet(AMyBullet* Bullet)
{
	if (!IsValid(Bullet))
		return;

	Bullets.Add(Bullet);
}

inline void ABulletSpawner::SpawnBullet(const FVector& Loc, const FVector& Dir, float Speed)
{
	if (Bullets.Num() <= 0)
		return;

	auto Bullet = Bullets.Pop();
	Bullet->InitSpawnLocation(Loc, Dir, Speed);
}
