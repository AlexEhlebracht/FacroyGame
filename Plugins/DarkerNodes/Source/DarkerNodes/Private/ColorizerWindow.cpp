/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"
#include "Classes/EditorStyleSettings.h"

void FColorizer::ColorWindow()
{
#if !PLATFORM_MAC
	const FVector2D IconWindow = FVector2D(30, 18);

	const FButtonStyle MinimizeButtonStyle =
		FButtonStyle(Button)
		.SetNormal(ImageBrush("/Window/WindowButton_Minimize_Normal.png", IconWindow))
		.SetHovered(ImageBrush("/Window/WindowButton_Minimize_Hovered.png", IconWindow))
		.SetPressed(ImageBrush("/Window/WindowButton_Minimize_Pressed.png", IconWindow));

	const FButtonStyle MaximizeButtonStyle =
		FButtonStyle(Button)
		.SetNormal(ImageBrush("/Window/WindowButton_Maximize_Normal.png", IconWindow))
		.SetHovered(ImageBrush("/Window/WindowButton_Maximize_Hovered.png", IconWindow))
		.SetPressed(ImageBrush("/Window/WindowButton_Maximize_Pressed.png", IconWindow));

	const FButtonStyle RestoreButtonStyle =
		FButtonStyle(Button)
		.SetNormal(ImageBrush("/Window/WindowButton_Restore_Normal.png", IconWindow))
		.SetHovered(ImageBrush("/Window/WindowButton_Restore_Hovered.png", IconWindow))
		.SetPressed(ImageBrush("/Window/WindowButton_Restore_Pressed.png", IconWindow));

	const FButtonStyle CloseButtonStyle =
		FButtonStyle(Button)
		.SetNormal(ImageBrush("/Window/WindowButton_Close_Normal.png", IconWindow))
		.SetHovered(ImageBrush("/Window/WindowButton_Close_Hovered.png", IconWindow))
		.SetPressed(ImageBrush("/Window/WindowButton_Close_Pressed.png", IconWindow));
#endif

	const FTextBlockStyle TitleTextStyle =
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9))
		.SetColorAndOpacity(FLinearColor::White)
		.SetShadowOffset(FVector2D(1.0f, 1.0f))
		.SetShadowColorAndOpacity(FLinearColor::Black);

	CoreStyle->Set(
		"Window",
		FWindowStyle()
#if !PLATFORM_MAC
		.SetMinimizeButtonStyle(MinimizeButtonStyle)
		.SetMaximizeButtonStyle(MaximizeButtonStyle)
		.SetRestoreButtonStyle(RestoreButtonStyle)
		.SetCloseButtonStyle(CloseButtonStyle)
#endif
		.SetTitleTextStyle(TitleTextStyle)
		.SetActiveTitleBrush(ImageBrush("/Transparent.png", Icon32))
		.SetInactiveTitleBrush(ImageBrush("/Window/WindowTitle_Inactive.png", Icon32))
		.SetFlashTitleBrush(ImageBrush("/Window/WindowTitle_Flashing.png", Icon24))
		.SetOutlineBrush(BorderBrush("/Window/WindowOutline.png"))
		.SetOutlineColor(FLinearColor(0.1f, 0.1f, 0.1f, 1.0f))
		.SetBorderBrush(BoxBrush("/Transparent.png", Icon256, 0.48f))
		.SetBackgroundBrush(ColorImageBrush(GreyBase))
		.SetChildBackgroundBrush(ColorImageBrush(GreyBase))
	);
}
