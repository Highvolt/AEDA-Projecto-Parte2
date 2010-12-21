/**
 * Pista_aterragem.h
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#ifndef PISTA_ATERRAGEM_H_
#define PISTA_ATERRAGEM_H_
#include <queue>
#include <vector>
#include "Plano_de_voo.h"


namespace std {

class operadorat{
public:
	/**
     * this operator compares arrivals
	 * @name ()
	 * @param const Plano_de_voo a
	 * @param const Plano_de_voo b
     * @return true or false depending on what arrival is first
	 */
	bool operator()(const Plano_de_voo  a, const Plano_de_voo  b) const{
		return (a.getChegada()>b.getChegada());
	}
};

class Pista_aterragem {
	int id;
	static int max_id;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadorat> pista;
public:
	/**
	* creates a new landing strip
	* @name Pista_aterragem
    */
	Pista_aterragem();

	/**
	 * class destructor for landing strip
	 * @name ~Pista_aterragem
	 */
	virtual ~Pista_aterragem();

	/**
	 * return every flight scheduled for this track
	 * @name get_lista
	 * @returns a vector of flights in this track
	 */
	vector<Plano_de_voo> get_lista();

	/**
	 * lands an airplane by inserting it in the queue
	 * @name aterrou
	 * @param Plano_de_voo a
	 *
	 */
	void aterrou(Plano_de_voo a);

	/**
	 * puts an airplane waiting to land
	 * @name entrou_na_fila
	 * @param Plano_de_voo a
	 */
	void entrou_na_fila(Plano_de_voo a);
};

}

#endif /** PISTA_ATERRAGEM_H_ */
