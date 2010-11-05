/*
 * Voos.h
 *
 *  Created on: 10 de Out de 2010
 *      Author: pedroborges
 */

#ifndef COMPANHIA_H_
#define COMPANHIA_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Tripulante;
class Aviao;

class Tipo_de_aviao{
private:
	string tipo;
	string descricao;
	string categoria;
public:

	Tipo_de_aviao(){
		this->tipo="";
		this->descricao="";
		this->categoria="";
	}

	Tipo_de_aviao(string tipo, string descricao, string categoria);
	string getCategoria() const
	{
		return categoria;
	}

	string getDescricao() const
	{
		return descricao;
	}

	string getTipo() const
	{
		return tipo;
	}

	void setCategoria(string categoria)
	{
		this->categoria = categoria;
	}

	void setDescricao(string descricao)
	{
		this->descricao = descricao;
	}

	void setTipo(string tipo)
	{
		this->tipo = tipo;
	}

};

class Aviao:public Tipo_de_aviao{
private:
	string matricula;
	string nome;
	int peso;


public:
	Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria);
	friend ostream & operator<<(ostream & out, Aviao x){
		out<<x.matricula<<'|'<<x.nome<<'|'<<x.peso<<'|'<<x.getTipo()<<'|'<<x.getDescricao()<<'|'<<x.getCategoria()<<endl;
		return out;
	}
	string getMatricula() const
	{
		return matricula;
	}

	string getNome() const
	{
		return nome;
	}

	int getPeso() const
	{
		return peso;
	}

	void setMatricula(string matricula)
	{
		this->matricula = matricula;
	}

	void setNome(string nome)
	{
		this->nome = nome;
	}

	void setPeso(int peso)
	{
		this->peso = peso;
	}

	bool operator==(const Aviao &b){
		return this->matricula==b.matricula;
	}
};


class Companhia_aerea{
private:
	vector<Tripulante> tripulantes;
	vector<Aviao> avioes;
	string sigla, nme_companhia;
public:
	Companhia_aerea(string & sigla, string & nme_companhia);
	int add_plane(Aviao aviao);
	Aviao *aviao_ptr(int i){
		if(i>=0 &&i<avioes.size()){
			return &avioes[i];
		}
	}
	Aviao *aviao_ptr(string mat){
		for(size_t i=0;i<avioes.size();i++){
			if(avioes[i].getMatricula()==mat){
				return &avioes[i];
			}
		}
	}
	Tripulante *tripulante_ptr(int i){
		if(i>=0 &&i<tripulantes.size()){
			return &tripulantes[i];
		}
	}
	int delete_plane(Aviao aviao);
	int delete_plane(int i);
	int add_crew(Tripulante tripulante);
	int delete_crew(Tripulante tripulante);
	int delete_crew(int i);
	vector<string> getPlanesnames();
	vector<Aviao> getAvioes() const;
	string getSigla() const;
	vector<Tripulante> getTripulantes() const;
	string getNome(){
		return this->nme_companhia;
	}
	void setAvioes(vector<Aviao> avioes);
	void setSigla(string sigla);
	void setTripulantes(vector<Tripulante> tripulantes);
	bool operator==(Companhia_aerea & a){
		return this->sigla==a.getSigla();
	}
	friend ostream & operator<<(ostream & out, Companhia_aerea x){
		out<<x.sigla<<'|'<<x.nme_companhia<<endl;
		return out;
	}


};




class Tripulante{
private:
	int numero;
	int salario_hora;
	string categoria;
	string nome;


public:
	Tripulante(int numero, string categoria, string nome, int salario_hora);
	string getCategoria() const;
	string getNome() const;
	int getNumero() const;

	int getSalario_hora() const;
	void setCategoria(string categoria);
	void setNome(string nome);
	void setNumero(int numero);
	void setSalario_hora(int salario_hora);
	bool operator==(const Tripulante &b){
		return this->numero==b.numero;
	}
	friend ostream & operator<<(ostream & out, Tripulante x){
		out<<x.numero<<'|'<<x.salario_hora<<'|'<<x.categoria<<'|'<<x.nome<<endl;
		return out;
	}
};




class aviao_ja_existe{
private:
	Aviao* existente;
public:
	aviao_ja_existe(Aviao* aviao){
		existente=aviao;
	}
	friend ostream & operator<<(ostream & out, aviao_ja_existe Dados){
		out<<"O Aviao com a matricula "<<Dados.existente->getMatricula()<<" ja existe"<<endl;
		return out;
	}
};

class aviao_nao_existe{
private:
	Aviao* existente;
public:
	aviao_nao_existe(Aviao* aviao){
		existente=aviao;
	}
	friend ostream & operator<<(ostream & out, aviao_nao_existe Dados){
		out<<"O Aviao com a matricula "<<Dados.existente->getMatricula()<<" nao existe"<<endl;
		return out;
	}
};

class trip_ja_existe{
private:
	Tripulante* existente;
public:
	trip_ja_existe(Tripulante* aviao){
		existente=aviao;
	}
	friend ostream & operator<<(ostream & out, trip_ja_existe Dados){
		out<<"O tripulante numero"<<Dados.existente->getNumero()<<" ja existe"<<endl;
		return out;
	}
};


#endif
