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

	
	// ************************** Create ************************************

	// create root json obj to add data
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Make")
	static FKKJsonObject Kk_CreateJsonObject();

	// create root array to add data
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|Make")
	static FKKJsonValueArray KK_CreateJsonArray();

	// ************************** Add OBJ Data ********************************

	// add int value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & KK_SetValue_Int(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , int32 Value);
	
	// add float value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & KK_SetValue_Float(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , float Value);

	// add bool value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & KK_SetValue_Bool(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , bool Value);

	// add string value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & KK_SetValue_String(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , FString Value);

	// add object value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & Kk_SetValue_Object(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , UPARAM(ref) FKKJsonObject & Value);

	// add array value with obj
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonObject & KK_SetValue_Array(UPARAM(ref) FKKJsonObject & kkJsonObject, FString KeyName , UPARAM(ref) FKKJsonValueArray & Value);

	
	// ************************** Add Array Data ********************************
	// add int value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_Int(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,int32 Value);

	// add float value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_Float(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,float Value);

	// add bool value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_Bool(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,bool Value);

	// add FString value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_FString(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,FString Value);

	// add object value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_Object(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,UPARAM(ref) FKKJsonObject & Value);

	// add array value with array
	UFUNCTION(BlueprintCallable,Category="KKJson|Set")
	static FKKJsonValueArray & KK_SetArrayValue_Array(UPARAM(ref) FKKJsonValueArray & KKJsonArrayValue,UPARAM(ref) FKKJsonValueArray & Value);
	
	// ************************* convert obj/array to string *************************

	// get json string from objecy
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|To")
	static FString KK_GetJsonString_Object(UPARAM(ref) FKKJsonObject & KKJsonObject);

	// get json string from array
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="KKJson|To")
	static FString KK_GetJsonString_Array(UPARAM(ref) FKKJsonValueArray & KKJsonValueArray);
};
