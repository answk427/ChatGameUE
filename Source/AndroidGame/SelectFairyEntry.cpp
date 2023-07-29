// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectFairyEntry.h"
#include "Components/TextBlock.h"
#include "Components/ScrollBox.h"
#include "Components/Image.h"
#include "FairyEntryInfo.h"

void USelectFairyEntry::SetText(FText Text)
{
	FairyName->SetText(Text);
}

void USelectFairyEntry::AddImage(UImage* Image, const FString& Name)
{
	Scroll_Fairy->AddChild(Image);
}

void USelectFairyEntry::AddImage(UTexture2D* Texture, const FString& Name)
{
	
	auto Img= NewObject<UImage>(this);

	Img->SetBrushFromTexture(Texture);
	Img->SetBrushSize(FVector2D(256.f, 256.f));
	
	Images.Add(Name, Img);

	//scroll 위젯에 이미지 추가
	Scroll_Fairy->AddChild(Img);
}

inline void USelectFairyEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UFairyEntryInfo* FairyInfo = Cast<UFairyEntryInfo>(ListItemObject);
	SetText(FText::FromString(FairyInfo->FairyName));

	auto FairySkins = FairyInfo->FairySkinMap;

	for(auto& Skin : FairySkins)
	{
		AddImage(Skin.Value, Skin.Key);
	}
}