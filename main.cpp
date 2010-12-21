

#include "Companhia.h"
#include "Aeroporto.h"
#include "Plano_de_voo.h"
#include "passageiro.h"
#include "hash_set.h"
#include "misc.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>



using namespace std;

string filenamecomp="companhias.txt";
string filenameplanos="planos.txt";


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
void delcomp(Companhia_aerea* comp);
void gerav(Companhia_aerea* comp);
void mostra_companhias();
void ver_planos();
void save();
void load();
void gerir_pistas();
void garquivo();
void gpas();

//*********

Aeroporto aeroporto(string("PT"));


int main(){

	cout<<"Aeroporto system v0.2 by: \n- ei09063 \n- ei09068 \n -ei09010\n"<<endl;
	cout<<"\tAeroporto: "<<aeroporto.getNome()<<endl;

	string names_ar[]={"Adiconar companhia:","gerenciar companhia","gerir pistas","Consultar arquivo","Gest‹o de passageiros","ver companhias","ver Planos","save","load","sair"};
	funcao_generica func_ar[]={&addcomp,&gerenciar_comp, &gerir_pistas,&garquivo,&gpas,&mostra_companhias,&ver_planos,&save,&load,&sair};
	vector<string> names(&names_ar[0],&names_ar[10]);
	vector<funcao_generica> func(&func_ar[0],&func_ar[10]);
	int opt=0;
	while (opt!=10){
		opt=menu_generico(names,func);

	}


	return 0;
}

void addpas(){
	cout<<"Adicionar Passageiro "<<endl<<endl;
	string nome;
	string bistr;
	unsigned long BI=0;
	vector<Plano_de_voo> planos;
	cout<<"Nome: ";
	getline(cin, nome);
	while(BI==0){
		cout<<"N¼ BI";
		getline(cin,bistr);
		BI=atol(bistr.c_str());
	}
	passageiro tmp(nome,BI,planos);
	aeroporto.PassIn(tmp);
}

void verpas(){
	Passageiro_tb a=aeroporto.getPassageiros();
	cout<<a<<endl;

}
void deletepas(){
	vector<passageiro> pass=aeroporto.getPassageiros().getPassageiros();
	int opt=menu(pass);
	aeroporto.PassOut(pass[opt]);
}


void addplanopass(){
	vector<passageiro> pass=aeroporto.getPassageiros().getPassageiros();
	int opt=menu(pass);
	aeroporto.PassOut(pass[opt]);
	vector<Plano_de_voo> planos;
	for(size_t i=0; i<aeroporto.getNumPlanos(); i++){
		planos.push_back(*(aeroporto.getPlano(i)));
	}
	int opt2=menu(planos);
	pass[opt].adicionar_voo(planos[opt2]);
	aeroporto.PassIn(pass[opt]);
}



void editpas(){
	vector<string> nomes;
	nomes.push_back("Apagar");
	nomes.push_back("Adiconar Plano");
	int opt=menu(nomes);
	if(opt==0){
		deletepas();
	}
	else{
		addplanopass();
	}

}





void gpas(){
	vector<string> nomes;
	nomes.push_back("Adicionar");
	nomes.push_back("Ver");
	nomes.push_back("Editar");
	nomes.push_back("Sair");
	int opt=menu(nomes);
	switch(opt){
	case 0:
		addpas();break;

	case 1:
		verpas();break;

	case 2:
		editpas();break;

	}

}

horas_data scandata(){
	horas_data temp;
	int ano=-1,mes=-1,dia=-1,hora=-1,min=-1;
	cout<<"\nAno: ";
	string pesotmp;
	while(ano<0){
		getline(cin, pesotmp);
		ano=atoi(pesotmp.c_str());
	}
	cout<<"\nmes: ";
	while(mes<=0 || mes>12){
		getline(cin, pesotmp);
		mes=atoi(pesotmp.c_str());
	}
	cout<<"\ndia: ";
	while(dia<=0 || dia>31 ){
		getline(cin, pesotmp);
		dia=atoi(pesotmp.c_str());
	}
	cout<<"\nhora: ";
	while(hora<0 || hora>=24){
		getline(cin, pesotmp);
		hora=atoi(pesotmp.c_str());
	}
	cout<< "\nminutos: ";
	while(min<0 || min>=60){
		getline(cin, pesotmp);
		min=atoi(pesotmp.c_str());
	}
	temp.ano=ano;
	temp.mes=mes;
	temp.dia=dia;
	temp.hora=hora;
	temp.min=min;
	return temp;
}

