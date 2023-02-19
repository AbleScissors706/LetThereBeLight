// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "KeyPickUp.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT4_API AKeyPickUp : public APickUp
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKeyPickUp();

	//override the WasCollected function - use implementation because its blueprintnative 
	void WasCollected_Implementation() override;
	
};
