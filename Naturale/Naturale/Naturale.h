#pragma once
#include"lista.h"
#include"lista.cpp"
#include"Nodo.h"
#include"Nodo.cpp"
#include<iostream>

class Naturale{
	friend istream & operator>>(istream&, Naturale&);
	friend ostream & operator<<(ostream&, Naturale&);
	//friend void operator +(Naturale&, Naturale&);
	//friend void operator *(Naturale&, Naturale);
	//friend void operator ^(Naturale&, Naturale);
	//friend void operator +=(Naturale&);

private:
	Lista <int>numero;

public:
	Naturale();
	//void operator ++(int);
	//void operator --(int);
	void Zero();
	bool Is_Zero();
	void Fact();
	~Naturale();
};

