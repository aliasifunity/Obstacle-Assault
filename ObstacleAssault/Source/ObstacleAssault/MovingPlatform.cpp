// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString MyString = "This is my string";

	UE_LOG(LogTemp,Display,TEXT("Out put: %s"),*MyString);


 
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime )
{	
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation+(PlatformVelocity*DeltaTime);

	SetActorLocation(CurrentLocation);

	float DistanceMoved_1 = FVector3d::Dist(StartLocation, CurrentLocation);

	if(DistanceMoved_1>MovedDistance) 
	{		

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();		
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime )
{	
	 
	 AddActorLocalRotation(RotationVelocity * DeltaTime);

}

