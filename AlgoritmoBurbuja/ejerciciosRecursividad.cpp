#include <iostream>
#include <string>

using namespace std;

int suma1aN(int n);
long long factorial(int n);
double potencia(double a, int n);
int sumaPares(int n);
int sumaImpares(int n);
void contarN_a_1(int n);
void contar1_a_N(int n);
bool esPar(int n);
int multiplicar(int a, int b);
int sumaDigitos(int n);

int contarDigitos(int n);
int invertirNumero(int n, int rev = 0);
bool esCapicua(int n);
int mcd(int a, int b);
void decToBin(int n);
void imprimirIzqDer(int n);
void imprimirDerIzq(int n);
bool esPalindromoStr(const string& s, int inicio, int fin);
int contarVocales(const string& s, int len);
void invertirCadena(const string& s, int len);

int main() {
    int opcionPrincipal = -1;
    
    while (opcionPrincipal != 0) {
        cout << "\n--- MENU PRINCIPAL ---\n\n";
        cout << " 1. Ejemplos basicos\n";
        cout << " 2. Numeros y cadenas\n\n";
        cout << " 0. Salir\n\n";
        cout << "Elija una opcion: ";
        
        if (!(cin >> opcionPrincipal)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcionPrincipal) {
            case 1: {
                int opcion = -1;
                while (opcion != 0) {
                    cout << "\n--- EJEMPLOS BASICOS ---\n\n";
                    cout << " 1. Suma 1 a n\n";
                    cout << " 2. Factorial de n\n";
                    cout << " 3. Potencia a^n\n";
                    cout << " 4. Suma n pares\n";
                    cout << " 5. Suma n impares\n";
                    cout << " 6. Contar n a 1\n";
                    cout << " 7. Contar 1 a n\n";
                    cout << " 8. Es par o impar\n";
                    cout << " 9. Multiplicar (sumas)\n";
                    cout << " 10. Suma de digitos\n\n";
                    cout << " 0. Volver al menu principal\n\n";
                    cout << "Elija una opcion: ";
                    
                    if (!(cin >> opcion)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }

                    cout << endl;

                    switch (opcion) {
                        case 1: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << suma1aN(n) << "\n";
                            break;
                        }
                        case 2: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << factorial(n) << "\n";
                            break;
                        }
                        case 3: {
                            double a;
                            int n;
                            cout << "Ingresa la base a: ";
                            cin >> a;
                            cout << "Ingresa el exponente n: ";
                            cin >> n;
                            cout << "Resultado: " << potencia(a, n) << "\n";
                            break;
                        }
                        case 4: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << sumaPares(n) << "\n";
                            break;
                        }
                        case 5: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << sumaImpares(n) << "\n";
                            break;
                        }
                        case 6: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            contarN_a_1(n);
                            cout << "\n";
                            break;
                        }
                        case 7: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            contar1_a_N(n);
                            cout << "\n";
                            break;
                        }
                        case 8: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            if (esPar(n)) {
                                cout << "Es Par\n";
                            } else {
                                cout << "Es Impar\n";
                            }
                            break;
                        }
                        case 9: {
                            int a, b;
                            cout << "Ingresa a: ";
                            cin >> a;
                            cout << "Ingresa b: ";
                            cin >> b;
                            cout << "Resultado: " << multiplicar(a, b) << "\n";
                            break;
                        }
                        case 10: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << sumaDigitos(n) << "\n";
                            break;
                        }
                        case 0:
                            cout << "Regresando al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion no valida. Intenta de nuevo.\n";
                            break;
                    }
                }
                break;
            }
            case 2: {
                int opcion = -1;
                while (opcion != 0) {
                    cout << "\n--- NUMEROS Y CADENAS ---\n\n";
                    cout << " 1. Contar digitos\n";
                    cout << " 2. Invertir numero\n";
                    cout << " 3. Es capicua\n";
                    cout << " 4. MCD (Euclides)\n";
                    cout << " 5. Decimal a binario\n";
                    cout << " 6. Digitos izq-der\n";
                    cout << " 7. Digitos der-izq\n";
                    cout << " 8. Es palindromo (cadena)\n";
                    cout << " 9. Contar vocales\n";
                    cout << " 10. Invertir cadena\n\n";
                    cout << " 0. Volver al menu principal\n\n";
                    cout << "Elija una opcion: ";
                    
                    if (!(cin >> opcion)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }

                    cout << endl;

                    switch (opcion) {
                        case 1: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << contarDigitos(n) << "\n";
                            break;
                        }
                        case 2: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            cout << "Resultado: " << invertirNumero(n) << "\n";
                            break;
                        }
                        case 3: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            if (esCapicua(n)) {
                                cout << "Es capicua\n";
                            } else {
                                cout << "No es capicua\n";
                            }
                            break;
                        }
                        case 4: {
                            int a, b;
                            cout << "Ingresa a: ";
                            cin >> a;
                            cout << "Ingresa b: ";
                            cin >> b;
                            cout << "MCD: " << mcd(a, b) << "\n";
                            break;
                        }
                        case 5: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            if (n == 0) {
                                cout << 0;
                            } else {
                                decToBin(n);
                            }
                            cout << "\n";
                            break;
                        }
                        case 6: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            imprimirIzqDer(n);
                            cout << "\n";
                            break;
                        }
                        case 7: {
                            int n;
                            cout << "Ingresa n: ";
                            cin >> n;
                            imprimirDerIzq(n);
                            cout << "\n";
                            break;
                        }
                        case 8: {
                            string str;
                            cout << "Ingresa la cadena: ";
                            cin >> ws;
                            getline(cin, str);
                            if (esPalindromoStr(str, 0, str.length() - 1)) {
                                cout << "Es palindromo\n";
                            } else {
                                cout << "No es palindromo\n";
                            }
                            break;
                        }
                        case 9: {
                            string str;
                            cout << "Ingresa la cadena: ";
                            cin >> ws;
                            getline(cin, str);
                            cout << "Vocales: " << contarVocales(str, str.length()) << "\n";
                            break;
                        }
                        case 10: {
                            string str;
                            cout << "Ingresa la cadena: ";
                            cin >> ws;
                            getline(cin, str);
                            invertirCadena(str, str.length());
                            cout << "\n";
                            break;
                        }
                       
                        default:
                            cout << "Opcion no valida. Intenta de nuevo\n";
                            break;
                    }
                }
                break;
            }
            case 0:
                cout << "\nSaliendo del programa\n";
                break;
            default:
                cout << "\nOpcion no valida. Intenta de nuevo\n";
                break;
        }
    }
    
    return 0;
}

