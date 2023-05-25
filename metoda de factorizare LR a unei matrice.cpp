#include <iostream>
#include <cmath>

using namespace std;

const int MAX_DIM = 10;

void afisareMatrice(double mat[][MAX_DIM], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double a[MAX_DIM][MAX_DIM], l[MAX_DIM][MAX_DIM], r[MAX_DIM][MAX_DIM];
    int n;

    cout << "Dimensiune matrice: ";
    cin >> n;

    cout << "Matricea A:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    if (a[1][1] == 0) {
        cout << "Matricea nu poate fi factorizata cu acest algoritm." << endl;
        return 0;
    }
    else {
        for (int i = 2; i <= n; i++) {
            a[i][1] = a[i][1] / a[1][1];
        }
        for (int k = 2; k <= n -1 ; k++) {
            for (int j = k; j <= n; j++) {
                double s = 0;
                for (int h = 1; h <= k - 1; h++) {
                    s += a[k][h] * a[h][j];
                }
                a[k][j] = a[k][j] - s;
            }
            if (a[k][k] == 0) {
                cout << "Matricea nu poate fi factorizata cu acest algoritm." << endl;
                return 0;
            }
            else {
                for (int i = k + 1; i <= n; i++) {
                    double s = 0;
                    for (int h = 1; h <= k - 1; h++) {
                        s += a[i][h] * a[h][k];
                    }
                    a[i][k] = (a[i][k] - s) / a[k][k];
                }
            }
        }
    }

    cout << endl << "Matricea L:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i == j) {
                l[i][j] = 1.0;
            }
            else {
                l[i][j] = a[i][j];
            }
        }
    }
    afisareMatrice(l, n);

    cout << endl << "Matricea R:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            r[i][j] = a[i][j];
        }
    }
    afisareMatrice(r, n);

    return 0;
}
