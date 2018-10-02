/*BankSimulation.cpp
Author: Chris Callahan
Submission  Date:  3/19/2017
Purpose:  This program simulates a bank with a limited number of tellers. When a teller is free, a customer who is in the waiting queue is helped by the open teller. 
Statement  of Academic  Honesty:The  following  code  represents  my  own  work.  I  have  neitherreceived  nor  given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.*/
#include <iostream>
#include <fstream>
#include <string>

#include "QueType.cpp"
#include "PriorityQueue.cpp"
#include "Customer.cpp"

using namespace std;

int main()
{
  ifstream input;
  string currentLine;
  int numTellers;
  input.open("input.txt");
  if(!input)
  {
    cout << "error opening input.txt file" << endl;
    return 1;
  }

  /* 
   * Find the number of tellers 
   */
  size_t pos;
  getline(input, currentLine);
  pos = currentLine.find(" ");
  string s = currentLine.substr(pos+1);
  numTellers = stoi(s);
  
  QueType<Customer> arrivalQueue(500);
  QueType<Customer> waitQueue(500);
  PriorityQueue<Customer> tellerQueue;
  
  while(getline(input, currentLine))
  {
    
    
    /*
     * Parse the current line of data and create a Customer object
     */
    string name;
    int arrival;
    int service;
    // size_t/string variables are used to parse the current line of data
    size_t pos1; 
    size_t pos2;
    size_t pos3;
    string arrivalString;

    // parse name
    pos1 = currentLine.find(" ");
    name = currentLine.substr(0, pos1);
     
    // parse arrival
    pos2 = currentLine.find("service");
    int x = currentLine.length() - pos2; 
    arrivalString = currentLine.substr(pos1+1, x);
    pos3 = arrivalString.find(" ");
    arrival = stoi(arrivalString.substr(pos3));
    
    // parse service
    pos3 = currentLine.find_last_of(" ");
    service = stoi(currentLine.substr(pos3));
        
    //create customer object and add it to arrival queue
    Customer * c = new Customer(name, arrival, service);
    arrivalQueue.Enqueue(*c);
    
    if(tellerQueue.size() < numTellers) //if tellers are open
      {
	tellerQueue.enqueue(*c, (c -> getArrival()) + (c -> getService()));
        c -> setWait(0);
      }
    else if(tellerQueue.peekPriority() <= (c -> getArrival())) //a customer has finished.
      {
        int time = tellerQueue.peekPriority(); // time teller opened
        Customer finishedCustomer = tellerQueue.dequeue();
        cout << finishedCustomer.getName() << " wait " << finishedCustomer.getWait() << " service " << (finishedCustomer.getWait() + finishedCustomer.getService() + finishedCustomer.getArrival()) << endl;
	if(waitQueue.IsEmpty()) //no wait
	  {
	    c -> setWait(0);
	    tellerQueue.enqueue(*c, (c -> getArrival()) + (c -> getService()));
	  }
        else //customers already waiting in line
	  {
	    Customer temp;
	    waitQueue.Dequeue(temp);
	    tellerQueue.enqueue(temp, (time + temp.getService()));
	    c -> setWait(tellerQueue.peekPriority() - (c -> getArrival()));
	    waitQueue.Enqueue(*c);
	    
	  }
      }
    else // tellers full and no tellers are finished
      {
	c -> setWait(tellerQueue.peekPriority() - (c -> getArrival())); 
	waitQueue.Enqueue(*c);
      }
  }
  
  // all possible customers have entered and are being helped/waiting in line
  while(!tellerQueue.isEmpty()) 
    {
      Customer fCustomer = tellerQueue.dequeue();
      Customer temp2;
      if(!waitQueue.IsEmpty())
	{
	  waitQueue.Dequeue(temp2);
	  tellerQueue.enqueue(temp2, temp2.getArrival() + temp2.getService()); 
	}
      cout << fCustomer.getName() << " wait " << fCustomer.getWait() << " service " << (fCustomer.getWait() + fCustomer.getService() + fCustomer.getArrival()) << endl;
    }			      
	

} // main  