void pesqarqdata(){
	horas_data d1;
	horas_data d2;
	cout<<"\n**DE:"<<endl;
	d1=scandata();
	cout<<"\n**ATE:"<<endl;
	d2=scandata();
	vector<Plano_de_voo> res=aeroporto.getArquivo().pesquisa(d1,d2);
	if(res.size()!=0){
		cout<<"Resultados da Pesquisa"<<endl;
		for(vector<Plano_de_voo>::iterator it=res.begin(); it!=res.end();it++){
			cout<<*it<<endl;
		}
	}
}
void pesqarqdatacomp(){
	horas_data d1;
	horas_data d2;
	cout<<"\n**DE:"<<endl;
	d1=scandata();
	cout<<"\n**ATE:"<<endl;
	d2=scandata();
	vector<string> comp=aeroporto.nomes_companhias();
	vector<Plano_de_voo> res=aeroporto.getArquivo().pesquisa(d1,d2,aeroporto.apt_companhia(menu(comp)));
	if(res.size()!=0){
		cout<<"Resultados da Pesquisa"<<endl;
		for(vector<Plano_de_voo>::iterator it=res.begin(); it!=res.end();it++){
			cout<<*it<<endl;
		}
	}

}

void arqsearch(){
	vector<string> nomes;
	nomes.push_back("Data");
	nomes.push_back("Data e Companhia");
	nomes.push_back("Sair");
	int opt=menu(nomes);
	if(opt==0){
		pesqarqdata();
	}
	else{
		if(opt==1){
			pesqarqdatacomp();
		}
	}

}

void calctaxa(){
	vector<string> nomes;
	nomes.push_back("Por data e companhia");
	nomes.push_back("Por companhia");
	int opt=menu(nomes);
	if(opt==0){
		horas_data d1;
		horas_data d2;
		cout<<"\n**DE:"<<endl;
		d1=scandata();
		cout<<"\n**ATE:"<<endl;
		d2=scandata();
		vector<string> comp=aeroporto.nomes_companhias();
		vector<Plano_de_voo> res=aeroporto.getArquivo().pesquisa(d1,d2,aeroporto.apt_companhia(menu(comp)));
		if(res.size()!=0){
			cout<<"Taxa: "<<res.size()*aeroporto.getTaxa()<<endl;
		}
	}
	else{
		vector<string> comp=aeroporto.nomes_companhias();
		vector<Plano_de_voo> res=aeroporto.getArquivo().pesquisa(aeroporto.apt_companhia(menu(comp)));
		if(res.size()!=0){
			cout<<"Taxa: "<<res.size()*aeroporto.getTaxa()<<endl;
		}

	}


}


void alt_taxa(){
	float nova=-1;
	string temp;
	while(nova<0){
		getline(cin,temp);
		nova=atof(temp.c_str());
	}
	aeroporto.setTaxa(nova);

}

void taxes_calc(){
	cout<<"Calculo de Taxa"<<endl<<endl;
	cout<<"Taxa actual : "<<aeroporto.getTaxa()<<endl;
	vector<string> nomes;
	nomes.push_back("Calcular Taxa");
	nomes.push_back("Alterar Taxa");
	nomes.push_back("Sair");
	int opt=menu(nomes);
	if(opt==0){
		calctaxa();
	}
	if(opt==1){
		alt_taxa();
	}

}

void garquivo(){
	vector<string> nomes;
	nomes.push_back("Ver");
	nomes.push_back("Pesquisar");
	nomes.push_back("Calculo Taxas");
	nomes.push_back("Sair");
	int opt=menu(nomes);
	switch(opt){
	case 0: cout<<aeroporto.getArquivo()<<endl; break;
	case 1: arqsearch();break;
	case 2: taxes_calc();break;
	}
}


