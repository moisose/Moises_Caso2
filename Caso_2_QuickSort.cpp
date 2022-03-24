/*
Moisés Solano Espinoza
2021144322
Caso 2
Quick Sort
*/

#include <iostream>
#include <time.h>
#include <ctime>
#include <string>

#include <chrono>
using namespace std;

// Variables para medir el tiempo
unsigned t0, t1;
// Variables para los analisis
int swaps, iteracionesPartition, llamadasRecursivas, llamadasPartition;

// funcion para intercambiar dos elementos del array
void swap(int array[] , int pos1, int pos2){
	int temp;
	temp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = temp;

    // Contador de intercambios
    swaps++;
}

// funcion para particionar el array utilizando como pivot
// el ultimo elemento del mismo array
int partition (int array[], int menor, int mayor) 
{ 
    // Se calcula el random en los dos casos para que no varie el tiempo
    // -----------------------------------------
    srand(time(NULL));
    int random = menor + rand() % (mayor - menor);
    // -----------------------------------------

    int pivot = array[mayor]; // pivot para la particion
    int i = (menor - 1); // contador del menor elemento
   
    // se
    for (int j = menor; j <= mayor- 1; j++) 
    { 
        // cantidad de iteraciones de este ciclo de partition
        iteracionesPartition++;
        // si el elemento actual es menor o igual que el pivot, se incrementa el menor elemento
        // por esto se deben intercambiar los elementos en la posicion i y j
        if (array[j] <= pivot) 
        { 
            i++;
            swap(array, i, j); 
        } 
    } 
    swap(array, i+1, mayor);
    return (i + 1); 
} 
   
// algoritmo que implementa el QuickSort
void quickSort(int arr[], int menor, int mayor) 
{ 
    if (menor < mayor) 
    { 
        // se incrementa el contador de particiones del array
        llamadasPartition++;
        int pivot = partition(arr, menor, mayor);
   
        // se ordenan los dos bloques recursivamente y se incrementa el contador
        // de llamadas recursivas
        llamadasRecursivas += 2;
        quickSort(arr, menor, pivot - 1); 
        quickSort(arr, pivot + 1, mayor); 
    } 
} 

// algortimo de particion que utiliza el pivot random
int partitionRandom(int arr[], int menor, int mayor)
{
    // numero random que sera el pivot
    srand(time(NULL));
    int random = menor + rand() % (mayor - menor);
 
    // se intercambia el elemento random elegido con el mayor
    // porque el algoritmo de partición utiliza el mayor elemento
    swap(arr[random], arr[mayor]);
 
    // incremento de contador de llamadas
    llamadasPartition++;
    return partition(arr, menor, mayor);
}
 
// algoritmo que implementa el quick sort con pivot random
void quickSortRandom(int array[], int menor, int mayor)
{
    if (menor < mayor) {
        // variable que contiene el index de la partición
        // después de elegir el pivot random y utilizar 
        // la funcion de particion normal
        int index = partitionRandom(array, menor, mayor);
 
        // se ordenan los dos bloques recursivamente y se incrementa el contador
        // de llamadas recursivas
        llamadasRecursivas += 2;
        quickSortRandom(array, menor, index - 1);
        quickSortRandom(array, index + 1, mayor);
    }
}

// funcion para documentar las pruebas del peor de los casos del Quick Sort
// O(n^2)
void pruebaQuickSort(int arr[], int lenght, int numero){
    double time;
    swaps = iteracionesPartition = llamadasRecursivas = llamadasPartition = 0;

    cout << "\n--------------------" << endl;
    cout << numero << ". Prueba Quick_Sort (" << lenght << " elementos)" << endl;
    t0 = clock();
    auto inicial = chrono::steady_clock::now();
	quickSort(arr, 0 , lenght-1);
    t1 = clock();
    auto final = chrono::steady_clock::now();
    cout << "--------------------" << endl;
    cout << "Informacion de contadores:" << endl;
    cout << "\t->Llamadas recursivas = " << llamadasRecursivas << endl;
    cout << "\t->Llamadas Partition = " << llamadasPartition << endl;
    cout << "\t->Iteraciones Partition = " << iteracionesPartition << endl;
    cout << "\t->Swaps = " << swaps << endl;

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n\t->Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(final - inicial).count() << " nanosegundos." << endl;
    cout << "\n\t->Tiempo de ejecucion: " << time << " segundos." << endl;
}

