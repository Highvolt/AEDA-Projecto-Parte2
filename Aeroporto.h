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
	bool delete_plane(Companhia_aerea* companhia, Aviao* aviao); // procurar todos os planos de voo com o aviao x e apaga-los avisando o utilizador que vai apagar planos de voo se continuar...
	bool existe_pv_aviao(Companhia_aerea* companhia, Aviao* aviao);  //devolve true se existir pelo menos um plano de voo com o Aviao aviao
	bool apaga_pv_aviao(Companhia_aerea* companhia, Aviao* aviao); //devolve true se apagar

};

}

#endif /* AEROPORTO_H_ */
