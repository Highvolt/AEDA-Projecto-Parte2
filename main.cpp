/*
 * main.cpp
 *
 *  Created on: 23 de Out de 2010
 *      Author: pedroborges
 */


#include "Companhia.h"
#include "Aeroporto.h"
#include "misc.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef void (*funcao)(Companhia_aerea*);
typedef void (*funcao_generica) (void);

//prototipos

void addcomp();
void gerenciar_comp();
void sair();
void gerir_comp(Companhia_aerea* comp);

//*********

Aeroporto aeroporto;


int main(){

	string names_ar[]={"Adiconar companhia:","gerenciar companhia","sair"};
	funcao_generica func_ar[]={&addcomp,&gerenciar_comp,&sair};
	vector<string> names(&names_ar[0],&names_ar[3]);
	vector<funcao_generica> func(&func_ar[0],&func_ar[3]);
	int opt=0;
	while (opt!=3){
	opt=menu_generico(names,func);

	}


	return 0;
}


void addcomp(){
	cout<<"Adicao de companhia"<<endl;
	string sigla,name;
	getline(cin,sigla);
	getline(cin,name);
	try{
		aeroporto.add_companhia(sigla,name);
	}
	catch(Companhia_ja_existe x){
		cout<<x<<endl;

	}


}



void gerenciar_comp(){
	cout<<"Gerir companhia aerea"<<endl;
	vector<string> nomes(aeroporto.nomes_companhias());
	vector<funcao_generica> funcoes(nomes.size(),&sair);

	gerir_comp(aeroporto.apt_companhia(menu_generico(nomes,funcoes)));
}

void gerir_comp(Companhia_aerea* comp){

}


void sair(){}