void pruebaQuickSortRandom(int arr[], int lenght, int numero){
    // ---------------
    double time;
    swaps = iteracionesPartition = llamadasRecursivas = llamadasPartition = 0;

    cout << "\n-------------------------------------" << endl;
    cout << numero <<". Prueba Quick_Sort con pivot Random (" << lenght << " elementos)" << endl;
    auto inicial2 = chrono::steady_clock::now();
    t0 = clock();
	quickSortRandom(arr, 0 , lenght-1);
    auto final2 = chrono::steady_clock::now();
    t1 = clock();
    cout << "-------------------------------------" << endl;
    cout << "Informacion de contadores:" << endl;
    cout << "\t->Llamadas recursivas = " << llamadasRecursivas << endl;
    cout << "\t->Llamadas Partition = " << llamadasPartition << endl;
    cout << "\t->Iteraciones Partition = " << iteracionesPartition << endl;
    cout << "\t->Swaps = " << swaps << endl;

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n\t->Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(final2 - inicial2).count() << " nanosegundos." << endl;
    cout << "\n\t->Tiempo de ejecucion: " << time << " segundos." << endl;
    cout << "___________________________________________________________________________________________________" << endl;
}

void pruebaQuickSortBoth(int arr[], int lenght, int numero){
    double time;
    swaps = iteracionesPartition = llamadasRecursivas = llamadasPartition = 0;

    cout << "\n--------------------" << endl;
    cout << numero << ". Prueba Quick_Sort (" << lenght << " elementos)" << endl;
    t0 = clock();
    auto inicial = chrono::steady_clock::now();
	quickSort(arr, 0 , lenght-1);
    t1 = clock();
    auto final = chrono::steady_clock::now();
    cout << "--------------------" << endl;
    cout << "Informacion de contadores:" << endl;
    cout << "\t->Llamadas recursivas = " << llamadasRecursivas << endl;
    cout << "\t->Llamadas Partition = " << llamadasPartition << endl;
    cout << "\t->Iteraciones Partition = " << iteracionesPartition << endl;
    cout << "\t->Swaps = " << swaps << endl;

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n\t->Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(final - inicial).count() << " nanosegundos." << endl;
    cout << "\n\t->Tiempo de ejecucion: " << time << " segundos." << endl;
    // ---------------

    swaps = iteracionesPartition = llamadasRecursivas = llamadasPartition = 0;

    cout << "\n-------------------------------------" << endl;
    cout << numero <<". Prueba Quick_Sort con pivot Random (" << lenght << " elementos)" << endl;
    auto inicial2 = chrono::steady_clock::now();
    t0 = clock();
	quickSortRandom(arr, 0 , lenght-1);
    auto final2 = chrono::steady_clock::now();
    t1 = clock();
    cout << "-------------------------------------" << endl;
    cout << "Informacion de contadores:" << endl;
    cout << "\t->Llamadas recursivas = " << llamadasRecursivas << endl;
    cout << "\t->Llamadas Partition = " << llamadasPartition << endl;
    cout << "\t->Iteraciones Partition = " << iteracionesPartition << endl;
    cout << "\t->Swaps = " << swaps << endl;

    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n\t->Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(final2 - inicial2).count() << " nanosegundos." << endl;
    cout << "\n\t->Tiempo de ejecucion: " << time << " segundos." << endl;
    cout << "___________________________________________________________________________________________________" << endl;
}

void pintarArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<" "; 
      
} 


