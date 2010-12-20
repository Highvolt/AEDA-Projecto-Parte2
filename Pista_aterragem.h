/*
 * Pista_aterragem.h
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#ifndef PISTA_ATERRAGEM_H_
#define PISTA_ATERRAGEM_H_
#include <queue>
#include <vector>
#include "Plano_de_voo.h"


namespace std {

class operadorat{
public:
	bool operator()(const Plano_de_voo  a, const Plano_de_voo  b) const{
		return (a.getChegada()>b.getChegada());
	}
};

class Pista_aterragem {
	int id;
	static int max_id;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadorat> pista;
public:
	Pista_aterragem();
	virtual ~Pista_aterragem();
	vector<Plano_de_voo> get_lista();
	void aterrou(Plano_de_voo a);
	void entrou_na_fila(Plano_de_voo a);
};

}

#endif /* PISTA_ATERRAGEM_H_ */
