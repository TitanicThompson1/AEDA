#include "zoo.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

/*
 * Classe Zoo
 */

//Construtor
/*
Zoo::Zoo(vector<Animal *> _animais,vector<Veterinario *> _veterinarios)
{
    animais=_animais;
    veterinarios=_veterinarios;
}
 */

int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1){ animais.push_back(a1);}

string Zoo::getInformacao() const
{
    string result="";
    for(int i=0;i<animais.size();i++)
    {
         result+= animais.at(i)->getInformacao();
    }
    return result;
}

bool Zoo::animalJovem(string nomeA)
{
    for(int i=0;i<animais.size();i++)
    {
        if(animais.at(i)->getNome()== nomeA)
        {
            if (animais.at(i)->eJovem())
                return true;
            return false;
        }

    }
    return false;
}

void Zoo::alocaVeterinarios(istream &isV)
{
    string nome,sCod;
    long cod;
    istringstream temp;

    while(getline(isV,nome)) {

        getline(isV, sCod);
        cod=stoi(sCod);
        Veterinario *vete = new Veterinario(nome, cod);
        veterinarios.push_back(vete);

    }

    int j=0, vet_size=veterinarios.size();

    for(int i=0;i<animais.size();i++)
    {
        j= i%vet_size;
        animais.at(i)->setVeterinario(veterinarios.at(j));
    }

}

bool Zoo::removeVeterinario (string nomeV)
{
    bool found=false;
    int i=-1;
    int ab=veterinarios.size();
    bool teste=i<ab;
    //cout << veterinarios.size() << endl;

    while(!found && i<(int)veterinarios.size())
    {

        if(veterinarios.at(i)->getNome()==nomeV)
            found=true;
        i++;
    }
    i--;
    if(!found)
        return found;
    Veterinario *v=veterinarios.at(i);

    vector <Veterinario*>::iterator ve=veterinarios.erase(veterinarios.begin()+i);
    if(ve==veterinarios.end())
        ve=veterinarios.begin();

    for(int a=0;a<animais.size();a++)
    {
        if(animais.at(a)->getVeterinario()==v)
        {
            animais.at(a)->setVeterinario(*ve);
        }

        cout << veterinarios.at(a)->getInfo() << endl;
    }

    return true;

}
bool Zoo::operator<(Zoo &zoo2) const
{
    int soma1=0,soma2=0;
    for(int i=0;i<animais.size();i++)
    {
        soma1+=animais.at(i)->getIdade();
    }
    for(int i=0;i<zoo2.animais.size();i++)
    {
        soma2+=zoo2.animais.at(i)->getIdade();
    }
    if (soma1<soma2)
        return true;
    else
        return false;
}