//
// Created by Ricardo Nunes on 01/11/2019.
//
//
// Created by Ricardo Nunes on 01/11/2019. mudei
//
#include "Menu.h"


static uint values[2];
static string svalues[3]={"casa","vivenda","apartamento"};

uint MenuInicial(OurCompany &c){

    novaJanela();
    char poss[]={'0','1','R','E','2'};
    char result;

    displayHead();

    cout << "1- Ver Imoveis" << endl;
    if(c.PessoaAtual!=NULL)
        cout << "2- Ver perfil" << endl;
    cout << "0- Sair";

    displayFooter(c);
    criaparagrafo(1);


    if(c.PessoaAtual==NULL)
        result=verificaValores('=',"Introduza o menu a que pretende ir:  ",poss, 4);
    else
        result=verificaValores('=',"Introduza o menu a que pretende ir:  ",poss, 5);

    switch (result){
        case '1':
            result= 4;
            break;
        case '2':
            result= 5;
            break;
        case 'R':
            result=2;
            break;
        case 'E':
            result = 3;
            break;
        case '0':
            result = 0;
            break;
        default:
            break;
    }
    return result;
}

void criaparagrafo(int num){
    for(int i=0; i<num;i++){
        cout << endl;
    }
}

void displayFooter(OurCompany &c){

    criaparagrafo(3);
    if(c.PessoaAtual!=NULL){
        cout << c.PessoaAtual->getNome() << endl;
    }else {
        cout << "R- Registrar | E- Entrar" << endl;
    }
}

void displayHead()
{
    cout << "IMOVELANDIA";
    criaparagrafo(3);
}

uint MenuImoveis(OurCompany &c)
{

    criaparagrafo(20);

    displayHead();

    cout << "1- Ver os imoveis" << endl
         << "2- Filtrar por tipo" << endl
         << "3- Filtrar por freguesia ou codigo postal" << endl
         << "4- Filtrar por preco" << endl
         << "5- Limpa filtros" << endl
         << "6- Ver Leiloes" << endl
         << "0- Voltar";


    criaparagrafo(3);

    values[0]=6;
    uint result=verificaValores('<',"Introduza o menu a que pretende ir:  ",values,2);

    switch (result){
        case 1:
            result=6;
            break;
        case 2:
            result= 10;
            break;
        case 3:
            result= 11;
            break;
        case 4:
            result= 15;
            break;
        case 5:
            result=9;
            break;
        case 6:
            result =16;
            break;
        case 0:
            result=1;
            break;
        default:
            break;
    }

    return result;
}
//Deborah 15.11 00h20

uint MenuPerfil(OurCompany &c)
{
    criaparagrafo(20);

    displayHead();

    cout << "Nome: " << c.PessoaAtual->getNome() << endl
         << "NIF:  " << c.PessoaAtual->getNIF() << endl
         << "Email:  " << c.PessoaAtual->getEmail() << endl
         << "Interesses:  " << c.PessoaAtual->getInteressesFormated() << endl
         << "Password:  " << c.PessoaAtual->getWebPassword() << endl
         << "Imoveis:  ";

    vector<uint> tempor=c.PessoaAtual->getListaImoveis();
    vector<Imovel> ims=c.getImoveis();
    for(int i=0;i<tempor.size();i++){
        cout << ims.at(tempor.at(i)-1).getNome();
    }

    criaparagrafo(2);
                                   //substituir por mostrar infos do perfil dessa pessoa
    cout << "1- Alterar perfil" << endl
         << "2- Ver reservas" << endl
         << "3- Fazer logout" << endl
         << "0- Voltar";

    cout << endl;

    values[0]=4;
    uint result=verificaValores('<',"Introduza o menu a que pretende ir:  ",values,2);

    switch (result){
        case 1:
            result=12; // Menu Alterar Perfil
            break;
        case 2:
            result=13; // Menu Ver Reservas
            break;
        case 3:
            result=14; // Menu Logout
            break;
        case 0:
            result=1;    // Menu Inicial
            break;
        default:
            break;
    }

    return result;
}