void gerir_desc(){
	cout<<"Gerir descolagem: \n"<<endl;
	vector<string> menuz;
	menuz.push_back("Ver");
	menuz.push_back("Descolar");
	menuz.push_back("Sair");
	int opt=menu(menuz);
	if(opt!=2){
		vector<Plano_de_voo> nomes=aeroporto.get_pista2().get_lista();
		//cout<<"n de voos: "<<nomes.size()<<endl;
		if(opt==0){
			for(vector<Plano_de_voo>::iterator it=nomes.begin();it!=nomes.end();it++){
				cout<<*it<<endl;
			}
		}else{
			opt=menu(nomes);
			aeroporto.descolar(nomes[opt]);
		}
	}

}

void gerir_aterragem(){
	cout<<"Gerir aterragem: \n"<<endl;
	vector<string> menuz;
	menuz.push_back("Ver");
	menuz.push_back("Aterrar");
	menuz.push_back("Sair");
	int opt=menu(menuz);
	if(opt!=2){
		vector<Plano_de_voo> nomes=aeroporto.get_pista1().get_lista();
		//cout<<"n de voos: "<<nomes.size()<<endl;
		if(opt==0){
			for(vector<Plano_de_voo>::iterator it=nomes.begin();it!=nomes.end();it++){
				cout<<*it<<endl;
			}
		}else{
			opt=menu(nomes);
			aeroporto.aterrou(nomes[opt]);
		}
	}
}


void gerir_pistas(){
	vector<string> pistas;
	pistas.push_back("Pista descolagem");
	pistas.push_back("Pista aterragem");
	int opt=menu(pistas);
	cout<<opt<<endl;
	if(opt==0){
		gerir_desc();
	}
	else{
		gerir_aterragem();
	}
}


