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
using namespace std;




class passageiro {
	string name;
	unsigned long int n_BI;
	vector<Planos_de_voo> viagens_realizadas;
public:
	passageiro(string nome, unsigned long int n_BI);
	void adicionar_voo(Plano_de_voo * a);
	virtual ~passageiro();
    unsigned long int getBI() const
    {
        return n_BI;
    }

    string getName() const
    {
        return name;
    }

    vector<Planos_de_voo> getViagens_realizadas() const
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

    void setViagens_realizadas(vector<Planos_de_voo> viagens_realizadas)
    {
        this->viagens_realizadas = viagens_realizadas;
    }

};

class elemento_hash{
	list<passageiro> users;
public:
	elemento_hash(passageiro a);
	void add_elemento(passageiro a);
};

class passageiro_tb{

};

#endif /* PASSAGEIRO_H_ */
