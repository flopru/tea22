#include <fmt/chrono.h>
#include <fmt/format.h>

#define MAX_NAME_LENGTH 42
//const unsigned int MAX_NAME_LENGTH 42

struct Person{
    unsigned int alter;
    float gewicht;
    char name[MAX_NAME_LENGTH];
};

auto main(int argc, char** argv) -> int
{
    Person paul;

    paul.gewicht = 47.3;
    paul.alter = 14;

    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Paul ist {} Jahre alt! \n", paul.alter);

    Person* pPers;
    pPers = &paul;

    fmt::print("Die Person auf auf die der Zeiger zeigt ist {} Jahre alt!\n", pPers->alter);

    Person paula = {18, 57.0, "Paula"};
    fmt::print("Paula ist {} Jahre alt!\n", paula.alter);

    pPers = &paula;
    fmt::print("Die Person auf auf die der Zeiger zeigt ist {} Jahre alt!\n", pPers->alter);


    // Festlegung eines Namens mittels Char-Array

    //paul.name = "Paul"; funktioniert nicht als nächstes kommt funktionierende Lösung
    strncpy(paul.name, "Paul", MAX_NAME_LENGTH);     // übergeben werden muss ein char Pointer des Ziels, der Quelle und am Ende wie viele Element maximal kopiert werden (Array wird als Zeiger behandelt genauso wir der String selbst --> deshalb hier keine Pointer-Schreibweise)
    fmt::print("Der Name von Paul ist {}\n", paul.name);


    // alternative Schreibweise mit konkreten Pointern
    const char* pName = "Paul jr der erste";
    strncpy(&paul.name[0], pName, MAX_NAME_LENGTH);
    fmt::print("Der Name von Paul ist {}\n", paul.name);


    strncpy(&paul.name[0], "Paul jr der zweite", MAX_NAME_LENGTH);
    fmt::print("Der Name von Paul ist {}\n", paul.name);

    // Bei Strukturen funktioniert die Zuweisung im Gegensatz zu Arrays (bei Strings brauchen wir die Copy-Funktion)
    paul = paula;           // Kopieren/Gleichsetzen funktioniert, sofern paul und paula gleich groß sind
    fmt::print("Der Name von Paul ist: {}\n", paul.name);


    // Mittels * (Derefferenzierungsoperator) wird festgelegt, dass Pointer aus die Stelle von paul zeigen soll
    *pPers = paul;
    fmt::print("Die Person auf die der Zeiger zeigt ist {} Jahre alt!\n", pPers->alter);


    return 0; /*exit gracefully*/
}