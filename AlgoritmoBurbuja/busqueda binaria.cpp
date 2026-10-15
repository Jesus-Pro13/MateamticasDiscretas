#include <iostream>

using namespace std;
int busquedaBinaria(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Retorna el índice si se encuentra el elemento
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Buscar en la mitad derecha
        }
        else {
            right = mid - 1; // Buscar en la mitad izquierda
        }
    }
    return -1; // Retorna -1 si no se encuentra el elemento
}
int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = busquedaBinaria(arr, size, target);
    if (result != -1) {
        cout << "Elemento encontrado en el índice: " << result << endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }
    return 0;
}