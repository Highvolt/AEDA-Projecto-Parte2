/*
 * Arquivo_de_voo.h
 *
 *  Created on: 18 de Dez de 2010
 *      Author: pedroborges
 */


#include <iostream>
#include "BST.h"
#include "Plano_de_voo.h"
#include "Companhia.h"
#ifndef ARQUIVO_DE_VOO_H_
#define ARQUIVO_DE_VOO_H_


namespace std {

class Arquivo_de_voo {
	BST<Plano_de_voo> arquivo;

public:

	/**
	 * creates a new flight archive
	 * @name Arquivo_de_voo
	 */
	Arquivo_de_voo();

	/**
	 * inserts a new flight plan into the archive
	 * @name insert
	 * @param Plano_de_voo & a
	 *
	 */
	void insert(Plano_de_voo & a);

	/**
	 * removes a flight plan from the archive
	 * @name remove
	 * @param Plano_de_voo & a
	 */
	void remove(Plano_de_voo & a);

	/**
	 * gives the flight plans whose departures are between d1 and d2
	 * @name pesquisa
	 * @param d1
	 * @param d2
	 * @return planos
	 */
	vector<Plano_de_voo> pesquisa(horas_data d1, horas_data d2);

	/**
	 *gives the flight plans whose departures are between d1 and d2 and that are related to a specified air company
	 *@name pesquisa
	 *@param d1
	 *@param d2
	 *@param Companhia_aerea * comp
	 *@return planos
	 */
	vector<Plano_de_voo> pesquisa(horas_data d1, horas_data d2, Companhia_aerea * comp);

	/**
	 * gives the flight plans corresponding to the searched air company
	 * @name pesquisa
	 * @param Companhia_aerea * comp
	 * @return vector<Plano_de_voo>
	 */
	vector<Plano_de_voo> pesquisa(Companhia_aerea * comp);

	/**
	 * class destructor for flightplans
	 * @name ~Arquivo_de_voo
	 *
	 */
	virtual ~Arquivo_de_voo();

	/**
	 * Allows the function to display in the screen flight archives
	 * @name <<
	 * @param ostream & out
	 * @param Arquivo_de_voo x
	 * @return a display in the screen
	 */
	friend ostream & operator<<(ostream & out, Arquivo_de_voo x) {
		BSTItrIn<Plano_de_voo> itr(x.arquivo);

		for(;!(itr.isAtEnd());itr.advance()){
			Plano_de_voo temp=itr.retrieve();
			out<<temp<<endl;
		}

		return out;
	}
};

}

#endif /** ARQUIVO_DE_VOO_H_ */
