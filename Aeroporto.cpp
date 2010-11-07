#include "Aeroporto.h"

using namespace std;

/**
 * class constructor for a airport
 * Initializes a airport
 * @name Aeroporto
 *
 */
Aeroporto::Aeroporto() {


}

Aeroporto::~Aeroporto() {
	// TODO Auto-generated destructor stub
}


void Aeroporto::add_companhia(string & sigla, string & nme_companhia){
	Companhia_aerea tmp(sigla,nme_companhia);
	for(vector<Companhia_aerea>::iterator it=companhias.begin(); it<companhias.end();it++){
		if(*it==tmp){
			throw Companhia_ja_existe(sigla,nme_companhia);
		}

	}
	companhias.push_back(tmp);
}


bool Aeroporto::existe_pv_aviao(Companhia_aerea* companhia, Aviao* aviao){
	for(size_t i=0; i<planos.size(); i++){
		if(*(planos[i].getAviao())==*aviao && *(planos[i].getCompanhia())==*companhia){
			return true;

		}
	}
	return false;
}

bool Aeroporto::apaga_pv_aviao(Companhia_aerea* companhia, Aviao* aviao){
	while(existe_pv_aviao(companhia,aviao)){
		for(vector<Plano_de_voo>::iterator it=planos.begin();it<planos.end(); it++){
			if(*(it->getAviao())==*aviao && *(it->getCompanhia())==*companhia){
				planos.erase(it);
				break;
			}
		}
	}
	return true;

}

vector<string> Aeroporto::nomes_companhias(){
	 vector<string> tmp(companhias.size(),"");
	 for(size_t it=0;it<companhias.size();it++){
		 tmp[it]=companhias[it].getNome();
	 }

	 return tmp;
}

bool Aeroporto::add_plano(Plano_de_voo & a){
	for(size_t i=0;i<planos.size(); i++){
		if(!(Compatible(a,planos[i]))){
			return false;
		}
	}
	planos.push_back(a);

	return true;
}

bool Aeroporto::del_companhia(Companhia_aerea *a){
	for(vector<Plano_de_voo>::iterator it=planos.begin();it<planos.end();it++){
		if(*(it->getCompanhia())==*a){
			planos.erase(it);
			it=planos.begin();
		}
	}
	for(vector<Companhia_aerea>::iterator it=companhias.begin();it<companhias.end();it++){
		if(*it==*a){
			companhias.erase(it);
			return true;
		}
	}
	return false;
}

