// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VR_PatrolActor.generated.h"

class USplineComponent;

UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_PatrolActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVR_PatrolActor();

	USplineComponent * SplineComponent;

	FVector GetWorldLocationByIndex(const int32 Index) const;

	int32 GetLastIndex() const;



	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
