// Copyright Epic Games, Inc. All Rights Reserved.

#include "AndroidGameGameMode.h"
#include "AndroidGameCharacter.h"

AAndroidGameGameMode::AAndroidGameGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AAndroidGameCharacter::StaticClass();	
}
