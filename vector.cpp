/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 20/02/24
PROGRAMA: arreglos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Utilizacion de arreglos
**********************************************/


#include <iostream> //Incluir la libreria de entrada y salida
#include <vector> //Incluir la libreria para vectores

using namespace std;

//Iniciar el codigo con main
int main() {
//Variables
vector<int> arreglo; //Variable para declarar un vector
char opcion;
int valor, indice, nuevoValor;
int suma = 0;
bool ciclo = true;

    //Crear las opciones que se mostraran al usuario con un while
    while (ciclo) {
        cout << "\nElije una opcion" << endl;
        cout << "1. Ingresar valores" << endl;
        cout << "2. Sumar valores" << endl;
        cout << "3. Mostrar la lista" << endl;
        cout << "4. Editar elementos" << endl;
        cout << "5. Borrar elementos" << endl;
        cout << "6. Vaciar arreglo" << endl;
        cout << "7. Salir del programa" << endl;
        cin >> opcion;

        //Crear el menu(switch) para las opciones(casos)
        switch (opcion) {
            case '1': {//Caso 1 para introducir un valor
                cout << "Introduce un valor: ";
                cin >> valor;
                arreglo.push_back(valor);
                cout << "Valor agregado correctamente." << endl;
                break;
            }//Fin de case 1
            case '2': {//Caso 2 que sirve para sumar los vectores y mostrar la suma
                for (int i = 0; i < arreglo.size(); i++) {
                    suma = suma + arreglo[i];
                }//Fin de for
                cout << "El total del arreglo es de: " << suma << endl;
                break;
            }//Fin de caso 2
            case '3': {//Caso 3 que sirve para mostrar nuestro arreglo
                cout << "Su arreglo es: " << endl;
                for (int i = 0; i < arreglo.size(); i++) {
                    cout << "[" << arreglo[i] << "], ";
                }
                break;
            }//Fin de caso 3
            case '4': {//Caso 4 que sirve para editar el valor de alguna posicion
                cout << "Su arreglo es: " << endl;
                for (int i = 0; i < arreglo.size(); i++) {//Inicio de for
                    cout << "[" << arreglo[i] << "], ";
                }//Fin de for
                cout << "\nIngrese la posicion de el valor que desea editar: " << endl;
                cin >> indice;
                cout << "Ingrese el nuevo valor" << endl;
                cin >> nuevoValor;
                    arreglo[indice] = nuevoValor;
                    cout << "Elemento editado correctamente." << endl;
                break;
            }//Fin de caso 4
            case '5': {//Caso 5 que sirve para borrar algun elemento del vector
                cout << "Su arreglo es: " << endl;
                for (int i = 0; i < arreglo.size(); i++) {
                    cout << "[" << arreglo[i] << "], ";
                }
                cout << "Ingrese la posicion del elemento que deseas borrar: " << endl;
                cin >> indice;
                arreglo.erase(arreglo.begin() + indice);
                cout << "Elemento borrado correctamente." << endl;

                break;
            }//Fin de caso 5
            case '6': {//Caso 6 que sirve para vaciar un arreglo
                cout << "Su arreglo es: " << endl;
                for (int i = 1; i <= arreglo.size(); i++) {
                    cout << "\t[" << i << "], ";
                }
                cout << endl;
                arreglo.clear();
                cout << "Arreglo vaciado correctamente." << endl;
                break;
            }//Fin de caso 6
            case '7': {//Caso 7 que sirve para salir el programa
                ciclo = false;
                break;
            }//Fin de caso 7
            default: {
                cout << "Opcion invalida" << endl;
                break;
            }//Fin de default
        }//Fin de switch
    }//Fin de while
}//Fin de main