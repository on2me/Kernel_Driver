#pragma once

#include <ntddk.h>

#ifndef PROCESS_TERMINATE
#define PROCESS_TERMINATE 0x0001
#endif

NTSTATUS RegisterProcessCallback();
void UnregisterProcessCallback();
