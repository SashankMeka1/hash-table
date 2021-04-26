#include "hash_table.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	char input[150];
	hash_table * table = new hash_table(100);//get input and just run the functions
	while (true){
		cout << "ADD, DELETE, QUIT, FILE, OR PRINT"<<endl;
		cin.getline(input, 150);
		if(!strcmp(input, "ADD")){
			table->add(nullptr, new Node(new Student()));
		}
		else if(!strcmp(input, "FILE")){
			table->addFile();
		}
		else if(!strcmp(input, "PRINT")){
			table->print();
		}
		else if(!strcmp(input, "QUIT")){
			delete table;
			return 0;
		}
		else if(!strcmp(input, "DELETE")){
			cout << "ID?"<<endl;//if delete then get the input and delete the node
			cin >> input;
			cin.ignore(100, '\n');
			table->del(nullptr, atoi(input));
		}

	}
	return 0;
}
