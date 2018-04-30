#include <iostream>
#include <string>
#include "DBList.h"
#include <fstream>

using namespace std;

//Public 
////////////////////////////////////////////

DBList::DBList() {
	Head = NULL;
	Tail = NULL;
	Current = NULL;
	Count = 0;
}

/**
* InsertFront -
*     Inserts a value at the front of the list by calling
*     actual insert with a node.
* Params:
*     string : data element to be inserted
*/
void DBList::InsertFront(string Data) {
	Node* Temp = new Node(Data);
	InsertFront(Temp);

}

/**
* InsertFront -
*     Inserts a value at the front of the list
* Params:
*     Node*& : node to be appended to front
*/
void DBList::InsertFront(Node* &Temp) {

	if (!Head) {
		Head = Temp;
		Tail = Temp;
		Tail->Next = Head;
		Current = Temp;
		Head->Prev = Tail;

	}
	else {
		Temp->Next = Head;
		Temp->Prev = Tail;
		Head->Prev = Temp;
		Tail->Next = Temp;
		Head = Temp;
		Current = Head;
	}
}


void DBList::InsertRear(Node* &Temp) {

	if (!Head) {
		DBList::InsertFront(Temp);
	}
	else {
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Tail = Temp;
		Tail->Next = Head;
		Head->Prev = Tail;
	}
}

/**
* InsertRear -
*     Inserts a value at the rear of the list by calling
*     actual insert with a node.
* Params:
*     string : data element to be inserted
*/
void DBList::InsertRear(string Data) {
	if (!Head) {
		DBList::InsertFront(Data);
	}
	else {
		Node* Temp = new Node(Data);
		InsertRear(Temp);
	}
}

void DBList::InsertInOrder(string Data) {
	if (!Head) {
		DBList::InsertFront(Data);
	}
	else {
		Node* Temp = new Node(Data);
		//Node* Location = DBList::_Find(Data);

	}
}

bool DBList::Delete(string x) {
	//One node 
	if (Current->Data == x)
		Current = Current->Next;
	if (Head == Tail && Head->Data == x) {
		delete Head;
		Head = NULL;
		Tail = NULL;
		return true;
		//Beginning of list
	}
	else if (Head->Data == x) {
		Head = Head->Next;
		delete Head->Prev;
		Head->Prev = Tail;
		Tail->Next = Head;
		return true;
		//End of list
	}
	else if (Tail->Data == x) {
		Tail = Tail->Prev;
		delete Tail->Next;
		Tail->Next = Head;
		Head->Prev = Tail;
		return true;
		//Middle of list
	}
	else {
		Node* Location = DBList::_Find(x);
		if (Location) {
			Location->Prev->Next = Location->Next;
			Location->Next->Prev = Location->Prev;
			delete Location;
			return true;
		}
	}
	return false;
}

bool DBList::Find(string x) {
	return false;
}

bool DBList::Update(string x, string y) {
	return false;
}

void DBList::Print(int columns) {
	Node *Temp = Head;
	int count = 1;
	while (Temp != Tail) {
		cout << Temp->Data << " ";
		Temp = Temp->Next;
		if (columns && count % columns == 0)
			cout << endl;
		count++;
	}
	cout << Temp->Data;
}

void DBList::Print() {
	DBList::Print(0);
}


void DBList::rPrint() {
	DBList::rPrint1(Tail);
}
//Private 
////////////////////////////////////////////

void DBList::rPrint(Node* Head) {
	if (Head == Tail) {
		return;
	}
	else {

		DBList::rPrint(Head->Next);
		cout << Head->Data << " ";
	}
}

void DBList::rPrint1(Node* Tail) {
	if (Tail == Head) {
		return;
	}
	else {
		cout << Tail->Data << " ";
		DBList::rPrint1(Tail->Prev);
	}
}



Node* DBList::_Find(string key) {
	Node* Temp = Head;

	while (Temp) {
		if (Temp->Data == key) {
			return Temp;
		}
		Temp = Temp->Next;
	}
	return NULL;
}

string DBList::Eliminate(string Data, int m)
{
	if (Head != Tail) {
		string Eliminated;
		Node * Temp;
		int move = Data.length();
		move *= m;
		for (int Step = 0; Step < move; Step++)
		{
			if (m % 2 == 1)
			{
				Current = Current->Prev;
			}
			else Current = Current->Next;
		}
		Temp = Current;
		Current = Temp->Next;
		Eliminated = Temp->Data;
		DBList::Delete(Eliminated);
		return Eliminated;
	}
	else return Current->Data;
}