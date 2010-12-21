/*
 * Pista_descolagem.h
 *
 *  Created on: 11 de Dez de 2010
 *      Author: pedroborges
 */

#ifndef PISTA_DESCOLAGEM_H_
#define PISTA_DESCOLAGEM_H_
#include <queue>
#include <vector>
#include "Plano_de_voo.h"



namespace std {


class operadordes{
public:

	/*
	 * this operator compares departures
	 * @name ()
	 * @param const Plano_de_voo ab
	 * @param const Plano_de_voo bb
	 * @return true or false depending on what departure is first
	 */
	bool operator()(const Plano_de_voo  ab, const Plano_de_voo  bb) const{
		return ab.getPartida()>bb.getPartida();

	}

};

class Pista_descolagem {
	int id;
	static int max_id;
	//vector<Plano_de_voo> pistav;
	priority_queue<Plano_de_voo,vector<Plano_de_voo>,operadordes> pista;
public:
	/*
	 * creates a new runway
	 * @name Pista_descolagem
	 */
	Pista_descolagem();

	/*
	 * class destructor for a runway
	 * @name ~Pista_descolagem
	 */
	virtual ~Pista_descolagem();

	/*
	 * return every flight scheduled for this runway
	 * @name get_lista
	 * @returns a vector of flights in this runway
	 */
	vector<Plano_de_voo> get_lista();
	/*
	 * takeoff an airplane by inserting it in the queue
	 * @name elvantou
	 * @param Plano_de_voo a
	 *
	 */
	void levantou(Plano_de_voo a);

	/*
	 * puts an airplane waiting to takeoff
	 * @name entrou_na_fila
	 * @param Plano_de_voo a
	 */
	void entrou_na_fila(Plano_de_voo a);
};

}

#endif /* PISTA_DESCOLAGEM_H_ */
