#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    fraccion *frac1 = inicializar_fraccion(8,2);
    fraccion *frac2 = NULL;
    inicializar_fraccion2(&frac2, 7,7);

    imprimir_fraccion(frac1);
    imprimir_fraccion(frac2);

    *frac1 = resta(frac1,frac2);
    imprimir_fraccion(frac1);

    *frac1 = resta(frac1,frac2);
    imprimir_fraccion(frac1);
    imprimir_fraccion(frac2);

    *frac1 = suma(frac1,frac2);
    imprimir_fraccion(frac1);

     *frac1 = simplificar (frac1);
    imprimir_fraccion(frac1);

    *frac1 = suma(frac1,frac2);
    imprimir_fraccion(frac1);

    *frac1 = suma(frac1,frac2);
    imprimir_fraccion(frac1);

     *frac1 = simplificar (frac1);
    imprimir_fraccion(frac1);

    return 0;
}
