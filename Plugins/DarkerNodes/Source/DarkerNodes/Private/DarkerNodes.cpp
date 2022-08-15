/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "DarkerNodes.h"

#include "Colorizer.h"
#include "MainFrame/Public/Interfaces/IMainFrameModule.h"

#define LOCTEXT_NAMESPACE "FDarkerNodesModule"

void FDarkerNodesModule::StartupModule()
{
	FColorizer Colorizer;
	Colorizer.Color();
}

void FDarkerNodesModule::ShutdownModule()
{
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDarkerNodesModule, DarkerNodes)
