#include <iostream>
#include "main.h"
#pragma warning(disable: 4996)

//共用函数
bool Filtration(string& ch)		//中文判断
{
	if (ch.length() == 0) {
		return false;
	}
	char* s = (char*)malloc(ch.length() + 1);
	strcpy(s, ch.data());
	int i = 0;
	int j = 0;
	for (i = 0; s[i]; i++) {	//英文，及标点符号判断，因为英文不管是utf-8编码还是gbk编码，都是以一个字节，并且每个字节都是大于零的
		if (s[i] < 0) {
			s[j++] = s[i];
		}
	}
	s[j] = 0;
	int n = 0;
	while (s[n]) {
		if (s[n] == (modelength == 3 ? -30 : -95) || s[n] == (modelength == 3 ? -19 : -93) \
			|| s[n] == (modelength == 3 ? -17 : 0)) {	//进行中文标点符号判断，当编码为gbk时，中文标点符号的第一个字节主要在-95，-93；当编码为utf-8时，中文标点符号的第一个字节主要在-30,-19,-17
			free(s);
			return false;
		}
		n += modelength;
	}
	if (ch.length() == strlen(s)) {
		free(s);
		return true;
	}
	else {
		free(s);
		return false;
	}
}
int choose(int left, int right) {
	int choosesta = 0;
	while (!(cin >> choosesta) || (getchar() == 10 ? ungetc(10, stdin), false : true) || choosesta < left || choosesta > right) {	//通过判断数字后的一个字符是不是回车，就可以是否为纯数字
		cout << "输入错误,请重新输入" << endl;	//进行数字判断，当数字超过限定范围时或者不是数字的时候将回驳回
		flushstd;		//清空stdin缓冲区
		cin.clear();	//清空cin状态
	}
	getchar();
	return choosesta;
}
string cinstr(int left, int right) {
	string out0 = "必须是纯中文,且长度须在";
	string out1 = to_string(left);
	string out2 = "至";
	string out3 = to_string(right);
	string out4 = "个汉字, 请重新输入\n";
	out0 = out0 + out1 + out2 + out3 + out4;
	string name;
	while (!(cin >> name) || (getchar() == 10 ? ungetc(10, stdin), false : true) || !Filtration(name) || name.length() < left*modelength || name.length() > right*modelength) {	//通过判断getc的字符是不是回车，就可以判断stdin缓冲区是否为空
		cout << out0;		//进行中文判断，当中文超过限定范围时或者不是中文的时候将回驳回
		flushstd;
		cin.clear();
	}
	return name;
}
void DIRECTORY(bool enter)		//表头
{
	if (enter) cout << endl;
	cout <<"   学号         姓名    性别   年龄   出生年    月      日      专业      英语入学分数   家庭地址" << endl;
	return;
}
void pause()
{
	cout << "按 Enter 键继续...: ";
	flushstd;
	return;
}
int begin()		//功能栏
{
	int space = 0;
	int ret = 0;
	cout << "1.展示学生信息\n";
	cout << "2.新增学生信息\n";
	cout << "3.删除学生信息\n";
	cout << "4.搜索学生信息\n";
	cout << "5.编辑学生信息\n";
	cout << "6.统计学生信息\n";
	cout << "7.导入学生信息\n";
	cout << "8.保存学生信息\n";
	cout << "9.清空学生信息\n";
	cout << "0.退出学生系统\n\n";
	cout << "请选择：";
	return choose(0, 9);
}
void Statistics(List& list)
{
	if (list.nodeinfo("size") == 0) {
		cout << "无数据\n" << endl;
		return;
	}
	while (true) {
		cout << "1.统计人数" << endl;
		cout << "2.统计男女生人数及比例" << endl;
		cout << "3.统计英语分数超过某一值的人数" << endl;
		cout << "4.统计所有学生英语成绩总分及其平均分" << endl;
		cout << "5.统计所有学生英语成绩的方差" << endl;
		cout << "6.依据英语成绩排序" << endl;
		cout << "7.依据年龄排序" << endl;
		cout << "0.退出此功能" << endl;
		cout << endl;
		cout << "请选择：";
		switch (choose(0, 7)) {
		case 0:
			return;
			break;
		case 1:
			cout << "共有" << list.nodeinfo("size") << "名学生" << endl;
			break;
		case 2:
			list.SexRatio();
			break;
		case 3:
			list.OverEnglisg();
			break;
		case 4:
			list.AVG();
			break;
		case 5:
			list.Variance();
			break;
		case 6:
			Engsort(list);
			break;
		case 7:
			Agesort(list);
			break;
		}
		cout << endl;
	}
}
int GCD(int men, int women)		//欧几里得算法计算最大公约数
{
	int temp = 0, max = 0, min = 0;
	if (men >= women) {
		max = men;
		min = women;
	}
	else {
		max = women;
		min = men;
	}
	while (temp = max % min) {
		max = min;
		min = temp;
	}
	return min;
}
void Engsort(List& list)		//依据英语成绩进行排序
{
	cout << "1.依据英语成绩升序排序" << endl;
	cout << "2.依据英语成绩降序排序" << endl;
	cout << "3.依据英语成绩和性别升序排序" << endl;
	cout << "4.依据英语成绩和性别降序排序" << endl;
	cout << "0.返回" << endl;
	switch (choose(0, 4)) {
	case 0:
		break;
	case 1:
		list.Sortlist(11);
		break;
	case 2:
		list.Sortlist(12);
		break;
	case 3:
		list.Sortlist(13);
		break;
	case 4:
		list.Sortlist(14);
		break;
	}
	return;
}
void Agesort(List& list)		//依据年龄进行排序
{
	cout << "1.依据年龄升序排序" << endl;
	cout << "2.依据年龄降序排序" << endl;
	cout << "3.依据年龄和性别升序排序" << endl;
	cout << "4.依据年龄和性别降序排序" << endl;
	cout << "0.返回" << endl;
	switch (choose(0, 4)) {
	case 0:
		break;
	case 1:
		list.Sortlist(21);
		break;
	case 2:
		list.Sortlist(22);
		break;
	case 3:
		list.Sortlist(23);
		break;
	case 4:
		list.Sortlist(24);
		break;
	}
	return;
}