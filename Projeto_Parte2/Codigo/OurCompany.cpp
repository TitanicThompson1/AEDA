//
// Created by Ricardo Nunes on 12/11/2019.
//

#include "OurCompany.h"

void OurCompany::importCompany(const string &filename){

    string temp;

    ifstream infile(filename);
    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);

    //Extrai nome da empresa
    getline(infile,nome);

    //Extrai morada da empresa
    getline(infile,temp);
    morada.setAddress(temp);

    //Extrai nome do ficheiro de imoveis e importa os imoveis
    getline(infile,temp);
    imovelFile=temp;
    importaImoveis(imoveis,temp);

    //Extrai nome do ficheiro de registrados
    getline(infile,temp);
    clientsFile=temp;
    importaRegistrado(clientes,temp);

    //Extrai nome do ficheiro de contratos
    getline(infile,temp);
    contractFile=temp;
    importaContrato(contratos,contractFile);

    //Extrai nome do ficheiro de reservas
    getline(infile,temp);
    reservFile=temp;
    importaReservas(reservas,temp);


    //Extrai nome do ficheiro de leiloes
    getline(infile,temp);
    leilaoFile=temp;
    importaLeilao(leiloes,leilaoFile);


    filtrados=imoveis;

    //obtem o dia atual
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    Date currentDay;
    string day= to_string(tPtr->tm_mday) + "/" + to_string(tPtr->tm_mon+1) + "/" + to_string(tPtr->tm_year+1900);
    currentDay.setDateFromString(day);

    limpaLeiloes(currentDay);

    infile.close();


}

void OurCompany::exportCompany(const string &filename ){

    string temp;

    ofstream outfile(filename);

    //verifica se ficheiro existe
    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);

    //exporta os vetores para os ficheiros correspondentes
    exportaImoveis(imoveis,imovelFile);
    exportaRegistrado(clientes, clientsFile);
    exportaReservas(reservas,reservFile);
    exportaContrato(contratos,contractFile);
    exportaLeilao(leiloes,leilaoFile);

    outfile << nome << endl
            << morada.getAddressFormated() << endl
            << imovelFile << endl
            << clientsFile << endl
            << contractFile << endl
            << reservFile << endl
            << leilaoFile;


    outfile.close();

}


ostream& operator<< (ostream& out, OurCompany& company){
    out << "Nome:  " << company.nome << endl
        << "Morada" << endl << company.morada << endl
        << "Ficheiro dos Imoveis:  " << company.imovelFile << endl;
    return out;
}

void OurCompany::personalizaFiltros(){
    limpaFiltros();
    uint idContrato;

    vector<string> interesses=PessoaAtual->getInteresses();
    if(interesses.size()==3){
        return;
    }
    vector<uint> idsQueremos;
    vector<uint> int_inter;

    for(auto ele : interesses){
        if(ele=="Flexivel"){
            int_inter.push_back(2);
        }else if(ele=="Compra"){
            int_inter.push_back(1);
        }else {
            int_inter.push_back(3);
        }
    }
    vector<Imovel> temp;
    for(auto ele : int_inter){

        for (auto it=filtrados.begin();it!=filtrados.end();it++){
            idContrato=it->getContrato();
            if(contratos.at(idContrato-1)->returnType()==ele){
                temp.push_back(*it);
            }
        }
    }
    filtrados=temp;

}

void OurCompany::limpaLeiloes(Date current)
{

    priority_queue<ItemLeilao> temp;
    uint idP;

    for(auto it=leiloes.begin();it!=leiloes.end();it++){

        if(it->getEndDate() < current){
            temp =it->getBiddings();
            idP=temp.top().getLicitador();
            clientes.at(idP-1)->addListaImoveis(it->getImovel());
            leiloes.erase(it);
            it--;
        }
    }
}


bool OurCompany::addImovel(Imovel newImovel)
{
    if (treeImoveis.insert(Imovel(newImovel)))
    {
        imoveis.push_back(newImovel);
        return true;
    }
    else
    {
        return false;
    }
}

bool OurCompany::createUpdateTree()
{
    bool aux = false;
    for (int i = 0; i < imoveis.size(); i++)
    {
        aux = treeImoveis.insert(imoveis.at(i));
    }
    return aux;
}

int OurCompany::showTreeImoveis(string filterType, string filterWord)
{
    BSTItrIn<Imovel> inicio(treeImoveis);

    queue<Imovel> auxQ;
    bool verify = false;
    int opt;
    if(filterType == "freguesia") {
        opt = 1;
    } else if (filterType == "codigo postal") {
        opt = 2;
    } else if (filterType == "tipo") {
        opt = 3;
    }


    while (!inicio.isAtEnd())
    {
        switch (opt)
        {
            case 1:
                if (inicio.retrieve().getAddress().getFreguesia() == filterWord)
                {
                    auxQ.push(inicio.retrieve());
                }
                break;
            case 2:
                if (inicio.retrieve().getAddress().getCodPos() == filterWord)
                {
                    auxQ.push(inicio.retrieve());
                }
                break;
            case 3:
                if (inicio.retrieve().getTipo() == filterWord)
                {
                    auxQ.push(inicio.retrieve());
                }
                break;
            default:
                break;
        }
        inicio.advance();
    }

    if (auxQ.size() == 0)
    {
        verify = false;
        cout << "Infelizmente nao encontramos essa referencia em nossa base de dados." << endl;
        cout << "Favor tentar novamente!" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        verify = true;
    }

    cout << setw(4) << "ID";
    cout << "|";
    cout << setw(14) << "Tipo";
    cout << "|";
    cout << setw(40) << "Nome";
    cout << "|";
    cout << setw(8) << "Area";
    cout << "|";
    cout << setw(49) << "Morada" << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    while(!auxQ.empty())
    {
        cout << setw(4) << auxQ.front().getId();
        cout << "|";
        cout << setw(14) << auxQ.front().getTipo();
        cout << "|";
        cout << setw(40) << auxQ.front().getNome();
        cout << "|";
        cout << setw(8) << auxQ.front().getArea();
        cout << "|";
        cout << setw(49) << auxQ.front().getAddress().getAddressFormated() << endl;
        auxQ.pop();
    }

    return EXIT_SUCCESS;
}

void OurCompany::verifyInactRegis() {
    for(auto it = clientes.begin(); it != clientes.end(); it++){

        if((*it)->getIsClient() == true ){
            for( auto ut = (*it)->getContratos().begin(); ut != (*it)->getContratos().end(); ut++ ){
                int idContReg =(*ut);
                int pos = procuraContrato(contratos, idContReg);

                Date aux = contratos.at(pos)->getDataAss();
                time_t now = time(0);

                tm *ltm = localtime(&now);


                if(aux.getYear() < 1900 + ltm->tm_year){
                    (*it)->setInactivo(true);
                        break;

                }
                        //aqui temos contratos no mesmo ano que a data actual e verificamos se contrato é no 3 º mês antes da data actual
                else if(aux.getYear()  == 1900 + ltm->tm_year && (1 + ltm->tm_mon  % contratos.at(pos)->getDataAss().getMonth() ) >=3 )  {
                    (*it)->setInactivo(true);
                        break;
                    }

                else{
                    (*it)->setInactivo(false);
                }

            }

        }


    }



}

