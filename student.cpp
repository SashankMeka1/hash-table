#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;
Student::Student(){//read in input for student definition
	cout << "Name?"<<endl;
	cin.getline(name, 50);
	cout << "ID?"<<endl;
	cin >> id;
	cin.ignore(100, '\n');
	cout << "GPA?"<<endl;
	cin >> gpa;
	cin.ignore(100, '\n');
}
Student::Student(char * in_name, int in_id, float in_gpa){
	strcpy(name, in_name);//alternate constructor for student for file
	id = in_id;
	gpa = in_gpa;
}
int Student::getid(){
	return id;//get the id
}
float Student::getgpa(){
	return gpa;//get the gpa
}
char* Student::getname(){//get the name
	return name;
}
