#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
const int rozmiarAlfabetu = 52;
unsigned char alfabet[rozmiarAlfabetu] = { 97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122, //duze litery
										   5,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90, };//male litery};  
		//p=11 q==17 e=23	
int PrimeNumbersArray[151] = { 101 ,103, 107, 109, 113, 127, 131 ,137 ,139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193 ,197, 199, 211, 223, 227, 229, 233, 239, 241 ,251 ,257
,263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409 ,419, 421, 431, 433, 439 ,443, 449, 457, 461, 463, 467 ,479, 487,
491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727 ,733 ,739 ,743,
751, 757, 761, 769, 773, 787, 797, 809,
811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
long qrsArray[1000][3];
int q=0, r=0, s=0;

bool primeNumbers(int n)
{
	if (n == 1) return true;

	if (n < 2)
		return false; //gdy liczba jest mniejsza ni� 2 to nie jest pierwsz�

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}
//=============================================================================
int Euklides(int &a, int &b) 
{
	int tmp;
	while (b > 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
//=============================================================================
long long PowerMod(int a, int k, int n)
{
	long long result = 1;
	for (int i = 0; i < k; i++)
	{
		result = (result *a % n) % n;
	}
	return result;
}
//=============================================================================
long long inversionOfModulo(long long a, long long n)
{
	int belowZero;
	cout << "q" << "\t" << "r"<< "\t" << "s" << endl;
	cout << "--------------------------" << endl;
		qrsArray[0][0] = 0;		qrsArray[0][1] = n;
		qrsArray[0][2] = 1;		qrsArray[1][0] = 0;
		qrsArray[1][1] = a;		qrsArray[1][2] = 0;
		for (int i = 0; i < 2; i++)
		{
			cout << qrsArray[i][0] << "\t" << qrsArray[i][1] << "\t" << qrsArray[i][2]<<endl;
		}
		for (int i = 2; i < 1000; i++)
		{
			
				q = qrsArray[i - 2][1] / qrsArray[i - 1][1];
				qrsArray[i][0] = q;
				r = qrsArray[i - 2][1] % qrsArray[i - 1][1];
				qrsArray[i][1] = r;
				s = qrsArray[i - 2][2] - qrsArray[i][0] * qrsArray[i - 1][2];
				qrsArray[i][2] = s;
				cout << qrsArray[i][0] << "\t" << qrsArray[i][1] << "\t" << qrsArray[i][2];
				cout << endl;

				if (qrsArray[i][1] == 1)
				{
					return qrsArray[i][2]; break;
				}
				
		}
//=============================================================================
	
}

void RSAencryption(int p, int q,int e, string &text)
{
	long long d = 0;
	long long c ;
	long long m ;
	int ifBelowZero;
	long long m_deszyfr = 0;
	int n = 0 , n_result =0;

	n = p * q;
	n_result = (p - 1)*(q - 1); 
	
	d = inversionOfModulo(e , n_result);
	if (d < 0)
	{
		ifBelowZero = d + n_result;
		d = ifBelowZero;
	}

	cout << " \nFunkcja Eulera: " << n_result << endl;
	cout << " e: " << e << endl; //Klucz publiczny(e, n)
	cout << " n: " << n << endl;
	cout << " d: " << d << endl; //Klucz tajny (d, n)
	cout << endl;
	
	cout << endl;
	cout << "Szyfrowanie: " << endl;
	for (int i = 0; i < text.size(); i++) // szyfrowanie
	{
		m = text[i];
		c = PowerMod(m, e, n);
		cout.width(5);
		cout << c <<" ";
	}
	cout << endl;
	cout << "Deszyfrowanie: " << endl;
	for (int i = 0; i < text.size(); i++) //deszyfrowanie
	{
		m = text[i];
		c = PowerMod(m, e, n);
		m = PowerMod(c, d, n); 
		//cout << m<<" ";
		text[i] = m;
		cout << text[i] ;
	}
}

int main()

{
	
	
	int p_, q_,e_,a_,n_; 
	string txt = "Szyfrowanie jest dzisiaj niezbedne, poniewaz coraz wiecej osob korzysta z sieci komputerowych, szczegolnie z Internetu";

		cout << "Podaj wspolczynnik p : \t";	 cin >> p_;
		cout << "Podaj wspolczynnik q : \t";	 cin >> q_;
		cout << "Podaj wspolczynnik e : \t";	 cin >> e_;


		RSAencryption(p_, q_, e_, txt);
	
	


	
	cout << endl;
	system("PAUSE");
	return 0;
}
