#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

// === Funktionsdeklarationen ===
void files_suchen(void);
void drucken(void);
void vorheizen(void);
void spule_wechseln(void);

// === Hauptmenü ===
int main(void) {
    int auswahl = -1;

    while (1) {
        printf("\n=== 3D DRUCKER MENÜ ===\n");
        printf("1 - Files suchen\n");
        printf("2 - Drucken\n");
        printf("3 - Vorheizen\n");
        printf("4 - Spule wechseln\n");
        printf("0 - Beenden\n");
        printf("Auswahl: ");
        if (scanf("%d", &auswahl) != 1) {
            printf("Ungültige Eingabe!\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        switch (auswahl) {
            case 1: files_suchen(); break;
            case 2: drucken(); break;
            case 3: vorheizen(); break;
            case 4: spule_wechseln(); break;
            case 0:
                printf("Programm wird beendet.\n");
                return 0;
            default:
                printf("Ungültige Auswahl!\n");
        }
    }
}

// === Funktion: Files suchen ===
void files_suchen(void) {
    printf("\n[FILES SUCHEN]\n");
    printf("USB-Stick verbunden. Suche nach .g und .gx Dateien...\n");
    printf("Datei gefunden: teil01.gx\n");
    printf("Datei geladen und wird gedruckt...\n");
}

// === Funktion: Drucken ===
void drucken(void) {
    printf("\n[DRUCKEN]\n");

    int zielTemp = 210;
    int dauer = 35;

    printf("Datei analysiert: Zieltemperatur = %d°C, Druckdauer = %d Sekunden\n", zielTemp, dauer);

    int temp = 0;
    while (temp < zielTemp) {
        temp += 5;
        if (temp > zielTemp) temp = zielTemp;
        printf("Heizen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Filament wird eingezogen (Uhrzeigersinn)...\n");
    sleep(2);

    printf("Druckvorgang gestartet (%d Sekunden)...\n", dauer);
    sleep(2); // Simulierter Druck

    printf("Druck abgeschlossen. Druckkopf kühlt ab...\n");

    while (temp > 0) {
        temp -= 10;
        if (temp < 0) temp = 0;
        printf("Abkühlen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Der Drucker ist fertig.\n");
}

// === Funktion: Vorheizen ===
void vorheizen(void) {
    int ziel = 0;
    printf("\n[VORHEIZEN]\nGewünschte Temperatur (°C): ");
    if (scanf("%d", &ziel) != 1 || ziel < 0) {
        printf("Ungültige Temperatur.\n");
        return;
    }

    int temp = 0;
    while (temp < ziel) {
        temp++;
        printf("Temperatur: %d°C\n", temp);
        usleep(50000);
    }

    printf("Vorheizen abgeschlossen.\n");
}

// === Funktion: Spule wechseln ===
void spule_wechseln(void) {
    char ok = 'n';

    printf("\n[SPULENWECHSEL]\n");

    printf("Deckel Öffnen und mit [OK] bestätigen: ");
    scanf(" %c", &ok);
    if (ok != 'o' && ok != 'O') {
        printf("Abbruch: Deckel nicht bestätigt.\n");
        return;
    }

    int temp = 0;
    while (temp < 240) {
        temp += 5;
        printf("Heizen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Temperatur erreicht.\n");
    printf("Filament wird entfernt (gegen Uhrzeigersinn)...\n");
    sleep(4); // 3–5 Sekunden

    printf("Neue Spule einsetzen und mit [o] bestätigen: ");
    scanf(" %c", &ok);
    if (ok != 'o' && ok != 'O') {
        printf("Abbruch: Spule nicht eingesetzt.\n");
        return;
    }

    printf("Filament wird geladen (Uhrzeigersinn)...\n");
    sleep(2);

    while (temp > 0) {
        temp -= 10;
        if (temp < 0) temp = 0;
        printf("Abkühlen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Spulenwechsel abgeschlossen.\n");
}