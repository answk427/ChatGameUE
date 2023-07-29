// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FairyEntryInfo.h"
#include "ShopUI.generated.h"

/**
 * 
 */
class UTextBlock;
class UListView;
class UDataTable;

UCLASS()
class ANDROIDGAME_API UShopUI : public UUserWidget
{
	GENERATED_BODY()

	TArray<UFairyEntryInfo*> FairyItems;

public:
	UShopUI(const FObjectInitializer &ObjectInitializer);

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CategoryText;

	UPROPERTY(meta = (BindWidget))
	UListView* FairyList;

	UPROPERTY()
	UDataTable* FairyDataTable;

	void InitList();

	void InitFairyDatas();

protected:
	virtual void NativeConstruct() override;
};
