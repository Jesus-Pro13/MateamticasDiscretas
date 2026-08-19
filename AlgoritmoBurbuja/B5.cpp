//B5. Temperaturas. Capturen siete temperaturas y ordénenlas de mayor a menor. Indiquen cuál es
//la temperatura más alta.
#include <iostream> 
using namespace std;

int main(){
    int n[7];
    

    for(int i=0; i<7; i++){
      cout<<"Ingresa una temperatura: ";
      cin>>n[i];  
    }
    
    
    for(int i=0; i<7; i++){
        for(int j=i+1; j<7; j++){
            if(n[i] > n[j]) { 
                swap(n[i], n[j]);
            }
        }
    }
    
    cout << "Despues: ";
    for(int i=0; i<7; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
    
    cout << "La temperatura mas alta es: " << n[6] << endl;
    
    return 0; 
}