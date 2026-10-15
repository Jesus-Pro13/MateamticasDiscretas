#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int obtenerIdNodo(string nombre, map<string, int>& diccionario, map<int, string>& inverso, int& contador) {
    if (diccionario.find(nombre) == diccionario.end()) {
        diccionario[nombre] = contador;
        inverso[contador] = nombre;
        contador++;
    }
    return diccionario[nombre];
}

vector<int> encontrarIsomorfismo(int n, const vector<vector<int>>& g1, const vector<vector<int>>& g2) {
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;

    do {
        bool coinciden = true;
        for (int i = 0; i < n && coinciden; i++) {
            for (int j = 0; j < n && coinciden; j++) {
                if (g1[i][j] != g2[p[i]][p[j]]) {
                    coinciden = false;
                }
            }
        }
        if (coinciden) return p;
        
    } while (next_permutation(p.begin(), p.end()));

    return vector<int>(); 
}

int main() {
    int n, aristas1, aristas2;

    cout << "Ingrese la cantidad de vertices para los grafos: ";
    cin >> n;

    vector<vector<int>> g1(n, vector<int>(n, 0));
    vector<vector<int>> g2(n, vector<int>(n, 0));

    map<string, int> dicc1;
    map<int, string> invDicc1;
    int contador1 = 0;
    
    map<string, int> dicc2;
    map<int, string> invDicc2;
    int contador2 = 0;

    cout << "\n--- GRAFO 1 ---" << endl;
    cout << "Ingrese la cantidad total de aristas (conexiones): ";
    cin >> aristas1;
    for (int i = 0; i < aristas1; i++) {
        string u_str, v_str;
        cout << "Ingrese la arista " << i + 1 << " (origen destino): ";
        cin >> u_str >> v_str;
        
        int u = obtenerIdNodo(u_str, dicc1, invDicc1, contador1);
        int v = obtenerIdNodo(v_str, dicc1, invDicc1, contador1);
        
        g1[u][v] = 1;
        g1[v][u] = 1; 
    }

    cout << "\n--- GRAFO 2 ---" << endl;
    cout << "Ingrese la cantidad total de aristas (conexiones): ";
    cin >> aristas2;
    for (int i = 0; i < aristas2; i++) {
        string u_str, v_str;
        cout << "Ingrese la arista " << i + 1 << " (origen destino): ";
        cin >> u_str >> v_str;
        
        int u = obtenerIdNodo(u_str, dicc2, invDicc2, contador2);
        int v = obtenerIdNodo(v_str, dicc2, invDicc2, contador2);
        
        g2[u][v] = 1;
        g2[v][u] = 1; 
    }

    vector<int> mapeo = encontrarIsomorfismo(n, g1, g2);

    if (!mapeo.empty()) {
        cout << "\nLos grafos SON isomorfos" << endl;
        cout << "\nFuncion Biyectiva encontrada:" << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "f(" << invDicc1[i] << ") = " << invDicc2[mapeo[i]] << endl;
        }
    } else {
       cout << "\nLos grafos NO son isomorfos." << endl;
    }

    return 0;
}