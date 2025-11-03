// Avalanche All Rights Reserved


#include "Widgets/Options/Widget_OptionsScreen.h"
#include "ICommonInputModule.h"
#include "Input/CommonUIInputTypes.h"
#include "DebugHelper.h"

void UWidget_OptionsScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (!ResetAction.IsNull())
	{
		FSimpleDelegate MyFunc{FSimpleDelegate::CreateUObject(this, &ThisClass::OnResetBoundActionTriggered)};
		FBindUIActionArgs ResetActionArgs{ResetAction, true,  MyFunc};
		ResetActionHandle = RegisterUIActionBinding(ResetActionArgs);
	}
	
	FSimpleDelegate MyBackFunc = FSimpleDelegate::CreateUObject(this, &ThisClass::OnBackBoundActionTriggered);
	FDataTableRowHandle DefaultBackAction = ICommonInputModule::GetSettings().GetDefaultBackAction();
	FBindUIActionArgs BackActionArgs{DefaultBackAction, true, MyBackFunc};
	RegisterUIActionBinding(BackActionArgs);
	
}


void UWidget_OptionsScreen::OnResetBoundActionTriggered()
{
	Debug::Print(TEXT("OnResetBoundActionTriggered11111111111"));
}

void UWidget_OptionsScreen::OnBackBoundActionTriggered()
{
	DeactivateWidget();
}
		