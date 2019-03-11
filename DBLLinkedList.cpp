/*
 * LinkedList.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Patrick
 */
#include <iostream>
#include "DBLLINKEDLIST.H"
using namespace std;

//constructor
NumberList::NumberList()
{
	head = nullptr;					//initializing the head to a nullptr
	tail = nullptr;					//initializing the tail to a nullptr
}

NumberList::~NumberList()
{
	deleteList();
}

//Appends node at the start of the list
void NumberList::reAppend(int num)
{
	ListNode *newNode;				//we need a node to point to new node
	ListNode *nodePtr;				//we need a node pointer to make everything happen

	//allocating new space for a new node
	newNode = new ListNode;			//dynamically allocating memory
	newNode->value = num;			//assigning number to the node
	newNode->next = nullptr;		//pointing the end value to null

	if(!head)
	{
		//this is when a list doesn't exist yet
		head = newNode;					//points head at the newly created node
		tail = newNode;					//points tail towards the newly created node

	}
	else
	{
		//this is when there is already a list
		nodePtr = head;					//points the node at the head of the list
		newNode->next = nodePtr;		//attaching newNode to nodePtr
		nodePtr->previous = newNode;	//assigning the previous node to be newNode
		head = newNode;					//pointing head to nodePtr since it is beginning of the list
	}
}

//appends node at the end of the list
void NumberList::appendNode(int num)
{
	ListNode *newNode;
	ListNode *nodePtr;

	newNode = new ListNode;				//dynamically allocating memory
	newNode->value = num;				//assigning number to the newNode
	newNode->next = nullptr;			//pointing newNode at nothing

	if(!head)							//specific circumstance of no list
	{

		head = newNode;					//assigning new node to head
		tail = newNode;					//assigning new node to tail

	}
	else
	{
			nodePtr = tail;					//points the node at the end of the list
			nodePtr->next = newNode;			//pointing nodePtr's next as newNode
			newNode->previous = nodePtr;		//attaching newNode to nodePtr
			tail = newNode;					//positioning tail to new node.
	}
}

//inserts node behind the bigger number
void NumberList::insertNodeInSortedOrder(int num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousPtr = nullptr;

	newNode = new ListNode;					//dynamically allocating a new node
	newNode->value = num;
	newNode->next = nullptr;
	newNode->previous = nullptr;

	if(!head)							//in the case of an empty list
	{
		nodePtr = head;
		nodePtr = newNode;
		head = newNode;
		tail = newNode;
		return;
	}

	if(num <= head->value)
	{
		nodePtr = head;					//pointing nodePtr towards head node
		head = newNode;						//assigning newNode as the head of the list
		newNode->next = nodePtr;		//pointing the next nodes at the same spot
		nodePtr->previous = newNode;		//point node to the new node values
		return;
	}

	nodePtr = head;
	while(nodePtr->next != nullptr)
	{
		previousPtr = nodePtr;			//moving the previousPtr along with nodePtr
		nodePtr = nodePtr->next;		//moving the nodePtr along the array

		if(newNode->value < nodePtr->value)		//general case of moving thru the node looking for insert
		{
			previousPtr->next = newNode;
			nodePtr->previous = newNode;
			newNode->next = nodePtr;
			newNode->previous = previousPtr;
			return;						//terminates function after the conditions executes
		}
	}
	appendNode(newNode->value);
}

