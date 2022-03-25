# Moises_Caso2
Archivos del caso 2 del curso Analisis de Algoritmos

IMPORTANTE: 
----------------------------------------------------
El archivo "DonQuijote.txt" es el archivo de mas de 10MB para la prueba del freetext,
el archivo "worstCase.txt" es un archivo con los mismos caracteres para una pequeña 
prueba del peor caso.

También se adjunta el archivo "datos.xlsx" con unas tablas y gráficas de excel.

Por último, hay un Makefile para los 3 .cpp, por lo que para ejecutar cada uno
se debe correr el ejecutable por separado. 

-----------------------------------------------------------------------
QUICK_SORT PEOR DE LOS CASOS O(n^2)
-----------------------------------------------------------------------
    
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


-----------------------------------------------------------------------
QUICK_SORT O(nlogn)
-----------------------------------------------------------------------

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


-----------------------------------------------------------------------
QUICK_SORT DIFERENCIA ENTRE PIVOT FIJO Y ALEATORIO
-----------------------------------------------------------------------

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


-----------------------------------------------------------------------
INSERTION_SORT MEJOR DE LOS CASOS O(n)
-----------------------------------------------------------------------

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

-----------------------------------------------------------------------
INSERTION_SORT PEOR DE LOS CASOS O(n^2)
-----------------------------------------------------------------------

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



-----------------------------------------------------------------------
ALGORITMO DE BUSQUEDA DE TEXTO LINEAL, PEOR DE LOS CASOS
-----------------------------------------------------------------------

Para el algoritmo el peor de los casos expresado en terminos de O grande es
      O(m + (n - m + 1))
      => O(m + (n - m))
      => O(m + n - m)
      => O(n)

      Esto quiere decir que es un algoritmo lineal.

      ¿Por que sucede esto?
         Esto se da especificamente porque el peor de los casos es cuando todos los caracteres
         del patron buscado son iguales a todas las letras del texto. Quiere decir que siempre 
         existirá la igualdad. 
         Por lo que en el algoritmo lo que sucede es lo siguiente: 
            -> Se calculan los hash al principio en un ciclo de tamaño del patron (m) por
            lo que ese ciclo siempre se va a dar en todos los casos sea el mejor, promedio o
            peor y es de O(m).

            -> Luego sigue el ciclo for para las comparaciones que va de 0 hasta n-m;
            por lo que en el peor de los casos se realiza el ciclo completo que tiene 
            una complejidad temporal de O(n - m + 1) por la condicion de salida.

            -> En conclusion en el peor de los casos ocurriria que se deben hacer todas las 
            comparaciones, y las dos notaciones de O grande que mencioné se sumarán,
            dando como resultado el O(n) de complejidad temporal.

            -> Por esta razón el algoritmo de busqueda es lineal.

-------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------


-----------------------------------------------------------------------
PRUEBAS = QUICK_SORT PEOR DE LOS CASOS O(n^2)
-----------------------------------------------------------------------

