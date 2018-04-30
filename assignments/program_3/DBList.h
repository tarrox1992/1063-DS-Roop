#include <iostream>
#include <string>

using namespace std;

struct Node {
	string Data;

	Node *Prev;
	Node *Next;
	Node(string x) {
		Data = x;
		Prev = NULL;
		Next = NULL;
	}
};

class DBList {
private:
	Node *Head;
	Node *Tail;
	Node *Current;
	Node* _Find(string);
	int Count;
	void rPrint(Node*);
	void rPrint1(Node*);
public:
	DBList();
	void InsertFront(string);
	void InsertFront(Node*&);
	void InsertRear(string);
	void InsertRear(Node*&);
	void InsertInOrder(string);
	void PriorityInsert(string Data);
	bool Delete(string);   //Removes item from list
	bool Find(string);     //Locate and see if exists
	bool Update(string, string);   //Change existing value
	void Print();
	void Print(int);
	void rPrint();
	string Eliminate(string, int); // Goes through elimination protocals
};