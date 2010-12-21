/*
 * passageiro.cpp
 *
 *  Created on: 13 de Dez de 2010
 *      Author: pedroborges
 */

#include "passageiro.h"

using namespace std;

passageiro::passageiro(string nome, unsigned long int n_BI) {
	this->n_BI=n_BI;
	this->name=nome;
	this->viagens_realizadas=vector<Plano_de_voo>();

}

passageiro::passageiro(string nome, unsigned long int n_BI, vector<Plano_de_voo> via){
	this->n_BI=n_BI;
	this->name=nome;
	this->viagens_realizadas=via;
}

void passageiro::adicionar_voo(Plano_de_voo  a){
	for(vector<Plano_de_voo>::iterator it=this->viagens_realizadas.begin();it!=this->viagens_realizadas.end();it++){
		if(a==*it){
			//excecp‹o
		}
	}
	this->viagens_realizadas.push_back(a);

}



passageiro::~passageiro() {
	// TODO Auto-generated destructor stub
}

Passageiro_tb::Passageiro_tb(){


}
Passageiro_tb::Passageiro_tb(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas){
	passageiro tmp(nome,BI,viagens_realizadas);
	tabela.insert(tmp);

}
void Passageiro_tb::insert(passageiro & a){
	tabelap::iterator it=tabela.find(a);
	if(it==tabela.end()){
		tabela.insert(a);
	}
	else{
		//excepcao

	}
}

void Passageiro_tb::insert(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas){
	passageiro a(nome,BI,viagens_realizadas);
	tabelap::iterator it=tabela.find(a);
	if(it==tabela.end()){
		tabela.insert(a);
	}
	else{
		//excepcao

	}

}
passageiro Passageiro_tb::find(passageiro & a){

	tabelap::iterator it=tabela.find(a);
	if(it==tabela.end()){
		//not found - excepcao

	}
	return *it;
}
void Passageiro_tb::deletep(passageiro & a){

	tabelap::iterator it=tabela.find(a);
	if(it==tabela.end()){
		//not found - excepcao

	}
	tabela.erase(it);
}

