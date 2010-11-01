
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Companhia.h"

using namespace std;

typedef void (*funcao_generica) (void);

bool menu_generico(vector<string> &names, vector<funcao_generica> &funcoes){
	if(names.size()!=funcoes.size()){
		return false;
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

	return true;

}



typedef void (*funcao)(Companhia_aerea*);

bool menu_companhia(vector<string> names, vector<funcao> funcoes,Companhia_aerea* comp){
	if(names.size()!=funcoes.size()){
		return false;
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

	return true;

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
