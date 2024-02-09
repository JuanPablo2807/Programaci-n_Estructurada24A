/***********PRESENTACIon**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 06/02/24
PROGRAMA: caracteres_y_cadenas.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Imprimir una secuencia de numeros bajo ciertas condiciones
**********************************************/

//Icluir la libreria "iostream" de c++
#include <iostream>
using namespace std;

//Iniciar con la funcion main
int main() {
    //Variabels
    bool ciclo = true;
    int numuser, veces, suma;
    char op;

    //Iniciar ciclo
    while(ciclo){
        cout << "Escribe un numero: ";
        cin >> numuser;
        //Validar numero
        if(numuser < 0 || numuser > 1000){
            cout << "No puedo calcular el valor" << endl;
        }
        else if (numuser > 0 && numuser <= 500){
            veces=100;
            suma=5;
        } else{
            veces = 50;
            suma = 10;
        }
    //Inicio del for
    for(int i = 1; i<= veces; i++){
        numuser = numuser + suma;
       cout << "La vez :" << i << "es de: " << numuser << endl;
    }
    //Mostrar el texto de salida
    cout << "Termine el ciclo, ingrese \"S\" para salir o cualquier otra cosa para continuar" << endl;
    cin >> op;
    //Condicion para terminar el programa
    if (op == 'S' || op == 's'){
        ciclo = false;
    }
    }//Finciclo while
    return 0;
}//Fin de main
