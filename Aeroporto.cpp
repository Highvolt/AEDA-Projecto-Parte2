/*
 * Aeroporto.cpp
 *
 *  Created on: 1 de Nov de 2010
 *      Author: pedroborges
 */

#include "Aeroporto.h"

using namespace std;

Aeroporto::Aeroporto() {


}

Aeroporto::~Aeroporto() {
	// TODO Auto-generated destructor stub
}

bool Aeroporto::existe_pv_aviao(Companhia_aerea* companhia, Aviao* aviao){
	for(size_t i=0; i<planos.size(); i++){
		if(*(planos[i]->getAviao())==*aviao && *(planos[i]->getCompanhia())==*companhia){
			return true;

		}
	}
	return false;
}
