// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FairyEntryInfo.generated.h"

/**
 * 
 */
UCLASS()
class ANDROIDGAME_API UFairyEntryInfo : public UObject
{
	GENERATED_BODY()

	UFairyEntryInfo();

public:
	UPROPERTY()
	FString FairyName;


	UPROPERTY()
	TMap<FString, UTexture2D*> FairySkinMap;

	void AddSkin(FString SkinName, UTexture2D* SkinTexture);

	void Init(FString BasicFairyName, TArray<FName> SkinNames, TArray<UTexture2D*> SkinTextures);
};
