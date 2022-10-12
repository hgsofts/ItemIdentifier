// Copyright 2022 HGsofts.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemID.h"
#include "ItemIDBFL.generated.h"

/**
 * 
 */
UCLASS()
class ITEMIDENTIFIER_API UItemIDBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static bool ItemIDEquals(FItemID Lhs, FItemID Rhs, EItemIDCompareType Compare = EItemIDCompareType::All);

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartA(FItemID ItemID) { return ItemID.GetPartA(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartB(FItemID ItemID) { return ItemID.GetPartB(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartC(FItemID ItemID) { return ItemID.GetPartC(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartD(FItemID ItemID) { return ItemID.GetPartD(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartAB(FItemID ItemID) { return ItemID.GetPartAB(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartBC(FItemID ItemID) { return ItemID.GetPartBC(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartCD(FItemID ItemID) { return ItemID.GetPartCD(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartABC(FItemID ItemID) { return ItemID.GetPartABC(); }

	UFUNCTION(BlueprintPure, Category = "Item Identifier")
	static int32 GetItemIDPartBCD(FItemID ItemID) { return ItemID.GetPartBCD(); }

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToInt (ItemID)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Item Identifier")
	static int32 Conv_ItemIDToInt(FItemID ItemID);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (ItemID)", CompactNodeTitle = "->", Keywords = "cast convert", BlueprintAutocast), Category = "Item Identifier")
	static FString Conv_ItemIDToString(FItemID ItemID);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (ItemID)", CompactNodeTitle = "==", BlueprintThreadSafe), Category = "Item Identifier")
	static bool Equal_ItemID(const FItemID& A, const FItemID& B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (ItemID)", CompactNodeTitle = "!=", BlueprintThreadSafe), Category = "Item Identifier")
	static bool NotEqual_ItemID(const FItemID& A, const FItemID& B);
};
