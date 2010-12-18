/*
 * passageiro.h
 *
 *  Created on: 13 de Dez de 2010
 *      Author: pedroborges
 */

#ifndef PASSAGEIRO_H_
#define PASSAGEIRO_H_

#include <vector>
#include "Plano_de_voo.h"
#include <list>
#include <hash_set.h>
using namespace std;




class passageiro {
	string name;
	unsigned long int n_BI;
	vector<Plano_de_voo> viagens_realizadas;
public:
	passageiro(string nome="", unsigned long int n_BI=0);
	passageiro(string nome, unsigned long int n_BI, vector<Plano_de_voo> via);
	void adicionar_voo(Plano_de_voo  a);
	virtual ~passageiro();
	unsigned long int getBI() const
	{
		return n_BI;
	}

	string getName() const
	{
		return name;
	}

	vector<Plano_de_voo> getViagens_realizadas() const
    						{
		return viagens_realizadas;
    						}

	void setBI(unsigned long int n_BI)
	{
		this->n_BI = n_BI;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setViagens_realizadas(vector<Plano_de_voo> viagens_realizadas)
	{
		this->viagens_realizadas = viagens_realizadas;
	}

};



struct hpass {
	int operator() (passageiro p) const {
		int v = 0;
		string s1=p.getName();
		for ( unsigned int i=0; i< s1.size(); i++)
			v = 37*v + s1[i];
		return v;
	}
};

struct eqpass {
	bool operator() (passageiro p1, passageiro p2) const {
		return p1.getBI()==p2.getBI();
	}
};

typedef hash_set<passageiro,hpass,eqpass> tabelap;

class Passageiro_tb{
	tabelap tabela;
public:
	Passageiro_tb(passageiro & a);
	Passageiro_tb(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas);
	void insert(passageiro & a);
	void insert(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas);
	passageiro find( unsigned long BI);
	void deletep(unsigned long BI);



};

#endif /* PASSAGEIRO_H_ */
