/*
 * Pista_aterragem.cpp
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#include "Pista_aterragem.h"
#include <vector>
#include "Plano_de_voo.h"
namespace std {

int Pista_aterragem::max_id=0;

Pista_aterragem::Pista_aterragem() {
	id=max_id++;

}

Pista_aterragem::~Pista_aterragem() {
	// TODO Auto-generated destructor stub
}

vector<Plano_de_voo*> Pista_aterragem::get_lista(){
	vector<Plano_de_voo*> temp;
	priority_queue<plano_aterragem> pista_t(pista);
	while(pista_t.size()!=0){
		temp.push_back(pista_t.top().get_p());
		pista_t.pop();
	}
	return temp;

}
void Pista_aterragem::aterrou(Plano_de_voo* a){
	if(pista.size()!=0){

		//excepcao
		if(pista.top().get_p()==(a)){
			vector<Plano_de_voo*> temp(temp);
			priority_queue<plano_aterragem> pista_t(pista);
			for(size_t i=0;i<temp.size();i++){
				if(temp[i]==a){
					pista_t.push(plano_aterragem(temp[i]));
				}
			}
		}
	}
}



void Pista_aterragem::entrou_na_fila(Plano_de_voo* a){
	pista.push(a);
}







}
