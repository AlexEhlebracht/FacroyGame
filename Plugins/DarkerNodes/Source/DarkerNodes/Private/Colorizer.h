/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#pragma once

#include "CoreMinimal.h"

#include "DarkerNodesSettings.h"
#include "Styling/SlateStyle.h"

class FColorizer
{
public:
	FColorizer();
	void Color();

private:
	void ReloadStyle();

	// Colorizers
	void ColorText();
	void ColorGraph();
	void ColorButtons();
	void ColorCheckbox();
	void ColorPanel();
	void ColorWindow();
	void ColorIcons();

	static void ReloadTextureResources();

	// Inside Var
	FString ThemeDirectory;
	FSlateStyleSet* EditorStyle;
	FSlateStyleSet* CoreStyle;
	FSlateStyleSet* NiagaraStyle;

	FTextBlockStyle NormalText;
	FButtonStyle Button;

	// Utilities
	void Reload(UObject* Object, struct FPropertyChangedEvent& Property);
	FColor MixColor(FColor Base, FColor Layer, float Alpha);
	FColor OffsetColor(FColor Base, int Offset);

	void AddMenuIcon(FSlateStyleSet* StyleSet, FString Name, FString Location) const;
	void ApplyImageBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FVector2D Size) const;
	void ApplyImageBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FVector2D Size, FColor Color) const;
	void ApplyColorImageBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const;
	
	FSlateImageBrush ImageBrush(FString Location, FVector2D Size = FVector2D(16, 16)) const;
	FSlateImageBrush ImageBrush(FString Location, FVector2D Size, FColor Color) const;
	FSlateImageBrush ColorImageBrush(FColor Color = FColor::White, FVector2D Size = FVector2D(16, 16)) const;

	void ApplyBoxBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FMargin Margin = 0.25, FColor Color = FColor::White) const;
	void ApplyColorBoxBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const;
	FSlateBoxBrush BoxBrush(FString Location, FVector2D Size, FMargin Margin = 0.25, FColor Color = FColor::White) const;
	FSlateBoxBrush ColorBoxBrush(FColor Color = FColor::White, FMargin Margin = FMargin(0.25)) const;
	void RemoveBoxBrush(FName Name) const;

	void ApplyColorBorderBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const;
	FSlateBorderBrush BorderBrush(FString Location, FMargin Margin = FMargin(0.25), FColor Color = FColor::White) const;

	FString GetThemeColor() const;

	// Icons

	FVector2D Icon0 = FVector2D::ZeroVector;
	FVector2D Icon8 = FVector2D(8, 8);
	FVector2D Icon12 = FVector2D(12, 12);
	FVector2D Icon14 = FVector2D(14, 14);
	FVector2D Icon16 = FVector2D(16, 16);
	FVector2D Icon20 = FVector2D(20, 20);
	FVector2D Icon24 = FVector2D(24, 24);
	FVector2D Icon32 = FVector2D(32, 32);
	FVector2D Icon40 = FVector2D(40, 40);
	FVector2D Icon256 = FVector2D(256, 256);

	// Colors

	FColor DebugRed = FColor(255, 0, 0);
	FColor DebugGreen = FColor(0, 255, 0);
	FColor DebugBlue = FColor(0, 0, 255);

	FColor GreyDark = FColor(20, 20, 20);
	FColor GreyBase = FColor(40, 40, 40);
	FColor GreyLight = FColor(120, 120, 120);

	FColor Primary;
	FColor HoverDark;
	FColor HoverBase;
	FColor HoverBaseBright;

	FColor TextColor = FColor(200, 200, 200);
	FColor TextShadow = FColor(10, 10, 10);

	FColor ButtonPrimary = FColor(0, 96, 178);
	FColor ButtonSuccess = FColor(58, 161, 17);
	FColor ButtonInfo = FColor(0, 96, 178);
	FColor ButtonWarning = FColor(223, 179, 0);
	FColor ButtonDanger = FColor(178, 0, 0);

	FColor ImageColor = FColor(255,255,255);
};
