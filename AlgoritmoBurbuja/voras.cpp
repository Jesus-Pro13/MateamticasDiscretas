#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void calcularCambioVoraz(vector<int>& denominaciones, int cantidad, bool Billetes) {

    sort(denominaciones.rbegin(), denominaciones.rend());

    cout << "\n--- Desglose del Cambio ---\n";

    for (int d : denominaciones) {
        if (cantidad >= d) {
            int cantidad_unidades = cantidad / d;
            cantidad = cantidad % d;              

            double valor_real = d / 100.0;
            string tipo = "Monedas";
            
            
            if (Billetes && d >= 2000) { 
                tipo = "Billetes";
            }

            cout << cantidad_unidades << " " << tipo << " de $" << valor_real << endl;
        }
    }

    if (cantidad > 0) {
        cout << "\n Quedo un sobrante de $" << cantidad / 100.0 
             << " que no se pudo dar con las denominaciones proporcionadas" << endl;
    }
}

int main() {
    int opcion;
    cout << "Seleccione el formato de denominaciones a utilizar:\n";
    cout << "1. Solo monedas\n";
    cout << "2. Billetes y monedas\n";
    cout << "Opcion: ";
    cin >> opcion;

    bool Billetes = (opcion == 2);

    int numDenominaciones;
    cout << "\nCuantas denominaciones diferentes va a ingresar: ";
    cin >> numDenominaciones;

    vector<int> denominaciones;
    for (int i = 0; i < numDenominaciones; i++) {
        double valor;
        cout << "Ingrese el valor de la denominacion " << i + 1 << ": $";
        cin >> valor;
      
        denominaciones.push_back(round(valor * 100)); 
    }

    double cantidadTotal;
    cout << "\nIngrese la cantidad total a devolver: $";
    cin >> cantidadTotal;

    int cantidadCentavos = round(cantidadTotal * 100);


    calcularCambioVoraz(denominaciones, cantidadCentavos, Billetes);

    return 0;
}