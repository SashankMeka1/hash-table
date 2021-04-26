#include "hash_table.h"
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
hash_table::hash_table(int in_size){//define array and size
	main_arr = new Node*[in_size];
	size = in_size;
}
void hash_table::addFile(){
	int student_num;//add a file and read in the students from the file
	cout << "How many students?";
	cin >> student_num;
	cin.ignore(100,'\n');
	srand(time(NULL));
	inc_id = 0;
	if(in_first and in_last){
		while(fgets(name, 75, in_first) and fgets(last, 20, in_last)){
			name[strcspn(name,"\n")] = '\0';
			last[strcspn(last,"\n")] = '\0';//randomly get names
			if(inc_id < student_num and rand()%3){
				if(strlen(last) > 2){
			     		strcat(name, " ");
					strcat(name, last);
					gpa = (float)(rand()%101)/(float)25;
					add(nullptr, new Node(new Student(name, inc_id, gpa)));
					inc_id++;
				}
			}
			else if(inc_id >= student_num){
				return;
			}
		}
	}
	fclose(in_first);
	fclose(in_last);
	in_first = fopen("first_names.txt", "r");
	in_last = fopen("surnames.txt", "r");
}
hash_table::~hash_table(){//delete the linked list and array destructors delete theier objects
	for(int i = 0; i < size; i++){
		if(main_arr[i]){
			delete main_arr[i];
		}
	}
	delete main_arr;//close files
	if(in_first){
		fclose(in_first);
	}
	if(in_last){
		fclose(in_last);
	}
}
void hash_table::add(Node * itr, Node * node){//add and check if too many collisions if so resize
	int idx = node->getStudent()->getid()%size;
	itr = main_arr[idx];
	int freq = 1;//frequency to check collisions
	if(itr){
		freq++;
		while(itr->getNext()){
			freq++;
			itr = itr->getNext();
		}
		itr->setNext(node);
	}
	else{
		main_arr[idx] = node;
	}
	if (freq == 3){
		rebuild(nullptr, nullptr);
	}
}
void hash_table::del(Node * itr, int id){//delete node
	int idx = id%size;
	itr = main_arr[idx];
	if(itr){
		if(itr->getStudent()->getid() == id){
			main_arr[idx] = itr->getNext();
			itr->setNext(nullptr);
			delete itr;
		}
		else{
			while(itr->getNext()){
				if(itr->getNext()->getStudent()->getid() == id){
					Node * to_delete = itr->getNext();
					itr->setNext(itr->getNext()->getNext());
					to_delete->setNext(nullptr);
					delete to_delete;
				}
			}
		}
	}
}
void hash_table::print(){//print
	for(int i = 0; i < size; i++){
		if(main_arr[i]){
			main_arr[i]->print();
		}
	}
}
void hash_table::rebuild(Node ** old_arr, Node * itr){
	size = size*2;//rebuild the entire hash table by swapping new and old array pointers
	old_arr = new Node*[size *2];
	Node ** temp;
	temp = old_arr;
	old_arr = main_arr;
	main_arr = temp;
	temp = nullptr;
	for(int i = 0; i < size/2; i++){
		if(old_arr[i]){
			itr = old_arr[i];
			add(nullptr, itr);
		}
	}
	delete old_arr;
}
