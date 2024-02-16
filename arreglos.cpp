/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 16/02/24
PROGRAMA: arreglos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Utilizacion de arreglos
**********************************************/

//Incluir la libreria "iostream"
#include <iostream>

using namespace std;

//Iniciar el codigo con main
int main() {
//Variables
int arreglo[10];
char opcion;
int valor, indice, nuevoValor;
int suma = 0;
int posicion = 0;
bool ciclo= true;

    //Crear las opciones que se mostraran al usuario con un while
    while(ciclo){
        cout << "Elije una opcion" << endl;
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
            case '1':{
                //Definimos la condicion para que no se puedan poner mas de 10 datos
                if(posicion == 10){
                    cout << "Arreglo lleno" << endl;
                }/*Fin del if*/ else {
                    cout << "Introduce un valor: ";
                    cin >> valor;
                    arreglo[posicion] = valor;
                    posicion++;
                }
                break;
            }//Fin de case 1
            case '2':{
                for(int i = 0; i < posicion; i++) {
                    suma = suma + arreglo[i];
                }//Fin de for
                cout << "El total del arreglo es de: " << suma << endl;
                break;
            }//Fin de caso 2
            case '3':{
                for(int i = 0; i < posicion; i++) {
                    cout << "[" << arreglo[i] << "], ";
                }
                break;
            }//Fin de caso 3
            case '4':{
                cout << "Ingrese la posicion de el valor que desea editar: " << endl;
                cin >> indice;
                cout << "Ingrese el nuevo valor" << endl;
                cin >> nuevoValor;
                if (indice >= 0 && indice < posicion){
                    arreglo[indice] = nuevoValor;
                    cout << "Elemento editado correctamente." << endl;
                }/*Fin del if*/ else {
                    cout << "Posicion fuera de rango." << endl;
                }
                break;
            }//Fin de caso 4
            case '5':{
                cout << "Ingrese la posicion del elemento que deseas borrar: " << endl;
                cin >> indice;

                if(indice >= 0 && indice < posicion){
                    for(int i = indice; i < posicion - 1; ++i){
                        arreglo[i] = arreglo[i+1];
                    }//Fin del for
                    posicion--;
                    cout << "Elemento borrado correctamente." << endl;
                }/*Fin del if*/ else {
                    cout << "Posicion fuera de rango." << endl;
                }//Fin del else
                break;
            }//Fin de caso 5
            case '6':{
                posicion = 0;
                cout << "Arreglo vaciado correctamente." << endl;
                break;
            }//Fin de caso 6
            case '7':{
                ciclo = false;
                break;
            }//Fin de caso 7
        }//Fin de switch
    }
}