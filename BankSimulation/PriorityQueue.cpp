/*
PriorityQueue.cpp
Author: Chris Callahan
Submission Date: 3/2/2017
Purpose: This is the single linear linked list implementation of the PriorityQueue class. It contains the 
functions of a Priority Queue, which is a Queue that orders its contents based on the priority number
associated with each item. The lowest numbers have highest priority.  
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate
assistance. I have not copied or modified code from any source other than the course webpage or
the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in
accordance with the University of Georgia's Academic Honesty Policy and the policies of this
course. I recognize that my work is based on an assignment created by the Department of
Computer Science at the University of Georgia. Any publishing or posting of source code for this
project is strictly prohibited unless you have written consent from the Department of Computer
Science at the University of Georgia.
*/

#include "PriorityQueue.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<class ItemType>
struct QueueNode
{
  ItemType info;
  int priority;
  QueueNode<ItemType> * next;
};

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
//Function: constructor
{
  frontPtr = nullptr;
  length = 0;
}

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType item)
//Function: Adds an item to queue with default priority (1)
//Pre: queue has been initialized.
//Post: item added to queue in correct order of importance
{
  QueueNode<ItemType> * newNode;
  newNode = new QueueNode<ItemType>;
  newNode -> priority = 1;
  newNode -> info = item;
  if(frontPtr == nullptr) //This is the first node added to the queue
    { 
      frontPtr = newNode;
      newNode -> next = nullptr;
      length++;
    }
  else //This is NOT the first node added to the queue 
    {
      QueueNode<ItemType> * current = frontPtr;
      while(current -> next != nullptr && current -> next -> priority <= 1)
	{
	  current = current -> next;
	}
      if(current -> next == nullptr) { // Adding to the end of the queue (or only on item is in queue)
	if(current -> priority > 1) {
	  newNode -> next = current;
	  frontPtr = newNode;
	}
	else {
	  current -> next = newNode;
	  newNode -> next = nullptr;
	}
      }
      else if(current -> priority > 1) { // Adding to the front of the queue
	newNode -> next = current;
	frontPtr = newNode;
      }
      else { // Adding to the middle of the queue
	QueueNode<ItemType> * temp = new QueueNode<ItemType>;
	temp = current -> next;
	current -> next = newNode;
	newNode -> next = temp;
      }
      length++;
    }
}

template<class ItemType>
void PriorityQueue<ItemType>::enqueue(ItemType item, int priority)
//Function: Adds an item to queue with correct priority
//Pre: queue has been initialized.
//Post: item added to queue in correct order of importance
{
  QueueNode<ItemType> * newNode;
  newNode = new QueueNode<ItemType>;
  newNode -> priority = priority;
  newNode -> info = item;
  if(frontPtr == nullptr) //This is the first node added to the queue
    {
      frontPtr = newNode;
      newNode -> next = nullptr;
      length++;
    }
  else // This is NOT the first node added to the queue
    {
      QueueNode<ItemType> * current = frontPtr;
      while(current -> next != nullptr && current -> next -> priority <= priority)
	{
	  current = current -> next;
	}
      if(current -> next == nullptr) { // Adding to the end of the queue (or only one item is in queue)
	if(current -> priority > priority) {
	  newNode -> next = current;
	  frontPtr = newNode;
	}
	else{
	  current -> next = newNode;
	  newNode -> next = nullptr;
	}
      }
      else if(current -> priority > priority) { // Add to front of queue
	newNode -> next = current;
	frontPtr = newNode;
      }
      else { // Adding to the middle of the queue
	QueueNode<ItemType> * temp = new QueueNode<ItemType>;
	temp = current -> next;
	current -> next = newNode;
	newNode -> next = temp;
      }
	
      length++;
    }
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::dequeue()
//Function: Removes the first item of the list and returns it
//Pre: queue is initialized. queue is not empty.
//Post: Item is removed and returned to caller.
{
  ItemType item = frontPtr -> info;
  if(frontPtr -> next == nullptr) // this is the last item in queue
    frontPtr = nullptr;
  else 
    frontPtr = frontPtr -> next;
  length--;
  return item;
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek()
//Function: returns the item of most importance
//Pre: queue is initialized. queue is not empty.
//Post: returns the item of most importane w/o removing
{
  return frontPtr -> info;
}

template<class ItemType>
int PriorityQueue<ItemType>::peekPriority()
//Function: returns the highest number of importance
//Pre: queue is initialized. queue is not empty.
//Post: returns the highest number of importance i.e. lowest priority value
{
  return frontPtr -> priority;
}

template<class ItemType>
void PriorityQueue<ItemType>::makeEmpty()
//Function: makes the Queue empty
//Pre: Queue is initialized.
//Post: Removes all items from queue.
{
  frontPtr = nullptr;
  length = 0;
}

template<class ItemType>
int PriorityQueue<ItemType>::size()
//Function: returns the number if items in queue
//Pre: queue is initialized
//Post: number of items in queue is returned
{
  return length;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty()
//Function: is queue empty?
//Pre: queue is initialized.
//Post: returns true if empty, false if not.
{
  return (length == 0);
}

template<class ItemType>
bool PriorityQueue<ItemType>::isFull()
//Function: is queue full?
//Pre: queue is initialized.
//Post: returns true if full, false if not.
{
  return (length > 0);
}

template<class ItemType>
void PriorityQueue<ItemType>::printQueue()
//Function: Prints contents of Queue
//Pre: queue is initialized
//post: Prints contents of queue from front to rear.
{
  cout << "Queue: ";
  QueueNode<ItemType> * current = frontPtr;
  
  while(current != nullptr)
    {
      cout << current -> info << " ";
      current = current -> next;
    }
  cout << endl;
}
