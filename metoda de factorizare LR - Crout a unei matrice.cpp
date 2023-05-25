#include <iostream>
#include<math.h>
using namespace std;

const int MAX_DIM = 10;

double a[MAX_DIM][MAX_DIM], L[MAX_DIM][MAX_DIM], R[MAX_DIM][MAX_DIM], s;
int n, i, j, k, h;

int main()
{
	cout << "Dimensiune matrice: "; cin >> n;
	cout << "Matricea A:" << endl;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
		{
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}
	if (a[1][1] == 0) {
		cout << "Matricea nu poate fi factorizata cu acest algoritm.";
		exit(1);
	}
	else
	{
		for (j = 2;j <= n;j++)
			a[1][j] = a[1][j] / a[1][1];
		for (k = 2;k <= n - 1;k++)
		{
			for (i = k;i <= n;i++)
			{
				s = 0;
				for (h = 1;h <= k - 1;h++)
					s += a[i][h] * a[h][k];
				a[i][k] = a[i][k] - s;
			}
			if (a[k][k] == 0) {
				cout << "\nMatricea nu poate fi factorizata cu acest algoritm.";
				exit(1);
			}
			else
			{
				for (j = k + 1;j <= n;j++)
				{
					s = 0;
					for (h = 1;h <= k - 1;h++)
						s += a[k][h] * a[h][j];
					a[k][j] = (a[k][j] - s) / a[k][k];
				}
			}
		}
		s = 0;
		for (h = 1;h <= n - 1;h++)
			s += a[n][h] * a[h][n];
		a[n][n] = a[n][n] - s;
	}
	cout << "Matricea L:" << endl;
	for (i = 1;i <= n;i++)
		for (j = 1;j <= i;j++)
			L[i][j] = a[i][j];
	cout << endl;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			cout << L[i][j] << "  ";
		cout << endl;
	}
	cout << "Matricea R:" << endl;
	for (i = 1;i <= n;i++)
	{
		for (j = i;j <= n;j++)
			R[i][j] = a[i][j];
		R[i][i] = 1;
	}
	cout << endl;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
			cout << R[i][j] << "  ";
		cout << endl;
	}
	return 0;
}