// Copyright 2022 HGsofts.

#pragma once

#include "ItemID.generated.h"

UENUM(BlueprintType)
enum class EItemIDCompareType : uint8
{		
	A = 0,	// 99 000000	// 9 is compare, 0 is ignore
	B,		// 00 99 0000 
	C,		// 0000 99 00 
	D,		// 000000 99 
	AB,		// 9999 0000
	BC,		// 00 9999 00
	CD,		// 0000 9999
	ABC,	// 999999 00
	BCD,	// 00 999999
	All,	// 99999999
};

USTRUCT(BlueprintType)
struct ITEMIDENTIFIER_API FItemID
{
	GENERATED_BODY()

public:	
	FItemID() = default;

	FItemID(int32 ID);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Identifier")
	int32 Identifier = -1; // must be 8 Digits

	bool IsValid() { return Identifier >= 0 && Identifier < 100000000; }

	FORCEINLINE int32 GetPartA() { return Identifier - (Identifier % 1000000); }

	FORCEINLINE int32 GetPartB() { return (Identifier % 1000000) - (Identifier % 10000); }

	FORCEINLINE int32 GetPartC() { return (Identifier % 10000) - (Identifier % 100); }

	FORCEINLINE int32 GetPartD() { return Identifier % 100; }

	FORCEINLINE int32 GetPartAB() { return Identifier - (Identifier % 10000); }

	FORCEINLINE int32 GetPartBC() { return (Identifier - (Identifier % 100)) % 1000000; }

	FORCEINLINE int32 GetPartCD() { return Identifier % 10000; }

	FORCEINLINE int32 GetPartABC() { return Identifier - (Identifier % 100); }

	FORCEINLINE int32 GetPartBCD() { return Identifier % 1000000; }

};

inline bool operator==(const FItemID& Lhs, const FItemID& Rhs) { return Lhs.Identifier == Rhs.Identifier; }
inline bool operator!=(const FItemID& Lhs, const FItemID& Rhs) { return Lhs.Identifier != Rhs.Identifier; }
