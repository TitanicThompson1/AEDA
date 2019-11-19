#include <iostream>
#include "Hospital.h"
#include "Doctor.h"

int main() {

    Hospital hosp(2);

    stack<Patient> s1;
    s1.push(Patient(222,"medicalSpecialtyA"));
    hosp.addTrays(s1);

    stack<Patient> s2;
    s2.push(Patient(555,"medicalSpecialtyB"));
    s2.push(Patient(341,"medicalSpecialtyC"));
    hosp.addTrays(s2);

    stack<Patient> s3;
    s3.push(Patient(341,"medicalSpecialtyC"));
    hosp.addTrays(s3);

    stack<Patient> s4;
    s4.push(Patient(341,"medicalSpecialtyC"));
    s4.push(Patient(111,"medicalSpecialtyC"));
    hosp.addTrays(s4);

    cout << "0: " << hosp.removePatients(777) << endl;
    list<stack<Patient> > b1 = hosp.getTrays();
    cout << "4: " << b1.size() << endl;
    cout << "222: " << b1.front().top().getCode() << endl;

    cout << "2: " << hosp.removePatients(341) << endl;
    b1 = hosp.getTrays();
    cout << "3: " << b1.size() << endl;
    cout << "222: " << b1.front().top().getCode() << endl;
    b1.pop_front();
    cout << "1: " << b1.front().size() << endl;
    cout << "555: " << b1.front().top().getCode() << endl;
    b1.pop_front();
    cout << "2: " << b1.front().size() << endl;
    cout << "111: " << b1.front().top().getCode() << endl;

    cout << "1: " << hosp.removePatients(222) << endl;
    b1 = hosp.getTrays();
    cout << "2: " << b1.size() << endl;

    return 0;
}

/*Teste a)
    Hospital hosp;
    queue<Patient> q1;
    q1.push(Patient(123,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    Doctor d1(1,"medicalSpecialtyX",q1);
    hosp.addDoctor(d1);
    Doctor d2(2,"medicalSpecialtyZ");
    hosp.addDoctor(d2);
    queue<Patient> q3;
    q3.push(Patient(111,"medicalSpecialtyA"));
    q3.push(Patient(666,"medicalSpecialtyA"));
    q3.push(Patient(777,"medicalSpecialtyA"));
    Doctor d3(3,"medicalSpecialtyA",q3);
    hosp.addDoctor(d3);
    queue<Patient> q4;
    q4.push(Patient(456,"medicalSpecialtyX"));
    Doctor d4(4,"medicalSpecialtyX",q4);
    hosp.addDoctor(d4);
    cout << "0: " << hosp.numPatients("medicalSpecialtyZ") << endl;
    cout << "4: " << hosp.numPatients("medicalSpecialtyX") << endl;
    cout << "3: " << hosp.numPatients("medicalSpecialtyA") << endl;
    return 0;
     */

/* teste b)
Hospital hosp;

queue<Patient> q1;
q1.push(Patient(123,"medicalSpecialtyZ"));
q1.push(Patient(456,"medicalSpecialtyZ"));
Doctor d1(1,"medicalSpecialtyZ",q1);
hosp.addDoctor(d1);

queue<Patient> q2;
q2.push(Patient(321,"medicalSpecialtyZ"));
Doctor d2(2,"medicalSpecialtyZ",q2);
hosp.addDoctor(d2);

queue<Patient> q3;
q3.push(Patient(111,"medicalSpecialtyZ"));
q3.push(Patient(666,"medicalSpecialtyZ"));
Doctor d3(3,"medicalSpecialtyZ",q3);
hosp.addDoctor(d3);

queue<Patient> q4;
Doctor d4(4,"medicalSpecialtyX",q4);
hosp.addDoctor(d4);

queue<Patient> q5;
q5.push(Patient(341,"medicalSpecialtyB"));
Doctor d5(5,"medicalSpecialtyB",q5);
hosp.addDoctor(d5);

hosp.sortDoctors();
list<Doctor> res = hosp.getDoctors();
cout << "5:  " << res.size() << endl;

cout << "4:  " << res.front().getCode() << endl;
cout << "0:  " << res.front().getPatients().size() << endl;
res.pop_front();
cout << "5:  " << res.front().getCode() << endl;
cout << "1:  " << res.front().getPatients().size() << endl;
res.pop_front();
cout << "2:  " << res.front().getCode() << endl;
cout << "1:  " << res.front().getPatients().size() << endl;
res.pop_front();
cout << "1:  " << res.front().getCode() << endl;
cout << "2:  " << res.front().getPatients().size() << endl;
res.pop_front();
cout << "3:  " << res.front().getCode() << endl;
cout << "2:  " << res.front().getPatients().size() << endl;
res.pop_front();
*/

