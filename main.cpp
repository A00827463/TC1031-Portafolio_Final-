#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "FuncionesVector.h"

int main() {
    // declarando variables para lectura del archivo;
    vector<Dato>v;
    Dato x;
    string mes, ip, hora, mensaje;
    int dia, i=0;
    ifstream bitacora;
    bitacora.open("bitacora.txt");
    
    while(bitacora >> mes >> dia >> hora >> ip){
        v.push_back(x); // evita error de ACCESS CODE al cargar datos;
        getline(bitacora,mensaje);
        v[i].mes = mes;
        v[i].dia = dia;
        v[i].hora = hora;
        v[i].ip = ip;
        v[i].mensaje = mensaje;
        i++;
    }
    crearKey(v); // crear Id que corresponde al mes y el dia
    selecDirecta(v); // metodo de ordenamiento;
    
    
    // comenzando seccion de busqueda
    bool seguir = true;
    int cantidadBusquedas = 1;
    while(seguir){
        string mesIncio, mesFin;
        int fInico, fFin, diaInicio, diaFin;
        cout << "Ingrese la fecha de inicio de busqueda: " << endl;
        cin >> mesIncio;
        cin >> diaInicio;
        fInico = crearFecha(mesIncio, diaInicio);
        cout << "ingrese la fecha de fin:" << endl;
        cin >> mesFin >> diaFin;
        fFin = crearFecha(mesFin, diaFin); // crear la fecha en formato de Key
        int indiceInicio = busqBinaria(v, fInico);
        int indiceFin = busqBinaria(v, fFin);
        
        while (v[indiceInicio].key == v[indiceInicio-1].key) {
            indiceInicio --;
        }
        while (v[indiceFin].key == v[indiceFin+1].key) {
            indiceFin ++;
        }
        
        vector<Dato> resultante;

        for(int j = indiceInicio; j <= indiceFin; j++){
            resultante.push_back(v[j]);
        }
        cout << "desplegando resultado de la busqueda" << " " << cantidadBusquedas  << endl;
        printVect(resultante);
        cout << "desea realizar otra busqueda? (s/n)" << endl;
        string comprobacion;
        cin >> comprobacion;
        if(comprobacion == "n"){
            seguir = false;
        }
        else{
            cantidadBusquedas ++;
            seguir = true;
        }
    }
    // imprimiendo bitacora ordenada en el  archivo Resultado.txt
    ofstream fs;
    int t = v.size();
    fs.open("Resultado.txt");
    for(int i =0; i < t ; i++){
        fs << v[i].mes << " " << v[i].dia << " " << v[i].hora
        << " " << v[i].ip << " " << v[i].mensaje << endl;
    }
    return 0;
}
