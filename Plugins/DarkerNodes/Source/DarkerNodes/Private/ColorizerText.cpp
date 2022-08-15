/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"

void FColorizer::ColorText()
{
	const FString Color = GetThemeColor();

	NormalText =
		FTextBlockStyle()
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9))
		.SetColorAndOpacity(FSlateColor(FLinearColor::FromSRGBColor(TextColor)))
		.SetShadowOffset(FVector2D::ZeroVector)
		.SetShadowColorAndOpacity(FLinearColor::FromSRGBColor(TextShadow))
		.SetHighlightColor(FLinearColor(Primary));

	CoreStyle->Set("NormalText", NormalText);
	EditorStyle->Set("NormalText", NormalText);

	const FEditableTextBoxStyle SpecialEditableTextBoxStyle =
		FEditableTextBoxStyle()
		.SetBackgroundImageNormal(BoxBrush("/Elements/TextBox/" + Color + "/TextBox.png", Icon16))
		.SetBackgroundImageHovered(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetBackgroundImageFocused(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetBackgroundImageReadOnly(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_ReadOnly.png", Icon16))
		.SetForegroundColor(FLinearColor::FromSRGBColor(TextColor))
		.SetScrollBarStyle(CoreStyle->GetWidgetStyle<FScrollBarStyle>("Scrollbar"));

	const FEditableTextBoxStyle NormalEditableTextBoxStyle = SpecialEditableTextBoxStyle;

	CoreStyle->Set(
		"EmbossedText",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 24))
		.SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor))
		.SetShadowOffset(FVector2D(0.0f, 1.0f))
		.SetShadowColorAndOpacity(FLinearColor::FromSRGBColor(TextShadow))
	);

	CoreStyle->Set(
		"SearchBox",
		FSearchBoxStyle()
		.SetTextBoxStyle(SpecialEditableTextBoxStyle)
		.SetUpArrowImage(ImageBrush("/Elements/Textbox/UpArrow.png", Icon8))
		.SetDownArrowImage(ImageBrush("/Elements/Textbox/DownArrow.png", Icon8))
		.SetGlassImage(ImageBrush("/Elements/Textbox/SearchGlass.png", Icon16))
		.SetClearImage(ImageBrush("/Elements/Textbox/X.png", Icon16))
	);

	EditorStyle->Set(
		"LevelViewportContextMenu.ActorType.Text",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8)));

	EditorStyle->Set(
		"LevelViewportContextMenu.AssetLabel.Text",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9)));

	EditorStyle->Set(
		"EditorModesToolbar.Label",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 7)));
	EditorStyle->Set(
		"EditorModesToolbar.EditableText",
		FEditableTextBoxStyle(NormalEditableTextBoxStyle)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9)));
	EditorStyle->Set(
		"EditorModesToolbar.Keybinding",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8)));

	EditorStyle->Set(
		"ToolBar.Label",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9)));
	EditorStyle->Set(
		"ToolBar.EditableText",
		FEditableTextBoxStyle(NormalEditableTextBoxStyle)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 9)));
	EditorStyle->Set(
		"ToolBar.Keybinding",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8)));

	EditorStyle->Set(
		"ToolBar.Heading",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8)));

	EditorStyle->Set(
		"ViewportMenu.Label",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 9)));

	EditorStyle->Set(
		"SProjectBadge.Text",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 12)));

	EditorStyle->Set(
		"Editor.SearchBoxFont",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 12)));

	EditorStyle->Set(
		"ViewportPinnedCommandList.Label",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		.SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor)));

	EditorStyle->Set(
		"ViewportPinnedCommandList.EditableText",
		FEditableTextBoxStyle(NormalEditableTextBoxStyle)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 9))
		.SetForegroundColor(FLinearColor::FromSRGBColor(TextColor)));

	EditorStyle->Set(
		"ViewportPinnedCommandList.Keybinding",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8))
		.SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor)));

	EditorStyle->Set(
		"ViewportPinnedCommandList.Heading",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8))
		.SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor)));

	EditorStyle->Set(
		"FlatButton.DefaultTextStyle",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 10))
		.SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor))
		.SetHighlightColor(FLinearColor::FromSRGBColor(TextColor))
		.SetShadowOffset(FVector2D(1, 1))
		.SetShadowColorAndOpacity(FLinearColor::FromSRGBColor(TextShadow)));

	EditorStyle->Set(
		"Profiler.EventGraph.DarkText",
		FTextBlockStyle(NormalText)
		.SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 8))
	);

	const FString FontAwesomePath = FPaths::EngineContentDir() / TEXT("Editor/Slate/Fonts/FontAwesome.ttf");	

	EditorStyle->Set("FindResults.FindInBlueprints", FTextBlockStyle(NormalText)
            .SetFont(FSlateFontInfo(FontAwesomePath, 10))
            .SetColorAndOpacity(FLinearColor::FromSRGBColor(TextColor))
        );
}
