```
///////////////////////////////////////////////////////////////////////////////
//                   YOU MUST COMPLETE AND COMMENT YOUR CODE!
// Title:            priorityqueue
// Files:            input_data.txt
// Semester:         (course) Spring 2018
//
// Author:           (your name)
// Email:            (your email address)
// Description:
//       describe program here thoroughly
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
* Struct Node:
*      Node for parameters in our queue
*
* Params:
*      [string] val		: holds our words
*	   [Node] next		: holds pointer for next spot in queue
*
*/

struct Node
{
	string val;
	Node *next;
	Node()
	{
		val = " ";
		next = NULL;
	}
	Node(string v)
	{
		val = v;
		next = NULL;
	}
};

/*
* class Queue
*     description of what this class does ...
* Methods:
*  - Queue()       : constructor
*  - string pop()  :
*/
class Queue
{
private:
	Node *Front;
	Node *Rear;

public:
	/**
	* Queue
	* constructor
	*
	* params:
	*     - none
	*/
	Queue()
	{
		Front = Rear = NULL;
	}

	/**
	* pop
	*/
	string pop()
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			return v;
		}
		else
		{
			return "error: cannot pop off empty queue.";
		}
	}
	/**
	* Function Push:
	*      Pushes an item onto the stack.
	*
	* Params:
	*      [string] v - value of item being pushed
	* Returns
	*      void
	*/

	void push(string v)
	{
		Node *n = new Node(v);

		// handle the empty case
		if (empty())
		{
			Front = n;
			Rear = n;
		}
		else
		{
			// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
	}

	bool empty() // boolean used to show whether queue is empty or not
	{
		return (Front == NULL);
	}

	/**
	* Function print:
	*      Prints queue
	*
	* Params:
	*      [ofstream] outfile - file to where it is printed
	* Returns
	*      void
	*/

	void print(ofstream &outfile)
	{
		Node *temp = Front;
		while (temp)
		{
			outfile << temp->val << '\n';
			temp = temp->next;
		}
		outfile << endl;
	}

	bool pop(string &v)
	{
		if (!empty())
		{
			Node *temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;          // give mem back to system
			v = t;
			return true;
		}
		else
		{
			cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}

	/**
	* Function sortSL:
	*      Sorts the queue from shortest to longest
	*
	* Params:
	*      none
	* Returns
	*      void
	*/

	void sortSL()
	{
		Node* t1 = Front;
		Node* t2 = Front;		// hold values to check against eachother

		string temp = "";		// holds string if need to switch

		bool swapped = false;   // checks if two values were swapped

		while (t1)
		{
			swapped = false;
			t2 = t1->next;
			while (t2)
			{	// if t2 is shorter than t1 then the values are switched
				if (t1->val.length() > t2->val.length())
				{
					swapped = true;
					temp = t1->val;
					t1->val = t2->val;
					t2->val = temp;
				}
				t2 = t2->next;
			}
			t1 = t1->next;
		}
		if (swapped) { return; }
	}
	void sortAB()
	{
		Node* t1 = Front;
		Node* t2 = Front;		// holds values to check against eachother

		string temp = "";		// holds string if need to switch

		bool swapped = false;   // checks if two values were swapped

		while (t1)
		{
			swapped = false;
			t2 = t1->next;
			while (t2)
			{   // if t2 is of equal length, then the first letters are checked
				if (t1->val.length() == t2->val.length())
				{	// increments i until it's the size of the word and sorts alphabetically
					for (int i = 0; i < t1->val.length(); i++)
						if (t1->val.at(i) < t2->val.at(i) && !swapped)
						{
							swapped = true;
							temp = t1->val;
							t1->val = t2->val;
							t2->val = temp;
						}
				}
				t2 = t2->next;
			}
			t1 = t1->next;
		}
		if (swapped) { return; }
	}
};

int main()
{
	// declares queue, strings for animals and commands from file, and input and output
	Queue Q;
	string animal, command;
	ifstream infile;
	infile.open("input.txt");
	ofstream outfile;
	outfile.open("output.txt");

	// while there is a command to do, executes command
	while (infile >> command)
	{
		if (command == "push")
		{	// takes in animal from file with push command and sorts the queue
			infile >> animal;
			Q.push(animal);
			Q.sortSL();
			Q.sortAB();
		}
		// pops off prioritized queue
		else outfile << Q.pop() << '\n';
	}
	// prints remainging information
	Q.print(outfile);
	return 0;
}
```
