// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PrimeAttributeSet.generated.h"

//macros to declare attributes
# define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class PROJECTROGUE_API UPrimeAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	//constructor
	UPrimeAttributeSet();

	//current Health
	UPROPERTY(BlueprintReadOnly, Category = "Health")//, ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UPrimeAttributeSet, CurrentHealth)

	//Max Health
	UPROPERTY(BlueprintReadOnly, Category = "Health")//, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UPrimeAttributeSet, MaxHealth)

	//Attack
	UPROPERTY(BlueprintReadOnly, Category = "Attack")//, ReplicatedUsing = OnRep_Attack)
	FGameplayAttributeData Attack;
	ATTRIBUTE_ACCESSORS(UPrimeAttributeSet, Attack)

	//Defense
	UPROPERTY(BlueprintReadOnly, Category = "Defense")//, ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UPrimeAttributeSet, Defense)

protected:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;


/*
*  For Online stuff if we ever do that as an example
* 
	
	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);
*/

};