uint MenuAlterarPerfil(OurCompany &c){

    novaJanela();

    cout << "1- Nome" << endl
         << "2- NIF" << endl
         << "3- Email" << endl
         << "4- Interesses" << endl
         << "5- Imoveis" << endl
         << "6- Password" << endl
         << "0- Voltar" << endl;

    criaparagrafo(2);
    uint dados[]={6};
    uint opcao=verificaValores('<', "Introduza o campo a alterar",dados,1);

    if(opcao==0)
        return 5;
    alteraRegistrado(*c.PessoaAtual,opcao,c);

    string temp;
    cout << "Alteracoes guardadas! Introduza qualquer tecla para continuar";cin >> temp;
    return 5;
}

uint MenuVerReservas(OurCompany &c) {

    auto imoveis=c.getImoveis();
    auto reservas=c.getReservas();
    vector<Reserva> res;

    for (auto it=reservas.begin();it!=reservas.end();it++){
        if(it->getIdContratante()==c.PessoaAtual->getId()){
            res.push_back(*it);
        }
    }


    cout << setw(4) << left <<  "ID"; cout << "|";
    cout << setw(25) << left << "Intervalo"; cout << "|";
    cout << setw(35) << left <<"Imovel"; cout << "|";
    cout << setw(15) << left << "Valor" << endl;


    cout << "----------------------------------------------------------------------------------------------------------------" << endl;


    for(int i=0;i<res.size();i++){
        cout << setw(4) << left << res.at(i).getID(); cout << "|";
        cout << setw(25) <<  left << res.at(i).getIntervalo().getIntervaloFormatted(); cout << "|";
        cout << setw(35) << left << imoveis.at(res.at(i).getIdImovel()-1).getNome(); cout << "|";
        cout << setw(15) << left << res.at(i).getValor() << endl;

    }

    criaparagrafo(3);

    cout << "1- Eliminar Reserva" << endl
         << "0- Voltar" << endl;

    uint dados[]={1};
    uint result= verificaValores('<',"Introduza o menu que deseja ir",dados,1);

    criaparagrafo(2);
    uint id;
    if(result==1){
        cout << "Introduza a reserva a apagar"; cin >> id;
        while(!findReserva(res,id)){
            cerr << "ERRO: Introduza a reserva a apagar"; cin >> id;
        }
        c.eraseReserva(id);
        string temporario;
        cout << "Reserva apagada! Introduza qualquer tecla para continuar"; cin >>temporario;
    }




    return 5;
}

uint MenuLogout(OurCompany& c) {

    novaJanela();
    string dados[]={"S","N"};
    string result=verificaValores('=',"Tem a certeza que deseja fazer logout? (S/N)",dados,2);

    if(result=="S"){
        c.PessoaAtual=NULL;
        //registrado=false;           //Já nao é necessario um registrado. Apagar
    }
    return 1;
}

uint MenuRegistrar(OurCompany& c) {

    criaparagrafo(20);

    displayHead();

    string temp;
    try {
        adicionaRegistrado(c);
    }catch(PessoaJaExistente pError) {
        cerr << "ERRO: Pessoa com NIF " << pError.getNIF() << " já existe! Prima qualquer tecla para continuar ";
        cin >> temp;
        return 1;
    }


    //registrado= true;
    novaJanela();

    cout << "Seja bem vindo a familia Imovelandia! Introduza qualquer tecla para continuar" << endl; cin>>temp;

    //c.personalizaFiltros();
    return 1;
}

uint MenuLogin(OurCompany& c) {

    criaparagrafo(20);

    displayHead();

    uint result;
    string login, password;
    Registrado r;

    cout << "Login (e-mail): ";
    cin >> login;

    r.setEmail(login);
    r.setNIF(0);
    r.setNome("");

    auto it = findClient(c.getRegistrados().begin(), c.getRegistrados().end(), r);

    while(it==c.getRegistrados().end()) {
        cout << "Login nao encontrado. Favor tentar novamente." << endl;
        cout << "Login (e-mail): ";
        cin >> login;
        r.setEmail(login);
        r.setNIF(0);
        r.setNome("");
        it = findClient(c.getRegistrados().begin(), c.getRegistrados().end(), r);
    }

    cout<<"Password: ";
    cin >> password;

    while(password != (*it)->getWebPassword()) {
        cout << "Senha incorrecta. Favor tentar novamente."<<endl;
        cout<<"Password: ";
        cin >> password;
    }
    c.PessoaAtual=*it;
    cout << "Senha correcta. Login realizado!" << endl;

    //c.personalizaFiltros();

    //Ir para MenuInicial
    result = 1;

    return result;
}

