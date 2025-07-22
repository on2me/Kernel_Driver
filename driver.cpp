#include <ntddk.h>
#include "process.h"
#include "device.h"

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    NTSTATUS status = CreateDevice(DriverObject);
    if (!NT_SUCCESS(status)) return status;

    status = RegisterProcessCallback();
    if (!NT_SUCCESS(status)) {
        DeleteDevice(); // sauber wieder freigeben!
        return status;
    }

    DriverObject->DriverUnload = [](PDRIVER_OBJECT) {
        UnregisterProcessCallback();
        DeleteDevice(); // immer beim Unload freigeben!
        DbgPrint("[Zenith] Driver unloaded.\n");
        };

    return STATUS_SUCCESS;
}

