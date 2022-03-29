// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_BaseCharacter.h"

// Sets default values
AVR_BaseCharacter::AVR_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVR_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVR_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



