#include "vmc.h"

Vecino buscarMinimo(const vector<Vecino>& vecinos, vector<bool>& visitados){
    Vecino min(-1,-1,0);
    int ind;
    
    //Iniciliazacion peso minimo. Se busca el primer vecino no visitado.
    for (int i = 0; i < vecinos.size(); i++) {
        if(visitados[vecinos[i].dst] == false){
            min = vecinos[i];
            ind = i;
            break;
        }
    }

    // Busqueda de un vecino que tenga el minimo peso.
    for (int i = ind + 1 ; i < vecinos.size(); i++){
        if (visitados[vecinos[i].dst] == false && vecinos[i].peso < min.peso) {
            min = vecinos[i];
        }
    }
    return min;
}

Vecino buscarAristaMinima(const vector<Vecino>& vecinos, int w){
    Vecino min(-1,-1,0);
    int ind = 0;

    //Inicializacion peso minimo. Se busca la primer arista a w.
    for (int i = 0; i < vecinos.size(); i++) {
        if(vecinos[i].dst == w){
            min = vecinos[i];
            ind = i;
            break;
        }
    }

    // Busqueda de una arista a w que tenga el minimo peso.
    for (int i = ind + 1 ; i < vecinos.size(); i++){
        if (vecinos[i].dst == w && vecinos[i].peso < min.peso) {
            min = vecinos[i];
        }
    }
    return min;
}

pair<vector<int>,int> VMC(const Grafo& G){ 
    vector<int> H ;  //almacena los vertices del ciclo en orden
    int costo = 0;
    int n = G.size();
    vector<bool> visitados(n);

    // agrego primer vertice del ciclo
    int v = 0;
    H.push_back(v);
    visitados[v] = true;
    for (int i = 0 ; i < n-1; i++){  
        
        Vecino w = buscarMinimo(G[v], visitados);
        if (w.dst == -1) return make_pair(H,costo); // No se encontro ningun vecino que no genere ciclos.

        visitados[w.dst] = true;
        costo = costo + w.peso;
        H.push_back(w.dst);
        
        v = w.dst;
    }
    Vecino cierre = buscarAristaMinima(G[H[n-1]],H[0]); // arista que cierra el ciclo.

    return make_pair(H,costo_camino(G, H) );
}