// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SLaserBeam.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class BASICTHIRD_API ASLaserBeam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASLaserBeam();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ParticleSystemComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
