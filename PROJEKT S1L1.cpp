#include <iostream>
#include<iomanip>
#include <cmath>
#include <stack>

using namespace std;

void showPop(int daySP, int susSP, int infSP, int recSP) { //dane na dzien 0
	cout << "Dzien: " << daySP << "\nMozliwi do zakazenia: " << susSP << "\nChorzy: " << infSP << "\nWyleczeni: " << recSP << "\nRazem: " << susSP + infSP + recSP << endl;
}
int simDay(int& daySD, int& susSD, int& infSD, int& recSD, double& infRSD, double& recRSD) { //symulacja dnia kolejnego SD-symulator dnia
	daySD = daySD + 1;
	infSD = (infSD * infRSD) - (recSD*recRSD) + infSD;
	recSD = (recSD * recRSD) + recSD;
	susSD = 100 - infSD - recSD;
	cout << "Dzien: " << floor(daySD) << "\nMozliwi do zakazenia: " << floor(susSD) << "\nChorzy: " << floor(infSD) << "\nWyleczeni: " << floor(recSD) << "\nRazem: " <<
		floor(susSD) + floor(infSD) + floor(recSD) << endl;
	return daySD, susSD, infSD, recSD; 
}

bool checkPop(int susCHE, int infCHE, int recCHE) { //sprawdzenie czy cos sie nie zepsulo w trakcie
	if ((susCHE < 0) || (infCHE < 0) || (recCHE < 0)) {
		cout << "Symulacja jest nieprawidlowa" << endl;
		return false;
	}
	else { return true; }
	if (susCHE + infCHE + recCHE != 100) {
		cout << "Symulacja jest nieprawidlowa" << endl;
		return false;
	}
	else { return true; }
}


int main() {
	int sus, inf, rec, day; //deklaracja stanu ludnosci, gdzie sus to mozliwy do infekcji, inf to chory, rec to wyzdrowialy, a day to obecny dzien
	sus = 80;
	inf = 10;
	rec = 10;
	day = 0;
	double infR, recR; //szanda na zarazenie i szansa na wyleczenie
	infR = 0.20;
	recR = 0.10;
	showPop(day, sus, inf, rec);
	
menu: //etykieta skokowa
	int opcja;
		cout << "\n===Symulator Epidemii===" << endl;
		cout << "1. Symuluj dzien kolejny" << endl;
		cout << "2.Zmien parametry modelu" << endl;
		cout << "3.Wyjdz" << endl;
		cout << "Wybierz opcje: " << endl;
			cin >> opcja;
		
		switch (opcja) {
		case 1:
			simDay(day, sus, inf, rec, infR, recR);
			if (checkPop(sus, inf, rec) == false) { //sprawdzenie czy wszystko gra
				break;
			}
			goto menu;
		case 2:
			double infR2, recR2;
			cout << "Podaj wspolczynnik zarazenia (0-1): " << endl;
			cin >> infR2;
			cout << "Podaj wspolczynnik uleczalnosci (0-1): " << endl;
			cin >> recR2;
			if ((recR2 < 0) || (recR2 > 1) || (infR2 < 0) || (infR2 > 1)) {
				cout << "Nie ma mozliwosci tej zmiany" << endl;
			}
			else { 
				recR = recR2; //zmiana wartosci zmiennych
				infR = infR2;
				cout << "Zmiana przeprowadzona pomyslnie" << endl;
			}
		
			goto menu;
		case 3:
			cout << "Wychodzenie..." << endl;
			break; //zamykanie programu
		default:
			cout << "Nie ma takiej opcji" << endl;
			goto menu; //funkcja skokowa w celu powrotu do menu
		}
			
		
	}

