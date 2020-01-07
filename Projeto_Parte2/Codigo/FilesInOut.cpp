//
// Created by debor on 15/11/2019.
//

#include "FilesInOut.h"



void importaRegistrado(vector<Registrado*> &clientes, const string &filename)
{
    ifstream infile(filename);

    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);

    string nome, email, temp, tipoR, temp2, temp3, temp4, temp5, senha, temp6;
    uint nif, qtde, idtemp2, impostos;
    vector<uint> interessesR;
    vector<uint> imoveisR;

    while(!infile.eof())
    {
        //ID
        getline(infile,temp); //ignora-se (id e automaticamente gerado pelo constructor)

        //EMPRESA OU SINGULAR
        getline(infile,tipoR);

        //NOME
        getline(infile,nome);

        //NIF
        getline(infile,temp2);
        nif = stoi(temp2);

        //EMAIL
        getline(infile,email);

        //PASSWORD
        getline(infile,senha);

        //INTERESSES
        getline(infile,temp3);
        vector<string> interessesR = formatarInteresses(temp3);

        //QTDE DE IMOVEIS
        getline(infile,temp4);
        qtde = stoi(temp4);

        //LISTA DE IMOVEIS (ID)
        if(qtde == 0) {
            getline(infile,temp5);

        } else {
            getline(infile,temp5);
            imoveisR = formatarListaImoveis(temp5);
        }

        //IMPOSTOS
        getline(infile,temp6);
        impostos = stoi(temp6);

        vector<unsigned int> contractsClient;
/*
        //id's dos contractos
        string auxId;

        while(getline(infile,auxId,'-')){
               contractsClient.push_back(stoi(auxId));

        }
        //ultimo id na linha do ficheiro
        getline(infile,auxId);
        contractsClient.push_back(stoi(auxId));

        //verificar e criar o tipo de registrado pretendido
*/
        if (tipoR=="Empresa") {
            Registrado *R = new Empresa(nome,nif,email,qtde,imoveisR, interessesR, senha, false, contractsClient,impostos);
            clientes.push_back(R);
        }else {
            Registrado *R = new Singular(nome,nif,email,qtde,imoveisR, interessesR, false, senha, impostos,contractsClient);
            clientes.push_back(R);
        }
        getline(infile,temp6);

        cout << "hello" << endl;
        //limpa vetor
        for(auto it=imoveisR.begin();it!=imoveisR.end();it++){
            imoveisR.erase(it);
            it--;
        }
    }

    infile.close();
}

void exportaRegistrado(const vector<Registrado*> &clientes, const string &filename)
{
    ofstream outfile(filename);

    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);

    for(int i = 0; i < clientes.size(); i++) {

        outfile << clientes.at(i)->getId() << endl;

        if(clientes.at(i)->getIsCompany() == true) {
            outfile << "Empresa" << endl;
        } else if(clientes.at(i)->getIsSingular() == true) {
            outfile << "Singular" << endl;
        }

        outfile << clientes.at(i)->getNome() << endl;

        outfile << clientes.at(i)->getNIF() << endl;

        outfile << clientes.at(i)->getEmail() << endl;

        outfile << clientes.at(i)->getWebPassword() << endl;

        outfile << clientes.at(i)->getInteressesFormated() << endl;

        outfile << clientes.at(i)->getQtdeImoveis() << endl;

        outfile << clientes.at(i)->getImoveisFormated() << endl;

        if(clientes.at(i)->getIsCompany() == true) {
            Empresa *e = dynamic_cast<Empresa*>(clientes.at(i));
            outfile << e->getIsencaoImpostos() << endl;
        } else if(clientes.at(i)->getIsSingular() == true) {
            Singular *s = dynamic_cast<Singular*>(clientes.at(i));
            outfile << s->getReducaoImpostos() << endl;
        }

        outfile << "::::::::::";

        if(i!=(clientes.size()-1))
            outfile << endl;
    }
    outfile.close();
}

