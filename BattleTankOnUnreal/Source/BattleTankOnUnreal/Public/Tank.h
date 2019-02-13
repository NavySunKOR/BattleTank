// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKONUNREAL_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UTankAimingComponent* TankAimingComponent = nullptr;


public:
	void AimAt(FVector TargetPos);
	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.0f; // TODO:specify proper speed of bullet velocity 1000m/s
	
};
