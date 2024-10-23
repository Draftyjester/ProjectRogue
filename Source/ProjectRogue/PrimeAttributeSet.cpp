// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimeAttributeSet.h"
//if we ever do online stuff: #include "Net/UnrealNetwork.h"

UPrimeAttributeSet::UPrimeAttributeSet(): CurrentHealth(100.f), MaxHealth(100.f), Attack(10.f), Defense(5.f)
{

}

void UPrimeAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// Clamp CurrentHealth to MaxHealth
	if (Attribute == GetCurrentHealthAttribute())
	{
		// Ensure CurrentHealth does not exceed MaxHealth
		const float MaxHealthValue = MaxHealth.GetCurrentValue();
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxHealthValue);

	}
}


/*
*  For Online stuff if we ever do that as an example
* 
void UPrimeAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPrimeAttributeSet, CurrentHealth, OldCurrentHealth);
}


void UPrimeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimeAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
}

*/
