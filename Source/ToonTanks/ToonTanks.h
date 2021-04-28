// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(ToonTanks, Log, All);

#define TTLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define TTLOG_S(Verbosity) UE_LOG(ToonTanks, Verbosity, TEXT("%s"), *TTLOG_CALLINFO)
#define TTLOG(Verbosity, Format, ...) UE_LOG(ToonTanks, Verbosity, TEXT("%s %s"), *TTLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))