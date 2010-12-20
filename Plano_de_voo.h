#ifndef PLANO_DE_VOO_H_
#define PLANO_DE_VOO_H_


#include "Companhia.h"
/**
 * data structure for dates and hours so it can be easier for us to do CRUD instructions in the airport flights
 */
struct horas_data{
	int hora;
	int min;
	int dia;
	int mes;
	int ano;
public:
	bool operator<(const horas_data &b) const{
		horas_data a=*this;
		if(a.ano<b.ano){
			return true;
		}else{
			if(a.ano==b.ano){
				if(a.mes<b.mes){
					return true;
				}
				else{
					if(a.mes==b.mes){
						if(a.dia<b.dia){
							return true;
						}
						else{
							if(a.dia==b.dia){
								if(a.hora<b.hora){
									return true;
								}
								else{

									if(a.hora==b.hora){
										if(a.min<b.min){
											return true;
										}
										else{
											return false;
										}
									}

								}

							}
						}
					}
				}
			}
		}
		return false;
	}
	bool operator>(const horas_data &b) const{
		horas_data a=*this;
		if(a.ano>b.ano){
			return true;
		}else{
			if(a.ano==b.ano){
				if(a.mes>b.mes){
					return true;
				}
				else{
					if(a.mes==b.mes){
						if(a.dia>b.dia){
							return true;
						}
						else{
							if(a.dia==b.dia){
								if(a.hora>b.hora){
									return true;
								}
								else{

									if(a.hora==b.hora){
										if(a.min>b.min){
											return true;
										}
										else{
											return false;
										}
									}

								}

							}
						}
					}
				}
			}
		}
		return false;
	}
	bool operator==(const horas_data &b) const{
		horas_data a=*this;
		if(a.ano!=b.ano){
			return false;
		}else{
			if(a.mes!=b.mes){
				return false;
			}
			else{
				if(a.dia!=b.dia){
					return false;
				}
				else{
					if(a.hora!=b.hora){
						return false;
					}
					else{
						if(a.min!=b.min){
							return false;
						}
						else{
							return true;
						}
					}

				}

			}
		}
	}


};


/**
 *
 *
 */

class Plano_de_voo {
private:
	horas_data partida;
	horas_data chegada;
	int n_do_voo;
	string origem;
	string destino;
	Aviao* aviao;
	Companhia_aerea* companhia;
	int n_passageiros;
	bool arquivado;
	bool pista;
	bool parte;

public:

	Plano_de_voo(){}
	Plano_de_voo(int hora_partida,int min_partida, int dia_partida, int mes_partida, int ano_partida, int hora_chegada,int min_chegada, int dia_chegada, int mes_chegada, int ano_chegada, Companhia_aerea* companhia, string origem, string destino, Aviao* aviao, int n_passageiros);

	/**
	 * Allows the user to see on the screen the information about the flight plan
	 *
	 * @param ostream &out
	 * @param Plano_de_voo x
	 * @return an ostream with the intel of the flight plan
	 */
	friend ostream & operator<<(ostream &out, Plano_de_voo x){
		out<<x.partida.ano<<'|'<<x.partida.mes<<'|'<<x.partida.dia<<'|'<<x.partida.hora<<'|'<<x.partida.min<<'|'
				<<x.chegada.ano<<'|'<<x.chegada.mes<<'|'<<x.chegada.dia<<'|'<<x.chegada.hora<<'|'<<x.chegada.min<<'|'<<x.companhia->getSigla()<<'|'<<x.aviao->getMatricula()<<'|'<<x.n_passageiros<<'|'<<x.origem<<'|'<<x.destino<< '|'<<x.arquivado<<endl;
		return out;
	}


	virtual ~Plano_de_voo();

