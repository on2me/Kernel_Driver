# Kernel-Level Driver Template (C/C++)

## English Description

This repository provides a **template** for developing a Windows kernel-level driver in **C/C++**.  
The main functionality of the driver is to **automatically terminate the Notepad process** when it is launched.

### Features
- Kernel-level process monitoring
- Termination of specific user-mode processes
- Clean and minimal driver structure for educational use

### Usage
> Kernel development requires deep technical knowledge.  
> Test in a virtual machine or safe environment to avoid system crashes.

1. Compile the driver using Visual Studio and the Windows Driver Kit (WDK)
2. Use `sc` or dedicated tools (e.g. OSR Loader) to load the driver
3. Launch Notepad to trigger the process termination

### License
This project is intended for **educational and research purposes only**.  
Use responsibly and at your own risk.

---

## Deutsche Beschreibung

Dieses Repository enthält eine **Vorlage** für die Entwicklung eines Windows-Kernel-Level-Treibers in **C/C++**.  
Die Hauptfunktion besteht darin, den **Notepad-Prozess automatisch zu beenden**, sobald er gestartet wird.

### Funktionen
- Überwachung von Prozessen auf Kernel-Ebene
- Beenden gezielter Benutzerprozesse
- Sauber strukturierter Beispielcode für Lernzwecke

### Nutzung
> Kernel-Entwicklung setzt fortgeschrittenes technisches Verständnis voraus.  
> Teste den Treiber nur in einer sicheren Umgebung oder virtuellen Maschine.

1. Kompiliere den Treiber mit Visual Studio und dem Windows Driver Kit (WDK)
2. Lade den Treiber mit `sc` oder Tools wie OSR Loader
3. Starte Notepad, um das Verhalten zu testen

### Lizenz
Dieses Projekt dient **ausschließlich zu Lern- und Forschungszwecken**.  
Verwendung erfolgt auf eigene Verantwortung.
