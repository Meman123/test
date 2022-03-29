// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VR_EnemyWeapon.generated.h"

class UStaticMeshComponent;

UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_EnemyWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVR_EnemyWeapon();

	void Fire();

	

protected:

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly)
	float ShotDistance;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


};
