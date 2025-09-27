// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITESTPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void OnPossess(APawn* aPawn) override;
	
};