//deletes node of that value
void NumberList::deleteNodeOfValue(int searchValue)
{
	ListNode *nodePtr;
	ListNode *previousPtr = nullptr;						//we need to have a node we can use to look back
	ListNode *nextPtr = nullptr;							//we need to have a node we can use to look forward

	if(!head)									//terminating in the case there is nothing in the list
	{
		cout << "there is no list." << endl;
		return;
	}

	if(head->value == searchValue && head->next != nullptr)				//if the search value is at the beginning
	{
		nodePtr = head->next;					//pointing to head's next node
		nodePtr->previous = nullptr;			//pointing node previous to null
		head = nullptr;

		delete head;							//deleting the head

		head = nodePtr;							//reassigning head to the nodePtr

		cout << "\ndone.";

		return;
	}
	else if(head->value == searchValue && head->next == nullptr)		//if head is the only value in the list
	{
		head = nullptr;
		delete head;
		cout << "\ndone.";
		return;
	}

		nodePtr = head;
		while(nodePtr != nullptr && nodePtr->value != searchValue)		//keeps going till end of list or found like value
		{
			//traversing thru the linked list
			nodePtr = nodePtr->next;

			if(nodePtr->value == searchValue && nodePtr->next != nullptr && nodePtr->previous != nullptr)
			{
				//this is the case where we are deleting a value in the middle of the list
				nextPtr = nodePtr->next;				//(nodePtr) --> (nodePtr->next) == (nextPtr)
				previousPtr = nodePtr->previous;		//(previousPtr) == (nodePtr->previous) <-- (nodePtr)

				nextPtr->previous = previousPtr;		//resetting the previous traversal
				previousPtr->next = nextPtr;			//resetting the next traversal

				cout << "\ndone.";

				nodePtr = nullptr;

				//now that we severed the links, we are ready to delete nodePtr
				delete nodePtr;
				return;
			}
			if(nodePtr->value == searchValue && nodePtr->next == nullptr && nodePtr->previous != nullptr)
			{
				//this is the case where we hit the end of an existing list but there's still numbers previous
				nodePtr = tail->previous;				//pointing to tail's previous node
				nodePtr->next = nullptr;				//pointing node previous to null
				tail = nullptr;
				cout << "\ndone.";

				delete tail;							//deleting the tail

				tail = nodePtr;
				return;
			}

		}
}

//deleting the node of a specific location
void NumberList::deleteNodeOfLocation(int location)
{
	ListNode *nodePtr;
	ListNode *previousPtr = nullptr;
	ListNode *nextPtr = nullptr;

	if(!head)
	{
		cout << "there is no list." << endl;
		return;
	}

	if(location > numberOfNodes() || location < 1)		//stops if arguments are out of scope
	{
		cout << "this node doesn't exist";
	}

	if(location == 1 && head->next != nullptr)				//case of the first node
	{
		nodePtr = head->next;					//pointing to head's next node
		nodePtr->previous = nullptr;			//pointing node previous to null
		head = nullptr;							//pointing head to null
		cout << "\ndone.";

		delete head;							//deleting the head

		head = nodePtr;							//reassigning head to the nodePtr

		return;
	}
	else if(location == 1 && head->next == nullptr)			//case of the head being first and last node
	{
		head = nullptr;
		delete head;
		cout << "\ndone.";
		return;
	}

	nodePtr = head;						//setting up nodePtr at the head of the list

	for(int count = 1; count <= location; count++)
	{
		if(location == count && nodePtr->next != nullptr && nodePtr->previous != nullptr)	//in case of middle nodes
		{
			//this is the case where we are deleting a value in the middle of the list
			nextPtr = nodePtr->next;				//(nodePtr) --> (nodePtr->next) == (nextPtr)
			previousPtr = nodePtr->previous;		//(previousPtr) == (nodePtr->previous) <-- (nodePtr)

			nextPtr->previous = previousPtr;		//resetting the previous traversal
			previousPtr->next = nextPtr;			//resetting the next traversal

			nodePtr = nullptr;

			cout << "\ndone.";
			//now that we severed the links, we are ready to delete nodePtr
			delete nodePtr;
			return;

		}
		else if(location == count && nodePtr->next == nullptr && nodePtr->previous != nullptr)
		{
			//this is the case where we hit the end of an existing list but there's still numbers previous
			nodePtr = tail->previous;				//pointing to tail's previous node
			nodePtr->next = nullptr;				//pointing node previous to null
			tail = nullptr;
			cout << "\ndone.";

			delete tail;							//deleting the tail

			tail = nodePtr;
			return;
		}

		//traversing the list
		nodePtr = nodePtr->next;
	}

}

