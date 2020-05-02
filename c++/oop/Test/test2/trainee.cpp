#include<iostream>
#include<string.h>
#include"trainee.h"
int Trainee::totalTrainees=0;
Trainee::Trainee(void)
{
	id = 0;
	name = NULL;
}
Trainee::Trainee(int _id, char *_name)
{
	id= _id;
 	name = new char[strlen(_name)+1];
	strcpy(name,_name);	
	totalTrainees++;
}
Trainee::~Trainee(void)
{
	if(name !=NULL)
		delete []name;
	totalTrainees --;
}
int Trainee::getID() const
{
	return id;
}
/* int Trainee::getName() const
{
	return name;
} */
int Trainee::getTotalTrainees(){
	return totalTrainees;
}