uint MenuDisplayImoveis(OurCompany &c)
{
    novaJanela();

    displayHead();

    displayImoveis(c.filtrados);
    criaparagrafo(2);

    if(c.PessoaAtual!=NULL){
        cout << "1- Comprar/Arrendar casa" << endl;
        values[0]=1;

    }else {
        values[0]=0;
    }

    cout << "0- Voltar";

    displayFooter(c);

    uint result=verificaValores('<',"Introduza o menu a que pretende ir:  ",values,2);

    switch (result){
        case 1:
            result= 8;
            break;
        case 0:
            result= 4;
            break;
        default:
            break;
    }

    return result;
}

void novaJanela(){
    criaparagrafo(30);
}

uint MenuLimparFiltros(OurCompany& c){

    novaJanela();
    c.filtrados=c.imoveis;

    string temp;
    cout << "Limpeza de filtros bem sucedida! Introduza qualquer tecla para continuar"; cin >> temp;
    return 4;
}

uint MenuFiltrarTipo(OurCompany &c){

    novaJanela();

    string tipo = verificaValores('=', "Introduza o tipo a filtrar por:", svalues, 3);

    c.createUpdateTree();

    if (c.showTreeImoveis("tipo", tipo) == EXIT_FAILURE)
    {
        return 11;
    }

    auto it = c.filtrados.begin();

    for (it; it < c.filtrados.end(); it++)
    {
        if (it->getTipo() != tipo)
        {
            c.filtrados.erase(it);

            it--;
        }
    }

    cout << "Filtragem bem sucedida!";

    cout << " Introduza qualquer tecla para continuar";
    cin >> tipo;

    return 4;
}

uint MenuFiltrarFreg(OurCompany &c)
{

    novaJanela();

    string freg, codpost;
    string option;
    auto it = c.filtrados.begin();

    cout << "Quer filtrar por freguesia ou codigo postal? ";
    getline(cin,option);

    if (option == "freguesia")
    {

    cout << "Introduza a freguesia a filtrar por:";
    cin >> freg;

    c.createUpdateTree();

    if (c.showTreeImoveis("freguesia", freg) == EXIT_FAILURE)
    {
    return 11;
    }

    for (it; it < c.filtrados.end(); it++)
    {
    if (it->getAddress().getFreguesia() != freg)
    {
    c.filtrados.erase(it);

    it--;
    }
    }
    }
    else if (option == "codigo postal")
    {

    cout << "Introduza o codigo postal a filtrar por:";
    cin >> codpost;

    c.createUpdateTree();

    if (c.showTreeImoveis("codigo postal", codpost) == EXIT_FAILURE)
    {
        return 11;
    }

    for (it; it < c.filtrados.end(); it++)
    {
        if (it->getAddress().getCodPos() != codpost)
        {
            c.filtrados.erase(it);

            it--;
        }
    }
    } else {
        cout << "Opcao invalida, favor tente novamente." << endl;
        return 11;
    }

    cout << "Filtragem bem sucedida!";

    cout << " Introduza qualquer tecla para continuar";
    cin >> freg;

    return 4;
    }

