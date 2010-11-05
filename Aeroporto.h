/*
 * Aeroporto.h
 *
 *  Created on: 1 de Nov de 2010
 *      Author: pedroborges
 */

#ifndef AEROPORTO_H_
#define AEROPORTO_H_

#include "Companhia.h"
#include <vector>
#include "Plano_de_voo.h"

namespace std {

class Aeroporto {
private:
	vector<Plano_de_voo> planos;
	vector<Companhia_aerea> companhias;

public:
	Aeroporto();
	virtual ~Aeroporto();

	void add_companhia(string & sigla, string & nme_companhia);
	vector<string> nomes_companhias();
	int getNumPlanos(){
		return this->planos.size();
	}
	Plano_de_voo* getPlano(int i){
		return &this->planos[i];
	}
	bool delete_plane(Companhia_aerea* companhia, Aviao* aviao); // procurar todos os planos de voo com o aviao x e apaga-los avisando o utilizador que vai apagar planos de voo se continuar...
	bool existe_pv_aviao(Companhia_aerea* companhia, Aviao* aviao);  //devolve true se existir pelo menos um plano de voo com o Aviao aviao
	bool apaga_pv_aviao(Companhia_aerea* companhia, Aviao* aviao); //devolve true se apagar
	vector<Companhia_aerea> *apt_comp(){
		return &companhias;
	}
	Companhia_aerea* apt_companhia(int i){
		return &companhias[i];
	}
	int getNumeroComp(){
		return companhias.size();
	}
	bool add_plano(Plano_de_voo & a);
	bool del_companhia(Companhia_aerea *a);
};


class Companhia_ja_existe{   //acabar implementacao
private:
	string sigla, nme;
public:
	Companhia_ja_existe(string & sigla, string & nme){
		this->sigla=sigla;
		this->nme=nme;
	}
	friend ostream & operator<<(ostream & out, Companhia_ja_existe x){
		out<<"A companhia com a sigla "<<x.sigla<<" e nome "<<x.nme<<" ja existe na base de dados.";
		return out;
	}

};

}

#endif /* AEROPORTO_H_ */
