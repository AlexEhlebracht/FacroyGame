/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#pragma once

#include "Engine/DeveloperSettings.h"
#include "DarkerNodesSettings.generated.h"

UENUM(BlueprintType)
enum class EHeaderStyle : uint8
{
	Gradient,
	Plain,
	Outline
};

UENUM(BlueprintType)
enum class EThemeLight : uint8
{
	Light UMETA(DisplayName = "Light (experimental, don't use it)"),
	Dark,
	Darker,
	Darkest
};

UENUM(BlueprintType)
enum class EThemeTemperature : uint8
{
	Cooler,
	Cool,
	Normal,
	Warm,
	Warmer
};

UENUM(BlueprintType)
enum class EPrimaryColor : uint8
{
	White,
	Orange,
	Cyan,
	Red,
	Purple,
	Green
};

UENUM(BlueprintType)
enum class EButtonPadding : uint8
{
	Small,
	Normal,
	Big
};

UENUM(BlueprintType)
enum class EBlueprintVarNodeLine : uint8
{
	Thin,
	Thick
};

UENUM(BlueprintType)
enum class EBlueprintVarNodeStyle : uint8
{
	Solid,
	DarkGlass,
	LightGlass
};


UCLASS(config = EditorPerProjectUserSettings, meta = (DisplayName = "Darker Nodes Plugin"))
class DARKERNODES_API UDarkerNodesSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UDarkerNodesSettings()
	{
		CategoryName = TEXT("Plugins");
		SectionName = TEXT("Darker Nodes Plugin");
	}

	/* -----[ Activation ] ----- */

	/* Activate or deactivate the whole plugin. Default: true */
	UPROPERTY(config, EditAnywhere, Category = "Activation")
	bool MasterActivate = true;

	/* Reload the default style. */
	UPROPERTY(config, EditAnywhere, Category = "Activation", meta = (EditCondition = "!MasterActivate"))
	bool ReloadDefaultStyle = false;

	/* -----[ Theme ] ----- */

	/* Variations of the grey background (making it lighter or darker). Default: darker */
	UPROPERTY(config, EditAnywhere, Category = "Theme")
	EThemeLight ThemeLight = EThemeLight::Darker;

	/* Variations of the grey background (making it more orange or cyan). Default: normal */
	UPROPERTY(config, EditAnywhere, Category = "Theme")
	EThemeTemperature ThemeTemperature = EThemeTemperature::Normal;

	/* Variations of the primary color. Default: orange */
	UPROPERTY(config, EditAnywhere, Category = "Theme")
	EPrimaryColor PrimaryColor = EPrimaryColor::Orange;

	/* Change the padding of buttons and text fields. Default: normal */
	UPROPERTY(config, EditAnywhere, Category = "Theme")
	EButtonPadding ButtonPadding = EButtonPadding::Normal;

	/* -----[ Blueprint ] ----- */

	/* Activate or deactivate the blueprint theme. Default: true */
	UPROPERTY(config, EditAnywhere, Category = "Blueprint")
	bool ActivateBlueprintTheme = true;

	/* Style of the VarNode top line. Default: thin */
	UPROPERTY(config, EditAnywhere, Category = "Blueprint", meta = (EditCondition = "ActivateBlueprintTheme"))
	EBlueprintVarNodeLine BlueprintVarNodeLine = EBlueprintVarNodeLine::Thin;

	/* Style of the VarNode style. Default: solid */
	UPROPERTY(config, EditAnywhere, Category = "Blueprint", meta = (EditCondition = "ActivateBlueprintTheme"))
	EBlueprintVarNodeStyle BlueprintVarNodeStyle = EBlueprintVarNodeStyle::Solid;

	/* Display a grid in the Blueprint graphs. Default: true */
	UPROPERTY(config, EditAnywhere, Category = "Blueprint")
	bool UseBlueprintGrid = true;

	/* Hide the origin axis. Default: false */
	UPROPERTY(config, EditAnywhere, Category = "Blueprint")
	bool DisableOriginAxis = false;

	/* -----[ Miscellaneous ] ----- */

	/* Use the thin icons of Darker Nodes. Default: true */
	UPROPERTY(config, EditAnywhere, Category = "Miscellaneous")
	bool UseCustomIcons = true;

	/* -----[ Customization ] ----- */

	/* Customize the backgrounds more in-depth. Default: false */
	UPROPERTY(config, EditAnywhere, Category = "Customization")
	bool UseGreyCustomization = false;

	/* Dark background of the theme. Default: RGB(20,20,20) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseGreyCustomization"))
	FColor GreyDark = FColor(20, 20, 20);

	/* Base background of the theme. Default: RGB(40,40,40) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseGreyCustomization"))
	FColor GreyBase = FColor(40, 40, 40);

	/* Light background of the theme. Default: RGB(80,80,80) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseGreyCustomization"))
	FColor GreyLight = FColor(80, 80, 80);

	/* Customize the colors more in-depth. Default: false */
	UPROPERTY(config, EditAnywhere, Category = "Customization")
	bool UseColorCustomization = false;

	/* Hover color on dark background. Default: RGB(229,110,23) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseColorCustomization"))
	FColor CustomPrimaryColor = FColor(229, 110, 23);

	/* Text color of the theme. Default: RGB(200,200,200) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseColorCustomization"))
	FColor TextColor = FColor(200, 200, 200);

	/* Customize the colors more in-depth. Default: false */
	UPROPERTY(config, EditAnywhere, Category = "Customization")
	bool UseButtonColorCustomization = false;

	/* Color for primary buttons. Default: RGB(0,96,178) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseButtonColorCustomization"))
	FColor ButtonPrimary = FColor(0, 96, 178);

	/* Color for success buttons. Default: RGB(58,161,17) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseButtonColorCustomization"))
	FColor ButtonSuccess = FColor(58, 161, 17);

	/* Color for info buttons. Default: RGB(0,96,178) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseButtonColorCustomization"))
	FColor ButtonInfo = FColor(0, 96, 178);

	/* Color for warning buttons. Default: RGB(223,179,0) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseButtonColorCustomization"))
	FColor ButtonWarning = FColor(223, 179, 0);

	/* Color for danger buttons. Default: RGB(178,0,0) */
	UPROPERTY(config, EditAnywhere, Category = "Customization", meta = (EditCondition = "UseButtonColorCustomization"))
	FColor ButtonDanger = FColor(178, 0, 0);

	/* Force texture resources reload. */
	UPROPERTY(config, EditAnywhere, Category = "Debug")
	bool ReloadTextureResources = false;

	virtual FName GetContainerName() const override
	{
		return "Editor";
	}
};
