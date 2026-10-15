#include <iostream>

using namespace std;

int busquedaLineal(int arr[], int target) {
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] == target) {
            return i; // Retorna el índice si se encuentra el elemento
        }
    }
    return -1; // Retorna -1 si no se encuentra el elemento
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    int result = busquedaLineal(arr, target);
    if (result != -1) {
        cout << "Elemento encontrado en el índice: " << result << endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }
    return 0;
}