/* teste c)
Doctor d1(1,"medicalSpecialtyX");
d1.moveToFront(111);
queue<Patient> res = d1.getPatients();
cout << "0:  " << res.size() << endl;

queue<Patient> q1;
q1.push(Patient(123,"medicalSpecialtyX"));
q1.push(Patient(456,"medicalSpecialtyX"));
q1.push(Patient(789,"medicalSpecialtyX"));
Doctor d2(2,"medicalSpecialtyX",q1);

d2.moveToFront(789);
res = d2.getPatients();
cout << "3:  " << res.size() << endl;
cout << "789:  " << res.front().getCode() << endl;
res.pop();
cout << "123:  " << res.front().getCode() << endl;
res.pop();
cout << "456:  " << res.front().getCode() << endl;

Doctor d3(3,"medicalSpecialtyX",q1);
d3.moveToFront(111);
res = d3.getPatients();
cout << "3:  " << res.size() << endl;
cout << "123:  " << res.front().getCode() << endl;
res.pop();
cout << "456:  " << res.front().getCode() << endl;
res.pop();
cout << "789:  " << res.front().getCode() << endl;
*/

/*teste d)
    Hospital hosp;

    queue<Patient> q;
    Doctor d1(1,"medicalSpecialtyZ",q);
    hosp.addDoctor(d1);

    Doctor d2(2,"medicalSpecialtyX",q);
    hosp.addDoctor(d2);

    queue<Patient> q3;
    Doctor d3(3,"medicalSpecialtyZ",q);
    hosp.addDoctor(d3);

    Doctor d4(4,"medicalSpecialtyX",q);
    hosp.addDoctor(d4);

    cout << "true:  " << hosp.addDoctor(50,"medicalSpecialtyX") << endl;
    list<Doctor> res = hosp.getDoctors();
    cout << "5:  " << res.size() << endl;
    cout << "50:  " << res.back().getCode() << endl;
    cout << "1:  " << res.front().getCode() << endl;

    cout << "false:  " << hosp.addDoctor(55,"medicalSpecialtyX") << endl;
    res = hosp.getDoctors();
    cout << "5:  " << res.size() << endl;

    cout << "true:  " <<hosp.addDoctor(60,"medicalSpecialtyA") << endl;
    res = hosp.getDoctors();
    cout << "6:  " << res.size() << endl;
    cout << "60:  " << res.back().getCode() << endl;
    cout << "1:  " << res.front().getCode() << endl;
    return 0;
    */

/*teste e)
    Hospital hosp;

    queue<Patient> q1;
    q1.push(Patient(123,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    q1.push(Patient(789,"medicalSpecialtyX"));
    Doctor d1(10,"medicalSpecialtyX",q1);
    hosp.addDoctor(d1);

    Doctor d2(20,"medicalSpecialtyZ");
    hosp.addDoctor(d2);

    queue<Patient> q3;
    q3.push(Patient(111,"medicalSpecialtyZ"));
    q3.push(Patient(666,"medicalSpecialtyZ"));
    q3.push(Patient(777,"medicalSpecialtyZ"));
    Doctor d3(30,"medicalSpecialtyZ",q3);
    hosp.addDoctor(d3);

    queue<Patient> q4;
    q4.push(Patient(341,"medicalSpecialtyX"));
    Doctor d4(40,"medicalSpecialtyX",q4);
    hosp.addDoctor(d4);

    queue<Patient> q5;
    q5.push(Patient(111,"medicalSpecialtyZ"));
    q5.push(Patient(666,"medicalSpecialtyZ"));
    Doctor d5(50,"medicalSpecialtyZ",q5);
    hosp.addDoctor(d5);

    try{
    hosp.removeDoctor(44);
    }catch(Hospital::DoctorInexistent e){
        cout << "Encontrou exceccao!!!" << endl;
    }
    cout << "5: " << hosp.getDoctors().size() << endl;

    queue<Patient> p1 = hosp.removeDoctor(50);
    cout << "2: " << p1.size() << endl;
    cout << "111: " << p1.front().getCode() << endl;
    cout << "4: " << hosp.getDoctors().size() << endl;

    p1 = hosp.removeDoctor(20);
    cout << "0: " << p1.size() << endl;
    cout << "3 " << hosp.getDoctors().size() << endl;

    return 0;
    */

/* teste f)
    Hospital hosp;

    queue<Patient> q1;
    q1.push(Patient(123,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    Doctor d1(1,"medicalSpecialtyX",q1);
    hosp.addDoctor(d1);

    Doctor d2(2,"medicalSpecialtyZ");
    hosp.addDoctor(d2);

    queue<Patient> q3;
    q3.push(Patient(111,"medicalSpecialtyZ"));
    q3.push(Patient(666,"medicalSpecialtyZ"));
    q3.push(Patient(777,"medicalSpecialtyZ"));
    Doctor d3(3,"medicalSpecialtyZ",q3);
    hosp.addDoctor(d3);

    queue<Patient> q4;
    q4.push(Patient(341,"medicalSpecialtyX"));
    Doctor d4(4,"medicalSpecialtyX",q4);
    hosp.addDoctor(d4);

    cout << "true: " << hosp.putInLessBusyDoctor(321,"medicalSpecialtyX") << endl;
    list<Doctor> docs = hosp.getDoctors();
    queue<Patient> Patients1 = docs.front().getPatients();
    cout << "3: " <<  Patients1.size() << endl;
    docs.pop_front(); docs.pop_front(); docs.pop_front();

    queue<Patient> patients2 = docs.front().getPatients();
    cout << "2: " <<  patients2.size() << endl;
    cout << "321: " <<  patients2.back().getCode() << endl;

    cout << "true: " << hosp.putInLessBusyDoctor(888,"medicalSpecialtyZ") << endl;
    docs = hosp.getDoctors();
    queue<Patient> patients3 = docs.front().getPatients();
    cout << "3: " <<  patients3.size() << endl;

    docs.pop_front();
    patients3 = docs.front().getPatients();
    cout << "1: " << patients3.size() << endl;
    cout << "888: " << patients3.back().getCode() << endl;

    docs.pop_front();
    patients3 = docs.front().getPatients();
    cout << "3: " << patients3.size() << endl;

    cout << "false: " << hosp.putInLessBusyDoctor(222,"medicalSpecialtyK") << endl;
    cout << "false: " << hosp.putInLessBusyDoctor(444,"medicalSpecialtyW") << endl;
*/

