

#include "OurCompany.h"
#include "Menu.h"

using namespace std;

bool registrado=false;


int main() {

    /* Inicio */


    OurCompany myCompany;
    myCompany.importCompany("OurCompany.txt");
    myCompany.verifyInactRegis();

   uint idMenu=1;
   while(idMenu!=0){
       switch (idMenu)
       {
           case 1:
               idMenu=MenuInicial(myCompany);
               break;
           case 2:
               idMenu= MenuRegistrar(myCompany);
               break;
           case 3:
               idMenu= MenuLogin(myCompany);
               break;
           case 4:
               idMenu= MenuImoveis(myCompany);
               break;
           case 5:
               idMenu= MenuPerfil(myCompany);
               break;
           case 6:
               idMenu= MenuDisplayImoveis(myCompany);
               break;
           case 8:
               idMenu = MenuComprarImovel(myCompany);
               break;
           case 9:
               idMenu= MenuLimparFiltros(myCompany);
               break;
           case 10:
               idMenu = MenuFiltrarTipo( myCompany);
               break;
           case 11:
               idMenu = MenuFiltrarFreg(myCompany);
               break;
           case 12:
               idMenu = MenuAlterarPerfil(myCompany);
               break;
           case 13:
               idMenu = MenuVerReservas(myCompany);
               break;
           case 14:
               idMenu = MenuLogout(myCompany);
               break;
           case 15:
               idMenu = MenuFiltrarPreco(myCompany);
               break;
           case 16:
               idMenu = MenuLeiloes(myCompany);
               break;
           case 17:
               idMenu = MenuCriarLeilao(myCompany);
               break;
           case 18:
               idMenu = MenuVerLeiloes(myCompany);
               break;

           default:
               break;
       }
   }


    myCompany.exportCompany("OurCompany.txt");

    return 0;


}