int suma1aN(int n) {
    if (n <= 0) return 0;
    return n + suma1aN(n - 1);
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

double potencia(double a, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1.0 / potencia(a, -n);
    return a * potencia(a, n - 1);
}

int sumaPares(int n) {
    if (n <= 0) return 0;
    return (2 * n) + sumaPares(n - 1);
}

int sumaImpares(int n) {
    if (n <= 0) return 0;
    return (2 * n - 1) + sumaImpares(n - 1);
}

void contarN_a_1(int n) {
    if (n > 0) {
        cout << n << " ";
        contarN_a_1(n - 1);
    }
}

void contar1_a_N(int n) {
    if (n > 0) {
        contar1_a_N(n - 1);
        cout << n << " ";
    }
}

bool esPar(int n) {
    if (n < 0) n = -n;
    if (n == 0) return true;
    if (n == 1) return false;
    return esPar(n - 2);
}

int multiplicar(int a, int b) {
    if (b == 0) return 0;
    if (b < 0) return -multiplicar(a, -b);
    return a + multiplicar(a, b - 1);
}

int sumaDigitos(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    return (n % 10) + sumaDigitos(n / 10);
}

int contarDigitos(int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    return 1 + contarDigitos(n / 10);
}

int invertirNumero(int n, int rev) {
    if (n == 0) return rev;
    return invertirNumero(n / 10, rev * 10 + (n % 10));
}

bool esCapicua(int n) {
    return n == invertirNumero(n);
}

int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}

void decToBin(int n) {
    if (n > 1) decToBin(n / 2);
    cout << n % 2;
}

void imprimirIzqDer(int n) {
    if (n < 0) { cout << "- "; n = -n; }
    if (n < 10) { cout << n << " "; } 
    else {
        imprimirIzqDer(n / 10);
        cout << n % 10 << " ";
    }
}

void imprimirDerIzq(int n) {
    if (n < 0) { cout << "- "; n = -n; }
    if (n < 10) { cout << n << " "; } 
    else {
        cout << n % 10 << " ";
        imprimirDerIzq(n / 10);
    }
}

bool esPalindromoStr(const string& s, int inicio, int fin) {
    if (inicio >= fin) return true;
    if (tolower(s[inicio]) != tolower(s[fin])) return false;
    return esPalindromoStr(s, inicio + 1, fin - 1);
}

int contarVocales(const string& s, int len) {
    if (len == 0) return 0;
    char c = tolower(s[len - 1]);
    int esVocal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
    return esVocal + contarVocales(s, len - 1);
}

void invertirCadena(const string& s, int len) {
    if (len == 0) return;
    cout << s[len - 1];
    invertirCadena(s, len - 1);
}