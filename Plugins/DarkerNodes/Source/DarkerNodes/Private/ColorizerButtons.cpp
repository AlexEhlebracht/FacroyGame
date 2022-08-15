/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"
#include "PIEPreviewDeviceProfileSelector/Private/PIEPreviewWindowCoreStyle.h"

void FColorizer::ColorButtons()
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();

	const FString Color = GetThemeColor();

	FMargin Margin;

	switch (DarkerNodesSettings.ButtonPadding)
	{
	case EButtonPadding::Small:
		Margin = FMargin(4, 2, 4, 2);
		break;
	case EButtonPadding::Normal:
		Margin = FMargin(8, 4, 8, 4);
		break;
	case EButtonPadding::Big:
		Margin = FMargin(16, 8, 16, 8);
		break;
	}

	// Button
	Button =
		FButtonStyle()
		.SetNormal(BoxBrush("/Elements/Button/" + Color + "/Button.png", Icon32))
		.SetHovered(BoxBrush("/Elements/Button/" + Color + "/Button_Hovered.png", Icon32))
		.SetPressed(BoxBrush("/Elements/Button/" + Color + "/Button_Pressed.png", Icon32))
		.SetNormalPadding(Margin)
		.SetPressedPadding(Margin);
	CoreStyle->Set("Button", Button);

	const FComboButtonStyle ComboButton =
		FComboButtonStyle()
		.SetButtonStyle(Button)
		.SetDownArrowImage(ImageBrush("/Elements/Button/ComboArrow.png", Icon8))
		.SetMenuBorderBrush(BoxBrush("/Elements/Button/" + Color + "/Button.png", Icon32))
		.SetMenuBorderPadding(Margin);
	CoreStyle->Set("ComboButton", ComboButton);

	const FComboBoxStyle ComboBox = FComboBoxStyle()
		.SetComboButtonStyle(ComboButton);
	CoreStyle->Set("ComboBox", ComboBox);


	EditorStyle->Set("FilePath.FolderButton", Button);
	EditorStyle->Set("PropertyEditor.AssetComboStyle", Button);

	// Textbox

	const FEditableTextBoxStyle NormalEditableTextBoxStyle =
		FEditableTextBoxStyle()
		.SetBackgroundImageNormal(BoxBrush("/Elements/TextBox/" + Color + "/TextBox.png", Icon16))
		.SetBackgroundImageHovered(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetBackgroundImageFocused(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetBackgroundImageReadOnly(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_ReadOnly.png", Icon16))
		.SetPadding(Margin)
		.SetScrollBarStyle(CoreStyle->GetWidgetStyle<FScrollBarStyle>("ScrollBar"))
		.SetForegroundColor(FSlateColor(FLinearColor::FromSRGBColor(TextColor)));
	CoreStyle->Set("NormalEditableTextBox", NormalEditableTextBoxStyle);
	CoreStyle->Set("SpecialEditableTextBox", NormalEditableTextBoxStyle);
	NiagaraStyle->Set("NiagaraEditor.ParameterEditableTextBox", NormalEditableTextBoxStyle);


	const FSpinBoxStyle SpinBox =
		FSpinBoxStyle()
		.SetBackgroundBrush(BoxBrush("/Elements/TextBox/" + Color + "/TextBox.png", Icon16))
		.SetHoveredBackgroundBrush(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetActiveFillBrush(BoxBrush("/Elements/TextBox/" + Color + "/TextBox_Hovered.png", Icon16))
		.SetInactiveFillBrush(BoxBrush("/Elements/TextBox/" + Color + "/TextBox.png", Icon16))
		.SetArrowsImage(ImageBrush("/Elements/Textbox/SpinArrows.png", Icon12))
		.SetForegroundColor(FSlateColor(FLinearColor::FromSRGBColor(GreyLight)));

	CoreStyle->Set("SpinBox", SpinBox);
	EditorStyle->Set("SpinBox", SpinBox);
	CoreStyle->Set("NumericEntrySpinBox", SpinBox);
	EditorStyle->Set("NumericEntrySpinBox", SpinBox);
	CoreStyle->Set("NumericEntrySpinBox_Dark", SpinBox);
	NiagaraStyle->Set("NiagaraEditor.ParameterSpinbox", SpinBox);

	// Tableview

	const FTableRowStyle DefaultTableRowStyle =
		FTableRowStyle()
		.SetEvenRowBackgroundBrush(FSlateNoResource())
		.SetEvenRowBackgroundHoveredBrush(ColorImageBrush(HoverBase))
		.SetOddRowBackgroundBrush(FSlateNoResource())
		.SetOddRowBackgroundHoveredBrush(ColorImageBrush(HoverBase))
		.SetSelectorFocusedBrush(BorderBrush("/Elements/Table/Selector.png", FMargin(0.25), HoverBaseBright))
		.SetActiveBrush(ColorImageBrush(HoverBase))
		.SetActiveHoveredBrush(ColorImageBrush(HoverBase))
		.SetInactiveBrush(ColorImageBrush(HoverBase))
		.SetInactiveHoveredBrush(ColorImageBrush(HoverBase))
		.SetActiveHighlightedBrush(ColorImageBrush(HoverBase))
		.SetInactiveHighlightedBrush(ColorImageBrush(HoverBase))
		.SetTextColor(FLinearColor::FromSRGBColor(TextColor))
		.SetSelectedTextColor(FLinearColor::FromSRGBColor(TextColor))
		.SetDropIndicator_Above(BorderBrush("/Elements/Table/DropZoneIndicator_Above.png", FMargin(10.0f / 16.0f, 10.0f / 16.0f, 0, 0), HoverBaseBright))
		.SetDropIndicator_Onto(BorderBrush("/Elements/Table/DropZoneIndicator_Onto.png", FMargin(0.25), HoverBaseBright))
		.SetDropIndicator_Below(BorderBrush("/Elements/Table/DropZoneIndicator_Below.png", FMargin(10.0f / 16.0f, 0, 0, 10.0f / 16.0f), HoverBaseBright));
	CoreStyle->Set("TableView.Row", FTableRowStyle(DefaultTableRowStyle));
	EditorStyle->Set("TableView.Row", FTableRowStyle(DefaultTableRowStyle));

	// SmallRounded

	EditorStyle->Set("EditorViewportToolBar.MenuButton", FButtonStyle(Button));
	EditorStyle->Set("EditorViewportToolBar.MenuButtonWarning", FButtonStyle(Button));
	EditorStyle->Set("ViewportPinnedCommandList.Button", FButtonStyle(Button));
	EditorStyle->Set("ViewportMenu.Button", FButtonStyle(Button));
	EditorStyle->Set(
		"ViewportMenu.Button.Start",
		FButtonStyle(Button)
		.SetNormal(BoxBrush("/Elements/Button/" + Color + "/Button_Start.png", Icon0, 0.5))
		.SetHovered(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Hovered.png", Icon0, 0.5))
		.SetPressed(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Pressed.png", Icon0, 0.5)));
	EditorStyle->Set(
		"ViewportMenu.Button.Middle",
		FButtonStyle(Button)
		.SetNormal(BoxBrush("/Elements/Button/" + Color + "/Button_Middle.png", Icon0, 0.5))
		.SetHovered(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Hovered.png", Icon0, 0.5))
		.SetPressed(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Pressed.png", Icon0, 0.5)));
	EditorStyle->Set(
		"ViewportMenu.Button.End",
		FButtonStyle(Button)
		.SetNormal(BoxBrush("/Elements/Button/" + Color + "/Button_End.png", Icon0, 0.5))
		.SetHovered(BoxBrush("/Elements/Button/" + Color + "/Button_End_Hovered.png", Icon0, 0.5))
		.SetPressed(BoxBrush("/Elements/Button/" + Color + "/Button_End_Pressed.png", Icon0, 0.5)));

	const FCheckBoxStyle ToggleStart =
		FCheckBoxStyle()
		.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
		.SetUncheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start.png", Icon0, 0.5))
		.SetUncheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Hovered.png", Icon0, 0.5))
		.SetUncheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Pressed.png", Icon0, 0.5))
		.SetCheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Checked.png", Icon0, 0.5))
		.SetCheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Hovered_Checked.png", Icon0, 0.5))
		.SetCheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Start_Pressed.png", Icon0, 0.5));

	const FCheckBoxStyle ToggleMiddle =
		FCheckBoxStyle()
		.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
		.SetUncheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle.png", Icon0, 0.5))
		.SetUncheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Hovered.png", Icon0, 0.5))
		.SetUncheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Pressed.png", Icon0, 0.5))
		.SetCheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Checked.png", Icon0, 0.5))
		.SetCheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Hovered_Checked.png", Icon0, 0.5))
		.SetCheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_Middle_Pressed.png", Icon0, 0.5));

	const FCheckBoxStyle ToggleEnd =
		FCheckBoxStyle()
		.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
		.SetUncheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_End.png", Icon0, 0.5))
		.SetUncheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_End_Hovered.png", Icon0, 0.5))
		.SetUncheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_End_Pressed.png", Icon0, 0.5))
		.SetCheckedImage(BoxBrush("/Elements/Button/" + Color + "/Button_End_Checked.png", Icon0, 0.5))
		.SetCheckedHoveredImage(BoxBrush("/Elements/Button/" + Color + "/Button_End_Hovered_Checked.png", Icon0, 0.5))
		.SetCheckedPressedImage(BoxBrush("/Elements/Button/" + Color + "/Button_End_Pressed.png", Icon0, 0.5));


	EditorStyle->Set("ViewportMenu.ToggleButton.Start", ToggleStart);
	EditorStyle->Set("ViewportMenu.ToggleButton.Middle", ToggleMiddle);
	EditorStyle->Set("ViewportMenu.ToggleButton.End", ToggleEnd);

	EditorStyle->Set("Property.ToggleButton.Start", ToggleStart);
	EditorStyle->Set("Property.ToggleButton.Middle", ToggleMiddle);
	EditorStyle->Set("Property.ToggleButton.End", ToggleEnd);

	CoreStyle->Set(
		"ToolBar.Button",
		FButtonStyle(Button)
		.SetNormal(FSlateNoResource())
		.SetPressed(ColorBoxBrush(HoverDark))
		.SetHovered(ColorBoxBrush(HoverDark))
		.SetNormalPadding(FMargin(2))
		.SetPressedPadding(FMargin(2))
	);

	ApplyColorBoxBrush(CoreStyle, "ToolBar.Button.Pressed", HoverDark);
	ApplyColorBoxBrush(CoreStyle, "ToolBar.Button.Hovered", HoverDark);

	ApplyColorBoxBrush(CoreStyle, "ToolBar.Button.Checked", HoverBase);
	ApplyColorBoxBrush(CoreStyle, "ToolBar.Button.Checked_Hovered", HoverDark);
	ApplyColorBoxBrush(CoreStyle, "ToolBar.Button.Checked_Pressed", HoverDark);

	CoreStyle->Set(
		"Menu.Button",
		FButtonStyle(Button)
		.SetNormal(FSlateNoResource())
		.SetHovered(ColorBoxBrush(Primary))
		.SetPressed(ColorBoxBrush(Primary))
		.SetNormalPadding(FMargin(0, 1))
		.SetPressedPadding(FMargin(0, 2, 0, 0))
	);

	ApplyColorBoxBrush(CoreStyle, "Menu.Button.Checked", HoverDark);
	ApplyColorBoxBrush(CoreStyle, "Menu.Button.Checked_Hovered", HoverDark);
	ApplyColorBoxBrush(CoreStyle, "Menu.Button.Checked_Pressed", HoverDark);
	ApplyColorBoxBrush(CoreStyle, "Menu.Button.SubMenuOpen", HoverDark);

	const FButtonStyle ToggleButton =
		FButtonStyle(Button)
		.SetNormal(FSlateNoResource())
		.SetHovered(ColorBoxBrush(HoverBase))
		.SetPressed(ColorBoxBrush(HoverBase))
		.SetNormalPadding(FMargin(0))
		.SetPressedPadding(FMargin(0));

	const FButtonStyle RoundButton =
		FButtonStyle(ToggleButton)
		.SetNormal(ColorBoxBrush(GreyBase))
		.SetHovered(ColorBoxBrush(HoverBase))
		.SetPressed(ColorBoxBrush(HoverBase));
	EditorStyle->Set("ToggleButton", ToggleButton);
	EditorStyle->Set("FlatButton", ToggleButton);

	//FSlateColorBrush(FLinearColor::White)

	EditorStyle->Set("RoundButton", RoundButton);
	EditorStyle->Set(
		"FlatButton",
		FButtonStyle(Button)
		.SetNormal(ColorBoxBrush(GreyBase))
		.SetHovered(ColorBoxBrush(HoverBase))
		.SetPressed(ColorBoxBrush(HoverBase))
	);
	EditorStyle->Set("FlatButton.Dark", RoundButton);
	EditorStyle->Set("FlatButton.DarkGrey", RoundButton);
	EditorStyle->Set("FlatButton.Light", RoundButton);
	EditorStyle->Set("FlatButton.Default", RoundButton);


	struct ButtonColor
	{
		FName Name;
		FColor Normal;
		FColor Hovered;

		ButtonColor(const FName& InName, const FColor& Color) : Name(InName)
		{
			Normal = Color;
			Normal.A = Color.A * 0.75;
			Hovered = Color;
			Hovered.A = Color.A * 1.0;
		}
	};

	// Red #b20000
	// Blue #0060b2
	// Yellow #dfb300
	// Green #3aa111

	TArray<ButtonColor> FlatButtons;
	FlatButtons.Add(ButtonColor("FlatButton.Primary", ButtonPrimary));
	FlatButtons.Add(ButtonColor("FlatButton.Success", ButtonSuccess));
	FlatButtons.Add(ButtonColor("FlatButton.Info", ButtonInfo));
	FlatButtons.Add(ButtonColor("FlatButton.Warning", ButtonWarning));
	FlatButtons.Add(ButtonColor("FlatButton.Danger", ButtonDanger));

	for (const ButtonColor& Entry : FlatButtons)
	{
		EditorStyle->Set(
			Entry.Name,
			FButtonStyle(Button)
			.SetNormal(BoxBrush("/Elements/Button/FlatButton.png", Icon0, 0.25, Entry.Normal))
			.SetHovered(BoxBrush("/Elements/Button/FlatButton.png", Icon0, 0.25, Entry.Hovered))
			.SetPressed(BoxBrush("/Elements/Button/FlatButton.png", Icon0, 0.25, Entry.Hovered))
		);
	}
}
