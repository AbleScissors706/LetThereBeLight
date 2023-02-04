// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = _RootComponent;

	LightSwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LIGHT!!"));
	LightSwitchMesh->SetupAttachment(RootComponent);

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light Bulb"));
	Light->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();

	Light->SetIntensity(0); 
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::InteractWithMe()
{
	UE_LOG(LogTemp, Warning, TEXT("You have INTERACTED!!"));

	if (bIsOn)
	{
		Light->SetIntensity(0);
		bIsOn = false;
	} 
	else
	{
		Light->SetIntensity(10000);
		bIsOn = true;
	}
}

