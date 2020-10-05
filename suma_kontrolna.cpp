#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <math.h>

using namespace std;
unsigned int  DJB(string str)
{
	int hash = 5381;
	for (int i = 0;  i < str.size(); i++)
	{
		hash = hash * 32 + hash + str[i];
	}
	return hash;
}
unsigned int Adler_32(string str)  //sumy kontrolne
{
	unsigned int A = 1;
	unsigned int B = 0;
	unsigned int P = 65521;

	for (int i = 0; i < str.length() ; i++) {
		A = (A + static_cast<int>( str[i])) % P;
		B = (B + A) % P;
	}
	return static_cast<long>(B * 65536 + A);
}

string Random( int size) {
	string str;
	str.resize(size);
	for (int i = 0; i < size; i++) {
		str[i] = (rand() % 26 )+ 97;
	}
	return str;
}
unsigned int howManyCollisions(int n,unsigned int Tab[]) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (Tab[i] == Tab[j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	srand((unsigned)time(NULL));
	int size = 400;
	unsigned int* TabForAdler = new unsigned int[size];
	unsigned int* TabForDjb = new unsigned int[size];
	string data = "test";
	unsigned int djb = DJB(data);
	unsigned int adler =  Adler_32(data);
	cout << "\nAdler_32: " << adler << endl;
	cout << "\n==================================" << endl;
	cout << "\nDJB: " << djb << endl;
	cout << "\n==================================\n" << endl;

	cout << "Adler_32: \n";
	for (int i = 0; i < size; i++) {
		TabForAdler[i] = Adler_32(Random(12));
	}
	cout << "Kolizja dla 12 znakow -> " << howManyCollisions(size, TabForAdler) << endl;
	for (int i = 0; i < size; i++) {
		TabForAdler[i] = Adler_32(Random(40));
	}
	cout << "Kolizja dla 1000 znakow -> " << howManyCollisions(size, TabForAdler) << endl;

	cout << "DJB: \n";
	for (int i = 0; i < size; i++) {
		TabForDjb[i] = DJB(Random(12));
	}
	cout << "Kolizja dla 12 znakow -> " << howManyCollisions(size, TabForDjb) << endl;
	for (int i = 0; i < size; i++) {
		TabForDjb[i] = DJB(Random(1000));
	}
	cout << "Kolizja dla 1000 znakow -> " << howManyCollisions(size, TabForDjb) << endl;

	cout << "\n\n";
	system("PAUSE");
	return 0;
}