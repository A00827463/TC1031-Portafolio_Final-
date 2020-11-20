#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
#include "Nodo.h"
#include "BST.h"

// Integrantes: Lucas Idigoras - A00827751
// Sebastian Rodriguez Salinas - A00827463

long ipToLong(string ip)
{
    int idx = 0;
    long datoFinal = 0, dato = 0;
    while (idx < ip.size())
    {
        if (ip[idx] != '.' && ip[idx] != ':')
        {
            dato = dato * 10 + ip[idx] - '0';
        }
        else
        {
            datoFinal = datoFinal * 1000 + dato;
            dato = 0;
        }
        idx++;
    }
    datoFinal = datoFinal * 10000 + dato;
    return datoFinal;
}
int main() {
    // system("clear");
    string ip, mes, hora, mesg, ipAuxAnt, ipAuxNueva;
    int dia;
    long ipAnt = 0, ipNueva;
    BST arbol;
    ifstream bitacora;
    bitacora.open("Bitacora.txt");
    int acumulador = 0;
    
    while (bitacora >> mes >> dia >> hora >> ip) {
        getline(bitacora, mesg);
        int indiceFin = ip.find(":");
        ipAuxNueva = ip;
        ip =  ip.substr(0,indiceFin);
        ipNueva = ipToLong(ip);
        if(ipNueva != ipAnt && acumulador > 0){
            arbol.add(acumulador, ipAnt,ipAuxAnt);
            ipAnt = ipNueva;
            ipAuxAnt = ipAuxNueva;
            acumulador = 1;
        }
        else{
            acumulador ++;
            ipAnt = ipNueva;
            ipAuxAnt = ipAuxNueva;
        }
    }
    arbol.add(acumulador, ipAnt,ipAuxAnt);
    bitacora.close();
    arbol.printTop(5);
   
 
    return 0;
}
