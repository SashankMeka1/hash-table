#include "Node.h"
#include <cstdio>
class hash_table{
	private:
	Node **main_arr;
	char name[75];
	char last[20];
	int * freq_arr;
	int size;
	int inc_id;
	float gpa;
	FILE *in_first = fopen("first_names.txt", "r");
	FILE *in_last = fopen("surnames.txt", "r");
	public:
	hash_table(int in_size);
	void rebuild(Node ** new_table, Node * itr);
	~hash_table();
	void add(Node * itr, Node * node);
	void del(Node * itr, int id);
	void print();
	void addFile();
};