//getting the value of a node at the nodeNum
int NumberList::getNodeValueAtLocation(int nodeNum)
{
	ListNode *nodePtr;

	int count = 1;

	nodePtr = head;						//setting the nodePtr to the start of the list
	//we need to traverse the list if needed.
	while(nodePtr != nullptr && count != nodeNum)
	{
		nodePtr = nodePtr->next;
		count += 1;
	}

	return nodePtr->value;
}

//this will merge the two nodes of positions a and b
void NumberList::mergeTwoNodes(int locA, int locB)
{
	ListNode *nodePtrA;
	ListNode *nodePtrB;
	ListNode *previousPtr = nullptr;
	ListNode *nextPtr = nullptr;

	//to merge we need to move thru by counting the nodes
	int countA = 1;
	int countB = 1;

	nodePtrA = head;					//pointing nodePtrA towards the start of the list
	nodePtrB = head;					//pointing nodePtrB towards the start of the list

	//idea is to merge both A and B, then wipe B
	//so we'll use nextPtr and previousPtr to reset the links after wiping node B
	//using previousPtr to link up to the next node and using nextPtr to link to the previous node

	if(!head)														//failsafe for empty list
	{
		cout << "there is no list" << endl;
		return;
	}

	if(countA > numberOfNodes())			//this is a failsafe
	{
		cout << "location of A is out of scope" << endl;
		return;
	}

	if(countB > numberOfNodes())
	{
		cout << "location of B is out of scope" << endl;
		return;
	}

	while(nodePtrA->next != nullptr && countA != locA)
	{
		nodePtrA = nodePtrA->next;
		countA++;
	}

	while(nodePtrB->next != nullptr && countB != locB)
	{
		nodePtrB = nodePtrB->next;
		countB++;
	}

	nodePtrA->value = nodePtrA->value + nodePtrB->value;		//adding both node values together

	//we need to delete node B after the adding
	//but before we do, we need to reset the pointer's link to each other
	//then we can wipe node B out.

	if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
	{
		previousPtr = nodePtrB->previous;
		nextPtr = nodePtrB->next;
		previousPtr->next = nextPtr;			//going to skip node B to the node after B
		nextPtr->previous = previousPtr;		//going to skip node B to the node before B
		cout << "\ndone";
		return;
	}
	else if(nodePtrB->next == nullptr)			//the case where node B is at the end of the list
	{
		previousPtr = nodePtrB->previous;		//setting the pointer before node B
		previousPtr->next = nullptr;			//pointing the next to else where

		//deleting node B
		nodePtrB = nullptr;
		delete nodePtrB;
		tail = previousPtr;
		cout << "\ndone";
		return;
	}
}

