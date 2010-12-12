/*
 * Pista_descolagem.h
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#ifndef PISTA_DESCOLAGEM_H_
#define PISTA_DESCOLAGEM_H_
#include <queue>
#include <vector>
#include "Plano_de_voo.h"



namespace std {
class plano_descolagem{
	Plano_de_voo *a;
public:
	Plano_de_voo* get_p()const{
		return a;
	}
	plano_descolagem(Plano_de_voo *a){
		this->a=a;
	}
	bool operator<(const plano_descolagem &b) const{
		return this->a->a_chega_pr_b(*(this->a),*(b.get_p()));
	}
};

class Pista_descolagem {
	int id;
	static int max_id;
	priority_queue<plano_descolagem> pista;
public:
	Pista_descolagem();
	virtual ~Pista_descolagem();
	vector<Plano_de_voo*> get_lista();
	void levantou(Plano_de_voo* a);
	void entrou_na_fila(Plano_de_voo* a);
};

}

#endif /* PISTA_DESCOLAGEM_H_ */
