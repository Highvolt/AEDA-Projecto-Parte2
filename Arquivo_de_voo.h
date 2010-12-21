/*
 * Arquivo_de_voo.h
 *
 *  Created on: 18 de Dez de 2010
 *      Author: pedroborges
 */


#include <iostream>
#include "BST.h"
#include "Plano_de_voo.h"
#include "Companhia.h"
#ifndef ARQUIVO_DE_VOO_H_
#define ARQUIVO_DE_VOO_H_


namespace std {

class Arquivo_de_voo {
	BST<Plano_de_voo> arquivo;

public:
	Arquivo_de_voo();
	void insert(Plano_de_voo & a);
	void remove(Plano_de_voo & a);
	vector<Plano_de_voo> pesquisa(horas_data d1, horas_data d2);
	vector<Plano_de_voo> pesquisa(horas_data d1, horas_data d2, Companhia_aerea * comp);
	vector<Plano_de_voo> pesquisa(Companhia_aerea * comp);
	virtual ~Arquivo_de_voo();

	friend ostream & operator<<(ostream & out, Arquivo_de_voo x) {
		BSTItrIn<Plano_de_voo> itr(x.arquivo);

		for(;!(itr.isAtEnd());itr.advance()){
			Plano_de_voo temp=itr.retrieve();
			out<<temp<<endl;
		}

		return out;
	}
};

}

#endif /* ARQUIVO_DE_VOO_H_ */
