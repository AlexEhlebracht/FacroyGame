/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"

#include "EditorStyleSet.h"
#include "Interfaces/IPluginManager.h"
#include "Classes/EditorStyleSettings.h"
#include "SettingsEditor/Public/ISettingsEditorModule.h"
#include "NiagaraEditorStyle.h"


FColorizer::FColorizer()
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();
	DarkerNodesSettings.OnSettingChanged().AddRaw(this, &FColorizer::Reload);

	ReloadStyle();
}

void FColorizer::ReloadStyle()
{
	EditorStyle = static_cast<FSlateStyleSet*>(&FEditorStyle::Get());
	CoreStyle = static_cast<FSlateStyleSet*>(const_cast<ISlateStyle*>(&FCoreStyle::Get()));
	NiagaraStyle = static_cast<FSlateStyleSet*>(const_cast<ISlateStyle*>(&FNiagaraEditorStyle::Get()));
	ThemeDirectory = IPluginManager::Get().FindPlugin(TEXT("DarkerNodes"))->GetBaseDir() + FString("/Resources/Theme");

	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();

	if (!DarkerNodesSettings.MasterActivate)
	{
		return;
	}

	switch (DarkerNodesSettings.ThemeLight)
	{
	case EThemeLight::Dark:
		GreyBase = OffsetColor(GreyBase, 20);
		GreyDark = OffsetColor(GreyDark, 20);
		GreyLight = OffsetColor(GreyLight, 20);
		break;
	case EThemeLight::Darker:
		break;
	case EThemeLight::Darkest:
		GreyBase = OffsetColor(GreyBase, -20);
		GreyDark = OffsetColor(GreyDark, -10);
		GreyLight = OffsetColor(GreyLight, -10);
		break;
	case EThemeLight::Light:
		GreyBase = FColor(210, 210, 210);
		GreyDark = FColor(225, 225, 225);
		GreyLight = FColor(200, 200, 200);
		TextColor = FColor(40, 40, 40);
		TextShadow = FColor(240, 240, 240);
		ImageColor = FColor(40, 40, 40);
		break;
	}

	const FColor WarmLayer = FColor(229, 110, 23);
	const FColor CoolLayer = FColor(23, 141, 229);

	switch (DarkerNodesSettings.ThemeTemperature)
	{
	case EThemeTemperature::Cooler:
		GreyBase = MixColor(GreyBase, CoolLayer, 0.05);
		GreyDark = MixColor(GreyDark, CoolLayer, 0.05);
		GreyLight = MixColor(GreyLight, CoolLayer, 0.05);
		break;
	case EThemeTemperature::Cool:
		GreyBase = MixColor(GreyBase, CoolLayer, 0.025);
		GreyDark = MixColor(GreyDark, CoolLayer, 0.025);
		GreyLight = MixColor(GreyLight, CoolLayer, 0.025);
		break;
	case EThemeTemperature::Normal:
		break;
	case EThemeTemperature::Warm:
		GreyBase = MixColor(GreyBase, WarmLayer, 0.025);
		GreyDark = MixColor(GreyDark, WarmLayer, 0.025);
		GreyLight = MixColor(GreyLight, WarmLayer, 0.025);
		break;
	case EThemeTemperature::Warmer:
		GreyBase = MixColor(GreyBase, WarmLayer, 0.05);
		GreyDark = MixColor(GreyDark, WarmLayer, 0.05);
		GreyLight = MixColor(GreyLight, WarmLayer, 0.05);
		break;
	}

	const FColor White = FColor(126, 126, 126);
	const FColor Orange = FColor(229, 110, 23);
	const FColor Cyan = FColor(23, 141, 229);
	const FColor Red = FColor(229, 25, 23);
	const FColor Purple = FColor(178, 23, 229);
	const FColor Green = FColor(74, 229, 23);

	switch (DarkerNodesSettings.PrimaryColor)
	{
	case EPrimaryColor::White:
		Primary = White;
		break;
	case EPrimaryColor::Orange:
		Primary = Orange;
		break;
	case EPrimaryColor::Cyan:
		Primary = Cyan;
		break;
	case EPrimaryColor::Red:
		Primary = Red;
		break;
	case EPrimaryColor::Purple:
		Primary = Purple;
		break;
	case EPrimaryColor::Green:
		Primary = Green;
		break;
	}

	if (DarkerNodesSettings.UseGreyCustomization)
	{
		GreyBase = DarkerNodesSettings.GreyBase;
		GreyDark = DarkerNodesSettings.GreyDark;
		GreyLight = DarkerNodesSettings.GreyLight;
	}

	if (DarkerNodesSettings.UseColorCustomization)
	{
		Primary = DarkerNodesSettings.CustomPrimaryColor;
		TextColor = DarkerNodesSettings.TextColor;
	}

	if (DarkerNodesSettings.UseButtonColorCustomization)
	{
		ButtonPrimary = DarkerNodesSettings.ButtonPrimary;
		ButtonSuccess = DarkerNodesSettings.ButtonSuccess;
		ButtonInfo = DarkerNodesSettings.ButtonInfo;
		ButtonWarning = DarkerNodesSettings.ButtonWarning;
		ButtonDanger = DarkerNodesSettings.ButtonDanger;
	}

	HoverDark = MixColor(GreyDark, Primary, 0.1);
	HoverBase = MixColor(GreyBase, Primary, 0.1);
	HoverBaseBright = MixColor(GreyBase, Primary, 0.5);

	if (!DarkerNodesSettings.UseGreyCustomization)
	{
		DarkerNodesSettings.GreyBase = GreyBase;
		DarkerNodesSettings.GreyDark = GreyDark;
		DarkerNodesSettings.GreyLight = GreyLight;
	}

	if (!DarkerNodesSettings.UseColorCustomization)
	{
		DarkerNodesSettings.CustomPrimaryColor = Primary;
		DarkerNodesSettings.TextColor = TextColor;
	}

	if (!DarkerNodesSettings.UseButtonColorCustomization)
	{
		DarkerNodesSettings.ButtonPrimary = ButtonPrimary;
		DarkerNodesSettings.ButtonSuccess = ButtonSuccess;
		DarkerNodesSettings.ButtonInfo = ButtonInfo;
		DarkerNodesSettings.ButtonWarning = ButtonWarning;
		DarkerNodesSettings.ButtonDanger = ButtonDanger;
	}
}

