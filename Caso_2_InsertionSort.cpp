/*
Moisés Solano Espinoza
2021144322
Caso 2
Insertion Sort
*/

#include <iostream>
#include <time.h>
#include <ctime>
#include <string>

#include <chrono>
using namespace std;

// variables para el analisis
int long contadorMovimientos = 0;
int contIteraciones = 0;

// variables para la medicion de tiempo
unsigned t0, t1;

// algoritmo de implementación del insertion sort
void insertionSort(int array[], int length) 
{  
    int i, j, key;
    for (int j = 1; j < length; j++) 
    {
        key = array[j];
        i = j-1;
        
        while (i >= 0 && array[i] > key) 
        {
            array[i+1] = array[i];
            i--;

            // contador que se incrementa con los intencambios
            contadorMovimientos++;
        }
        array[i+1] = key;

        // contador de iteraciones del for
        contIteraciones++;    
    }  
}

// funcion para documentar las pruebas del peor de los casos del Insertion Sort
// O(n^2)
void pruebaInsertionSort(int arr[], int lenght, int numero){
    double time;
    contadorMovimientos = contIteraciones = 0;

    cout << "\n--------------------" << endl;
    cout << numero << ". Prueba Insertion Sort (" << lenght << " elementos)" << endl;
    auto inicial = chrono::steady_clock::now();
    t0 = clock();
	insertionSort(arr, lenght);
    t1 = clock();
    auto final = chrono::steady_clock::now();
    cout << "--------------------" << endl;
    cout << "Informacion de contadores:" << endl;
    cout << "\t->Contador movimientos = " << contadorMovimientos << endl;
    cout << "\t->Cantidad de iteraciones del for = " << contIteraciones << endl;

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n\t->Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(final - inicial).count() << " nanosegundos." << endl;
    cout << "\n\t->Tiempo de ejecucion: " << time << " segundos." << endl;

    cout << "___________________________________________________________________________________________________" << endl;

}


void pintarArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<" "; 
      
} 


