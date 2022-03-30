// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VR_BaseCharacter.generated.h"

class UVR_HealthComponent;

class AVR_EnemyWeapon;

UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

	

public:
	// Sets default values for this character's properties
	AVR_BaseCharacter();


	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AVR_EnemyWeapon> StartingWeaponClass;

	UPROPERTY(EditDefaultsOnly)
		FName WeaponSocketName;

	UPROPERTY(EditDefaultsOnly)
		AVR_EnemyWeapon* CurrentWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UVR_HealthComponent* HealthComponent;

	UFUNCTION(BlueprintCallable)
		void StartFire();

	UFUNCTION(BlueprintCallable)
		void StopFire();

	UFUNCTION()
		void OnHealthChanged(UVR_HealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void OnDeath(UVR_HealthComponent* HealthComp, class AController* InstigatedBy, AActor* Killer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	


	

};
