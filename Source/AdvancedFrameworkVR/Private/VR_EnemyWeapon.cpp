// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_EnemyWeapon.h"
#include "Components/StaticMeshComponent.h"
#include "kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "particles/ParticleSystemComponent.h"
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
	RoundsPerMinute = 600.0f;
	bDrawDebug = false;

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

		FVector ImpactPoint = TraceEnd;

		FHitResult Hit;
		if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, WEAPON_COLLISION, QueryParams))
		{

			AActor* HitActor = Hit.GetActor();
			UGameplayStatics::ApplyPointDamage(HitActor, ShotDamage, ShotDirection, Hit, MyOwner->GetInstigatorController(), MyOwner, DamageType);
			
			if (ImpactEffect)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
			}
			//DrawDebugLine(GetWorld(), EyeLocation, Hit.ImpactPoint, FColor::White, false, 1.0f, 0, 1.0f);

			ImpactPoint = Hit.ImpactPoint;
		}

		if (bDrawDebug)
		{
			DrawDebugLine(GetWorld(), EyeLocation, Hit.ImpactPoint, FColor::White, false, 1.0f, 0, 1.0f);
		}

		if (MuzzleFlash)
		{
			UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, WeaponMesh, MuzzleSocketName);
		}

		if (TracerEffect)
		{
			UParticleSystemComponent* tracerComponent = UGameplayStatics::SpawnEmitterAttached(TracerEffect, WeaponMesh, MuzzleSocketName);
			if (tracerComponent)
			{
				tracerComponent->SetVectorParameter(TracerTargetName, ImpactPoint);
			}
		}
	}
	LastFireTime = GetWorld()->TimeSeconds;
}

void AVR_EnemyWeapon::StartFire()
{

	float FirstDelay = FMath::Max(0.0f, LastFireTime + TimeBetweenShots - GetWorld()->TimeSeconds);
	GetWorldTimerManager().SetTimer(TimerHandle_Autoshot,this, &AVR_EnemyWeapon::Fire, TimeBetweenShots, 0.0f);
}

void AVR_EnemyWeapon::Stopfire()
{

	GetWorldTimerManager().ClearTimer(TimerHandle_Autoshot);
}


