// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

UCLASS()
class MYPROJECT4_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

	//return wether it is active or not the pickup
	UFUNCTION(BlueprintPure, Category = "PickUp")
	bool IsActive();

	//allow other classes to safely change if pickup is active or not
	UFUNCTION(BlueprintCallable, Category = "PickUp")
	void SetActive(bool NewPickUpState);

	//function to call when pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

	//return mesh for pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickUpMesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//true when pickup can be used and false when it is deactivated
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	//static mesh to represent pickup in level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PickUp", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickUpMesh;
};