void load(){
	fstream filecomp;
	filecomp.open(filenamecomp.c_str(),fstream::in);
	if(filecomp.is_open()){
		string tmp;

		getline(filecomp,tmp);

		aeroporto.SetNome(tmp);
		getline(filecomp,tmp);
		aeroporto.setTaxa(atof(tmp.c_str()));

		while(getline(filecomp,tmp)){
			string sigla="",nome="";
			size_t i=0;
			for(;i<tmp.size() && tmp[i]!='|';i++){
				sigla+=tmp[i];
			}
			i++;
			for(;i<tmp.size() && tmp[i]!='\n';i++){
				nome+=tmp[i];
			}
			aeroporto.add_companhia(sigla,nome);
			fstream compav;
			string filenameav=sigla+"av.txt";
			compav.open(filenameav.c_str(),fstream::in);
			if(compav.is_open()){
				while(getline(compav,tmp)){
					string matricula="",peso_str="",tipo="",des="",cat="";
					int peso;
					nome="";
					size_t i=0;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						matricula+=tmp[i];
					}
					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						nome+=tmp[i];
					}
					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						peso_str+=tmp[i];
					}
					peso=atoi(peso_str.c_str());
					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						tipo+=tmp[i];
					}
					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						des+=tmp[i];
					}
					i++;

					for(;i<tmp.size() && tmp[i]!='\n';i++){
						cat+=tmp[i];
					}
					Aviao tmpav(matricula,nome,peso,tipo,des,cat);
					aeroporto.apt_companhia(aeroporto.getNumeroComp()-1)->add_plane(tmpav);
				}
			}
			fstream comptr;
			string filenametr=sigla+"tr.txt";
			comptr.open(filenametr.c_str(),fstream::in);
			if(comptr.is_open()){
				while(getline(comptr,tmp)){
					string numero_str="",ordenado_str="",nome="",cat="";
					int numero,ordenado;
					nome="";
					size_t i=0;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						numero_str+=tmp[i];
					}
					i++;
					numero=atoi(numero_str.c_str());
					for(;i<tmp.size() && tmp[i]!='|';i++){
						ordenado_str+=tmp[i];
					}
					ordenado=atoi(ordenado_str.c_str());

					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						cat+=tmp[i];
					}
					i++;


					for(;i<tmp.size() && tmp[i]!='\n';i++){
						nome+=tmp[i];
					}
					Tripulante tmptr(numero,cat,nome,ordenado);
					aeroporto.apt_companhia(aeroporto.getNumeroComp()-1)->add_crew(tmptr);
				}
			}

		}
	}
	filecomp.close();

	//********planos*******

	fstream planos;
	planos.open(filenameplanos.c_str(),fstream::in);
	if(planos.is_open()){
		string tmp;
		while(getline(planos,tmp)){
			int anop=-1,mesp=-1,diap=-1,horap=-1,minp=-1;
			int anoc=-1,mesc=-1,diac=-1,horac=-1,minc=-1;
			string origem="",destino="";
			string comp="",av="";
			int n_pass=-1;
			size_t i=0;
			string conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			anop=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			mesp=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			diap=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			horap=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			minp=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			anoc=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			mesc=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			diac=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			horac=atoi(conv.c_str());
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			minc=atoi(conv.c_str());

			for(;i<tmp.size() && tmp[i]!='|';i++){
				comp+=tmp[i];
			}
			i++;
			for(;i<tmp.size() && tmp[i]!='|';i++){
				av+=tmp[i];
			}
			i++;
			conv="";
			for(;i<tmp.size() && tmp[i]!='|';i++){
				conv+=tmp[i];
			}
			i++;
			n_pass=atoi(conv.c_str());

			for(;i<tmp.size() && tmp[i]!='|';i++){
				origem+=tmp[i];
			}
			i++;

			for(;i<tmp.size() && tmp[i]!='|';i++){
				destino+=tmp[i];
			}
			bool arquivado;
			string arqt="";
			i++;
			for(;i<tmp.size() && tmp[i]!='\n';i++){
				arqt+=tmp[i];
				//cout<<"arquivado "<<arqt<<endl;
			}
			arquivado=atoi(arqt.c_str());
			Plano_de_voo tmppv(horap,minp,diap,mesp,anop,horac,minc,diac,mesc,anoc, aeroporto.apt_companhia(comp),origem, destino, aeroporto.apt_companhia(comp)->aviao_ptr(av),n_pass);
			tmppv.set_arq(arquivado);
			if(tmppv.valid()==false){
				cout<<"Dados invalidos"<<endl;
			}
			else{
				if(aeroporto.add_plano(tmppv)==false){
					cout<<"Incompativel"<<endl;
				}else {
					cout<<"Plano de voo adicionado com sucesso"<<endl;
				}
			}



		}

	}
	//*******passageiros***
	fstream passageiros;
	string filename_pass="Passageiros.txt";
	passageiros.open(filename_pass.c_str(),fstream::in);
	if(passageiros.is_open()){
		string tmp;
		while(getline(passageiros,tmp) && tmp.size()>2){
			//cout<<"start"<<endl;
			string nome="";
			string bistr="";
			unsigned long BI=0;
			vector<Plano_de_voo> plat;
			int i=0;
			for(;i<tmp.size() && tmp[i]!='|';i++ ){
				nome+=tmp[i];
			}
			i++;
			for(;i<tmp.size() && tmp[i]!='|' && tmp[i]!='\n';i++){
				bistr+=tmp[i];
			}

			BI=atol(bistr.c_str());
			//cout<<nome<<BI<<endl;
			//cout<<"OLA"<<endl;
			//cout<<tmp[i];
			if(tmp[i]!='\n' && i<tmp.size()){
				//cout<<"COCO"<<endl;
				i++;
				while(tmp[i]!='\n'  && i<tmp.size()){



					//cout<<tmp[i]<<endl;
					int anop=-1,mesp=-1,diap=-1,horap=-1,minp=-1;
					int anoc=-1,mesc=-1,diac=-1,horac=-1,minc=-1;
					string origem="",destino="";
					string comp="",av="";
					int n_pass=-1;
					//size_t i=0;
					string conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					anop=atoi(conv.c_str()); //
					//cout<<"Ano:"<<anop<<endl;
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					mesp=atoi(conv.c_str());
					//cout<<mesp<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					diap=atoi(conv.c_str());
					//cout<<diap<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					horap=atoi(conv.c_str());
					//cout<<horap<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					minp=atoi(conv.c_str());
					//cout<<minp<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					anoc=atoi(conv.c_str());
					//cout<<anoc<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					mesc=atoi(conv.c_str());
					//cout<<mesc<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					diac=atoi(conv.c_str());
					//cout<<diac<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					horac=atoi(conv.c_str());
					//cout<<horac<<endl;  //
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					minc=atoi(conv.c_str());
					//cout<<minc<<endl;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						comp+=tmp[i];
					}
					i++;
					for(;i<tmp.size() && tmp[i]!='|';i++){
						av+=tmp[i];
					}
					i++;
					conv="";
					for(;i<tmp.size() && tmp[i]!='|';i++){
						conv+=tmp[i];
					}
					i++;
					n_pass=atoi(conv.c_str());

					for(;i<tmp.size() && tmp[i]!='|';i++){
						origem+=tmp[i];
					}
					i++;

					for(;i<tmp.size() && tmp[i]!='|';i++){
						destino+=tmp[i];
					}
					i++;
					bool arquivado;
					string arqt="";

					for(;i<tmp.size() && tmp[i]!='\n' && tmp[i]!='|';i++){
						arqt+=tmp[i];
						//cout<<"arquivado "<<arqt<<endl;
					}
					i++;
					//cout<<"Final"<<tmp[i]<<endl;
					arquivado=atoi(arqt.c_str());
					Plano_de_voo tmppv(horap,minp,diap,mesp,anop,horac,minc,diac,mesc,anoc, aeroporto.apt_companhia(comp),origem, destino, aeroporto.apt_companhia(comp)->aviao_ptr(av),n_pass);
					tmppv.set_arq(arquivado);
					//cout<<tmppv<<endl; //
					plat.push_back(tmppv);

				}
			}
			passageiro tmp(nome, BI, plat);
			aeroporto.PassIn(tmp);

		}
	}

}


