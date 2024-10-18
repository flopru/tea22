#include <fmt/chrono.h>
#include <fmt/format.h>

/* .bss Segment für nicht initialisierte Daten oder für Initialisierung mit 0*/
int foo;                                                // globale Variable ohne static --> mit static ist Variable nur innerhalb des Moduls sichtbar
static int foo2;

/* .data Segment für initialisierte Daten*/
int data = 43;
int data2 = 45;

/* .rodata Segment für konstante Daten*/
const int rodata = 43;
const int rodata2 = 45;

// Version für eine "Call by Value" Funktion
void doSomething(int value){                    // Beispiel für Funktionsaufruf mit 'Call by Value'
    value = value + 1;                          // an die Funktion wurde nur eine Kopie von Value übergeben, von dem her ist die Ausgabe um 1 größer, aber der Wert von Value bleibt gleich! --> 'Call by Value'
    fmt::print("doSomething, value{}\n", value);
}

// Version der vorherigen Variable als "Call by Reference"
void doSomethingPtr(int* ptr){
    *ptr = *ptr+1;                              // Zugriff auf den Wert an der Adresse ptr und Erhöhung um 1; anschließende Ablage an der Adresse in ptr
    fmt::print("doSomething, value{}\n", *ptr);
}

int* doReturnAPtr(){
    static int value = 4711;
    fmt::print("doReturnAPtr, value{}\n", value);
    return &value;
}

void doSomethingStatic(){
    static int value = 56;
    value = value +1;
    fmt::print("doSomethingStatic, value{}\n", value);
}

auto main(int argc, char **argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);
    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));

    doSomething(42);
    int bar = 42;
    // Der Inhalt von bar wird in Funktion hineinkopiert; der Wert von bar selbst bleibt gleich
    doSomething(bar);                                   
    fmt::print("The value of bar is: {}\n", bar);

    // an Funktion wird keine Kopie von bar übergeben, sondern die Adresse und damit kann der Wert in bar verändert werden
    doSomethingPtr(&bar);                               // Der Inhalt von bar wird in Funktion hineinkopiert; der Wert von bar selbst bleibt gleich
    fmt::print("The value of bar after 'doSomethingPtr' is: {}\n", bar);

    int* returnedPtr = doReturnAPtr();
    fmt::print("The value of returnedPtr content after doReturnAPtr is: {}\n", *returnedPtr);
    doSomething(42);
    fmt::print("The value of returnedPtr content after doReturnAPtr is: {}\n", *returnedPtr);
  

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();

    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of foo2 {} address of foo2 {}\n", foo2, fmt::ptr(&foo2));
    int var;
    fmt::print("Value of var {} address of var {}\n", var, fmt::ptr(&var));

    fmt::print("Value of data {} address of data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of data2 {} address of data2 {}\n", data2, fmt::ptr(&data2));

    fmt::print("Value of rodata {} address of rodata {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of rodata2 {} address of rodata2 {}\n", rodata2, fmt::ptr(&rodata2));

    return 0; /* exit gracefully*/
}
