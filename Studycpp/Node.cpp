#include <iostream>
#include "main.h"
//Node���ʵ��

bool Node::add(list<Node*>& node, List &list, bool find)	//Ϊ�ڵ����ѧ����Ϣ
{
	//ѧ�ţ�����, �Ա�
	cout << "ѧ��(����Ϊ10���ַ�,���롰0������):" << endl;
	string stunum;
	cin >> stunum;
	if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stunum == "0") {		//��Щ���ǽ��зǷ������ж�
		getchar();
		return false;
	}
	while ((getchar() == 10 ? ungetc(10, stdin), false : true) || cin.fail() || strspn(stunum.data(), "0123456789") != stunum.length() || stunum.length() != 10) {
		if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stunum == "0") {
			getchar();
			return false;
		}
		cout << "ѧ��ӦΪ�������ҳ���Ϊ10���ַ�,����������" << endl;
		flushstd;
		cin.clear();
		cin >> stunum;
	}
	getchar();
	if (list.findrepeat(stunum) == true && find) {
		cout << "���д�ͬѧ" << endl;
		return false;
	}
	this->stunum = stunum;
	cout << "����:\t";
	this->name = cinstr(2, 4);
	cout << "�Ա�:\t";
	string gender;
gogender:
	cin >> gender;
	flushstd;
	if (gender == "��") {
		this->gender = gender;
	}
	else if (gender == "Ů") {
		this->gender = gender;
	}
	else {
		cout << "�Ա��������,����������" << endl;
		goto gogender;
	}
	//�������ڣ� ����;
	cout << "��������\n�꣺\t";
	int day = 0;
	this->year = choose(2000, 2050);
	cout << "�£�\t";
	this->month = choose(1, 12);
	cout << "�գ�\t";
	if (month == 2 && year % 4 == 0 && year % 100 != 0)
	{
		day = choose(1, 29);
	}
	else if (month == 2) {
		day = choose(1, 28);
	}
	else if (month == 1 || month == 3 || month == 5 || \
		month == 7 || month == 8 || month == 10 || month == 12) {
		day = choose(1, 31);
	}
	else {
		day = choose(1, 30);
	}
	this->day = day;
	cout << "����:\t";
	this->age = choose(0, 120);
	//��ͥסַ��רҵ, Ӣ��ɼ�
	cout << "��ͥסַ:";
	this->address = cinstr(4, 30);
	cout << "רҵ:\t";
	this->specialized = cinstr(4, 8);
	cout << "Ӣ����ѧ�ɼ�:";
	this->english = choose(0, 150);
	return true;
}
void Node::putstu() {		//���ڵ��е��������
	cout << this->stunum << "\t";
	cout << this->name;
	if (this->name.length() != 4 * modelength) {
		cout << "\t";
	}
	cout << this->gender << "\t";
	cout << this->age << "\t";
	cout << this->year << "\t";
	cout << this->month << "\t";
	cout << this->day << "\t";
	cout << this->specialized;
	if (this->specialized.length() != 8 * modelength) {
		cout << "\t";
	}
	cout << this->english << "\t";
	cout << this->address << endl;
	return;
}