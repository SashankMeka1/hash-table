#include "hash_table.h"
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
hash_table::hash_table(int in_size){
	main_arr = new Node*[in_size];
	freq_arr = new int[in_size];
	size = in_size;
}
void hash_table::addFile(){
	int student_num;
	cout << "How many students?";
	cin >> student_num;
	cin.ignore(100,'\n');
	srand(time(NULL));
	inc_id = 0;
	if(in_first and in_last){
		while(fgets(name, 75, in_first) and fgets(last, 20, in_last)){
			name[strcspn(name,"\n")] = '\0';
			last[strcspn(last,"\n")] = '\0';
			if(inc_id < student_num){
				if(strlen(last) > 2){
			     		strcat(name, " ");
					strcat(name, last);
					gpa = (float)(rand()%101)/(float)25;
					add(nullptr, new Node(new Student(name, inc_id, gpa)));
					inc_id++;
				}
			}
			else{
				return;
			}
		}
	}
	fclose(in_first);
	fclose(in_last);
	in_first = fopen("first_names.txt", "r");
	in_last = fopen("surnames.txt", "r");
}
hash_table::~hash_table(){
	for(int i = 0; i < size; i++){
		if(main_arr[i]){
			delete main_arr[i];
		}
	}
	delete main_arr;
	delete freq_arr;
	if(in_first){
		fclose(in_first);
	}
	if(in_last){
		fclose(in_last);
	}
}
void hash_table::add(Node * itr, Node * node){
	int idx = node->getStudent()->getid()%size;
	itr = main_arr[idx];
	freq_arr[idx]++;
	if(itr){
		while(itr->getNext()){
			itr = itr->getNext();
		}
		itr->setNext(node);
	}
	else{
		main_arr[idx] = node;
	}
	if (freq_arr[idx] == 3){
		rebuild(nullptr, nullptr);
	}
}
void hash_table::del(Node * itr, int id){
	int idx = id%size;
	itr = main_arr[idx];
	freq_arr[idx]--;
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
void hash_table::print(){
	for(int i = 0; i < size; i++){
		if(main_arr[i]){
			main_arr[i]->print();
		}
	}
}
void hash_table::rebuild(Node ** old_arr, Node * itr){
	size = size*2;
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