uint MenuComprarImovel(OurCompany& c){

    novaJanela();

    listarImoveis(c.filtrados);
    uint temp;

    //Obtem o id do imovel a procurar(com prevenção de erros)
    cout << "Introduza o Imovel a comprar/alugar: "; cin >> temp;

    int ind;

    while((ind=procuraIdEmImoveis(c.filtrados,temp))==-1){
        cerr << "ERRO: Introduza um imovel valido";cin >>temp;
    }

    //Calcula preco com desconto
    double desconto;
    if(c.PessoaAtual->getIsCompany()){
        Empresa *e = dynamic_cast<Empresa*>(c.PessoaAtual);
        desconto= e->getIsencaoImpostos();
    }else{
        Singular *s = dynamic_cast<Singular*>(c.PessoaAtual);
        desconto= s->getReducaoImpostos();
    }
    desconto=desconto/100;

    //valor por um dia/semana/mes ou total
    double val= c.contratos.at(c.filtrados.at(ind).getContrato()-1)->getPreco() - c.contratos.at(c.filtrados.at(ind).getContrato()-1)->getPreco() * desconto;



    criaparagrafo(3);

    uint idxContrato;
    idxContrato=c.filtrados.at(ind).getContrato();

    if(c.contratos.at(idxContrato-1)->returnType()!=2){

        cout << c.filtrados.at(ind);
        cout << "Preco com desconto:  " << val << endl;

        try{
        confirmaAssinatura(c.PessoaAtual->getNome());
        }catch(...){
            return 6;
        }
        c.eraseImovel(c.filtrados.at(ind).getId());


        string continuar;
        cout << "Compra/Reserva feita! Introduza qualquer tecla para continuar";cin >> continuar;
        //c.personalizaFiltros();
        return 6;

    }


    //Este intervalo tem que estar ORDENADO!
    vector<Intervalo> inds= c.filtrados.at(ind).getInds();

    /*Introducao das datas pretendentes*/

    cout << "Datas Indisponiveis:  ";
    for(int i=0;i<inds.size();i++)
        cout << inds.at(i) << "   ";

    cout << endl << "Introduza uma data disponivel: ";
    Date di,df;
    di.insertDate();
    df.insertDate();

    Intervalo inter(di,df);

    bool encontrouIntersecao=false;

    //verifica se alguma data coincide
    for(int i=0;i<inds.size();i++){

        /*Se o proximo intervalo*/

        if(InterCoincide(inds.at(i),inter)){
            encontrouIntersecao=true;
            break;
        }
    }

    long int ndias;
    string base;
    bool ndiasValido=true;


    if(!encontrouIntersecao){
        ndias=df-di;
        idxContrato=c.filtrados.at(ind).getContrato();
        base=c.contratos.at(idxContrato-1)->getBase();
        if(base=="semanal"){
            if(ndias%7!=0){
                ndiasValido=false;
            }
        }else if(base=="mensal"){
            if(ndias%30!=0){
                ndiasValido=false;
            }
        }

    }



    while (encontrouIntersecao || !ndiasValido){
        cerr << "ERRO: Intervalo invalido(Datas ja reservadas). Introduza novamente" << endl;
        di.insertDate();
        df.insertDate();
        inter.setIntervalo(di,df);

        encontrouIntersecao=false;

        for(int i=0;i<inds.size();i++){

            /*Se o proximo intervalo*/

            if(InterCoincide(inds.at(i),inter)){
                encontrouIntersecao=true;
                break;
            }

        }

        if(!encontrouIntersecao){
            ndias=df-di;
            idxContrato=c.filtrados.at(ind).getContrato();
            base=c.contratos.at(idxContrato-1)->getBase();
            if(base=="semanal"){
                if(ndias%7!=0){
                    ndiasValido=false;
                }
            }else if(base=="mensal"){
                if(ndias%30!=0){
                    ndiasValido=false;
                }
            }

        }
    }

    criaparagrafo(3);

    try{
        confirmaAssinatura(c.PessoaAtual->getNome());
    }catch(...){
        return 6;
    }



    Reserva res(c.filtrados.at(ind).getProprietario(),c.PessoaAtual->getId(),inter,c.filtrados.at(ind).getId(),0);
    c.addReserva(res);

    //adiciona intervalo de indisponibilidade ao imovel

    c.addInterEmImovel(ind,inter);
    c.sortIntervalosDeImovel(ind);

    //c.personalizaFiltros();

    return 6;
}

