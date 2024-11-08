
// sichert ab, dass auch bei mehrfacher inkludierung der h-Datei in ein anderen Modul keine Fehlermeldung kommt --> Fehler wäre,dass Structur redefiniert wird --> include Guard sorgt dafür, dass die vermieden wird
#ifndef MY_FANCY_TRIANGLE_H
#define MY_FANCY_TRIANGLE_H

struct Triangle {
    // unigned damit keine negativen Zahlen entstehen können
    unsigned int side_a;
    unsigned int side_b;
    unsigned int side_c;
};

Triangle* newTriangle();
Triangle* newTriangleWithValues(unsigned int a, unsigned int b, unsigned int c);

unsigned int perimeter(Triangle* self);
void  freeTriangle(Triangle* ptr);

#endif