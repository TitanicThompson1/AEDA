//
// Created by flavi on 08/11/2019. mudei
//
//modifiquei

#ifndef PROJAEDA_DATE_H
#define PROJAEDA_DATE_H



#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class Date {

private:
    unsigned short day;
    unsigned short month;
    unsigned short year;

public:

    //Constructors
    Date(){};
    Date(string date);
    Date(unsigned short day, unsigned short month, unsigned short year);

    // GET methods
    unsigned short getDay() const {return day;};
    unsigned short getMonth() const {return month;};
    unsigned short getYear() const {return year;};
    string getDateFormatted() const;

    // SET methods
    void setDay(unsigned short day){this->day=day;};
    void setMonth(unsigned short month){this->month=month;};
    void setYear(unsigned year){this->year=year;};
    void setDateFromString(string s);


    // other methods

    /*
    @Função para inserir datas num determinado contexto retornando um objecto da classe Date
    @return objecto do tipo data
    */
    void insertDate();

    /*
    @Verifica se data é válida para os meses, dias e anos e regras inerentes
       @return false se é inválida e true se é válida
    */
    bool validDate();

    //formata o cout
    friend ostream& operator<<(ostream& out, const Date & data);

    //Instrui em como efectuar a operacao ==
    friend bool operator==(const Date& d1, const Date& d2);

    //Instrui em como efectuar a operacao <
    friend bool operator<(const Date& begin, const Date& end);

    //Instrui em como efectuar a operacao >
    friend bool operator>(const Date& begin, const Date& end);

    friend bool operator<=(const Date& begin, const Date& end);

    friend bool operator>=(const Date& begin, const Date& end);

    //fazer
    long int operator-(const Date& dt2);

};


class Intervalo{
    Date dataInicio;
    Date dataFim;

public:
    Intervalo(){};
    Intervalo(Date date1,Date date2);

    /*GET-Methods*/
    Date getDataInicio() const{return dataInicio;};
    Date getDataFim() const {return dataFim;};
    string getIntervaloFormatted() const;
    long int  getNumDays() {return (dataFim - dataInicio);};

    /*SET-Methods*/
    void setIntervalo(Date di,Date df){dataInicio=di;dataFim=df;};
    void setIntervaloFromString(string s);

    bool operator<(Intervalo& int1);
    friend ostream& operator<<(ostream& out, Intervalo& intv );

};

bool InterCoincide(Intervalo& inter1, Intervalo& inter2);


class IntervaloException{
    Intervalo intv;

public:
    IntervaloException(Intervalo intv) : intv(intv){};
    //friend ostream& operator<<(ostream& out, Intervalo& intv);
};




/*
class DataException{
    Data data ;
public:
    DataException(Date data);
    friend ostream<< operator(ostream out, Date data);
};
*/
#endif //PROJAEDA_DATE_H
