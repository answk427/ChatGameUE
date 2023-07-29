// Fill out your copyright notice in the Description page of Project Settings.


#include "FairyEntryInfo.h"

UFairyEntryInfo::UFairyEntryInfo()
{
	
}

void UFairyEntryInfo::AddSkin(FString SkinName, UTexture2D* SkinTexture)
{
	FairySkinMap.Add(SkinName, SkinTexture);
	
}

void UFairyEntryInfo::Init(FString BasicFairyName, TArray<FName> SkinNames, TArray<UTexture2D*> SkinTextures)
{
	FairyName = BasicFairyName;

	for(int i=0; i<SkinNames.Num(); ++i)
	{
		AddSkin(SkinNames[i].ToString(), SkinTextures[i]);
	}
}