int main()
{ 
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "###################################### CASO 2 ########################################" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    // creacion de los arrays de pruebas para el O(n^2) con pivote fijo y aleatorio
    int arr[1000];
    int arr2[2000];
    int arr3[3000];
    int arr4[4000];
    int arr5[5000];
    int arr6[6000];
    int arr7[7000];
    int arr8[8000];
    int arr9[9000];
    int arr10[10000];

    int arr11[7000];
    int arr12[8000];
    int arr13[9000];
    int arr14[10000];
    int arr15[11000];
    int arr16[12000];
    int arr17[13000];
    int arr18[14000];
    int arr19[15000];
    int arr20[16000];
    int arr21[17000];
    int arr22[18000];
    int arr23[19000];
    int arr24[20000];
    int arr25[21000];
    int arr26[22000];
    


    // se rellenan los arrays de forma ordenada ascendente
    for (int i=0; i < 10000; i++){
        if(i < 1000){
            arr[i] = i;
        }
        if(i < 2000){
            arr2[i] = i;
        }
        if(i < 3000){
            arr3[i] = i;
        }
        if(i < 4000){
            arr4[i] = i;
        }
        if(i < 5000){
            arr5[i] = i;
        }
        if(i < 6000){
            arr6[i] = i;
        }
        if(i < 7000){
            arr7[i] = i;
        }
        if(i < 8000){
            arr8[i] = i;
        }
        if(i < 9000){
            arr9[i] = i;
        }
        if(i < 10000){
            arr10[i] = i;
        }
    }

    for (int i=0; i < 19000; i++){
        if(i < 7000){
            arr11[i] = 7000 - i;
        }
        if(i < 8000){
            arr12[i] = 8000 - i;
        }
        if(i < 9000){
            arr13[i] = 9000 - i;
        }
        if(i < 10000){
            arr14[i] = 10000 - i;
        }
        if(i < 11000){
            arr15[i] = 11000 - i;
        }
        if(i < 12000){
            arr16[i] = 12000 - i;
        }
        if(i < 13000){
            arr17[i] = 13000 - i;
        }
        if(i < 14000){
            arr18[i] = 14000 - i;
        }
        if(i < 15000){
            arr19[i] = 15000 - i;
        }
        if(i < 16000){
            arr20[i] = 16000 - i;
        }
        if(i < 17000){
            arr21[i] = 17000 - i;
        }
        if(i < 18000){
            arr22[i] = 18000 - i;
        }
        if(i < 19000){
            arr23[i] = 19000 - i;
        }
        // if(i < 20000){
        //     arr24[i] = 20000 - i;
        // }
        // if(i < 21000){
        //     arr25[i] = 21000 - i;
        // }
        // if(i < 22000){
        //     arr26[i] = 22000 - i;
        // }
    }


    // pintarArray(arr11, 1000);


    // ------------------------------------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------------------------------------------------------------------------------------------------------

    cout << "\n\n-------------------------------------------" << endl;
    cout << "\tQUICK_SORT PEOR DE LOS CASOS O(n^2)" << endl;
    cout << "-------------------------------------------" << endl;

    /*
    El peor de los casos en el quick sort es O(n^2)
    ¿Por qué se da este comportamiento?
        Este caso se da cuando el array ya se encuentra ordenado, entonces 
        en el momento que se escoge el pivot mayor en todas las divisiones
        o niveles se va a crear un desnivel hacia un lado, y no se aplicaría
        correctamente la tecnica de divide y vencerás.

        Entonces en cada division se va a hacer el problema con un elemento 
        menos y el problema se repetira hasta el final.

    ¿Qué comportamiento logré reconocer con las pruebas que lo explique?
        Logré reconocer con pruebas manuales de arrays pequeños que cuando se 
        elige el pivot como el mayor y la lista esta ordenada en cada iteracion
        se hace el problema mas pequeño en n-1, es decir al principio será n,
        luego n-1, después n-2, luego n-3 ... y todo eso se suma.

        Después de analizar este comportamiento esa es una sumatoria de ir decrementando
        n hasta llegar a 1. Se puede expresar en una formula como : 
                -> [n(n+1)/2] - 1
                -> n^2 - n
                -> n^2
        En términos de O la fórmula se simplifica hasta llegar al O(n^2).

        Para demostrar esto se muestra la siguiente tabla con los datos de las pruebas:

                                           **                      
        ________________________________________________________________________________________________
       | Cantidad de elementos |         Swaps          |        Llamadas Recursivas       |  Tiempo   |
       -------------------------------------------------------------------------------------------------
       |       125 	           |        7 874           |               248                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       250  	       |        31 374          |               498                |   0.000   |
       -------------------------------------------------------------------------------------------------
       |       500  	       |        125 249         |               998                |   0.001   |
       -------------------------------------------------------------------------------------------------
       |       1 000  	       |        500 499         |             1 998                |   0.003   |
       -------------------------------------------------------------------------------------------------
       |       2 000  	       |        2 000 999       |             3 998                |   0.012   |
       -------------------------------------------------------------------------------------------------
       |       4 000  	       |        8 001 999       |             7 998                |   0.046   |
       -------------------------------------------------------------------------------------------------
       |       8 000 	       |        32 003 999      |             15 998               |   0.184   |
       -------------------------------------------------------------------------------------------------
       |       16 000  	       |        128 007 999     |             31 998               |   0.736   |
       -------------------------------------------------------------------------------------------------
       |       32 000  	       |        512 015 999     |             63 998               |   3.049   |
       -------------------------------------------------------------------------------------------------
       |       35 000  	       |       612 517 499      |             69 998               |   3.584   |
       -------------------------------------------------------------------------------------------------

       Los swaps son el dato más importante que demuestra el O(n^2).
       Las llamadas recursivas son la cantidad de llamadas a la función se hacen hasta obtener el resultado.
       En la gráfica se demuestra de forma más visual la forma de la curva cuadrática.


       También esta el comportamiento de la relacion entre el T(n) y el O(n). 
       Esto quiere decir que la relacion que existe entre por ejemplo el T(n2)/T(n1) 
       debe ser muy similar a la de O(n2)/O(n1). Como esta relacion siempre se mantiene quiere decir
       que el algoritmo si se comporta como O(n^2) en el peor de los casos.
       
       A continuación una tabla con las relaciones: 
       
        ____________________________________________________________________________________________________________________
       | Cantidad de elementos |         T(n)           |            n^2         |    T(n+1)/T(n)   |     O(n+1)/O(n)
       ---------------------------------------------------------------------------------------------------------------------
       |       1 000 	       |        0,003           |         1 000 000      |        4         |       4
       ---------------------------------------------------------------------------------------------------------------------
       |       2 000  	       |        0,012           |         4 000 000      |   2,166666667    |       2,25
       ---------------------------------------------------------------------------------------------------------------------
       |       3 000  	       |        0,026           |         9 000 000      |   1,730769231    |     1,777777778 
       ---------------------------------------------------------------------------------------------------------------------
       |       4 000  	       |        0,045           |        16 000 000      |   1,577777778    |       1,5625
       ---------------------------------------------------------------------------------------------------------------------
       |       5 000  	       |        0,071           |        25 000 000      |   1,436619718    |       1,44
       ---------------------------------------------------------------------------------------------------------------------
       |       6 000  	       |        0,102           |        36 000 000      |   1,382352941    |       1,361111111
       ---------------------------------------------------------------------------------------------------------------------
       |       7 000 	       |        0,141           |        49 000 000      |   1,29787234     |       1,306122449
       ---------------------------------------------------------------------------------------------------------------------
       |       8 000  	       |        0,183           |        64 000 000      |   1,278688525    |       1,265625
       ---------------------------------------------------------------------------------------------------------------------
       |       9 000  	       |        0,29            |        81 000 000      |   1,239316239    |       1,234567901
       ---------------------------------------------------------------------------------------------------------------------
       |       10 000  	       |       612 517 499      |       100 000 000      |       ...        |       ...
       ---------------------------------------------------------------------------------------------------------------------
       
    */
    // Llamado a las pruebas para que se generen los print en pantalla

    // -----------------------------------------------------
    pruebaQuickSort(arr, 1000, 1); 
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr2, 2000, 2);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr3, 3000, 3);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr4, 4000, 4);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr5, 5000, 5);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr6, 6000, 6);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr7, 7000, 7);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr8, 8000, 8);
    // -----------------------------------------------------
    // -----------------------------------------------------
    pruebaQuickSort(arr9, 9000, 9);
    // ------------------------------------------------
    // ------------------------------------------------
    pruebaQuickSort(arr10, 10000, 10);


    // ------------------------------------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------------------------------------------------------------------------------------------------------
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "\n\n-------------------------------------------" << endl;
    cout << "\tQUICK_SORT O(nlogn)" << endl;
    cout << "-------------------------------------------" << endl;

    /*
    El caso promedio y el mejor caso del Quick Sort se comporta como logaritmico.

    ¿Por qué ocurre esto?
        Esto se da porque al ser un algoritmo que divide el array dependiendo del 
        pivot, en la mayoría de los casos cada subarray tiene un tamaño similiar
        y el problema se va volviendo cada vez más pequeño y con unas divisiones
        no tan desniveladas.
        
        Esto relacionado con el tiempo, se puede analizar como que este algoritmo
        conforme vaya aumentando el n el tiempo no va a ir aumentando mucho, como 
        pasaba en el O(n^2), sino mas bien se convierte mas eficiente en cuestion 
        de tiempo.

        Para poder analizar este comportamiento cree varios arrays que van aumentando
        de 1000 en 1000, y estan ordenados desendentemente. Utilicé el pivot random
        para las pruebas. Entonces llame a la funcion de quick sort con pivot random
        para cada uno de los arrays y medi el tiempo de ejecucion.

        A continuacion mostrare una tabla que muestra el comportamiento del algoritmo.
        n es el tamaño del problema, t(n) es el tiempo que tardo en darme una respuesta,
        n logn significa el calculo del n*log n, luego viene la relacion entre el 
        t(n+1) y el t(n), y luego viene la relacion entre el O(n+1) y el O(n).

         ____________________________________________________________________________________________________________________
       |            n          |         T(n)           |       n log2(n)         |    T(n+1)/T(n)   |     O(n+1)/O(n)
       ---------------------------------------------------------------------------------------------------------------------
       |       7 000 	       |       1027000          |     89 411,97445       |    0,969814995    |     1,16009377
       ---------------------------------------------------------------------------------------------------------------------
       |       8 000  	       |       996000           |     103 726,27428      |    1,003012048    |     1,13974385
       ---------------------------------------------------------------------------------------------------------------------
       |       9 000  	       |       999000           |     118 221,38357      |    1,997997998    |     1,12396861 
       ---------------------------------------------------------------------------------------------------------------------
       |       10 000  	       |      1996000           |     132 877,12380      |    0,997995992    |     1,11138299
       ---------------------------------------------------------------------------------------------------------------------
       |       11 000  	       |      1992000           |     147 677,37494      |    1,001506024    |     1,10110951
       ---------------------------------------------------------------------------------------------------------------------
       |       12 000  	       |      1995000           |     162 608,96142      |    1,000501253    |     1,09256532
       ---------------------------------------------------------------------------------------------------------------------
       |       13 000 	       |      1996000           |     177 660,91204      |    0,998496994    |     1,08534819
       ---------------------------------------------------------------------------------------------------------------------
       |       14 000  	       |      1993000           |     192 823,94889      |    1,001505268    |     1,07917157
       ---------------------------------------------------------------------------------------------------------------------
       |       15 000  	       |      1996000           |     208 090,12320      |    1,497995992    |     1,07382583
       ---------------------------------------------------------------------------------------------------------------------
       |       16 000  	       |      2990000           |     223 452,54855      |    1,000668896    |     1,06915407
       ---------------------------------------------------------------------------------------------------------------------
       |       17 000  	       |      2992000           |     238 905,20114      |    1,000668449    |     1,06503653
       ---------------------------------------------------------------------------------------------------------------------
       |       18 000  	       |      2994000           |     254 442,76715      |    0,998997996    |     1,06138024
       ---------------------------------------------------------------------------------------------------------------------
       |       19 000  	       |      2991000           |     270 060,52416      |       ...         |         ...
       ---------------------------------------------------------------------------------------------------------------------

       Como se puede observar, la diferencia entre la penutima y la ultima columna es muy poca en la matoria de los casos,
       incluso menor a 0,1 por lo que se ve que el algoritmo cumple este comportamiento.
       Si se cren arrays más grandes y se sigue comparando siempre va a seguir este comportamiento.
    */

    pruebaQuickSortRandom(arr11, 7000, 1);
    pruebaQuickSortRandom(arr12, 8000, 2);
    pruebaQuickSortRandom(arr13, 9000, 3);
    pruebaQuickSortRandom(arr14, 10000, 4);
    pruebaQuickSortRandom(arr15, 11000, 5);
    pruebaQuickSortRandom(arr16, 12000, 6);
    pruebaQuickSortRandom(arr17, 13000, 7);
    pruebaQuickSortRandom(arr18, 14000, 8);
    pruebaQuickSortRandom(arr19, 15000, 9);
    pruebaQuickSortRandom(arr20, 16000, 10);
    pruebaQuickSortRandom(arr21, 17000, 11);
    pruebaQuickSortRandom(arr22, 18000, 12);
    pruebaQuickSortRandom(arr23, 19000, 13);
    // pruebaQuickSortRandom(arr24, 20000, 14);
    // pruebaQuickSortRandom(arr25, 21000, 15);
    // pruebaQuickSortRandom(arr26, 22000, 16);


    // ------------------------------------------------------------------------------------------------------------------------------------------------
    // ------------------------------------------------------------------------------------------------------------------------------------------------
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "___________________________________________________________________________________________________" << endl;
    cout << "\n\n--------------------------------------------------" << endl;
    cout << "\tQUICK_SORT DIFERENCIA ENTRE PIVOT FIJO Y ALEATORIO" << endl;
    cout << "--------------------------------------------------" << endl;

    /*
    ¿Cuál es la influencia del pivot random?
        Este es un tema que da mucho de que pensar. Siempre está la duda de 
        si es mejor el pivot random o fijo, pero depende mucho de la lista
        y de la implementación que se desea hacer.

        Como en el caso que mostré en las pruebas del peor de los casos O(n^2) que 
        la lista sigue un orden, el pivot fijo es claramente menos eficiente
        que el pivot aleatorio. En este caso en específico es mejor utilizar 
        el random porque nos puede dar un valor que no sea el máximo y de esta
        forma lograr obtener unas divisiones recursivas mejor balanceadas.
        El fijo solo nos crea un desnivel hacia un lado, y no es lo que buscamos
        en este algoritmo. Por lo que el porcentaje de mejora del random en este 
        caso es claramente favorable.

        Pero si el array está desordenado y no se sabe si sigue un patrón u 
        orden en específico, es trivial saber si el fijo o random es mejor. 
        Ya entra tambien cual es la implementacion que desea hacer el programador,
        porque no es medible cual es la mejor opción.
    */


    pruebaQuickSortBoth(arr11, 7000, 1);
    pruebaQuickSortBoth(arr12, 8000, 2);
    pruebaQuickSortBoth(arr13, 9000, 3);
    pruebaQuickSortBoth(arr14, 10000, 4);
    pruebaQuickSortBoth(arr15, 11000, 5);
    pruebaQuickSortBoth(arr16, 12000, 6);
    pruebaQuickSortBoth(arr17, 13000, 7);
    pruebaQuickSortBoth(arr18, 14000, 8);
    pruebaQuickSortBoth(arr19, 15000, 9);
    pruebaQuickSortBoth(arr20, 16000, 10);
    
}
