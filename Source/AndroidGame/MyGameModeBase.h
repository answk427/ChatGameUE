// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BulletSpawner.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ANDROIDGAME_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameModeBase();

	ABulletSpawner* BulletSpawner = nullptr;

	UFUNCTION(BlueprintCallable)
	void SpawnBulletSpawner();
};
