//B3. Calificaciones. Capturen seis calificaciones enteras del 0 al 10 y ordénenlas de menor a mayor.
//Muestren también la calificación más baja y la más alta.

#include <iostream> 
using namespace std;

int main(){
    int n[5];

    for(int i=0; i<5; i++){
      cout<<"Ingresa una calificacion: ";
      cin>>n[i];
      if(n[i]<0 || n[i]>10){
        cout<<"La calificacion debe estar entre 0 y 10. Intenta de nuevo."<<endl;
        i--;
      }  
    }
    
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(n[i] > n[j]) { 
                swap(n[i], n[j]);
            }
        }
    }
    
    cout << "Calificaciones despues: ";
    for(int i=0; i<5; i++){
        cout<<n[i]<<" ";
    }
    cout << endl;
    
    cout << "Calificacion mas baja: " << n[0] << endl;
    cout << "Calificacion mas alta: " << n[4] << endl;
    
    return 0; 
}