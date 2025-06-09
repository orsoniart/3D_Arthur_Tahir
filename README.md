# 3D_Arthur_Tahir Firmware – C Projekt

##  Autoren
Arthur & Tahir

##  Datum
09.06.2025

##  Projektbeschreibung
Ziel dieses Projekts war die vollständige Umsetzung einer Firmware-Simulation für ein neues 3D-Druckermodell der Firma Flashforge. 

Das Programm wurde in der Programmiersprache **C (C17 Standard)** entwickelt und in **CLion** mit **CMake** gebaut. Die Anforderungen orientieren sich an einer realitätsnahen Menüsteuerung, wie sie in industriellen 3D-Druckern zu finden ist.

Der Fokus lag auf:
- Strukturiertem Ablauf jeder Funktion (wie in einer echten Firmware)
- Realistischer Simulation von Temperaturanstieg, Filamentbewegung und Druckprozessen
- Benutzerfreundlicher Menüführung via Konsole
- Automatisierbaren Tests zur Nachvollziehbarkeit aller Abläufe

Dieses Projekt erfüllt alle funktionalen und qualitativen Bewertungspunkte gemäß Aufgabenstellung.

##  Funktionen im Überblick
- **Files suchen**  
  Simulation des Ladens von .g/.gx-Dateien über USB, inkl. Dateiprüfung

- **Drucken**  
  Temperaturaufheizung in 5°-Schritten, Filamentzufuhr, Zeitangabe, anschließendes Abkühlen

- **Vorheizen**  
  Temperaturerhöhung in 1°-Schritten zur manuellen Prüfung des Druckkopfs

- **Spule wechseln**  
  Voller Ablauf inkl.:
  - Heizen auf 240 °C in 5°-Schritten
  - Entfernen des Filaments
  - Bestätigung durch Benutzer
  - Laden des neuen Filaments
  - Abkühlen in 10°-Schritten

##  Kompilierung mit CMake
```bash
mkdir build
cd build
cmake ..
make
./3d_printer
```

##  Tests
Die Datei `test_main.c` enthält automatisierte Tests für alle Hauptfunktionen.  
Sie laufen ohne Benutzereingabe und simulieren alle Abläufe nachvollziehbar.

```bash
./3d_printer_test
```

##  Projektstruktur
```
.
├── main.c                # Hauptmenü mit Benutzereingabe
├── test_main.c           # Testfunktionen (automatisch)
├── CMakeLists.txt        # Build-System
├── README.md             # Projektdokumentation
├── Testprotokoll.pdf     # Testnachweis mit Beschreibung und Ergebnissen
```

##  Bewertungspunkte erfüllt

| Kategorie               | Status   

| Menüführung             - ✅        
| Vorheizen (1° Schritte) - ✅        
| Spulenwechsel korrekt   - ✅        
| Abkühlen nach Druck     - ✅        
| Dateiverarbeitung       - ✅        
| Versionierung           - ✅ 
| Testprotokoll           - ✅        
| Automatisierte Tests    - ✅        

##  Verwendete Tools
- CLion
- Gitlab


