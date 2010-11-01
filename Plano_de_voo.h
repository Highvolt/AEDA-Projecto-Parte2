/*
 * Plano_de_voo.h
 *
 *  Created on: 28 de Out de 2010
 *      Author: pedroborges
 */

#ifndef PLANO_DE_VOO_H_
#define PLANO_DE_VOO_H_


#include "Companhia.h"
struct horas_data{
	int hora;
	int min;
	int dia;
	int mes;
	int ano;
};


class Plano_de_voo {
private:
	horas_data partida;
	horas_data chegada;
	int n_do_voo;
	string origem;
	string destino;
	Aviao* aviao;
	Companhia_aerea* companhia;
	int n_passageiros;

public:
	Plano_de_voo(int hora_partida,int min_partida, int dia_partida, int mes_partida, int ano_partida, int hora_chegada,int min_chegada, int dia_chegada, int mes_chegada, int ano_chegada, Companhia_aerea* companhia, string origem, string destino, Aviao* aviao);
	virtual ~Plano_de_voo();
};

#endif /* PLANO_DE_VOO_H_ */
