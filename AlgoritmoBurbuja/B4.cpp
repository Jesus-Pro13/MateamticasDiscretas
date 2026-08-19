//B4. Edades. Capturen las edades de cinco personas y ordénenlas de menor a mayor. Muestren la
//lista original y la lista ordenada.
#include <iostream> 
using namespace std;

int main(){
    int n[5];
    

    for(int i=0; i<5; i++){
      cout<<"Ingresa una edad: ";
      cin>>n[i];  
    }
    
    cout << "\nEdades antes: ";
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
    
    cout << "Edades despues: ";
    for(int i=0; i<5; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
    
    return 0; 
}