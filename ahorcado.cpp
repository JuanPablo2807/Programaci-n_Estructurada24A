/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 22/04/24
PROGRAMA: ahorcado.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Juego del ahorcado
**********************************************/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Función para seleccionar una palabra aleatoria del banco de palabras
string seleccionarPalabra(const vector<string>& banco) {
    // Genera un índice aleatorio dentro del rango del tamaño del banco de palabras
    int indiceAleatorio = rand() % banco.size();
    // Devuelve la palabra correspondiente al índice aleatorio
    return banco[indiceAleatorio];
}

// Función para jugar al juego del ahorcado
void jugarAhorcado(const string& palabra) {
    int intentos = 6; // Inicializa el número de intentos
    string palabraOculta(palabra.length(), '_'); // Crea una cadena de guiones del mismo tamaño que la palabra a adivinar
    string letrasUsadas = ""; // Inicializa una cadena vacía para almacenar las letras usadas

    cout << "La palabra tiene " << palabra.length() << " letras." << endl; // Imprime la longitud de la palabra

    // Ciclo principal del juego, se ejecuta mientras haya intentos restantes y la palabra no haya sido adivinada
    while (intentos > 0 && palabraOculta != palabra) {
        // Muestra la palabra oculta, los intentos restantes y las letras usadas
        cout << "Palabra: " << palabraOculta << endl;
        cout << "Intentos restantes: " << intentos << endl;
        cout << "Letras usadas: " << letrasUsadas << endl;

        char entrada;
        cout << "Ingresa una letra o la palabra completa si ya la sabes: ";
        cin >> entrada;

        if (isalpha(entrada)) { // Verifica si la entrada es una letra
            char letra = tolower(entrada); // Convierte la letra ingresada a minúscula

            if (letrasUsadas.find(letra) != string::npos) { // Verifica si la letra ya ha sido usada
                cout << "Ya has usado esa letra. ¡Intenta con otra!" << endl;
                continue; // Vuelve al inicio del ciclo
            }

            letrasUsadas += letra; // Agrega la letra a las letras usadas

            bool letraEncontrada = false; // Bandera para indicar si la letra ha sido encontrada en la palabra
            for (int i = 0; i < palabra.length(); ++i) {
                if (tolower(palabra[i]) == letra) { // Compara la letra ingresada con las letras de la palabra (ignora mayúsculas/minúsculas)
                    palabraOculta[i] = palabra[i]; // Actualiza la palabra oculta con la letra encontrada
                    letraEncontrada = true;
                }
            }

            if (!letraEncontrada) { // Si la letra no ha sido encontrada en la palabra
                cout << "¡Letra incorrecta! Pierdes un intento." << endl;
                --intentos; // Reduce el número de intentos
            }
        } else { // Si la entrada es una palabra completa
            string palabraIntentada;
            cout << "Ingresa la palabra completa: ";
            cin >> palabraIntentada;

            if (palabraIntentada == palabra) { // Verifica si la palabra ingresada es correcta
                cout << "¡Felicidades! Has adivinado la palabra correctamente: " << palabra << endl;
                return; // Termina la función
            } else { // Si la palabra ingresada es incorrecta
                cout << "¡Palabra incorrecta! Pierdes un intento." << endl;
                --intentos; // Reduce el número de intentos
            }
        }
    }

    if (palabraOculta == palabra) { // Si la palabra ha sido adivinada correctamente
        cout << "¡Felicidades! Has adivinado la palabra correctamente: " << palabra << endl;
    } else { // Si se han agotado los intentos
        cout << "¡Oh no! Te has quedado sin intentos. La palabra era: " << palabra << endl;
    }
}

// Función para mostrar las instrucciones del juego
void mostrarInstrucciones() {
    cout << "Instrucciones del juego:" << endl;
    cout << "1. Selecciona una letra o ingresa la palabra completa si ya la sabes." << endl;
    cout << "2. Tienes 6 intentos para adivinar la palabra." << endl;
    cout << "3. Si ingresas una vocal, pierdes un intento." << endl;
    cout << "Buena suerte!" << endl; // Mensaje de buena suerte
}

int main() {
    srand(time(nullptr)); // Inicializa la semilla para la generación de números aleatorios

    // Banco de palabras sin acentos
    vector<string> bancoDePalabras = {"manzana", "naranja", "banana", "pera", "uva", "sandia", "kiwi", "pina", "cereza", "melon", "limon", "fresa", "durazno", "mango", "papaya", "guayaba", "coco", "toronja", "frambuesa", "arandano"};

    int opcion;
    do {
        // Menú principal
        cout << "¡Bienvenido al juego del ahorcado!" << endl;
        cout << "Menu:" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Instrucciones" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { // Opción para jugar
                string palabraSeleccionada = seleccionarPalabra(bancoDePalabras);
                jugarAhorcado(palabraSeleccionada);
                break;
            }
            case 2: { // Opción para mostrar instrucciones
                mostrarInstrucciones();
                break;
            }
            case 3: // Opción para salir del juego
                cout << "¡Hasta luego!" << endl;
                break;
            default: // Opción por defecto para manejar entradas inválidas
                cout << "Opcion no valida. Por favor, selecciona una opcion valida." << endl;
                break;
        }
    } while (opcion != 3); // Repetir el ciclo hasta que el jugador elija salir

    return 0;
}
