#pragma once
class Trainee{
	private:
		int id;
		char *name;
		static int totalTrainees;
	public:
		int getID() const;
		char *getName() const;
		void setID(int _id);
		void setName(char *_name);
		Trainee(void);
		Trainee( int _n, char * name);
		~Trainee(void);
		static int getTotalTrainees();
};
