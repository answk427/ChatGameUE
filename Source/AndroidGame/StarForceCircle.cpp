// Fill out your copyright notice in the Description page of Project Settings.


#include "StarForceCircle.h"

// Sets default values
AStarForceCircle::AStarForceCircle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OffsetVec.Set(1.f, 0.f, 0.f);

	MiddleCircle = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MiddleCircle"));
	MovableCircle = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MovableCircle"));
}

// Called when the game starts or when spawned
void AStarForceCircle::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AStarForceCircle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovableCircle->AddLocalOffset(OffsetVec * Speed);

	float CurrentX = MovableCircle->GetRelativeLocation().X;

	if (FMath::Abs(CurrentX) >= LimitX)
	{
		OffsetVec = -OffsetVec;
	}
		

	//MovableCircle->AddLocalRotation(FRotator(1.f, 0.f, 0.f));
	FRotator OffsetRot(1.f, 0.f, 0.f);
	FTransform tr(OffsetRot, OffsetVec);

	//MovableCircle->AddLocalTransform(tr);
	//UE_LOG(LogTemp, Warning, TEXT("MovableCircle RelativeLoc: %s"), *MovableCircle->GetRelativeLocation().ToString());
			
}

bool AStarForceCircle::CheckOverlap()
{
	if (!CheckChance)
		return false;

	CheckChance = false;

	float diffX = FMath::Abs(MiddleCircle->GetComponentLocation().X - MovableCircle->GetComponentLocation().X);
	UE_LOG(LogTemp, Warning, TEXT("CheckOverlap diffX : %f"), diffX);

	
	if (diffX <= MiddleCircleRadius)
		return true;

	return false;
}

float AStarForceCircle::GetDiffCircles()
{
	return 0.f;
}

void AStarForceCircle::Init()
{
	CheckChance = true;

	Speed = 1.f;

	float RandomBool = FMath::FRandRange(0.f, 100.f);
	if (RandomBool < 50.0f)
		OffsetVec = -OffsetVec;
	

	float RandomX = FMath::FRandRange(-LimitX, LimitX);
	FVector CurrentLoc = MovableCircle->GetRelativeLocation();
	CurrentLoc.X = RandomX;
	MovableCircle->SetRelativeLocation(CurrentLoc);
}

void AStarForceCircle::StopCircle()
{
	Speed = 0.f;
}

