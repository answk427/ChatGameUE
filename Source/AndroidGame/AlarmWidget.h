// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AlarmWidget.generated.h"

/**
 * 
 */
UCLASS()
class ANDROIDGAME_API UAlarmWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//시간,분을 합쳐서 60*24 = 1440분으로 변환해 저장
	TArray<int> AlarmTimes;




};
