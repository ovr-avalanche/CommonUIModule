// Avalanche All Rights Reserved


#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"


void UListDataObject_Collection::AddChildListData(UListDataObject_Base* InChildListData)
{
	InChildListData->InitDataObject();

	InChildListData->SetParentData(this);
	
	ChildListDataArray.Add(InChildListData);
}