int main(){

    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "###################################### CASO 2 ########################################" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    // creacion de los arrays para las pruebas
    int lista[1000];
    int lista2[2000];
    int lista3[3000];
    int lista4[4000];
    int lista5[5000];
    int lista6[6000];
    int lista7[7000];
    int lista8[8000];
    int lista9[9000];
    int lista10[10000];

    int lista11[1000];
    int lista12[2000];
    int lista13[3000];
    int lista14[4000];
    int lista15[5000];
    int lista16[6000];
    int lista17[7000];
    int lista18[8000];
    int lista19[9000];
    int lista20[10000];

    // en este ciclo se rellenan los arrays de forma ascendente
    // para el mejor de los casos
    for (int i = 0; i < 10000; i++){
        if (i < 1000){
            lista[i] = i;
        }
        if (i < 2000){
            lista2[i] = i;
        }
        if (i < 3000){
            lista3[i] = i;
        }
        if (i < 4000){
            lista4[i] = i;
        }
        if (i < 5000){
            lista5[i] = i;
        }
        if (i < 6000){
            lista6[i] = i;
        }
        if (i < 7000){
            lista7[i] = i;
        }
        if (i < 8000){
            lista8[i] = i;
        }
        if (i < 9000){
            lista9[i] = i;
        }
        if (i < 10000){
            lista10[i] = i;
        }
    }

    // en este ciclo se rellenan los arrays de forma descendente
    // para el peor de los casos
    for (int i = 0; i < 10000; i++){
        if (i < 1000){
            lista11[i] = 1000 - i;
        }
        if (i < 2000){
            lista12[i] = 2000 - i;
        }
        if (i < 3000){
            lista13[i] = 3000 - i;
        }
        if (i < 4000){
            lista14[i] = 4000 - i;
        }
        if (i < 5000){
            lista15[i] = 5000 - i;
        }
        if (i < 6000){
            lista16[i] = 6000 - i;
        }
        if (i < 7000){
            lista17[i] = 7000 - i;
        }
        if (i < 8000){
            lista18[i] = 8000 - i;
        }
        if (i < 9000){
            lista19[i] = 9000 - i;
        }
        if (i < 10000){
            lista20[i] = 10000 - i;
        }
    }

    // ------------------------------------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------------------------------------------------------------------------------------------------------

    cout << "\n\n-------------------------------------------" << endl;
    cout << "\tINSERTION_SORT MEJOR DE LOS CASOS O(n)" << endl;
    cout << "-------------------------------------------" << endl;

    /* 
    Mejor de los casos O(n) -> Lineal

    Este es el mejor de los casos porque el O grande es n y no puede 
    ser más eficiente para este algoritmo.
    
    ¿Por qué es así?
    Esto se da porque el array que se quiere ordenar ya está ordenado
    ascendentemente, por lo que cuando se pregunta si se ocupa hacer
    el swap de elementos este nunca se va a hacer. Lo único que va a ocurrir
    es que se van a hacer n - 1 iteraciones del ciclo for.

    Por esta razón en las pruebas que realicé se muestra que independientemente
    del largo del array siempre la cantidad de swaps va a ser 0 y la cantidad
    de iteraciones n - 1 porque el ciclo for no empieza en 0 sino en 1.

    Para demostrar esto se muestra la siguiente tabla con los datos de las pruebas:

                                           **                      
        ________________________________________________________________________________________________
       | Cantidad de elementos |         Swaps          |        Iteraciones del for       |  Tiempo   |
       -------------------------------------------------------------------------------------------------
       |       1 000 	       |           0            |               999                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       2 000  	       |           0            |              1 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       3 000  	       |           0            |              2 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       4 000  	       |           0            |              3 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       5 000  	       |           0            |              4 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       6 000  	       |           0            |              5 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       7 000 	       |           0            |              6 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       8 000  	       |           0            |              7 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       9 000  	       |           0            |              8 999               |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       10 000  	       |           0            |              9 999               |   0.000   |
       -------------------------------------------------------------------------------------------------

       
    */

    pruebaInsertionSort(lista, 1000, 1);
    pruebaInsertionSort(lista2, 2000, 2);
    pruebaInsertionSort(lista3, 3000, 3);
    pruebaInsertionSort(lista4, 4000, 4);
    pruebaInsertionSort(lista5, 5000, 5);
    pruebaInsertionSort(lista6, 6000, 6);
    pruebaInsertionSort(lista7, 7000, 7);
    pruebaInsertionSort(lista8, 8000, 8);
    pruebaInsertionSort(lista9, 9000, 9);
    pruebaInsertionSort(lista10, 10000, 10);

    
    // pintarArray(lista12, 100);

    // ------------------------------------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------------------------------------------------------------------------------------------------------
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;

    cout << "\n\n-------------------------------------------" << endl;
    cout << "\tINSERTION_SORT PEOR DE LOS CASOS O(n^2)" << endl;
    cout << "-------------------------------------------" << endl;

    /*
    Peor de los casos O(n^2) -> Cuadrático

    Este es el peor de los casos porque es en el que se van a tener que 
    hacer más swaps de elementos desordenados. Esto se da porque en 
    todas las iteraciones se tienen que hacer todos los cambios posibles
    para que quede ordenado.

    En las pruebas que realicé se evidencia este comportamiento. Utilicé arrays
    que están ordenados descendentemente. En la primera iteración el i está 
    en el índice 1 y este esta dosordenado, por lo que se tiene que hacer un swap.
    Cuando el i = 2 también va a estar desordenado, por lo que se van a tener que
    hacer 2 swaps para que el subarray quede ordenado. Y así sucesivamente.

    Si analizamos esto con más detalle, quiere decir que la primera iteracion 
    va a ver 1 swap, en la siguiente 2, en la siguiente 3 y así hasta n-1.
    Por lo que se puede concluir que se va a hacer una sumatoria de swaps
    hasta llegar al punto final que se puede expresar como : 1 + 2 + .. + n-1.

    Esto pasado a una fórmula quedaría como: n(n-1)/2

    En términos de O sería : n(n-1)/2
        	               : n(n-1)
                           : n^2 - n
                           : n
                           : O(n^2)

    Por lo tanto, el comportamiento es cuadrático en el peor de los casos
    y el caso promedio.

    A continuación mostraré los resultados obtenidos para que quede más claro.
    También se va a poder observar que el crecimiento no va a ser uniforme, al contrario
    de una lineal. Si la cantidad de elementos del array son pocos, el incremento de 
    swaps es mínimo, pero conforme la cantidad va aumentando los swaps crecen conciderablemente;
    típico de una cuadrática. Esta es la razón por la cual en las graficas se ve una
    funcion con forma de u, porque al principio los cambios van a ser pocos pero conforme
    crece la cantidad de elementos los cambios crecen enormemente.

    Para demostrar esto se muestra la siguiente tabla con los datos de las pruebas:

                                           **                      
        ________________________________________________________________________________________________
       | Cantidad de elementos |         Swaps          |        Iteraciones del for       |  Tiempo   |
       -------------------------------------------------------------------------------------------------
       |       100  	       |         4950           |               99                 |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       250  	       |         31 125         |               249                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       500  	       |       124 750          |               499                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       1 000  	       |       499 500          |             1 999                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       2 000  	       |      1 999 000         |             2 999                |   0.005   |
       -------------------------------------------------------------------------------------------------
       |       4 000  	       |      7 998 000         |             3 999                |   0.018   |
       -------------------------------------------------------------------------------------------------
       |       8 000 	       |      31 996 000        |             7 999                |   0.071   |
       -------------------------------------------------------------------------------------------------
       |       16 000  	       |     127 992 000        |             15 999               |   0.282   |
       -------------------------------------------------------------------------------------------------
       |       32 000  	       |     511 984 000        |             31 999               |   1.157   |
       -------------------------------------------------------------------------------------------------
       |       64 000  	       |    2 047 968 000       |             63 999               |   4.494   |
       -------------------------------------------------------------------------------------------------
       Estas son unas pruebas que realicé pero no se muestran en el main porque lo acomodé con otros
       ejemplos con cantidades diferentes. Lo importante es el comportamiento.


       También esta el comportamiento de la relacion entre el T(n) y el O(n). 
       Esto quiere decir que la relacion que existe entre por ejemplo el T(n2)/T(n1) 
       debe ser muy similar a la de O(n2)/O(n1). Como esta relacion siempre se mantiene quiere decir
       que el algoritmo si se comporta como O(n^2) en el peor de los casos.
       
       A continuación una tabla con las relaciones: 
       
        _________________________________________________________________________________________________________________________
       | Cantidad de elementos |   T(n) en nanosegundos / segundos |            n^2         |     T(n+1)/T(n)   |     O(n+1)/O(n)
       --------------------------------------------------------------------------------------------------------------------------
       |       1 000 	       |        997 000 / 0,001            |         1 000 000      |    5,001003009    |       4
       --------------------------------------------------------------------------------------------------------------------------
       |       2 000  	       |        4 986 000 / 0,005          |         4 000 000      |   2,000401123     |     2,25
       --------------------------------------------------------------------------------------------------------------------------
       |       3 000  	       |        9 974 000 / 0,01           |         9 000 000      |   1,70262683      |   1,777777778 
       --------------------------------------------------------------------------------------------------------------------------
       |       4 000  	       |        16 982 000 / 0,017         |        16 000 000      |   1,58403015      |    1,5625
       --------------------------------------------------------------------------------------------------------------------------
       |       5 000  	       |        26 900 000 / 0,027         |        25 000 000      |   1,480446097     |     1,44
       --------------------------------------------------------------------------------------------------------------------------
       |       6 000  	       |        39 824 000 / 0,039         |        36 000 000      |   1,301576939     |   1,361111111
       --------------------------------------------------------------------------------------------------------------------------
       |       7 000 	       |        51 834 000 / 0,052         |        49 000 000      |   1,327622796     |   1,306122449
       --------------------------------------------------------------------------------------------------------------------------
       |       8 000  	       |        68 816 000 / 0,069         |        64 000 000      |   1,260869565     |   1,265625
       --------------------------------------------------------------------------------------------------------------------------
       |       9 000  	       |        86 769 000 / 0,087         |        81 000 000      |   1,241690485     |   1,234567901
       --------------------------------------------------------------------------------------------------------------------------
       |       10 000  	       |       107 739 000 / 0,107         |       100 000 000      |       ...         |       ...
       --------------------------------------------------------------------------------------------------------------------------
    */

    pruebaInsertionSort(lista11, 1000, 1);
    pruebaInsertionSort(lista12, 2000, 2);
    pruebaInsertionSort(lista13, 3000, 3);
    pruebaInsertionSort(lista14, 4000, 4);
    pruebaInsertionSort(lista15, 5000, 5);
    pruebaInsertionSort(lista16, 6000, 6);
    pruebaInsertionSort(lista17, 7000, 7);
    pruebaInsertionSort(lista18, 8000, 8);
    pruebaInsertionSort(lista19, 9000, 9);
    pruebaInsertionSort(lista20, 10000, 10);

    return 0;
}