/*
Moisés Solano Espinoza
2021144322
Caso 2
FreeText Algorithm
*/
#include <iostream>
#include <time.h>
#include <ctime>
#include <string>
#include <fstream>



using namespace std;

// variables para la medicion de tiempo
unsigned t0, t1;

int contadorApariciones = 0;
int contadorIteraciones = 0;

void rabinKarp(string patron, string texto) {
   int m = patron.length(); // variables que contienen el largo de 
   int n = texto.length(); // los strings

   int baseHash = 3456867; // numero utilizado para el hash

   int i, j; // variables para los ciclos

   int patronHash = 0; // hash del patron
   int textHash = 0; // hash del texto

   // En este ciclo se calcula el hash del patron y del texto                                         // m
   for (i = 0; i < m; i++) {
      patronHash = (patron[i]) % baseHash;
      textHash = (texto[i]) % baseHash;
   }

   // ciclo for para encontrar las apariciones del patron en
   // el texto
   for (i = 0; i <= n - m; i++) { // condicion de parada para no sobrepasar                           // n - m + 1
                                  // los indices al final
      
      contadorIteraciones++;
      if (patronHash == textHash) { // los hashes son iguales
         

         for (j = 0; j < m; j++) { // como los hashes son iguales se procede
                                  // a comparar las letras
            if (texto[i + j] != patron[j]){ // caso en el que no son iguales
               break;
            }
         }
         if (j == m){ // se encontró el patrón
            cout << "El patron se encontro en la posicion: " << i + 1 << endl;
			   contadorApariciones++;
			}
      }
      if (i < n - m) {
         textHash = (texto[i + m]) % baseHash; // se calcula de nuevo el hash del texto
            
         if (textHash < 0){
            textHash = (textHash + baseHash);
         }
      }
   }
}

int main()
{
   cout << "----------------------------------------------------------------------------------------" << endl;
   cout << "###################################### CASO 2 ########################################" << endl;
   cout << "----------------------------------------------------------------------------------------" << endl;

   cout << "\n\n-------------------------------------------" << endl;
   cout << "\tALGORITMO DE BUSQUEDA DE TEXTO LINEAL" << endl;
   cout << "-------------------------------------------" << endl;

   // variables que contienen el texto
	string linea;
	string textoT;
	string texto;

   double time; // variable para la medicion del tiempo
   t0 = clock();

   // se abre el fichero del archivo .txt
	fstream archivo("DonQuijote.txt");

   // ciclo para leer el archivo
	while(!archivo.eof()){
		// archivo >> textoT;
		// texto += textoT;
		getline(archivo, textoT);
		texto += textoT;
		// texto += " ";
	}
	archivo.close(); // se cierra el fichero
   t1 = clock();

   time = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "->Tiempo de carga: " << time << "\n" << endl;

	string patron = "Felizmente"; // patron que se desea buscar

   t0 = clock();
	rabinKarp(patron, texto);
   t1 = clock();

   time = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "\n\t->Tiempo de busqueda: " << time << " segundos." << endl;

	cout << "Cantidad de apariciones del patron (" << patron << ") = " << contadorApariciones << endl;


   // ------------------------------------------------------------------------------------------------
   // Prueba peor caso
   // ------------------------------------------------------------------------------------------------
   cout << "\n\n___________________________________________________________________________________________________" << endl;
   cout << "___________________________________________________________________________________________________" << endl;
   cout << "___________________________________________________________________________________________________" << endl;
   cout << "___________________________________________________________________________________________________" << endl;

   cout << "---------------------------------------------------" << endl;
   cout << "\tALGORITMO DE BUSQUEDA DE TEXTO LINEAL PEOR CASO" << endl;
   cout << "---------------------------------------------------" << endl;


   /*
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
   */


   contadorApariciones = 0;
   contadorIteraciones = 0;

   // se abre el fichero del archivo .txt
	fstream archivo2("worstCase.txt");
   texto = "";
   textoT = "";

   // ciclo para leer el archivo
	while(!archivo2.eof()){
		// archivo >> textoT;
		// texto += textoT;
		getline(archivo2, textoT);
		texto += textoT;
		// texto += " ";
	}
	archivo2.close(); // se cierra el fichero
   t1 = clock();

   time = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "->Tiempo de carga: " << time << "\n" << endl;

	patron = "aaaaaaaaaaaaaaaa"; // patron que se desea buscar

   t0 = clock();
	rabinKarp(patron, texto);
   t1 = clock();

   time = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "\n\t->Tiempo de busqueda: " << time << " segundos." << endl;

	cout << "Cantidad de apariciones del patron (" << patron << ") = " << contadorApariciones << endl;
   cout << "Contador itearaciones: " << contadorIteraciones << endl;
   cout << "N: " << texto.length() << "; M: " << patron.length() << endl;
   cout << "M + (N-M + 1) = " << contadorIteraciones << endl;
	return 0;
}
