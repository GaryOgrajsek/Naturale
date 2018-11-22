#pragma once
#include"Nodo.h"
template<class tipo>
class Lista {
	//friend Lista operator +(Lista &, Lista &); //mantieni ordine DA FARE
	friend Lista<tipo> Merge(const Lista &, const Lista &);
private:
	Nodo<tipo> * L;
public:
	Lista();
	void InserisciInTesta(tipo);
	void InserisciInCoda(tipo);
	void InserisciOrdinato(tipo); //ordine crescente
	void Modifica(tipo, tipo);
	Nodo<tipo> * Ricerca(tipo); //	ricerca un dato e restituisce il puntatore al nodo precedente quello che contiene il dato cercato
	void Visualizza();
	void VisualizzaNonOrdinato();
	bool Controlla(Nodo<tipo>*);
	void Elimina(tipo);
	void EliminaTesta();
	void Inverti();
	bool ControllaSeZero();
	void Azzera();
	Nodo<tipo>* GetElle();
	void Riduci();
	~Lista();
};

