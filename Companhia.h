

#ifndef COMPANHIA_H_
#define COMPANHIA_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
 *class Tripulante iniciator
 */
class Tripulante;
/**
 *class Aviao iniciator
 */
class Aviao;

class Tipo_de_aviao{
private:
	string tipo;
	string descricao;
	string categoria;
public:
	/**
		 * class empty constructor for a airplane type
		 */
	Tipo_de_aviao(){
		this->tipo="";
		this->descricao="";
		this->categoria="";
	}

	Tipo_de_aviao(string tipo, string descricao, string categoria);
	/**
	 * returns airplane category
	 * @name getCategoria
	 * @return parameter categoria
	 */
	string getCategoria() const
	{
		return categoria;
	}
	/**
     * returns airplane description
     * @name getDescricao
     * @return parameter descricao
     */
	string getDescricao() const
	{
		return descricao;
	}
	/**
     * returns airplane type
     * @name getTipo
     * @return parameter tipo
     */
	string getTipo() const
	{
		return tipo;
	}
	/**
     * sets airplane category
     * @name setCategoria
     * @param string categoria
     */
	void setCategoria(string categoria)
	{
		this->categoria = categoria;
	}
	/**
     * sets airplane description
     * @name setDescricao
     * @param string descricao
     */
	void setDescricao(string descricao)
	{
		this->descricao = descricao;
	}
	/**
     * sets airplane type
     * @name setTipo
     * @param string tipo
     */
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
/**
	 * class constructor for a airplane
	 * @name Aviao
	 * @param string matricula
	 * @param string nome
	 * @param int peso
	 * @param string tipo
	 * @param string descricao
	 * @param string categoria
	 */
	Aviao(string matricula, string nome, int peso, string tipo, string descricao, string categoria);
	/**
	 * Allows the functions to display in the screen plane information
     * @param ostream & out
	 * @param Aviao x
     * @return a display in the screen plane information
	 */
	friend ostream & operator<<(ostream & out, Aviao x){
		out<<x.matricula<<'|'<<x.nome<<'|'<<x.peso<<'|'<<x.getTipo()<<'|'<<x.getDescricao()<<'|'<<x.getCategoria()<<endl;
		return out;
	}
	/**
     * returns airplane plate
     
     * @return parameter matricula
     */
	string getMatricula() const
	{
		return matricula;
	}
	/**
     * returns airplane name
     * @name getNome
     * @return parameter nome
     */
	string getNome() const
	{
		return nome;
	}
	/**
     * returns airplane weight
     * @name getPeso
     * @return parameter peso
     */
	int getPeso() const
	{
		return peso;
	}
	/**
     * sets airplane registration
     * @name setMatricula
     * @param string matricula
     */

	void setMatricula(string matricula)
	{
		this->matricula = matricula;
	}
	/**
     * sets airplane name
     * @name setNome
     * @param string nome
     *
     */
	void setNome(string nome)
	{
		this->nome = nome;
	}
	/**
     * sets airplane weight
     * @name setPeso
     * @param int peso
     */
	void setPeso(int peso)
	{
		this->peso = peso;
	}
	/**
     * Allows the functions to compare airplanes
     * @name ==
     * @param const Aviao &b
     * @return true if they are equal, if not returns false
     */
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
	/**
	 * class constructor for a air company
	 * Data maintenance: CRUD(create , read, update and remove) data related to crews and planes from a given Companhia_aerea
	 * @name COmpanhia_aerea
	 * @param string & sigla
	 * @param string & nme_companhia
	 *
	 */
	Companhia_aerea(string & sigla, string & nme_companhia);
	/**
	 * Add a plane to the vector avioes
	 * @name add_plane
	 * @param Aviao aviao
	 * @return 0 if the airplane is added with success  and -1 if it already exists in the vector
	 */
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
	/**
	 * Deletes a plane from vector avioes
	 * @name delete_plane
	 * @param Aviao aviao
	 * @return 0 if the airplane is found and erased from the vector and -1 if not found
	 */
	int delete_plane(Aviao aviao);
	/**
	 * deletes a plane from vector avioes by choosing the vector's position where the plane is
	 * @name delete_plane
	 * @param int i
	 * @return 0 if the airplane is erased with success, if not found returns -1
	 */
	int delete_plane(int i);
	/**
	 * adds a crew member to the vector tripulante
	 * @name add_crew
	 * @param Tripulante tripulante
	 * @return -1 if the crew member already exists, and 0 if it was added with success
	 */
	int add_crew(Tripulante tripulante);
	/**
	 * deletes a crew member from the vector tripulante
	 * @name delete_crew
	 * @param Tripulante tripulante
	 * @return 0 if airplane was found in the vector and erased, -1 if not found
	 */
	int delete_crew(Tripulante tripulante);
	/**
	 * deletes a crew member from vector tripulante by choosing the vector's position where the crew member is
	 * @name delete_crew
	 * @param int i
	 * @return 0 if airplane was found in the vector and erased, -1 if not found
	 */
	int delete_crew(int i);
	/**
	 * Returns a vector of string's with the airplane names
	 * @return vector names
	 */
	vector<string> getPlanesnames();
	/**
	 * returns the vector of all airplanes
	 * @name getAvioes
	 * @return vector aviao
	 */
	vector<Aviao> getAvioes() const;
	/**
     * returns the airline initials
     * @name getSigla
     * @return sigla
     */
	string getSigla() const;
	/**
     * return the vector of all crew members
     * @name getTripulantes
     * @return vector tripulantes
     */
	vector<Tripulante> getTripulantes() const;
	/**
     * returns airline name
     * @name getNome
     * @return nme_companhia
     */
	string getNome(){
		return this->nme_companhia;
	}
	/**
     * sets the data member avioes = parameter avioes
     * @name setAvioes
     * @param vector<Aviao> avioes
     *
     */
	void setAvioes(vector<Aviao> avioes);
	/**
     * sets the data member sigla = parameter sigla
     * @name setSigla
     * @param string sigla
     */
	void setSigla(string sigla);
	/**
     * sets the data member tripulantes = parameter tripulantes
     * @name setTripulantes
     * @param vector<Tripulante> tripulantes
     */
	void setTripulantes(vector<Tripulante> tripulantes);
	/**
     * Allows the functions to compare airlines
     * @name ==
     * @param Companhia_aerea & a
     * @return true if they are equal, if not returns false
     */
	bool operator==(Companhia_aerea & a){
		return this->sigla==a.getSigla();
	}
	/**
	 * Allows the functions to display in the screen the air company logo and name
     * @param ostream & out
	 * @param Companhia_aerea x
     * @return a display in the screen the air company logo and name
	 */
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
	/**
	 * class constructor for a tripulant
	 * @name Tripulante
	 * @param int numero
	 * @param string categoria
	 * @param string nome
	 * @param int salario_hora
	 */
	Tripulante(int numero, string categoria, string nome, int salario_hora);
	/**
	 * returns crew member category
	 * @name getCategoria
	 * @returns parameter categoria
	 */
	string getCategoria() const;
	/**
     * returns crew member name
     * @name getNome
     * @returns parameter nome
     */
	string getNome() const;
	/**
     * returns crew member number
     * @name getNumero
     * @returns parameter numero
     */
	int getNumero() const;
	 /**
     * returns how many received per hour by a crew member
     * @name getSalario_hora
     * @returns parameter salario_hora
     */

