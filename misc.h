
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

typedef void (*funcao)();

bool menu(vector<string> names, vector<funcao> funcoes){
	if(names.size()!=funcoes.size()){
		return false;
	}

	for(unsigned int n=0;n<names.size();n++){
		cout<<n<<" - "<<names[n]<<endl;
	}

	string opt_temp="";
	unsigned int opt=n+1;

	while(opt>n){
		cout<<"\n\n \t opcao"<<"[0-"<<names.size()-1<<"] :"<<endl;
		opt=atoi(opt_temp.c_str());
	}

	funcoes[opt]();

	return true;

}
