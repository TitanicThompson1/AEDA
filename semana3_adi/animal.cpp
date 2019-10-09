
#include "animal.h"
#include <sstream>
using namespace std;

/*
 * Classe Animal
 */

int Animal::maisJovem=-1;

//Construtor
Animal::Animal(string nome, int idade)
{
    this->nome= nome;
    this->idade= idade;
    if(idade < maisJovem || maisJovem<0)
        maisJovem=idade;
    vet= NULL;

}

//Metodos GET

int Animal::getMaisJovem() {return maisJovem;}

string Animal::getNome() const {
	return nome;
}

//Metodos SET

void Animal::setVeterinario(Veterinario *vet) { this->vet=vet;}

//Outros Metodos

string Animal::getInformacao() const
{
    string vete="";
    if(vet!=NULL)
        return nome+", "+to_string(idade)+", "+vet->getInfo();
    else
        return nome+", "+to_string(idade);
}

Veterinario* Animal::getVeterinario() const { return vet;}

/*
 * Classe Cao
 */

//Construtor

Cao::Cao(string nome, int idade, string raca): Animal(nome,idade)
{
    this->raca=raca;
}

//Outros Metodos
bool Cao::eJovem() const
{
    if(idade<5)
        return true;
    return false;
}

string Cao::getInformacao() const
{
    string result= Animal::getInformacao()+", "+raca;
    return result;
}

/*
 * Classe Voador
 */

//Construtor

Voador::Voador(int vmax, int amax)
{
    velocidade_max= vmax;
    altura_max= amax;
}

string Voador::getInformacao() const
{
    string result= to_string(velocidade_max) + ", " + to_string(altura_max);
    return result;
}

/*
 * Classe Morcego
 */

//Construtor
Morcego::Morcego(string nome, int idade, int vmax, int amax): Animal(nome,idade), Voador(vmax,amax){}

//Outros Metodos
bool Morcego::eJovem() const
{
    if(idade<4)
        return true;
    return false;
}

string Morcego::getInformacao() const
{

    string result=Animal::getInformacao()+", "+Voador::getInformacao();
    return result;
}




