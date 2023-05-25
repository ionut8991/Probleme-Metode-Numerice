#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float f(float x) {
    return (4 * x * x * x - 8 * x * x + 12 * x - 8);
}

void secanta(float x0, float x1, float epsif, int nmax, float& xr, int& kod) {
    int iter = 0;
    float fx0, fx1, fxr;
    ofstream fwrite("fisiersecanta.txt", ios::out); // deschide fisierul pentru scriere
    kod = 0;
    fx0 = f(x0);
    fx1 = f(x1);
    fwrite << "Procedura metoda secantei\n\n";
    fwrite << "iter x0 / fx0 x1 / fx1 xr / fxr\n";

    while (fabs(fx1) > epsif && iter < nmax) {
        iter++;
        xr = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
        fxr = f(xr);

        fwrite << iter << "\t\t" << x0 << "\t\t" << fx0 << "\t\t" << x1 << "\t\t" << fx1 << "\t\t" << xr << "\t\t" << fxr << "\n";

        if (fabs(fxr) <= epsif) {
            kod = 0;
            break;
        }

        x0 = x1;
        fx0 = fx1;
        x1 = xr;
        fx1 = fxr;
    }

    if (iter == nmax)
        kod = 1;

    fwrite << "solutia ecuatiei: " << xr;
    fwrite.close();
}

int main() {
    float x0, x1, xr, sol;
    int cod, nmax;
    cout << "x0=";
    cin >> x0;
    cout << "x1=";
    cin >> x1;
    cout << "nmax=";
    cin >> nmax;
    secanta(x0, x1, 1E-2, nmax, sol, cod);
    cout << "\n cod=" << cod;
    cout << "\n sol=" << sol;
    return 0;
}

