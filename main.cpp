#include <iostream>
#include "HashTable.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include "IP.h"


using namespace std;
 

int main()
{

    //Se establece la ruta del archivo de texto
    string route = "/Users/maugarcia/Documents/Universidad/tercer semestre/Analisis de requerimiento de software/Coding/Act 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)/bitacora.txt";

    //Declaracion de variables
    string mes, error, hora, dirIP;
    int dia;

    ifstream inputFile(route);


    //Creamos nuestra tabla con un tamaño de 25000
    HashTable HT(25000);



    //Creamos los objetos y los vamos agregando a la tabla
    while (!inputFile.eof()){   //mientras no sea el final del archivo envia true or false
        inputFile >> mes >> dia >> hora >> dirIP;
        getline(inputFile, error);
        IP ip = IP(mes, dia, hora, dirIP, error);

        HT.insert(dirIP, ip.toString());
    }

    HT.printHash();

    cout << endl << endl;

    //Busacmos por IP
    cout << "Buscar: " << endl;
    HT.search("505.13.173.18:4083"); //IP existente
    HT.search("111.13.173.18:4083"); //IP inexistente

    cout << endl;

    //Eliminamos por IP
    cout << "Eliminar: " << endl;
    HT.remove("505.13.173.18:4083");//IP existente
    HT.remove("111.13.173.18:4083");//IP inexistente


    //Cerramos el archivo
    inputFile.close();
    return 0;
}

