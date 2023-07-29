// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "ShootingPlayer.h"
#include "EngineUtils.h"
#include "ShootingGameUI.generated.h"

/**
 * 
 */
UCLASS()
class ANDROIDGAME_API UShootingGameUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MainText;

	int RemainingTime = 20.f;

	FTimerHandle TimerHandle;

	void SetTimeText();
	void StartTimer();
	void SearchPlayer();

	UFUNCTION()
	void DieFunc();
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual void NativeConstruct() override;


};
