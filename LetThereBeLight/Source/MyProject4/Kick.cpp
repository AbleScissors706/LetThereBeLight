// Fill out your copyright notice in the Description page of Project Settings.


#include "Kick.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UKick::UKick()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}


// Called when the game starts
void UKick::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UKick::Kick_Implementation()
{
	FHitResult Hit;

	const FVector Start = GetComponentLocation();
	FVector End = Start + GetComponentRotation().Vector() * TraceDistance;

	FCollisionQueryParams TraceParams;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	if (bHit)
	{
		UStaticMeshComponent* MeshComponent = Cast<UStaticMeshComponent>(Hit.GetActor()->GetRootComponent());
		if (MeshComponent && Hit.GetActor()->IsRootComponentMovable())
		{
			DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 2.0f);
			FVector Forward = this->GetForwardVector();
			MeshComponent->AddImpulse(Forward * ImpulseForce * MeshComponent->GetMass());
		}
	}
}


// Called every frame
void UKick::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

