
#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "veterinario.h"
#include <string>
using namespace std;


class Animal {
protected:
    /** nome do animal */
    string nome;
    /** idade do animal */
    int idade;
    /**Apontador para o veterinario do animal*/
    Veterinario *vet;
    /**Variavel global com a idade do animal mais jovem*/
    static int maisJovem;
public:
    /**Construtor da classe animal
     *
     * @param nome
     * @param idade
     */
    Animal(string nome, int idade);

    /**Obtem a idade do animal mais jovem
     *
     * @return idade do animal mais jovemm
     */
    static int getMaisJovem();

    /**Destrutor da clasee amimal
     *
     */
    virtual ~Animal() {};

    /**Retorna o nome do animal
     *
     * @return
     */
    string getNome() const;

    virtual bool eJovem() const = 0;

    virtual string getInformacao() const;

    void setVeterinario(Veterinario *vet);

    Veterinario* getVeterinario() const;

    int getIdade() const {return idade;};
};


class Cao: public Animal {
	string raca;
public:
	Cao(string nome, int idade, string raca);
    bool eJovem() const;
    string getInformacao() const;
	//completar
};


class Voador {
	int velocidade_max;
	int altura_max;
public:
	Voador(int vmax, int amax);
    virtual ~Voador(){};
    virtual string getInformacao() const;
};


class Morcego: public Animal, public Voador {
public:
    bool eJovem() const;
	Morcego(string nome, int idade, int vmax, int amax);
	string getInformacao() const;
};


#endif /* SRC_ANIMAL_H_ */
