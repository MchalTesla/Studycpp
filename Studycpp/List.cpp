#include <iostream>
#include <fstream>
#include <iomanip>
#include "main.h"
using namespace std;

//List类的实现
bool List::buildlist()		//创建节点
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
bool List::findrepeat(string& tname)		//寻找重复节点
{
	for (list<Node*>::iterator line = this->node.begin(); line != node.end(); line++) {		//通过迭代器进行遍历
		if ((*line)->stunum == tname) {		//判断是否有重复的学号
			return true;
		}
	}
	return false;
}
void List::show()		//遍历节点
{
	if (this->node.size() != 0) {
		DIRECTORY(true);
		for (list<Node*>::iterator line = this->node.begin(); line != node.end(); line++) {		//遍历
			(*line)->putstu();		//putustu()函数可以输出整个节点的数据
		}
	}
	else {
		cout << "无数据" << endl;
	}
	cout << endl;
}
void List::search()			//搜索数据
{
	if (this->node.size() == 0) {
		cout << "无数据" << endl;
		return;
	}
	cout << "请输入要查询学生的学号或者姓名，输入“0”退出" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是学号还是姓名
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//学号执行
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				return;
			}
		}
	}
	else {
		bool state = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//姓名执行
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
	cout << "没有此学生" << endl;
	return;
}
void List::editstu()		//编辑数据
{
	if (this->node.size() == 0) {
		cout << "无数据" << endl;
		return;
	}
	cout << "请输入编辑学生的学号或者姓名,输入“0”返回" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是学号还是姓名
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//学号执行
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				cout << "确认修改？（1.确认 0.取消）" << endl;
				if (choose(0, 1)) {
					bool state = (*line)->add(this->node, *this, false);
					DIRECTORY(true);
					(*line)->putstu();
					if(state) cout << "修改成功" << endl;
				}
				return;
			}
		}
	}
	else {
		bool state = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//姓名执行
			if ((*line)->name == TNAME) {
				state = true;
				DIRECTORY(true);
				(*line)->putstu();
				cout << "确认修改？（1.确认 0.取消）" << endl;
				if (choose(0, 1)) {
					bool state = (*line)->add(this->node, *this, false);
					DIRECTORY(true);
					(*line)->putstu();
					if(state) cout << "修改成功" << endl;
				}
			}
		}
		if (state == true) {		//如果成功进行了一次修改，则结束函数
			return;
		}
	}
	cout << "没有此学生" << endl;
	return;
}
void List::deletelist(list<Node*>::iterator& itor)		//protected 删除节点
{
	delete(*itor);
	this->node.erase(itor);
	return;
}
void List::deletestu()		//删除学生数据
{
	if (this->node.size() == 0) {
		cout << "无数据" << endl;
		return;
	}
	cout << "请输入需要删除学生的学号或者姓名,输入“0”返回" << endl;
	string TNAME;
	cin >> TNAME;
	flushstd;
	if (TNAME == "0") {
		return;
	}
	if (strspn(TNAME.data(), "0123456789") == TNAME.length()) {		//判断输入的是学号还是姓名
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//学号执行
			if ((*line)->stunum == TNAME) {
				DIRECTORY(true);
				(*line)->putstu();
				cout << "确认删除？（1.确认 0.取消）" << endl;
				if (choose(0, 1)) {
					this->deletelist(line);
					cout << "删除成功" << endl;
				}
				return;
			}
		}
	}
	else {
		bool state = false;
		_delete_1:
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//姓名执行
			if ((*line)->name == TNAME) {
				state = true;
				DIRECTORY(true);
				(*line)->putstu();
				cout << "确认删除？（1.确认 0.取消）" << endl;
				if (choose(0, 1)) {
					this->deletelist(line);
					cout << "删除成功" << endl;
					goto _delete_1;
				}
			}
		}
		if (state == true) {	//如果成功删除了一次，则结束函数
			return;
		}
	}
	cout << "没有此学生" << endl;
	return;
}
void List::close(int mode)		//关闭
{
	for (list<Node*>::iterator line = node.begin(); line != node.end(); line++) {	//将所有new出来的对象都delete
		delete(*line);
	}
	list<Node*>().swap(this->node);		//清空list
	if (mode == 0) { this->state = false; }		//判断是否需要结束程序，如果mode=0，则将List中的state设置为false，表示程序要停止
	return;
}
void List::import()		//文件导入
{
	cout << "请将需要导入的文件拖入此处:";
	string filename;
	cin >> filename;		//将文件拖入到命令栏中会自动输入文件的位置，使用这种方法可以进行文件导入
	flushstd;
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) {		//判断文件是否可以打开
		cout << "文件不存在" << endl;
	}
	else if (infile.get(), infile.eof()) {
		cout << "文件内无数据" << endl;
	}
	else {
		infile.seekg(ios::beg);
		while (infile.get(), !infile.eof()) {		//进行文件是否读取完毕判断
			infile.seekg(-1, ios::cur);
			Node* temp = new Node;
			if (infile >> temp->stunum >> temp->name >> temp->gender >> temp->age \
				>> temp->year >> temp->month >> temp->day >> temp->specialized \
				>> temp->english >> temp->address, infile.fail() || infile.get() != 10)		//对文件的读取进行正确性判断，判断是否读取错误
			{
				cout << "文件无法导入" << endl;
				delete temp;
				return;
			}
			else if (this->findrepeat(temp->stunum)) {delete temp; }
			else { this->node.push_back(temp); }
		}
		infile.close();
		cout << "文件导入成功" << endl;
return;
	}
}
void List::readfile(string& filename)	//文件读取
{
	if (!this->can_open(filename)) {		//判断文件是否可以打开
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
		while (infile.get(), !infile.eof()) {	//进行文件是否读取完毕判断
			infile.seekg(-1, ios::cur);
			Node* temp = new Node;

			if (infile >> temp->stunum >> temp->name >> temp->gender >> temp->age \
				>> temp->year >> temp->month >> temp->day >> temp->specialized \
				>> temp->english >> temp->address, infile.fail() || infile.get() != 10)		//对文件的读取进行正确性判断，判断是否读取错误
			{
				cout << "文件无法导入" << endl;
				delete temp;
				this->close(0);		//如果读入失败，则会关闭程序
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
	if (this->node.size() == 0 && !force) {		//判断链表中是否有属于
		cout << "无数据" << endl;
		return false;
	}
	else if (!this->can_open(filename)) {		//判断文件是否可以打开
		return false;
	}
	else {
		ofstream tmpfile;
		tmpfile.open(".tmpfile");
		bool error = false;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {	//对文件的写入进行正确性判断，判断是否读取错误
			tmpfile << (*line)->stunum << ' ' << (*line)->name << ' ' << (*line)->gender << ' ' << (*line)->age \
				<< ' ' << (*line)->year << ' ' << (*line)->month << ' ' << (*line)->day << ' ' << (*line)->specialized \
				<< ' ' << (*line)->english << ' ' << (*line)->address << endl;
			error = tmpfile.fail();
		}
		tmpfile.close();
		if (!error) {
			remove(filename.data());
			if (rename(".tmpfile", filename.data()) == 0) {
				cout << "保存成功" << endl;
				return true;
			}
		}
		cout << "保存失败" << endl;
		return false;
	}

}
bool List::can_open(string& filename)		//进行文件是否可以正确打开判断
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) {
		cout << filename << "不存在" << endl;
		cout << "是否创建一个新的" << filename << "（1.是 0.否）" << endl;
		if (choose(0, 1)) {
			ofstream tempfile;
			tempfile.open(filename);
			if (tempfile.is_open()) {
				cout << "文件创建成功\n" << endl;
				tempfile.close();
				return true;
			}
			else {
				cout << "文件创建失败\n" << endl;
			}
		}
		return false;
	}
	else {
		infile.close();
		return true;
	}
}
void ::List::SexRatio()		//性别统计
{
	int men = 0, women = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		if ((*line)->gender == "男") {
			men++;
		}
		else if ((*line)->gender == "女"){
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
	cout << "男生人数 = " << men << "    女生人数 = " << women << endl;
	cout << "男女生比例 = " << men / numgcd << " : " << women / numgcd << endl;
	return;
}
void List::OverEnglisg()		//统计多少人的英语成绩超过了某一值
{
	cout << "请输入统计多少分及以上的学生" << endl;
	int score = choose(0, 150);
	int num = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		if ((*line)->english >= score) {
			num++;
		}
	}
	cout << "有" << num << "位学生超过" << score << "分," << "占比约为" \
		<< fixed << setprecision(2) << ((double)num / this->node.size()) * 100 << "%" << endl;
	return;
}
void List::AVG()		//统计学生的英语平均分
{
	int allscore = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		allscore += (*line)->english;
	}
	cout << "总分=" << allscore << ",平均分=" << fixed << setprecision(2) << (double)allscore / this->node.size() << endl;
}
void List::Variance()		//统计学生的英语成绩的方差
{
	int allscore = 0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		allscore += (*line)->english;	//首先判断总分
	}
	double avg = (double)allscore / this->node.size();
	double var = 0.0;
	for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
		var += ((double)(*line)->english - avg) * ((double)(*line)->english - avg);		//接着进行方差计算
	}
	cout << "方差 = " << fixed << setprecision(2) << var / this->node.size() << endl;
}
void List::Sortlist(int mode)	//11:eu;12:ed;13:esu;14:esd;21:au;22:ad;23:asu;24:asd;	多种模式的排序
{
	Node** arr = (Node**)malloc(sizeof(Node*) * this->node.size());		//创建一个和节点数量一样多的指针型的数组，用于进行基数排序
	switch (mode) {
	case 11: {
		cout << "\n排名\t";
		DIRECTORY(false);
		for (int count = 0, arrcount = 0; count <= 150; count++) {		//count累加
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {		//遍历
				if ((*line)->english == count) {		//如果某一个学生的分数等于count，则将他的指针写入到数组中
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 12: {
		cout << "\n排名\t";
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
		cout << "\n排名\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 0; count <= 150; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "男") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 0; count <= 150; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "女") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 14: {
		cout << "\n排名\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 150; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "男") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 150; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->english == count && (*line)->gender == "女") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 21: {
		cout << "\n序号\t";
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
		cout << "\n序号\t";
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
		cout << "\n序号\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 0; count <= 120; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "男") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 0; count <= 120; count++) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "女") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	case 24: {
		cout << "\n序号\t";
		DIRECTORY(false);
		int arrcount = 0;
		for (int count = 120; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "男") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		cout << endl;
		for (int count = 120; count >= 0; count--) {
			for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++) {
				if ((*line)->age == count && (*line)->gender == "女") {
					arr[arrcount++] = *line;
					cout << arrcount << "\t";
					(*line)->putstu();
				}
			}
		}
		break;
	}
	}
	cout << "\n是否维持此顺序（1.是 0.否）" << endl;
	if (choose(0, 1)) {
		cout << "修改中******" << endl;
		int count = 0;
		for (list<Node*>::iterator line = this->node.begin(); line != this->node.end(); line++, count++) {		//遍历
			*line = arr[count];		//将数组中的指针写回list中，起到对list中的指针排序的作用
		}
		cout << "修改成功******" << endl;
	}
	free(arr);
	return;
}
int List::nodeinfo(const char* mode)		//返回一个node.size() ,用于获取学生的数量
{
	if (strcmp(mode, "size") == 0) {
		return (int)this->node.size();
	}
	return 0;
}