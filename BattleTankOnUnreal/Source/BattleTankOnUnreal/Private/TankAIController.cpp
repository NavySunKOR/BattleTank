// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PossessedTank = GetControlledTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp,Log,TEXT("No AI possessed tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Found AI possessed tank! : %s"), *(PossessedTank->GetName()))
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player tank not spotted!"))
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Spotted player tank! : %s"), *(PlayerTank->GetName()))
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
	{
		return nullptr;
	}

	return Cast<ATank>(PlayerTank);
}