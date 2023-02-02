#pragma once

#include "KKJsonType.generated.h"

USTRUCT(BlueprintType)
struct FKKJsonObject
{
	GENERATED_USTRUCT_BODY()
	TSharedPtr<FJsonObject> JsonObject;
	FKKJsonObject(TSharedPtr<FJsonObject> InJsonObject):JsonObject(InJsonObject){}
	FKKJsonObject(){}
};

USTRUCT(BlueprintType)
struct FKKJsonValueArray
{
	GENERATED_USTRUCT_BODY()
	TArray<TSharedPtr<FJsonValue>> JsonValueArray;
	FKKJsonValueArray(TArray<TSharedPtr<FJsonValue>> InJsonValueArray):JsonValueArray(InJsonValueArray){}
	FKKJsonValueArray(){}
};

USTRUCT(BlueprintType)
struct FKKJsonValue
{
	GENERATED_USTRUCT_BODY()
	TSharedPtr<FJsonValue> JsonValue;
	FKKJsonValue(TSharedPtr<FJsonValue> InJsonValue):JsonValue(InJsonValue){}
	FKKJsonValue(){}
};