/* teste g)

    Hospital hosp(2);
    queue<Patient> q1;
    q1.push(Patient(123,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    q1.push(Patient(456,"medicalSpecialtyX"));
    Doctor d1(1,"medicalSpecialtyX",q1);
    hosp.addDoctor(d1);

    Doctor d2(2,"medicalSpecialtyZ");
    hosp.addDoctor(d2);

    queue<Patient> q3;
    q3.push(Patient(111,"medicalSpecialtyZ"));
    q3.push(Patient(666,"medicalSpecialtyZ"));
    q3.push(Patient(777,"medicalSpecialtyZ"));
    Doctor d3(3,"medicalSpecialtyZ",q3);
    hosp.addDoctor(d3);

    queue<Patient> q4;
    q4.push(Patient(341,"medicalSpecialtyX"));
    Doctor d4(4,"medicalSpecialtyX",q4);
    hosp.addDoctor(d4);

    stack<Patient> s1;
    s1.push(Patient(222,"medicalSpecialtyA"));
    hosp.addTrays(s1);
    stack<Patient> s2;
    s2.push(Patient(555,"medicalSpecialtyB"));
    s2.push(Patient(865,"medicalSpecialtyC"));
    hosp.addTrays(s2);
    stack<Patient> s3;
    s3.push(Patient(341,"medicalSpecialtyD"));
    hosp.addTrays(s3);

    hosp.processPatient(2);
    list<stack<Patient> > b1 = hosp.getTrays();
    cout << "3: " << b1.size() << endl;
    cout << "222: " << b1.front().top().getCode() << endl;

    hosp.processPatient(1);
    b1 = hosp.getTrays();
    cout << "3: " << b1.size() << endl;
    cout << "123: " << b1.front().top().getCode() << endl;

    hosp.processPatient(3);
    b1=hosp.getTrays();
    cout << "3: " << b1.size() << endl;
    cout << "123: " << b1.front().top().getCode() << endl;
    cout << "2: " << b1.back().size() << endl;
    cout << "111: " << b1.back().top().getCode() << endl;

    hosp.processPatient(3);
    b1=hosp.getTrays();
    cout << "4: " << b1.size() << endl;
    cout << "1: " << b1.back().size() << endl;
    cout << "666: " << b1.back().top().getCode() << endl;

    hosp.processPatient(6);
    b1=hosp.getTrays();
    cout << "4: " << b1.size() << endl;
    cout << "1: " << b1.back().size() << endl;
    cout << "666: " << b1.back().top().getCode() << endl;
    */

/*
 * teste h)
    Hospital hosp(2);

    stack<Patient> s1;
    s1.push(Patient(222,"medicalSpecialtyA"));
    hosp.addTrays(s1);

    stack<Patient> s2;
    s2.push(Patient(555,"medicalSpecialtyB"));
    s2.push(Patient(341,"medicalSpecialtyC"));
    hosp.addTrays(s2);

    stack<Patient> s3;
    s3.push(Patient(341,"medicalSpecialtyC"));
    hosp.addTrays(s3);

    stack<Patient> s4;
    s4.push(Patient(341,"medicalSpecialtyC"));
    s4.push(Patient(111,"medicalSpecialtyC"));
    hosp.addTrays(s4);

    cout << "0: " << hosp.removePatients(777) << endl;
    list<stack<Patient> > b1 = hosp.getTrays();
    cout << "4: " << b1.size() << endl;
    cout << "222: " << b1.front().top().getCode() << endl;

    cout << "2: " << hosp.removePatients(341) << endl;
    b1 = hosp.getTrays();
    cout << "3: " << b1.size() << endl;
    cout << "222: " << b1.front().top().getCode() << endl;
    b1.pop_front();
    cout << "1: " << b1.front().size() << endl;
    cout << "555: " << b1.front().top().getCode() << endl;
    b1.pop_front();
    cout << "2: " << b1.front().size() << endl;
    cout << "111: " << b1.front().top().getCode() << endl;

    cout << "1: " << hosp.removePatients(222) << endl;
    b1 = hosp.getTrays();
    cout << "2: " << b1.size() << endl;
*/