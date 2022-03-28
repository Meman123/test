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

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* GrenadeBody;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* GrenadeLever;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* GrenadePin;

protected:


public:

	UPROPERTY(BlueprintReadWrite, Category = "Grenade")
		bool bPinSacado;

	UPROPERTY(BlueprintReadWrite, Category = "Grenade")
		bool bDragCooldown;

	UPROPERTY(BlueprintReadWrite, Category = "Grenade")
		bool bReleased;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Grenade")
		float GrenadeExplosionTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grenade")
		UParticleSystem*ExplosionParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grenade")
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
