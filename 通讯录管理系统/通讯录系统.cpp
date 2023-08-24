#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //最大人数


        //显示菜单 showmenu
void showmenu() {
	cout << "************************\n"
		<< "****  1.添加联系人  ****\n"
		<< "****  2.显示联系人  ****\n"
		<< "****  3.删除联系人  ****\n"
		<< "****  4.查找联系人  ****\n"
		<< "****  5.修改联系人  ****\n"
		<< "****  6.清空联系人  ****\n"
		<< "****  0.退出通讯录  ****\n"
		<< "************************\n"
		<< endl;
}

//联系人结构
struct person {
	string name;   //名字
	int sex;    //性别 1男 2女
	int age;       //年龄
	string number;    //联系电话
	string address;//家庭住址
};

//通讯录结构
struct addressbook {
	//通讯录中保存的联系人的数组
	struct person personarr[MAX];
	//通讯录中保存的联系人的个数
	int size;
};



//添加联系人函数
void addperson(addressbook* abs) {
         //判断通讯录是否已满
	if (abs->size == MAX) {
	
		cout << "通讯录已满" << endl;
		system("pause");
		return;
	
	}
	else {

		string name;
		cout << "联系人姓名：";
		cin >> name;              //输入姓名
		abs->personarr[abs->size].name = name; //将姓名添加到通讯录

		//性别
		cout << "联系人性别：\n" << "1.男  2.女  " << endl;
		int sex;
		cin >> sex;
		// 检测输入是否为1或2，输入错误时重新输入
		while (true) {
			if (sex == 1 || sex == 2)
			{
				abs->personarr[abs->size].sex = sex;
				break;
			}
			else { 
				cout << "请输入正确数值：" << endl;
				cin >> sex; }
		}
		//年龄
		cout << "联系人年龄：";
		int age;
		cin >> age;
		abs->personarr[abs->size].age = age;
		//号码
		cout << "联系号码：";
		string number;
		cin >> number;
		abs->personarr[abs->size].number = number;
		//住址
		cout << "家庭住址：";
		string address;
		cin >> address;
		abs->personarr[abs->size].address = address;
		//更新通讯录人数
		abs->size++;

		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}


}
//显示所有联系人
void showperson(addressbook * abs) {
	if (abs->size == 0) {
			cout << "您还没有保存过联系人" << endl;
			system("pause");
			system("cls");
	}
	else
	{
		for (int i = 0; i < abs->size; i++) 
		{
			cout << "姓名：  " << abs->personarr[i].name << "\t"
				<< "性别：  " << (abs->personarr[i].sex == 1 ? "男" : "女") << "\t"
				<< "年龄：  " << abs->personarr[i].age << "\t"
				<< "联系号码：" << abs->personarr[i].number << "\t"
				<< "家庭住址:" << abs->personarr[i].address << endl;
			
		}

		system("pause");
		system("cls");
	}
	


}

//检测联系人是否存在
int searchperson(addressbook * abs , string name) 
{
	for (int i = 0; i < abs->size; i++) 
	{
		if (abs->personarr[i].name == name)
		{
			return i;//若存在 返回联系人所在数组位置编号
		}
		return -1;//不存在 返回 -1
	
	}

}

//删除联系人

void deletperson(addressbook* abs) {

	{cout << "请输入你要删除的联系人名字： " << endl;
	string d_name;
	cin >> d_name;
	int i = searchperson(abs, d_name);
	if (i == -1)
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
	else {

		cout << "找到了： \n" << "姓名：  " << abs->personarr[i].name << "\t"
			<< "性别：  " << (abs->personarr[i].sex == 1 ? "男" : "女") << "\t"
			<< "年龄：  " << abs->personarr[i].age << "\t"
			<< "联系号码：" << abs->personarr[i].number << "\t"
			<< "家庭住址:" << abs->personarr[i].address << endl;
		cout << "确定删除吗？\n"
			<< "1.确定 2.取消" << endl;
		int r;
		cin >> r;
		if (r != 1 && r != 2) {
			cout << "请输入正确数值:  " << endl;
			cin >> r;
		}

		else if (r == 1) {
			for (int n = i; n < abs->size; n++) {
				abs->personarr[n] = abs->personarr[n + 1];//数据前移 覆盖掉要删除的数据
				abs->size--;
				cout << "删除成功" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (r == 2) {
			system("cls");
		}

	}



	}
}

//查找联系人
void findperson(addressbook * abs ){
	cout << "输入您要查找的联系人姓名：" << endl;
	string f_name;
	cin >> f_name;
	int i = searchperson(abs, f_name);
	if (i == -1)
	{
		cout << "未找到联系人" << endl;
		

	}
	else {
		cout << "找到联系人： \n" << "姓名：  " << abs->personarr[i].name << "\t"
			<< "性别：  " << (abs->personarr[i].sex == 1 ? "男" : "女") << "\t"
			<< "年龄：  " << abs->personarr[i].age << "\t"
			<< "联系号码：" << abs->personarr[i].number << "\t"
			<< "家庭住址:" << abs->personarr[i].address << endl;
	
	}
	system("pause");
	system("cls");

}

//修改联系人
void reviseperson(addressbook* abs) {
	cout << "你要修改的联系人姓名：" << endl;
	string s_name;
	cin >> s_name;
	int i = searchperson(abs, s_name);
	if (i == -1)
	{
		cout << "未找到联系人" << endl;


	}
	else {
	
		cout << "联系人姓名：";
		string name;
		cin >> name;              
		abs->personarr[i].name = name; 

		
		cout << "联系人性别：\n" << "1.男  2.女  " << endl;
		int sex;
		cin >> sex;
		
		while (true) {
			if (sex == 1 || sex == 2)
			{
				abs->personarr[i].sex = sex;
				break;
			}
			else {
				cout << "请输入正确数值：" << endl;
				cin >> sex;
			}
		}
		
		cout << "联系人年龄：";
		int age;
		cin >> age;
		abs->personarr[i].age = age;
		
		cout << "联系号码：";
		string number;
		cin >> number;
		abs->personarr[i].number = number;
		
		cout << "家庭住址：";
		string address;
		cin >> address;
		abs->personarr[i].address = address;
		cout << "修改完成" << endl;
	}


	system("pause");
	system("cls");


}


//清空联系人
void clearperson(addressbook* abs) {
	cout << "确定要清空联系人吗？" << endl;
	cout << "1.确定 2.取消"<<endl;
	int i;
	cin >> i;
		if (i != 1 && i != 2) {
			cout << "请输入正确数值:  " << endl;
			cin >> i;
		}

		else if (i == 1) {
			abs->size = 0;
			cout << "通讯录已清空" << endl;
				system("pause");
				system("cls");
			}
		else if (i == 2) {
			system("cls");
		}
	


}



int main()
{
	//创建通讯录
	addressbook abs;
	//初始化通讯录当前人员个数
	abs.size = 0;

	while (true) {        //只有0退出 其他按键循环
		showmenu();
		int in;
		cin >> in;     //输入
		//switch语句实现多选择分支（也可以if...else）
		switch (in)
		{
		case 0: //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1://添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			deletperson(&abs);

			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			reviseperson(&abs);

			break;
		case 6://清空联系人
			clearperson(&abs);
			break;

		default:

			break;
		}
	}
	system ("pause");
	return 0;
}
