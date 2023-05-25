#include <iostream>
#include <cmath>
using namespace std;

double a[10][10], b[10], x[10];
int i, j, n;

void citesteDate()
{
    cout << "Nr necunoscute: ";
    cin >> n;

    cout << "Elem mat: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }

    cout << "Vector initial: " << endl;
    for (i = 1; i <= n; i++) {
        cout << "x[" << i << "]=";
        cin >> x[i];
    }
}

void gaussSeidel()
{
    double epsilon = 0.0001;
    int maxIter = 100;
    int iter = 0;
    double sum;
    double error;

    do {
        error = 0.0;

        for (i = 1; i <= n; i++) {
            sum = 0.0;

            for (j = 1; j <= n; j++) {
                if (j != i) {
                    sum += a[i][j] * x[j];
                }
            }

            x[i] = (a[i][n + 1] - sum) / a[i][i];

            error += fabs(x[i] - x[i - 1]);
        }

        iter++;
    } while (error > epsilon && iter < maxIter);
}

void afiseazaSolutie()
{
    cout << "\nSol este:" << endl;
    for (i = 1; i <= n; i++) {
        cout << "x" << i << "=" << x[i] << endl;
    }
}

int main()
{
    citesteDate();
    gaussSeidel();
    afiseazaSolutie();

    return 0;
}
