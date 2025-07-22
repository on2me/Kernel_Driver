#include "device.h"


PDEVICE_OBJECT g_DeviceObject = nullptr; //Device erstmal null
UNICODE_STRING g_DeviceName = RTL_CONSTANT_STRING(L"\\Device\\Zenith");
UNICODE_STRING g_SymbolicLink = RTL_CONSTANT_STRING(L"\\DosDevices\\Zenith");

NTSTATUS CreateDevice(PDRIVER_OBJECT DriverObject) { // Funktion zum Erstellen des Device Objects
	NTSTATUS status = IoCreateDevice( // IoCreateDevice erstellt ein Device Object
		DriverObject, // Driver Object, der das Device erstellt
		0, // Device Extension Size, hier 0, da keine Erweiterung ben�tigt wird
		&g_DeviceName, // Device Name wird hier �bergeben
		FILE_DEVICE_UNKNOWN, // Device Type, hier FILE_DEVICE_UNKNOWN, da es sich um ein generisches Ger�t handelt
		0, // Device Characteristics, hier 0, da keine speziellen Eigenschaften ben�tigt werden
		FALSE, // Device wird nicht als exclusive markiert
		&g_DeviceObject // Device Object wird hier erstellt
	); // �berpr�fen des R�ckgabestatus von IoCreateDevice

	if (!NT_SUCCESS(status)) {
		return status; // Fehler beim Erstellen des Device Objects
	}

	status = IoCreateSymbolicLink(&g_SymbolicLink, &g_DeviceName); // Symbolischen Link erstellen, 
								 //Symbolic Link zeigt auf das Device Object per Device Name

	if (!NT_SUCCESS(status)) { // Fehler beim Erstellen des symbolischen Links
		IoDeleteDevice(g_DeviceObject); // Device Object l�schen, da der Link nicht erstellt werden konnte
	}

	return status; // Erfolgreich, gibt den Status zur�ck
}

void DeleteDevice() { // Funktion zum L�schen des Device Objects und des symbolischen Links
	IoDeleteSymbolicLink(&g_SymbolicLink); // Symbolischen Link l�schen
	IoDeleteDevice(g_DeviceObject); // Device Object l�schen
}