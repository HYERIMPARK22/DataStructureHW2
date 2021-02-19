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
	cout << "# 검색 전 도서 목록 출력 " << endl;
	printList();

	search();
	printLine();
	cout << "# 검색 후 도서 목록 출력 " << endl;
	printList();

	deleteNode();
	printLine();
	cout << "# 삭제 후 도서 목록 출력 " << endl;
	printList();

	
	cout << "# 현재 남아있는 도서 중 대출 횟수가 가장 많은 책의 정보 출력(Tail Node)" << endl;
	lastBookPrint();
	printLine();

}

void search()
{
	string stemp;
	bool res;
	while (1)
	{
		cout << "# 대출 할 책의 ISBN을 입력하세요 : ";
		cin >> stemp;
		if (cin.fail())
		{
			cout << "잘못된 형식을 입력하셨습니다. 다시 입력해주세요." << endl;
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
				cout << "해당하는 책을 찾지 못했습니다. 다시 입력해주세요. " << endl;
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
		cout << "# 삭제 할 책의 ISBN을 입력하세요 : ";
		cin >> stemp;
		if (cin.fail())
		{
			cout << "잘못된 형식을 입력하셨습니다. 다시 입력해주세요." << endl;
			myflush();
		}
		else {
			aTargetNode->elem.setIsbn(stemp);
			res = l.deleteNode(stemp);
			if (res == true)
			{
				cout << "삭제하려는 책의 ISBN : " << aTargetNode->elem.getIsbn() << endl;
				cout << "삭제가 완료되었습니다." << endl;
				break;
			}

			else
			{
				cout << "해당하는 책이 존재하지 않습니다. 다시 입력해주세요. " << endl;
				myflush();
			}
		}
	}
}
void lastBookPrint()	//last함수 확인해보는 함수
{
	ListElementType elem;
	l.last(elem);
	cout << "Tail Node의 책의 제목 : " << elem.getName() << endl;
	cout << "Tail Node의 책의 ISBN : " << elem.getIsbn() << endl;
	cout << "Tail Node의 책의 대출 횟수 : " << elem.getBorrowCount() << endl;
}

//----------------------------------------------------------------------
void printList()		//List 값 확인 시 사용
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

void makedata() {		//여러권이 검색되는 단어:용서,기술,온도,사람
	ElementType a("모든 순간이 너였다", "하태완", "위즈덤하우스", "시/에세이", 0, "9791162202913",151);
	l.insert(a);
	ElementType b("용서해 테오", "질 티보", "어린이작가정신", "동화", 1, "9788972889410",162);
	l.insert(b);
	ElementType c("최신 온도센서 기술동향", "정용택", "홍릉과학출판사", "기술/공학", 2, "9791156003434",123);
	l.insert(c);
	ElementType d("죽여 마땅한 사람들", "피터 스완슨", "푸른숲", "소설", 3, "9791156756552",192);
	l.insert(d);
	ElementType e("비하인드 허 아이즈", "사라 핀보로", "북폴리오", "소설", 4, "9788937857591",184);
	l.insert(e);
	ElementType f("아낌없이 뺏는 사랑", "피터 스완슨", "푸른숲", "소설", 5, "9791156756934",139);
	l.insert(f);
	ElementType g("켈빈이 들려주는 온도 이야기", "김충섭", "자음과모음", "과학", 6, "9788954420822",174);
	l.insert(g);
	ElementType h("오직 두 사람", "김영하", "문학동네", "소설", 7, "9788954645614",147);
	l.insert(h);
	ElementType i("냉장고를 부탁해", "JTBC 냉장고를 부탁해 제작팀", "중앙북스", "요리", 8, "9788927806837",170);
	l.insert(i);
	ElementType j("온가족이 즐거운 주말요리", "구본길", "리스컴", "요리", 9, "9788991193352",166);
	l.insert(j);
	ElementType k("늙지 않는 비밀", "엘리자베스 블랙번", "알에이치코리아", "건강", 10, "9788925563275",185);
	l.insert(k);
	ElementType u("나쁜국어 독해기술", "진형석", "쏠티북스", "중/고등참고서", 11, "9788997408139",111);
	l.insert(u);
	ElementType m("불행 피하기 기술", "롤프 도벨리", "인플루엔셜", "자기계발", 12, "9791186560617",122);
	l.insert(m);
	ElementType n("크레이빙 마인드", "저드슨 브루어", "어크로스", "인문", 13, "9791160560404",134);
	l.insert(n);
	ElementType o("용서", "달라이 라마", "오래된미래", "시/에세이", 14, "9788995501467",199);
	l.insert(o);
	ElementType p("며느라기", "수신지", "귤프레스", "만화", 15, "9791196287801",100);
	l.insert(p);
	ElementType q("나와 청소년문학 20년", "박상률", "학교도서관저널", "시/에세이", 16, "9788969150233",162);
	l.insert(q);
	ElementType r("언어의 온도", "이기주", "말글터", "시/에세이", 17, "9791195522125",136);
	l.insert(r);
	ElementType s("인투 더 워터", "폴라 호킨스", "북폴리오", "소설", 18, "9791162332528",148);
	l.insert(s);
	ElementType t("푸드 앤 더 시티", "제니퍼 코크럴킹", "삼천리", "정치/사회", 19, "9788994898261",191);
	l.insert(t);
}