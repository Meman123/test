// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_EnemyWeapon.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVR_EnemyWeapon::AVR_EnemyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = WeaponMesh;
}

// Called when the game starts or when spawned
void AVR_EnemyWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}



