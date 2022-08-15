/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"
#include "Classes/EditorStyleSettings.h"

void FColorizer::ColorGraph()
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();
	const FString Color = GetThemeColor();

	// Graph Nodes

	if (DarkerNodesSettings.ActivateBlueprintTheme)
	{
		ApplyBoxBrush(EditorStyle, "Graph.Node.Body", "/Graph/RegularNode_body.png");
		ApplyBoxBrush(EditorStyle, "Graph.Node.ColorSpill", "/Graph/RegularNode_color_spill.png");
		ApplyBoxBrush(EditorStyle, "Graph.PlayInEditor", "/Graph/Selection/" + Color + "/RegularNode_shadow_selected.png", 0.5);
		ApplyBoxBrush(EditorStyle, "Graph.Node.ShadowSelected", "/Graph/Selection/" + Color + "/RegularNode_shadow_selected.png", 0.5);
		RemoveBoxBrush("Graph.Node.Shadow");
		RemoveBoxBrush("Graph.Node.TitleGloss");
		RemoveBoxBrush("Graph.Node.TitleHighlight");

		switch (DarkerNodesSettings.BlueprintVarNodeStyle)
		{
		case EBlueprintVarNodeStyle::Solid:
			ApplyBoxBrush(EditorStyle, "Graph.VarNode.Body", "/Graph/VarNode_body_solid.png", FMargin(0.25, 0.5));
			break;
		case EBlueprintVarNodeStyle::DarkGlass:
			ApplyBoxBrush(EditorStyle, "Graph.VarNode.Body", "/Graph/VarNode_body_dark_glass.png", FMargin(0.25, 0.5));
			break;
		case EBlueprintVarNodeStyle::LightGlass:
			ApplyBoxBrush(EditorStyle, "Graph.VarNode.Body", "/Graph/VarNode_body_light_glass.png", FMargin(0.25, 0.5));
			break;
		}

		switch (DarkerNodesSettings.BlueprintVarNodeLine)
		{
		case EBlueprintVarNodeLine::Thin:
			ApplyImageBrush(EditorStyle, "Graph.VarNode.ColorSpill", "/Graph/VarNode_color_spill_thin.png", FVector2D(132, 28));
			break;
		case EBlueprintVarNodeLine::Thick:
			ApplyImageBrush(EditorStyle, "Graph.VarNode.ColorSpill", "/Graph/VarNode_color_spill_thick.png", FVector2D(132, 28));
			break;
		}

		ApplyBoxBrush(EditorStyle, "Graph.VarNode.ShadowSelected", "/Graph/Selection/" + Color + "/VarNode_shadow_selected.png", 0.5);
		RemoveBoxBrush("Graph.VarNode.Gloss");
		RemoveBoxBrush("Graph.VarNode.Shadow");


		ApplyBoxBrush(EditorStyle, "Graph.CollapsedNode.Body", "/Graph/RegularNode_body.png");
		ApplyBoxBrush(EditorStyle, "Graph.CollapsedNode.BodyColorSpill", "/Graph/CollapsedNode_Body_ColorSpill.png");

		// Pin Icons

		ApplyImageBrush(EditorStyle, "Graph.Pin.Connected_VarA", "/Elements/Pin/Pin_connected_VarA.png", FVector2D(15, 11));
		ApplyImageBrush(EditorStyle, "Graph.Pin.Disconnected_VarA", "/Elements/Pin/Pin_disconnected_VarA.png", FVector2D(15, 11));
		ApplyImageBrush(EditorStyle, "Graph.Pin.Connected", "/Elements/Pin/Pin_connected.png", FVector2D(11, 11));
		ApplyImageBrush(EditorStyle, "Graph.Pin.Disconnected", "/Elements/Pin/Pin_disconnected.png", FVector2D(11, 11));

		ApplyImageBrush(EditorStyle, "Graph.ExecPin.Connected", "/Elements/Pin/ExecPin_Connected.png", FVector2D(12, 16));
		ApplyImageBrush(EditorStyle, "Graph.ExecPin.Disconnected", "/Elements/Pin/ExecPin_Disconnected.png", FVector2D(12, 16));
		ApplyImageBrush(EditorStyle, "Graph.ExecPin.ConnectedHovered", "/Elements/Pin/ExecPin_Connected.png", FVector2D(12, 16), FColor(150, 150, 150));
		ApplyImageBrush(EditorStyle, "Graph.ExecPin.DisconnectedHovered", "/Elements/Pin/ExecPin_Disconnected.png", FVector2D(12, 16), FColor(150, 150, 150));
		ApplyImageBrush(EditorStyle, "Graph.ExecutionBubble", "/Elements/Pin/ExecutionBubble.png", FVector2D(16, 16));
	}

	// Grid

	EditorStyle->Set("Graph.Panel.GridLineColor", FLinearColor::FromSRGBColor(FColor(35, 35, 35)));
	GetMutableDefault<UEditorStyleSettings>()->RegularColor = FLinearColor::FromSRGBColor(FColor(35, 35, 35));
	
	EditorStyle->Set("Graph.Panel.GridRuleColor", FLinearColor::FromSRGBColor(FColor(21, 21, 21)));
	GetMutableDefault<UEditorStyleSettings>()->RuleColor = FLinearColor::FromSRGBColor(FColor(21, 21, 21));
	
	if (DarkerNodesSettings.DisableOriginAxis)
	{
		EditorStyle->Set("Graph.Panel.GridCenterColor", FLinearColor::FromSRGBColor(FColor(21, 21, 21)));
		GetMutableDefault<UEditorStyleSettings>()->CenterColor = FLinearColor::FromSRGBColor(FColor(21, 21, 21));
	}
	else
	{
		EditorStyle->Set("Graph.Panel.GridCenterColor", FLinearColor::FromSRGBColor(FColor(55, 55, 55)));
		GetMutableDefault<UEditorStyleSettings>()->CenterColor = FLinearColor::FromSRGBColor(FColor(55, 55, 55));
	}

	ApplyBoxBrush(EditorStyle, "Kismet.Comment.Background", "/Graph/Comment_Background.png");

	// Comments

	ApplyBoxBrush(EditorStyle, "Graph.Node.CommentBubble", "/Graph/CommentBubble.png");
	ApplyImageBrush(EditorStyle, "Graph.Node.CommentArrow", "/Graph/CommentBubbleArrow.png", Icon8);

	// Panel

	ApplyImageBrush(EditorStyle, "BlueprintEditor.Details.ArgUpButton", "/Icons/Graph/icon_FunctionArgUp.png", Icon16);
	ApplyImageBrush(EditorStyle, "BlueprintEditor.Details.ArgDownButton", "/Icons/Graph/icon_FunctionArgDown.png", Icon16);
}
