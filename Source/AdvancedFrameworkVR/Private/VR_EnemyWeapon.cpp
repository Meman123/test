// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_EnemyWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include <AdvancedFrameworkVR/AdvancedFrameworkVR.h>

// Sets default values
AVR_EnemyWeapon::AVR_EnemyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = WeaponMesh;

	ShotDistance = 10000.0f;
	ShotDamage = 20.0f;
}

// Called when the game starts or when spawned
void AVR_EnemyWeapon::BeginPlay()
{
	Super::BeginPlay();

	TimeBetweenShots = 60 / RoundsPerMinute;
	
}



void AVR_EnemyWeapon::Fire()
{

	AActor* MyOwner = GetOwner();
	if (MyOwner)
	{
		FVector EyeLocation;
		FRotator EyeRotation;
		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector ShotDirection = EyeRotation.Vector();

		FVector TraceEnd = EyeLocation + (ShotDirection * ShotDistance);

		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(MyOwner);
		QueryParams.AddIgnoredActor(this);
		QueryParams.bTraceComplex = true;

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, WEAPON_COLLISION, QueryParams))
		{

			AActor* HitActor = Hit.GetActor();
			UGameplayStatics::ApplyPointDamage(HitActor, ShotDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), MyOwner, DamageType);
			DrawDebugLine(GetWorld(), EyeLocation, Hit.ImpactPoint, FColor::White, false, 1.0f, 0, 1.0f);

		}

	}
	
}

void AVR_EnemyWeapon::StartFire()
{
	GetWorldTimerManager().SetTimer(TimerHandle_Autoshot,this, &AVR_EnemyWeapon::Fire, TimeBetweenShots, 0.0f);
}

void AVR_EnemyWeapon::Stopfire()
{
}


