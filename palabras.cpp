#include <iostream> // Incluimos la biblioteca para entrada y salida estándar
#include <cctype>   // Incluimos la biblioteca para funciones de caracteres

using namespace std;

// Función para contar vocales, consonantes y espacios
void contarCaracteres(const char* palabra, int& vocales, int& consonantes, int& espacios) {
    while (*palabra) {
        char c = tolower(*palabra); // Convertimos el caracter a minúscula
        if (isalpha(c)) { // Si es una letra
            // Verificamos si es una vocal
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        } else if (isspace(c)) { // Si es un espacio en blanco
            espacios++;
        }
        palabra++; // Avanzamos al siguiente caracter
    }
}

// Función para verificar si una palabra es palíndromo
bool esPalindromo(const char* palabra) {
    int inicio = 0;
    int fin = 0;
    // Mover fin al final de la palabra
    while (palabra[fin] != '\0') {
        fin++;
    }
    fin--;

    while (inicio < fin) { // Verificamos si los caracteres simétricos son iguales
        if (tolower(palabra[inicio]) != tolower(palabra[fin])) { // Convertimos ambos caracteres a minúsculas para la comparación
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

int main() {
    const int TAMANIO_MAX = 100; // Tamaño máximo de la entrada
    char entrada[TAMANIO_MAX]; // Declaramos un arreglo para almacenar la entrada del usuario

    cout << "Ingrese una palabra o frase: "; // Solicitamos la entrada al usuario
    cin.getline(entrada, TAMANIO_MAX); // Leemos la entrada

    int numVocales = 0, numConsonantes = 0, numEspacios = 0;
    contarCaracteres(entrada, numVocales, numConsonantes, numEspacios); // Contamos vocales, consonantes y espacios en la entrada

    cout << "Numero de vocales: " << numVocales << endl; // Mostramos el número de vocales
    cout << "Numero de consonantes: " << numConsonantes << endl; // Mostramos el número de consonantes
    cout << "Numero de espacios: " << numEspacios << endl; // Mostramos el número de espacios

    if (esPalindromo(entrada)) { // Verificamos si la entrada es un palíndromo
        cout << "La palabra/frase es un palindromo." << endl; // Mostramos el mensaje correspondiente
    } else {
        cout << "La palabra/frase no es un palindromo." << endl; // Mostramos el mensaje correspondiente
    }

    // Convertir a mayúsculas y minúsculas
    cout << "En mayusculas: ";
    for (int i = 0; entrada[i] != '\0'; i++) { // Iteramos sobre cada caracter de la entrada
        cout << (char)toupper(entrada[i]); // Convertimos el caracter a mayúscula y lo mostramos
    }
    cout << endl;

    cout << "En minusculas: ";
    for (int i = 0; entrada[i] != '\0'; i++) { // Iteramos sobre cada caracter de la entrada
        cout << (char)tolower(entrada[i]); // Convertimos el caracter a minúscula y lo mostramos
    }
    cout << endl;

    // Concatenar con otra palabra o frase
    char segundaEntrada[TAMANIO_MAX]; // Declaramos un arreglo para almacenar la segunda entrada
    cout << "Ingrese otra palabra o frase para concatenar: "; // Solicitamos la segunda entrada al usuario
    cin.getline(segundaEntrada, TAMANIO_MAX); // Leemos la segunda entrada

    int i = 0;
    while (entrada[i] != '\0') { // Buscamos el final de la primera entrada
        i++;
    }
    int j = 0;
    while (segundaEntrada[j] != '\0') { // Concatenamos la segunda entrada al final de la primera
        entrada[i++] = segundaEntrada[j++];
    }
    entrada[i] = '\0'; // Agregamos el carácter nulo al final

    cout << "Palabra o frase concatenada: " << entrada << endl; // Mostramos la palabra o frase concatenada

    return 0;
}
