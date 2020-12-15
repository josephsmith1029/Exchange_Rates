#include <iostream>
#include <iomanip>

using namespace std;

//Constants
const int MAX_RATES = 7;
const int MIN_RATES = 1;
const int HEADER_LENGTH = 50;
const char HEADER_DESIGN = '=';
//Variables
string currencies[MAX_RATES] = {"EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "HKD"};
double exchangeRates[MAX_RATES] = { 0.823, 104.017, 0.750, 0.887, 1.276, 1.327, 7.752 };
//Function Prototypes
void intro();
void inputExchange(string currency, double rate);
//Function tool prototypes
void header(int length, string text, char design);
void resetPage();
void errorMessage(int code);

int main() {
	intro();
}

void intro() {
	int selection = 0;
	resetPage();
	cout << "Select a currency: \n";
	for (int i = 0; i < MAX_RATES; i++) {
		cout << i + 1 << ". " << currencies[i] << "\n";
	}
	while (selection > MAX_RATES || selection < MIN_RATES) {
		cin >> selection;
		if (selection > MAX_RATES || selection < MIN_RATES) {
			errorMessage(0);
		}
	}
	inputExchange(currencies[selection - 1], exchangeRates[selection - 1]);
}

void inputExchange(string currency, double rate) {
	resetPage();
	double amount, convertedAmount;
	cout << "USD to " << currency << " Converter";
	cout << "\nEnter amount in USD: ";
	cin >> amount;
	convertedAmount = amount * rate;
	cout << endl << fixed << setprecision(2) << amount << " in USD is " << convertedAmount << " in " << currency;
	cout << "\nPress enter to return to menu.";
	cin.sync();
	cin.get();
	cin.ignore();
	intro();
}

void header(int length, string text, char design) {
	for (int i = 0; i < length; i++)
		cout << design;
	cout << endl << text << endl;
	for (int i = 0; i < length; i++)
		cout << design;
	cout << endl;
}

void resetPage() {
	system("CLS");
	header(HEADER_LENGTH, "\t\tUSD EXCHANGE RATES", HEADER_DESIGN);
}

void errorMessage(int code) {
	switch (code) {
	case 0: cout << "Invalid selection !! Please try again.\n";
	}
}