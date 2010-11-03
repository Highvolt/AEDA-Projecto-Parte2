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




class Companhia_aerea{
private:
	vector<Tripulante*> tripulantes;
	vector<Aviao*> avioes;
	string sigla, nme_companhia;
public:
	Companhia_aerea(string & sigla, string & nme_companhia);
	int add_plane(Aviao aviao);
	int delete_plane(Aviao aviao);
	int delete_plane(int i);
	int add_crew(Tripulante tripulante);
	int delete_crew(Tripulante tripulante);
	int delete_crew(int i);
    vector<Aviao*> getAvioes() const;
    string getSigla() const;
    vector<Tripulante*> getTripulantes() const;
    void setAvioes(vector<Aviao*> avioes);
    void setSigla(string sigla);
    void setTripulantes(vector<Tripulante*> tripulantes);


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

};

class Tipo_de_aviao{
private:
	string tipo;
	string descricao;
	string categoria;
public:
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

class Aviao: public Tipo_de_aviao{
private:
	string matricula;
	string nome;
	int peso;

public:
	Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria);
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




#endif
