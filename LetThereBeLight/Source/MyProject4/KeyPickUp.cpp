// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyPickUp.h"
#include "PickUp.h"

//set default value
AKeyPickUp::AKeyPickUp()
{
	GetMesh()->SetSimulatePhysics(true); 
}

void AKeyPickUp::WasCollected_Implementation()
{
	//use base pickup behaviour
	Super::WasCollected_Implementation();

	//destroy key
	Destroy();
}
