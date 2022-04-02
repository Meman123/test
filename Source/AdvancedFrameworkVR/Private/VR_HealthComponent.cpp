// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_HealthComponent.h"

// Sets default values for this component's properties
UVR_HealthComponent::UVR_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	DefaultHealth = 100.0f;
	bDied = false;
	
	
	// ...
}


// Called when the game starts
void UVR_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = DefaultHealth;

	AActor* ActorOwner = GetOwner();
	if (IsValid(ActorOwner))
	{
		ActorOwner->OnTakeAnyDamage.AddDynamic(this, &UVR_HealthComponent::HandleTakeAnyDamage);
	}

	if (bDied)
	{
		return;
	}
	
}

void UVR_HealthComponent::HandleTakeAnyDamage( AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.f)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, DefaultHealth);
	OnHealthChanged.Broadcast(this, CurrentHealth, Damage, DamageType, InstigatedBy, DamageCauser);

	if (CurrentHealth == 0.0f)
	{
		bDied = true;
		OnDeath.Broadcast(this, InstigatedBy, DamageCauser);
	}

}

