class Student{
	private:
		int id;
		float gpa;
		char name[150];
	public:
		Student();
		Student(char * in_name, int in_id, float in_gpa);
		int getid();
		float getgpa();
		char* getname();

};
