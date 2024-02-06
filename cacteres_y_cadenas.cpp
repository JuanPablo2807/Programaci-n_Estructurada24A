/***********PRESENTACIon**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 02/02/24
PROGRAMA: caracteres_y_cadenas.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Utilizacion de caracteres
**********************************************/

//Incluir la libreria "iostream"
#include <iostream>
using namespace std;

//Iniciar main
int main() {
//Definir variables
int edad=18;
string nombre = "Juan Pablo Gonzalez Jimenez";
string residencia = "Cañadas de Obregón";
string fecha = "02/02/24";
string carrera = "Ingeniería en Computación";
string semestre = "2do semestre";

/*Imprimi los datos utilizando las secuencias de escape de
tabulador, comillas dobles y salto de linea para una mejor */
    cout << "\t\"Nombre:\"\n" << nombre << endl;
    cout << "\t\"Edad:\"\n" << edad << endl;
    cout << "\t\"Lugar de residencia:\"\n" <<residencia << endl;
    cout << "\t\"Fecha:\"\n" << fecha << endl;
    cout << "\t\"Carrera:\"\n" << carrera << endl;
    cout << "\t\"Semestre:\"\n" << semestre << endl;

    return 0;
} //Finalizar main
