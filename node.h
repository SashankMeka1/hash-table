#include "student.h"
class Node{
	public:
	void print();
	Node(Student *in_student);
	~Node();
	Node* getNext();
	Student* getStudent();
	void setNext(Node * node);
	private:
	Node * next;
	Student *student;
};
