
// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "ListDataObject_Collection.generated.h"

/**
 * 
 */
UCLASS()
class UITESTPROJECT_API UListDataObject_Collection : public UListDataObject_Base
{
	GENERATED_BODY()

public:
	void AddChildListData(UListDataObject_Base* InChildListData);
	
	//~ Begin UListDataObject_Base interface
	virtual TArray<UListDataObject_Base*> GetAllChildListData() const override {return ChildListDataArray;};
	virtual bool HasAnyChildListData() const override {return !ChildListDataArray.IsEmpty();};
	//~ End UListDataObject_Base interface
	
private:
	UPROPERTY(Transient)
	TArray<UListDataObject_Base*> ChildListDataArray;
	
};
