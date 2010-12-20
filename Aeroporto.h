#ifndef AEROPORTO_H_
#define AEROPORTO_H_

#include "Companhia.h"
#include <vector>
#include "Plano_de_voo.h"
#include <string>
#include "Pista_aterragem.h"
#include "Pista_descolagem.h"
#include "Arquivo_de_voo.h"
#include "passageiro.h"

namespace std {

class Aeroporto {
private:
	string nome;
	vector<Plano_de_voo> planos;
	vector<Companhia_aerea> companhias;
	Pista_aterragem pista1;
	Pista_descolagem pista2;
	Passageiro_tb passageiros;
	Arquivo_de_voo arquivos;

public:

	Aeroporto(string  nome);

	/**
	 *class destructor for a airport
	 *@name -Aeroporto
	 */
	virtual ~Aeroporto();

	/**
	 * adds a company to the vector of all companies
	 * @name add_companhia
	 * @param string & sigla
	 * @param string & nme_companhia
	 *
	 */
	void add_companhia(string & sigla, string & nme_companhia);
	vector<string> nomes_companhias();

	/**
	 * returns the number os flght plans
	 * @name getNumPlanos
	 * @return the size of vector planos
	 */
	int getNumPlanos(){
		return this->planos.size();
	}

	/**
	 * returns a flight plan existing in a position of the vector planos
	 * @name getPlano
	 * @param int i
	 * @return a flight plan from the vector planos
	 */
	Plano_de_voo* getPlano(int i){
		return &this->planos[i];
	}

	/**
	 * delete every flight plan belonging to a airplane from a air company and launches a warning to th user
	 *@name delete_plane
	 *@param Companhia_aerea* companhia
	 *@param  Aviao* aviao
	 *@return true if the flight was erased and false if not
	 **/
	bool delete_plane(Companhia_aerea* companhia, Aviao* aviao);

	/**
	 * check if there is at least a flight plan with the plane searched
	 * @name existe_pv_aviao
	 * @param Companhia_aerea* companhia
	 * @param Aviao* aviao
	 * @return true if there is in the vector companhia at least a flight plan with the air plane searched
	 */
	bool existe_pv_aviao(Companhia_aerea* companhia, Aviao* aviao);

	/**
	 * erases the flight plan from the vector when searching for a specific air plane
	 * @name apaga_pv_aviao
	 * @param Companhia_aerea* companhia
	 * @param Aviao* aviao
	 * @ return true if it was deleted
	 */
	bool apaga_pv_aviao(Companhia_aerea* companhia, Aviao* aviao);

	/**
	 * gives the name of all air companies
	 * @name apt_comp
	 * @return the vector companhias
	 */
	vector<Companhia_aerea> *apt_comp(){
		return &companhias;
	}
	/**
	 * gives the name of a air company situated in a given position
	 * @name apt_companhia
	 * @param int i
	 * @return the name of the air company positioned in the position i of the vector companhias
	 */
	Companhia_aerea* apt_companhia(int i){
		return &companhias[i];
	}

	/**
	 * gives to the user the name of a air company by inserting the air company sigla
	 * @name apt_companhia
	 * @param string sigla
	 * @return the name of the air company
	 */
	Companhia_aerea* apt_companhia(string sigla){
		for(size_t i=0;i<companhias.size();i++){
			if(companhias[i].getSigla()==sigla){
				return &companhias[i];
			}
		}
	}

	/**
	 * gives the number of companies at that moment
	 * @name getNumeroComp
	 * @return the size of the vector companhias
	 */
	int getNumeroComp(){
		return companhias.size();
	}
	/**
	 * adds a flight plan to the vector of flights plans
	 * @name add_plano
	 * @param Plano_de_voo & a
	 * @return true if the plan was added with success
	 */
	bool add_plano(Plano_de_voo & a);

	/**
	 * deletes a air company
	 * @name del_companhia
	 * @param Companhia_aerea *a
	 * @return true if it was deleted with success
	 */
	bool del_companhia(Companhia_aerea *a);


	string getNome(){
		return nome;
	}
	void SetNome(string nome){
		this->nome=nome;
	}

	Pista_aterragem get_pista1() const{
		return this->pista1;
	}

	Pista_descolagem get_pista2() const{
		return this->pista2;
	}

	void descolar(Plano_de_voo & a){
		for(vector<Plano_de_voo>::iterator it=this->planos.begin();it!=planos.end();it++){
			if(*it==a){
				it->set_arq(true);
				this->arquivos.insert(*it);

				this->pista2.levantou(a);
				//cout<<"fim"<<endl;
				break;

			}
		}

	}

	void aterrou(Plano_de_voo & a){
		for(vector<Plano_de_voo>::iterator it=this->planos.begin();it!=planos.end();it++){
			if(*it==a){
				it->set_arq(true);
				this->arquivos.insert(*it);

				this->pista1.aterrou(a);
				//cout<<"fim"<<endl;
				break;

			}
		}

	}

};


class Companhia_ja_existe{   //acabar implementacao
private:
	string sigla, nme;
public:
	/**
	 * class constructor for a already existing air company
	 * @name Companhia_ja_existe
	 * @param string & sigla
	 * @param string & nme
	 *
	 */
	Companhia_ja_existe(string & sigla, string & nme){
		this->sigla=sigla;
		this->nme=nme;
	}

	/**
	 * Allows the functions to display in the screen air companies acronyms
     * @name <<
     * @param ostream & out
     * @param Companhia_ja_existe x
     * @return a display in the screen of a air company acronym
	 */
	friend ostream & operator<<(ostream & out, Companhia_ja_existe x){
		out<<"A companhia com a sigla "<<x.sigla<<" e nome "<<x.nme<<" ja existe na base de dados.";
		return out;
	}




};

}

#endif /* AEROPORTO_H_ */
