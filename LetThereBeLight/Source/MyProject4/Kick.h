// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Kick.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT4_API UKick : public USceneComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UKick();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Kick")
	void Kick();
	void Kick_Implementation();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere, Category = "Kick")
	float TraceDistance = 1000.0f;
	UPROPERTY(EditAnywhere, Category = "Kick")
	float ImpulseForce = 50.0f;
		
};
