// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "VR_BaseThrowable.generated.h"


UCLASS()
class ADVANCEDFRAMEWORKVR_API AVR_BaseThrowable : public AActor
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* CustomRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* GrenadeBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* GrenadeLever;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* GrenadePin;

protected:

	FTimerHandle THDragCooldown;

	FTimerHandle THExplosionSecuence;

	FTimerHandle THExplosion;

	UFUNCTION()
		void DragCooldown();

	UFUNCTION()
		void ExplosionSecuence();

	
	


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultVariables")
		bool bPinSacado;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultVariables")
		bool bDragCooldown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "DefaultVariables")
		bool bReleased;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Grenade Setup")
		float GrenadeExplosionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grenade Setup")
		UParticleSystem*ExplosionParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grenade Setup")
		USoundCue*ExplosionSound;


public:	
	// Sets default values for this actor's properties
	AVR_BaseThrowable();

	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
