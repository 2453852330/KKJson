// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KKJsonType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KKJsonBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KKJSON_API UKKJsonBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// init json obj/array
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Init")
	static bool KK_GetJsonObjectFromString(FString InString,FKKJsonObject & KKJsonObject);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Init")
	static bool KK_GetJsonArrayFromString(FString InString,FKKJsonValueArray & KKJsonValueArray);


	// get json data

	// return current json object , helper to linker worker
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonObject & KK_GetValue_Int(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName,int32 & Value);
	// return current json object , helper to linker worker
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonObject & KK_GetValue_Float(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName,float & Value);
	// return current json object , helper to linker worker
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonObject & KK_GetValue_Bool(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName,bool & Value);
	// return current json object , helper to linker worker
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonObject & KK_GetValue_String(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName,FString & Value);


	
	// get json obj/array , return new json obj/array ;
	
	// return the new json value array 
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonValueArray  KK_GetValue_Array(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName);
	// return the new json object
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static FKKJsonObject  KK_GetValue_Object(UPARAM(ref) FKKJsonObject & KKJsonObject,FString KeyName);

	// get array data
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Get")
	static bool  KK_GetArrayValue(UPARAM(ref) FKKJsonValueArray & kkJsonValueArray,int32 Index,FKKJsonValue & KKJsonValue);

	// convert json value to other data
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static int32 KK_AsInt(UPARAM(ref) FKKJsonValue & KKJsonValue);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static float KK_AsFloat(UPARAM(ref) FKKJsonValue & KKJsonValue);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static bool KK_AsBool(UPARAM(ref) FKKJsonValue & KKJsonValue);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static FString KK_AsString(UPARAM(ref) FKKJsonValue & KKJsonValue);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static FKKJsonObject KK_AsObject(UPARAM(ref) FKKJsonValue & KKJsonValue);
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Convert")
	static FKKJsonValueArray KK_AsArray(UPARAM(ref) FKKJsonValue & KKJsonValue);
	
};
