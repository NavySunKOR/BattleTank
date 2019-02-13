// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

void UTankAimingComponent::AimAt(FVector AimPos, float LaunchSpeed)
{
	if (!Barrel) { return;}
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		AimPos,
		LaunchSpeed,
		false,
		0,
		0, //추후 탄낙 별도 적용 시 수정
		ESuggestProjVelocityTraceOption::DoNotTrace //탄환 따라가는 카메라 생성 시 추가.
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveAimPoint(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s "),*TankName, *AimDirection.ToString());
	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * Barrel)
{
	this->Barrel = Barrel;
}

void UTankAimingComponent::MoveAimPoint(FVector AimDirection)
{
	//Get Look Rotation To AimDirection
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotation - BarrelRotation;

	UE_LOG(LogTemp,Warning,TEXT("%s 's AimAsRotation : %s , BarrelRotation : %s "),*GetOwner()->GetName(),*AimAsRotation.ToString(),*BarrelRotation.ToString())

	//MoveTurret yaw
	//MoveBarrel pitch

}


