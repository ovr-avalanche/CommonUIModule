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
