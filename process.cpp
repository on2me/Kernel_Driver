#include <ntifs.h>
#include "process.h"

extern "C" UCHAR* PsGetProcessImageFileName(PEPROCESS Process);

void ProcessNotifyRoutine(HANDLE ParentId, HANDLE ProcessId, BOOLEAN Create) {
    UNREFERENCED_PARAMETER(ParentId);
    if (!Create) return;

    PEPROCESS targetProcess = nullptr;
    NTSTATUS status = PsLookupProcessByProcessId(ProcessId, &targetProcess);
    if (!NT_SUCCESS(status)) return;

    const char* imageName = (const char*)PsGetProcessImageFileName(targetProcess);
    if (imageName && _stricmp(imageName, "notepad.exe") == 0) {
        DbgPrint("[Zenith] Notepad erkannt -> versuche zu beenden!\n");

        KAPC_STATE apc;
        KeStackAttachProcess((PKPROCESS)targetProcess, &apc);

        HANDLE hProc = nullptr;
        status = ObOpenObjectByPointer(
            targetProcess,
            OBJ_KERNEL_HANDLE,
            NULL,
            PROCESS_TERMINATE,
            *PsProcessType,
            KernelMode,
            &hProc
        );

        if (NT_SUCCESS(status)) {
            ZwTerminateProcess(hProc, 0);
            ZwClose(hProc);
            DbgPrint("[Zenith] Notepad beendet.\n");
        }
        else {
            DbgPrint("[Zenith] Fehler beim Öffnen: 0x%X\n", status);
        }

        KeUnstackDetachProcess(&apc);
    }

    ObDereferenceObject(targetProcess);
}

NTSTATUS RegisterProcessCallback() {
    return PsSetCreateProcessNotifyRoutine(ProcessNotifyRoutine, FALSE);
}

void UnregisterProcessCallback() {
    PsSetCreateProcessNotifyRoutine(ProcessNotifyRoutine, TRUE);
}