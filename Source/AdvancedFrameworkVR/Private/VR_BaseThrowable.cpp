// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_BaseThrowable.h"

// Sets default values
AVR_BaseThrowable::AVR_BaseThrowable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent = CustomRootComponent;

	GrenadeBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GrenadeBody"));
	GrenadeBody->SetupAttachment(RootComponent);

	GrenadeLever= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GrenadeLever"));
	GrenadeLever->SetupAttachment(GrenadeBody);

	GrenadePin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GrenadePin"));
	GrenadePin->SetupAttachment(GrenadeBody);

	

}

// Called when the game starts or when spawned
void AVR_BaseThrowable::BeginPlay()
{
	Super::BeginPlay();
    Getsdasd
	
}

// Called every frame
void AVR_BaseThrowable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

