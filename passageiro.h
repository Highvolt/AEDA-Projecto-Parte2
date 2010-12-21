#ifndef PASSAGEIRO_H_
#define PASSAGEIRO_H_
#include <iostream>
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
	/**
	 * creates a new passenger
	 * @name passageiro
	 * @param string nome=""
	 * @param unsigned long int n_BI=0
	 */
	passageiro(string nome="", unsigned long int n_BI=0);

	/**
	 * creates a new passenger
	 * @name passageiro
	 * @param string nome
	 * @param unsigned long int n_BI
	 * @param vector<Plano_de_voo> via
	 */
	passageiro(string nome, unsigned long int n_BI, vector<Plano_de_voo> via);

	/**
	 * adds the airplanes to the vector
	 * @name adicionar_voo
	 * @param Plano_de_voo a
	 */
	void adicionar_voo(Plano_de_voo  a);

	/**
	 * class destructor of passengers
	 * @name ~passageiro
	 */
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


	/**
	 * allows the user to watch the name of the passenger
	 * @name <<
	 * @param ostream & out
	 * @param passageiro a
	 * @return the display resulted from the function
	 */
	friend ostream & operator<<(ostream & out, passageiro a){
		out<<a.name<<'|'<<a.n_BI;
		vector<Plano_de_voo> planos=a.getViagens_realizadas();
		for(vector<Plano_de_voo>::iterator it=planos.begin();it!=planos.end(); it++){
			out<<'|'<<*it;
		}
		out<<endl;
		return out;
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
/**
 * creating a hash_table
 * @name tableap
 * @return a hash_table
 */
typedef hash_set<passageiro,hpass,eqpass> tabelap;

class Passageiro_tb{
	tabelap tabela;
public:
	/**
	 * creates a passengers hash table
	 * @name Passageiro_tb
	 */
	Passageiro_tb();
	/**
	 * creates a passengers hash table
	 * @name Passageiro_tb
	 * @param string nome
	 * @param unsigned long BI
	 * @param vector<Plano_de_voo> & viagens_realizadas
	 */

	Passageiro_tb(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas);
	/**
	 * inserts a new passenger in the hash table
	 * @name insert
	 * @param passageiro & a
	 */
	void insert(passageiro & a);
	/**
	 * inserts a new passenger in the hash table with the given caracteristics
	 * @name insert
	 * @param string nome
	 * @param unsigned long BI
	 * @param vector<Plano_de_voo> & viagens_realizadas
	 *
	 */
	void insert(string nome, unsigned long BI, vector<Plano_de_voo> & viagens_realizadas);

	/**
	 * returns a vector of passengers in the hash table
	 * @name getPassageiros
	 * @return a vector of passengers
	 */
	vector<passageiro> getPassageiros(){
		vector<passageiro> temp;
		for(tabelap::iterator it=tabela.begin();it!=tabela.end();it++){
			temp.push_back(*it);
		}
		return temp;
	}
	/**
	 * finds a given passenger in the hash table of passengers
	 * @name find
	 * @param passageiro & a
	 * @return the found passenger
	 */
	passageiro find(passageiro & a);

	/**
	 * deletes a passenger from the hash table of passengers
	 * @name deletep
	 * @param passageiro & a
	 */
	void deletep(passageiro & a );

	/**
	 * returns the hash table of passengers
	 * @name getTAB
	 * @return the hash table
	 */
	tabelap getTAB(){
		return tabela;
	}

	/**
	 *allows the user to see the hash table of passengers
	 *@name <<
	 *@param ostream & out
	 *@param Passageiro_tb & a
	 *@return the hash table
	 */
	friend ostream & operator<<(ostream & out, Passageiro_tb & a){
		tabelap copia=a.getTAB();
		for(tabelap::iterator it=copia.begin();it!=copia.end();it++){
			out<<*it;
		}
		return out;
	}


};

#endif /** PASSAGEIRO_H_ */
