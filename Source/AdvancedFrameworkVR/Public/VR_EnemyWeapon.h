// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VR_EnemyWeapon.generated.h"

class UStaticMeshComponent;
class UParticleSystem;

UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_EnemyWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVR_EnemyWeapon();

	void StartFire();

	void Stopfire();



protected:

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly)
		float ShotDistance;

	UPROPERTY(EditDefaultsOnly)
		float ShotDamage;

	float TimeBetweenShots;

	float LastFireTime;

	FTimerHandle TimerHandle_Autoshot;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = 0.1f))
		float RoundsPerMinute;


	//aquivoy

	UPROPERTY(EditDefaultsOnly)
	bool bDrawDebug;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* TracerEffect;

	UPROPERTY(EditDefaultsOnly)
		FName MuzzleSocketName;

	UPROPERTY(EditDefaultsOnly)
		FName TracerTargetName;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageType>  DamageType;

	void Fire();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


};
