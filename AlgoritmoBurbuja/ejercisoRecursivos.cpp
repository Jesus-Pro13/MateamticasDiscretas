#include <iostream>

using namespace std;

double potencia(double a, int n) {
    if (n == 0) {
        return 1;
    } else {
        return a * potencia(a, n - 1);
    }
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int busquedaLineal(int a[], int i, int j, int x) {
    if (a[i] == x) {
        return i;
    } else if (i == j) {
        return 0; 
    } else {
        return busquedaLineal(a, i + 1, j, x);
    }
}

int busquedaBinaria(int a[], int izq, int der, int x) {
    if (izq > der) {
        return -1; 
    }
    
    int medio = izq + (der - izq) / 2;
    
    if (a[medio] == x) {
        return medio;
    } else if (x < a[medio]) {
        return busquedaBinaria(a, izq, medio - 1, x);
    } else {
        return busquedaBinaria(a, medio + 1, der, x);
    }
}

int main() {
    int opcion;
    
    do {
        cout << "\n--- MENU DE ALGORITMOS RECURSIVOS ---\n";
        cout << "1. Calcular potencia\n";
        cout << "2. Calcular factorial\n";
        cout << "3. Busqueda lineal\n";
        cout << "4. Busqueda binaria\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion) {
            case 1: {
                double base;
                int exponente;
                cout << "Ingresa la base: ";
                cin >> base;
                cout << "Ingresa el exponente: ";
                cin >> exponente;
                cout << "El resultado es: " << potencia(base, exponente) << endl;
                break;
            }
            case 2: {
                int num;
                cout << "Ingresa un numero entero positivo: ";
                cin >> num;
                if (num < 1) {
                    cout << "El numero debe ser mayor o igual a 1" << endl;
                } else {
                    cout << "El factorial de " << num << " es: " << factorial(num) << endl;
                }
                break;
            }
            case 3: {
                int tamano;
                cout << "Ingresa la cantidad de elementos del arreglo: ";
                cin >> tamano;
                
                int* datos = new int[tamano];
                
                cout << "Ingresa los " << tamano << " elementos:\n";
                for (int k = 0; k < tamano; k++) {
                    cout << "Elemento [" << k << "]: ";
                    cin >> datos[k];
                }
                
                int buscar;
                cout << "Que numero quieres buscar ";
                cin >> buscar;
                
                int posicion = busquedaLineal(datos, 0, tamano - 1, buscar);
                
                if (posicion != 0 || datos[0] == buscar) {
                    cout << "Numero encontrado en el indice: " << posicion << endl;
                } else {
                    cout << "El numero no se encuentra en el arreglo" << endl;
                }
                
                delete[] datos;
                break;
            }
            case 4: {
                int tamano;
                cout << "Ingresa la cantidad de elementos del arreglo: ";
                cin >> tamano;
                
                int* datosOrdenados = new int[tamano];
                
                cout << "Ingresa los " << tamano << " elementos :\n";
                for (int k = 0; k < tamano; k++) {
                    cout << "Elemento [" << k << "]: ";
                    cin >> datosOrdenados[k];
                }
                
                int buscar;
                cout << "Que numero quieres buscar ";
                cin >> buscar;
                
                int posicion = busquedaBinaria(datosOrdenados, 0, tamano - 1, buscar);
                
                if (posicion != -1) {
                    cout << "Numero encontrado en el indice: " << posicion << endl;
                } else {
                    cout << "El numero no se encuentra en el arreglo" << endl;
                }
                
                delete[] datosOrdenados;
                break;
            }
            default:
                cout << "Opcion no valida Intenta de nuevo" << endl;
        }
    } while(opcion != 0);

    return 0;
}