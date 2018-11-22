#include "Naturale.h"
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
//--------------------------------------------------------
//                     Costruttore
//--------------------------------------------------------
Naturale::Naturale() {}

Naturale::~Naturale() {}

//--------------------------------------------------------
//                     friend
//--------------------------------------------------------

//--------------------------------
//              Input
//--------------------------------
istream & operator>>(istream &cin, Naturale &nat) {

	//Numero inserito dall'utente
	int n;
	//Serve per contenere il valore della singola cifra di num
	int cifra;

	//Inserimento del numero da tastiera
	cout << "Numero da inserire: ";
	cin >> n;

	//------------- Controllo ------------------
	//Il numero deve essere maggiore di zero
	//Altrimenti interrompe l'inserimento 
	if (n < 0) {
		cout << "Il numero deve essere maggiore di zero" << endl;
		return cin;
	}

	//Scansiona tutte le cifre del numero
	//Le inserisce in testa alla lista
	while (n >= 0) {
		//Ottiene la prima cifra del numero
		cifra = n % 10;

		//Inserisce in testa la cifra ottenuta
		nat.numero.InserisciInTesta(cifra);

		//Sposta la seconda cifra in prima posizione
		n /= 10;
	}

	return cin;
}

//--------------------------------
//            Output
//--------------------------------
template<class tipo>
ostream &operator<<(ostream &cout, Naturale &nat) {

	Nodo<tipo>* p = L;

	//Contiene la lista
	string str = null;

	//Finchè il puntatore non punta a nullptr
	while (p != nullptr) {
		//Riceve il numero dal nodo
		str += p->getInfo();

		//Sposta p al nodo successivo
		p->getPunt();
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

void Naturale::Fact(){
}

/*int FATT(int n){
	if (n <= 1) return 1;
	else return n * FATT(n - 1);
}*/