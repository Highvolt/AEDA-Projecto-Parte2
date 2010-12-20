/*
 * Pista_descolagem.cpp
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#include "Pista_descolagem.h"
#include <queue>
#include <vector>
#include "Plano_de_voo.h"

namespace std {

int Pista_descolagem::max_id=0;

Pista_descolagem::Pista_descolagem() {
	id=max_id++;

}

Pista_descolagem::~Pista_descolagem() {
	// TODO Auto-generated destructor stub
}


vector<Plano_de_voo*> Pista_descolagem::get_lista(){
	vector<Plano_de_voo*> temp;
	priority_queue<plano_descolagem> pista_t(pista);
	while(pista_t.size()!=0){
		temp.push_back(pista_t.top().get_p());
		pista_t.pop();
	}
	return temp;

}
void Pista_descolagem::levantou(Plano_de_voo* a){
	if(pista.size()!=0){


		if(pista.top().get_p()!=(a)){
			vector<Plano_de_voo*> temp=get_lista();
			priority_queue<plano_descolagem> pista_t;
			for(size_t i=0;i<temp.size();i++){
				if(temp[i]!=a){
					pista_t.push(plano_descolagem(temp[i]));
				}
			}
			pista=pista_t;
		}
		else{
			pista.pop();
		}
	}
}



void Pista_descolagem::entrou_na_fila(Plano_de_voo* a){
	pista.push(a);
}



}
