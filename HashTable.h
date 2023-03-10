/*
 * HashTable.h
 * La clase HashTable implementa las funciones de una tabla Hash con encadenamiento
 * Autor: Mauricio Garcia Villanueva - A01704098
 * Creado el 21/11/22
 *
 */

#ifndef ACT5_1_HASHTABLE_H
#define ACT5_1_HASHTABLE_H

#include <list>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include "IP.h"
#include <math.h>

using namespace std;

class HashTable{
private:
    int size;
    list<pair<string, string>> *map;
public:
    HashTable();
    HashTable(int n);
    ~HashTable();

    int hashFunction(string key);
    void insert(string key, string value);
    void search(string key);
    void remove(string key);
    void printHash();

};


/*
 * Constructor Default
 */
HashTable::HashTable()
{
    this->size = 10;
    map = new list <pair<string, string>> [this->size];
}
/*
 * Constructor Default con valor
 */
HashTable::HashTable(int n)
{
    this->size = n;
    map = new list <pair<string, string>> [this->size];
}
/*
 * Destructor
 */
HashTable::~HashTable() {
    delete[] map;
}
/*
 * El metodo hashFunction genera el indice del elemento con O(1)
 */
int HashTable :: hashFunction(string key) {

    stringstream ip1(key);
    string s1, s2, s3,s4;

    getline(ip1, s1, '.');getline(ip1, s2, '.');
    getline(ip1, s3, '.');getline(ip1, s4, ':');

    int num1 = stoi(s1); int num2 = stoi (s2);
    int num3 = stoi (s3); int num4 = stoi (s4);

    num1 = pow(num1, 1);
    num2 = pow(num2, 2);
    num3 = pow(num3, 3);
    num4 = pow(num4, 4);

    int total = num1 + num2+ num3 + num4;

    return (total % size);
}
/*
 * El metodo insert agrega los elementos a la tabla con O(1).
 */
void HashTable::insert(string key, string value){
    int index = hashFunction(key);
    map[index].emplace_back(key, value);
}
/*
 * El metodo search busca un elemento de la tabla con O(1).
 * Existe la excepcion en la que las claves de dos elementos son
 * la misma por lo que la complejidad deja de ser O(1).
 */
void HashTable::search(string key) {
    int index = hashFunction(key);
    auto& cell = map[index];
    auto bItr = begin(cell);
    bool keyExist = false;
    for(; bItr != end(cell) ; bItr++){
        if(bItr->first == key){
            keyExist = true;
            cout << "Key: " << bItr->first << " [EXISTE] y su informacion es: " << bItr->second << endl;
            break;
        }
    }
    if(!keyExist){
        cout << "[WARNING] Key: "<< key << " no ha sido encotrada" << endl;
    }
    return;

}
/*
 * El metodo remove elimina un elemento de la tabla con O(1).
 * Existe la excepcion en la que las claves de dos elementos son
 * la misma por lo que la complejidad deja de ser O(1).
 */
void HashTable::remove(string key) {
    int index = hashFunction(key);
    auto& cell = map[index];
    auto bItr = begin(cell);
    bool keyExist = false;
    for(; bItr != end(cell) ; bItr++){
        if(bItr->first == key){
            keyExist = true;
            cout << "Key: " << bItr->first;
            bItr =  cell.erase(bItr);
            cout << " se ha eliminado" << endl;
            break;
        }
    }
    if(!keyExist){
        cout << "[WARNING] Key: "<< key << " no encontrada" << endl;
    }
    return;

}

/*
 * El metodo printHash imprime los elemntos de la tabla con O(N)
 */
void HashTable::printHash() {

    for (int i = 0; i < size; i++) {
        cout << i;

        for (auto x : map[i])
            cout << " --> [" << "Key: " << x.first << " Value: " << x.second << "]";
        cout << endl;
    }
    return;
}




#endif //ACT5_1_HASHTABLE_H
