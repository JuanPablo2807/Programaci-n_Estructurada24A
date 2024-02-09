/***********PRESENTACIon**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 09/02/24
PROGRAMA: caracteres_y_cadenas.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Menu con la secuencia finonacci
**********************************************/
#include <iostream>

using namespace std;
int terminos;

void opcion1() {
    int num1 = 0;
    int num2 = 1;
        cout << "Has seleccionado el ciclo for" << endl;

        cout << "Ingresa el número hasta el que deseas llegar: " << endl;
        cin >> terminos;


        cout << "Secuencia de Fibonacci con " << terminos << " términos:" << endl;

        cout << num1 << " ";

        for (int i = 0; num2 <= terminos; i++) {
            int suma = num1 + num2;
            cout << num2 << " ";

            num1 = num2;
            num2 = suma;
        }
    }

void opcion2() {
    int num1 = 0;
    int num2 = 1;
    cout << "Has seleccionado el ciclo while" << endl;

    cout << "Ingresa el número hasta el que deseas llegar: " << endl;
    cin >> terminos;

    cout << "Secuencia de Fibonacci hasta el " << terminos << ":" << endl;
    cout << num1 << " ";

    while(num2 <= terminos) {
        cout << num2 << " ";

        int suma = num1 + num2;
        num1 = num2;
        num2 = suma;
    }
}

void opcion3() {
    int num1 = 0;
    int num2 = 1;
    cout << "Has seleccionado el ciclo do-while" << endl;

    cout << "Ingresa el número hasta el que deseas llegar: " << endl;
    cin >> terminos;

    cout << "Secuencia de Fibonacci hasta el " << terminos << ":" << endl;
    cout << num1 << " ";

    do {
        cout << num2 << " ";

        int suma = num1 + num2;
        num1 = num2;
        num2 = suma;
    } while(num2 <= terminos);
}

int main() {
    int opcion;

    do {
        int terminos;
        int num1 = 0;
        int num2 = 1;
        // Mostrar el menú
        cout << "\nElige la opcion que deseas utilizar" << endl;
        cout << "1. Ciclo for" << endl;
        cout << "2. Ciclo while" << endl;
        cout << "3. Ciclo do-while" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        // Según la opción seleccionada por el usuario, llamar a la función correspondiente
        switch (opcion) {
            case 1:
                opcion1();
                break;
            case 2:
                opcion2();
                break;
            case 3:
                opcion3();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, selecciona una opción válida." << endl;
                break;
        }
    } while (opcion != 4); // Continuar mostrando el menú hasta que el usuario seleccione la opción de salir

    return 0;
}