uint MenuFiltrarPreco(OurCompany& c){
    novaJanela();

    uint precoi,precos;
    string temp;

    cout << "Introduza o preco minimo (0 se nao quiser minimo): "; cin>>precoi;

    cout << "Introduza o preco maximo (0 se nao quiser maximo): "; cin>>precos;

    auto it=c.filtrados.begin();

    for(it;it<c.filtrados.end();it++){
        if(precoi==0){
            if(c.contratos.at(it->getContrato())->getPreco() > precos){
                c.filtrados.erase(it);
                it--;

            }
        }else if(precos==0){
            if(c.contratos.at(it->getContrato())->getPreco() < precoi){
                c.filtrados.erase(it);
                it--;
            }
        }else {
            if(c.contratos.at(it->getContrato())->getPreco() > precos && c.contratos.at(it->getContrato())->getPreco() < precoi){
                c.filtrados.erase(it);
                it--;
            }
        }

    }

        cout << "Filtragem bem sucedida!";

    cout << " Introduza qualquer tecla para continuar";cin >> temp;

    return 4;

}

uint MenuLeiloes(OurCompany &c){

    novaJanela();
    cout << "1- Ver leiloes disponiveis" << endl;
    int val[1];
    val[0]=1;
    if(c.PessoaAtual!=NULL){
        cout << "2- Criar leilao" << endl;
        val[0]=2;
    }
    cout << "0- Voltar" << endl;

    criaparagrafo(2);

    uint result=verificaValores('<',"Introduza o menu a que pretende ir:  ",val,1);



    switch (result){
        case 1:
            result=18;
            break;
        case 2:
            result=17;
            break;
        case 0:
            result=4;
            break;
        default:
            cerr << "ERRO" << endl;
            break;
    }
    return result;

}

uint MenuCriarLeilao(OurCompany &c){

    novaJanela();
    string tempoo;
    int res;
    vector<uint> idImov= c.PessoaAtual->getListaImoveis();
    if(idImov.empty()){
        cout << "Não tem nenhum imovel para leiloar! Introduza qualquer tecla para continuar";cin >> res;
        return 16;      //MenuLeilao
    }
    vector<Imovel> imvs;
    for(auto it=idImov.begin();it!=idImov.end();it++){
        imvs.push_back(c.imoveis.at(*it - 1));
    }
    listarImoveis(imvs);

    criaparagrafo(2);

    int val[1]; val[0]=imvs.size();

    uint result=verificaValores('<',"Introduza o imovel a leiloar:   ", val, 1);

    bool existe=existeLeilao(c.leiloes,imvs.at(result-1).getId());
    if(existe){
        cout << "Um leilao ja existe para esse imovel! Introduza qualquer tecla para continuar"; cin >> tempoo;
        return 16;
    }

    if(result==0){
        return 16;
    }

    Date final;
    cout << "Insira a data final do leilao" << endl;
    final.insertDate();

    novaJanela();

    Leilao novo(result,final);


    c.leiloes.push_back(novo);


    cout << "Leilao criado! Introduza qualquer tecla para continuar"; cin >> tempoo;

    return 16;
}

uint MenuVerLeiloes(OurCompany &c){

    novaJanela();

    displayLeiloes(c);

    criaparagrafo(1);
    int val[1];

    val[0]=0;
    if(c.PessoaAtual!=NULL && !c.leiloes.empty()){
        cout << "1- Fazer licitacao" << endl;
        cout << "2- Eliminar licitacao" << endl;
        val[0]=2;
    }

    cout << "0- Voltar";

    criaparagrafo(2);

    uint result=verificaValores('<',"Introduza o que pretende fazer:  ", val, 1);

    if(result==0)
        return 16;


    val[0]=c.leiloes.size();
    string msg;
    uint opc=result;

    if(result==1){
        msg="Introduza o imovel a fazer a licitacao:  ";
    }else {
        msg= "Introduza o leilao em que quer eliminar a sua licitacao";
    }

    result=verificaValores('<',msg, val, 1);

    if( opc==1){

        double mon;
        cout << "Introduza o montante:  "; cin >> mon;
        while (cin.fail()){
            cin.ignore();
            cin.clear();
            cerr << "Introduza um valor valido: ";cin >> mon;
        }

        ItemLeilao il(c.PessoaAtual->getId(),mon);

        c.leiloes.at(result-1).addBidding(il);
    }else {
        c.leiloes.at(result-1).eraseBidding(c.PessoaAtual->getId());
    }

    cout << "Operacao feita! Introduza qualquer tecla para continuar"; cin >>msg;

    return 16;

}


