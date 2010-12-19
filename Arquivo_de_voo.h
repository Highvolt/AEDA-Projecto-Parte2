/*
 * Arquivo_de_voo.h
 *
 *  Created on: 18 de Dez de 2010
 *      Author: pedroborges
 */

#include "BST.h"
#include "Plano_de_voo.h"
#ifndef ARQUIVO_DE_VOO_H_
#define ARQUIVO_DE_VOO_H_
Plano_de_voo PNULL=Plano_de_voo(0,0,0, 0, 0, 0,0,0,0,0, NULL, "","", NULL, 0);

namespace std {

class Arquivo_de_voo {
	BST<Plano_de_voo> arquivo;

public:
	Arquivo_de_voo():arquivo(PNULL){

	}
	void insert(Plano_de_voo & a);
	void remove(Plano_de_voo & a);
	virtual ~Arquivo_de_voo();
};

}

#endif /* ARQUIVO_DE_VOO_H_ */
