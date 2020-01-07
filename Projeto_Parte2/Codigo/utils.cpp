//
// Created by Ricardo Nunes on 08/11/2019.
//

#include "utils.h"



vector<string> formatarInteresses(string interessesFile){
    vector<string> interesses;
    string temp;
    istringstream sstring(interessesFile);
    while(getline(sstring, temp, ',')) {
        interesses.push_back(temp);
    }
    return interesses;
}

vector<uint> formatarListaImoveis(string imoveisFile) {
    vector<uint> listaImoveis;
    string temp;
    uint newtemp;
    istringstream sstring(imoveisFile);
    while(getline(sstring, temp, ',')) {
        newtemp = stoi(temp);
        listaImoveis.push_back(newtemp);
    }
    return listaImoveis;
}

void confirmaAssinatura(string nome){

    cout << "Assine para confirmar compra";
    cin.ignore();
    string temp1;
    getline(cin,temp1);
    while(temp1!=nome){
        if(temp1=="0")
            throw Cancela("Compra/arrendar");
        cerr << "ERRO: Assinatura invalida. Assine novamente";getline(cin,temp1);
    }

}
