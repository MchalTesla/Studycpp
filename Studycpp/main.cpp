#include <iostream>
#include "main.h"

int main()
{
	string filename = "student1.txt";
	List list;
	list.readfile(filename);
	while (list.state) {
		system(cls);
		switch (begin()) {
		case 1:				//刷新学生信息 
			list.show();
			break;
		case 2:				//新增学生信息 
			list.buildlist();
			break;
		case 3:				//删除学生信息 
			list.deletestu();
			break;
		case 4:				//学生信息搜索 
			list.search();
			break;
		case 5:				//学生信息编辑 
			list.editstu();
			break;
		case 6:				//学生信息统计 	 
			Statistics(list);
			break;
		case 7:				//导入学生信息
			list.import();
			break;
		case 8:				//保存学生信息
			list.savefile(filename, false);
			break;
		case 9:				//清空学生信息
			list.close(1);
			cout << "清空成功" << endl;
			break;
		case 0:				//退出 
			cout << "1.保存后退出 2.不保存直接退出 3.取消" << endl;
			switch (choose(1, 3)) {
			case 1:
				if (list.savefile(filename, false) || (cout << "是否继续（1.是 0.否）", (choose(0, 1) == 1 ? list.savefile(filename,true), true : false))) {
					list.close(0);		//用于提示链表为空以及判断文件是否正确写入
				}
				break;
			case 2:
				if (cout << "确认不保存退出（1.确认 0.取消）" << endl, choose(0, 1)) {
					list.close(0);
				}
				break;
			case 3:
				break;
			}
			break;
		}
		pause();	//按 Enter 继续
	}
	return 0;
}