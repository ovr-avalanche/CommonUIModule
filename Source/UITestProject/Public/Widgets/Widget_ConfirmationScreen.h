// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "FrontendTypes/FrontendEnumTypes.h"
#include "Widget_ConfirmationScreen.generated.h"

USTRUCT(BlueprintType)
struct FConfirmScreenButtonInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EConfirmScreenButtonType ConfirmScreenButtonType = EConfirmScreenButtonType::Unknown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ButtonTextToDisplay;
};

UCLASS()
class UITESTPROJECT_API UConfirmScreenInfoObject : public UObject
{
	GENERATED_BODY()

public:

	static UConfirmScreenInfoObject* CreateOKScreen(const FText& InScreenTitle, const FText& InScreenMessage);
	static UConfirmScreenInfoObject* CreateYesNoScreen(const FText& InScreenTitle, const FText& InScreenMessage);
	static UConfirmScreenInfoObject* CreateOkCancelScreen(const FText& InScreenTitle, const FText& InScreenMessage);

	
	UPROPERTY(Transient)
	FText ScreenTitle;

	UPROPERTY(Transient)
	FText ScreenMessage;

	UPROPERTY(Transient)
	TArray<FConfirmScreenButtonInfo> AvailableScreenButtons;
};

//-------------------------------------------------------------------------------------------------------------------

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UITESTPROJECT_API UWidget_ConfirmationScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()
public:
	void InitConfirmScreen(UConfirmScreenInfoObject* InConfirmScreenInfoObject, TFunction<void(EConfirmScreenButtonType)> ClickedButtonCallback);

	
private:
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* CommonTextBlock_Title;
	
	UPROPERTY(meta = (BindWidget))
	UCommonTextBlock* CommonTextBlock_Message;

	UPROPERTY(meta = (BindWidget))
	class UDynamicEntryBox* DynamicEntryBox_Buttons;
	
};
