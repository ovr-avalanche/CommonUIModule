// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "FrontendTypes/FrontendEnumTypes.h"
#include "Widget_ConfirmationScreen.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UITESTPROJECT_API UWidget_ConfirmationScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* CommonTextBlock_Title;
	
	UPROPERTY(meta = (BindWidget))
	UCommonTextBlock* CommonTextBlock_Message;

	UPROPERTY(meta = (BindWidget))
	class UDynamicEntryBox* DynamicEntryBox_Buttons;
	
};
