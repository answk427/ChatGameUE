// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingPlayer.h"

// Sets default values
AShootingPlayer::AShootingPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("MyCollision"));
	SetRootComponent(SphereCollision);

	CharacterSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Character"));
	CharacterSprite->SetupAttachment(GetRootComponent());
}

void AShootingPlayer::DiePlayer()
{
	GetWorld()->GetFirstPlayerController()->Possess(CameraPawn);
	DieDelegate.Broadcast();
	Destroy();
}

// Called when the game starts or when spawned
void AShootingPlayer::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->SetViewTarget(CameraPawn);
}

void AShootingPlayer::MoveLeftRight(float InputVal)
{
	UE_LOG(LogTemp, Warning, TEXT("%hs, Value : %f"), __FUNCTION__, InputVal);
	//AddMovementInput(FVector(1.f, 0.f, 0.f), InputVal);
	AddActorWorldOffset(FVector(1.f, 0.f, 0.f)*InputVal*Speed);
}

void AShootingPlayer::MoveUpDown(float InputVal)
{
	UE_LOG(LogTemp, Warning, TEXT("%hs, Value : %f"), __FUNCTION__, InputVal);
	//AddMovementInput(FVector(0.f, 0.f, 1.f), InputVal);
	AddActorWorldOffset(FVector(0.f, 0.f, 1.f)*InputVal*Speed);
}

// Called every frame
void AShootingPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootingPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShootingPlayer::MoveLeftRight);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &AShootingPlayer::MoveUpDown);
	
}