void importaContrato(vector<Contrato*> &cont, const string &filename){
    ifstream infile(filename);

    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);

    int id;
    double preco;
    double periodo;
    bool renovavel;

    string base;
    unsigned int type;
    int cedencia;
    int auxrenov;
    string temp;

    while(!infile.eof()){
        getline(infile,temp);
        type =stoi(temp);

        if(type == 1){
            getline(infile, temp);
            preco = stod(temp);
            //Obter data de assinatura
            Date dataAss;
            string auxData;
            getline(infile,auxData);

            dataAss.setDateFromString(auxData);

            Venda *aux=new Venda(preco,dataAss);
            cont.push_back(aux);
            getline(infile,temp);
        }
        else if(type == 3) {
            getline(infile, temp);
            preco = stoi(temp);

            getline(infile, temp);
            periodo = stoi(temp);

            getline(infile, temp);
            auxrenov =stoi(temp);

            if (auxrenov== 1) {
                renovavel = true;
            } else {
                renovavel = false;
            }
            Date dataAss;
            string aux;
            getline(infile,aux);

            dataAss.setDateFromString(aux);
            LongaDuracao *contrato=new LongaDuracao(preco,dataAss, renovavel, periodo);

            cont.push_back(contrato);
            getline(infile, temp);
        }
        else{
            getline(infile, temp);
            preco = stod(temp);


            //cedencia base
            getline(infile,temp);
            base=temp;

            getline(infile, temp);
            periodo = stoi(temp);

            getline(infile, temp);
            auxrenov = stoi(temp);

            if (auxrenov == 1) {
                renovavel = true;
            }
            else {
                renovavel = false;
            }

            Date dataAss;
            string auxData;
            getline(infile,auxData);

            dataAss.setDateFromString(auxData);

            Flexivel *aux= new Flexivel( preco, dataAss,periodo,  renovavel, base);

            cont.push_back(aux);
            getline(infile, temp);
        }


    }
    infile.close();

}

void exportaContrato(vector<Contrato*> &cont, const string &filename){

    ofstream outfile(filename);

    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);

    for(int i = 0; i< cont.size(); i++){
        int type = cont.at(i)->returnType();
        if(type == 1){

            outfile << cont.at(i)->returnType() << endl;
            outfile << cont.at(i)->getPreco() << endl;
            outfile << cont.at(i)->getDataAss() << endl;
            outfile << "::::::::::";

        }
        else if( type == 2) {
            Flexivel *v = static_cast<Flexivel*>(cont.at(i));

            outfile << v->returnType() << endl;
            outfile << v->getPreco() << endl;
            outfile << v->getBase() << endl;
            outfile << v->getPeriodo() << endl;
            outfile << v->getRenovavel() << endl;
            outfile << v->getDataAss() << endl;
            outfile << "::::::::::";
        }
        else{
            LongaDuracao *l = static_cast<LongaDuracao*>(cont.at(i));
            outfile << l->returnType() << endl;
            outfile << l->getPreco() << endl;
            outfile << l->getPeriodo() << endl;
            outfile << l->getRenovavel() << endl;
            outfile << l->getDataAss() << endl;
            outfile << "::::::::::";

        }

        if(i!=(cont.size()-1))
            outfile << endl;
    }
    outfile.close();
}

void importaImoveis(vector<Imovel> &imoveis, const string &filename)
{
    ifstream infile(filename);

    //Verifica se ficheiro existe
    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);


    string nome,tipo,temp;
    uint area,idC,idP;
    Address morada;
    Imovel im;

    while(!infile.eof())
    {
        //ID
        getline(infile,temp);

        //Tipo
        getline(infile,tipo);

        //Nome
        getline(infile,nome);

        //Area
        getline(infile,temp);
        area=stoi(temp);

        //Morada
        getline(infile,temp);
        morada.setAddress(temp);


        //id Contrato
        getline(infile,temp);
        idC=stoi(temp);

        //Indisponibilidade
        vector<Intervalo> inds;
        getline(infile,temp);
        if(temp!="0")
            inds= IndisFromString(temp);

        //ID proprietario
        getline(infile,temp);
        idP=stoi(temp);

        //:::::::::
        getline(infile,temp);


        im.setImovel(tipo,nome,area,morada,idC,inds,idP);
        imoveis.push_back(im);
    }
    infile.close();

}

