/*
 * Pista_descolagem.cpp
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#include "Pista_descolagem.h"
#include <algorithm>
#include <queue>
#include <vector>
#include "Plano_de_voo.h"
#include <climits>

namespace std {

int Pista_descolagem::max_id=0;

Pista_descolagem::Pista_descolagem() {
	id=max_id++;

}

Pista_descolagem::~Pista_descolagem() {
	// TODO Auto-generated destructor stub
}


vector<Plano_de_voo> Pista_descolagem::get_lista(){

	//sort_heap(pistav.begin(),pistav.end());
	vector<Plano_de_voo> temp;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadordes> pista_t(pista);
//	for(vector<Plano_de_voo>::iterator it=pistav.begin();it!=pistav.end();it++){
//		pista_t.push((*it));
//		cout<<*it<<endl;
//	}
//	Plano_de_voo PNULL=Plano_de_voo(INT_MAX,INT_MAX,INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX, NULL, "","", NULL, INT_MAX);
//	Plano_de_voo PNULL2=Plano_de_voo(0,0,0, 0, 0, 0,0,0,0,0, NULL, "","", NULL, 0);
	//pista_t.push(&PNULL2);
	//pista_t.pop();

	while(!pista_t.empty() ){
		temp.push_back(pista_t.top());

		pista_t.pop();
		//pista_t.push(&PNULL);
	}
	return temp;

//	vector<Plano_de_voo*> temp;
//
//	priority_queue<Plano_de_voo*,vector<Plano_de_voo*>,operadordes> pista_t(pista);
//
//	while(!pista_t.empty()){
//		cout<<"ciclo - "<<pista_t.size()<<endl;
//		temp.push_back(pista_t.top());
//		cout<<*temp[temp.size()-1]<<endl;
//		pista_t.pop();
//	}
//	return temp;

}
void Pista_descolagem::levantou(Plano_de_voo a){
	if(pista.size()!=0){


		if(!(pista.top()==(a))){
			vector<Plano_de_voo> temp=get_lista();
			priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadordes> pista_t;
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



void Pista_descolagem::entrou_na_fila(Plano_de_voo a){
	cout<<"ENTROU DESCOLAGEM"<<a<<endl;
	pista.push(a);
	//pistav.push_back(a);
	//cout<<pistav.size()<<endl;

	//cout<<*pista.top()<<endl;
}



}
