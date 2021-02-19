#pragma once
#include "book.h"
#include <iomanip>	//출력 정렬

typedef book ListElementType;
const int maxListSize = 1000;
struct Node;
typedef Node *Link;
struct Node {
	Link prev;
	ListElementType elem;
	Link next;
};
class List {
public:
	List();
	void insert(const ListElementType & elem);
	bool first(ListElementType & elem);
	bool next(ListElementType & elem);
	bool search(Link &aTargetNode, string strISBN);
	bool deleteNode(string strISBN);
	bool last(ListElementType & elem);
	bool updateByIncresingLoanCount(string strISBN);
	void print();
	bool previous(ListElementType &elem);


private:

	Link head;
	Link tail;
	Link current;

};

