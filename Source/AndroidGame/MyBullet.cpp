// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBullet.h"
#include "BulletSpawner.h"
#include "MyGameModeBase.h"
#include "ShootingPlayer.h"
#include "GameFramework/Character.h"

// Sets default values
AMyBullet::AMyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyCollision = CreateDefaultSubobject<USphereComponent>(TEXT("RootComp"));
	RootComponent = MyCollision;

	

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComp"));
	MySprite->SetupAttachment(RootComponent);

	Direction.Set(1.f, 0.f, 0.f);
}

void AMyBullet::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if(Cast<ATriggerVolume>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorName : %s, Func %hs, Other Actor : %s, Other Component : %s"), *GetName(),__FUNCTION__, *OtherActor->GetName(), *OverlappedComponent->GetName());
		UE_LOG(LogTemp, Warning, TEXT("InitOverlap"));
		InitOverlapped();
		return;
	}

	auto Player = Cast<AShootingPlayer>(OtherActor);
	if (Player != nullptr)
	{
		InitOverlapped();
		Player->DiePlayer();
	}
	
}

// Called when the game starts or when spawned
void AMyBullet::BeginPlay()
{
	Super::BeginPlay();
	MyCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyBullet::OverlapBegin);
}

// Called every frame
void AMyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(Direction*Speed*DeltaTime);
}

void AMyBullet::InitSpawnLocation(const FVector& SpawnLoc, const FVector& Dir, float NewSpeed)
{
	SetActorLocation(SpawnLoc);
	Direction = Dir.GetSafeNormal();
	Speed = NewSpeed;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);

	UE_LOG(LogTemp, Warning, TEXT("Actor : %s, Loc : %s, Dir : %s, Speed : %f"), *GetName(), *GetActorLocation().ToString(), *Direction.ToString(), Speed);
}

void AMyBullet::InitOverlapped()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	SetActorLocation(FVector::ZeroVector);

	auto BulletSpawner = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode())->BulletSpawner;
	if (BulletSpawner == nullptr)
		return;

	BulletSpawner->RetrieveBullet(this);
}