//swap nodes in positions of a and b
void NumberList::swapNodes(int locA, int locB)
{
	ListNode *nextPtr = nullptr;								//the next pointer
	ListNode *previousPtr = nullptr;							//the previous pointer
	ListNode *tempNext = nullptr;								//the temp next pointer
	ListNode *tempPrev = nullptr;								//the temp previous pointer
	ListNode *nodePtrA;								//the node pointer for node A
	ListNode *nodePtrB;								//the node pointer for node B

	int countA = 1;										//need a counter for A
	int countB = 1;										//need a counter for B

	nodePtrA = head;					//pointing nodePtrA at the start of the list
	nodePtrB = head;					//pointing nodePtrB at the start of the list

	if(!head)
	{
		return;
	}

	if(locA > numberOfNodes() || locA < 1)
	{
		cout << "the location of the A node is out of scope";
		return;
	}

	if(locB > numberOfNodes() || locB < 1)
	{
		cout << "the location of the B node is out of scope";
		return;
	}

	while(nodePtrA->next != nullptr && countA != locA)
	{
		nodePtrA = nodePtrA->next;					//moving the nodePtrA in place
		countA++;
	}

	while(nodePtrB->next != nullptr && countB != locB)
	{
		nodePtrB = nodePtrB->next;					//moving the nodePtrB in place
		countB++;
	}

	//we need to consider that numbers can be next to each other
	if((nodePtrB->previous == nodePtrA && nodePtrA->next == nodePtrB)
	|| (nodePtrA->previous == nodePtrB && nodePtrB->next == nodePtrA))
	{

	//once we find node A we assign it to the temp pointers
		if(nodePtrA->previous != nullptr && nodePtrA->next != nullptr)
		{
				//this is the condition where node A is in the middle of the array
				tempNext = nodePtrA->next;
				tempPrev = nodePtrA->previous;

				if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
				{
					//this is the case where node B is in the middle of the array
					//The node swap, while tempPtr = nodePtrA
					//transferring the links from pointer B to A
					previousPtr = nodePtrB->previous;
					nextPtr = nodePtrB->next;
					//the actual swap is being done
					previousPtr->next = nodePtrA;
					nextPtr->previous = nodePtrA;
					nodePtrA->next = nextPtr;
					nodePtrA->previous = nodePtrB;

					//transferring the links from pointer A to B
					tempPrev->next = nodePtrB;
					tempNext->previous = nodePtrB;
					nodePtrB->next = nodePtrA;
					nodePtrB->previous = tempPrev;

					return;

				}
				else if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the head of the list
				{
					nextPtr = nodePtrB->next;

					//swapping from A to B
					nextPtr->previous = nodePtrA;
					nodePtrA->next = nodePtrB;
					nodePtrA->previous = nullptr;
					head = nodePtrA;


					tempPrev->next = nodePtrB;
					tempNext->previous = nodePtrB;
					nodePtrB->next = tempNext;
					nodePtrB->previous = nodePtrA;

					return;
				}
				else if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
				{
					previousPtr = nodePtrB->previous;

					previousPtr->next = nodePtrA;
					nodePtrA->previous = nodePtrB;
					nodePtrA->next = nullptr;
					tail = nodePtrA;

					//transferring the links from pointer A to B
					tempPrev->next = nodePtrB;
					tempNext->previous = nodePtrB;
					nodePtrB->next = nodePtrA;
					nodePtrB->previous = tempPrev;

					return;
				}
		}

		else if(nodePtrA->previous != nullptr && nodePtrA->next == nullptr)
		{
			//this is the case where A are at the end of the list
			tempPrev = nodePtrA->previous;

			if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
			{
				//this is the case where node B is in the middle of the array
				//The node swap, while tempPtr = nodePtrA
				//transferring the links from pointer B to A
				previousPtr = nodePtrB->previous;
				nextPtr = nodePtrB->next;
				//the actual swap is being done
				previousPtr->next = nodePtrA;
				nextPtr->previous = nodePtrA;
				nodePtrA->next = nodePtrB;
				nodePtrA->previous = previousPtr;

				//transferring the links from pointer A to B
				tempPrev->next = nodePtrB;
				nodePtrB->previous = nodePtrA;
				nodePtrB->next = nullptr;
				tail = nodePtrB;

				return;
			}
			else if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the start of the list
			{
				nextPtr = nodePtrB->next;

				nextPtr->previous = nodePtrA;
				nodePtrA->next = nodePtrB;
				nodePtrA->previous = nullptr;
				head = nodePtrA;

				//transferring from pointer A to B
				tempPrev->next = nodePtrB;
				nodePtrB->previous = nodePtrA;
				nodePtrB->next = nullptr;
				tail = nodePtrB;

				return;
			}
		/*		if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
				{
					previousPtr = nodePtrB->previous;

					previousPtr->next = nodePtrA;
					nodePtrA->previous = previousPtr;

					//transferring the links from pointer A to B
					tempPrev->next = nodePtrB;
					nodePtrB->previous = tempPrev;
					tail = nodePtrB;

					return;
				}*/
		}
		else if(nodePtrA->previous == nullptr && nodePtrA->next != nullptr)
		{
			//this is the case where A is at the start of the list
			tempNext = nodePtrA->next;

			if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
			{
				//this is the case where node B is in the middle of the array
				//The node swap, while tempPtr = nodePtrA
				//transferring the links from pointer B to A
				previousPtr = nodePtrB->previous;
				nextPtr = nodePtrB->next;

				//the actual swap is being done
				previousPtr->next = nodePtrA;
				nextPtr->previous = nodePtrA;
				nodePtrA->next = nextPtr;
				nodePtrA->previous = nodePtrB;

				//transferring the links from pointer A to B
				tempNext->previous = nodePtrB;
				nodePtrB->next = nodePtrA;
				nodePtrB->previous = nullptr;
				head = nodePtrB;

				return;
			}
		/*		if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the start of the list
				{
					nextPtr = nodePtrB->next;

					nextPtr->previous = nodePtrA;
					nodePtrA->next = nextPtr;

					//transferring from pointer A to B
					tempNext->previous = nodePtrB;
					nodePtrB->next = tempNext;
					head = nodePtrB;

					return;
				}*/
			else if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
			{
				previousPtr = nodePtrB->previous;

				previousPtr->next = nodePtrA;
				nodePtrA->previous = nodePtrB;
				nodePtrA->next = nullptr;
				tail = nodePtrA;

				//transferring the links from pointer A to B
				tempNext->previous = nodePtrB;
				nodePtrB->next = nodePtrA;
				nodePtrB->previous = nullptr;
				head = nodePtrB;

				return;
			}
		}
	}

	//this is where both nodes are not next to each other
	//once we find node A we assign it to the temp pointers
	else if(nodePtrA->previous != nullptr && nodePtrA->next != nullptr)
	{
		//this is the condition where node A is in the middle of the array
		tempNext = nodePtrA->next;
		tempPrev = nodePtrA->previous;

		if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
		{
			//this is the case where node B is in the middle of the array
			//The node swap, while tempPtr = nodePtrA
			//transferring the links from pointer B to A
			previousPtr = nodePtrB->previous;
			nextPtr = nodePtrB->next;
			//the actual swap is being done
			previousPtr->next = nodePtrA;
			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;
			nodePtrA->previous = previousPtr;

			//transferring the links from pointer A to B
			tempPrev->next = nodePtrB;
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			nodePtrB->previous = tempPrev;

			return;

		}
		else if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the head of the list
		{
			nextPtr = nodePtrB->next;

			//swapping from A to B
			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;
			nodePtrA->previous = nullptr;
			head = nodePtrA;


			tempPrev->next = nodePtrB;
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			nodePtrB->previous = tempPrev;

			return;
		}
		else if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
		{
			previousPtr = nodePtrB->previous;

			previousPtr->next = nodePtrA;
			nodePtrA->previous = previousPtr;
			nodePtrA->next = nullptr;
			tail = nodePtrA;

			//transferring the links from pointer A to B
			tempPrev->next = nodePtrB;
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			nodePtrB->previous = tempPrev;

			return;
		}
	}

	else if(nodePtrA->previous != nullptr && nodePtrA->next == nullptr)
	{
		//this is the case where A are at the end of the list
		tempPrev = nodePtrA->previous;

		if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
		{
			//this is the case where node B is in the middle of the array
			//The node swap, while tempPtr = nodePtrA
			//transferring the links from pointer B to A
			previousPtr = nodePtrB->previous;
			nextPtr = nodePtrB->next;
			//the actual swap is being done
			previousPtr->next = nodePtrA;
			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;
			nodePtrA->previous = previousPtr;

			//transferring the links from pointer A to B
			tempPrev->next = nodePtrB;
			nodePtrB->previous = tempPrev;
			nodePtrB->next = nullptr;
			tail = nodePtrB;

			return;
		}
		else if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the start of the list
		{
			nextPtr = nodePtrB->next;

			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;
			nodePtrA->previous = nullptr;
			head = nodePtrA;

			//transferring from pointer A to B
			tempPrev->next = nodePtrB;
			nodePtrB->previous = tempPrev;
			nodePtrB->next = nullptr;
			tail = nodePtrB;

			return;
		}
/*		if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
		{
			previousPtr = nodePtrB->previous;

			previousPtr->next = nodePtrA;
			nodePtrA->previous = previousPtr;

			//transferring the links from pointer A to B
			tempPrev->next = nodePtrB;
			nodePtrB->previous = tempPrev;
			tail = nodePtrB;

			return;
		}*/
	}

	else if(nodePtrA->previous == nullptr && nodePtrA->next != nullptr)
	{
		//this is the case where A is at the start of the list
		tempNext = nodePtrA->next;

		if(nodePtrB->previous != nullptr && nodePtrB->next != nullptr)
		{
			//this is the case where node B is in the middle of the array
			//The node swap, while tempPtr = nodePtrA
			//transferring the links from pointer B to A
			previousPtr = nodePtrB->previous;
			nextPtr = nodePtrB->next;

			//the actual swap is being done
			previousPtr->next = nodePtrA;
			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;
			nodePtrA->previous = previousPtr;

			//transferring the links from pointer A to B
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			nodePtrB->previous = nullptr;
			head = nodePtrB;

			return;
		}
/*		if(nodePtrB->previous == nullptr && nodePtrB->next != nullptr)		//if node B is at the start of the list
		{
			nextPtr = nodePtrB->next;

			nextPtr->previous = nodePtrA;
			nodePtrA->next = nextPtr;

			//transferring from pointer A to B
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			head = nodePtrB;

			return;
		}*/
		else if(nodePtrB->previous != nullptr && nodePtrB->next == nullptr)			//if node B is at the end of the list
		{
			previousPtr = nodePtrB->previous;

			previousPtr->next = nodePtrA;
			nodePtrA->previous = previousPtr;
			nodePtrA->next = nullptr;
			tail = nodePtrA;

			//transferring the links from pointer A to B
			tempNext->previous = nodePtrB;
			nodePtrB->next = tempNext;
			nodePtrB->previous = nullptr;
			head = nodePtrB;

			return;
		}
	}
}

