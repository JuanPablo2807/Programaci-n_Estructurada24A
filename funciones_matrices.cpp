#include <iostream>

const int MAX_DIMENSION = 15;

// Función para imprimir una matriz
void printMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Función para sumar dos matrices
void sumaMatrices(int A[MAX_DIMENSION][MAX_DIMENSION], int B[MAX_DIMENSION][MAX_DIMENSION], int result[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Función para restar dos matrices
void restaMatrices(int A[MAX_DIMENSION][MAX_DIMENSION], int B[MAX_DIMENSION][MAX_DIMENSION], int result[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplicaMatrices(int A[MAX_DIMENSION][MAX_DIMENSION], int B[MAX_DIMENSION][MAX_DIMENSION], int result[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < dimension; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para editar un elemento de una matriz
void editarElemento(int A[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    int row, col, newValue;
    std::cout << "Ingrese la fila del elemento a editar (entre 0 y " << dimension - 1 << "): ";
    std::cin >> row;
    std::cout << "Ingrese la columna del elemento a editar (entre 0 y " << dimension - 1 << "): ";
    std::cin >> col;
    std::cout << "Ingrese el nuevo valor: ";
    std::cin >> newValue;

    if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
        A[row][col] = newValue;
        std::cout << "Elemento editado exitosamente." << std::endl;
        std::cout << "Matriz A actualizada:" << std::endl;
        printMatrix(A, dimension);
    } else {
        std::cout << "Posicion invalida." << std::endl;
    }
}

// Función para borrar un elemento de una matriz
void borrarElemento(int A[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    int row, col;
    std::cout << "Ingrese la fila del elemento a borrar (entre 0 y " << dimension - 1 << "): ";
    std::cin >> row;
    std::cout << "Ingrese la columna del elemento a borrar (entre 0 y " << dimension - 1 << "): ";
    std::cin >> col;

    if (row >= 0 && row < dimension && col >= 0 && col < dimension) {
        A[row][col] = 0; // Se borra el elemento asignándole el valor 0
        std::cout << "Elemento borrado exitosamente." << std::endl;
        std::cout << "Matriz A actualizada:" << std::endl;
        printMatrix(A, dimension);
    } else {
        std::cout << "Posicion invalida." << std::endl;
    }
}

// Función para vaciar una matriz
void vaciarMatriz(int A[MAX_DIMENSION][MAX_DIMENSION], int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            A[i][j] = 0; // Asignar 0 a todos los elementos
        }
    }
    std::cout << "Matriz vaciada exitosamente." << std::endl;
    std::cout << "Matriz A actualizada:" << std::endl;
    printMatrix(A, dimension);
}
