#include <iostream>
using namespace std;
// Declaracion de los prototipos de funciones 
void I1();
void I2();
void I3();
void I4();
void I5();
void printArray(int arr[], int size);
void insertionSort(int arr[], int size);
void descendingInsertionSort(int arr[], int size);

int main(){
    int opt;
    
    do {
        // menu
        cout<<"\nMenu de opciones: \n";
        cout<<"1. Ordenar Seis numeros en orden ascendente. .\n";
        cout<<"2. Ordenar seis numeros en orden descendente.\n";
        cout<<"3. Precios.\n";
        cout<<"4. Estaturas.\n";
        cout<<"5. Numeros negativos y positivos.\n";
        cout<<"0. Salir.\n";
        cout<<"Ingrese una opcion: ";
        cin>>opt;

        // Estructura de control para ejecutar la funcion correspondiente a la opcion
        switch(opt){
            case 1:
                I1();
                break;
            case 2:
                I2();
                break;
            case 3:
                I3();
                break;
            case 4:
                I4();
                break;
            case 5:
                I5();
                break;
            case 0:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente de nuevo."<<endl;
        }  
    } while (opt != 0); // El programa termina cuando se ingresa un cero
    
    return 0;
}

// Funcion auxiliar para imprimir el contenido de cualquier arreglo
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Algoritmo de ordenamiento para organizar arreglos de menor a mayor
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Algoritmo de ordenamiento para organizar arreglos de mayor a menor
void descendingInsertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void I1(){
    int n[6];
    for(int i=0; i<6; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }
    
    cout << "\nAntes: ";
    for(int i=0; i<6; i++){
        cout<<n[i]<<" "; 
    }
    cout << endl;
    
    insertionSort(n, 6);
    
    cout << "Despues: ";
    for(int i=0; i<6; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
};
void I2(){
    int n[6];
    for(int i=0; i<6; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }

    
    descendingInsertionSort(n, 6);
    
    cout << "Despues: ";
    for(int i=0; i<6; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
};
void I3(){
    int n[6];
    for(int i=0; i<6; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }
    
    
    cout << endl;
    
    insertionSort(n, 6);
    
    cout<<"El mas barato es: "<<n[0]<<endl;
    cout<<"El mas caro es: "<<n[5]<<endl;
    cout << endl;
};
void I4(){
    int n[6];
    for(int i=0; i<6; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }
    
    cout << "\nAntes: ";
    for(int i=0; i<6; i++){
        cout<<n[i]<<" "; 
    }
    cout << endl;
    
    insertionSort(n, 6);
    
    cout << "Despues: ";
    for(int i=0; i<6; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
};
void I5(){
    int n[8];
    for(int i=0; i<8; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }

    cout << endl;
    
    insertionSort(n, 8);
    
    cout << "Lista Ordenada: ";
    for(int i=0; i<8; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
};

