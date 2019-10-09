
#include "veterinario.h"
#include <sstream>
using namespace std;

//Construtor
Veterinario::Veterinario(string nome, int cod)
{
    this->nome=nome;
    codOrdem= cod;
}


string Veterinario::getNome() const {
	return nome;
}

string Veterinario::getInfo() const
{

    return nome+", "+to_string(codOrdem);
}



