/* Copyright (C) 2020 Hugo ATTAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "Colorizer.h"

void FColorizer::ColorIcons()
{
	UDarkerNodesSettings& DarkerNodesSettings = *GetMutableDefault<UDarkerNodesSettings>();

	if (DarkerNodesSettings.UseCustomIcons)
	{
		// Opacity 50%

		// Red #b20000
		// Blue #0060b2
		// Yellow #dfb300
		// Green #3aa111

		AddMenuIcon(EditorStyle, "Kismet.Status.Unknown", "/Menu/CompileStatus_Working.png");
		AddMenuIcon(EditorStyle, "Kismet.Status.Error", "/Menu/CompileStatus_Fail.png");
		AddMenuIcon(EditorStyle, "Kismet.Status.Good", "/Menu/CompileStatus_Good.png");
		AddMenuIcon(EditorStyle, "Kismet.Status.Warning", "/Menu/CompileStatus_Warning.png");

		AddMenuIcon(EditorStyle, "AssetEditor.SaveAsset", "/Menu/icon_SaveAsset_40x.png");
		AddMenuIcon(EditorStyle, "SystemWideCommands.FindInContentBrowser", "/Menu/icon_toolbar_genericfinder_40px.png");
		AddMenuIcon(EditorStyle, "BlueprintEditor.FindInBlueprint", "/Menu/icon_Blueprint_Find_40px.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.FindInMaterial", "/Menu/icon_Blueprint_Find_40px.png");
		AddMenuIcon(EditorStyle, "TranslationEditor.Search", "/Menu/icon_Blueprint_Find_40px.png");

		AddMenuIcon(EditorStyle, "FullBlueprintEditor.EditGlobalOptions", "/Menu/icon_Blueprint_Options_40px.png");
		AddMenuIcon(EditorStyle, "FullBlueprintEditor.EditClassDefaults", "/Menu/icon_BlueprintEditor_Defaults_40x.png");
		AddMenuIcon(EditorStyle, "FullBlueprintEditor.SwitchToBlueprintDefaultsMode", "/Menu/icon_BlueprintEditor_Defaults_40x.png");
		AddMenuIcon(EditorStyle, "BlueprintEditor.EnableSimulation", "/Menu/icon_Enable_Simulation_40px.png");
		AddMenuIcon(EditorStyle, "PlayWorld.PlayInViewport", "/Menu/icon_playInSelectedViewport_40x.png");
		AddMenuIcon(EditorStyle, "GraphEditor.ToggleHideUnrelatedNodes", "/Menu/icon_HideUnrelatedNodes_40x.png");

		AddMenuIcon(EditorStyle, "LevelEditor.Build", "/Menu/icon_build_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.Recompile", "/Menu/icon_compile_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.OpenContentBrowser", "/Menu/icon_ContentBrowser_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.EditorModes", "/Menu/icon_Editor_Modes_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.GameSettings", "/Menu/icon_game_settings_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.OpenLevelBlueprint", "/Menu/icon_kismet2_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.OpenMarketplace", "/Menu/icon_Marketplace_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.EditMatinee", "/Menu/icon_matinee_40x.png");

		AddMenuIcon(EditorStyle, "LevelEditor.SourceControl", "/Menu/icon_source_control_40x.png");
		AddMenuIcon(EditorStyle, "LevelEditor.SourceControl.On", "/Menu/icon_source_control_40x_on.png");
		AddMenuIcon(EditorStyle, "LevelEditor.SourceControl.Off", "/Menu/icon_source_control_40x_off.png");
		AddMenuIcon(EditorStyle, "LevelEditor.SourceControl.Unknown", "/Menu/icon_source_control_40x_unknown.png");
		AddMenuIcon(EditorStyle, "LevelEditor.SourceControl.Problem", "/Menu/icon_source_control_40x_problem.png");

		AddMenuIcon(EditorStyle, "MaterialEditor.Apply", "/Menu/icon_MatEd_Apply_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.CameraHome", "/Menu/icon_MatEd_Home_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.ToggleRealtimeExpressions", "/Menu/icon_MatEd_LiveNodes_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.AlwaysRefreshAllPreviews", "/Menu/icon_MatEd_Refresh_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.ToggleLivePreview", "/Menu/icon_MatEd_LivePreview_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.ToggleMaterialStats", "/Menu/icon_MatEd_Stats_40x.png");
		AddMenuIcon(EditorStyle, "MaterialEditor.TogglePlatformStats", "/Menu/icon_MobileStats_40x.png");

		AddMenuIcon(EditorStyle, "PlayWorld.PausePlaySession", "/Menu/icon_pause_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.StopPlaySession", "/Menu/icon_stop_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.PossessPlayer", "/Menu/icon_possess_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.EjectFromPlayer", "/Menu/icon_eject_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.RepeatLastLaunch", "/Menu/icon_PlayOnDevice_40px.png");
		AddMenuIcon(EditorStyle, "PlayWorld.PlayInNewProcess", "/Menu/icon_PlayStandalone_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.PlayInEditorFloating", "/Menu/icon_playInWindow_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.PlayInMobilePreview", "/Menu/icon_PlayMobilePreview_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.LateJoinSession", "/Menu/icon_simulate_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.ResumePlaySession", "/Menu/icon_simulate_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.Simulate", "/Menu/icon_simulate_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.RepeatLastPlay", "/Menu/icon_simulate_40x.png");

		AddMenuIcon(EditorStyle, "PlayWorld.SingleFrameAdvance", "/Menu/icon_advance_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.ShowCurrentStatement", "/Menu/icon_findnode_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.StepOut", "/Menu/icon_DebugStepOut_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.StepInto", "/Menu/icon_DebugStepIn_40x.png");
		AddMenuIcon(EditorStyle, "PlayWorld.StepOver", "/Menu/icon_DebugStepOver_40x.png");

		AddMenuIcon(EditorStyle, "BTEditor.SwitchToBehaviorTreeMode", "/Menu/BehaviorTreeMode_40x.png");
		AddMenuIcon(EditorStyle, "UMGEditor.SwitchToDesigner", "/Menu/Designer_40x.png");
		AddMenuIcon(EditorStyle, "FullBlueprintEditor.SwitchToScriptingMode", "/Menu/icon_BlueprintEditor_EventGraph_40x.png");
		AddMenuIcon(CoreStyle, "WidgetReflector.Icon", "/Menu/icon_tab_WidgetReflector_40x.png");
	}

	ApplyImageBrush(EditorStyle, "EditorViewport.LocationGridSnap", "/Icons/Viewport/LocationGridSnap.png", Icon14, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RotationGridSnap", "/Icons/Viewport/RotationGridSnap.png", Icon14, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.Layer2DSnap", "/Icons/Viewport/Layer2DSnap.png", Icon14, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.ScaleGridSnap", "/Icons/Viewport/ScaleGridSnap.png", Icon14, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.ToggleSurfaceSnapping", "/Icons/Viewport/icon_surface_snapping_14px.png", Icon14, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RelativeCoordinateSystem_Local", "/Icons/Viewport/icon_axis_local_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RelativeCoordinateSystem_Local.Small", "/Icons/Viewport/icon_axis_local_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RelativeCoordinateSystem_World", "/Icons/Viewport/icon_axis_world_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RelativeCoordinateSystem_World.Small", "/Icons/Viewport/icon_axis_world_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.CamSpeedSetting", "/Icons/Viewport/icon_CameraSpeed_24x16px.png", FVector2D(24, 16), TextColor);

	ApplyImageBrush(EditorStyle, "DetailsView.EditRawProperties", "/Icons/DetailsView/icon_PropertyMatrix_16px.png", Icon16, TextColor);

	ApplyImageBrush(EditorStyle, "CurveEd.Visible", "/Icons/DetailsView/icon_visible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "CurveEd.VisibleHighlight", "/Icons/DetailsView/icon_visible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "CurveEd.Invisible", "/Icons/DetailsView/icon_invisible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "CurveEd.InvisibleHighlight", "/Icons/DetailsView/icon_invisible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "Level.VisibleIcon16x", "/Icons/DetailsView/icon_visible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "Level.VisibleHighlightIcon16x", "/Icons/DetailsView/icon_visible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "Level.NotVisibleIcon16x", "/Icons/DetailsView/icon_invisible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "Level.NotVisibleHighlightIcon16x", "/Icons/DetailsView/icon_invisible_16px.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "GenericViewButton", "/Icons/DetailsView/icon_visible_16px.png", Icon16, TextColor);

	ApplyImageBrush(EditorStyle, "EditorViewport.TranslateMode", "/Icons/Viewport/icon_translateb_16x.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.RotateMode", "/Icons/Viewport/icon_rotateb_16x.png", Icon16, TextColor);
	ApplyImageBrush(EditorStyle, "EditorViewport.ScaleMode", "/Icons/Viewport/icon_scaleb_16x.png", Icon16, TextColor);

	ApplyImageBrush(EditorStyle, "TimelineEditor.AddFloatTrack", "/Icons/Timeline/icon_TrackAddFloat_36x24px.png", FVector2D(36, 24), TextColor);
	ApplyImageBrush(EditorStyle, "TimelineEditor.AddVectorTrack", "/Icons/Timeline/icon_TrackAddVector_36x24px.png", FVector2D(36, 24), TextColor);
	ApplyImageBrush(EditorStyle, "TimelineEditor.AddEventTrack", "/Icons/Timeline/icon_TrackAddEvent_36x24px.png", FVector2D(36, 24), TextColor);
	ApplyImageBrush(EditorStyle, "TimelineEditor.AddColorTrack", "/Icons/Timeline/icon_TrackAddColor_36x24px.png", FVector2D(36, 24), TextColor);
	ApplyImageBrush(EditorStyle, "TimelineEditor.AddCurveAssetTrack", "/Icons/Timeline/icon_TrackAddCurve_36x24px.png", FVector2D(36, 24), TextColor);
	ApplyImageBrush(EditorStyle, "TimelineEditor.DeleteTrack", "/Icons/Timeline/icon_TrackDelete_36x24px.png", FVector2D(36, 24), TextColor);
}
