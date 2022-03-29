// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VR_BaseCharacter.generated.h"

class AVR_EnemyWeapon;

UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AVR_EnemyWeapon> StartingWeaponClass;

	UPROPERTY(EditDefaultsOnly)
		FName WeaponSocketName;

	UPROPERTY(EditDefaultsOnly)
		AVR_EnemyWeapon*CurrentWeapon;



public:
	// Sets default values for this character's properties
	AVR_BaseCharacter();

	UFUNCTION(BlueprintCallable)
		void StartFire();

	UFUNCTION(BlueprintCallable)
		void StopFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	


	

};
