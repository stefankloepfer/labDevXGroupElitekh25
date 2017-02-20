#include <iostream>
#include <unistd.h>

/*!
 *
 * @param argc
 * @param argv
 * @return
 * @details Prozesse können mit einer Posix-Funktion fork() erzeugt werden. Dabei wird von dem gerade laufenden
 * Vaterprozess eine vollständige Kopie erstellt, die an der gleichen Stelle wie der Vater weiterläuft.
 *
 *  pid_t fork()
 *  // -1 falls Fehler,
 *  // 0 im Sohnprozess,
 *  // !0, bin im Vater, ProzessID des Sohnes
 *
 * Durch eine Abfrage kann der laufende Prozess ermitteln, ob er der Vater oder der Sohn-Prozess ist um
 * dann entsprechend zu verzweigen. Spannend an unten stehendem Programm ist, dass nicht vorhersagbar ist,
 * wer zuerst seine Ausgabe gibt, der Vater- oder ein Sohn-Prozess, es wird von Mal zu Mal unterschiedlich sein.
 */
int main (int argc, char *argv[]) {
    pid_t pid     = fork ();
    int   context = 0; // prüfvariable initialisieren
    do /*!< ab in die Schleife um dauerhauft sachen auszgeben */
    {
        if (pid == 0) {
            for ( int i = 0; i < 3; ++i ) {
                std::cout << "Adresse von context-Kind\t" << &context << std::endl;
                std::cout << "Wert von context-Kind\t" << context << std::endl;
                ++context;
            }
//ab hier läuft erster Kind-Prozess

        } else if (pid == -1)
        {
            std::cout << "Fehler in der Matrix" << std::endl;
//ab hier läuft zweiter KindProzess
        } else
        {
            for ( int i = 0; i < 3; ++i ) {

                std::cout << "Adresse von context-Vater\t" << &context << std::endl;
                std::cout << "Wert von context-Vater:\t" << context << std::endl;
                ++context;
            }
//ab hier läuft Vaterprozess weiter
        }
        sleep (1);
    } while (true);

    return 0;
}


