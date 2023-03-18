#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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
* FUNCIONES
*/
fraccion* inicializar_fraccion(int numerador, int denominador);
void inicializar_fraccion2(fraccion* *fraccion_a_ini, int numerador, int denominador);
void imprimir_fraccion(fraccion *fraccion_a_imp);
int obtenerdenominador(fraccion fr);
int obtenernumerador(fraccion fr);
int alguna_fraccion_es_cero (fraccion fr1, fraccion fr2);
int comparar(fraccion *fr1, fraccion *fr2);
fraccion simplificar(fraccion *fr);
fraccion suma(fraccion *fr1, fraccion *fr2);
fraccion resta(fraccion *fr1, fraccion *fr2);


#endif // FUNCIONES_H_INCLUDED
