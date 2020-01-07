//
// Created by debor on 12/11/2019.
//

#include "gerirRegistrados.h"

vector<string> Interesses = {"Compra", "Longa Duracao", "Flexivel"};

void adicionaRegistrado(OurCompany& c){

    string nome,temp, password;
    uint NIF;
    string email;
    vector <string> interesses;
    uint qtdeImoveis = 0;
    string resposta;
    bool eEmpresa;

    cout << "Insira seu NIF: " ;cin.ignore(); getline(cin, temp);
    NIF = stoi(temp);
    cout << endl;

    Registrado *p1 = new Registrado();
    //NIF
    p1->setNIF(NIF);

    if(find(c.getRegistrados().begin(),c.getRegistrados().end(),p1) != c.getRegistrados().end())
    {throw PessoaJaExistente(NIF);}

    cout << "Insira o seu nome:  "; getline(cin, nome);
    cout << endl;
    //NOME
    p1->setNome(nome);

    cout << "Insira o seu e-mail:  "; getline(cin, email);
    cout << endl;
    //EMAIL
    p1->setEmail(email);


    //listaImoveis
    vector<uint> listaImoveis;

    qtdeImoveis=0;
    //QUANTIDADE DE IMOVEIS
    p1->setQtdeImoveis(qtdeImoveis);


    //LISTA DE INTERESSES
    string respostaI;
    cout << "Quais sao seus interesses? Escolha pelo menos 1 e no maximo 3 opcoes (Digite S ou N): " << endl;
    for (auto elem : Interesses) {
        cout << elem << " " ;
        cin >> respostaI;
        while (respostaI!= "S" && respostaI!= "N") {
            cerr << "Erro: Introduza S ou N" << endl;
            cin >> respostaI;
        }
        if(respostaI == "S") {
            interesses.push_back(elem);
        }
    }
    p1->setInteresses(interesses);

    cout << "Introduza a sua palavra passse"; cin>> password;
    p1->setWebPassword(password);

    //Empresa/Singular
    string dados[]={"N","S"};
    temp=verificaValores('=',"E uma empresa? (S/N)",dados,2);



    uint desconto;
    if(temp=="N"){
        eEmpresa=false;
        cout << "Introduza insencao de imposto(%)"; cin >> desconto;
        vector<unsigned int> aux;

        Registrado *p22 = new Empresa(nome,NIF,email,qtdeImoveis,listaImoveis,interesses,password,false,aux,desconto);
        c.addRegistrado(p22);
        c.PessoaAtual=p22;
    }else{
        vector<unsigned int> aux;
        eEmpresa=true;
        cout << "Introduza reducao de imposto(%)"; cin >> desconto;
        Registrado *p22 = new Empresa(nome,NIF,email,qtdeImoveis,listaImoveis,interesses,password,false,aux,desconto);
        c.addRegistrado(p22);
        c.PessoaAtual=p22;
    }



}

void eliminaRegistrado(vector<Registrado*> &clientes, uint id)
{
    bool encontrou=false;
    for(auto it=clientes.begin();it!=clientes.end();it++){
        if(!encontrou &&(*it)->getId() == id){
            clientes.erase(it);
            it--;
            encontrou=true;
        }else if (encontrou){
            (*it)->setId((*it)->getId()-1);
        }
    }
    if(!encontrou)
        throw PessoaNaoExistente(id);
}

//é necessário fazer a função por referência ?
void alteraRegistrado(Registrado &R, uint opcao, OurCompany &c1)
{
    string nome, password;
    uint NIF;
    string email;
    vector <string> interesses;
    //vector <Contrato> contractsClient;
    uint qtdeImoveis, option;
    string temp2, temp3, temp4;
    string respostaI;
    vector <string> newInteresses;
    uint imovTemp;
    uint dados[]={5};

    switch (opcao)
    {
        case 1:
            cout << "Insira o seu nome corrigido:  "; cin.ignore(); getline(cin, nome);
            R.setNome(nome);
            break;
        case 2:
            cout << "Insira o seu NIF corrigido:  "; cin.ignore(); getline(cin, temp2);
            NIF = stoi(temp2);
            R.setNIF(NIF);
            break;
        case 3:
            cout << "Insira o seu novo email: " << endl; cin.ignore(); getline(cin, email);
            R.setEmail(email);
            break;
        case 4:
            cout << "Quais sao seus novos interesses? Escolha pelo menos 1 e no maximo 3 opcoes (Digite S ou N): " << endl;
            for (auto elem : Interesses) {
                cout << elem << " " ;
                cin >> respostaI;
                while (respostaI!= "S" && respostaI!= "N") {
                    cerr << "Erro: Introduza S ou N" << endl;
                    cin >> respostaI;
                }
                if(respostaI == "S") {
                    newInteresses.push_back(elem);
                }
            }
            R.setInteresses(newInteresses);
            break;
        case 5:
            cout << "Os seus imoveis sao: " << endl;
            for (int i = 0; i < R.getListaImoveis().size();i++) {
                if(i == R.getListaImoveis().size()-1){
                    cout << to_string(R.getListaImoveis().at(i)) << endl;
                } else{
                    cout << to_string(R.getListaImoveis().at(i)) << ", ";
                }
            }
            cout << "Qual imovel deseja modificar? " << endl;
            cin >> temp3;
            imovTemp = stoi(temp3);
            cout << "1- Tipo" << endl
                 << "2- Nome" << endl
                 << "3- Area" << endl
                 << "4- Morada" << endl
                 << "5- Contrato" << endl;


            option=verificaValores('<',"Qual informacao deseja modificar? ",dados,1);

            alteraImovel(c1.imoveis.at(imovTemp-1), option,c1.contratos);
            break;
        case 6:
            cout << "Insira a sua nova palavra-passe:  "; cin.ignore(); getline(cin, password);
            R.setWebPassword(password);
            break;
        default:
            break;
    }

}



vector<Registrado*>::const_iterator findClient(vector<Registrado*>::const_iterator inicio, vector<Registrado*>::const_iterator fim, Registrado &R) {

    vector<Registrado*>::const_iterator it;
    for(it=inicio;it!=fim;it++){
        if(((*it)->getNIF() == R.getNIF())||((*it)->getEmail() == R.getEmail())||((*it)->getNome() == R.getNome())) {
            return it;
        }
    }
    return fim;
}