// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_PatrolActor.h"
#include "Components/SplineComponent.h"

// Sets default values
AVR_PatrolActor::AVR_PatrolActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
}

FVector AVR_PatrolActor::GetWorldLocationByIndex(const int32 Index) const
{
	if (SplineComponent && Index <= GetLastIndex())
	{
		SplineComponent->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World);
	}
	return GetActorLocation();
}

int32 AVR_PatrolActor::GetLastIndex() const
{
	if (SplineComponent)
	{
		SplineComponent->GetNumberOfSplinePoints();
	}
	return 0;
}

// Called when the game starts or when spawned
void AVR_PatrolActor::BeginPlay()
{
	Super::BeginPlay();
	
}



