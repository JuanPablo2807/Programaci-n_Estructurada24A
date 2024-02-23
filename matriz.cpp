/***********PRESENTACION**************
NOMBRE: Juan Pablo Gonzalez Jimenez
FECHA: 23/02/24
PROGRAMA: arreglos.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Operaciones de una matriz
**********************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_DIMENSION = 10;

// Función para imprimir una matriz
void printMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int dimension, operation;

    do {
        cout << "Ingrese la dimension de las matrices (entre 2 y 10): ";
        cin >> dimension;

        if (dimension < 2 || dimension > 10) {
            cout << "Dimension no valida. Debe estar entre 2 y 10." << endl;
            return 1;
        }

        int A[MAX_DIMENSION][MAX_DIMENSION], B[MAX_DIMENSION][MAX_DIMENSION], result[MAX_DIMENSION][MAX_DIMENSION];

        srand(time(0)); // Inicializar la semilla de los numeros aleatorios
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                A[i][j] = rand() % 201 - 100; // Numeros aleatorios entre -100 y 100
                B[i][j] = rand() % 201 - 100; // Numeros aleatorios entre -100 y 100
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
                cout << "Resultado de la suma:" << endl;
                for (int i = 0; i < dimension; ++i) {
                    for (int j = 0; j < dimension; ++j) {
                        result[i][j] = A[i][j] + B[i][j];
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }
            case 2: {
                cout << "Resultado de la resta:" << endl;
                for (int i = 0; i < dimension; ++i) {
                    for (int j = 0; j < dimension; ++j) {
                        result[i][j] = A[i][j] - B[i][j];
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                cout << "Resultado de la multiplicacion:" << endl;
                for (int i = 0; i < dimension; ++i) {
                    for (int j = 0; j < dimension; ++j) {
                        result[i][j] = 0;
                        for (int k = 0; k < dimension; ++k) {
                            result[i][j] += A[i][k] * B[k][j];
                        }
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }
            case 4: {
                int row, col, newValue;
                cout << "Ingrese la fila del elemento a editar (entre 0 y " << dimension - 1 << "): ";
                cin >> row;
                cout << "Ingrese la columna del elemento a editar (entre 0 y " << dimension - 1 << "): ";
                cin >> col;
                cout << "Ingrese el nuevo valor: ";
                cin >> newValue;

                if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
                    A[row][col] = newValue;
                    cout << "Elemento editado exitosamente." << endl;
                    cout << "Matriz A actualizada:" << endl;
                    printMatrix(A, dimension);
                } else {
                    cout << "Posicion invalida." << endl;
                }
                break;
            }
            case 5: {
                int row, col;
                cout << "Ingrese la fila del elemento a borrar (entre 0 y " << dimension - 1 << "): ";
                cin >> row;
                cout << "Ingrese la columna del elemento a borrar (entre 0 y " << dimension - 1 << "): ";
                cin >> col;

                if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
                    A[row][col] = 0; // Se borra el elemento asignándole el valor 0
                    cout << "Elemento borrado exitosamente." << endl;
                    cout << "Matriz A actualizada:" << endl;
                    printMatrix(A, dimension);
                } else {
                    cout << "Posicion invalida." << endl;
                }
                break;
            }
            case 6: {
                for (int i = 0; i < dimension; ++i) {
                    for (int j = 0; j < dimension; ++j) {
                        A[i][j] = 0; // Asignar 0 a todos los elementos
                    }
                }
                cout << "Matriz vaciada exitosamente." << endl;
                cout << "Matriz A actualizada:" << endl;
                printMatrix(A, dimension);
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
