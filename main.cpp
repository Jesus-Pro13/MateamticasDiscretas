#include <iostream>
#include <cstring>

extern "C" {
    #define MAXN 0
    #include "nauty.h"
}
using namespace std;
int main() {
    int n, aristas1, aristas2;

    cout << "Ingrese la cantidad de vertices para los grafos: ";
    cin >> n;

    int m = SETWORDSNEEDED(n);
    nauty_check(WORDSIZE, m, n, NAUTYVERSIONID);

    // Asignación de memoria dinámica para los grafos
    graph* g1 = new graph[n * m];
    graph* g2 = new graph[n * m];
    graph* cg1 = new graph[n * m];
    graph* cg2 = new graph[n * m];

    int* lab1 = new int[n];
    int* ptn1 = new int[n];
    int* orbits1 = new int[n];
    
    int* lab2 = new int[n];
    int* ptn2 = new int[n];
    int* orbits2 = new int[n];

    static DEFAULTOPTIONS_GRAPH(options);
    statsblk stats;
    options.getcanon = TRUE; 

    EMPTYGRAPH(g1, m, n);
    EMPTYGRAPH(g2, m, n);

    // Captura de datos para el Grafo 1
    cout << "\n--- GRAFO 1 ---" << std::endl;
    cout << "Ingrese la cantidad total de aristas (conexiones): ";
    cin >> aristas1;
    for (int i = 0; i < aristas1; i++) {
        int u, v;
        cout << "Ingrese la arista " << i + 1 << " (origen destino): ";
        cin >> u >> v;
        ADDONEEDGE(g1, u, v, m);
    }

    cout << "\n--- GRAFO 2 ---" << std::endl;
    cout << "Ingrese la cantidad total de aristas (conexiones): ";
    cin >> aristas2;
    for (int i = 0; i < aristas2; i++) {
        int u, v;
        cout << "Ingrese la arista " << i + 1 << " (origen destino): ";
        cin >> u >> v;
        ADDONEEDGE(g2, u, v, m);
    }

    densenauty(g1, lab1, ptn1, orbits1, &options, &stats, m, n, cg1);
    densenauty(g2, lab2, ptn2, orbits2, &options, &stats, m, n, cg2);

    if (memcmp(cg1, cg2, n * m * sizeof(graph)) == 0) {
        cout << "\nResultado: ¡Los grafos SON isomorfos!" << std::endl;
    } else {
        cout << "\nResultado: Los grafos NO son isomorfos." << std::endl;
    }

    delete[] g1; delete[] g2; delete[] cg1; delete[] cg2;
    delete[] lab1; delete[] ptn1; delete[] orbits1;
    delete[] lab2; delete[] ptn2; delete[] orbits2;

    return 0;
}