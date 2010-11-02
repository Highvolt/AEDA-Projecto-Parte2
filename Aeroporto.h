/*
 * Aeroporto.h
 *
 *  Created on: 1 de Nov de 2010
 *      Author: pedroborges
 */

#ifndef AEROPORTO_H_
#define AEROPORTO_H_

#include "Companhia.h"
#include <vector>
#include "Plano_de_voo.h"

namespace std {

class Aeroporto {
private:
	vector<Plano_de_voo*> planos;
	vector<Companhia_aerea*> companhias;

public:
	Aeroporto();
	virtual ~Aeroporto();
	bool add_plano();
	bool add_companhia();


};

}

#endif /* AEROPORTO_H_ */
