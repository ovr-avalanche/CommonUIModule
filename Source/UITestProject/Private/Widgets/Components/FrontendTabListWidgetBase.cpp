// Avalanche All Rights Reserved


#include "Widgets/Components/FrontendTabListWidgetBase.h"
#include "Widgets/Components/FrontendCommonButtonBase.h"
#include "Editor/WidgetCompilerLog.h"

#if WITH_EDITOR
void UFrontendTabListWidgetBase::ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!TabButtonEntryWidget)
	{
		CompileLog.Error(FText::FromString(TEXT("var TabButtonEntryWidget is not set! ") +
			GetClass()->GetName() +
			TEXT(" needs a valid entry widget class")
		));
	}
}
#endif