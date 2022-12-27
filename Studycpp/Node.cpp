#include <iostream>
#include "main.h"
//Node类的实现

bool Node::add(list<Node*>& node, List &list, bool find)	//为节点添加学生信息
{
	//学号，姓名, 性别
	cout << "学号(长度为10个字符,输入“0”返回):" << endl;
	string stunum;
	cin >> stunum;
	if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stunum == "0") {		//这些都是进行非法输入判断
		getchar();
		return false;
	}
	while ((getchar() == 10 ? ungetc(10, stdin), false : true) || cin.fail() || strspn(stunum.data(), "0123456789") != stunum.length() || stunum.length() != 10) {
		if ((getchar() == 10 ? ungetc(10, stdin), true : false) && cin.good() && stunum == "0") {
			getchar();
			return false;
		}
		cout << "学号应为纯数字且长度为10个字符,请重新输入" << endl;
		flushstd;
		cin.clear();
		cin >> stunum;
	}
	getchar();
	if (list.findrepeat(stunum) == true && find) {
		cout << "已有此同学" << endl;
		return false;
	}
	this->stunum = stunum;
	cout << "姓名:\t";
	this->name = cinstr(2, 4);
	cout << "性别:\t";
	string gender;
gogender:
	cin >> gender;
	flushstd;
	if (gender == "男") {
		this->gender = gender;
	}
	else if (gender == "女") {
		this->gender = gender;
	}
	else {
		cout << "性别输入错误,请重新输入" << endl;
		goto gogender;
	}
	//出生日期， 年龄;
	cout << "出生日期\n年：\t";
	int day = 0;
	this->year = choose(2000, 2050);
	cout << "月：\t";
	this->month = choose(1, 12);
	cout << "日：\t";
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
	cout << "年龄:\t";
	this->age = choose(0, 120);
	//家庭住址，专业, 英语成绩
	cout << "家庭住址:";
	this->address = cinstr(4, 30);
	cout << "专业:\t";
	this->specialized = cinstr(4, 8);
	cout << "英语入学成绩:";
	this->english = choose(0, 150);
	return true;
}
void Node::putstu() {		//将节点中的数据输出
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