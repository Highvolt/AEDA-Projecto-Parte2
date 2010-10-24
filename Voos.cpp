/*
 * Voos.cpp
 *
 *  Created on: 10 de Out de 2010
 *      Author: pedroborges
 */

#include "Voos.h"

using namespace std;

Voos::Voos() {
	// TODO Auto-generated constructor stub

}

Voos::~Voos() {
	// TODO Auto-generated destructor stub
}



Aviao::Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria): Tipo_de_aviao::Tipo_de_aviao(tipo,descricao,categoria){
	this->matricula=matricula;
	this->nome=nome;
	this->peso=peso;
}

Tipo_de_aviao::Tipo_de_aviao(string tipo, string descricao, string categoria){
	this->tipo=tipo;
	this->descricao=descricao;
	this->categoria=categoria;
}

Tripulante::Tripulante(int numero, string categoria, string nome, int salario_hora){
	this->numero=numero;
	this->categoria=categoria;
	this->nome=nome;
	this->salario_hora=salario_hora;
}

Companhia_aerea::Companhia_aerea(string &sigla, string &nme_companhia){
	this->sigla=sigla;
	this->nme_companhia=nme_companhia;
}

int Companhia_aerea::add_plane(Aviao aviao){
	for(vector<Aviao*>::iterator it=avioes.begin(); it<avioes.end(); it++){
		if(**it==aviao){
			//adicionar gestao de erros
			return -1;
		}
	}
	avioes.push_back(&aviao);
	return 0;
}

int Companhia_aerea::delete_plane(Aviao aviao){
	for(vector<Aviao*>::iterator it=avioes.begin(); it<avioes.end(); it++){
		if(**it==aviao){
			avioes.erase(it);
			return 0;
		}
	}
	//adicionar gest‹o de erros
	return -1;
}


int Companhia_aerea::delete_plane(int i){ //confirmar resultado
	if(i<avioes.size()){
		vector<Aviao*>::iterator it=avioes.begin();
		for(;i>0;it++){
		--i;
		}
		avioes.erase(it);
		return 0;
	}

	//adicionar gest‹o de erros
	return -1;
}

int Companhia_aerea::add_crew(Tripulante tripulante){
	for(vector<Tripulante*>::iterator it=tripulantes.begin(); it<tripulantes.end(); it++){
		if(**it==tripulante){
			//adicionar gest‹o de erros
			return -1;
		}
	}

	return 0;
}

int Companhia_aerea::delete_crew(int i){  //confirmar resultado
	if(i<tripulantes.size()){
		vector<Tripulante*>::iterator it=tripulantes.begin();
		for(;i>0;it++){
		--i;
		}
		tripulantes.erase(it);
		return 0;
	}

	//adicionar gest‹o de erros
	return -1;
}

int Companhia_aerea::delete_crew(Tripulante tripulante){
	for(vector<Tripulante*>::iterator it=tripulantes.begin(); it<tripulantes.end(); it++){
		if(**it==tripulante){
			tripulantes.erase(it);
			return 0;
		}
	}
	//adicionar gest‹o de erros
	return -1;
}