//this function will delete all the nodes in the list
void NumberList::deleteList()
{
	ListNode *nodePtr;
	ListNode *nextPtr;

	if(!head)
	{
		return;
	}

	nodePtr = head;									//setting nodePtr to start of the list
	while(nodePtr != nullptr)
	{

		nextPtr = nodePtr->next;
		nodePtr = nullptr;
		delete nodePtr;
		nodePtr = nextPtr;

	}
	head = nullptr;
}

//this function will count the number of nodes that exist
int NumberList::numberOfNodes()
{
	int count = 1;
	ListNode *nodePtr;

	if(!head)
	{
		return 0;
	}
	nodePtr = head;
	while(nodePtr->next != nullptr)		//will move thru list if it isn't the end of the list
	{
		nodePtr = nodePtr->next;
		count++;
	}

	return count;
}

void NumberList::removeAllDuplicates()
{
	ListNode *nodePtr;
	ListNode *compPtr;
	nodePtr = head;								//initializing nodePtr to start of the list
	compPtr = nodePtr->next;

	if(!head)
		return;

	//first time thru the list
	while(compPtr != nullptr)
	{
		if(nodePtr->value == compPtr->value)
		{
			deleteNodeOfValue(nodePtr->value);
		}
		compPtr = compPtr->next;
	}

	nodePtr = head->next;
	compPtr = head;

	//second time where we have to skip values since compPtr might overlap with nodePtr
	while(nodePtr != nullptr)
	{
		while(compPtr != nullptr)
		{
			if(nodePtr->next == nullptr && nodePtr->previous == compPtr)
				return;
			if(nodePtr == compPtr)
				compPtr = compPtr->next;
			if(nodePtr->value == compPtr->value)
			{
				deleteNodeOfValue(nodePtr->value);
			}
			compPtr = compPtr->next;
		}
		nodePtr = nodePtr->next;
	}
}
void NumberList::displayList() const
{
	ListNode *nodePtr;

	cout << "displaying from beginning to end:" << endl;
	nodePtr = head;									//pointing nodePtr at the start
	if(!head)
	{
		cout << "\nthe list is empty." << endl;
		return;
	}

	while(nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}

	cout << "\n\ndisplaying from the end and back:" << endl;
	nodePtr = tail;									//pointing nodePtr at the end
	while(nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->previous;
	}

}

