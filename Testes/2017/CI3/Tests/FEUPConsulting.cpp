/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//
//TODO
void FEUPConsulting::addAvailability(Student* student, string expertizeAvailable, unsigned cost) {

    BSTItrIn<Expertize> it(expertizes);
    Expertize wanted(expertizeAvailable,cost);
    bool found=false;

    while(!it.isAtEnd()){
        Expertize exp=it.retrieve();
        if(wanted==exp){
            it.retrieve().addConsultant(student);
            found=true;
            break;
        }
        it.advance();
    }
    if(!found){
        wanted.addConsultant(student);
        expertizes.insert(wanted);
    }

}
//TODO:
vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	vector<Student*> temp;
    BSTItrIn<Expertize> it(expertizes);

    while(!it.isAtEnd()){
        Expertize exp=it.retrieve();
        if(project->getExpertize() == exp.getName() && project->getCost()==exp.getCost()){
            auto students=exp.getConsultants();
            for(auto it=students.begin();it!=students.end();it++){
                if((*it)->getCurrentProject()==""){
                    temp.push_back(*it);
                }
            }
            break;
        }
        it.advance();
    }
	return temp;

}


bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
	//TODO:
	return true;

}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {
	//TODO:

}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	//TODO

}


//
// TODO: Part III - Priority Queue
//
//TODO:
void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {

	for(auto it=candidates.begin();it!=candidates.end();it++){

	    if(it->getPastProjects().size() >= min){
            activeStudents.push(*it);
	    }
	}

}


int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {
	//TODO:
	return 0;

}





















