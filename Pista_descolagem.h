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


class operadordes{
public:
	bool operator()(const Plano_de_voo  ab, const Plano_de_voo  bb) const{
		return ab.getPartida()>bb.getPartida();

	}

};

class Pista_descolagem {
	int id;
	static int max_id;
	//vector<Plano_de_voo> pistav;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadordes> pista;
public:
	Pista_descolagem();
	virtual ~Pista_descolagem();
	vector<Plano_de_voo> get_lista();
	void levantou(Plano_de_voo a);
	void entrou_na_fila(Plano_de_voo a);
};

}

#endif /* PISTA_DESCOLAGEM_H_ */
