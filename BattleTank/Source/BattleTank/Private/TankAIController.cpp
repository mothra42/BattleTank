// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
	
	//Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	//Fire if ready
	AimingComponent->Fire();
}