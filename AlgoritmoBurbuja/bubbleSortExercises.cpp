#include <iostream>
using namespace std;
// Declaracion de los prototipos de funciones 
void B1();
void B2();
void B3();
void B4();
void B5();
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void descendingBubbleSort(int arr[], int size);

int main(){
    int opt;
    
    // Ciclo do-while para mantener el menu activo hasta que el usuario decida salir
    do {
        // menu
        cout<<"\nMenu de opciones: \n";
        cout<<"1. Ordenar cinco numeros en orden ascendente.\n";
        cout<<"2. Ordenar cinco numeros en orden descendente.\n";
        cout<<"3. Capturar seis calificaciones enteras del 0 al 10 y ordenarlas.\n";
        cout<<"4. Capturar las edades de cinco personas y ordenarlas.\n";
        cout<<"5. Capturar siete temperaturas y ordenarlas de mayor a menor.\n";
        cout<<"0. Salir.\n";
        cout<<"Ingrese una opcion: ";
        cin>>opt;

        // Estructura de control para ejecutar la funcion correspondiente a la opcion
        switch(opt){
            case 1:
                B1();
                break;
            case 2:
                B2();
                break;
            case 3:
                B3();
                break;
            case 4:
                B4();
                break;
            case 5:
                B5();
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
void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            // Si el elemento actual es mayor que el siguiente se intercambian
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Algoritmo de ordenamiento para organizar arreglos de mayor a menor
void descendingBubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            // Si el elemento actual es menor que el siguiente se intercambian
            if(arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Funcion B1: Ordena cinco numeros ascendentes mostrando el antes y el despues
void B1(){
    int n[5];
    cout<<"\n-- B1. Cinco numeros en orden ascendente --\n";
    
    // Captura de los datos ingresados por el usuario
    for(int i = 0; i < 5; i++){
        cout<<"Ingresa el numero "<<(i+1)<<": ";
        cin>>n[i];
    }
    
    // Mostrar estado inicial, ordenar y mostrar estado final
    cout<<"\nAntes: ";
    printArray(n, 5);
    
    bubbleSort(n, 5);
    
    cout<<"Despues: ";
    printArray(n, 5);
}

// Funcion B2: Ordena cinco numeros descendentes y muestra solo el final
void B2(){
    int n[5];
    cout<<"\n-- B2. Cinco numeros en orden descendente --\n";
    
    // Captura de datos
    for(int i = 0; i < 5; i++){
        cout<<"Ingresa el numero "<<(i+1)<<": ";
        cin>>n[i];
    }
    
    // Ordenar de mayor a menor y mostrar
    descendingBubbleSort(n, 5);
    
    cout<<"\nResultado final: ";
    printArray(n, 5);
}

// Funcion B3: Captura seis calificaciones validas, las ordena y muestra los extremos
void B3(){
    int n[6];
    cout<<"\n-- B3. Calificaciones --\n";
    
    // Ciclo para capturar las 6 calificaciones con validacion
    for(int i = 0; i < 6; i++){
        cout<<"Ingresa la calificacion "<<(i+1)<<": ";
        cin>>n[i];
        
        // Validacion para que el numero este estrictamente entre 0 y 10
        if(n[i] < 0 || n[i] > 10){
            cout<<"La calificacion debe estar entre 0 y 10. Intenta de nuevo."<<endl;
            i--; // Se resta a i para volver a pedir esta posicion
        }
    }
    
    // Ordenar arreglo de menor a mayor
    bubbleSort(n, 6);
    
    // Al estar ordenado, el indice 0 es el menor y el indice 5 es el mayor
    cout<<"\nCalificaciones ordenadas: ";
    printArray(n, 6);
    cout<<"La calificacion mas baja es: "<<n[0]<<endl;
    cout<<"La calificacion mas alta es: "<<n[5]<<endl;
}

// Funcion B4: Captura cinco edades, muestra original y ordenada
void B4(){
    int n[5];
    cout<<"\n-- B4. Edades --\n";
    
    // Captura de las edades
    for(int i = 0; i < 5; i++){
        cout<<"Ingresa una edad: ";
        cin>>n[i];
    }
    
    // Mostrar la lista antes del ordenamiento
    cout<<"\nEdades originales: ";
    printArray(n, 5);
    
    // Ordenar y mostrar la lista despues
    bubbleSort(n, 5);
    cout<<"Edades ordenadas: ";
    printArray (n, 5);
}

// Funcion B5: Captura siete temperaturas, ordena descendente e indica la mas alta
void B5(){
    int n[7];
    cout<<"\n-- B5. Temperaturas --\n";
    
    // Captura de las 7 temperaturas
    for(int i = 0; i < 7; i++){
        cout<<"Ingresa la temperatura "<<(i+1)<<": ";
        cin>>n[i];
    }
    
    // Ordenar de mayor a menor para facilitar la busqueda
    descendingBubbleSort(n, 7);
    
    cout<<"\nTemperaturas ordenadas (mayor a menor): ";
    printArray(n, 7);
    
    // Como esta ordenado descendente, la temperatura mas alta quedo en el indice 0
    cout<<"La temperatura mas alta es: "<<n[0]<<endl;
}