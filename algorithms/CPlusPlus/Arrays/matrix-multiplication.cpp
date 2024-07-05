#include <iostream>
using namespace std;

void multiplyMatrices(int** firstMatrix, int** secondMatrix, int** result, int row1, int col1, int row2, int col2) {
    // Initializing elements of result matrix to 0
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying firstMatrix and secondMatrix and storing in result
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void display(int** matrix, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row1, col1, row2, col2;
    
    cout << "Enter rows and columns for the first matrix: ";
    cin >> row1 >> col1;

    cout << "Enter rows and columns for the second matrix: ";
    cin >> row2 >> col2;

    // Checking if multiplication is possible
    if (col1 != row2) {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    // Dynamic memory allocation for matrices
    int** firstMatrix = new int*[row1];
    for (int i = 0; i < row1; ++i)
        firstMatrix[i] = new int[col1];

    int** secondMatrix = new int*[row2];
    for (int i = 0; i < row2; ++i)
        secondMatrix[i] = new int[col2];

    int** result = new int*[row1];
    for (int i = 0; i < row1; ++i)
        result[i] = new int[col2];

    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            cin >> firstMatrix[i][j];
        }
    }

    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; ++j) {
            cin >> secondMatrix[i][j];
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, result, row1, col1, row2, col2);

    cout << "Resultant matrix:" << endl;
    display(result, row1, col2);

    // Deallocate memory
    for (int i = 0; i < row1; ++i)
        delete[] firstMatrix[i];
    delete[] firstMatrix;

    for (int i = 0; i < row2; ++i)
        delete[] secondMatrix[i];
    delete[] secondMatrix;

    for (int i = 0; i < row1; ++i)
        delete[] result[i];
    delete[] result;

    return 0;
}
