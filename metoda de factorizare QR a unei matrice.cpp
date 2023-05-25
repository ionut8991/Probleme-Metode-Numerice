#include <iostream>
#include <cmath>

using namespace std;

const int MAX_DIM = 10;

void unitate(double a[][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}

void produs(double a[][MAX_DIM], double b[][MAX_DIM], double c[][MAX_DIM], int n) {
    double ct[MAX_DIM][MAX_DIM];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ct[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ct[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = ct[i][j];
        }
    }
}

void factorizareQR(double a[][MAX_DIM], double q[][MAX_DIM], double r[][MAX_DIM], int n) {
    double v[MAX_DIM];
    double beta;

    unitate(q, n);
    for (int k = 0; k < n - 1; k++) {
        double s = 0.0;
        for (int i = k; i < n; i++) {
            s += a[i][k] * a[i][k];
        }
        double sigma = sqrt(s);
        if (sigma != 0.0) {
            if (a[k][k] < 0) {
                sigma = -sigma;
            }
            v[k] = a[k][k] + sigma;
            for (int i = 0; i < k; i++) {
                v[i] = 0.0;
            }
            for (int i = k + 1; i < n; i++) {
                v[i] = a[i][k];
            }
            s = 0.0;
            for (int i = k; i < n; i++) {
                s += v[i] * v[i];
            }
            beta = s / 2.0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        q[i][j] = -v[i] * v[j] / beta;
                    }
                    else {
                        q[i][j] = 1.0 - v[i] * v[i] / beta;
                    }
                }
            }
            produs(q, a, a, n);
            produs(q, r, r, n);
        }
    }
}

void afisareMatrice(double mat[][MAX_DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    double a[MAX_DIM][MAX_DIM], q[MAX_DIM][MAX_DIM], r[MAX_DIM][MAX_DIM];

    cout << "Dimensiune matrice: ";
    cin >> n;

    cout << "Matricea A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    factorizareQR(a, q, r, n);

    cout << endl << "Matricea Q:" << endl;
    afisareMatrice(q, n);

    cout << endl << "Matricea R:" << endl;
    afisareMatrice(r, n);

    return 0;
}
