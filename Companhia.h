/*
 * Voos.h
 *
 *  Created on: 10 de Out de 2010
 *      Author: pedroborges
 */

#ifndef COMPANHIA_H_
#define COMPANHIA_H_
#include <vector>
#include <string>

using namespace std;

class Tripulante;
class Aviao;



class Companhia_aerea{
private:
	vector<Tripulante*> tripulantes;
	vector<Aviao*> avioes;
	string sigla, nme_companhia;
public:
	Companhia_aerea(string & sigla, string & nme_companhia);
	int add_plane(Aviao aviao);
	int delete_plane(Aviao aviao);
	int delete_plane(int i);
	int add_crew(Tripulante tripulante);
	int delete_crew(Tripulante tripulante);
	int delete_crew(int i);

};




class Tripulante{
private:
	int numero;
	int salario_hora;
	string categoria;
	string nome;

public:
	Tripulante(int numero, string categoria, string nome, int salario_hora);
	bool operator==(const Tripulante &b){
		return this->numero==b.numero;
	}

};

class Tipo_de_aviao{
private:
	string tipo;
	string descricao;
	string categoria;
public:
	Tipo_de_aviao(string tipo, string descricao, string categoria);
};

class Aviao: public Tipo_de_aviao{
private:
	string matricula;
	string nome;
	int peso;

public:
	Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria);
	bool operator==(const Aviao &b){
		return this->matricula==b.matricula;
	}
};




#endif
