// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FrontendCommonButtonBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UITESTPROJECT_API UFrontendCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetButtonText(FText InTex);
	
private:

	//-----from UUserWidget-----------------//
	virtual void NativePreConstruct() override; // called when making changes in the editor in the widget blueprint
	//-----from UUserWidget-----------------//
	
	//------------bound widgets-----------------//
	UPROPERTY(meta = (BindWidgetOptional))
	class UCommonTextBlock* CommonTextBlock_ButtonText;
	//------------bound widgets-----------------//

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Button", meta = (AllowPrivateAccess = "true"))
	FText ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Button", meta = (AllowPrivateAccess = "true"))
	bool bUseUpperCaseForButtonText = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Button", meta = (AllowPrivateAccess = "true"))
	FText ButtonDescriptionText; 

};
