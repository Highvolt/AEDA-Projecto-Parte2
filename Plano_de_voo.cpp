/*
 * Plano_de_voo.cpp
 *
 *  Created on: 28 de Out de 2010
 *      Author: pedroborges
 */

#include "Plano_de_voo.h"
using namespace std;


void set_horas(int hora,int min, int dia, int mes, int ano, horas_data* dest){
	if(hora>=0 && min>=0 && hora<24 && min>60 &&mes>0 && mes<=12 && ano>0){
		dest->hora=hora;
		dest->min=min;
		switch(mes){
		case 1 || 3 || 5 || 7 || 8 ||10 || 12: if(dia<=31){dest->dia=dia;}else{dest->dia=-1;} break;
		case 2: if(ano%4.0==0){
			if(ano%100==0){
				if(ano%400==0){
					if(dia<=29)
						dest->dia=dia;
				}
				else{dest->dia=-1;}
			}
			if(dia<=29)
				dest->dia=dia;
		}else{
			if(dia<29)
				dest->dia=dia;
			else{
				dest->dia=-1;
			}
		}
		break;
		default: if(dia<=30){dest->dia=dia;}else{dest->dia=-1;}
		}
		dest->mes=mes;
		dest->ano=ano;
	}
}

Plano_de_voo::Plano_de_voo(int hora_partida,int min_partida, int dia_partida, int mes_partida, int ano_partida, int hora_chegada,int min_chegada, int dia_chegada, int mes_chegada, int ano_chegada, Companhia_aerea* companhia, string origem, string destino, Aviao* aviao){
	set_horas(hora_partida,min_partida,dia_partida,mes_partida,ano_partida,&partida);
	set_horas(hora_chegada,min_chegada,dia_chegada,mes_chegada,ano_chegada,&chegada);
	this->companhia=companhia;
	this->origem=origem;
	this->destino=destino;
	this->aviao=aviao;
}

bool Plano_de_voo::valid(){
	if(this->partida.hora!=-1 && this->partida.min!=-1 && this->partida.dia!=-1 && this->partida.mes!=-1 && this->partida.ano!=-1 && this->chegada.hora!=-1 && this->chegada.min!=-1 && this->chegada.dia!=-1 && this->chegada.mes!=-1 && this->chegada.ano!=-1){
		return true;
	}
	return false;
}



Plano_de_voo::~Plano_de_voo() {
	// TODO Auto-generated destructor stub
}
