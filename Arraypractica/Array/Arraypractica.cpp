#include <iostream>

using namespace std;

void printArray(int a[], int t)
{
	for (int i = 0; i < t; i++)
		cout << a[i] << " ";
}
int sumaArrayI(int a[], int t)
{
	int c = 0;
	for (int i = 0; i < t; i++)
		c += a[i];
	return c;
}

int sumaArrayR(int a[], int t)
{
	if (!t)
		return 0;
	return a[0] + sumaArrayR(a + 1, --t);
}

int swapArrayI(int a[], int t)
{
	for (int i = 0; i < (t / 2); i++)
	{
		int aux = a[i];
		a[i] = a[t - 1];
		a[--t] = aux;
	}
	return 1;
}

void swapArrayR(int a[], int t)
{
	if (t / 2 == 0)
		return;
	int aux = a[0];
	a[0] = a[t - 1];
	a[--t] = aux;
	swapArrayR(a + 1, t - 1);
}

void Swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

void bubbleArray(int a[], int t)
{
	for (int i = 0; i < t - 1; i++)
	{
		for (int j = 0; j < t - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				Swap(a[j], a[j + 1]);
		}
			
	}
}

int orden(int a[], int mini, int maxi)
{
	int p = a[maxi];
	int w = mini - 1;
	for (int j = mini; j <= maxi-1; j++)
	{
		if (a[j] < p)
		{
			w++;
			Swap(a[mini], a[j]);
		}
	}
	Swap(a[w + 1], a[maxi]);
	return w + 1;
}

void quickArray(int a[], int mini, int maxi)
{
	if (mini < maxi)
	{
		int p = orden(a, mini, maxi);
		quickArray(a, mini, maxi - 1);
		quickArray(a, mini + 1, maxi);
	}
}

void insArray(int a[], int t)
{
	int x, y;
	for (int i = 1; i < t; i++)
	{
		y = a[i];
		x = i - 1;
		while (x >= 0 and y < a[x])
		{
			a[x + 1] = a[x];
			x--;
		}
		a[x + 1] = y;
	}
}

int main()
{
	int a[5] = { 1, 4, 5, 6, 3 };
	// printArray(a,4);
	//cout << sumaArrayI(a, 4) << endl;
	//cout << sumaArrayR(a, 4) << endl;
	//swapArrayI(a, 5);
	//swapArrayR(a, 5);
	//bubbleArray(a, 5);
	//quickArray(a, 0, 4);
	insArray(a, 5);
	printArray(a, 5);


	return 0;
}