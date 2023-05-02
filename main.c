#include <stdio.h>
#include "ivector.h"

void imprimirSolucion(ivector vec, int tam) {
    printf("\n");
    for (int i = 0; i < tam; ++i) {
        if (vec[i] != 0)
            printf("%d, ", vec[i]);
    }
}

void backtracking(ivector vec, int tamVector, int sumaActual, int sumaObjetivo, ivector solucionParcial, int puesto) {

    if (sumaActual == sumaObjetivo) {
        imprimirSolucion(solucionParcial, tamVector);
        return;
    }

    if (puesto == tamVector || sumaActual > sumaObjetivo)
        return;


    solucionParcial[puesto] = vec[puesto];
    backtracking(vec, tamVector, sumaActual + vec[puesto], sumaObjetivo, solucionParcial, puesto + 1);
    solucionParcial[puesto] = 0;
    backtracking(vec, tamVector, sumaActual, sumaObjetivo, solucionParcial, puesto + 1);

}

int main() {

    int tamVector = 5;
    int sumaObjetivo = 6;
    ivector vec = icreavector(tamVector);
    ivector solucionParcial = icreavector(tamVector);

    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    vec[3] = 4;
    vec[4] = 5;

    for (int i = 0; i < tamVector; ++i) {
        solucionParcial[i] = 0;
    }

    backtracking(vec, tamVector, 0, sumaObjetivo, solucionParcial, 0);

    ifreevector(&vec);
    ifreevector(&solucionParcial);

    return 0;
}