// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSpawner.h"

// Sets default values
ABulletSpawner::ABulletSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneComp);

	ConstructorHelpers::FClassFinder<AMyBullet> BulletC(TEXT("Blueprint'/Game/2DSideScroller/Blueprints/BP_MyBullet.BP_MyBullet_C'"));

	if(BulletC.Succeeded())
	{
		BulletClass = BulletC.Class;
	}

}

// Called when the game starts or when spawned
void ABulletSpawner::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.f, 50.f, 0.f));

	for(int i=0; i<500; ++i)
	{
		auto Bullet = GetWorld()->SpawnActor<AMyBullet>(BulletClass);
		Bullet->SetActorHiddenInGame(true);
		Bullet->SetActorEnableCollision(false);
		Bullet->SetActorTickEnabled(false);
		Bullets.Add(Bullet);
	}

	float Delay = 0.f;
	float MinRotate = 170.f;
	float MaxRotate = 350.f;

	for(int i=0; i<30; ++i)
	{
		Delay += 0.5f;
		MinRotate += 30.f;
		MaxRotate += 30.f;

		FTimerHandle TimerHandle;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([&, MinRotate, MaxRotate, Delay]()
		{

			StartCirclePattern(0.1f, 300.f, MinRotate, MaxRotate, 16);

			// TimerHandle 초기화
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		}), 1.f, false, Delay);


		
	}
	

}

// Called every frame
void ABulletSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABulletSpawner::StartCirclePattern(float Delay, float Speed, float MinRot, float MaxRot, float BulletCnt)
{
	float CurrentDelay = -Delay;
	float StrideRot = (MaxRot - MinRot) / BulletCnt;
	
	for(int i=0; i<BulletCnt; ++i)
	{
		CurrentDelay += Delay;
		float CurrentRot = MinRot + StrideRot * i;
		FRotator Rot(CurrentRot, 0.f, 0.f);
		DelaySpawnBullet(GetActorLocation(), Rot.Vector(), Speed, CurrentDelay);
	}
}

void ABulletSpawner::DelaySpawnBullet(const FVector& Loc, const FVector& Dir, float Speed, float Delay)
{
	FTimerHandle TimerHandle;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([&,Loc,Dir,Speed,Delay]()
	{

		SpawnBullet(Loc, Dir, Speed);

		// TimerHandle 초기화
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}), 1.f , false, Delay);
}


