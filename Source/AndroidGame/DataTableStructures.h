// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "DataTableStructures.generated.h"

USTRUCT()
struct FFairyData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Fairy)
	FName FairyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Skin)
	TArray<FName> FairySkinName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Skin)
	TArray<UTexture2D*> FairySkin;
};

/**
 * 
 */
UCLASS()
class ANDROIDGAME_API UDataTableStructures : public UObject
{
	GENERATED_BODY()

	
};