void save(){
	fstream filecomp;
	filecomp.open(filenamecomp.c_str(),fstream::out |fstream::trunc);
	if(filecomp.is_open()){
		filecomp<<aeroporto.getNome()<<endl;
		filecomp<<aeroporto.getTaxa()<<endl;
		for(size_t i=0;i<aeroporto.getNumeroComp();i++){
			filecomp<<*aeroporto.apt_companhia(i);
			fstream compav;
			string filenameav=aeroporto.apt_companhia(i)->getSigla()+"av.txt";
			compav.open(filenameav.c_str(),fstream::out |fstream::trunc);
			if(compav.is_open()){
				for(size_t j=0; j<aeroporto.apt_companhia(i)->getAvioes().size(); j++){
					compav<<*aeroporto.apt_companhia(i)->aviao_ptr(j);
				}
			}
			compav.close();
			fstream comptr;
			string filenametr=aeroporto.apt_companhia(i)->getSigla()+"tr.txt";
			comptr.open(filenametr.c_str(),fstream::out |fstream::trunc);
			if(comptr.is_open()){
				for(size_t j=0; j<aeroporto.apt_companhia(i)->getTripulantes().size(); j++){
					comptr<<*aeroporto.apt_companhia(i)->tripulante_ptr(j);
				}
			}
			comptr.close();
		}
	}


	filecomp.close();

	//********planos*******

	fstream planos;
	planos.open(filenameplanos.c_str(),fstream::out |fstream::trunc);
	if(planos.is_open()){
		for(size_t i=0;i<aeroporto.getNumPlanos();i++){
			planos<<*aeroporto.getPlano(i)<<endl;

		}
	}

	//*****passageiros****
	fstream passageiros;
	string filename_pass="Passageiros.txt";
	passageiros.open(filename_pass.c_str(),fstream::out |fstream::trunc);
	if(passageiros.is_open()){
		Passageiro_tb a=aeroporto.getPassageiros();
		passageiros<<a;
	}

}



