// Copyright 2021 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelPinCategory.h"
#include "VoxelGraphOutputs.generated.h"

class FVoxelCppConstructor;

using FVoxelGraphPermutationArray = TArray<uint32, TInlineAllocator<2>>;

inline uint32 GetTypeHash(const FVoxelGraphPermutationArray& Array)
{
	if (Array.Num() == 0)
	{
		return 0;
	}
	else
	{
		return FCrc::MemCrc32(Array.GetData(), Array.Num());
	}
}

USTRUCT()
struct FVoxelGraphOutput
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Outputs")
	FName Name;

	UPROPERTY(EditAnywhere, Category = "Outputs")
	EVoxelDataPinCategory Category = EVoxelDataPinCategory::Float;

	UPROPERTY()
	FGuid GUID;

	UPROPERTY(Transient)
	uint32 Index = -1;

	FString GetDeclaration(FVoxelCppConstructor& Constructor) const;
	FString GetRefDeclaration(FVoxelCppConstructor& Constructor) const;
	
	static const TArray<FVoxelGraphOutput> DefaultOutputs;
	static const TArray<FVoxelGraphPermutationArray> DefaultOutputsPermutations;
};

namespace FVoxelGraphOutputsUtils
{
	FString GetPermutationName(const FVoxelGraphPermutationArray& Permutation, const TMap<uint32, FVoxelGraphOutput>& Outputs);
	TMap<FName, uint32> GetSingleOutputsNamesMap(
		const TArray<FVoxelGraphPermutationArray>& Permutations,
		const TMap<uint32, FVoxelGraphOutput>& Outputs,
		EVoxelDataPinCategory CategoryFilter);
	VOXELGRAPH_API bool IsVoxelGraphOutputHidden(int32 Index);
}