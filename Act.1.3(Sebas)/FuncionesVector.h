#ifndef FuncionesVector_h
#define FuncionesVector_h

struct Dato{
    int key, dia;
    string mes, hora, ip,mensaje;
};

// imprim el vector y te regresa el tamaño
// Orden(n);
int printVect(vector<Dato> & v){
    int t = v.size();
    for(int i =0; i < t; i++){
        cout <<v[i].key<< " " << v[i].mes << " " << v[i].dia << " " << v[i].hora << " " << v[i].ip << " " << v[i] . mensaje << endl;;
    }
    return t;
}

// creamos una Key que sirve para hacer el sort con enteros
// Complejidad: O(n);
void crearKey (vector <Dato> & v){
    int t = v.size();
    for(int i = 0; i < t; i ++){
        string m = v[i].mes;
        if(m == "Jun"){
            v[i].key = 600 + v[i].dia;
        }
        else if (m == "Jul"){
            v[i].key = 700 + v[i].dia;
        }
        else if (m == "Aug"){
            v[i].key = 800 + v[i].dia;
        }
        else if (m == "Sep"){
            v[i].key = 900 + v[i].dia;
        }
        else{
            v[i].key = 1000 + v[i].dia;
        }
    }
}
// regresa un entero en formato mes + año para que haga match con el key
// Complejidad: O(1)
int crearFecha(string m, int dia){
    int f = 0;
    if(m == "Jun"){
        f = 600 + dia;
        return f;
    }
    else if(m == "Jul"){
        f = 700 + dia;
        return f;
    }
    else if(m == "Aug"){
        f = 800 + dia;
        return f;
    }
    else if(m == "Sep"){
        f = 900 + dia;
        return f;
    }
    else if(m == "Oct"){
        f = 1000 + dia;
        return f;
    }
    else{
        cout << "ingreso una fecha que no se encuentra en la bitacora" << endl;
        return -1;
    }
}


// ordenamiento seleccion directa
// O(n^2);
int selecDirecta(vector <Dato> & v){
    int indiceMayor, t = v.size(), cant = 0;
    Dato aux;
    for(int i = 0; i< t - 1; i ++){
        indiceMayor = 0;
        for(int j = 1; j < t- i; j ++){
            cant ++;
            if(v[j].key > v[indiceMayor].key){
                indiceMayor = j;
            }
        }
        if(indiceMayor != t - i -1){
            aux = v[indiceMayor];
            v[indiceMayor] = v[t-1-i];
            v[t-i-1] = aux;
            
            
        }
    }
    return  cant;
}


// metodo de busqueda que utilizamos
// Complejida: O(log n)
int busqBinaria(vector <Dato> & v, int fBusqueda){
    int fin = v.size() -1, mit, ini = 0;
    
    while(ini <= fin){
        mit = (fin + ini)/2;
        if(v[mit].key == fBusqueda){
            return mit;
        }
        if(v[mit].key > fBusqueda){
            fin = mit - 1;
        }
        else{
            ini = mit + 1;
        }
    }
    return - 1;
}
#endif /* FuncionesVector_h */
