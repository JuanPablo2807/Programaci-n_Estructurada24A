/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 26/02/24
PROGRAMA: arreglos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Operaciones de conjuntos
**********************************************/

// Inclusión de bibliotecas
#include <iostream>   // Para entrada y salida estándar
#include <vector>     // Para utilizar vectores
#include <algorithm>  // Para realizar operaciones en rangos de elementos

using namespace std; // Espacio de nombres estándar

// Función para imprimir un conjunto de caracteres
void imprimirConjunto(const vector<char>& conjunto) {
    cout << "Conjunto: { "; // Imprime un mensaje inicial
    for (char elemento : conjunto) { // Itera sobre cada elemento del conjunto
        cout << elemento << " "; // Imprime cada elemento seguido de un espacio
    }
    cout << "}" << endl;
}

// Función para realizar la unión de dos conjuntos de caracteres
vector<char> unionConjuntos(const vector<char>& conjunto1, const vector<char>& conjunto2) {
    vector<char> union_resultado = conjunto1; // Inicializa el resultado con el primer conjunto
    for (char elemento : conjunto2) { // Itera sobre cada elemento del segundo conjunto
        // Verifica si el elemento no está presente en el resultado
        if (find(union_resultado.begin(), union_resultado.end(), elemento) == union_resultado.end()) {
            union_resultado.push_back(elemento); // Si no está presente, lo agrega al resultado
        }
    }
    return union_resultado; // Devuelve el resultado de la unión
}

// Función para realizar la intersección de dos conjuntos de caracteres
vector<char> interseccionConjuntos(const vector<char>& conjunto1, const vector<char>& conjunto2) {
    vector<char> interseccion_resultado; // Inicializa el resultado como un conjunto vacío
    for (char elemento : conjunto1) { // Itera sobre cada elemento del primer conjunto
        // Verifica si el elemento está presente en el segundo conjunto
        if (find(conjunto2.begin(), conjunto2.end(), elemento) != conjunto2.end()) {
            interseccion_resultado.push_back(elemento); // Si está presente, lo agrega al resultado
        }
    }
    return interseccion_resultado; // Devuelve el resultado de la intersección
}

// Función para realizar la diferencia entre dos conjuntos de caracteres
vector<char> diferenciaConjuntos(const vector<char>& conjunto1, const vector<char>& conjunto2) {
    vector<char> diferencia_resultado; // Inicializa el resultado como un conjunto vacío
    for (char elemento : conjunto1) { // Itera sobre cada elemento del primer conjunto
        // Verifica si el elemento no está presente en el segundo conjunto
        if (find(conjunto2.begin(), conjunto2.end(), elemento) == conjunto2.end()) {
            diferencia_resultado.push_back(elemento); // Si no está presente, lo agrega al resultado
        }
    }
    return diferencia_resultado; // Devuelve el resultado de la diferencia
}

// Función principal
int main() {
    vector<char> conjunto1, conjunto2; // Declara dos conjuntos de caracteres
    int opcion; // Variable para almacenar la opción del usuario

    do { // Bucle principal
        // Muestra un menú de opciones al usuario
        cout << "Operaciones con conjuntos:" << endl;
        cout << "1. Insertar elementos en conjunto 1" << endl;
        cout << "2. Insertar elementos en conjunto 2" << endl;
        cout << "3. Mostrar conjuntos" << endl;
        cout << "4. Realizar la union de los conjuntos" << endl;
        cout << "5. Realizar la interseccion de los conjuntos" << endl;
        cout << "6. Realizar la diferencia entre los conjuntos" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion; // Lee la opción del usuario

        // Switch para manejar la selección del usuario
        switch (opcion) {
            case 1: {
                char elemento; // Declara una variable para el elemento a insertar
                cout << "Inserte un elemento en conjunto 1: ";
                cin >> elemento; // Lee el elemento desde la entrada estándar
                conjunto1.push_back(elemento); // Agrega el elemento al conjunto 1
                break;
            }
            case 2: {
                char elemento; // Declara una variable para el elemento a insertar
                cout << "Inserte un elemento en conjunto 2: ";
                cin >> elemento; // Lee el elemento desde la entrada estándar
                conjunto2.push_back(elemento); // Agrega el elemento al conjunto 2
                break;
            }
            case 3: {
                // Muestra los conjuntos utilizando la función imprimirConjunto
                cout << "Conjunto 1:" << endl;
                imprimirConjunto(conjunto1);
                cout << "Conjunto 2:" << endl;
                imprimirConjunto(conjunto2);
                break;
            }
            case 4: {
                // Realiza la unión de los conjuntos utilizando la función unionConjuntos
                vector<char> union_resultado = unionConjuntos(conjunto1, conjunto2);
                cout << "Union de los conjuntos:" << endl;
                imprimirConjunto(union_resultado); // Imprime el resultado
                break;
            }
            case 5: {
                // Realiza la intersección de los conjuntos utilizando la función interseccionConjuntos
                vector<char> interseccion_resultado = interseccionConjuntos(conjunto1, conjunto2);
                cout << "Interseccion de los conjuntos:" << endl;
                imprimirConjunto(interseccion_resultado); // Imprime el resultado
                break;
            }
            case 6: {
                // Realiza la diferencia entre los conjuntos utilizando la función diferenciaConjuntos
                vector<char> diferencia_resultado = diferenciaConjuntos(conjunto1, conjunto2);
                cout << "Diferencia de los conjuntos (Conjunto 1 - Conjunto 2):" << endl;
                imprimirConjunto(diferencia_resultado); // Imprime el resultado
                break;
            }
            case 7:
                // Sale del programa
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                // Opción inválida
                cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 7); // Repite el bucle mientras la opción del usuario sea diferente de 7

    return 0;
}
