// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopUI.h"
#include "Engine/DataTable.h"
#include "DataTableStructures.h"
#include "Components/ListView.h"

UShopUI::UShopUI(const FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UDataTable> FairyTable(TEXT("DataTable'/Game/2DSideScroller/DataTables/FairyDatas.FairyDatas'"));

	if (FairyTable.Succeeded())
		FairyDataTable = FairyTable.Object;
}

void UShopUI::InitList()
{
	FairyList->ClearListItems();

	for(auto& Item : FairyItems)
	{
		FairyList->AddItem(Item);
	}
	
}

void UShopUI::InitFairyDatas()
{
	if (FairyDataTable == nullptr)
		return;
	
	TArray<FFairyData*> Datas;

	FairyDataTable->GetAllRows(TEXT("FairyDataTable"), Datas);
	
	for (auto Data : Datas)
	{
		UFairyEntryInfo* Item = NewObject<UFairyEntryInfo>();
		Item->Init(Data->FairyName.ToString(), Data->FairySkinName, Data->FairySkin);
		FairyItems.Add(Item);
	}

}

void UShopUI::NativeConstruct()
{
	Super::NativeConstruct();

	InitFairyDatas();
	InitList();
}