void NumberList::menu()
{
	bool finish = false;
	int choice;
	int input;

		while(finish == false)
		{
			cout << "\n1. reappend node.";
			cout << "\n2. append node.";
			cout << "\n3. insert node in sorted order.";
			cout << "\n4. delete node of a specific value.";
			cout << "\n5. delete value at a specific location.";
			cout << "\n6. get node at a specific location.";
			cout << "\n7. merge two nodes together.";
			cout << "\n8. swap two nodes.";
			cout << "\n9. get the count of nodes in the list.";
			cout << "\n10. remove nodes with duplicate values.";
			cout << "\n11. delete the whole list.";
			cout << "\n12. display all nodes.";
			cout << "\n13. exit.";
			cout << "\nWhat would you like to do? ";
			cin >> choice;

			if(choice == 1)
			{
				//this will append a node at the start of the list
				cout << "\nwhat value would you like to append to the start? ";
				cin >> input;
				reAppend(input);
			}
			else if(choice == 2)
			{
				//this will append a node at the end of the list
				cout << "\nwhat value would you like to append at the end of the list? ";
				cin >> input;
				appendNode(input);
			}
			else if(choice == 3)
			{
				//this will insert a node in sorted order
				cout << "\nwhat value would you like to insert into the node? ";
				cin >> input;
				insertNodeInSortedOrder(input);
			}
			else if(choice == 4)
			{
				//this will delete a node of specific value
				cout << "\nwhat value would you like to delete from the list? ";
				cin >> input;
				cout << "\ndeleting...";
				deleteNodeOfValue(input);
			}
			else if(choice == 5)
			{
				//this will delete a node at a specific location
				cout << "\nwhich node would you like to delete (1-" << numberOfNodes() << ")? ";
				cin >> input;
				deleteNodeOfLocation(input);
			}
			else if(choice == 6)
			{
				//this will get node at a specific location
				cout << "\nwhich node would you like to see? ";
				cin >> input;
				cout << "\nthe " << input << " node contains the value: ";
				cout << getNodeValueAtLocation(input);
				cout << "\n";
			}
			else if(choice == 7)
			{
				int locA = 0;
				int locB = 0;
				//this will merge two nodes by adding nodes a and b and deleting b

					cout << "\nthis will merge two nodes of specific location (1-" << numberOfNodes() << "): " << endl;
					cout << "which is the location A of the node you'd like to merge into? ";
					cin >> locA;
					cout << "\nwhich is the location B of the node you'd like to add into A? ";
					cin >> locB;

				mergeTwoNodes(locA, locB);
			}
			else if(choice == 8)
			{
				int locA = 0;
				int locB = 0;
				//this will swap the nodes of 2 locations

					cout << "\nthis will swap two nodes of the specified location(1-" << numberOfNodes() << "): " << endl;
					cout << "which is the location A of the node you'd like to swap? ";
					cin >> locA;
					cout << "which is the location B of the node you'd like to swap? ";
					cin >> locB;

				swapNodes(locA, locB);
			}
			else if(choice == 9)
			{
				//this will return the number of nodes in the list
				cout << "the list has this many nodes:";
				cout << numberOfNodes();
			}

			else if(choice == 10)
			{
				//this will remove duplicate values that exist in the node
				cout << "removing duplicates...";
				removeAllDuplicates();
			}
			else if(choice == 11)
			{
				//this will delete the whole list
				cout << "\ndeleting the list.";
				deleteList();
				cout << "\ndone";
			}
			else if(choice == 12)
			{
				//this will display the whole list
				cout << "displaying the numbers in the list:" << endl;
				displayList();
				cout << "\ndone";
			}
			else if(choice == 13)
			{
				//this will end the program
				cout << "\nbye." << endl;
				finish = true;
			}
			else
				cout << "that's an invalid choice";

		}
}
