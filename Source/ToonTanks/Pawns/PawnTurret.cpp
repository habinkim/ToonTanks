// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"
//#include "Components/CapsuleComponent.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	// GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() >= FireRange) 
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();

	Destroy();
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn)
	{
		return;
	}

	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}

	TTLOG(Warning, TEXT("Fire Condition Checked"));
	//UE_LOG(ToonTanks, Warning, TEXT("Fire Condition Checked"));
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}