#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractableDoor.generated.h"

class UDoorInteractionComponent;

UCLASS()
class MYPROJECT4_API AInteractableDoor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AInteractableDoor();

protected:

	UPROPERTY(EditAnywhere, NoClear)
	UDoorInteractionComponent* DoorInteractionComponent;

};