#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

// Integrantes: Lucas Idigoras - A00827751
// Sebastian Rodriguez Salinas - A00827463


struct Resumen
{
    string mes, dia, hora;
    string mensaje; 
};

void printAll(unordered_map<string, vector<Resumen> > nodos_ips){
    for(auto it = nodos_ips.begin(); it != nodos_ips.end(); it++){
        cout << "ip: " << it->first <<endl;
        cout << "No. Accesos: " << it->second.size() << endl;
        cout << "Resumen: " << endl;
        for (int i = 0; i<it->second.size();i++){
            cout << it->second[i].mes << " " << it->second[i].dia << " - " << it->second[i].mensaje << endl;
        }
        cout << endl;
    }
}

void printSpesific(unordered_map<string, vector<Resumen> > nodos_ips){
    string opcion;
    cin >> opcion;
    cout << "ip: " << opcion <<endl;
    cout << "No. Accesos: " << nodos_ips[opcion].size() << endl;
    cout << "Resumen: " << endl;
    for (int i = 0; i<nodos_ips[opcion].size();i++){
        cout << nodos_ips[opcion][i].mes << " " << nodos_ips[opcion][i].dia << " - " << nodos_ips[opcion][i].mensaje << endl;
    }
    cout << endl;

}

int main(){
    unordered_map<string, vector<Resumen> > nodos_ips;
    string ip, mes, hora, mesg;
    string dia;
    int t1;
    ifstream bitacora;
    bitacora.open("bitacora.txt");
    Resumen resumen;
    
    int contador = 1;
    while (!bitacora.eof()){
        bitacora >> mes >> dia >> hora >> ip;
        getline(bitacora, mesg);
        resumen.mes = mes;
        resumen.dia = dia;
        resumen.hora = hora;
        resumen.mensaje = mesg;
        t1 = ip.find(":");
        ip = ip.substr(0, t1);
        nodos_ips[ip].push_back(resumen);
        contador++;
    }

    // printAll(nodos_ips);
    bool continuar = true;
    while(continuar){
        printSpesific(nodos_ips);
        cout << "Deseas hacer otra consulta?: si / no"<< endl;
        string respuesta;
        cin >> respuesta;
        if (respuesta == "si"){
            continuar = true;
        }
        else continuar = false;
    }
    bitacora.close();

    return 0;
}