void FColorizer::Color()
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();

	if (!DarkerNodesSettings.MasterActivate)
	{
		return;
	}

	ColorText();
	ColorGraph();
	ColorButtons();
	ColorCheckbox();
	ColorPanel();
	ColorWindow();
	ColorIcons();

	ReloadTextureResources();
}


void FColorizer::ReloadTextureResources()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

void FColorizer::Reload(UObject* Object, struct FPropertyChangedEvent& Property)
{
	const FName PropertyName = Property.GetPropertyName();
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();

	if (DarkerNodesSettings.ReloadDefaultStyle)
	{
		UE_LOG(LogTemp, Log, TEXT("[Darker Nodes] Reloading default style..."));
		UEditorStyleSettings* StyleSettings = GetMutableDefault<UEditorStyleSettings>();
		StyleSettings->SelectionColor = FLinearColor(0.728f, 0.364f, 0.003f);
		StyleSettings->PressedSelectionColor = FLinearColor(0.701f, 0.225f, 0.003f);
		StyleSettings->InactiveSelectionColor = FLinearColor(0.25f, 0.25f, 0.25f);
		StyleSettings->EditorChildWindowBackgroundOverride = FSlateBrush();
		StyleSettings->EditorMainWindowBackgroundOverride = FSlateBrush();
		StyleSettings->RegularColor = FLinearColor(0.035, 0.035, 0.035);
		StyleSettings->RuleColor = FLinearColor(0.008, 0.008, 0.008);
		StyleSettings->CenterColor = FLinearColor::Black;
		StyleSettings->bUseGrid = true;
		StyleSettings->SaveConfig();
		UE_LOG(LogTemp, Log, TEXT("[Darker Nodes] Done!"));

		DarkerNodesSettings.ReloadDefaultStyle = false;
	}

	if (DarkerNodesSettings.ReloadTextureResources)
	{
		ReloadTextureResources();
		DarkerNodesSettings.ReloadTextureResources = false;
	}

	if (!DarkerNodesSettings.MasterActivate)
	{
		return;
	}

	ISettingsEditorModule* SettingsEditorModule = FModuleManager::GetModulePtr<ISettingsEditorModule>("SettingsEditor");
	if (SettingsEditorModule)
	{
		UEditorStyleSettings* StyleSettings = GetMutableDefault<UEditorStyleSettings>();
		StyleSettings->SelectionColor = FLinearColor::FromSRGBColor(Primary);
		StyleSettings->PressedSelectionColor = FLinearColor::FromSRGBColor(Primary);
		StyleSettings->InactiveSelectionColor = FLinearColor::FromSRGBColor(HoverBase);
		StyleSettings->bUseGrid = DarkerNodesSettings.UseBlueprintGrid;
		StyleSettings->SaveConfig();

		SettingsEditorModule->OnApplicationRestartRequired();
	}
}

FColor FColorizer::MixColor(FColor Base, FColor Layer, float Alpha)
{
	Base.R = FMath::Lerp(Base.R, Layer.R, Alpha);
	Base.G = FMath::Lerp(Base.G, Layer.G, Alpha);
	Base.B = FMath::Lerp(Base.B, Layer.B, Alpha);
	return Base;
}

FColor FColorizer::OffsetColor(FColor Base, int Offset)
{
	Base.R += Offset;
	Base.G += Offset;
	Base.B += Offset;
	return Base;
}
