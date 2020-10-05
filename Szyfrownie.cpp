
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
const int rozmiarAlfabetu = 62;
string tekst_jawny, tekst_zaszyfrowany, opcja, tekst_tmp ;
int Histogram[1000];

unsigned char alfabet[rozmiarAlfabetu] = { 97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122 ,  //duze litery
										   65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90, //male litery
										   0,1,2,3,4,5,6,7,8,9 }; //cyfry
/*char alfabet[36] = { 'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','R',
					   'S','T','U','W','Y','Z','0','1','2','3','4','5','6','7','8','9' };*/
int przesuniecie=4, rozmiarTekstuJawnego, rozmiarTekstuTajnego;

int main()
{
	ifstream in;
	ofstream out;
	ofstream out_tmp;
	out_tmp.open("txt_odszyfr_tmp.txt");
	in.open("tekst_jawny.txt");
	out.open("tekst_zaszyfrowany.txt");

	while (!in.eof())
	{
		getline(in, tekst_jawny);
		
		rozmiarTekstuJawnego = tekst_jawny.length();
		tekst_zaszyfrowany.resize(rozmiarTekstuJawnego);

		for (int i = 0; i < rozmiarTekstuJawnego; i++)
		{
			for (int j = 0; j < rozmiarAlfabetu; j++)
			{
				
				if (tekst_jawny[i] == alfabet[j])
				{
					tekst_zaszyfrowany[i] = (int)alfabet[(j + przesuniecie) % rozmiarAlfabetu];
					
				}
			}
		}
		//cout << tekst_zaszyfrowany;
		out << tekst_zaszyfrowany << endl;

		for (int i = 0; i < rozmiarTekstuTajnego; i++)
		{
			for (int j = 0; j < rozmiarAlfabetu; j++)
			{
				if (tekst_zaszyfrowany[i] == alfabet[j])
				{
					tekst_jawny[i] = (int)alfabet[(j - przesuniecie) % rozmiarAlfabetu];
					
				}
			}
		}
		out_tmp << tekst_jawny << endl;
		
	}
	
	in.close();
	out.close();
	out_tmp.close();

	system("PAUSE");
	return 0;
}
