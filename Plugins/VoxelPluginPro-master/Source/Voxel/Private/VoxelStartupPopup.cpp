// Copyright 2021 Phyronnaz

#include "VoxelStartupPopup.h"
#include "VoxelMinimal.h"
#include "VoxelMessages.h"
#include "VoxelUtilities/VoxelSystemUtilities.h"

#include "Misc/MessageDialog.h"
#include "Misc/ConfigCacheIni.h"
#include "HAL/PlatformProcess.h"

void FVoxelStartupPopup::OnModuleStartup()
{
	FVoxelSystemUtilities::DelayedCall([]()
	{
		FVoxelStartupPopup().ShowPopup();
	});
}

void FVoxelStartupPopup::ShowPopup()
{
	int32 VoxelPluginVersion = 0;
	GConfig->GetInt(TEXT("VoxelPlugin"), TEXT("VoxelPluginVersion"), VoxelPluginVersion, GEditorPerProjectIni);
	
	const auto OpenLink = [=](const FString& Url)
	{
		FString Error;
		FPlatformProcess::LaunchURL(*Url, nullptr, &Error);
		if (!Error.IsEmpty())
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Failed to open " + Url + "\n:" + Error));
		}
	};

	constexpr int32 LatestVoxelPluginVersion = 2;
	if (VoxelPluginVersion < LatestVoxelPluginVersion)
	{
		const auto Close = [=]()
		{
			GConfig->SetInt(TEXT("VoxelPlugin"), TEXT("VoxelPluginVersion"), LatestVoxelPluginVersion, GEditorPerProjectIni);
		};

		FVoxelMessages::FNotification Notification;
		Notification.UniqueId = OBJECT_LINE_ID();
		Notification.Message = "Voxel Plugin has been updated to 1.2!";
		Notification.Duration = 1e6f;
		Notification.OnClose = FSimpleDelegate::CreateLambda(Close);
		
		auto& Button = Notification.Buttons.Emplace_GetRef();
		Button.Text = "Show Release Notes";
		Button.Tooltip = "See the latest plugin release notes";
		Button.OnClick = FSimpleDelegate::CreateLambda([=]() 
		{
			OpenLink("https://releases.voxelplugin.com");
			Close();
		});
		
		FVoxelMessages::ShowNotification(Notification);
	}

}