#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

void citesteMatrice(double mat[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Elemente matrice: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> mat[i][j];
        }
    }
}

void rezolvaSistem(double mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (i != j) {
                double b = mat[i][j] / mat[j][j];
                for (int k = 1; k <= n + 1; k++) {
                    mat[i][k] = mat[i][k] - b * mat[j][k];
                }
            }
        }
    }
}

void afiseazaSolutii(double mat[MAX_SIZE][MAX_SIZE], int n) {
    cout << "\nSolutiile sunt: " << endl;
    for (int i = 1; i <= n; i++) {
        double solutie = mat[i][n + 1] / mat[i][i];
        cout << "x" << i << " = " << solutie << endl;
    }
}

int main() {
    int n;
    cout << "Numar necunoscute: ";
    cin >> n;

    double mat[MAX_SIZE][MAX_SIZE];

    citesteMatrice(mat, n);
    rezolvaSistem(mat, n);
    afiseazaSolutii(mat, n);

    return 0;
}
