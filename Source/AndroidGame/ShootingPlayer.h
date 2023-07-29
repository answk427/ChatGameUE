// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"


#include "ShootingPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDie);

UCLASS()
class ANDROIDGAME_API AShootingPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShootingPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* CharacterSprite;

	UPROPERTY(EditAnywhere)
	APawn* CameraPawn = nullptr;

	UPROPERTY(EditAnywhere)
	float Speed = 10.f;

	FOnDie DieDelegate;

	void DiePlayer();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveLeftRight(float InputVal);
	void MoveUpDown(float InputVal);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
