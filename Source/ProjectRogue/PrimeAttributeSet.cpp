// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimeAttributeSet.h"

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



void UPrimeAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPrimeAttributeSet, CurrentHealth, OldCurrentHealth);
}

void UPrimeAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPrimeAttributeSet, MaxHealth, OldMaxHealth);
}

void UPrimeAttributeSet::OnRep_Attack(const FGameplayAttributeData& OldAttack) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPrimeAttributeSet, Attack, OldAttack);
}

void UPrimeAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense) {
	GAMEPLAYATTRIBUTE_REPNOTIFY(UPrimeAttributeSet, Defense, OldDefense);
}

void UPrimeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimeAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimeAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimeAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UPrimeAttributeSet, Defense, COND_None, REPNOTIFY_Always);
}


