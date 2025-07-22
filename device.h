#pragma once
#include <ntddk.h>

extern PDEVICE_OBJECT g_DeviceObject;

NTSTATUS CreateDevice(PDRIVER_OBJECT DriverObject);
void DeleteDevice();