--------------------
1. Prueba Quick_Sort (1000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 1998
        ->Llamadas Partition = 999
        ->Iteraciones Partition = 499500
        ->Swaps = 500499

        ->Tiempo de ejecucion: 2029000 nanosegundos.

        ->Tiempo de ejecucion: 0.003 segundos.

--------------------
2. Prueba Quick_Sort (2000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 3998
        ->Llamadas Partition = 1999
        ->Iteraciones Partition = 1999000
        ->Swaps = 2000999

        ->Tiempo de ejecucion: 10995000 nanosegundos.

        ->Tiempo de ejecucion: 0.011 segundos.

--------------------
3. Prueba Quick_Sort (3000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 5998
        ->Llamadas Partition = 2999
        ->Iteraciones Partition = 4498500
        ->Swaps = 4501499

        ->Tiempo de ejecucion: 26927000 nanosegundos.

        ->Tiempo de ejecucion: 0.027 segundos.

--------------------
4. Prueba Quick_Sort (4000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 7998
        ->Llamadas Partition = 3999
        ->Iteraciones Partition = 7998000
        ->Swaps = 8001999

        ->Tiempo de ejecucion: 46876000 nanosegundos.

        ->Tiempo de ejecucion: 0.047 segundos.

--------------------
5. Prueba Quick_Sort (5000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 9998
        ->Llamadas Partition = 4999
        ->Iteraciones Partition = 12497500
        ->Swaps = 12502499

        ->Tiempo de ejecucion: 71809000 nanosegundos.

        ->Tiempo de ejecucion: 0.072 segundos.

--------------------
6. Prueba Quick_Sort (6000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 11998
        ->Llamadas Partition = 5999
        ->Iteraciones Partition = 17997000
        ->Swaps = 18002999

        ->Tiempo de ejecucion: 105011000 nanosegundos.

        ->Tiempo de ejecucion: 0.104 segundos.

--------------------
7. Prueba Quick_Sort (7000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 13998
        ->Llamadas Partition = 6999
        ->Iteraciones Partition = 24496500
        ->Swaps = 24503499

        ->Tiempo de ejecucion: 140593000 nanosegundos.

        ->Tiempo de ejecucion: 0.141 segundos.

--------------------
8. Prueba Quick_Sort (8000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 15998
        ->Llamadas Partition = 7999
        ->Iteraciones Partition = 31996000
        ->Swaps = 32003999

        ->Tiempo de ejecucion: 184359000 nanosegundos.

        ->Tiempo de ejecucion: 0.184 segundos.

--------------------
9. Prueba Quick_Sort (9000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 17998
        ->Llamadas Partition = 8999
        ->Iteraciones Partition = 40495500
        ->Swaps = 40504499

        ->Tiempo de ejecucion: 233003000 nanosegundos.

        ->Tiempo de ejecucion: 0.233 segundos.

--------------------
10. Prueba Quick_Sort (10000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 19998
        ->Llamadas Partition = 9999
        ->Iteraciones Partition = 49995000
        ->Swaps = 50004999

        ->Tiempo de ejecucion: 288737000 nanosegundos.

        ->Tiempo de ejecucion: 0.289 segundos.




-----------------------------------------------------------------------
PRUEBAS = QUICK_SORT O(nlogn)
-----------------------------------------------------------------------

-------------------------------------
1. Prueba Quick_Sort con pivot Random (7000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 9414
        ->Llamadas Partition = 4707
        ->Iteraciones Partition = 105330
        ->Swaps = 58609

        ->Tiempo de ejecucion: 997000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

-------------------------------------
2. Prueba Quick_Sort con pivot Random (8000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 10836
        ->Llamadas Partition = 5418
        ->Iteraciones Partition = 114200
        ->Swaps = 63603

        ->Tiempo de ejecucion: 1022000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

-------------------------------------
3. Prueba Quick_Sort con pivot Random (9000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 12146
        ->Llamadas Partition = 6073
        ->Iteraciones Partition = 141418
        ->Swaps = 87321

        ->Tiempo de ejecucion: 998000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

-------------------------------------
4. Prueba Quick_Sort con pivot Random (10000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 13494
        ->Llamadas Partition = 6747
        ->Iteraciones Partition = 183884
        ->Swaps = 116556

        ->Tiempo de ejecucion: 1970000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
5. Prueba Quick_Sort con pivot Random (11000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 14842
        ->Llamadas Partition = 7421
        ->Iteraciones Partition = 183729
        ->Swaps = 110177

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
6. Prueba Quick_Sort con pivot Random (12000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 16154
        ->Llamadas Partition = 8077
        ->Iteraciones Partition = 189340
        ->Swaps = 105271

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
7. Prueba Quick_Sort con pivot Random (13000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 17504
        ->Llamadas Partition = 8752
        ->Iteraciones Partition = 206412
        ->Swaps = 113783

        ->Tiempo de ejecucion: 1994000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
8. Prueba Quick_Sort con pivot Random (14000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 18934
        ->Llamadas Partition = 9467
        ->Iteraciones Partition = 221825
        ->Swaps = 122667

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
9. Prueba Quick_Sort con pivot Random (15000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 20252
        ->Llamadas Partition = 10126
        ->Iteraciones Partition = 239356
        ->Swaps = 130484

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
10. Prueba Quick_Sort con pivot Random (16000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 21616
        ->Llamadas Partition = 10808
        ->Iteraciones Partition = 258531
        ->Swaps = 141344

        ->Tiempo de ejecucion: 1994000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

-------------------------------------
11. Prueba Quick_Sort con pivot Random (17000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 22860
        ->Llamadas Partition = 11430
        ->Iteraciones Partition = 273380
        ->Swaps = 157149

        ->Tiempo de ejecucion: 2992000 nanosegundos.

        ->Tiempo de ejecucion: 0.003 segundos.
___________________________________________________________________________________________________

-------------------------------------
12. Prueba Quick_Sort con pivot Random (18000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 24242
        ->Llamadas Partition = 12121
        ->Iteraciones Partition = 292407
        ->Swaps = 170529

        ->Tiempo de ejecucion: 2992000 nanosegundos.

        ->Tiempo de ejecucion: 0.003 segundos.
___________________________________________________________________________________________________

-------------------------------------
13. Prueba Quick_Sort con pivot Random (19000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 25540
        ->Llamadas Partition = 12770
        ->Iteraciones Partition = 364605
        ->Swaps = 232547

        ->Tiempo de ejecucion: 2992000 nanosegundos.

        ->Tiempo de ejecucion: 0.003 segundos.



-----------------------------------------------------------------------
PRUEBAS = QUICK_SORT DIFERENCIA ENTRE PIVOT FIJO Y ALEATORIO
-----------------------------------------------------------------------

--------------------
1. Prueba Quick_Sort (7000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 13998
        ->Llamadas Partition = 6999
        ->Iteraciones Partition = 24496500
        ->Swaps = 24503499

        ->Tiempo de ejecucion: 143260000 nanosegundos.

        ->Tiempo de ejecucion: 0.143 segundos.

-------------------------------------
1. Prueba Quick_Sort con pivot Random (7000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 7000
        ->Llamadas Partition = 3500
        ->Iteraciones Partition = 92432
        ->Swaps = 47810

        ->Tiempo de ejecucion: 1004000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

--------------------
2. Prueba Quick_Sort (8000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 15998
        ->Llamadas Partition = 7999
        ->Iteraciones Partition = 31996000
        ->Swaps = 32003999

        ->Tiempo de ejecucion: 187617000 nanosegundos.

        ->Tiempo de ejecucion: 0.188 segundos.

-------------------------------------
2. Prueba Quick_Sort con pivot Random (8000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 8000
        ->Llamadas Partition = 4000
        ->Iteraciones Partition = 106315
        ->Swaps = 56760

        ->Tiempo de ejecucion: 974000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

--------------------
3. Prueba Quick_Sort (9000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 17998
        ->Llamadas Partition = 8999
        ->Iteraciones Partition = 40495500
        ->Swaps = 40504499

        ->Tiempo de ejecucion: 234373000 nanosegundos.

        ->Tiempo de ejecucion: 0.234 segundos.

-------------------------------------
3. Prueba Quick_Sort con pivot Random (9000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 9000
        ->Llamadas Partition = 4500
        ->Iteraciones Partition = 134262
        ->Swaps = 59238

        ->Tiempo de ejecucion: 998000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

--------------------
4. Prueba Quick_Sort (10000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 19998
        ->Llamadas Partition = 9999
        ->Iteraciones Partition = 49995000
        ->Swaps = 50004999

        ->Tiempo de ejecucion: 289257000 nanosegundos.

        ->Tiempo de ejecucion: 0.289 segundos.

-------------------------------------
4. Prueba Quick_Sort con pivot Random (10000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 10000
        ->Llamadas Partition = 5000
        ->Iteraciones Partition = 233164
        ->Swaps = 73860

        ->Tiempo de ejecucion: 996000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

--------------------
5. Prueba Quick_Sort (11000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 21998
        ->Llamadas Partition = 10999
        ->Iteraciones Partition = 60494500
        ->Swaps = 60505499

        ->Tiempo de ejecucion: 348810000 nanosegundos.

        ->Tiempo de ejecucion: 0.349 segundos.

-------------------------------------
5. Prueba Quick_Sort con pivot Random (11000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 16106
        ->Llamadas Partition = 8053
        ->Iteraciones Partition = 256518
        ->Swaps = 77519

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

--------------------
6. Prueba Quick_Sort (12000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 23998
        ->Llamadas Partition = 11999
        ->Iteraciones Partition = 71994000
        ->Swaps = 72005999

        ->Tiempo de ejecucion: 414403000 nanosegundos.

        ->Tiempo de ejecucion: 0.415 segundos.

-------------------------------------
6. Prueba Quick_Sort con pivot Random (12000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 17584
        ->Llamadas Partition = 8792
        ->Iteraciones Partition = 272754
        ->Swaps = 84913

        ->Tiempo de ejecucion: 998000 nanosegundos.

        ->Tiempo de ejecucion: 0.001 segundos.
___________________________________________________________________________________________________

--------------------
7. Prueba Quick_Sort (13000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 25998
        ->Llamadas Partition = 12999
        ->Iteraciones Partition = 84493500
        ->Swaps = 84506499

        ->Tiempo de ejecucion: 487227000 nanosegundos.

        ->Tiempo de ejecucion: 0.487 segundos.

-------------------------------------
7. Prueba Quick_Sort con pivot Random (13000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 15756
        ->Llamadas Partition = 7878
        ->Iteraciones Partition = 282706
        ->Swaps = 98126

        ->Tiempo de ejecucion: 1970000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

--------------------
8. Prueba Quick_Sort (14000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 27998
        ->Llamadas Partition = 13999
        ->Iteraciones Partition = 97993000
        ->Swaps = 98006999

        ->Tiempo de ejecucion: 592901000 nanosegundos.

        ->Tiempo de ejecucion: 0.593 segundos.

-------------------------------------
8. Prueba Quick_Sort con pivot Random (14000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 16964
        ->Llamadas Partition = 8482
        ->Iteraciones Partition = 295778
        ->Swaps = 107371

        ->Tiempo de ejecucion: 1995000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

--------------------
9. Prueba Quick_Sort (15000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 29998
        ->Llamadas Partition = 14999
        ->Iteraciones Partition = 112492500
        ->Swaps = 112507499

        ->Tiempo de ejecucion: 650331000 nanosegundos.

        ->Tiempo de ejecucion: 0.65 segundos.

-------------------------------------
9. Prueba Quick_Sort con pivot Random (15000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 15000
        ->Llamadas Partition = 7500
        ->Iteraciones Partition = 321174
        ->Swaps = 110438

        ->Tiempo de ejecucion: 1971000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

--------------------
10. Prueba Quick_Sort (16000 elementos)
--------------------
Informacion de contadores:
        ->Llamadas recursivas = 31998
        ->Llamadas Partition = 15999
        ->Iteraciones Partition = 127992000
        ->Swaps = 128007999

        ->Tiempo de ejecucion: 740622000 nanosegundos.

        ->Tiempo de ejecucion: 0.741 segundos.

-------------------------------------
10. Prueba Quick_Sort con pivot Random (16000 elementos)
-------------------------------------
Informacion de contadores:
        ->Llamadas recursivas = 21058
        ->Llamadas Partition = 10529
        ->Iteraciones Partition = 339986
        ->Swaps = 133240

        ->Tiempo de ejecucion: 1994000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.



-----------------------------------------------------------------------
PRUEBAS = INSERTION_SORT MEJOR DE LOS CASOS O(n)
-----------------------------------------------------------------------

--------------------
1. Prueba Insertion Sort (1000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
2. Prueba Insertion Sort (2000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 1999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
3. Prueba Insertion Sort (3000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 2999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
4. Prueba Insertion Sort (4000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 3999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
5. Prueba Insertion Sort (5000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 4999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
6. Prueba Insertion Sort (6000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 5999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
7. Prueba Insertion Sort (7000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 6999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
8. Prueba Insertion Sort (8000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 7999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
9. Prueba Insertion Sort (9000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 8999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.
___________________________________________________________________________________________________

--------------------
10. Prueba Insertion Sort (10000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 0
        ->Cantidad de iteraciones del for = 9999

        ->Tiempo de ejecucion: 0 nanosegundos.

        ->Tiempo de ejecucion: 0 segundos.



-----------------------------------------------------------------------
PRUEBAS = INSERTION_SORT PEOR DE LOS CASOS O(n^2)
-----------------------------------------------------------------------

--------------------
1. Prueba Insertion Sort (1000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 499500
        ->Cantidad de iteraciones del for = 999

        ->Tiempo de ejecucion: 1022000 nanosegundos.

        ->Tiempo de ejecucion: 0.002 segundos.
___________________________________________________________________________________________________

--------------------
2. Prueba Insertion Sort (2000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 1999000
        ->Cantidad de iteraciones del for = 1999

        ->Tiempo de ejecucion: 3964000 nanosegundos.

        ->Tiempo de ejecucion: 0.003 segundos.
___________________________________________________________________________________________________

--------------------
3. Prueba Insertion Sort (3000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 4498500
        ->Cantidad de iteraciones del for = 2999

        ->Tiempo de ejecucion: 8976000 nanosegundos.

        ->Tiempo de ejecucion: 0.009 segundos.
___________________________________________________________________________________________________

--------------------
4. Prueba Insertion Sort (4000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 7998000
        ->Cantidad de iteraciones del for = 3999

        ->Tiempo de ejecucion: 17977000 nanosegundos.

        ->Tiempo de ejecucion: 0.018 segundos.
___________________________________________________________________________________________________

--------------------
5. Prueba Insertion Sort (5000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 12497500
        ->Cantidad de iteraciones del for = 4999

        ->Tiempo de ejecucion: 26903000 nanosegundos.

        ->Tiempo de ejecucion: 0.027 segundos.
___________________________________________________________________________________________________

--------------------
6. Prueba Insertion Sort (6000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 17997000
        ->Cantidad de iteraciones del for = 5999

        ->Tiempo de ejecucion: 38897000 nanosegundos.

        ->Tiempo de ejecucion: 0.039 segundos.
___________________________________________________________________________________________________

--------------------
7. Prueba Insertion Sort (7000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 24496500
        ->Cantidad de iteraciones del for = 6999

        ->Tiempo de ejecucion: 53884000 nanosegundos.

        ->Tiempo de ejecucion: 0.054 segundos.
___________________________________________________________________________________________________

--------------------
8. Prueba Insertion Sort (8000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 31996000
        ->Cantidad de iteraciones del for = 7999

        ->Tiempo de ejecucion: 68787000 nanosegundos.

        ->Tiempo de ejecucion: 0.069 segundos.
___________________________________________________________________________________________________

--------------------
9. Prueba Insertion Sort (9000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 40495500
        ->Cantidad de iteraciones del for = 8999

        ->Tiempo de ejecucion: 87340000 nanosegundos.

        ->Tiempo de ejecucion: 0.087 segundos.
___________________________________________________________________________________________________

--------------------
10. Prueba Insertion Sort (10000 elementos)
--------------------
Informacion de contadores:
        ->Contador movimientos = 49995000
        ->Cantidad de iteraciones del for = 9999

        ->Tiempo de ejecucion: 108801000 nanosegundos.

        ->Tiempo de ejecucion: 0.109 segundos.


-----------------------------------------------------------------------
PRUEBAS = ALGORITMO DE BUSQUEDA DE TEXTO LINEAL, PEOR DE LOS CASOS
-----------------------------------------------------------------------

->Tiempo de carga: 0.107

El patron se encontro en la posicion: 1
El patron se encontro en la posicion: 2
El patron se encontro en la posicion: 3
El patron se encontro en la posicion: 4
El patron se encontro en la posicion: 5
El patron se encontro en la posicion: 6
...

El patron se encontro en la posicion: 8482
El patron se encontro en la posicion: 8483
El patron se encontro en la posicion: 8484
El patron se encontro en la posicion: 8485

        ->Tiempo de busqueda: 0.03 segundos.
Cantidad de apariciones del patron (aaaaaaaaaaaaaaaa) = 8485
Contador itearaciones: 8485
N: 8500; M: 16
M + (N-M + 1) = 8485