void ver_planos(){
	cout<<"Planos de voo\n"<<endl;
	if(aeroporto.getNumPlanos()==0){
		cout<<"\nNao existem planos de voo disponiveis\n\n"<<endl;
	}
	cout<<"partida: <ano | mes | dia | hora | minutos> | chegada : <ano | mes | dia | hora | minutos> | companhia | matricula do aviao | num de passageiros | origem | destino"<<endl<<endl;
	for(size_t i=0; i<aeroporto.getNumPlanos(); i++){
		cout<<*(aeroporto.getPlano(i))<<endl;
	}
}

void mostra_companhias(){

	for(size_t i=0; i<aeroporto.getNumeroComp();i++){
		cout<<*(aeroporto.apt_companhia(i))<<endl;
	}
}


void addcomp(){
	cout<<"Adicao de companhia"<<endl;
	string sigla,name;
	cout<<"Sigla: ";
	getline(cin,sigla);
	cout<<"Nome: ";
	getline(cin,name);
	try{
		aeroporto.add_companhia(sigla,name);
	}
	catch(Companhia_ja_existe & x){
		cout<<x<<endl;
	}
	cout<<"Companhia Aerea criada com sucesso"<<endl<<endl;


}



void gerenciar_comp(){
	cout<<"Gerir companhia aerea"<<endl;
	vector<string> nomes(aeroporto.nomes_companhias());
	vector<funcao_generica> funcoes(nomes.size(),&sair);

	gerir_comp(aeroporto.apt_companhia(menu_generico(nomes,funcoes)-1));
}

void ver_av(Companhia_aerea* comp){
	cout<<"Avioes::::\n"<<"<matricula>|<nome>|<Peso>|<Tipo>|<Descricao>|<categoria>"<<endl;
	for(size_t i=0;i<comp->getAvioes().size(); i++){
		cout<<*comp->aviao_ptr(i)<<endl;
	}
}

void ver_tr(Companhia_aerea* comp){
	cout<<"Tripulantes::::\n"<<"<numero>|<salario_hora>|<categoria>|<Nome>"<<endl;
	for(size_t i=0;i<comp->getTripulantes().size(); i++){
		cout<<*comp->tripulante_ptr(i)<<endl;
	}
}

void gerir_comp(Companhia_aerea* comp){
	cout<<*comp<<endl;
	string names_ar[]={"ver avioes","Adiconar aviao:","Apagar aviao:","editar aviao","Adicionar plano de voo", "Ver Tripulantes","Adicionar Tripulante", "Apagar tripulante","editar tripulante","apagar companhia","sair"};
	funcao func_ar[]={&ver_av,&addav,&delav,&editav,&gerav,&ver_tr,&addtri,&deltri,&edittri,&delcomp,&sair};
	vector<string> names(&names_ar[0],&names_ar[11]);
	vector<funcao> func(&func_ar[0],&func_ar[11]);
	int opt=0;
	while(opt!=11 && opt!=10){
		opt=menu_companhia(names,func,comp);
	}


}

