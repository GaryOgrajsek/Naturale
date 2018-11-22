#include "lista.h"
#include<iostream>
using namespace std;

/*Lista operator +(Lista uno, Lista due) {
cout << "no";
}*/

//implementare stack con i puntatori e lista
template <class tipo>
Lista<tipo> Merge(const Lista<tipo> & uno, const Lista<tipo> & due) {
	Lista tre;
	Nodo<tipo> *p1 = uno.L;
	Nodo<tipo> *p2 = due.L;
	while (p1->getPunt() != 0 && p2->getPunt() != 0) {
		if (p1->getInfo() >= p2->getInfo()) {
			tre.InserisciInCoda(p2->getInfo());
			p2 = p2->getPunt();
		}
		else {
			tre.InserisciInCoda(p1->getInfo());
			p1 = p1->getPunt();
		}
	}
	while (p1 != 0) {
		tre.InserisciInCoda(p1->getInfo());
		p1 = p1->getPunt();
	}
	while (p2 != 0) {
		tre.InserisciInCoda(p2->getInfo());
		p2 = p2->getPunt();
	}
	return tre;
}

template <class tipo>
Lista<tipo>::Lista() {
	L = 0; //se la lista è nuova, L non punta a niente.
}

template <class tipo>
void Lista<tipo>::InserisciInTesta(tipo x) {
	Nodo<tipo> *P = new Nodo<tipo>(x); //parte costruttore nodo che mette 0 a punt e x a info
	P->setPunt(L);
	L = P;
}

template <class tipo>
void Lista<tipo>::InserisciInCoda(tipo x) {
	Nodo<tipo> *p = L;
	Nodo<tipo> *temp = new Nodo<tipo>(x);

	if (L != 0) {
		while (p->getPunt() != 0) {
			p = p->getPunt();
		}

		p->setPunt(temp);
		temp->setPunt(0);
	}
	else
		L = temp;
}

template <class tipo>
void Lista<tipo>::InserisciOrdinato(tipo x) {
	Nodo<tipo> *p = new Nodo<tipo>(x);

	if (L == 0 || x < L->getInfo()) {
		p->setPunt(L);
		L = p;
	}
	else {
		Nodo<tipo> *prec, *succ;
		succ = L;
		prec = 0;
		while (x > succ->getInfo() && succ->getPunt() != 0) {
			prec = succ;
			succ = succ->getPunt();
		}
		if (x > prec->getInfo() && x < succ->getInfo()) {
			prec->setPunt(p);
			p->setPunt(succ);
		}
		else {
			succ->setPunt(p);
		}
	}
}

template <class tipo>
void Lista<tipo>::Visualizza() {
	Nodo<tipo> *P = L;
	while (P != 0) { //così sennò non visualizza l'ultimo. E supera l'ultimo.
		cout << P->getInfo();
		P = P->getPunt();
	}
}

template <class tipo>
void Lista<tipo>::VisualizzaNonOrdinato() {
	Nodo<tipo> *p = L;
	while (Controlla(p)) {
		cout << p->getInfo();
		p = p->getPunt();
	}
}

template <class tipo>
bool Lista<tipo>::Controlla(Nodo<tipo>* q) {
	Nodo<tipo>* p = L;
	while (p != q && p != q->getPunt()) {
		p = p->getPunt();
	}
	return (p != q->getPunt());
}

template <class tipo>
void Lista<tipo>::Elimina(tipo x) {
	Nodo<tipo> *succ, *prec;
	succ = L;
	prec = NULL;
	while (succ != 0 && succ->getInfo() != x) {
		prec = succ;
		succ = succ->getPunt();
	}
	if (succ != 0) {
		if (succ == L) {
			L = L->getPunt();
		}
		else {
			prec->setPunt(succ->getPunt());
		}
		delete succ;
	}
}

template <class tipo>
void Lista<tipo>::EliminaTesta() {
	Nodo<tipo> *P = L;
	if (P->getPunt() != 0) {
		L = P->getPunt();
		delete P;
	}
}

template <class tipo>
void Lista<tipo>::Modifica(tipo prima, tipo dopo) {
	Nodo<tipo> *p;
	p = L;
	if (L != 0) {
		while (p != 0) {
			if (p->getInfo() == prima) {
				p->setInfo(dopo);
				break;
			}
			else {
				p = p->getPunt();
			}
		}
	}
}

template <class tipo>
Nodo<tipo>* Lista<tipo>::Ricerca(tipo x) {
	Nodo<tipo> *succ, *prec;
	succ = L;
	prec = NULL;
	if (L == 0) {
		cout << "Lista vuota.";
	}
	else {
		while (succ != 0 && succ->getInfo() != x) {
			prec = succ;
			succ = succ->getPunt();
		}
		return prec;
	}
}

template <class tipo>
void Lista<tipo>::Inverti() {
	Nodo<tipo> *succ = L;
	Nodo<tipo> *prec = 0;
	Nodo<tipo> *tmp = NULL;
	while (succ != 0) {
		tmp = succ->getPunt();
		succ->setPunt(prec);
		L = succ;
		prec = succ;
		succ = tmp;
	}
}

template <class tipo>
bool Lista<tipo>::ControllaSeZero() {
	return (L->getInfo() == 0 && L->getPunt() == 0);
}

template <class tipo>
void Lista<tipo>::Azzera() {
	Nodo<tipo>* P = L;
	while (P->getPunt() != 0) {
		EliminaTesta();
	}
	P->setInfo(0);
}

template<class tipo>
Nodo<tipo>* Lista<tipo>::GetElle() {
	return L;
}

template<class tipo>
void Lista<tipo>::Riduci() {
	Nodo<tipo>* P = L;
	while (P->getPunt != 0) {
		P = P->getPunt();
	}
	P->setInfo(P->getInfo() - 1);
}

template <class tipo>
Lista<tipo>::~Lista() {
}