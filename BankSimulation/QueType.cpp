/* QueType.cpp
Author:  Chris Callahan
Submission  Date:  2/10/2017
Purpose: This program is an array implementation of a circular queue ADT class.
Statement  of Academic  Honesty:The  following  code  represents  my  own  work.  I  have  neitherreceived  nor  given  inappropriate assistance. I have not copiedor  modified code from any source other than the course webpageor the course textbook. I recognize that any unauthorizedassistance or plagiarism will be handled in accordance  withthe  University  of  Georgia's  Academic  Honesty  Policy  and  thepolicies  of  this course.  I  recognize  that  my  work  is  basedon  an  assignment  created  by  the  Department  of ComputerScience at the University of Georgia. Any publishingor posting of source code for this project  is strictlyprohibited  unless  you  have written consent  from  the  Departmentof Computer Science  at the  University  of  Georgia.
*/

#include<iostream>
#include<string>
#include "QueType.h"

	
template<class ItemType> 
QueType<ItemType>::QueType()
{
  items = new ItemType[500];
  front = -1;
  rear = -1;
  maxQue = 500;
} // QueType constructor

template<class ItemType>
QueType<ItemType>::QueType(int max)
{
  items = new ItemType[max];
  front = -1;
  rear = -1;
  maxQue = max;
} // QueType constructor

template<class ItemType>
QueType<ItemType>::~QueType()
{
  delete [] items;
} // ~QueType

template<class ItemType> 
void QueType<ItemType>::MakeEmpty()
{
  front = -1;
  rear = -1;	
} // MakeEmpty

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const 
{
  if((front == -1) && (rear == -1)) return true;
  return false;	
} // IsEmpty

template<class ItemType>
bool QueType<ItemType>::IsFull() const
{
  if((rear == maxQue-1 && front == 0) || (front == rear+1)) return true;
  return false;
} // IsFull

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
  if(this->IsFull())
    {
      throw FullQueue();
    }
  else 
    {
      if((rear == maxQue-1) && (front != 0)) /* check if at the end of circle */
	rear = -1;
      
      rear++;
      items[rear] = newItem;
      if(front == -1) front = 0; 
    }
} // Enqueue

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
  if(this->IsEmpty())
    {
      throw EmptyQueue();
    }
  else
    {
      item = items[front];
      front++;
      if(front == maxQue) front = 0; /* check if end of circle is reached */
      
      if(front-1 == rear) /* check if dequeue made the queue empty */
	{
	  rear = -1;
	  front = -1;
	}
    }
} // Dequeue

template<class ItemType>
int QueType<ItemType>::length()
{
  if(this->IsEmpty()) return 0;
  else if(front > rear) return ((maxQue - front) + (rear+1));
  return (1 + (rear - front));
} // length
