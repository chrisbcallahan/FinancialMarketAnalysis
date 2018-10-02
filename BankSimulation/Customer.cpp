/*Customer.cpp
Author:  Chris Callahan
Submission  Date:  3/19/2017
Purpose:  This is the implementation of the customer class. 
Statement  of Academic  Honesty:The  following  code  represents  my  own  work.  I  have  neitherreceived  nor  given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.*/
#include "Customer.h"
#include "string"

using namespace std;

Customer::Customer()
{

}

Customer::Customer(string name, int arrival, int service) 
{
  this -> name = name;
  this -> arrival = arrival;
  this -> service = service;
}

string Customer::getName()
//funct: returns name of customer
//pre: customer is initialized
//post: name is returned
{
  return this->name;
}

int Customer::getArrival()
//funct: returns arrival time
//pre: customer is initialzed
//post: arrival time is retured
{
  return this->arrival;
}

int Customer::getService()
//funct: returns service time
//pre: customer is initialized
//post: service time is returned
{
  return this->service;
}

int Customer::getWait()
//funct: returns wait time
//pre: customer is initialized
//post: wait is returned
{
  return this -> wait;
}

void Customer::setName(string name)
//funct: sets the customer
//pre: customer is initialized
//post: name is set
{
  this -> name = name;
}
void Customer::setWait(int wait)
//funct: sets the wait time
//pre: customer is initialized
//post: wait time is set
{
  this -> wait = wait;
}
void Customer::setArrival(int arrival)
//funct: sets the arrival time
//pre: customer is initialized
//post: arrival time is set
{
  this -> arrival = arrival;
}

void Customer::setService(int service)
//funct: sets the service time
//pre: customer is initialized
//post: service time is set
{
  this -> service = service;
}

void Customer::printCustomer()
//funct: prints the customer info
//pre: custome is initialized
//post: info is printed
{
  cout << this -> getName() << endl;
  cout << this -> getArrival() << endl;
  cout << this -> getService() << endl;
}
