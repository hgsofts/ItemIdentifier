// Copyright 2022 HGsofts.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FItemIdentifierModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
