/*!
 * @author Mirko Matosin
 * @date 22.2.2017
 * @brief 1. Erzeugen Sie 2 Prozesse durch Fork. Jeder Prozess soll eine eigene main_x() bekommen,
 * die nach dem Fork() aufgerufen wird. Lassen Sie jeden Prozess in einer großen Schleife
 * jeweils einen unterschiedlichen Text per printf oder cout ausgeben
 *
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
 * Beide Prozesse haben komplett getrennte Speiherbereiche. Obwohl die Adresse von "context" gleich ist, so ist dies
 * nur im Virtual Memory der Fall. Die LookupMemoryTable hat eigene werte für beide Adressen.
 * Adresse von context-Vater	0x7ffc9664f440
 * Wert von context-Vater:	14
 * Adresse von context-Kind	0x7ffc9664f440
 * Wert von context-Kind	12
 * Clone the calling process, creating an exact copy.
 * Return -1 for errors, 0 to the new process,
 * and the process ID of the new process to the old process.
 */
#include <iostream>
#include <unistd.h>
#include "mm_standard_usages.h"
#include "boost/thread"

void printstuff ();

int main(int argc, char *argv[]) {
  pid_t pid = fork();
  i32 context = 0; // prüfvariable initialisieren

  do /*!< ab in die Schleife um dauerhauft sachen auszgeben */
  {
    if (pid == 0) {
      for (i8 i = 0; i < 3; ++i) {
        std::cout << "Adresse von context-Kind\t" << &context << std::endl;
        std::cout << "Wert von context-Kind\t" << context << std::endl;
        ++context;
      }
//ab hier läuft erster Kind-Prozess

    } else if (pid == -1) {
      std::cout << "Fehler in der Matrix" << std::endl;
      break;
//ab hier läuft zweiter KindProzess
    } else {
      for (i8 i = 0; i < 3; ++i) {

        std::cout << "Adresse von context-Vater\t" << &context << std::endl;
        std::cout << "Wert von context-Vater:\t" << context << std::endl;
        ++context;
      }
//ab hier läuft Vaterprozess weiter
    }
    sleep(1);
  } while (true);

  return 0;
}

void print












/*

#include <windows.h>

int main(int argc, char *argv[])
{

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    CreateProcess( NULL,   // No module name (use command line)
                   "cmd.exe /c c:\\start.bat",        // Command line
                   NULL,           // Process handle not inheritable
                   NULL,           // Thread handle not inheritable
                   FALSE,          // Set handle inheritance to FALSE
                   0,              // No creation flags
                   NULL,           // Use parent's environment block
                   NULL,           // Use parent's starting directory
                   &si,            // Pointer to STARTUPINFO structure
                   &pi );           // Pointer to PROCESS_INFORMATION structure

    return 0;
}
*/
