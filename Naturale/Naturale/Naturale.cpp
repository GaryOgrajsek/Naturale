#include "Naturale.h"
#include <iostream>
#include <string>

using namespace std;
//--------------------------------------------------------
//                     Costruttore
//--------------------------------------------------------
Naturale::Naturale() {}

Naturale::~Naturale() {}

bool ValidoInput(int x) {
	if (x < 0 && x != floor(x)) {
		return false;
	}
	return true;
}
//--------------------------------------------------------
//                     friend
//--------------------------------------------------------

//--------------------------------
//              Input
//--------------------------------
istream & operator>>(istream &cin, Naturale &nat) {

	//Numero inserito dall'utente
	int n;
	do {
		cout << "Numero: ";
		cin >> n;
	} while (!(ValidoInput(n)));
	//Serve per contenere il valore della singola cifra di num

	//------------- Controllo ------------------
	//Il numero deve essere maggiore di zero
	//Altrimenti interrompe l'inserimento 
	if (n < 0) {
		cout << "Il numero deve essere maggiore di zero" << endl;
		return cin;
	}

	//Scansiona tutte le cifre del numero
	//Le inserisce in testa alla lista
	while (n != 0) {
		//Ottiene la prima cifra del numero
		//Inserisce in testa la cifra ottenuta
		nat.numero.InserisciInTesta(n % 10);

		//Sposta la seconda cifra in prima posizione
		n /= 10;
	}

	return cin;
}

//--------------------------------
//            Output
//--------------------------------

ostream &operator<<(ostream &cout, Naturale &nat) {

	Nodo<int>* p = nat.numero.GetElle();

	//Contiene la lista
	string str="";

	//Finchè il puntatore non punta a nullptr
	while (p != nullptr) {
		//Riceve il numero dal nodo
		str += to_string(p->getInfo());

		//Sposta p al nodo successivo
		p = p->getPunt();
	}

	//Stampa la stringa
	cout << str << endl;

	return cout;
}

//--------------------------------
//              ++
//--------------------------------

void operator --(Naturale& numero){
}

void Naturale::Zero() {
	numero.Azzera();
}

bool Naturale::Is_Zero() {
	return(numero.ControllaSeZero());
}

Naturale Naturale::Fact(){
	Naturale temporaneo = this;
	if (numero.ControllaSeUno()) {
		temporaneo.numero.InserisciInTesta(1);
		return temporaneo;
	}
	return numero * Fact(numero - 1);
}
template <class tipo>
bool Lista<tipo>::ControllaSeUno() {
	Nodo<tipo>* p = L;
	int check = 0;
	while (p->getPunt() != 0) {
		check += p->getInfo();
	}
	return (check <= 1);
}
/*int FATT(int n){
	if (n <= 1) return 1;
	else return n * FATT(n - 1);
}*/
