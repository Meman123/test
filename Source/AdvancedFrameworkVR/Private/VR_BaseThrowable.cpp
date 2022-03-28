// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_BaseThrowable.h"
#include "Kismet/GameplayStatics.h"



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

	GetWorld()->GetTimerManager().SetTimer(THDragCooldown, this, &AVR_BaseThrowable::DragCooldown, 0.2f, false);

	

    
	
}

// Called every frame
void AVR_BaseThrowable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPinSacado)
	{
		GetWorld()->GetTimerManager().SetTimer(THExplosion, this, &AVR_BaseThrowable::ExplosionSecuence, GrenadeExplosionTime, false);
	}

}


void AVR_BaseThrowable::DragCooldown()
{
	bDragCooldown = true;
}

void AVR_BaseThrowable::ExplosionSecuence()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, GetActorLocation());
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	TArray<AActor*> Ignored;
	UGameplayStatics::ApplyRadialDamage(GetWorld(), 100, GetActorLocation(), 500, UDamageType::StaticClass(), Ignored, this, nullptr, false, ECollisionChannel::ECC_Visibility);
	Destroy();

}





