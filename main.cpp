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
void sair(Companhia_aerea* comp);
void addav(Companhia_aerea* comp);
void delav(Companhia_aerea* comp);
void editav(Companhia_aerea* comp);
void addtri(Companhia_aerea* comp);
void deltri(Companhia_aerea* comp);
void edittri(Companhia_aerea* comp);

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
	catch(Companhia_ja_existe & x){
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

	string names_ar[]={"Adiconar aviao:","Apagar aviao:","editar aviao", "Adicionar Tripulante", "Apagar tripulante","editar tripulante","sair"};
	funcao func_ar[]={&addav,&delav,&editav,&addtri,&deltri,&edittri,&sair};
	vector<string> names(&names_ar[0],&names_ar[7]);
	vector<funcao> func(&func_ar[0],&func_ar[7]);
	int opt=0;
	while(opt!=7){
	opt=menu_companhia(names,func,comp);
	}


}

void addav(Companhia_aerea* comp){
	string matricula,  nome,   tipo,  descricao,  categoria;
	int peso=-1;
	cout<<"Matricula: ";
	getline(cin,matricula);
	cout<<"\nNome: ";
	getline(cin,nome);
	cout<<"\nPeso: ";
	string pesotmp;
	while(peso<=0){
		getline(cin, pesotmp);
		peso=atoi(pesotmp.c_str());
	}
	cout<<"\nTipo: ";
	getline(cin,tipo);
	cout<<"\nDescricao: ";
	getline(cin,descricao);
	cout<<"\nCategoria: ";
	getline(cin,categoria);

	Aviao tmp( matricula,  nome, peso,  tipo,  descricao,  categoria);
	try{
	comp->add_plane(tmp);
	}
	catch(aviao_ja_existe & x){
		cout<<endl<<x<<endl<<endl;
	}
}
void delav(Companhia_aerea* comp){}
void editav(Companhia_aerea* comp){}
void addtri(Companhia_aerea* comp){}
void deltri(Companhia_aerea* comp){}
void edittri(Companhia_aerea* comp){}


void sair(){}
void sair(Companhia_aerea* comp){}