void planos(Companhia_aerea* comp, Aviao* av){

	int ano=-1,mes=-1,dia=-1,hora=-1,min=-1;
	cout<<"****Partida***";
	cout<<"\nAno: ";
	string pesotmp;
	while(ano<0){
		getline(cin, pesotmp);
		ano=atoi(pesotmp.c_str());
	}
	cout<<"\nmes: ";
	while(mes<=0 || mes>12){
		getline(cin, pesotmp);
		mes=atoi(pesotmp.c_str());
	}
	cout<<"\ndia: ";
	while(dia<=0 || dia>31 ){
		getline(cin, pesotmp);
		dia=atoi(pesotmp.c_str());
	}
	cout<<"\nhora: ";
	while(hora<0 || hora>=24){
		getline(cin, pesotmp);
		hora=atoi(pesotmp.c_str());
	}
	cout<< "\nmin: ";
	while(min<0 || min>=60){
		getline(cin, pesotmp);
		min=atoi(pesotmp.c_str());
	}

	int ano_c=-1,mes_c=-1,dia_c=-1,hora_c=-1,min_c=-1;
	cout<<"****Chegada***";
	cout<<"\nano_c: ";

	while(ano_c<0){
		getline(cin, pesotmp);
		ano_c=atoi(pesotmp.c_str());
	}
	cout<<"\nmes_c: ";
	while(mes_c<=0 || mes_c>12){
		getline(cin, pesotmp);
		mes_c=atoi(pesotmp.c_str());
	}
	cout<<"\ndia_c: ";
	while(dia_c<=0 || dia_c>31 ){
		getline(cin, pesotmp);
		dia_c=atoi(pesotmp.c_str());
	}
	cout<<"\nhora_c: ";
	while(hora_c<0 || hora_c>=24){
		getline(cin, pesotmp);
		hora_c=atoi(pesotmp.c_str());
	}
	cout<< "\nmin_c: ";
	while(min_c<0 || min_c>=60){
		getline(cin, pesotmp);
		min_c=atoi(pesotmp.c_str());
	}

	string origem,destino;
	cout<<"\nOrigem: ";
	getline(cin,origem);
	cout<<"\nDestino: ";
	getline(cin,destino);
	cout<< "\npassageiros: ";
	int np=-1;
	while(np<=0){
		getline(cin, pesotmp);
		np=atoi(pesotmp.c_str());
	}

	Plano_de_voo tmp(hora,min,dia,mes,ano,hora_c,min_c,dia_c,mes_c,ano_c, comp,origem, destino, av,np);

	if(tmp.valid()==false){
		cout<<"Dados invalidos"<<endl;
	}
	else{
		if(aeroporto.add_plano(tmp)==false){
			cout<<"Incompativel"<<endl;
		}else {
			cout<<"Plano de voo adicionado com sucesso"<<endl;
		}
	}



}

void gerav(Companhia_aerea* comp){
	int opt=menu(comp->getAvioes());

	planos(comp,comp->aviao_ptr(opt));
}

void delcomp(Companhia_aerea* comp){
	if(aeroporto.del_companhia(comp)){
		cout<<"Companhia Apagada"<<endl;
	}
	else{
		cout<<"Companhia n‹o existe"<<endl;
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
	cout<<"Aviao adicionado com sucesso"<<endl;
}
void delav(Companhia_aerea* comp){
	int opt=menu(comp->getAvioes());
	if(opt>=0){
		aeroporto.apaga_pv_aviao(comp,comp->aviao_ptr(opt));
		comp->delete_plane(opt);
	}
}
void editav(Companhia_aerea* comp){
	cout<<"***Edicao de avioes todos os dados anteriores s‹o perdidos..."<<endl<<endl;
	delav(comp);
	addav(comp);

}
void addtri(Companhia_aerea* comp){
	int numero=-1,salario_hora=-1;
	string categoria,nome;
	cout<<"\nnumero: ";
	string pesotmp;
	while(numero<=0){
		getline(cin, pesotmp);
		numero=atoi(pesotmp.c_str());
	}
	cout<<"Categoria: ";
	getline(cin, categoria);
	cout<<"Nome: ";
	getline(cin, nome);
	cout<<"\nSalario por hora: ";
	while(salario_hora<=0){
		getline(cin, pesotmp);
		salario_hora=atoi(pesotmp.c_str());
	}

	Tripulante tmp(numero,categoria, nome,salario_hora);
	try{
		comp->add_crew(tmp);
	}
	catch (trip_ja_existe & x){
		cout<<x<<endl;
	}
	cout<<tmp<<"\n foi criado com sucesso"<<endl;
}

void deltri(Companhia_aerea* comp){
	int opt=menu(comp->getTripulantes());
	if(opt>=0){
		comp->delete_crew(opt);
	}

}
void edittri(Companhia_aerea* comp){
	cout<<"***Edicao de tripulantes todos os dados anteriores s‹o perdidos..."<<endl<<endl;
	deltri(comp);
	addtri(comp);
}


void sair(){}
void sair(Companhia_aerea* comp){}
