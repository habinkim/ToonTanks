// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase2.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase2 : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool SetPlayerEnabled);
	
};
