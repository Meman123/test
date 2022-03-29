// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VR_BaseCharacter.h"
#include "VR_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_Enemy : public AVR_BaseCharacter
{
	GENERATED_BODY()



		virtual FVector GetPawnViewLocation() const override;
};
