// Avalanche All Rights Reserved


#include "Widgets/Components/FrontendCommonButtonBase.h"
#include "CommonTextBlock.h"

void UFrontendCommonButtonBase::SetButtonText(FText InTex)
{
	if (CommonTextBlock_ButtonText && !InTex.IsEmpty())
	{
		CommonTextBlock_ButtonText->SetText(bUseUpperCaseForButtonText? InTex.ToUpper() : InTex);
	}
}

void UFrontendCommonButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	SetButtonText(ButtonText);
}

void UFrontendCommonButtonBase::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	if (CommonTextBlock_ButtonText && GetCurrentTextStyleClass())
	{
		CommonTextBlock_ButtonText->SetStyle(GetCurrentTextStyleClass());
	}
}
