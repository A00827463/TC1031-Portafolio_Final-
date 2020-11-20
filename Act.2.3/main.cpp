// Sebastian Rodriguez A00827463
// Lucas Idigoras A00827751
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;
#include "Node.h"
#include "DoubleLinkedList.h"


// Complejidad O(n)
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

int main()
{
    DoubleLinkedList<Dato> lista;
    Dato x;
    string mes, ip, hora, mensaje, ipInicio, ipFin;
    int dia;
    long lIpInicio, lIpFin;
    ifstream bitacora;
    bitacora.open("Bitacora.txt");
    while (bitacora >> mes >> dia >> hora >> ip)
    {
        getline(bitacora, mensaje);
        x.dia = dia;
        x.mes = mes;
        x.hora = hora;
        x.ip = ip;
        x.ipKey = ipToLong(x.ip);
        x.mensaje = mensaje;
        lista.addAtLast(x);
    }
    lista.sortBurbuja();


    bool seguir = true;
    int cantidadBusquedas = 1;
    while (seguir)
    {
        cout << "Ingrese el Ip de inicio: "; cin >> ipInicio;
        // ipInicio = "104.58.845.3:5423";
        lIpInicio = ipToLong(ipInicio);

        cout << "ingrese el Ip de fin: "; cin >> ipFin;
        // ipFin = "932.13.249.9:4646";
        lIpFin = ipToLong(ipFin);
        cout << "\033[2J\033[1;1H";
        int indiceInicio = lista.busqSec(lIpInicio);
        int indiceFin = lista.busqSec(lIpFin);

        if (indiceInicio == -1 || indiceFin == -1)
        {
            cout << " → ip Inicial o Final Incorrecto, verificar datos e intenta de nuevo" << endl;
            usleep(5000000);
            cout << "\033[2J\033[1;1H";
            cout << "Regresando..."<<endl;
            usleep(3000000);
            cout << "\033[2J\033[1;1H";
            continue;
        }
        DoubleLinkedList<Dato> resultante;
        lista.addFromTo(resultante, indiceInicio, indiceFin);
        cout << "Desplegando resultado de la busqueda No. " << cantidadBusquedas << endl;
        resultante.print();
        cout << "Desea realizar otra busqueda? (s/n)" << endl;
        string comprobacion;
        cin >> comprobacion;
        if (comprobacion == "n")
        {
            cout << "\033[2J\033[1;1H";
            cout <<"Hasta Luego !"<<endl;
            seguir = false;
        }
        else
        {
            cantidadBusquedas++;
            seguir = true;
        }
        resultante.~DoubleLinkedList();
    }

    lista.txt();
    lista.~DoubleLinkedList();
    return 0;
}