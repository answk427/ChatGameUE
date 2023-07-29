// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameUI.h"

void UShootingGameUI::SetTimeText()
{
	MainText->SetText(FText::FromString(FString::FromInt(RemainingTime)));
}

void UShootingGameUI::StartTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);

	RemainingTime = 21;

	GetWorld()->GetTimerManager().SetTimer(TimerHandle,
		FTimerDelegate::CreateLambda(
			[&]()
			{
				RemainingTime -= 1;
				SetTimeText();
				
			}
	), 1.f, true, 1.f);
}

void UShootingGameUI::SearchPlayer()
{
	for (AShootingPlayer* Player : TActorRange<AShootingPlayer>(GetWorld()))
	{
		Player->DieDelegate.AddUObject(this, &UShootingGameUI::DieFunc);
	}
	
}

void UShootingGameUI::DieFunc()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	MainText->SetText(FText::FromString(TEXT("GameOver")));
}

void UShootingGameUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(RemainingTime<0)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		MainText->SetText(FText::FromString(TEXT("승리!")));
	}
	//GetWorld()->GetTimerManager().SetTimer(SwitchCameraTimerHandler,
	//	FTimerDelegate::CreateLambda(
	//		[&, Duration]()
	//{
	//	//Switch Other Character's Camerae
	//	SwitchDamagedCharacterCamera(Duration);
	//	UE_LOG(LogTemp, Error, TEXT("SwitchMultiCamera In Timer"));
	//}), 
	
	
}

void UShootingGameUI::NativeConstruct()
{
	Super::NativeConstruct();
	SearchPlayer();
	StartTimer();
}
