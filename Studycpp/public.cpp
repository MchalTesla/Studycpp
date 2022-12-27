#include <iostream>
#include "main.h"
#pragma warning(disable: 4996)

//���ú���
bool Filtration(string& ch)		//�����ж�
{
	if (ch.length() == 0) {
		return false;
	}
	char* s = (char*)malloc(ch.length() + 1);
	strcpy(s, ch.data());
	int i = 0;
	int j = 0;
	for (i = 0; s[i]; i++) {	//Ӣ�ģ����������жϣ���ΪӢ�Ĳ�����utf-8���뻹��gbk���룬������һ���ֽڣ�����ÿ���ֽڶ��Ǵ������
		if (s[i] < 0) {
			s[j++] = s[i];
		}
	}
	s[j] = 0;
	int n = 0;
	while (s[n]) {
		if (s[n] == (modelength == 3 ? -30 : -95) || s[n] == (modelength == 3 ? -19 : -93) \
			|| s[n] == (modelength == 3 ? -17 : 0)) {	//�������ı������жϣ�������Ϊgbkʱ�����ı����ŵĵ�һ���ֽ���Ҫ��-95��-93��������Ϊutf-8ʱ�����ı����ŵĵ�һ���ֽ���Ҫ��-30,-19,-17
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
	while (!(cin >> choosesta) || (getchar() == 10 ? ungetc(10, stdin), false : true) || choosesta < left || choosesta > right) {	//ͨ���ж����ֺ��һ���ַ��ǲ��ǻس����Ϳ����Ƿ�Ϊ������
		cout << "�������,����������" << endl;	//���������жϣ������ֳ����޶���Χʱ���߲������ֵ�ʱ�򽫻ز���
		flushstd;		//���stdin������
		cin.clear();	//���cin״̬
	}
	getchar();
	return choosesta;
}
string cinstr(int left, int right) {
	string out0 = "�����Ǵ�����,�ҳ�������";
	string out1 = to_string(left);
	string out2 = "��";
	string out3 = to_string(right);
	string out4 = "������, ����������\n";
	out0 = out0 + out1 + out2 + out3 + out4;
	string name;
	while (!(cin >> name) || (getchar() == 10 ? ungetc(10, stdin), false : true) || !Filtration(name) || name.length() < left*modelength || name.length() > right*modelength) {	//ͨ���ж�getc���ַ��ǲ��ǻس����Ϳ����ж�stdin�������Ƿ�Ϊ��
		cout << out0;		//���������жϣ������ĳ����޶���Χʱ���߲������ĵ�ʱ�򽫻ز���
		flushstd;
		cin.clear();
	}
	return name;
}
void DIRECTORY(bool enter)		//��ͷ
{
	if (enter) cout << endl;
	cout <<"   ѧ��         ����    �Ա�   ����   ������    ��      ��      רҵ      Ӣ����ѧ����   ��ͥ��ַ" << endl;
	return;
}
void pause()
{
	cout << "�� Enter ������...: ";
	flushstd;
	return;
}
int begin()		//������
{
	int space = 0;
	int ret = 0;
	cout << "1.չʾѧ����Ϣ\n";
	cout << "2.����ѧ����Ϣ\n";
	cout << "3.ɾ��ѧ����Ϣ\n";
	cout << "4.����ѧ����Ϣ\n";
	cout << "5.�༭ѧ����Ϣ\n";
	cout << "6.ͳ��ѧ����Ϣ\n";
	cout << "7.����ѧ����Ϣ\n";
	cout << "8.����ѧ����Ϣ\n";
	cout << "9.���ѧ����Ϣ\n";
	cout << "0.�˳�ѧ��ϵͳ\n\n";
	cout << "��ѡ��";
	return choose(0, 9);
}
void Statistics(List& list)
{
	if (list.nodeinfo("size") == 0) {
		cout << "������\n" << endl;
		return;
	}
	while (true) {
		cout << "1.ͳ������" << endl;
		cout << "2.ͳ����Ů������������" << endl;
		cout << "3.ͳ��Ӣ���������ĳһֵ������" << endl;
		cout << "4.ͳ������ѧ��Ӣ��ɼ��ּܷ���ƽ����" << endl;
		cout << "5.ͳ������ѧ��Ӣ��ɼ��ķ���" << endl;
		cout << "6.����Ӣ��ɼ�����" << endl;
		cout << "7.������������" << endl;
		cout << "0.�˳��˹���" << endl;
		cout << endl;
		cout << "��ѡ��";
		switch (choose(0, 7)) {
		case 0:
			return;
			break;
		case 1:
			cout << "����" << list.nodeinfo("size") << "��ѧ��" << endl;
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
int GCD(int men, int women)		//ŷ������㷨�������Լ��
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
void Engsort(List& list)		//����Ӣ��ɼ���������
{
	cout << "1.����Ӣ��ɼ���������" << endl;
	cout << "2.����Ӣ��ɼ���������" << endl;
	cout << "3.����Ӣ��ɼ����Ա���������" << endl;
	cout << "4.����Ӣ��ɼ����Ա�������" << endl;
	cout << "0.����" << endl;
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
void Agesort(List& list)		//���������������
{
	cout << "1.����������������" << endl;
	cout << "2.�������併������" << endl;
	cout << "3.����������Ա���������" << endl;
	cout << "4.����������Ա�������" << endl;
	cout << "0.����" << endl;
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