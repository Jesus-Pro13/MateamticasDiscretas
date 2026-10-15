#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void encontrarCircuitos(int n, int nodoActual, vector<bool>& visitado, vector<int>& circuito, int pesoActual, const vector<vector<pair<bool, int>>>& grafo, int& contador) {
    
    if (circuito.size() == n) {
        if (grafo[nodoActual][0].first) {
            if (circuito[1] < circuito.back()) {
                contador++;
                int pesoTotal = pesoActual + grafo[nodoActual][0].second;
                
                cout << "Circuito " << contador << ": C1";
                for (int i = 1; i < circuito.size(); ++i) {
                    cout << " -> C" << circuito[i] + 1;
                }
                cout << " -> C1 | Peso Total: " << pesoTotal << "\n";
            }
        }
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (!visitado[i] && grafo[nodoActual][i].first) {
            visitado[i] = true;
            circuito.push_back(i);
            
            encontrarCircuitos(n, i, visitado, circuito, pesoActual + grafo[nodoActual][i].second, grafo, contador);
            circuito.pop_back();
            visitado[i] = false;
        }
    }
}

int main() {
    int n;
    
    cout << "Ingrese el numero total de ciudades: ";
    cin >> n;

    if (n < 3) {
        cout << " Se necesitan al menos 3 ciudades\n";
        return 0;
    }
    
    vector<vector<pair<bool, int>>> grafo(n, vector<pair<bool, int>>(n, {false, 0}));
    
    cout << "Agregue las aristas una por una\n";
    cout << "Ingrese 0 cuando haya terminado de registrar las aristas\n\n";

    while (true) {
        int origen, destino, peso;
        
        cout << "Ciudad de Origen (1 a " << n << ", o 0 para finalizar): ";
        cin >> origen;
        
        if (origen == 0) {
            break;
        }

        cout << "Ciudad de Destino (1 a " << n << "): ";
        cin >> destino;
        
        cout << "Peso de la ruta: ";
        cin >> peso;
        if (origen > 0 && origen <= n && destino > 0 && destino <= n) {
            if (origen != destino && peso > 0) {
                grafo[origen - 1][destino - 1] = {true, peso};
                grafo[destino - 1][origen - 1] = {true, peso};
                cout << "->  Ruta C" << origen << " <--> C" << destino << " guardada con peso " << peso <<endl<<endl;
            } else {
                cout << "-> El peso debe ser mayor a 0 y no puedes conectar una ciudad consigo misma\n\n";
            }
        } else {
            cout << "->Las ciudades deben estar entre 1 y " << n <<endl<<endl;
        }
    }

    vector<bool> visitado(n, false);
    vector<int> circuito;
    visitado[0] = true;
    circuito.push_back(0); 
    int contador = 0;
    encontrarCircuitos(n, 0, visitado, circuito, 0, grafo, contador);
    
    cout << "Total de circuitos unicos encontrados: " << contador <<endl;

    return 0;
}