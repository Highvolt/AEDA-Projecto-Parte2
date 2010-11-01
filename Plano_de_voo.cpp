/*
 * Plano_de_voo.cpp
 *
 *  Created on: 28 de Out de 2010
 *      Author: pedroborges
 */

#include "Plano_de_voo.h"
using namespace std;


Plano_de_voo::Plano_de_voo(int hora_partida,int min_partida, int dia_partida, int mes_partida, int ano_partida, int hora_chegada,int min_chegada, int dia_chegada, int mes_chegada, int ano_chegada, Companhia_aerea* companhia, string origem, string destino, Aviao* aviao){
	this->partida.hora=hora_partida;
	this->partida.min=min_partida;
	this->partida.dia=dia_partida;
	this->partida.mes=mes_partida;
	this->partida.ano=ano_partida;
}

Plano_de_voo::~Plano_de_voo() {
	// TODO Auto-generated destructor stub
}
