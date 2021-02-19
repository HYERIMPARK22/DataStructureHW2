#include <iostream>
using namespace std;
#include <string>
#include "book.h"
#include "List.h"
typedef book ElementType;
void search();
void deleteNode();
void lastBookPrint();

void printList();
void myflush();
void printLine();
void makedata();

List l;		

int main()
{
	makedata();
	printLine();
	cout << "# �˻� �� ���� ��� ��� " << endl;
	printList();

	search();
	printLine();
	cout << "# �˻� �� ���� ��� ��� " << endl;
	printList();

	deleteNode();
	printLine();
	cout << "# ���� �� ���� ��� ��� " << endl;
	printList();

	
	cout << "# ���� �����ִ� ���� �� ���� Ƚ���� ���� ���� å�� ���� ���(Tail Node)" << endl;
	lastBookPrint();
	printLine();

}

void search()
{
	string stemp;
	bool res;
	while (1)
	{
		cout << "# ���� �� å�� ISBN�� �Է��ϼ��� : ";
		cin >> stemp;
		if (cin.fail())
		{
			cout << "�߸��� ������ �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			myflush();
		}
		else {
			res = l.updateByIncresingLoanCount(stemp);

			if (res == true)
			{
				break;
			}

			else
			{
				cout << "�ش��ϴ� å�� ã�� ���߽��ϴ�. �ٽ� �Է����ּ���. " << endl;
				myflush();
			}
		}
	}


}
void deleteNode()
{
	string stemp;
	Link aTargetNode = new Node;
	bool res;
	while (1)
	{
		cout << "# ���� �� å�� ISBN�� �Է��ϼ��� : ";
		cin >> stemp;
		if (cin.fail())
		{
			cout << "�߸��� ������ �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			myflush();
		}
		else {
			aTargetNode->elem.setIsbn(stemp);
			res = l.deleteNode(stemp);
			if (res == true)
			{
				cout << "�����Ϸ��� å�� ISBN : " << aTargetNode->elem.getIsbn() << endl;
				cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
				break;
			}

			else
			{
				cout << "�ش��ϴ� å�� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���. " << endl;
				myflush();
			}
		}
	}
}
void lastBookPrint()	//last�Լ� Ȯ���غ��� �Լ�
{
	ListElementType elem;
	l.last(elem);
	cout << "Tail Node�� å�� ���� : " << elem.getName() << endl;
	cout << "Tail Node�� å�� ISBN : " << elem.getIsbn() << endl;
	cout << "Tail Node�� å�� ���� Ƚ�� : " << elem.getBorrowCount() << endl;
}

//----------------------------------------------------------------------
void printList()		//List �� Ȯ�� �� ���
{
	printLine();
	l.print();
	printLine();
}
void myflush()
{
	cin.clear();
	while (cin.get() != '\n');
}

void printLine()
{
	cout << "------------------------------------------------------------------------" << endl;
}

void makedata() {		//�������� �˻��Ǵ� �ܾ�:�뼭,���,�µ�,���
	ElementType a("��� ������ �ʿ���", "���¿�", "������Ͽ콺", "��/������", 0, "9791162202913",151);
	l.insert(a);
	ElementType b("�뼭�� �׿�", "�� Ƽ��", "����۰�����", "��ȭ", 1, "9788972889410",162);
	l.insert(b);
	ElementType c("�ֽ� �µ����� �������", "������", "ȫ���������ǻ�", "���/����", 2, "9791156003434",123);
	l.insert(c);
	ElementType d("�׿� ������ �����", "���� ���Ͻ�", "Ǫ����", "�Ҽ�", 3, "9791156756552",192);
	l.insert(d);
	ElementType e("�����ε� �� ������", "��� �ɺ���", "��������", "�Ҽ�", 4, "9788937857591",184);
	l.insert(e);
	ElementType f("�Ƴ����� ���� ���", "���� ���Ͻ�", "Ǫ����", "�Ҽ�", 5, "9791156756934",139);
	l.insert(f);
	ElementType g("�̺��� ����ִ� �µ� �̾߱�", "���漷", "����������", "����", 6, "9788954420822",174);
	l.insert(g);
	ElementType h("���� �� ���", "�迵��", "���е���", "�Ҽ�", 7, "9788954645614",147);
	l.insert(h);
	ElementType i("����� ��Ź��", "JTBC ����� ��Ź�� ������", "�߾ӺϽ�", "�丮", 8, "9788927806837",170);
	l.insert(i);
	ElementType j("�°����� ��ſ� �ָ��丮", "������", "������", "�丮", 9, "9788991193352",166);
	l.insert(j);
	ElementType k("���� �ʴ� ���", "�����ں��� ����", "�˿���ġ�ڸ���", "�ǰ�", 10, "9788925563275",185);
	l.insert(k);
	ElementType u("���۱��� ���ر��", "������", "��Ƽ�Ͻ�", "��/�������", 11, "9788997408139",111);
	l.insert(u);
	ElementType m("���� ���ϱ� ���", "���� ������", "���÷翣��", "�ڱ���", 12, "9791186560617",122);
	l.insert(m);
	ElementType n("ũ���̺� ���ε�", "���彼 ����", "��ũ�ν�", "�ι�", 13, "9791160560404",134);
	l.insert(n);
	ElementType o("�뼭", "�޶��� ��", "�����ȹ̷�", "��/������", 14, "9788995501467",199);
	l.insert(o);
	ElementType p("������", "������", "��������", "��ȭ", 15, "9791196287801",100);
	l.insert(p);
	ElementType q("���� û�ҳ⹮�� 20��", "�ڻ��", "�б�����������", "��/������", 16, "9788969150233",162);
	l.insert(q);
	ElementType r("����� �µ�", "�̱���", "������", "��/������", 17, "9791195522125",136);
	l.insert(r);
	ElementType s("���� �� ����", "���� ȣŲ��", "��������", "�Ҽ�", 18, "9791162332528",148);
	l.insert(s);
	ElementType t("Ǫ�� �� �� ��Ƽ", "������ ��ũ��ŷ", "��õ��", "��ġ/��ȸ", 19, "9788994898261",191);
	l.insert(t);
}