void exportaImoveis(vector<Imovel> &imoveis,  const string &filename)
{
    ofstream outfile(filename);

    //Verifica se ficheiro existe
    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);

    for (int i=0;i<imoveis.size();i++){
        outfile << imoveis.at(i).getId() << endl
                << imoveis.at(i).getTipo() << endl
                << imoveis.at(i).getNome() << endl
                << imoveis.at(i).getArea() << endl
                << imoveis.at(i).getAddress().getAddressFormated() << endl
                << imoveis.at(i).getContrato() << endl
                << imoveis.at(i).getIndsFormatted() << endl
                << imoveis.at(i).getProprietario() << endl
                << "::::::::::";

        if(i!=imoveis.size()-1)
            outfile << endl;


    }
    outfile.close();

}

void importaReservas(vector<Reserva> &reservas, const string &filename){

    ifstream infile(filename);
    string temp;
    uint idR, idP, idC, idI;
    Intervalo inter;
    double val;

    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);

    while(!infile.eof()){

        //importa id da reserva
        getline(infile,temp);
        idR=stoi(temp);

        //importa id do proprietario do imovel
        getline(infile,temp);
        idP=stoi(temp);

        //importa id da pessoa que faz a reserva
        getline(infile,temp);
        idC=stoi(temp);

        //importa intervalo
        getline(infile, temp);
        inter.setIntervaloFromString(temp);

        //importa id do imovel
        getline(infile,temp);
        idI=stoi(temp);

        //importa valor
        getline(infile,temp);
        val=stoi(temp);

        //importa os ::::::::::
        getline(infile,temp);

        Reserva r(idP,idC,inter,idI,val);

        reservas.push_back(r);

    }
}

void exportaReservas(vector<Reserva> &reservas, const string &filename){

    ofstream outfile(filename);

    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);
    int i=0;
    for(auto it=reservas.begin();it!=reservas.end();it++){
        outfile << it->getID() << endl
                << it->getIdProprietario() << endl
                << it->getIdContratante() << endl
                << it->getIntervalo().getIntervaloFormatted() << endl
                << it->getIdImovel() << endl
                << it->getValor() << endl
                << "::::::::::";


        if (i!=reservas.size()-1)
            outfile << endl;
        i++;
    }
}

void importaLeilao(vector<Leilao> &leiloes, const string &filename){
    ifstream infile(filename);


    if(!infile.is_open())
        throw FicheiroNaoExistente(filename);

    string temp;
    priority_queue<ItemLeilao> licitacoes;
    int idL,idI;
    Date datafim;

    while(!infile.eof()){

        //importa id do leilao
        getline(infile,temp);
        idL=stoi(temp);

        //importa as licitacoes
        getline(infile,temp);
        licitacoes= getBiddingsFromString(temp);

        //importa o id do imovel
        getline(infile,temp);
        idI=stoi(temp);

        //importa a data de fim do leilao
        getline(infile,temp);
        datafim.setDateFromString(temp);

        //importa os ::::::::::
        getline(infile,temp);

        Leilao lei(licitacoes,idI,datafim);
        leiloes.push_back(lei);
    }
    infile.close();
}

void exportaLeilao(vector<Leilao> &leiloes, const string &filename){
    ofstream outfile(filename);

    if(!outfile.is_open())
        throw FicheiroNaoExistente(filename);

    int i=0;
    for (auto it=leiloes.begin();it!=leiloes.end();it++){
        outfile << it->getID() << endl
                << it->getBiddingsFormatted() << endl
                << it->getImovel() << endl
                << it->getEndDate().getDateFormatted() << endl
                << "::::::::::";

        if (i!=leiloes.size()-1)
            outfile << endl;
        i++;
    }
    outfile.close();
}

