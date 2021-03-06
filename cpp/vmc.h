#ifndef TP2_ALGO3_VMC_H
#define TP2_ALGO3_VMC_H

#include "tipos.h"
#include "aux.h"

Vecino buscarMinimo(const vector<Vecino>& vecinos, vector<bool>& visitados);
Vecino buscarAristaMinima(const vector<Vecino>& vecinos, int w);
pair<vector<int>,int> VMC(const Grafo& G);

#endif //TP2_ALGO3_VCM_H