#ifndef TP2_ALGO3_AGM_H
#define TP2_ALGO3_AGM_H

// variables globales
const int INT_MAX;
Vecino V_INDEF;
vector<bool> visitados;
vector<int> orden;


void dfs_rec(int v);
vector<int> dfs(const Grafo& G,int v0);
pair<int, Vecino> buscarmin(const Grafo& g);
Grafo prim(const Grafo& g);
int peso_camino(const Grafo& g, const vector<int>& camino);
void limpiar_visitados();
void AGM(const Grafo& g);

#endif //TP2_ALGO3_AGM_H