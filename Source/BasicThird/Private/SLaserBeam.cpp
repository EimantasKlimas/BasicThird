// Fill out your copyright notice in the Description page of Project Settings.


#include "SLaserBeam.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASLaserBeam::ASLaserBeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("CubeComponent");
	MeshComponent->SetCollisionProfileName("Laser Beam");
	RootComponent = MeshComponent;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComponent");
	ParticleSystemComponent->SetupAttachment(MeshComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->InitialSpeed = 1000.0f;
	MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ASLaserBeam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASLaserBeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

