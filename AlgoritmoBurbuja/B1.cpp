// B1. Cinco números en orden ascendente. Capturen cinco números enteros, ordénenlos de menor
//a mayor y muestren la lista antes y después del ordenamiento.
#include <iostream> 
using namespace std;

int main(){
    int n[5];
    

    for(int i=0; i<5; i++){
      cout<<"Ingresa un numero: ";
      cin>>n[i];  
    }
    
    cout << "\nAntes: ";
    for(int i=0; i<5; i++){
        cout<<n[i]<<" "; 
    }
    cout << endl;
    
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(n[i] > n[j]) { 
                swap(n[i], n[j]);
            }
        }
    }
    
    cout << "Despues: ";
    for(int i=0; i<5; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
    
    return 0; 
}