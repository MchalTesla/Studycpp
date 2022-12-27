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
constexpr int modelength = sizeof("ģ") - 1;
using namespace std;

class Node;
class List;

bool Filtration(string& ch);
int choose(int left, int right);
string cinstr(int left, int right);
int GCD(int men, int women);
void DIRECTORY(bool enter);
void pause();
int begin();		//������
void Statistics(List& list);
void Engsort(List& list);
void Agesort(List& list);

class Node {		//Node����
public:
	bool add(list<Node*>& node, List& list, bool find);
	void putstu();
	int year;		//����������
	int month;
	int day;
	string gender;		//�Ա� 
	int age;		//����  
	int english;	//Ӣ��ɼ� 
	string address;	//��ͥ��ַ 
	string specialized;	//רҵ 
	string name;		//���� 
	string stunum;	//ѧ�� 
};

class List {		//List�Ķ���
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