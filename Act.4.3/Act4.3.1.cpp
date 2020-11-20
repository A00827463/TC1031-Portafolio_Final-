#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

// Integrantes: Lucas Idigoras - A00827751
// Sebastian Rodriguez Salinas - A00827463

// Complejidad O(n^2)
void printListAdj(vector<vector<int> > &listAdj){
    cout <<"Adjacesent List: "<< endl;
	for (int i=0; i<listAdj.size(); i++){
		cout << (i+1)<< " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << (listAdj[i][j]+1);
		}
		cout << endl;
	}
}


// Complejidad O(n)
int main(){
    
    int cantIp, cantIncidencias;
    unordered_map<string, pair<int, int> > nodos_ips;
    string ip, mes, hora, mesg, ipOrigen, ipDestino;
    int dia;
    int t1, t2;
    ifstream bitacora;
    bitacora.open("bitacora.txt");
    bitacora >> cantIp >> cantIncidencias;
    for (int i = 0; i <cantIp; i++){
        bitacora >> ip;
        pair <int, int> uno;
        uno.first = i;
        uno.second = 0;
        nodos_ips[ip] = uno;
    }
    
    int max = 0;
    vector<vector<int> > listAdj(cantIp);
    vector<string> boot;
    for(int j = 0; j < cantIncidencias; j++){
        bitacora >> mes >> dia >> hora >> ipOrigen >> ipDestino;
        getline(bitacora, mesg);
        t1 = ipOrigen.find(":");
        t2 = ipDestino.find(":");
        ipOrigen = ipOrigen.substr(0, t1);
        ipDestino = ipDestino.substr(0, t2);
        int numNodoOrigen = nodos_ips[ipOrigen].first;
        int numNodoDestino = nodos_ips[ipDestino].first;
        nodos_ips[ipOrigen].second++;
        if (max < nodos_ips[ipOrigen].second){
            max = nodos_ips[ipOrigen].second;
            
        }
        listAdj[numNodoOrigen].push_back(numNodoDestino);
    }

    for(auto it = nodos_ips.begin(); it != nodos_ips.end(); it++){
        if(it->second.second == max){
            cout << it->first << "  " << it->second.second << endl;
        }
    }
    // printListAdj(listAdj);
    bitacora.close();

    return 0;
}