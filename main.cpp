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
#include <fstream>

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
void delcomp(Companhia_aerea* comp);
void gerav(Companhia_aerea* comp);
void mostra_companhias();
void ver_planos();

//*********

Aeroporto aeroporto;


int main(){

	string names_ar[]={"Adiconar companhia:","gerenciar companhia","ver companhias","ver Planos","sair"};
	funcao_generica func_ar[]={&addcomp,&gerenciar_comp,&mostra_companhias,&ver_planos,&sair};
	vector<string> names(&names_ar[0],&names_ar[5]);
	vector<funcao_generica> func(&func_ar[0],&func_ar[5]);
	int opt=0;
	while (opt!=5){
		opt=menu_generico(names,func);

	}


	return 0;
}


void save(){

}

void ver_planos(){
	cout<<"Planos de voo"<<endl;
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
	getline(cin,sigla);
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

void gerir_comp(Companhia_aerea* comp){
	cout<<*comp<<endl;
	string names_ar[]={"Adiconar aviao:","Apagar aviao:","editar aviao","Adicionar plano de voo", "Adicionar Tripulante", "Apagar tripulante","editar tripulante","apagar companhia","sair"};
	funcao func_ar[]={&addav,&delav,&editav,&gerav,&addtri,&deltri,&edittri,&delcomp,&sair};
	vector<string> names(&names_ar[0],&names_ar[9]);
	vector<funcao> func(&func_ar[0],&func_ar[9]);
	int opt=0;
	while(opt!=9 && opt!=8){
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
void edittri(Companhia_aerea* comp){}


void sair(){}
void sair(Companhia_aerea* comp){}
