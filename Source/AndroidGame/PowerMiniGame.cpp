// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerMiniGame.h"

void UPowerMiniGame::NativeConstruct()
{
	Super::NativeConstruct();
	Init();
	
}

void UPowerMiniGame::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (GameEnd)
		return;

	float CurrentPercent = MyBar->Percent;
	UE_LOG(LogTemp, Warning, TEXT("NativeTic CurrentPercent : %f"), CurrentPercent);
		

	float NewPercent = CurrentPercent + EnemyPower*InDeltaTime;

	if (NewPercent <= 0)
		NewPercent = 0.f;

	if (NewPercent >= 1.f)
		NewPercent = 1.f;

	MyBar->SetPercent(NewPercent);

	
		

	if (NewPercent == 1.f)
		Fail();
}

void UPowerMiniGame::UserTouch()
{
	if (GameEnd)
		return;

	float CurrentPercent = MyBar->Percent;
	float NewPercent = CurrentPercent + TouchPower;

	if (NewPercent < 0)
		NewPercent = 0.f;

	MyBar->SetPercent(NewPercent);

	if (NewPercent == GoalPercent)
	{
		UE_LOG(LogTemp, Warning, TEXT("GoalPercent zzz"));
		Success();
	}


	UE_LOG(LogTemp, Warning, TEXT("UserTouch"));
}

void UPowerMiniGame::Init()
{
	MyBar->SetPercent(StartPercent);
	GameEnd = false;
	MainText->SetText(FText::FromString(TEXT("터치하세요!")));
	ReButton->SetIsEnabled(false);
	ReButton->SetVisibility(ESlateVisibility::Collapsed);
}

void UPowerMiniGame::Success()
{
	MainText->SetText(FText::FromString(TEXT("성공!")));
	GameEnd = true;
}

void UPowerMiniGame::Fail()
{
	MainText->SetText(FText::FromString(TEXT("실패!")));
	GameEnd = true;
	ReButton->SetIsEnabled(true);
	ReButton->SetVisibility(ESlateVisibility::Visible);
}
