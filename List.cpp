#include "List.h"
#include <assert.h>


List::List()
{
	head = new Node;
	assert(head);
	head->prev = 0;
	head->next = 0;
	current = 0;		//dummy ����
	tail = head;

}

void List::insert(const ListElementType & elem)
{
	Link addedNode = new Node;
	assert(addedNode);
	addedNode->elem = elem;

	Link pred(head);
	while (pred->next != 0 && (pred->next->elem.getBorrowCount() <= addedNode->elem.getBorrowCount()))
		pred = pred->next;

	if (pred->next == 0)	//tail ����϶�
	{
		addedNode->next = 0;
		addedNode->prev = pred;
		pred->next = addedNode;
		tail = addedNode;
	}
	else {			//tail ��尡 �ƴҶ�
		addedNode->next = pred->next;
		addedNode->prev = pred;
		pred->next->prev = addedNode;
		pred->next = addedNode;
	}

}

bool List::first(ListElementType & elem)
{
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}

}

bool List::next(ListElementType & elem)
{
	assert(current);

	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}

}

bool List::search(Link &aTargetNode, string strISBN)
{
	Node temp;
	assert(head);
	Link pred(head);
	while (pred != 0)
	{
		if (strISBN == pred->elem.getIsbn())
		{
			aTargetNode->elem = pred->elem;
			return true;
		}
		pred = pred->next;
	}

	return false;

}

bool List::deleteNode(string strISBN)
{
	assert(head);
	Link pred(head), delNode;
	while (pred->next != 0)
	{
		if (strISBN == pred->next->elem.getIsbn())
		{
			delNode = pred->next;
			if (delNode->next != 0)		//������� ��尡 tail��尡 �ƴҶ�
			{
				pred->next = delNode->next;
				pred->next->prev = pred;
			}
			else           //������� ��尡 tail����϶�
			{
				pred->next = 0;
				tail = pred;
			}
			delete delNode;
			return true;
		}
		pred = pred->next;
	}
	return false;
}
bool List::last(ListElementType & elem)
{
	if (tail == 0)
		return false;
	else
	{
		elem = tail->elem;
		current = tail;
		return true;
	}
}
bool List::updateByIncresingLoanCount(string strISBN)
{
	Link aTargetNode = new Node;
	bool res;
	int tCnt;
	aTargetNode->elem.setIsbn(strISBN);
	res = search(aTargetNode, strISBN);

	if (res == true)
	{
		cout << "ã�� å�� ���� : " << aTargetNode->elem.getName() << endl;
		cout << "ã�� å�� ISBN : " << aTargetNode->elem.getIsbn() << endl;
		cout << "ã�� å�� ���� ���� Ƚ�� : " << aTargetNode->elem.getBorrowCount() << endl;
		deleteNode(strISBN);
		tCnt = aTargetNode->elem.getBorrowCount();
		aTargetNode->elem.setBorrowCount(++tCnt);
		insert(aTargetNode->elem);
		cout << "ã�� å�� ���ο� ���� Ƚ�� : " << aTargetNode->elem.getBorrowCount() << endl;

		return true;
	}

	else return false;
}

void List::print()
{
	Link pred(head);
	Link cur(pred->next);
	cout.setf(ios::right);
	cout << setw(30) << "å����";
	cout << setw(30) << "���ڸ�";
	cout << setw(30) << "���ǻ�";
	cout << setw(30) << "ī�װ�";
	cout << setw(30) << "�Ϸù�ȣ";
	cout << setw(30) << "ISBN";
	cout << setw(30) << "����Ƚ��" << endl << endl;
	while (pred->next != 0)
	{
		cout << setw(30) << cur->elem.getName();
		cout << setw(30) << cur->elem.getAuthor();
		cout << setw(30) << cur->elem.getCompany();
		cout << setw(30) << cur->elem.getCategory();
		cout << setw(30) << cur->elem.getNum();
		cout << setw(30) << cur->elem.getIsbn();
		cout << setw(30) << cur->elem.getBorrowCount() << endl << endl;
		pred = pred->next;
		cur = cur->next;
	}
}

bool List::previous(ListElementType &elem)
{
	assert(current);
	if (current->prev == 0)
		return false;
	else
	{
		current = current->prev;
		elem = current->elem;
		return true;
	}

}



