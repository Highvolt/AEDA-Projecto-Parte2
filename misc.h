
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Companhia.h"

using namespace std;
/*
 * Menu generator for basic operations such as choosing options
 * @param vector<T> dados
 * @return the option chosen by the user
 */

template<class T>
int menu(vector<T> dados){
	if(dados.size()==0){
		return -1;
	}
	for(unsigned int n=0;n<dados.size();n++){
		cout<<n+1<<" - "<<dados[n]<<endl;
	}

	string opt_temp="";
	unsigned int opt=dados.size()+1;

	while(opt>dados.size() || opt<=0){
		cout<<"\n\n \t opcao"<<"[1-"<<dados.size()<<"] :"<<endl;
		getline(cin,opt_temp);
		opt=atoi(opt_temp.c_str());
	}



	return opt-1;

}

/*
 * inicialization of a generic function pointer
 */
typedef void (*funcao_generica) (void);
/*
 * This generates the second base of hour menus, where intel, that our functions return, will be read, used and modified
 * @param vector<string> &names
 * @param vector<funcao_generica> &funcoes
 * @return the opion chosen by the user
 */
int menu_generico(vector<string> &names, vector<funcao_generica> &funcoes){
	if(names.size()!=funcoes.size()){
		return -1;
	}

	for(unsigned int n=0;n<names.size();n++){
		cout<<n+1<<" - "<<names[n]<<endl;
	}

	string opt_temp="";
	unsigned int opt=names.size()+1;

	while(opt>names.size() || opt<=0){
		cout<<"\n\n \t opcao"<<"[1-"<<names.size()<<"] :"<<endl;
		getline(cin,opt_temp);
		opt=atoi(opt_temp.c_str());
	}

	funcoes[opt-1]();

	return opt;

}



typedef void (*funcao)(Companhia_aerea*);

int menu_companhia(vector<string> names, vector<funcao> funcoes,Companhia_aerea* comp){
	if(names.size()!=funcoes.size()){
		return -1;
	}

	for(unsigned int n=0;n<names.size();n++){
		cout<<n+1<<" - "<<names[n]<<endl;
	}

	string opt_temp="";
	unsigned int opt=names.size()+1;

	while(opt>names.size() || opt<=0){
		cout<<"\n\n \t opcao"<<"[1-"<<names.size()<<"] :"<<endl;
		getline(cin,opt_temp);
		opt=atoi(opt_temp.c_str());
	}


	funcoes[opt-1](comp);

	return opt;

}

int menu_de_companhias(vector<Companhia_aerea*> comps){

	for(size_t i=0;i<comps.size();i++){
		cout<<i+1<<" - "<<comps[i]->getSigla()<<endl;
	}



	string opt_temp="";
	unsigned int opt=comps.size()+1;

	while(opt>comps.size() || opt<=0){
		cout<<"\n\n \t opcao"<<"[1-"<<comps.size()<<"] :"<<endl;
		getline(cin,opt_temp);
		opt=atoi(opt_temp.c_str());
	}

	return opt-1;
}
