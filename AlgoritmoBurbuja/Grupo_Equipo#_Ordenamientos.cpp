#include <iostream>
using namespace std;

// Prototipos de funciones generales
void menuBurbuja();
void menuInsercion();
void printArray(int arr[], int size);

// Prototipos Burbuja
void B1();
void B2();
void B3();
void B4();
void B5();
void bubbleSort(int arr[], int size);
void descendingBubbleSort(int arr[], int size);

// Prototipos Insercion
void I1();
void I2();
void I3();
void I4();
void I5();
void insertionSort(int arr[], int size);
void descendingInsertionSort(int arr[], int size);

int main() {
    int opt;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Ejercicios ordenacion burbuja\n";
        cout << "2. Ejercicios ordenacion insercion\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opt;

        switch (opt) {
            case 1:
                menuBurbuja();
                break;
            case 2:
                menuInsercion();
                break;
            case 0:
                cout << "Saliendo del programa general\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo\n";
        }
    } while (opt != 0);

    return 0;
}

// FUNCIONES DE MENU SECUNDARIO


void menuBurbuja() {
    int opt;
    do {
        cout << "\n--- Ejercicios ordenacion burbuja ---\n";
        cout << "1. Ordenar cinco numeros en orden ascendente.\n";
        cout << "2. Ordenar cinco numeros en orden descendente.\n";
        cout << "3. Capturar seis calificaciones enteras del 0 al 10 y ordenarlas.\n";
        cout << "4. Capturar las edades de cinco personas y ordenarlas.\n";
        cout << "5. Capturar siete temperaturas y ordenarlas de mayor a menor.\n";
        cout << "0. Regresar al menu principal.\n";
        cout << "Ingrese una opcion: ";
        cin >> opt;

        switch (opt) {
            case 1: B1(); break;
            case 2: B2(); break;
            case 3: B3(); break;
            case 4: B4(); break;
            case 5: B5(); break;
            default: cout << "Opcion invalida. Intente de nuevo\n";
        }
    } while (opt != 0);
}

void menuInsercion() {
    int opt;
    do {
        cout << "\n--- Ejercicios ordenacion insercion ---\n";
        cout << "1. Ordenar seis numeros en orden ascendente.\n";
        cout << "2. Ordenar seis numeros en orden descendente.\n";
        cout << "3. Precios.\n";
        cout << "4. Estaturas.\n";
        cout << "5. Numeros negativos y positivos.\n";
        cout << "0. Regresar al menu principal.\n";
        cout << "Ingrese una opcion: ";
        cin >> opt;

        switch (opt) {
            case 1: I1(); break;
            case 2: I2(); break;
            case 3: I3(); break;
            case 4: I4(); break;
            case 5: I5(); break;
            default: cout << "Opcion invalida. Intente de nuevo\n";
        }
    } while (opt != 0);
}



void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Algoritmos Burbuja
void bubbleSort(int arr[]) {
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0])-i; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    } 
}

void descendingBubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Algoritmos Insercion
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void descendingInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// FUNCIONES DE EJERCICIOS BURBUJA

void B1() {
    int n[5];
    cout << "\n-- B1. Cinco numeros en orden ascendente --\n";
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa el numero " << (i + 1) << ": ";
        cin >> n[i];
    }
    cout << "\nAntes: ";
    printArray(n, 5);
    bubbleSort(n, 5);
    cout << "Despues: ";
    printArray(n, 5);
}

void B2() {
    int n[5];
    cout << "\n-- B2. Cinco numeros en orden descendente --\n";
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa el numero " << (i + 1) << ": ";
        cin >> n[i];
    }
    descendingBubbleSort(n, 5);
    cout << "\nResultado final: ";
    printArray(n, 5);
}

void B3() {
    int n[6];
    cout << "\n-- B3. Calificaciones --\n";
    for (int i = 0; i < 6; i++) {
        cout << "Ingresa la calificacion " << (i + 1) << ": ";
        cin >> n[i];
        if (n[i] < 0 || n[i] > 10) {
            cout << "La calificacion debe estar entre 0 y 10. Intenta de nuevo.\n";
            i--;
        }
    }
    bubbleSort(n, 6);
    cout << "\nCalificaciones ordenadas: ";
    printArray(n, 6);
    cout << "La calificacion mas baja es: " << n[0] << endl;
    cout << "La calificacion mas alta es: " << n[5] << endl;
}

void B4() {
    int n[5];
    cout << "\n-- B4. Edades --\n";
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa una edad: ";
        cin >> n[i];
    }
    cout << "\nEdades originales: ";
    printArray(n, 5);
    bubbleSort(n, 5);
    cout << "Edades ordenadas: ";
    printArray(n, 5);
}

void B5() {
    int n[7];
    cout << "\n-- B5. Temperaturas --\n";
    for (int i = 0; i < 7; i++) {
        cout << "Ingresa la temperatura " << (i + 1) << ": ";
        cin >> n[i];
    }
    descendingBubbleSort(n, 7);
    cout << "\nTemperaturas ordenadas (mayor a menor): ";
    printArray(n, 7);
    cout << "La temperatura mas alta es: " << n[0] << endl;
}

// FUNCIONES DE EJERCICIOS INSERCION

void I1() {
    int n[6];
    cout << "\n-- I1. Seis numeros ascendentes --\n";
    for (int i = 0; i < 6; i++) {
        cout << "Ingresa un numero: ";
        cin >> n[i];
    }
    cout << "\nAntes: ";
    printArray(n, 6);
    insertionSort(n, 6);
    cout << "Despues: ";
    printArray(n, 6);
}

void I2() {
    int n[6];
    cout << "\n-- I2. Seis numeros descendentes --\n";
    for (int i = 0; i < 6; i++) {
        cout << "Ingresa un numero: ";
        cin >> n[i];
    }
    descendingInsertionSort(n, 6);
    cout << "\nDespues: ";
    printArray(n, 6);
}

void I3() {
    int n[5];
    cout << "\n-- I3. Precios --\n";
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa un precio: ";
        cin >> n[i];
    }
    insertionSort(n, 5);
    cout << "\nEl mas barato es: " << n[0] << endl;
    cout << "El mas caro es: " << n[4] << endl;
}

void I4() {
    int n[5];
    cout << "\n-- I4. Estaturas --\n";
    for (int i = 0; i < 5 ; i++) {
        cout << "Ingresa una estatura: ";
        cin >> n[i];
    }
    cout << "\nAntes: ";
    printArray(n, 5);
    insertionSort(n, 5);
    cout << "Despues: ";
    printArray(n, 5);
}

void I5() {
    int n[8];
    cout << "\n-- I5. Numeros negativos y positivos --\n";
    for (int i = 0; i < 8; i++) {
        cout << "Ingresa un numero: ";
        cin >> n[i];
    }
    insertionSort(n, 8);
    cout << "\nLista Ordenada: ";
    printArray(n, 8);
}