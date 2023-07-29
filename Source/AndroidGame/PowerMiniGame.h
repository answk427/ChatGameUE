// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PowerMiniGame.generated.h"

/**
 * 
 */



UCLASS()
class ANDROIDGAME_API UPowerMiniGame : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(meta = (BindWidget))
	UBorder* BaseBorder;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* MyBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MainText;

	UPROPERTY(meta = (BindWidget))
	UButton* ReButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float EnemyPower = 0.1f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TouchPower = 0.1f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float StartPercent = 0.5f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float GoalPercent = 0.f;

	bool GameEnd = false;
		

	UFUNCTION(BlueprintCallable)
	void UserTouch();

	UFUNCTION(BlueprintCallable)
	void Init();


	void Success();

	void Fail();
};
