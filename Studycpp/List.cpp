#include <iostream>
#include <fstream>
#include <iomanip>
#include "main.h"
using namespace std;

//List���ʵ��
bool List::buildlist()		//�����ڵ�
{
	Node* temp = new Node;
	bool state = temp->add(this->node, *this, true);
	if (state == true) {
		this->node.push_back(temp);
		return true;
	}
	else {
		delete(temp);
		return false;
	}
}
bool List::findrepeat(string& tname)		//Ѱ���ظ��ڵ�
{
	for (list<Node*>::iterator line = this->node.begin(); line != node.end(); line++) {		//ͨ�����������б���
		if ((*line)->stunum == tname) {		//�ж��Ƿ����ظ���ѧ��
			return true;
		}
	}
	return false;
}
void List::show()		//�����ڵ�
{
	if (this->node.size() != 0) {
		DIRECTORY(true);
		for (list<Node*>::iterator line = this->node.begin(); line != node.end(); line++) {		//����
			(*line)->putstu();		//putustu()����������������ڵ������
		}
	}
	else {
		cout << "������" << endl;
	}
	cout << endl;
}
void List::search()			//��������
{
	if (this->node.size() == 0) {
		cout << "������" << endl;
		return;
	}
	cout << "������Ҫ��ѯѧ����ѧ�Ż������������롰0���˳�" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//�ж��������ѧ�Ż�������
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//ѧ��ִ��
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				return;
			}
		}
	}
	else {
		bool state = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//����ִ��
			if ((*line)->name == TNAME) {
				state = true;
				DIRECTORY(true);
				(*line)->putstu();
			}
		}
		if (state == true) {
			return;
		}
	}
	cout << "û�д�ѧ��" << endl;
	return;
}
void List::editstu()		//�༭����
{
	if (this->node.size() == 0) {
		cout << "������" << endl;
		return;
	}
	cout << "������༭ѧ����ѧ�Ż�������,���롰0������" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//�ж��������ѧ�Ż�������
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//ѧ��ִ��
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				cout << "ȷ���޸ģ���1.ȷ�� 0.ȡ����" << endl;
				if (choose(0, 1)) {
					bool state = (*line)->add(this->node, *this, false);
					DIRECTORY(true);
					(*line)->putstu();
					if(state) cout << "�޸ĳɹ�" << endl;
				}
				return;
			}
		}
	}
	else {
		bool state = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//����ִ��
			if ((*line)->name == TNAME) {
				state = true;
				DIRECTORY(true);
				(*line)->putstu();
				cout << "ȷ���޸ģ���1.ȷ�� 0.ȡ����" << endl;
				if (choose(0, 1)) {
					bool state = (*line)->add(this->node, *this, false);
					DIRECTORY(true);
					(*line)->putstu();
					if(state) cout << "�޸ĳɹ�" << endl;
				}
			}
		}
		if (state == true) {		//����ɹ�������һ���޸ģ����������
			return;
		}
	}
	cout << "û�д�ѧ��" << endl;
	return;
}
void List::deletelist(list<Node*>::iterator& itor)		//protected ɾ���ڵ�
{
	delete(*itor);
	this->node.erase(itor);
	return;
}
void List::deletestu()		//ɾ��ѧ������
{
	if (this->node.size() == 0) {
		cout << "������" << endl;
		return;
	}
	cout << "��������Ҫɾ��ѧ����ѧ�Ż�������,���롰0������" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//�ж��������ѧ�Ż�������
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//ѧ��ִ��
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				cout << "ȷ��ɾ������1.ȷ�� 0.ȡ����" << endl;
				if (choose(0, 1)) {
					this->deletelist(line);
					cout << "ɾ���ɹ�" << endl;
				}
				return;
			}
		}
	}
	else {
		bool state = false;
		_delete_1:
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//����ִ��
			if ((*line)->name == TNAME) {
				state = true;
				DIRECTORY(true);
				(*line)->putstu();
				cout << "ȷ��ɾ������1.ȷ�� 0.ȡ����" << endl;
				if (choose(0, 1)) {
					this->deletelist(line);
					cout << "ɾ���ɹ�" << endl;
					goto _delete_1;
				}
			}
		}
		if (state == true) {	//����ɹ�ɾ����һ�Σ����������
			return;
		}
	}
	cout << "û�д�ѧ��" << endl;
	return;
}
void List::close(int mode)		//�ر�
{
	for (list<Node*>::iterator line = node.begin(); line != node.end(); line++) {	//������new�����Ķ���delete
		delete(*line);
	}
	list<Node*>().swap(this->node);		//���list
	if (mode == 0) { this->state = false; }		//�ж��Ƿ���Ҫ�����������mode=0����List�е�state����Ϊfalse����ʾ����Ҫֹͣ
	return;
}
void List::import()		//�ļ�����
{
	cout << "�뽫��Ҫ������ļ�����˴�:";
	string filename;
	cin >> filename;		//���ļ����뵽�������л��Զ������ļ���λ�ã�ʹ�����ַ������Խ����ļ�����
	flushstd;
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) {		//�ж��ļ��Ƿ���Դ�
		cout << "�ļ�������" << endl;
	}
	else if (infile.get(), infile.eof()) {
		cout << "�ļ���������" << endl;
	}
	else {
		infile.seekg(ios::beg);
		while (infile.get(), !infile.eof()) {		//�����ļ��Ƿ��ȡ����ж�
			infile.seekg(-1, ios::cur);
			Node* temp = new Node;
			if (infile >> temp->stunum >> temp->name >> temp->gender >> temp->age \
				>> temp->year >> temp->month >> temp->day >> temp->specialized \
				>> temp->english >> temp->address, infile.fail() || infile.get() != 10)		//���ļ��Ķ�ȡ������ȷ���жϣ��ж��Ƿ��ȡ����
			{
				cout << "�ļ��޷�����" << endl;
				delete temp;
				return;
			}
			else if (this->findrepeat(temp->stunum)) {delete temp; }
			else { this->node.push_back(temp); }
		}
		infile.close();
		cout << "�ļ�����ɹ�" << endl;
return;
	}
}
void List::readfile(string& filename)	//�ļ���ȡ
{
	if (!this->can_open(filename)) {		//�ж��ļ��Ƿ���Դ�
		this->close(0);
		return;
	}
	else {
		ifstream infile;
		infile.open(filename);
		if (infile.get(), infile.eof()) {
			return;
		}
		infile.seekg(ios::beg);
		while (infile.get(), !infile.eof()) {	//�����ļ��Ƿ��ȡ����ж�
			infile.seekg(-1, ios::cur);
			Node* temp = new Node;

			if (infile >> temp->stunum >> temp->name >> temp->gender >> temp->age \
				>> temp->year >> temp->month >> temp->day >> temp->specialized \
				>> temp->english >> temp->address, infile.fail() || infile.get() != 10)		//���ļ��Ķ�ȡ������ȷ���жϣ��ж��Ƿ��ȡ����
			{
				cout << "�ļ��޷�����" << endl;
				delete temp;
				this->close(0);		//�������ʧ�ܣ����رճ���
				return;
			}
			else { this->node.push_back(temp); }
		}
		infile.close();
		return;
	}
}
bool List::savefile(string& filename, bool force)
{
	if (this->node.size() == 0 && !force) {		//�ж��������Ƿ�������
		cout << "������" << endl;
		return false;
	}
	else if (!this->can_open(filename)) {		//�ж��ļ��Ƿ���Դ�
		return false;
	}
	else {
		ofstream tmpfile;
		tmpfile.open(".tmpfile");
		bool error = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//���ļ���д�������ȷ���жϣ��ж��Ƿ��ȡ����
			tmpfile << (*line)->stunum << ' ' << (*line)->name << ' ' << (*line)->gender << ' ' << (*line)->age \
				<< ' ' << (*line)->year << ' ' << (*line)->month << ' ' << (*line)->day << ' ' << (*line)->specialized \
				<< ' ' << (*line)->english << ' ' << (*line)->address << endl;
			error = tmpfile.fail();
		}
		tmpfile.close();
		if (!error) {
			remove(filename.data());
			if (rename(".tmpfile", filename.data()) == 0) {
				cout << "����ɹ�" << endl;
				return true;
			}
		}
		cout << "����ʧ��" << endl;
		return false;
	}

}
bool List::can_open(string& filename)		//�����ļ��Ƿ������ȷ���ж�
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) {
		cout << filename << "������" << endl;
		cout << "�Ƿ񴴽�һ���µ�" << filename << "��1.�� 0.��" << endl;
		if (choose(0, 1)) {
			ofstream tempfile;
			tempfile.open(filename);
			if (tempfile.is_open()) {
				cout << "�ļ������ɹ�\n" << endl;
				tempfile.close();
				return true;
			}
			else {
				cout << "�ļ�����ʧ��\n" << endl;
			}
		}
		return false;
	}
	else {
		infile.close();
		return true;
	}
}
void ::List::SexRatio()		//�Ա�ͳ��
{
	int men = 0, women = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		if ((*line)->gender == "��") {
			men++;
		}
		else if ((*line)->gender == "Ů"){
		women++;
		}
	}
	int numgcd;
	if (men == 0 || women == 0) {
		numgcd = men > women ? men : women;
	}
	else {
		numgcd = GCD(men, women);
	}
	cout << "�������� = " << men << "    Ů������ = " << women << endl;
	cout << "��Ů������ = " << men / numgcd << " : " << women / numgcd << endl;
	return;
}
void List::OverEnglisg()		//ͳ�ƶ����˵�Ӣ��ɼ�������ĳһֵ
{
	cout << "������ͳ�ƶ��ٷּ����ϵ�ѧ��" << endl;
	int score = choose(0, 150);
	int num = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		if ((*line)->english >= score) {
			num++;
		}
	}
	cout << "��" << num << "λѧ������" << score << "��," << "ռ��ԼΪ" \
		<< fixed << setprecision(2) << ((double)num / this->node.size()) * 100 << "%" << endl;
	return;
}
void List::AVG()		//ͳ��ѧ����Ӣ��ƽ����
{
	int allscore = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		allscore += (*line)->english;
	}
	cout << "�ܷ�=" << allscore << ",ƽ����=" << fixed << setprecision(2) << (double)allscore / this->node.size() << endl;
}
void List::Variance()		//ͳ��ѧ����Ӣ��ɼ��ķ���
{
	int allscore = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		allscore += (*line)->english;	//�����ж��ܷ�
	}
	double avg = (double)allscore / this->node.size();
	double var = 0.0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		var += ((double)(*line)->english - avg) * ((double)(*line)->english - avg);		//���Ž��з������
	}
	cout << "���� = " << fixed << setprecision(2) << var / this->node.size() << endl;
}
void List::Sortlist(int mode)	//11:eu;12:ed;13:esu;14:esd;21:au;22:ad;23:asu;24:asd;	����ģʽ������
{
	Node** arr = (Node**)malloc(sizeof(Node*) * this->node.size());		//����һ���ͽڵ�����һ�����ָ���͵����飬���ڽ��л�������
	switch (mode) {
	case 11: {
		cout << "\n����\t";
		DIRECTORY(false);
		for (int count = 0, arrcount = 0; count <= 150; count++) {		//count�ۼ�
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {		//����
				if ((*line)->english == count) {		//���ĳһ��ѧ���ķ�������count��������ָ��д�뵽������
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 12: {
		cout << "\n����\t";
		DIRECTORY(false);
		for (int count = 150, arrcount = 0; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count) {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 13: {
		cout << "\n����\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 0; count <= 150; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "��") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 0; count <= 150; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "Ů") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 14: {
		cout << "\n����\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 150; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "��") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 150; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "Ů") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 21: {
		cout << "\n���\t";
		DIRECTORY(false);
		for (int count = 0, arrcount = 0; count <= 120; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count) {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 22: {
		cout << "\n���\t";
		DIRECTORY(false);
		for (int count = 120, arrcount = 0; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count) {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 23: {
		cout << "\n���\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 0; count <= 120; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "��") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 0; count <= 120; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "Ů") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 24: {
		cout << "\n���\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 120; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "��") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 120; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "Ů") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	}
	cout << "\n�Ƿ�ά�ִ�˳��1.�� 0.��" << endl;
	if (choose(0, 1)) {
		cout << "�޸���******" << endl;
		int count = 0;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++, count++) {		//����
			*line = arr[count];		//�������е�ָ��д��list�У��𵽶�list�е�ָ�����������
		}
		cout << "�޸ĳɹ�******" << endl;
	}
	free(arr);
	return;
}
int List::nodeinfo(const char* mode)		//����һ��node.size() ,���ڻ�ȡѧ��������
{
	if (strcmp(mode, "size") == 0) {
		return (int)this->node.size();
	}
	return 0;
}