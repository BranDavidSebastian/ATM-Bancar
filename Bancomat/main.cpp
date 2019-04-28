#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <sstream>

using namespace std;

int adunare (int a, int b)
{
	int suma;
	suma = a + b;
	return suma;
}

int scadere (int c, int d)
{
	int diferenta;
	diferenta = c - d;
	return diferenta;
}

float transfer (float contExpeditor){

    int sumaTransferata;
    cout << "Cat doriti sa transferati: ";
    cin >> sumaTransferata;
    if (sumaTransferata > contExpeditor)
    {
        cout << "Fonduri insuficiente!";
sumaTransferata=0;
    }
    else


cout << "\nSuma a fost transferata cu succes!";

return sumaTransferata;
}

int main(void)
{
	int alegere;
	float cont = 10000;
	float cont2 = 500;
	string cont2iban;
	int sumaBani;
	int cod;
	const int CR = 13;
	int incercari = 3;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	std::string codstr;

	retry:
	cod = 0;
	codstr = "0";
	cout<< endl;
	cout<< "\t \t Bine ati venit la BanutzBank \t \t \n";
	cout<< endl;
	cout<< endl;
	cout<< "Va rugam introduceti pinul: ";
    do
	{
		cod = _getch();
		if (isdigit(cod))
			{
				codstr += (char)cod;
				cout << "*";
			}
	}
	while (cod != CR);

	stringstream convert(codstr);
	if ( !(convert >> cod) )
		cod = 0;
	system ("CLS");
   if (incercari == 1){
    cout << "Cardul a fost blocat!";
  return 0;
   }

	if (cod == 1234)
	{
		goto proceed;
	}
	else
	{
		system ("CLS");
		cout<< "PIN INVALID!";
		system ("CLS");
		incercari--;
		if (incercari > 1)
		cout<< "Mai ai " << incercari << " incercari pentru a nu-ti fi blocat cardul!" << endl;
		else if ( incercari == 1) {
            cout << "Mai ai o incercare pentru a nu-ti fi blocat cardul!" << endl;
		}
		else
            cout << endl;
		goto retry;
	}

	proceed:
	cout<< "\nAccesam datele";
	system ("CLS");

	repeat:
	cout<< "\n\nSelectati o optiune: \n";
	cout<< "[1] Interogare sold\n[2] Retragere numerar\n[3] Depozitare numerar \n[4] Transfer bancar\n\n";
	cout<< "Optiunea selectata este: ";
	cin>> alegere;
	system ("CLS");

	if (alegere==1)
	{
		cout<< "\nSoldul dumneavoastra este: " << cont;
	}
	else if (alegere==2)
	{
		cout<< "\nIntroduceti suma pe care doriti sa o retrageti: ";
		cin>> sumaBani;
		system ("CLS");
		if (sumaBani>cont)
		{
			cout<< "\nFONDURI INSUFICIENTE";
		}
		else if (sumaBani<=0)
		{
			cout<< "\nSuma nu poate fi negativa, si nu va vom adauga daca puneti -, ne pare rau!";
		}
		else
		{
		cont = scadere (cont, sumaBani);
		cout<< "\nTranzactia a fost incheiata cu succes! " ;
		}
	}
	else if (alegere==3)
	{
		cout<< "\nIntroduceti suma pe care doriti sa o depozitati ";
		cin>> sumaBani;
		system ("CLS");
		if (sumaBani<=0)
		{
			cout<< "\nDaca doriti sa retrageti bani apelati la optiunea retragere numerar";
		}
		else
		{
			cont = adunare (cont, sumaBani);
			cout<< "\nTranzactia a fost incheiata cu succes! ";
		}
	}
	else if (alegere ==4){
    cout << "\n Introduceti IBAN-ul contului destinatar: ";
    cin >> cont2iban;


    sumaBani =transfer(cont);
    cont= scadere (cont, sumaBani);
    cont2 = adunare (cont2, sumaBani);
    cout << "\n Contul destinatar are acum: " << cont2 << " lei";

	}
	else
	{
		cout<< "\n\nAlegere invalida!";
		goto repeat;
		return 0;
	}

	last:
	cout<< "\n\nDoriti sa efectuati inca o tranzactie?\n";
	cout<< "Selectati o optiune\n\n";
	cout<< "[1] Da \n[2] Nu\n\n" << "Optiune selectata: ";
	cin>>alegere;
	system ("CLS");
	if (alegere==1)
	{
		goto repeat;
	}
	else
	{
		end:
		system ("CLS");
		cout<< "\n Va multumim ca ati ales serviciile BanutzBank!";
		return 0;
	}
}
