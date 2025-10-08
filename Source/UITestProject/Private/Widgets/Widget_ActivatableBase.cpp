// Avalanche All Rights Reserved


#include "Widgets/Widget_ActivatableBase.h"
#include "Controllers/MyFrontendController.h"

AMyFrontendController* UWidget_ActivatableBase::GetOwningFrontendController()
{
	if (!CachedOwningFrontendController.IsValid())
	{
		CachedOwningFrontendController = GetOwningPlayer<AMyFrontendController>();
	}
	return CachedOwningFrontendController.IsValid() ? CachedOwningFrontendController.Get() : nullptr;
}
