#include <string>
#include <cstring>
#include <list>
#define flushstd while (getchar() != '\n')
#ifdef __linux__
#define cls "clear"
#elif _WIN32
#define cls "cls"
#else
#define cls "clear"
#endif
constexpr int modelength = sizeof("模") - 1;
using namespace std;

class Node;
class List;

bool Filtration(string& ch);
int choose(int left, int right);
string cinstr(int left, int right);
int GCD(int men, int women);
void DIRECTORY(bool enter);
void pause();
int begin();		//功能栏
void Statistics(List& list);
void Engsort(List& list);
void Agesort(List& list);

class Node {		//Node定义
public:
	bool add(list<Node*>& node, List& list, bool find);
	void putstu();
	int year;		//出生年月日
	int month;
	int day;
	string gender;		//性别 
	int age;		//年龄  
	int english;	//英语成绩 
	string address;	//家庭地址 
	string specialized;	//专业 
	string name;		//姓名 
	string stunum;	//学号 
};

class List {		//List的定义
protected:
	list<Node*> node;
public:
	bool state = true;
	bool can_open(string& filename);
	int nodeinfo(const char* mode);
	bool findrepeat(string& tname);
	bool buildlist();
	void show();
	void deletestu();
	void deletelist(list<Node*>::iterator& itor);
	void close(int mode);
	void search();
	void editstu();
	void import();
	void readfile(string& filename);
	bool savefile(string& filename, bool force);
	void SexRatio();
	void OverEnglisg();
	void AVG();
	void Variance();
	void Sortlist(int mode);
};