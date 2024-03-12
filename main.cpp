/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 11/03/24
PROGRAMA: arreglos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Operaciones de una matriz
**********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones_matrices.cpp"

using namespace std;

int main() {
    int dimension, operation;

    do {
        cout << "Ingrese la dimension de las matrices (entre 2 y 15): ";
        cin >> dimension;

        if (dimension < 2 || dimension > 15) {
            cout << "Dimension no valida. Debe estar entre 2 y 15." << endl;
            return 1;
        }

        int A[MAX_DIMENSION][MAX_DIMENSION], B[MAX_DIMENSION][MAX_DIMENSION], result[MAX_DIMENSION][MAX_DIMENSION];

        srand(time(0)); // Inicializar la semilla de los numeros aleatorios
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                A[i][j] = rand() % 601 - 200; // Numeros aleatorios entre -100 y 100
                B[i][j] = rand() % 601 - 200; // Numeros aleatorios entre -100 y 100
            }
        }

        cout << "Matriz A:" << endl;
        printMatrix(A, dimension);

        cout << "Matriz B:" << endl;
        printMatrix(B, dimension);

        cout << "Seleccione la operacion a realizar:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Editar elemento" << endl;
        cout << "5. Borrar elemento" << endl;
        cout << "6. Vaciar matriz" << endl;
        cout << "7. Salir" << endl;
        cin >> operation;

        switch (operation) {
            case 1: {
                sumaMatrices(A, B, result, dimension);
                cout << "Resultado de la suma:" << endl;
                printMatrix(result, dimension);
                break;
            }
            case 2: {
                restaMatrices(A, B, result, dimension);
                cout << "Resultado de la resta:" << endl;
                printMatrix(result, dimension);
                break;
            }
            case 3: {
                multiplicaMatrices(A, B, result, dimension);
                cout << "Resultado de la multiplicacion:" << endl;
                printMatrix(result, dimension);
                break;
            }
            case 4: {
                editarElemento(A, dimension);
                break;
            }
            case 5: {
                borrarElemento(A, dimension);
                break;
            }
            case 6: {
                vaciarMatriz(A, dimension);
                break;
            }
            case 7: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:
                cout << "Operacion no valida." << endl;
                break;
        }

    } while (operation != 7);

    return 0;
}