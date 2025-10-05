// Avalanche All Rights Reserved


#include "FrontendFunctionLibrary.h"
#include "FrontendSettings/FrontendDeveloperSettings.h"

TSoftClassPtr<UWidget_ActivatableBase> UFrontendFunctionLibrary::GetFrontendSoftWidgetClassByTag(UPARAM(meta = (Categories = "Frontend.Widget")) FGameplayTag InWidgetTag)
{
	const UFrontendDeveloperSettings* FrontendSettings = GetDefault<UFrontendDeveloperSettings>();
	
	checkf(FrontendSettings->FrontendWidgetMap.Contains(InWidgetTag), TEXT("%s Tag is not found the FrontendSetting TMAP"), *InWidgetTag.ToString());

	
	return FrontendSettings->FrontendWidgetMap.FindRef(InWidgetTag);
}
