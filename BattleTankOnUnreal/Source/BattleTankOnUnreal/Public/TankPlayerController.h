// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKONUNREAL_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public: 
	ATank* GetControlledTank() const;
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	bool GetSightLineTrace(FVector& OutResult) const;
	void AimToCrosshairs();

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTranceRange = 1000000.0f;

	bool GetLookVectorHitLocation(FVector LookDir, FVector& HitPos) const;
};


