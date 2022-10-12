// Copyright 2022 HGsofts.

#include "ItemIDBFL.h"
#include "Misc/MessageDialog.h"

bool UItemIDBFL::ItemIDEquals(FItemID Lhs, FItemID Rhs, EItemIDCompareType Compare /*= EItemIDCompareType::All*/)
{
#if WITH_EDITOR	
	FString Message;	
	FString Title(TEXT("UItemIDBFL ItemIDEquals"));
	FText TitleText = FText::FromString(Title);

	if (!Lhs.IsValid())
	{
		Message = FString::Printf(TEXT("invalid Item ID [ %d ]"), Lhs.Identifier);
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Message), &TitleText);
	}

	if (!Rhs.IsValid())
	{
		Message = FString::Printf(TEXT("invalid Item ID [ %d ]"), Rhs.Identifier);
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Message), &TitleText);
	}
#endif	

	switch (Compare)
	{
	case EItemIDCompareType::All:
		return Lhs == Rhs;

	case EItemIDCompareType::A:	
		return Lhs.GetPartA() == Rhs.GetPartA();

	case EItemIDCompareType::B:
		return Lhs.GetPartB() == Rhs.GetPartB();

	case EItemIDCompareType::C:
		return Lhs.GetPartC() == Rhs.GetPartC();

	case EItemIDCompareType::D:
		return Lhs.GetPartD() == Rhs.GetPartD();

	case EItemIDCompareType::AB:
		return Lhs.GetPartAB() == Rhs.GetPartAB();
		
	case EItemIDCompareType::BC:
		return Lhs.GetPartBC() == Rhs.GetPartBC();

	case EItemIDCompareType::CD:
		return Lhs.GetPartCD() == Rhs.GetPartCD();
		
	case EItemIDCompareType::ABC:
		return Lhs.GetPartABC() == Rhs.GetPartABC();

	case EItemIDCompareType::BCD:
		return Lhs.GetPartBCD() == Rhs.GetPartBCD();	
	}
	
	return false;
}

int32 UItemIDBFL::Conv_ItemIDToInt(FItemID ItemID)
{
	return ItemID.Identifier;
}

FString UItemIDBFL::Conv_ItemIDToString(FItemID ItemID)
{
	return FString::Printf(TEXT("%02d %02d %02d %02d"), ItemID.GetPartA() / 1000000, ItemID.GetPartB() / 10000, ItemID.GetPartC() / 100, ItemID.GetPartD());
}

bool UItemIDBFL::Equal_ItemID(const FItemID& A, const FItemID& B)
{
	return A == B;
}

bool UItemIDBFL::NotEqual_ItemID(const FItemID& A, const FItemID& B)
{
	return A != B;
}
