//
// Created by Ricardo Nunes on 08/11/2019. mudei
//

#include "gerirImoveis.h"


void adicionaImovel(vector<Imovel> &imoveis, uint id){

    string tipo, nome;
    Address morada;
    uint area;

    string tiposPoss[3]={"vivenda","apartamento","casa"};

    //Pede para o utilizador inserir o tipo de Imovel. Se inserir mal, repete até fazer acertadamente
    tipo=verificaValores('=',"Insire o tipo de imovel:  ", tiposPoss, 3);

    cout << "Insira o nome do seu Imovel:  "; cin.ignore(); getline(cin, nome);
    cout << endl;

    cout << "Morada" << endl;

    //Funcao definida em gerirAddress que pede a Morada
    morada= insereMorada();

    cout << "Insira a area do seu Imovel:  "; cin >> area;

    //cria vetor de intervalos vazio(uma vez que, se cria imovel novo, nao existem reservas)
    vector<Intervalo> inter;

    Imovel i1(tipo,nome,area,morada, 0, inter,id);

    //Se existir um imovel com a mesma morada, lança uma execção
    if(find(imoveis.begin(),imoveis.end(),i1) != imoveis.end())
        throw ImovelJaExistente(nome);


    imoveis.push_back(i1);
}

void eliminaImovel(vector<Imovel> &imoveis, uint idI)
{

    bool encontrou=false;
    int count=0;
    for(auto it=imoveis.begin();it!=imoveis.end();it++){

        //Apaga imovel
        if(!encontrou && it->getId()==idI){
            imoveis.erase(it);
            it--;
            encontrou=true;
        }else if(encontrou){    //se ja o encontrou, atualiza os proximos ids
            it->setId(count);
        }
        count++;
    }
    if (!encontrou)
        throw ImovelInexistente(idI);
}

void alteraImovel(Imovel &I, uint campo,vector<Contrato*> &contratos)
{
    string tiposPoss[3]={"vivenda","apartamento","casa"};
    string tipo, nome;
    Address morada;
    uint area;

    switch (campo)
    {
        case 1:
            tipo=verificaValores('=',"Insire o tipo de imovel:  ", tiposPoss, 3);
            I.setTipo(tipo);
            break;
        case 2:
            cout << "Insira o nome do seu Imovel:  "; cin.ignore(); getline(cin, nome);
            I.setNome(nome);
            break;
        case 3:
            cout << "Morada" << endl;
            morada= insereMorada();
            //Verificar se morada já existe
            I.setAddress(morada);
            break;
        case 4:
            cout << "Insira a area do seu Imovel:  "; cin >> area;
            I.setArea(area);
            break;
        case 5:
            alteraContrato(I,contratos);
            break;
        default:
            break;
    }

}

void displayImoveis(const vector<Imovel> &imoveis)
{
    cout << setw(4) << "ID"; cout << "|";
    cout << setw(14) <<  "Tipo"; cout << "|";
    cout << setw(40) << "Nome"; cout << "|";
    cout << setw(8) << "Area"; cout << "|";
    cout << setw(49) << "Morada" << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;


    for(int i=0;i<imoveis.size();i++){
        cout << setw(4) << imoveis.at(i).getId(); cout << "|";
        cout << setw(14) <<  imoveis.at(i).getTipo(); cout << "|";
        cout << setw(40) << imoveis.at(i).getNome(); cout << "|";
        cout << setw(8) << imoveis.at(i).getArea(); cout << "|";
        cout << setw(49) << imoveis.at(i).getAddress().getAddressFormated() << endl;
    }
}

void listarImoveis(vector<Imovel> &imoveis){
    for(int i=0;i<imoveis.size();i++){
        cout << (i+1) << " - " << imoveis.at(i).getNome() << endl;
    }
}


int procuraIdEmImoveis(const vector<Imovel> &im, uint id){
    int result=-1;
    for (int i=0;i<im.size();i++){
        if(im.at(i).getId()==id){
            result=i;
            break;
        }
    }
    return result;
}