#pragma comment(lib,"wininet.lib") //remove if not using VC++.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wininet.h>
#include <cstring>
#include <string>

using namespace std;

float kurs() {

	

	string str, str2;
	float ex;

	HINTERNET connect = InternetOpenA("MyBrowser", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	if (!connect) {
		cout << "Connection Failed or Syntax error";

	}

	HINTERNET OpenAddress = InternetOpenUrlA(connect, "http://api.nbp.pl/api/exchangerates/rates/a/eur/", NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION, 0);

	if (!OpenAddress)
	{
		DWORD ErrorNum = GetLastError();
		cout << "Failed to open URL \nError No: " << ErrorNum;
		InternetCloseHandle(connect);

	}

	char DataReceived[4096];
	DWORD NumberOfBytesRead = 0;
	while (InternetReadFile(OpenAddress, DataReceived, 4096, &NumberOfBytesRead) && NumberOfBytesRead)
	{
		//cout << DataReceived;
		str += DataReceived;
	}

	ex = stof(str.substr(111, 6));

	//cout << ex;

	InternetCloseHandle(OpenAddress);
	InternetCloseHandle(connect);

	return ex;

}




void sprawdz(int* cenapomodulo) {

	if (*cenapomodulo <= 5)
		*cenapomodulo = 5;
	else
		*cenapomodulo = 9;
};




int main()
{
	int cena, cenapl, i;
	double mnoznik[4] = { 0.85,0.75,0.65,0.5 };
	int temp, temp2;

	cout << "Dzisiejsz sredni kurs EUR wynosi  " << kurs();
	

	do {

		cout << "\nPodaj cene w EURO znaleziona na zagranicznych stronach: ";
		cin >> cena;
		cenapl = (int)(cena * kurs());
		cout << "Cena sugerowana to " << cenapl << " PLN \n\n";
		cout << "\tNormalne \t\t Dodatkowo obnizone\n";

		for (i = 0; i<4; i++)
		{
			temp = (int)(cenapl*mnoznik[i]);
			temp2 = (int)(cenapl*mnoznik[i]);
			//printf("\n\ncena po obnizce %d\n\n", temp);
			temp = temp % 10;
			temp2 -= temp;
			sprawdz(&temp);
			temp2 += temp;


			if (i == 0)
				cout << "\tKlasa 1 to PLN " << temp2;
			else if (i == 1)
				cout << "\t\t Klasa 1 to PLN " << temp2 << "\n";
			else if (i == 2)
				cout << "\tKlasa 2 to PLN " << temp2;
			else
				cout <<"\t\t Klasa 2 to PLN " << temp2 << "\n"; 
		}



	} while (1);
	//Dziekuje za skorzystanie z programu\n\t\tCopyright by Dorota Przyjemska.";
	
	return 0;
}
