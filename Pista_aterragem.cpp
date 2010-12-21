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
/*
* creates a new landing strip
* @name Pista_aterragem
*/
Pista_aterragem::Pista_aterragem() {
	id=max_id++;

}

Pista_aterragem::~Pista_aterragem() {
	// TODO Auto-generated destructor stub
}

vector<Plano_de_voo> Pista_aterragem::get_lista(){
	vector<Plano_de_voo> temp;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadorat> pista_t(pista);


	while(!pista_t.empty() ){
		temp.push_back(pista_t.top());

		pista_t.pop();

	}
	return temp;


}
void Pista_aterragem::aterrou(Plano_de_voo a){
	if(pista.size()!=0){


		if(!(pista.top()==(a))){
			vector<Plano_de_voo> temp=get_lista();
			priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadorat> pista_t;
			for(size_t i=0;i<temp.size();i++){
				if(!(temp[i]==a)){
					pista_t.push(temp[i]);
				}
			}
			pista=pista_t;
		}
		else{
			pista.pop();
		}
	}
}



void Pista_aterragem::entrou_na_fila(Plano_de_voo a){
	//cout<<"ENTROU ATERRAGEM"<<a<<endl;
	pista.push(a);
}







}
