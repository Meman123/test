// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_BaseCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include <VR_EnemyWeapon.h>
#include <VR_HealthComponent.h>

// Sets default values
AVR_BaseCharacter::AVR_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
	//HealthComponent = CreateDefaultSubobject<UVR_HealthComponent>(TEXT("HealthComponent"));

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

	if (IsValid(HealthComponent))
	{
		HealthComponent->OnHealthChanged.AddDynamic(this, &AVR_BaseCharacter::OnHealthChanged);
		HealthComponent->OnDeath.AddDynamic(this, &AVR_BaseCharacter::OnDeath);

	}
	
}

void AVR_BaseCharacter::StartFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartFire();
	}
}

void AVR_BaseCharacter::StopFire()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Stopfire();
	}
}

void AVR_BaseCharacter::OnHealthChanged(UVR_HealthComponent* HealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
}

void AVR_BaseCharacter::OnDeath(UVR_HealthComponent* HealthComp, AController* InstigatedBy, AActor* Killer)
{
	StopFire();
	GetMovementComponent()->StopMovementImmediately();
	this->SetActorEnableCollision(false);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}





