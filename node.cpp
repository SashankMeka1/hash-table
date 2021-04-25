#include "node.h"
#include <iostream>
using namespace std;
Node::Node(Student* in_student){
	student = in_student;
	next = nullptr;
}
Node::~Node(){
	delete student;
	if(next){
		delete next;
	}
}
void Node::print(){
	cout << "Name "<<student->getname()<<endl;
	cout<<"ID "<<student->getid()<<endl;
	cout << "GPA "<< student->getgpa()<<endl;
	if(next){
		next->print();
	}
}
Node* Node::getNext(){
	return next;
}
Student* Node::getStudent(){
	return student;
}
void Node::setNext(Node * node){
	next = node;
}