	int getSalario_hora() const;
	/**
     * sets crew member category
     * @name setCategoria
     * @param string categoria
     */
	void setCategoria(string categoria);
	 /**
     * sets crew member name
     * @name setNome
     * @param string nome
     *
     */
	void setNome(string nome);
	/**
     * sets crew member number
     * @name setNumero
     * @param int numero
     */
	void setNumero(int numero);
	/**
     * sets how many received per hour by a crew member
     * @name setSalaraio_hora
     * @param int salario_hora
     */
	void setSalario_hora(int salario_hora);
	 /**
     *   Allows the functions to compare crew members
     * @name ==
     * @param const Tripulante &b
     * @return true if they are equal, if not returns false
     *
     */
	bool operator==(const Tripulante &b){
		return this->numero==b.numero;
	}
	/**
	 * Allows the functions to display in the screen crew member registration
     * @param ostream & out
	 * @param Tripulante x
     * @return a display in the screen of a crew member registration
	 */
	friend ostream & operator<<(ostream & out, Tripulante x){
		out<<x.numero<<'|'<<x.salario_hora<<'|'<<x.categoria<<'|'<<x.nome<<endl;
		return out;
	}
};




class aviao_ja_existe{
private:
	Aviao* existente;
public:
	/**
	 * class constructor for a already existing airplane
	 * @name aviao_ja_existe
	 * @param Aviao* aviao
	 */
	aviao_ja_existe(Aviao* aviao){
		existente=aviao;
	}
	/**
	 * Allows the user to see on the screen the message that says the plane already exist
     * @param ostream & out
	 * @param aviao_ja_existe Dados
     * @return the message that says the plane already exist
	 */
	friend ostream & operator<<(ostream & out, aviao_ja_existe Dados){
		out<<"O Aviao com a matricula "<<Dados.existente->getMatricula()<<" ja existe"<<endl;
		return out;
	}
};

class aviao_nao_existe{
private:
	Aviao* existente;
public:
	/**
	 * class constructor for a non existing airplane
	 * @param Aviao* aviao
	 */
	aviao_nao_existe(Aviao* aviao){
		existente=aviao;
	}
	/**
	 * Allows the user to see on the screen the message that says the plane does not exist
     * @param ostream & out
	 * @param aviao_nao_existe Dados
     * @return the message that says the plane does not exist
	 */
	friend ostream & operator<<(ostream & out, aviao_nao_existe Dados){
		out<<"O Aviao com a matricula "<<Dados.existente->getMatricula()<<" nao existe"<<endl;
		return out;
	}
};

class trip_ja_existe{
private:
	Tripulante* existente;
public:
	/**
	 * class constructor for a already existing crew member
	 * @param Tripulante* aviao
	 */
	trip_ja_existe(Tripulante* aviao){
		existente=aviao;
	}
	/**
	 * Allows the user to see on the screen the message that says the crew member already exist
     * @param ostream & out
	 * @param trip_ja_existe Dados
     * @return the message that says the crew member already exist
	 */
	friend ostream & operator<<(ostream & out, trip_ja_existe Dados){
		out<<"O tripulante numero"<<Dados.existente->getNumero()<<" ja existe"<<endl;
		return out;
	}
};


#endif
