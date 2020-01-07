//
// Created by Ricardo Nunes on 08/11/2019.
//

#include "gerirAddress.h"

Address insereMorada(){
    string rua, loc, codpos, freguesia;
    uint num;
    cout << "Introduza a rua:  "; cin >> rua;
    cout << "Introduza o numero da porta:  ";cin >> num;
    cout << "Introduza a freguesia:  ";cin >> freguesia;
    cout << "Introduza o codigo-postal:  ";cin >> codpos;
    cout << "Inroduza a localidade:  ";cin >> loc;


    Address res(rua,num,freguesia,codpos,loc);
    return res;
}