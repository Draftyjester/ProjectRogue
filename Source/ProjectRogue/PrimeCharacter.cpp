// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimeCharacter.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

// Sets default values
APrimeCharacter::APrimeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialize the Ability System Component.
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UPrimeAttributeSet>(TEXT("AttributeSet"));


	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

	

}

UAbilitySystemComponent* APrimeCharacter::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void APrimeCharacter::BeginPlay()
{
	Super::BeginPlay();

	//initialize attributes
	InitializeAttributes();
	
}

void APrimeCharacter::InitializeAttributes() {

}

// Called every frame
void APrimeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APrimeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

