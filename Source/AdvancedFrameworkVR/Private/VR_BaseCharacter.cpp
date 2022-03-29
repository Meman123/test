// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_BaseCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include <VR_EnemyWeapon.h>

// Sets default values
AVR_BaseCharacter::AVR_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;

}



// Called when the game starts or when spawned
void AVR_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(StartingWeaponClass))
	{
		CurrentWeapon = GetWorld()->SpawnActor<AVR_EnemyWeapon>(StartingWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator);
		if (IsValid(CurrentWeapon))
		{
			CurrentWeapon->SetOwner(this);
			CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocketName);
		}
	}
	
}

void AVR_BaseCharacter::StartFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
}





