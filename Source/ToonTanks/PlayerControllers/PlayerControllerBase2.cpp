// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase2.h"

void APlayerControllerBase2::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}

	bShowMouseCursor = SetPlayerEnabled;
}