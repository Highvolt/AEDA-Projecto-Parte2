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

class plano_aterragem{
	Plano_de_voo *a;
public:
	Plano_de_voo* get_p()const{
		return a;
	}
	plano_aterragem(Plano_de_voo *a){
		this->a=a;
	}
	bool operator<(const plano_aterragem &b) const{
		return this->a->a_chega_pr_b(*(this->a),*(b.get_p()));
	}
};

class Pista_aterragem {
	int id;
	static int max_id;
	priority_queue<plano_aterragem> pista;
public:
	Pista_aterragem();
	virtual ~Pista_aterragem();
	vector<Plano_de_voo*> get_lista();
	void aterrou(Plano_de_voo* a);
	void entrou_na_fila(Plano_de_voo* a);
};

}

#endif /* PISTA_ATERRAGEM_H_ */
