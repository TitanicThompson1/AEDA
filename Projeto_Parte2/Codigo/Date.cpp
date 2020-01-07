//
// Created by flavi on 08/11/2019. mudei
//

#include"Date.h"



Date::Date(string date) {

    istringstream str_date(date);

    vector<string> s;
    string aux_str = "";

    //obter elementos da data
    while (getline(str_date, aux_str, '/')) {

        s.push_back(aux_str);

    }

    year = stoi(s[0]);
    month = stoi(s[1]);
    day = stoi(s[2]);


}

Date::Date(unsigned short day, unsigned short month, unsigned short year) {

    this->year = year;
    this->month = month;
    this->day = day;
}


/*********************************
 * Show Date
 ********************************/

// display a Date in a nice format
ostream& operator<<(ostream& out, const Date & date) {

    //vamos definir como o operador << se comporta com a classe DATE!!

    return  out << right << setfill('0') << setw(4) << date.getYear() << "/" << setfill('0') << setw(2) << date.getMonth() << "/" << setfill('0') << setw(2) << date.getDay() << setfill(' ');

}


void Date::insertDate() {
    //variável para validar data a ser inserida
    bool valid_date = false;

    Date date, empty;
    //objecto da classe date que será retornado

    unsigned short year, month, day;

    //ciclo continua enquanto data for invalida
    while (!valid_date) {
        Date aux_date;
        //Obter informação para a data do que é inserido


        cout << "Ano: ";
        cin >> year;


        //verifica se o utilizador deseja cancelar
        if (year == 0 && !cin.fail())
        {
            this->year = 0;
            this->month = 0;
            this->day = 0;
            return;
        }

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Mes: ";
        cin >> month;


        //verifica se o utilizador deseja cancelar
        if (month == 0 && !cin.fail())
        {
            this->year = 0;
            this->month = 0;
            this->day = 0;
            return;
        }

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Dia: ";
        cin >> day;

        //verifica se o utilizador deseja cancelar
        if (day == 0 && !cin.fail())
        {
            this->year = 0;
            this->month = 0;
            this->day = 0;
            return;
        }
        //Controlar se data inserida é válida



        if (!cin) {
            cerr << "Data inserida invalida, tente novamente!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');


        }

        else {


            //Controla se data inserida é válida tendo em conta as regras para as mesmas
            aux_date = Date(day, month, year);
            if (aux_date.validDate()) {
                valid_date = true;
                this->year = year;
                this->month = month;
                this->day = day;
            }
            else {
                cerr << "Date inserida invalida, ano, mes ou dia fora da gama permitida, tente novamente!" << endl;

            }
        }
        //Controla se data inserida é válida tendo em conta as regras para as mesmas
    }



}




bool Date::validDate() {

    //ano bissexto
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 and year % 100 == 0)) {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) and (day >= 1 and day <= 31)) {

            return true;
        }
        else if ((month == 4 || month == 6 || month == 8 || month == 10 || month == 12) and (day >= 1 and day <= 30)) {
            return true;
        }
        else {
            if (month == 2 and (day >= 1 and day <= 29)) {
                return true;
            }

        }


    }
        //resto dos anos
    else {

        //calendário gregoriano começa o ano com 1, tendo passado de 1 a.C. para 1 a.D.
        //
        if (year >= 1) {
            if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11) and (day >= 1 and day <= 31)) {

                return true;
            }
            else if ((month == 4 || month == 6 || month == 8 || month == 10 || month == 12) and (day >= 1 and day <= 30)) {
                return true;
            }
            else {
                if (month == 2 and (day >= 1 and day <= 28)) {
                    return true;
                }

            }




        }

    }

    return false;

}


bool operator<(const Date& begin, const Date& end)
{

    //Situações possíveis de comparação da data 1 com data 2
    if (begin.year < end.year) {

        return true;
    }
    else if (begin.year == end.year && begin.month < end.month) {
        return true;
    }
    else if (begin.year == end.year && begin.month == end.month && begin.day < end.day) {
        return true;

    }


    else {
        return false;
    }
}

bool operator==(const Date& d1, const Date& d2)
{
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)				//compara o ano, o mes e o dia das duas datas
    {
        return true;
    }
    return false;
}

bool operator>(const Date& begin, const Date& end)
{
    if (begin.year > end.year) {

        return true;
    }
    else if (begin.year == end.year && begin.month > end.month) {
        return true;
    }
    else if (begin.year == end.year && begin.month == end.month && begin.day > end.day) {
        return true;

    }


    else {
        return false;
    }
}

bool operator<=(const Date& begin, const Date& end)
{


    //Situações possíveis de comparação da data 1 com data 2
    if (begin.year < end.year) {

        return true;
    }
    else if (begin.year == end.year && begin.month < end.month) {
        return true;
    }
    else if (begin.year == end.year && begin.month == end.month && begin.day <= end.day) {
        return true;

    }


    else {
        return false;
    }
}

bool operator>=(const Date& begin, const Date& end)
{
    if (begin.year > end.year) {

        return true;
    }
    else if (begin.year == end.year && begin.month > end.month) {
        return true;
    }
    else if (begin.year == end.year && begin.month == end.month && begin.day >= end.day) {
        return true;

    }


    else {
        return false;
    }
}



Intervalo::Intervalo(Date date1,Date date2){

    dataInicio=date1;
    dataFim=date2;
}

bool InterCoincide(Intervalo& inter1, Intervalo& inter2){
    if(inter1 < inter2)
        return false;
    else if(inter2 < inter1)
        return false;
    else
        return true;
}

bool Intervalo::operator<(Intervalo& int1){

    if(int1.dataFim.getYear()< dataInicio.getYear())
        return true;
    else if(int1.dataFim.getMonth()< dataInicio.getMonth())
        return true;
    else if(int1.dataFim.getDay() < dataInicio.getDay())
        return true;

    return false;
}


ostream& operator<<(ostream& out, Intervalo& intv ){
    out << intv.dataInicio.getDateFormatted() <<"-" << intv.dataFim.getDateFormatted();
    return out;

}

string Date::getDateFormatted() const{
    string result;
    result=to_string(day)+"/"+ to_string(month)+"/"+to_string(year);
    return result;
}

void Date::setDateFromString(string s){
    istringstream sstream(s);
    string temp;
    getline(sstream,temp,'/');
    day=stoi(temp);
    getline(sstream,temp,'/');
    month=stoi(temp);
    getline(sstream,temp);
    year=stoi(temp);
}

void Intervalo::setIntervaloFromString(string s){
    istringstream sstream(s);
    string temp;
    getline(sstream, temp,'-');

    dataInicio.setDateFromString(temp);
    getline(sstream, temp);
    dataFim.setDateFromString(temp);
}

string Intervalo::getIntervaloFormatted() const{
    string result;
    result=dataInicio.getDateFormatted() + "-" + dataFim.getDateFormatted();
    return result;
}


// To store number of days in all months from January to Dec.
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

// This function counts number of leap years before the
// given date
int countLeapYears(Date d)
{
    int years = d.getYear();

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.getMonth() <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

// This function returns number of days between two given
// dates
long int Date::operator-(const Date& dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'

    // initialize count using years and day
    long int n1 = this->year*365 + this->day;

    // Add days for months in given date
    for (int i=0; i<this->month - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(*this);

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

    long int n2 = dt2.year*365 + dt2.day;
    for (int i=0; i<dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}
