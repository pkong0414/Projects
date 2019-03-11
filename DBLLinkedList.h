/*
 * LinkedList.h
 *
 *  Created on: Nov 4, 2016
 *      Author: Patrick
 */

#ifndef DBLLINKEDLIST_H_
#define DBLLINKEDLIST_H_

class NumberList
{
	private:
		struct ListNode
		{
			int value;
			struct ListNode *next;
			struct ListNode *previous;
		};

	public:

		ListNode *head;
		ListNode *tail;

		//constructor
		NumberList();

		//destructor
		~NumberList();

		void reAppend(int);						//puts a new node at the start of the list
		void appendNode(int);					//puts a new node at the end of the list
		void insertNodeInSortedOrder(int);		//puts the node behind the bigger number
		void deleteNodeOfValue(int);			//delete the specific node of that value
		void deleteNodeOfLocation(int);			//delete the specific node of that location
		int getNodeValueAtLocation(int);		//returns the value of the node at the specified location
		void mergeTwoNodes(int, int);			//appends the a and b nodes together, then deletes the b node
		void swapNodes(int, int);				//swaps the values of two nodes
		void deleteList();						//deletes the entire list
		int numberOfNodes();					//counts the number of nodes in the list
		void removeAllDuplicates();				//looks at the nodes and removes any duplicate nodes
		void displayList() const;				//displays the whole node in a list
		void menu();
};



#endif /* LINKEDLIST_H_ */
