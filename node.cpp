#include "node.h"
#include <iostream>
using namespace std;
Node::Node(Student* in_student){
	student = in_student;
	next = nullptr;//get the student set next
}
Node::~Node(){//delete entire list
	delete student;//delete student
	if(next){
		delete next;
	}
}
void Node::print(){//print out all students
	cout << "Name "<<student->getname()<<endl;
	cout<<"ID "<<student->getid()<<endl;
	cout << "GPA "<< student->getgpa()<<endl;
	if(next){
		next->print();
	}
}
Node* Node::getNext(){//get next
	return next;
}
Student* Node::getStudent(){//get the student
	return student;
}
void Node::setNext(Node * node){//ste the next node
	next = node;
}
