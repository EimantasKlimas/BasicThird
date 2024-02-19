// Fill out your copyright notice in the Description page of Project Settings.


#include "sPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AsPlayerCharacter::AsPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	SpringArmComponent->bUsePawnControlRotation = true;
}

void AsPlayerCharacter::MoveForward(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), value);
}

void AsPlayerCharacter::TurnRight(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, value);
}

void AsPlayerCharacter::PrimaryAttack()
{
	FVector HeadLocation = GetMesh()->GetSocketLocation("head");
	FTransform SpawnTM = FTransform(GetControlRotation(), HeadLocation);
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParameters);
}

// Called when the game starts or when spawned
void AsPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AsPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AsPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AsPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("TurnRight", this, &AsPlayerCharacter::TurnRight);

	PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AsPlayerCharacter::PrimaryAttack);

}

