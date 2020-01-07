//
// Created by flavi on 12/11/2019.
//

#include "GerirContratos.h"


void inserirContrato(Imovel &aux,vector<Contrato *> &contratos){


    cout << "(Introduza 0 para voltar para o menu anterior)" << endl << endl;

    //Objectos date para utilizar na insercao de intervalos


    //evitar erro na escrita de caracteres
    cin.ignore();
    //Introduzir o tipo de contrato pretendido
    cout << "Introduza o tipo de contrato ";
    string tipo_contrato;

    //tratar o tipo de contrato
    getline(cin, tipo_contrato);
    while( tipo_contrato != "Flexivel" && tipo_contrato != "Longa Duracao" && tipo_contrato != "Venda") {
        cin.clear();
        cin.ignore(1000, '\n');
        cerr << "Comando errado. Por favor introduza de novo o tipo de contrato: ";
        cin >> tipo_contrato;


        //verficia se pretende cancelar
        if (tipo_contrato == "0") {
            throw Cancela("Adiciona Contrato");
        }

    }
    //Tratar os vários casos de tipo de contrato
    if(tipo_contrato == "Flexivel") {
        //Inserir primeiro se é Diario,Semanal etc?!?!isto é mesmo necessário??
        //Ao inserir datas já temos a flexibilidade que quiseremos!!!


        string decisao;

        //introduzir preco
        double preco;
        cout << "Introduza o preço: ";
        cin >> preco;

        if(preco == 0) {
            throw Cancela("Adiciona Contrato");
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o preco de novo:  " ;
            cin >> preco;
            //para cancelar
            if(preco == 0) {
                throw Cancela("Adiciona Contrato");
            }


        }
        //Verificar cedencia  base

        cout <<"Qual a cedencia base (Diaria, Semanal ou Mensal: )";
        cin >> decisao;

        while (decisao != "Diaria" && decisao != "Semanal" && decisao != "Mensal") {

            //verficia se pretende cancelar
            if (decisao == "0")
            {
                throw Cancela("Adiciona Contrato");
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza de novo cedencia base pretendida:  ";
            cin >> decisao;

        }
        //obter atributo cedencia base do contrato flexível

        string base=decisao;

        //atribuir periodo
        unsigned int periodo;
        cout << "Introduza periodo fixo pretendido: ";
        cin >> periodo;

        if(periodo == 0) {
            throw Cancela("Adiciona Contrato");
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o periodo de novo:  " ;
            cin >> periodo;

            //para cancelar
            if(periodo == 0) {
                throw Cancela("Adiciona Contrato");
            }


        }



        //Verificar se é renovável
        cout <<"Contrato é renovável? S (Sim) N (Não): ";
        cin >> decisao;
        while (decisao != "S" && decisao != "N") {

            //verficia se pretende cancelar
            if (decisao == "0")
            {
                throw Cancela("Adiciona Contrato");
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza N (Não) ou S (Sim):  " << endl;
            cin >> decisao;
        }

        bool renov;
        if( decisao == "S"){
            renov = true;

        }
        else {
            renov = false;
        }

        Date dataAssAux;
        dataAssAux.insertDate();

        Flexivel contrato(preco,dataAssAux,periodo,renov,base);    //id é criado automáticamente usando variável estática!!!

        aux.setId(contrato.getId());
        contratos.push_back(&contrato);
        return ;//contrato inserido no vector de contratos!!!

    }

    //contratos de longa duracao so permitem ter um intervalo de datas renovavel ou não renovavel
    else if(tipo_contrato =="Longa Duracao"){

        string decisao;

        //introduzir preco
        double preco;
        cout << "Introduza o preço: ";
        cin >> preco;

        if(preco == 0) {
            throw Cancela("Adiciona Contrato");
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o preco de novo:  " ;
            cin >> preco;
            //para cancelar
            if(preco == 0) {
                throw Cancela("Adiciona Contrato");
            }


        }


        //atribuir periodo
        unsigned int periodo;
        cout << "Introduza periodo fixo pretendido: ";
        cin >> periodo;

        if(periodo == 0) {
            throw Cancela("Adiciona Contrato");
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o periodo de novo:  " ;
            cin >> periodo;

            //para cancelar
            if(periodo == 0) {
                throw Cancela("Adiciona Contrato");
            }


        }



        //Verificar se é renovável
        cout <<"Contrato é renovável? S (Sim) N (Não): ";
        cin >> decisao;
        while (decisao != "S" && decisao != "N") {

            //verficia se pretende cancelar
            if (decisao == "0")
            {
                throw Cancela("Adiciona Contrato");
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza N (Não) ou S (Sim):  " << endl;
            cin >> decisao;
        }

        bool renov;
        if( decisao == "S"){
            renov = true;

        }
        else {
            renov = false;
        }

        Date dataAssAux;
        dataAssAux.insertDate();


        LongaDuracao contrato(preco,dataAssAux,renov,periodo);         //id é criado automáticamente usando variável estática!!!
        //inserir id no imovel e guardar contrato num vector de Contrato *
        aux.setId(contrato.getId());



        contratos.push_back(&contrato);

        return ;

    }
    else{

        string decisao;
        //Introduzir preco
        double preco;
        cout << "Introduza o preço: ";
        cin >> preco;

        if(decisao == "0") {
            throw Cancela("Adiciona Contrato");
        }

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o preco de novo  " << endl;
            cin >> preco;
            //para cancelar
            if(decisao == "0") {
                throw Cancela("Adiciona Contrato");
            }


        }

        //Obter data da Assinatura
        Date dataAssAux;
        dataAssAux.insertDate();
        Venda contrato(preco,dataAssAux);

        aux.setId(contrato.getId());
        contratos.push_back(&contrato);
        return ;
    }

    //nada foi inserido!!!

}




void eliminaContrato(vector<Contrato *> &contratos, unsigned int id){
    bool encontrou=false;

    for(auto it = contratos.begin(); it != contratos.end(); it++) {
        if (!encontrou && (*it)->getId() == id) {
            contratos.erase(it);
            it--;
            encontrou=true;
        }else if(encontrou)
            (*it)->setId((*it)->getId()-1);
    }
    if(!encontrou)
        throw ContratoException(id);

}
//como fazer por pesquisa binaria usando STL!?!?!


void alteraContrato(Imovel &imov, vector<Contrato *> &contratos){
    //obter posicao do contrato com o id guardado no imovel
    int pos = procuraContrato(contratos,imov.getId());

    if(contratos.at(pos)->returnType() == 1){
        double preco;
        cout << "Insira o novo preco: ";
        cin >> preco;

        while(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Comando errado. Por favor introduza o preco de novo: " ;
            cin >> preco;

            //para cancelar
            if(preco == 0) {
                return ;
            }


        }
        //alteramos apenas o preco
        contratos.at(pos)->setPreco(preco);
    }
    else {
        unsigned int campo;
        string decisao;
        cout <<"Insira o Campo a alterar: ";
        cin >> campo;

        switch(campo){
            case 1:

                double preco;
                cout << "Insira o novo preco: ";
                cin >> preco;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Comando errado. Por favor introduza o preco de novo: " ;
                    cin >> preco;

                    //para cancelar
                    if(preco == 0) {
                        return ;
                    }


                    }
                    contratos.at(pos)->setPreco(preco);
                break;
            case 2:
                unsigned int periodo;
                cout << "Insira o Periodo:";
                cin >> periodo;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Comando errado. Por favor introduza o preco de novo: " ;
                    cin >> periodo;

                    //para cancelar
                    if(periodo == 0) {
                        return ;
                    }
                }

                contratos.at(pos)->setPeriodo(periodo);
                break;
            case 3:
                cout << "Insira se é renovavel ou não: S (Sim) N (Não) :";
                cin >> decisao;
                while(decisao !="S" && decisao !="N") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Comando errado. Por favor tente de novo: " ;
                    cin >> periodo;

                    //para cancelar
                    if(decisao == "0") {
                        return ;
                    }
                }

                if(decisao == "S"){
                    contratos.at(pos)->setRenovavel(true);
                }
                else{
                    contratos.at(pos)->setRenovavel(false);
                }
                break;
            case 4:

                cout << "Insira nova cedencia  base: ";
                cin >> decisao;
                while(decisao !="Diario" && decisao !="Semanal" && decisao != "Mensal") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Comando errado. Por favor tente de novo: " ;
                    cin >> periodo;

                    //para cancelar
                    if(decisao == "0") {
                        return ;
                    }
                }

                contratos.at(pos)->setBase(decisao);
                break;
            case 5:

                cout <<"Insira novo tipo de Contrato (Venda, Flexivel ou Longa Duracao): ";
                cin >> decisao;
                while(decisao !="Venda" && decisao !="Flexivel" && decisao != "Longa Duracao") {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cerr << "Comando errado. Por favor tente de novo: " ;
                    cin >> periodo;

                    //para cancelar
                    if(decisao == "0") {
                        return ;
                    }
                }
                if(decisao == "Venda"){
                    Venda aux(contratos.at(pos)->getPreco(),contratos.at(pos)->getDataAss());
                    contratos.at(pos) = &aux;

                }
                else{
                    unsigned int auxId = imov.getContrato();
                    inserirContrato(imov,contratos);
                    eliminaContrato(contratos, auxId);

                }
                break;
        }


    }




}



 int procuraContrato(vector<Contrato*> &contratos, unsigned int id){
    int r = contratos.size() - 1;

    int l = 0;

    while(l <= r) {
        int m = l + (r - 1) / 2;

        if (contratos.at(m)->getId() == id) {
            return m;


        }

        if (contratos.at(m)->getId() < id) {
            l = m + 1;

        } else {
            r = m - 1;
        }

    }

    return -1; //posicao do contrato com id pretendido não encontrado
}

