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

Tripulantes::Tripulantes(int numero, string categoria, string nome, int salario_hora){
	this->numero=numero;
	this->categoria=categoria;
	this->nome=nome;
	this->salario_hora=salario_hora;
}

Companhia_aerea::Companhia_aerea(string &sigla, string &nme_companhia){
	this->sigla=sigla;
	this->nme_companhia=nme_companhia;
}

void Companhia_aerea::add_plane(Aviao aviao){

	avioes.push_back(&aviao);
}


