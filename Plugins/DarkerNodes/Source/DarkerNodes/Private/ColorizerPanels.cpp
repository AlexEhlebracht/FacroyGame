/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"
#include "Classes/EditorStyleSettings.h"
#include "EditorStyle/Private/SlateEditorStyle.cpp"

void FColorizer::ColorPanel()
{
	const FButtonStyle CloseButton =
		FButtonStyle()
		.SetNormal(ImageBrush("/Elements/Panel/CloseApp_Normal.png", Icon16))
		.SetPressed(ImageBrush("/Elements/Panel/CloseApp_Pressed.png", Icon16))
		.SetHovered(ImageBrush("/Elements/Panel/CloseApp_Hovered.png", Icon16));

	//ApplyColorBorderBrush(CoreStyle, "Border", Green);
	CoreStyle->Set(
		"Docking.Tab",
		FDockTabStyle()
		.SetCloseButtonStyle(CloseButton)
		.SetNormalBrush(ColorBoxBrush(GreyBase))
		.SetHoveredBrush(ColorBoxBrush(HoverBase))
		.SetForegroundBrush(ColorBoxBrush(GreyDark))
		.SetActiveBrush(ColorBoxBrush(GreyDark))
		.SetColorOverlayTabBrush(ColorBoxBrush(HoverBase))
		.SetColorOverlayIconBrush(ColorBoxBrush(HoverBase))
		.SetContentAreaBrush(FSlateColorBrush(FLinearColor(GreyDark)))
		.SetTabWellBrush(FSlateNoResource())
		.SetTabPadding(FMargin(5, 2, 5, 2))
		.SetOverlapWidth(-1.0f)
		.SetFlashColor(FSlateColor(HoverBase))
	);

	CoreStyle->Set(
		"Docking.MajorTab",
		FDockTabStyle()
		.SetCloseButtonStyle(CloseButton)
		.SetNormalBrush(ColorBoxBrush(GreyBase))
		.SetActiveBrush(ColorBoxBrush(HoverBase))
		.SetColorOverlayTabBrush(ColorBoxBrush(GreyDark))
		.SetColorOverlayIconBrush(ColorBoxBrush(GreyDark))
		.SetForegroundBrush(ColorBoxBrush(GreyDark))
		.SetHoveredBrush(ColorBoxBrush(HoverBase))
		.SetContentAreaBrush(ColorBoxBrush(GreyDark))
		.SetTabWellBrush(FSlateNoResource())
		.SetTabPadding(FMargin(8, 4, 8, 4))
		.SetOverlapWidth(0.0f)
		.SetFlashColor(FSlateColor(HoverBase))
	);

	//EditorStyle->Set("ToolPalette.DockingWell", new FSlateColorBrush(FLinearColor(Blue)));


	CoreStyle->Set("ToolBar.Separator", new FSlateColorBrush(FLinearColor(GreyDark)));

	ApplyImageBrush(EditorStyle, "Graph.Panel.SolidBackground", "/Graph/GraphPanel_SolidBackground.png", Icon16);
	ApplyColorImageBrush(EditorStyle, "Window.Background", GreyDark);
	ApplyColorBoxBrush(EditorStyle, "Window.Background", GreyDark);

	ApplyColorBoxBrush(EditorStyle, "ToolBar.Background", GreyDark);
	ApplyColorBoxBrush(CoreStyle, "ToolBar.Background", GreyDark);
	ApplyColorBoxBrush(CoreStyle, "Menu.Background", GreyDark);
	//ApplyColorBoxBrush(CoreStyle, "Docking.Background", Red);
	//ApplyColorBoxBrush(CoreStyle, "Docking.Border", Red);
	//ApplyColorBoxBrush(CoreStyle, "Docking.Tab.ContentAreaBrush", Red);

	//ApplyColorBoxBrush(EditorStyle, "PropertyTable.Cell.DropDown.Background", Green);
	//ApplyColorBoxBrush(EditorStyle, "PropertyTable.ContentBorder", Green);
	//ApplyColorBoxBrush(EditorStyle, "PropertyWindow.WindowBorder", Green);
	ApplyColorBoxBrush(EditorStyle, "Graph.InstructionBackground", FColor(40, 40, 40, 128));
	ApplyColorBoxBrush(EditorStyle, "ContentBrowser.TileViewTooltip.ContentBorder", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "ProjectBrowser.TileViewTooltip.ContentBorder", GreyBase);
	//ApplyColorBoxBrush(EditorStyle, "ExpandableArea.Border", Blue);
	//ApplyColorBoxBrush(EditorStyle, "PaletteToolBar.Background", Blue);

	ApplyColorBoxBrush(CoreStyle, "ToolPanel.GroupBorder", GreyBase);
	ApplyBoxBrush(EditorStyle, "ToolPanel.GroupBorder", "/Graph/GraphPanel_SolidBackground.png");
	
	ApplyColorBoxBrush(EditorStyle, "SCSEditor.TreePanel", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "ContentBrowser.TopBar.GroupBorder", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "ToolPanel.DarkGroupBorder", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "ToolPanel.LightGroupBorder", GreyBase);

	ApplyColorBoxBrush(EditorStyle, "DetailsView.CollapsedCategory", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "DetailsView.CollapsedCategory_Hovered", HoverDark);
	ApplyColorBoxBrush(EditorStyle, "DetailsView.CategoryTop", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "DetailsView.CategoryTop_Hovered", HoverDark);
	ApplyColorImageBrush(EditorStyle, "DetailsView.CategoryMiddle", GreyBase);
	ApplyColorImageBrush(EditorStyle, "DetailsView.CategoryMiddle_Hovered", HoverBase);
	ApplyColorBoxBrush(EditorStyle, "DetailsView.CategoryBottom", GreyBase);
	ApplyColorBoxBrush(EditorStyle, "DetailsView.AdvancedDropdownBorder", GreyBase);
	ApplyColorImageBrush(EditorStyle, "DetailsView.AdvancedDropdownBorder.Open", GreyBase);

	UEditorStyleSettings* StyleSettings = GetMutableDefault<UEditorStyleSettings>();
	StyleSettings->SelectionColor = FLinearColor::FromSRGBColor(Primary);
	StyleSettings->PressedSelectionColor = FLinearColor::FromSRGBColor(Primary);
	StyleSettings->InactiveSelectionColor = FLinearColor::FromSRGBColor(HoverBase);
	StyleSettings->SaveConfig();

	FCoreStyle::SetSelectionColor(FLinearColor::FromSRGBColor(Primary));
	//FCoreStyle::SetSelectorColor(FLinearColor::FromSRGBColor(Green));
	FCoreStyle::SetPressedSelectionColor(FLinearColor::FromSRGBColor(Primary));
	FCoreStyle::SetInactiveSelectionColor(FLinearColor::FromSRGBColor(HoverBase));

	CoreStyle->Set("InvertedForeground", FSlateColor(TextColor));
	CoreStyle->Set("DefaultForeground", FSlateColor(TextColor));
	EditorStyle->Set("InvertedForeground", FSlateColor(TextColor));
	EditorStyle->Set("DefaultForeground", FSlateColor(TextColor));

	CoreStyle->Set(
		"Docking.UnhideTabwellButton",
		FButtonStyle(Button)
		.SetNormal(ColorImageBrush(FColor::Transparent, FVector2D(10, 10)))
		.SetPressed(ImageBrush("/Docking/ShowTabwellButton_Pressed.png", FVector2D(10, 10)))
		.SetHovered(ImageBrush("/Docking/ShowTabwellButton_Hovered.png", FVector2D(10, 10)))
		.SetNormalPadding(0)
		.SetPressedPadding(0)
	);

	const FTableColumnHeaderStyle TableColumnHeaderStyle =
		FTableColumnHeaderStyle()
		.SetSortPrimaryAscendingImage(ImageBrush("/Panel/SortUpArrow.png", FVector2D(8,4)))
		.SetSortPrimaryDescendingImage(ImageBrush("/Panel/SortDownArrow.png", FVector2D(8,4)))
		.SetSortSecondaryAscendingImage(ImageBrush("/Panel/SortUpArrows.png", FVector2D(16,4)))
		.SetSortSecondaryDescendingImage(ImageBrush("/Panel/SortDownArrows.png", FVector2D(16,4)))
		.SetNormalBrush(ColorBoxBrush(GreyDark))
		.SetHoveredBrush(ColorBoxBrush(HoverDark))
		.SetMenuDropdownImage(ImageBrush("/Panel/ColumnHeader_Arrow.png", Icon8))
		.SetMenuDropdownNormalBorderBrush(ColorBoxBrush(GreyBase))
		.SetMenuDropdownHoveredBorderBrush(ColorBoxBrush(HoverBase));
	CoreStyle->Set("TableView.Header.Column", TableColumnHeaderStyle);

	const FSplitterStyle TableHeaderSplitterStyle =
		FSplitterStyle()
		.SetHandleNormalBrush(FSlateNoResource())
		.SetHandleHighlightBrush(ImageBrush("/Panel/HeaderSplitterGrip.png", Icon8));

	CoreStyle->Set(
		"TableView.Header",
		FHeaderRowStyle()
		.SetColumnStyle(TableColumnHeaderStyle)
		.SetLastColumnStyle(TableColumnHeaderStyle)
		.SetColumnSplitterStyle(TableHeaderSplitterStyle)
		.SetBackgroundBrush(ColorBoxBrush(GreyDark))
		.SetForegroundColor(FLinearColor::FromSRGBColor(TextColor))
	);
}
