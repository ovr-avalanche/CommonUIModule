// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ListDataObject_Base.generated.h"

#define SETTER_GETTER(DataType, PropertyName) \
	FORCEINLINE DataType Get##PropertyName() const {return PropertyName;} \
	void Set##PropertyName(DataType In##PropertyName) {PropertyName = In##PropertyName;}
/**
 * 
 */
UCLASS()
class UITESTPROJECT_API UListDataObject_Base : public UObject
{
	GENERATED_BODY()
public:
	// FORCEINLINE FName GetDataID() const { return DataID; }
	// void SetDataID(FName InDataID) {DataID = InDataID;}

	SETTER_GETTER(FName, DataID); // expands to the commented getter/setter above
	SETTER_GETTER(FText, DataDisplayName);
	SETTER_GETTER(FText, DataDescriptionText);
	SETTER_GETTER(FText, DisabledText);
	SETTER_GETTER(TSoftObjectPtr<UTexture2D>, SoftDescriptionImage);
	SETTER_GETTER(UListDataObject_Base*, ParentData);

	//returns an empty array in the base class. should be overwritten to return all child data a tab has.
	virtual TArray<UListDataObject_Base*> GetChildListData() const{return TArray<UListDataObject_Base*>();}
private:
	FName DataID;
	FText DataDisplayName;
	FText DataDescriptionText;
	FText DisabledText;
	TSoftObjectPtr<UTexture2D> SoftDescriptionImage;

	UPROPERTY(Transient)
	UListDataObject_Base* ParentData;
};
