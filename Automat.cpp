#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


class uzytkownik
{
public:
	string imie;
	string nazwisko;
	string login;

public:	
uzytkownik(string imie="", string nazwisko="", string login="")
{
	this->imie=imie;
	this->nazwisko=nazwisko;
	this->login=login;
}

~uzytkownik()
{

}

void wyswietl()
{
	cout << login << " "<< imie << " " << nazwisko << " " << endl;
}

string get_imie(){ return imie; }

string get_nazwisko(){ return nazwisko; }

string get_login(){	return login; }

};


main(){
string organizationunit; //jednostka organizacyjna
string opis;
string grupa;
string grupa2;
string skryptlogowania;
string linijka="";

string quota="\"";
fstream plik;
string NazwaPliku = "nowiuzytkownicy.txt"; //nazwa pliku zczytywanego z nowymi u¿ytkownikami

plik.open(NazwaPliku.c_str(), ios::in);
{
		if(plik.good())
		{
			cout << "Otwarto plik! " << NazwaPliku << endl;
			
			
			
			plik.seekp(0,ios::beg);
			plik >> organizationunit >> opis >> grupa >> skryptlogowania; //zczytywanie z pliku informacji o danym projekcie
			
			
			while(!plik.eof())
			{
				
				
				uzytkownik doOdczytu;
				plik >> doOdczytu.login >> doOdczytu.imie >> doOdczytu.nazwisko;  //zczytywanie z pliku informacji o konsultancie
				doOdczytu.wyswietl();


				/*
				Polecenie dsadd do dodawania u¿ytkownika domenowego
				*/
					system(("dsadd user cn="+quota+doOdczytu.get_imie()+" "+doOdczytu.get_nazwisko()+quota+",OU="+organizationunit+",dc=teleinvention,dc=local -upn "+doOdczytu.get_login()+
						"@teleinvention.local"+" -samid "+doOdczytu.get_login()+" -display "+quota+doOdczytu.get_imie()+" "+doOdczytu.get_nazwisko()+quota+
						" -fn "+doOdczytu.get_imie()+" -ln "+doOdczytu.get_nazwisko()+" -pwd password -desc "+opis+" -mustchpwd yes"+" -loscr "+skryptlogowania).c_str());
	
				cout << endl;
				
				
				
				/*
				Polecenie net gropu do dodania uzytkownika do grupy
				*/
				system(("net group "+grupa+" "+doOdczytu.get_login()+" /domain /add").c_str());
			
			
				/*
				net user do wyswietlania informacji o nowo utworzonym u¿ytkowniku
				*/
				system(("net user "+doOdczytu.get_login()+" /domain").c_str());

			
			}
			plik.close();
			
			system("Pause");
			plik.open(NazwaPliku.c_str(), ios::out); //otwarty do zapisu by usunac zawartosc pliku.
			plik.close();
			
		}
		else 
		{
			cout << "Blad odczytu!" << endl;
		}
}

}








