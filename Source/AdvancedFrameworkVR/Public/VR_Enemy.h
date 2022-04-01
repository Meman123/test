// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VR_BaseCharacter.h"
#include "VR_Enemy.generated.h"

class AVR_PatrolActor;

/**
 * 
 */
UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_Enemy : public AVR_BaseCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AVR_PatrolActor* PatrolActorReference;



	virtual FVector GetPawnViewLocation() const override;
};