	bool valid();
	/**
	 * Returns a pointer of a plane
	 * @name *getAviao
	 * @return pointer of a plane
	 */
	Aviao *getAviao() const;
	/**
	 * Returns date and hour of plane arrival to the airport
	 * @name getChegada
	 * @return date and time through the horas_data structure
	 *
	 */
	horas_data getChegada() const;
	/**
	 * Returns a pointer of an airplane company
	 * @name *getCompanhia
	 * @return pointer of an airplane company
	 */
	Companhia_aerea *getCompanhia() const;
	/**
	 * Returns a string with the destination of the flight
	 * @name getDestino
	 * @return flight destination
	 */
	string getDestino() const;
	/**
	 * Returns the flight number
	 * @name getDo_voo
	 * @return flight number
	 */
	int getDo_voo() const;
	/**
	 * Returns a string with the flight origin information
	 * @name getOrigem
	 * @return flight origin
	 */
	string getOrigem() const;
	/**
	 * Returns date and hour of an airplane depart
	 * @name getPartida
	 * @return date and time through the horas_data structure
	 */
	horas_data getPartida() const;
	/**
	 * Returns the number of passengers
	 * @name getPassageiros
	 * @return the number of passengers
	 */
	int getPassageiros() const;
	/**
	 * This sets an Airplane, this->aviao = aviao
	 * @name setAviao
	 * @param Aviao *aviao
	 */
	void setAviao(Aviao *aviao);
	/**
	 * This sets the airplane arrival, date and time
	 * @name setChegada
	 * @param horas_data chegada
	 */
	void setChegada(horas_data chegada);
	/**
	 * This sets the data member companhia = parameter companhia
	 * @name setCompanhia
	 * @param Companhia_aerea *companhia
	 */
	void setCompanhia(Companhia_aerea *companhia);
	/**
	 * This sets the data member destino = parameter destino
	 * @name setDestino
	 * @param string destino
	 */
	void setDestino(string destino);
	/**
	 * This sets the data member n_do_voo = parameter n_do_voo
	 * @name setDo_voo
	 * @param int n_do_voo
	 */
	void setDo_voo(int n_do_voo);
	/**
	 * This sets the data member origem = parameter origem
	 * @name setOrigem
	 * @param string origem
	 */
	void setOrigem(string origem);
	/**
	 * This sets the airplane departure, date and time
	 * @name setPartida
	 * @param horas_data partida
	 */
	void setPartida(horas_data partida);
	/**
	 * This sets the data member n_passageiros = parameter n_passageiros
	 * @name setPassageiros
	 * @param int n_passageiros
	 */
	void setPassageiros(int n_passageiros);
	/**
	 * Comparison between a flight plan A with another one named B
	 * @name Compatible
	 * @param Plano_de_voo &a
	 * @param Plana_de_voo &b
	 * @return 0 if the flight plans put themselfs upon each other and 1 if they don't
	 */
	friend bool Compatible(Plano_de_voo &b, Plano_de_voo &a){
		if(*(a.getCompanhia())==*(b.getCompanhia()) && *(a.getAviao())==*(b.getAviao())){
			if((b.partida.ano>=a.partida.ano && b.chegada.ano<=a.chegada.ano)){
				if((b.partida.mes>=a.partida.mes && b.chegada.mes<=a.chegada.mes)){
					if((b.partida.dia>=a.partida.dia && b.chegada.dia<=a.chegada.dia)){
						if((b.partida.hora>=a.partida.hora && b.chegada.hora<=a.chegada.hora)){
							if((b.partida.min>=a.partida.min && b.chegada.min<=a.chegada.min)){
								return false;
							}
							else{
								return true;
							}
						}
						else{
							return true;
						}

					}
					else{
						return true;
					}
				}
				else{
					return true;
				}
			}
			else{
				return true;
			}
		}
		else{
			return true;
		}

	}

	const bool a_chega_pr_b(const Plano_de_voo & A,const Plano_de_voo & B)const{
		return A.chegada<B.chegada;
	}
	const bool a_parte_pr_b(const Plano_de_voo & A,const Plano_de_voo & B)const{
		return A.partida<B.partida;
	}

	bool operator==(const Plano_de_voo & a) const{
		return (this->n_do_voo==a.getDo_voo() && this->partida==a.getPartida() && this->chegada==a.getChegada() && this->companhia==a.getCompanhia());
	}

	bool is_arquivado(){
		return arquivado;
	}

	bool is_pista(){
		return pista;
	}

	void arquivar(){
		arquivado=true;
	}

	void por_pista(){
		pista=true;
	}

	bool operator<(const Plano_de_voo & a) const{
		if(parte)
			return (this->partida<a.getPartida());
		else{
			return this->chegada<a.getChegada();
		}
	}

	void tipo(const string &nome_aeroporto){
		if(nome_aeroporto==origem){
			parte=true;
		}
		else{
			if(nome_aeroporto==destino){
				parte=false;
			}
			else{
				//erro
			}
		}
	}

	void set_arq(bool arq){
		arquivado=arq;
	}

	bool get_arquivado(){
		return arquivado;
	}
	bool get_parte(){
		return parte;
	}

};

#endif /* PLANO_DE_VOO_H_ */
