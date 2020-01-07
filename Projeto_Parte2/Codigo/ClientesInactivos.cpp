//
// Created by flavi on 21/12/2019.
//

#include "ClientesInactivos.h"
/* */
unordered_set<unsigned int,hashInact, eq> getTabelaDispersaoInact(vector<Registrado*> &registrados){
    unordered_set<unsigned int,hashInact,eq> tab_disp;
    for(auto it = registrados.begin(); it < registrados.end(); it++){
        if((*it)->getIsClient() && (*it)->getIsInact()){
            unsigned int insert_id = (*it)->getId();
            tab_disp.insert(insert_id);

        }


    }
    return tab_disp;

}


/* Permitir que clientes não tenham contratos,ou seja, já têm que ter tido um contrato e deixaram de ter
 * Como medir o tempo de inactividade?Empresa tem de ter data e relógio actualizado, ou apenas por datas?
 * Classe Data também tem de ter hora, passamos a ter classe DataHora!(mudar classe Data)
 * Ao importar clientes, com determinado contrato identificado com um id, esse contrato tem de ter uma data e hora associados(mudar classe contracto)
 *
 *
 *
 * */
