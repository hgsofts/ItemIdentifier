// Copyright 2022 HGsofts.

#include "ItemID.h"

FItemID::FItemID(int32 ID)
{	
	if (ID > 99999999)
	{
		UE_LOG(LogTemp, Error, TEXT("[%d] ID must be 8 Digits"));
		ID = ID % 100000000;
	}
	
	Identifier = ID;
}
