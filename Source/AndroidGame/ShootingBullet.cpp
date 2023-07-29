// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingBullet.h"

// Sets default values
AShootingBullet::AShootingBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*Direction.Set(1.f, 0.f, 0.f);

	MySprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MySprite1"));

	MySprite->OnComponentBeginOverlap.AddDynamic(this, &AShootingBullet::OverlapBegin);
	
	SetRootComponent(MySprite);*/

	
	
}

// Called when the game starts or when spawned
//void AShootingBullet::BeginPlay()
//{
//	Super::BeginPlay();
//
//	
//}
//
//void AShootingBullet::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
//	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	UE_LOG(LogTemp, Warning, TEXT("ShootingBullet OverlapBegin %hs"), __FUNCTION__);
//}
//
//// Called every frame
//void AShootingBullet::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	AddActorWorldOffset(Direction*Speed*DeltaTime);
//	
//}
//
