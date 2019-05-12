// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RotationSpeed)
{
	//use the yaw to turn the turret
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1.0, 1.0);
	auto YawChange = RotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewYaw = RelativeRotation.Yaw + YawChange;
	SetRelativeRotation(FRotator(0, NewYaw, 0));
}

