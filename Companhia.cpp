/*
 * Voos.cpp
 *
 *  Created on: 10 de Out de 2010
 *      Author: pedroborges
 */

#include "Companhia.h"

using namespace std;



Aviao::Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria): Tipo_de_aviao::Tipo_de_aviao(tipo,descricao,categoria){
	this->matricula=matricula;
	this->nome=nome;
	this->peso=peso;
}

/**
 * class constructor for a airplane type
 * @name Tipo_de_aviao
 * @param string tipo
 * @param string descricao
 * @param string categoria
 *
 */
Tipo_de_aviao::Tipo_de_aviao(string tipo, string descricao, string categoria){
	this->tipo=tipo;
	this->descricao=descricao;
	this->categoria=categoria;
}

string Tripulante::getCategoria() const
{
    return categoria;
}

string Tripulante::getNome() const
{
    return nome;
}

int Tripulante::getNumero() const
{
    return numero;
}

int Tripulante::getSalario_hora() const
{
    return salario_hora;
}

void Tripulante::setCategoria(string categoria)
{
    this->categoria = categoria;
}

void Tripulante::setNome(string nome)
{
    this->nome = nome;
}

void Tripulante::setNumero(int numero)
{
    this->numero = numero;
}

void Tripulante::setSalario_hora(int salario_hora)
{
    this->salario_hora = salario_hora;
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

vector<string> Companhia_aerea::getPlanesnames(){
	vector<string> names;
	for(size_t i=0; i<avioes.size();i++){
		names.push_back(avioes[i].getNome());
	}
	return names;
}

int Companhia_aerea::add_plane(Aviao aviao){
	for(vector<Aviao>::iterator it=avioes.begin(); it<avioes.end(); it++){
		if(*it==aviao){
			throw aviao_ja_existe(&aviao);
			return -1;
		}
	}
	avioes.push_back(aviao);
	return 0;
}

int Companhia_aerea::delete_plane(Aviao aviao){
	for(vector<Aviao>::iterator it=avioes.begin(); it<avioes.end(); it++){
		if(*it==aviao){
			avioes.erase(it);
			return 0;
		}
	}
	throw aviao_nao_existe(&aviao);
	return -1;
}


int Companhia_aerea::delete_plane(int i){ //confirmar resultado
	if(i<avioes.size()){
		vector<Aviao>::iterator it=avioes.begin();
		for(;i>0;it++){
		--i;
		}
		avioes.erase(it);
		return 0;
	}


	return -1;
}

int Companhia_aerea::add_crew(Tripulante tripulante){
	for(vector<Tripulante>::iterator it=tripulantes.begin(); it<tripulantes.end(); it++){
		if(*it==tripulante){
			throw trip_ja_existe(&tripulante);
			return -1;
		}
	}
	tripulantes.push_back(tripulante);

	return 0;
}

vector<Aviao> Companhia_aerea::getAvioes() const
{
    return avioes;
}

string Companhia_aerea::getSigla() const
{
    return sigla;
}

vector<Tripulante> Companhia_aerea::getTripulantes() const
{
    return tripulantes;
}

void Companhia_aerea::setAvioes(vector<Aviao> avioes)
{
    this->avioes = avioes;
}

void Companhia_aerea::setSigla(string sigla)
{
    this->sigla = sigla;
}

void Companhia_aerea::setTripulantes(vector<Tripulante> tripulantes)
{
    this->tripulantes = tripulantes;
}

int Companhia_aerea::delete_crew(int i){  //confirmar resultado
	if(i<tripulantes.size()){
		vector<Tripulante>::iterator it=tripulantes.begin();
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
	for(vector<Tripulante>::iterator it=tripulantes.begin(); it<tripulantes.end(); it++){
		if(*it==tripulante){
			tripulantes.erase(it);
			return 0;
		}
	}
	//adicionar gest‹o de erros
	return -1;
}
