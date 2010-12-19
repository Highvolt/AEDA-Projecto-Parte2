
#include "Plano_de_voo.h"
using namespace std;


void set_horas(int hora,int min, int dia, int mes, int ano, horas_data* dest){
	if(hora>=0 && min>=0 && hora<24 && min<60 &&mes>0 && mes<=12 && ano>0){
		dest->hora=hora;
		dest->min=min;
		switch(mes){
		case 1 || 3 || 5 || 7 || 8 ||10 || 12: if(dia<=31){dest->dia=dia;}else{dest->dia=-1;} break;
		case 2: if(ano%4==0){
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
	else{
		dest->hora=dest->mes=dest->min=dest->ano=dest->dia=-1;
	}
}

/**
 * class constructor that creates a flight  plan
 *
 * @param int hora_partida
 * @param int min_partida
 * @param int dia_partida
 * @param int mes_partida
 * @param int ano_partida
 * @param int hora_chegada
 * @param int min_chegada
 * @param int dia_chegada
 * @param int mes_chegada
 * @param int ano_chegada
 * @param Companhia_aerea* companhia
 * @param string origem
 * @param string destino
 * @param Aviao* aviao
 * @param int n_passageiros
 */
Plano_de_voo::Plano_de_voo(int hora_partida,int min_partida, int dia_partida, int mes_partida, int ano_partida, int hora_chegada,int min_chegada, int dia_chegada, int mes_chegada, int ano_chegada, Companhia_aerea* companhia, string origem, string destino, Aviao* aviao,int n_passageiros){
	set_horas(hora_partida,min_partida,dia_partida,mes_partida,ano_partida,&partida);
	set_horas(hora_chegada,min_chegada,dia_chegada,mes_chegada,ano_chegada,&chegada);
	this->companhia=companhia;
	this->origem=origem;
	this->destino=destino;
	this->aviao=aviao;

	this->n_passageiros=n_passageiros;
	this->arquivado=false;
	this->pista=false;
}

Aviao *Plano_de_voo::getAviao() const
{
	return aviao;
}

horas_data Plano_de_voo::getChegada() const
{
	return chegada;
}

Companhia_aerea *Plano_de_voo::getCompanhia() const
{
	return companhia;
}

string Plano_de_voo::getDestino() const
{
	return destino;
}

int Plano_de_voo::getDo_voo() const
{
	return n_do_voo;
}

string Plano_de_voo::getOrigem() const
{
	return origem;
}

horas_data Plano_de_voo::getPartida() const
{
	return partida;
}

int Plano_de_voo::getPassageiros() const
{
	return n_passageiros;
}

void Plano_de_voo::setAviao(Aviao *aviao)
{
	this->aviao = aviao;
}

void Plano_de_voo::setChegada(horas_data chegada)
{
	this->chegada = chegada;
}

void Plano_de_voo::setCompanhia(Companhia_aerea *companhia)
{
	this->companhia = companhia;
}

void Plano_de_voo::setDestino(string destino)
{
	this->destino = destino;
}

void Plano_de_voo::setDo_voo(int n_do_voo)
{
	this->n_do_voo = n_do_voo;
}

void Plano_de_voo::setOrigem(string origem)
{
	this->origem = origem;
}

void Plano_de_voo::setPartida(horas_data partida)
{
	this->partida = partida;
}

void Plano_de_voo::setPassageiros(int n_passageiros)
{
	this->n_passageiros = n_passageiros;
}

/**
 * Function that allow us to know if the flight plan is valid or not
 * @name valid
 * @return 0 if the flight plan is valid and 1 if it isn't
 */
bool Plano_de_voo::valid(){
	if(this->partida.hora!=-1 && this->partida.min!=-1 && this->partida.dia!=-1 && this->partida.mes!=-1 && this->partida.ano!=-1 && this->chegada.hora!=-1 && this->chegada.min!=-1 && this->chegada.dia!=-1 && this->chegada.mes!=-1 && this->chegada.ano!=-1){
		return true;
	}
	return false;
}


/**
 * class destructor
 * @name ~Plano_de_voo
 */
Plano_de_voo::~Plano_de_voo() {
	// TODO Auto-generated destructor stub
}
