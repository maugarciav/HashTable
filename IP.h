/*
 * IP.h
 * La clase IP crea los objetos IP y implementa sus metodos
 * Autor: Mauricio Garcia Villanueva - A01704098
 * Creado el 7/10/22
 *
 */

#ifndef ACT3_4_IP_H
#define ACT3_4_IP_H


#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

class IP{
protected:
    string mes, error, hora, dirIP;
    int dia;
    int cont;

public:
    IP();
    IP(std::string, int, std::string, std::string, std::string);

    std::string getmes();
    int getdia();
    std::string gethora();
    std::string getdirIp();
    std::string geterror();
    int getcont();
    void contplus();
    void reset();
    std::string toString();

    //Sobrecarga de operador < para comparar las IP`s
    bool operator < (const IP &p1)
    {
        stringstream ip1(p1.dirIP);
        string s1, s2, s3,s4;

        getline(ip1, s1, '.');getline(ip1, s2, '.');
        getline(ip1, s3, '.');getline(ip1, s4, ':');

        int num1 = stoi(s1); int num2 = stoi (s2);
        int num3 = stoi (s3); int num4 = stoi (s4);

        stringstream ip2(this->dirIP);
        string ss1, ss2, ss3,ss4;

        getline(ip2, ss1, '.');getline(ip2, ss2, '.');
        getline(ip2, ss3, '.');getline(ip2, ss4, ':');

        int n1 = stoi(ss1); int n2 = stoi (ss2);
        int n3 = stoi (ss3); int n4 = stoi (ss4);

        if(num1 > n1) return true;
        else if (num1 == n1 && num2 > n2)return true;
        else if (num1 == n1 && num2 == n2 && num3 > n3) return true;
        else if (num1 == n1 && num2 == n2 && num3 == n3 && num4 > n4) return true;
        else return false;
    }

    //Sobrecarga de operador > para comparar las IP`s
    bool operator > (const IP &p1){
        stringstream ip1(p1.dirIP);
        string s1, s2, s3,s4;

        getline(ip1, s1, '.');getline(ip1, s2, '.');
        getline(ip1, s3, '.');getline(ip1, s4, ':');

        int num1 = stoi(s1); int num2 = stoi (s2);
        int num3 = stoi (s3); int num4 = stoi (s4);

        stringstream ip2(this->dirIP);
        string ss1, ss2, ss3,ss4;

        getline(ip2, ss1, '.');getline(ip2, ss2, '.');
        getline(ip2, ss3, '.');getline(ip2, ss4, ':');

        int n1 = stoi(ss1); int n2 = stoi (ss2);
        int n3 = stoi (ss3); int n4 = stoi (ss4);
        if(num1 < n1) return true;
        else if (num1 == n1 && num2 < n2)return true;
        else if (num1 == n1 && num2 == n2 && num3 < n3) return true;
        else if (num1 == n1 && num2 == n2 && num3 == n3 && num4 < n4) return true;
        else return false;

    }

    //Sobrecarga de operador ==  para comparar las IP`s
    bool operator == (IP &p1){
        if(p1.dirIP == this->dirIP){
            p1.contplus();
            return true;
        }
        return false;
    }


};

//Constructor default
IP::IP(){};
//Constructor con 5 parámetros. Recibe el mes, el dia, la hora, la direccion IP y el
// error.
IP::IP(std::string m, int d, std::string h, std::string ip, std::string err){
    mes = m;
    dia = d;
    hora = h;
    dirIP = ip;
    error = err;
    cont = 1;
}
//Métodos de acceso para todas las variables de instancia
std::string IP :: getmes(){
    return mes;
}
int IP :: getdia(){
    return dia;
}
std::string IP :: gethora(){
    return hora;
}
std::string IP :: getdirIp() {
    return dirIP;
}
std::string IP :: geterror(){
    return error;
}
int IP :: getcont (){
    return cont;
}

//El metodo contplus agrega 1 al contador de la IP
void IP ::contplus() {
    cont ++;
}

//El metodo reset resetea el contador de la IP
void IP:: reset(){
    cont = 0;
}

//El metodo toString regresa el objeto IP formateado a una string
string IP::toString() {
    ostringstream aux;
    aux << mes << " " << dia << " " << hora << " "
        << dirIP << " " << error; //" " << cont;
    return aux.str();
}





//Sobrecarga de operadores
#endif //ACT3_4_IP_H
