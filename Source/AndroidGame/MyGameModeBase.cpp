// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase()
{
}

void AMyGameModeBase::SpawnBulletSpawner()
{
	
	BulletSpawner = GetWorld()->SpawnActor<ABulletSpawner>(ABulletSpawner::StaticClass());
}
