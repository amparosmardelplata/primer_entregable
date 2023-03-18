#include <stdio.h>
#include <stdlib.h>

/**
 * Estructura para numeros fraccionarios
 * ATENCION. Se encuentra limitada por valores:
 * MINIMO = -2.147.483.648
 * MAXIMO = 2.147.483.647
 */
typedef struct
{
    int numerador;
    int denominador;
} fraccion;

/**
 * Crea e inicializa una fraccion version 2
 */
void inicializar_fraccion2(fraccion* *fraccion_a_ini, int numerador, int denominador)
{
    //llego la direccion, en el contenido de ese lugar reservo lugar
    *fraccion_a_ini = malloc(sizeof(fraccion));
    if (*fraccion_a_ini == NULL){
        perror ("no es posible reservar memoria");
        exit(104);
    }
    (*fraccion_a_ini)->numerador = numerador;
    (*fraccion_a_ini)->denominador = denominador;

}

/**
 * Crea e inicializa una fraccion version
 */
fraccion* inicializar_fraccion(int numerador, int denominador)
{
    fraccion* resultado = malloc(sizeof(fraccion));
    if (resultado == NULL){
        perror ("no es posible reservar memoria");
        exit(104);
    }

    (*resultado).numerador = numerador; // mejor no
    resultado->denominador = denominador;

    return resultado;

}


/**
 * Imprime en formato num/num una fraccion
 */
void imprimir_fraccion(fraccion *fraccion_a_imp)
{
    printf("%d/%d\n", fraccion_a_imp->numerador, fraccion_a_imp->denominador);
}

/**
* obtiene el denominador de una fraccion
*
* retorna el valor
*/
int obtenerdenominador(fraccion fr)
{
    return fr.denominador;
}

/**
* obtiene el numerador de una fraccion
*
* retorna el valor
*/
int obtenernumerador(fraccion fr)
{
    return fr.numerador;
}

/**
* Revisa si alguna fraccion es cero en el numerador
*
* retorna
* 0 si ninguna es cero
* 1 si la primera es cero
* 2 si la segunda es cero
*/
int alguna_fraccion_es_cero (fraccion fr1, fraccion fr2)
{
    int resultado = 0;
    if (obtenernumerador(fr1) == 0)
    {
        resultado = 1;
    }
    if (obtenerdenominador(fr2) == 0)
    {
        resultado = 2;
    }
    return resultado;
}

/**
* Simplifica una fraccion
*
* retorna el valor simplificado con posibilidades a:
* Si la fraccion es 0/numero simplifica a 0/1
* Si la fraccion es entera simplifica a (valor simplificado)/1
* Si la fraccion es entera a la inversa 1/(valor simplificado)
* Si la fraccion no se puede simplificar, el mismo valor
*/
fraccion simplificar(fraccion *fr)
{
    fraccion resultado;

    int numerador = obtenernumerador(*fr);
    int denominador = obtenerdenominador(*fr);

    if (numerador == 0){
        resultado.numerador = 0;
        resultado.denominador = 1;
    }
    if (numerador % denominador == 0)          ///si es = a 0 es entera
    {
        resultado.numerador = numerador / denominador;
        resultado.denominador = 1 ;
    }
    else if (denominador % numerador == 0)     ///puede ser entera a la inversa
    {
        resultado.denominador = denominador / numerador;
        resultado.numerador = 1;
    }
    else                                      ///no se puede simplificar
    {
        resultado.denominador = fr->denominador;
        resultado.numerador = fr->numerador;
    }

    return resultado;
}


/**
* Suma dos fracciones
*
* retorna la suma, verifica las situaciones:
* Si alguna fraccion es 0/n retorna la otra fraccion
* Si ninguna es 0 realiza el calculo
*
*/
fraccion suma(fraccion *fr1, fraccion *fr2)
{
    fraccion resultado;

    if (alguna_fraccion_es_cero(*fr1,*fr2) == 1)     ///si el primer numero es 0, la resta es el seg negativo
    {
        resultado.numerador = fr2->numerador;
        resultado.denominador = fr2->denominador ;
    }
    if (alguna_fraccion_es_cero(*fr1,*fr2) == 2)      ///si el segundo numero es 0
    {
        resultado.numerador = fr1->numerador;
        resultado.denominador = fr1->denominador ;
    }
    if (alguna_fraccion_es_cero(*fr1,*fr2) == 0)
    {
        resultado.numerador =  fr1->numerador * fr2->denominador + fr2->numerador * fr1->denominador;
        resultado.denominador = fr2->denominador * fr1->denominador;
    }

    return resultado;
}



/**
* Resta dos fracciones
*
* retorna la resta, verifica las situaciones:
* Si alguna fraccion es 0/n retorna la otra fraccion
* Si ninguna es 0 realiza el calculo
*
*/
fraccion resta(fraccion *fr1, fraccion *fr2)
{
    fraccion resultado;

    if (alguna_fraccion_es_cero(*fr1,*fr2) == 1)     ///si el primer numero es 0, la resta es el seg negativo
    {
        resultado.numerador = -fr2->numerador;
        resultado.denominador = fr2->denominador ;
    }
    if (alguna_fraccion_es_cero(*fr1,*fr2) == 2)      ///si el segundo numero es 0
    {
        resultado.numerador = fr1->numerador;
        resultado.denominador = fr1->denominador ;
    }
    if (alguna_fraccion_es_cero(*fr1,*fr2) == 0)
    {
        resultado.numerador =  (fr1->numerador * fr2->denominador) - (fr2->numerador * fr1->denominador);
        resultado.denominador = fr2->denominador * fr1->denominador;
    }

    return resultado;
}

/**
* Compara dos fracciones
*
* retorna:
* 0 si eran iguales
* 1 se la primera es mayor
* -1 si la primera es menor
*
*/
int comparar(fraccion *fr1, fraccion *fr2)
{
    int resultado = 99;

    if (obtenernumerador(resta(fr1,fr2)) == 0)  ///si al restar el numerador es 0, eran iguales
    {
        resultado = 0;
    }
    if (obtenernumerador(resta(fr1,fr2)) > 0)
    {
        resultado = 1;
    }
    if (obtenernumerador(resta(fr1,fr2)) < 0)
    {
        resultado = -1;
    }
    return resultado;
}


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
