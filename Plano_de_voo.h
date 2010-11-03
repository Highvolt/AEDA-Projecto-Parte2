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
	bool valid();
    Aviao *getAviao() const;
    horas_data getChegada() const;
    Companhia_aerea *getCompanhia() const;
    string getDestino() const;
    int getDo_voo() const;
    string getOrigem() const;
    horas_data getPartida() const;
    int getPassageiros() const;
    void setAviao(Aviao *aviao);
    void setChegada(horas_data chegada);
    void setCompanhia(Companhia_aerea *companhia);
    void setDestino(string destino);
    void setDo_voo(int n_do_voo);
    void setOrigem(string origem);
    void setPartida(horas_data partida);
    void setPassageiros(int n_passageiros);

};

#endif /* PLANO_DE_VOO_H_ */
