// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    // Initialize result to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;
    int r1, c1, r2, c2;
    int m1[MAX][MAX], m2[MAX][MAX], res[MAX][MAX];

    cout << "Choose an operation:\n1. Transpose\n2. Add Matrices\n3. Multiply Matrices\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter rows and columns: ";
        cin >> r1 >> c1;
        readMatrix(m1, r1, c1);
        
        cout << "\nOriginal Matrix:\n";
        printMatrix(m1, r1, c1);
        
        transposeMatrix(m1, res, r1, c1);
        cout << "\nTransposed Matrix:\n";
        printMatrix(res, c1, r1);

    } else if (choice == 2) {
        cout << "Enter rows and columns for both matrices: ";
        cin >> r1 >> c1;
        r2 = r1; c2 = c1; // Must be same size
        
        cout << "Enter Matrix 1:\n";
        readMatrix(m1, r1, c1);
        cout << "Enter Matrix 2:\n";
        readMatrix(m2, r2, c2);
        
        addMatrices(m1, m2, res, r1, c1);
        cout << "\nResult of Addition:\n";
        printMatrix(res, r1, c1);

    } else if (choice == 3) {
        cout << "Enter rows and columns for Matrix A: ";
        cin >> r1 >> c1;
        cout << "Enter rows and columns for Matrix B: ";
        cin >> r2 >> c2;

        if (c1 != r2) {
            cout << "Error: Columns of A must equal Rows of B." << endl;
            return 1;
        }

        cout << "Enter Matrix A:\n";
        readMatrix(m1, r1, c1);
        cout << "Enter Matrix B:\n";
        readMatrix(m2, r2, c2);

        multiplyMatrices(m1, m2, res, r1, c1, c2);
        cout << "\nResult of Multiplication:\n";
        printMatrix(res, r1, c2);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
