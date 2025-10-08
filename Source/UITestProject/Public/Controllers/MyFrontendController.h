// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyFrontendController.generated.h"

/**
 * 
 */
UCLASS()
class UITESTPROJECT_API AMyFrontendController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void OnPossess(APawn* aPawn) override;
	
};
