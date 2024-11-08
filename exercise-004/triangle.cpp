#include "triangle.h"
#include "stdlib.h"         // wird gebraucht für malloc-Funktion und für free-Funktione

// malloc-Funktion und free-Funktion sind Gegenspieler --> Speicherbereich, welcher von malloc allokiert wurde kann über free wieder freigegeben werden
// malloc: Konstruktion eines Objekts
// free: Destruktion eines Objekts

unsigned int perimeter(Triangle* self){
    return self->side_a + self->side_b + self->side_c;
}

// Triangle temp; Problem: Nur ein Dreieck kann erzeugt werden

// Funktion, die Objekt erzeugt: "Konstruktor" --> Vordefinierung eines neu erzeugten Dreiecks
Triangle* newTriangle(){
    //darf nicht als lokale Variable erzeugt werden --> sonst wird Objekt bei jedem neuen Aufruf überschrieben
    // Triangle temp; -> Problem Verweis auf stacklokale Variable
    
    Triangle* temp = (Triangle*) malloc(sizeof(Triangle));                  //malloc allokiert uninitialisierten Speicherbereich --> es muss übergeben werden wir viel Speicher gebraucht wird
   
    // Vorinitialisierung des Dreiecks
    temp->side_a = 0;
    temp->side_b = 0;
    temp->side_c = 0;

    return temp;
}

Triangle* newTriangleWithValues(unsigned int a, unsigned int b, unsigned int c){
    
    Triangle* temp = newTriangle();

    // Vorinitialisierung des Dreiecks
    temp->side_a = a;
    temp->side_b = b;
    temp->side_c = c;

    return temp;
}



void  freeTriangle(Triangle* ptr){
        free(ptr);
}