#include "Node.h"
#include <cstdio>
class hash_table{
	private:
	Node **main_arr;
	char name[75];
	char last[20];//files and arrays
	int size;
	int inc_id;
	float gpa;//functions and variables
	FILE *in_first = fopen("first_names.txt", "r");
	FILE *in_last = fopen("surnames.txt", "r");
	public:
	hash_table(int in_size);//get table and define functions
	void rebuild(Node ** new_table, Node * itr);
	~hash_table();
	void add(Node * itr, Node * node);
	void del(Node * itr, int id);
	void print();
	void addFile();
};
