
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <Companhia.h>

using namespace std;

typedef void (*funcao)(Companhia_aerea*);

bool menu_companhia(vector<string> names, vector<funcao> funcoes,Companhia_aerea* comp){
	if(names.size()!=funcoes.size()){
		return false;
	}

	for(unsigned int n=0;n<names.size();n++){
		cout<<n<<" - "<<names[n]<<endl;
	}

	string opt_temp="";
	unsigned int opt=names.size()+1;

	while(opt>names.size()){
		cout<<"\n\n \t opcao"<<"[0-"<<names.size()-1<<"] :"<<endl;
		opt=atoi(opt_temp.c_str());
	}

	funcoes[opt](comp);

	return true;

}
