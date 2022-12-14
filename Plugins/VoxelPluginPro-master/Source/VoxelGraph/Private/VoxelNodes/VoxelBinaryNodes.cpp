// Copyright 2021 Phyronnaz

#include "VoxelNodes/VoxelBinaryNodes.h"
#include "VoxelNodes/VoxelNodeHelpers.h"
#include "Runtime/VoxelNodeType.h"
#include "Runtime/VoxelComputeNode.h"
#include "CppTranslation/VoxelCppConstructor.h"
#include "VoxelContext.h"
#include "NodeFunctions/VoxelNodeFunctions.h"

GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FLess, <)
GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FLessEqual, <=)
GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FGreater, >)
GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FGreaterEqual, >=)
GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FEqual, ==)
GENERATED_VOXELNODE_IMPL_BINARY_FLOAT(UVoxelNode_FNotEqual, !=)

GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_ILess, <)
GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_ILessEqual, <=)
GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_IGreater, >)
GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_IGreaterEqual, >=)
GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_IEqual, ==)
GENERATED_VOXELNODE_IMPL_BINARY_INT(UVoxelNode_INotEqual, !=)