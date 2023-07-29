// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "SelectFairyEntry.generated.h"

/**
 * 
 */

class UTextBlock;
class UScrollBox;
class UImage;

UCLASS()
class ANDROIDGAME_API USelectFairyEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, UImage*> Images;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* FairyName;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* Scroll_Fairy;

	void SetText(FText Text);

	void AddImage(UImage* Image, const FString& Name);
	void AddImage(UTexture2D* Texture, const FString& Name);

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};


