#include <iostream>
#include <cmath>


using namespace std;

unsigned long PowerMod(int a, int k, int n)
{
	int result = 1;
	for (int i = 0; i < k; i++)
	{
		result = (result *a %n) % n;
	}
	return result;
}
void Binary(int number) {
	int binary[31]; int i = 0;
	while (number != 0) {
		binary[i++] = number % 2;
		number /= 2;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << binary[j];
}
unsigned long PowerModFast(int base, int power, int modulo)
{
	int result = 1;
	cout << base << " ^ " << power << " mod " << modulo << " =  ";
	while (power > 0) {
		if (power % 2 == 1) {
			result = (result * base) % modulo;
		}
		base = (base*base) % modulo;
		power = power / 2;	
	}
	return result;
}


int main()
{
	int a, b;

	cout << endl;
	int A = PowerMod(2, 3, 11);
	//int B = PowerMod(5, b, 23);
	int B = 5;
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;

	int keyA = PowerMod(B, 3, 11);
	//int keyB = PowerMod(A, b, 23);

	cout << "\nKlucz A: " << keyA << endl;
	//cout << "Klucz B: " << keyB << endl;
	 cout << "\n ================ POWER FAST MODULO ==============================" << endl;
	 cout << PowerModFast(5,3 , 11); 
	 cout << endl;
	 cout << "\n ================ POWER MODULO ==============================" << endl;
	 cout << PowerMod(5, 3, 11);
	 cout << endl;
	system("PAUSE");
	return 0;
}