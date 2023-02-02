// Fill out your copyright notice in the Description page of Project Settings.


#include "KKJsonBlueprintFunctionLibrary.h"

bool UKKJsonBlueprintFunctionLibrary::KK_GetJsonObjectFromString(FString InString,FKKJsonObject & KKJsonObject)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(InString);

	if (FJsonSerializer::Deserialize(JsonReader,JsonObject))
	{
		KKJsonObject.JsonObject = JsonObject;
		return true;
	}
	else
	{
		return false;
	}
}

bool UKKJsonBlueprintFunctionLibrary::KK_GetJsonArrayFromString(FString InString,FKKJsonValueArray & KKJsonValueArray)
{
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(InString);
	TArray<TSharedPtr<FJsonValue>> JsonValueList;
	if (FJsonSerializer::Deserialize(JsonReader,JsonValueList))
	{
		KKJsonValueArray.JsonValueArray = JsonValueList;
		return true;
	}
	else
	{
		return false;
	}
}


// get
FKKJsonObject& UKKJsonBlueprintFunctionLibrary::KK_GetValue_Int(FKKJsonObject& KKJsonObject, FString KeyName,
	int32& Value)
{
	check(KKJsonObject.JsonObject != nullptr);
	Value = KKJsonObject.JsonObject->GetNumberField(KeyName);
	return KKJsonObject;
}

FKKJsonObject& UKKJsonBlueprintFunctionLibrary::KK_GetValue_Float(FKKJsonObject& KKJsonObject, FString KeyName,
	float& Value)
{
	check(KKJsonObject.JsonObject != nullptr);
	Value = KKJsonObject.JsonObject->GetNumberField(KeyName);
	return KKJsonObject;
}

FKKJsonObject& UKKJsonBlueprintFunctionLibrary::KK_GetValue_Bool(FKKJsonObject& KKJsonObject, FString KeyName,
	bool& Value)
{
	check(KKJsonObject.JsonObject != nullptr);
	Value = KKJsonObject.JsonObject->GetBoolField(KeyName);
	return KKJsonObject;
}

FKKJsonObject& UKKJsonBlueprintFunctionLibrary::KK_GetValue_String(FKKJsonObject& KKJsonObject, FString KeyName,
	FString& Value)
{
	check(KKJsonObject.JsonObject != nullptr);
	Value = KKJsonObject.JsonObject->GetStringField(KeyName);
	return KKJsonObject;
}

FKKJsonValueArray UKKJsonBlueprintFunctionLibrary::KK_GetValue_Array(FKKJsonObject& KKJsonObject, FString KeyName)
{
	check(KKJsonObject.JsonObject != nullptr);
	return FKKJsonValueArray(KKJsonObject.JsonObject->GetArrayField(KeyName));
}

FKKJsonObject UKKJsonBlueprintFunctionLibrary::KK_GetValue_Object(FKKJsonObject& KKJsonObject, FString KeyName)
{
	check(KKJsonObject.JsonObject != nullptr);
	TSharedPtr<FJsonObject> tmp_obj = KKJsonObject.JsonObject->GetObjectField(KeyName);
	return FKKJsonObject(tmp_obj);
}

bool  UKKJsonBlueprintFunctionLibrary::KK_GetArrayValue(FKKJsonValueArray& kkJsonValueArray, int32 Index,FKKJsonValue & KKJsonValue)
{
	
	if (Index >= 0 && Index < kkJsonValueArray.JsonValueArray.Num())
	{
		KKJsonValue.JsonValue = kkJsonValueArray.JsonValueArray[Index];
		return true;
	}
	else
	{
		return false;
	}
}

// convert json value to data
int32 UKKJsonBlueprintFunctionLibrary::KK_AsInt(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return KKJsonValue.JsonValue->AsNumber();
}

float UKKJsonBlueprintFunctionLibrary::KK_AsFloat(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return KKJsonValue.JsonValue->AsNumber();
}

bool UKKJsonBlueprintFunctionLibrary::KK_AsBool(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return KKJsonValue.JsonValue->AsBool();
}

FString UKKJsonBlueprintFunctionLibrary::KK_AsString(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return KKJsonValue.JsonValue->AsString();
}

FKKJsonObject UKKJsonBlueprintFunctionLibrary::KK_AsObject(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return FKKJsonObject(KKJsonValue.JsonValue->AsObject());
}

FKKJsonValueArray UKKJsonBlueprintFunctionLibrary::KK_AsArray(FKKJsonValue& KKJsonValue)
{
	check(KKJsonValue.JsonValue!=nullptr);
	return FKKJsonValueArray(KKJsonValue.JsonValue->AsArray());
}
