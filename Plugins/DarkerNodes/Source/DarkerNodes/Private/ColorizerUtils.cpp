/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"

void FColorizer::AddMenuIcon(FSlateStyleSet* StyleSet, FString Name, FString Location) const
{
	ApplyImageBrush(StyleSet, FName(Name), Location, Icon40, ImageColor);
	ApplyImageBrush(StyleSet, FName(Name + FString(".Small")), Location.Replace(TEXT("/Menu"), TEXT("/Menu/Small")), Icon20, ImageColor);
}

void FColorizer::ApplyImageBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FVector2D Size) const
{
	ApplyImageBrush(StyleSet, Name, Location, Size, ImageColor);
}

void FColorizer::ApplyImageBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FVector2D Size, FColor Color) const
{
	StyleSet->Set(
		Name,
		new FSlateImageBrush(
			ThemeDirectory + Location,
			Size,
			FLinearColor::FromSRGBColor(Color)
		)
	);
}

void FColorizer::ApplyColorImageBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const
{
	StyleSet->Set(
		Name,
		new FSlateImageBrush(
			ThemeDirectory + FString("/Blank.png"),
			FVector2D(16, 16),
			FLinearColor::FromSRGBColor(Color)
		)
	);
}


FSlateImageBrush FColorizer::ImageBrush(FString Location, FVector2D Size) const
{
	return ImageBrush(Location, Size, ImageColor);
}

FSlateImageBrush FColorizer::ImageBrush(FString Location, FVector2D Size, FColor Color) const
{
	return FSlateImageBrush(
		ThemeDirectory + Location,
		Size,
		FLinearColor::FromSRGBColor(Color)
	);
}

FSlateImageBrush FColorizer::ColorImageBrush(FColor Color, FVector2D Size) const
{
	return FSlateImageBrush(
		ThemeDirectory + FString("/Blank.png"),
		Size,
		FLinearColor::FromSRGBColor(Color)
	);
}

void FColorizer::ApplyBoxBrush(FSlateStyleSet* StyleSet, FName Name, FString Location, FMargin Margin, FColor Color) const
{
	StyleSet->Set(
		Name,
		new FSlateBoxBrush(
			ThemeDirectory + Location,
			Margin,
			FLinearColor::FromSRGBColor(Color)
		)
	);
}

void FColorizer::ApplyColorBoxBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const
{
	StyleSet->Set(
		Name,
		new FSlateBoxBrush(
			ThemeDirectory + FString("/Blank.png"),
			FMargin(0.25),
			FLinearColor::FromSRGBColor(Color)
		)
	);
}

FSlateBoxBrush FColorizer::ColorBoxBrush(FColor Color, FMargin Margin) const
{
	return FSlateBoxBrush(
		ThemeDirectory + FString("/Blank.png"),
		Margin,
		FLinearColor::FromSRGBColor(Color)
	);
}

FSlateBoxBrush FColorizer::BoxBrush(FString Location, FVector2D Size, FMargin Margin, FColor Color) const
{
	return FSlateBoxBrush(
		ThemeDirectory + Location,
		Size,
		Margin,
		FLinearColor::FromSRGBColor(Color)
	);
}

void FColorizer::RemoveBoxBrush(FName Name) const
{
	EditorStyle->Set(
		Name,
		new FSlateBoxBrush(
			ThemeDirectory + FString("/Transparent.png"),
			FMargin()
		)
	);
}

void FColorizer::ApplyColorBorderBrush(FSlateStyleSet* StyleSet, FName Name, FColor Color) const
{
	StyleSet->Set(
		Name,
		new FSlateBorderBrush(
			ThemeDirectory + FString("/Blank.png"),
			FMargin(0.25),
			FLinearColor::FromSRGBColor(Color)
		)
	);
}

FSlateBorderBrush FColorizer::BorderBrush(FString Location, FMargin Margin, FColor Color) const
{
	return FSlateBorderBrush(
		ThemeDirectory + Location,
		Margin,
		Color
	);
}

FString FColorizer::GetThemeColor() const
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();
	
	FString Color;

	// Cyan = Orange + 180
	// Purple = Orange - 100
	// Green = Orange + 80
	// Red = Orange - 25

	switch (DarkerNodesSettings.PrimaryColor)
	{
	case EPrimaryColor::Cyan:
		Color = "Cyan";
		break;
	case EPrimaryColor::Orange:
		Color = "Orange";
		break;
	case EPrimaryColor::White:
		Color = "White";
		break;
	case EPrimaryColor::Red:
		Color = "Red";
		break;
	case EPrimaryColor::Purple:
		Color = "Purple";
		break;
	case EPrimaryColor::Green:
		Color = "Green";
		break;
	}

	if (DarkerNodesSettings.ThemeLight == EThemeLight::Light)
	{
		Color = "Cyan_Light";
	}

	return Color;
}
