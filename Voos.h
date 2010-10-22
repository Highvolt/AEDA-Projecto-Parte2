/*
 * Voos.h
 *
 *  Created on: 10 de Out de 2010
 *      Author: pedroborges
 */

#ifndef VOOS_H_
#define VOOS_H_
#include <vector>
#include <string>

using namespace std;

class Tripulantes;
class Aviao;

class Companhia_aerea{
private:
	vector<Tripulantes*> tripulantes;
	vector<Aviao*> avioes;
	string sigla, nme_companhia;
public:

	Companhia_aerea(string & sigla, string & nme_companhia);
	void add_plane(Aviao aviao);

};




class Tripulantes{
private:
	int numero, salario_hora;
	string categoria, nome;

public:
	Tripulantes(int numero, string categoria, string nome, int salario_hora);


};

class Tipo_de_aviao{
private:
	string tipo, descricao, categoria;
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



class Voos{
private:
	struct horas_ut{
		int inicio_h;
		int inicio_min;
		int fim_h;
		int fim_min;
	};

public:
	Voos();
	virtual ~Voos();
};



#endif /* VOOS_H_ */
