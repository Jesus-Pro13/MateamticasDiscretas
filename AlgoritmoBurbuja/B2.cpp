//B2. Cinco números en orden descendente. Capturen cinco números enteros y ordénenlos de
//mayor a menor. Muestren el resultado final.

#include <iostream> 
using namespace std;

int main(){
    int n[5];
    int temp;

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
            if(n[i] < n[j]) { 
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