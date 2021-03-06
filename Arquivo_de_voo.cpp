/*
 * Arquivo_de_voo.cpp
 *
 *  Created on: 18 de Dez de 2010
 *      Author: pedroborges
 */

#include "Arquivo_de_voo.h"

using namespace std;


Plano_de_voo PNULL=Plano_de_voo(0,0,0, 0, 0, 0,0,0,0,0, NULL, "","", NULL, 0);

/**
 * creates a new flight archive
 * @name Arquivo_de_voo
 */
Arquivo_de_voo::Arquivo_de_voo():arquivo(PNULL){

}

void Arquivo_de_voo::insert(Plano_de_voo & a){
	if(arquivo.isEmpty()){

		arquivo.insert(a);

	}
	else{

		Plano_de_voo pesq=arquivo.find(a);
		if(pesq==PNULL){
			arquivo.insert(a);
		}

	}
}

void Arquivo_de_voo::remove(Plano_de_voo & a){
	Plano_de_voo pesq=arquivo.find(a);
	if(!(pesq==PNULL)){
		arquivo.remove(a);
	}


}

vector<Plano_de_voo> Arquivo_de_voo::pesquisa(horas_data d1, horas_data d2){
	vector<Plano_de_voo> planos;
	BSTItrIn<Plano_de_voo> itr(arquivo);
	while((! itr.isAtEnd()) ){
		Plano_de_voo actual=itr.retrieve();

		if(actual.get_parte()){
			if(actual.getPartida()>d2){
				return planos;
			}
			if(!(actual.getPartida()<d1)){
				planos.push_back(actual);
			}
		}
		else{
			if(actual.getChegada()>d2){
				return planos;
			}
			if(!(actual.getChegada()<d1)){
				planos.push_back(actual);
			}
		}
		itr.advance();
	}

	return planos;
}

vector<Plano_de_voo> Arquivo_de_voo::pesquisa(horas_data d1, horas_data d2, Companhia_aerea * comp){
	vector<Plano_de_voo> planos;
	BSTItrIn<Plano_de_voo> itr(arquivo);
	while((! itr.isAtEnd()) ){
		Plano_de_voo actual=itr.retrieve();

		if(actual.get_parte()){
			if(actual.getPartida()>d2){
				return planos;
			}
			if(!(actual.getPartida()<d1) && actual.getCompanhia()==comp){
				planos.push_back(actual);
			}
		}
		else{
			if(actual.getChegada()>d2){
				return planos;
			}
			if(!(actual.getChegada()<d1) && actual.getCompanhia()==comp){
				planos.push_back(actual);
			}
		}
		itr.advance();
	}

	return planos;
}


vector<Plano_de_voo> Arquivo_de_voo::pesquisa(Companhia_aerea * comp){
	vector<Plano_de_voo> planos;
	BSTItrIn<Plano_de_voo> itr(arquivo);
	while((! itr.isAtEnd()) ){
		Plano_de_voo actual=itr.retrieve();


			if(actual.getCompanhia()==comp){
				planos.push_back(actual);
			}

		itr.advance();
	}

	return planos;
}




Arquivo_de_voo::~Arquivo_de_voo() {
	// TODO Auto-generated destructor stub
}


