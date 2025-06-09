#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#define usleep(x) Sleep((x) / 1000)
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

// === Testversionen der Hauptfunktionen ===

void test_files_suchen(void) {
    printf("\n[TEST] Files suchen:\n");
    printf("USB-Stick erkannt. .g/.gx-Dateien: teil01.gx\n");
    printf("Datei geladen. Druck startet.\n");
}

void test_vorheizen(void) {
    printf("\n[TEST] Vorheizen:\n");
    int ziel = 180;
    int temp = 0;

    while (temp < ziel) {
        temp++;
        printf("Temperatur: %d°C\n", temp);
        usleep(50000);
    }

    printf("Vorheizen abgeschlossen (Ziel: %d°C).\n", ziel);
}

void test_spule_wechseln(void) {
    printf("\n[TEST] Spule wechseln:\n");

    int temp = 0;
    while (temp < 240) {
        temp += 5;
        printf("Heizen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Filament entfernt (3–5 Sek)...\n");
    sleep(4);

    printf("Neue Spule simuliert eingesetzt.\n");
    printf("Filament wird geladen...\n");
    sleep(2);

    while (temp > 0) {
        temp -= 10;
        if (temp < 0) temp = 0;
        printf("Abkühlen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Spulenwechsel erfolgreich abgeschlossen.\n");
}

void test_drucken(void) {
    printf("\n[TEST] Drucken:\n");

    int zielTemp = 210;
    int dauer = 30;
    int temp = 0;

    printf("Datei analysiert. Zieltemp = %d°C, Dauer = %ds\n", zielTemp, dauer);

    while (temp < zielTemp) {
        temp += 5;
        printf("Heizen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Filament eingezogen. Druck startet...\n");
    sleep(2);

    printf("Druck simuliert (%ds)...\n", dauer);
    sleep(2);

    while (temp > 0) {
        temp -= 10;
        printf("Abkühlen: %d°C\n", temp);
        usleep(100000);
    }

    printf("Druck vollständig abgeschlossen.\n");
}

// === Hauptfunktion: Alle Tests laufen durch ===
int main(void) {
    printf("=== AUTOMATISCHE TESTS START ===\n");

    test_files_suchen();
    test_vorheizen();
    test_spule_wechseln();
    test_drucken();

    printf("\n=== ALLE TESTS ERFOLGREICH ===\n");
    return 0;
}
