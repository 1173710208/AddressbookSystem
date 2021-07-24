#include<iostream>
#include<string>
using namespace std;

#define MAX 1000//做多保存一千人

//联系人结构体
struct Person {
	string m_Name;
	int m_Sex;//1 man 2 women
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;//当前有多少人;
};

//展示菜单
void showMenu();
//添加联系人
void addPerson(Addressbooks* ads);
//显示联系人
void showPerson(Addressbooks* ads);
//检测联系人是否存在 return数组下标i
int isExist(Addressbooks* ads, string name);
//删除联系人
void deletePerson(Addressbooks* ads);
//查找联系人
void findPerson(Addressbooks* ads);
//修改联系人
void modifyPerson(Addressbooks* ads);
//修改联系人
void clearPerson(Addressbooks* ads);

int main() {

	Addressbooks ads;
	ads.m_Size = 0;

	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
		{
			addPerson(&ads);
			break; 
		}
		case 2://显示联系人
		{
			showPerson(&ads);
			break;
		}
		case 3://删除联系人
		{
			deletePerson(&ads);
			break;
		}
		case 4://查找联系人
		{
			findPerson(&ads);
			break;
		}
		case 5://修改联系人
		{
			modifyPerson(&ads);
			break;
		}
		case 6://清空联系人
		{
			clearPerson(&ads);
			break;
		}
		case 0://退出通讯录
		{
			cout << "欢迎您下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
		}
	}


	system("pause");
	return 0;
}

//展示菜单
void showMenu()
{
	cout << "**********************" << endl;
	cout << "**** 1.添加联系人 ****" << endl;
	cout << "**** 2.显示联系人 ****" << endl;
	cout << "**** 3.删除联系人 ****" << endl;
	cout << "**** 4.查找联系人 ****" << endl;
	cout << "**** 5.修改联系人 ****" << endl;
	cout << "**** 6.清空联系人 ****" << endl;
	cout << "**** 0.退出通讯录 ****" << endl;
	cout << "**********************" << endl;
}
//添加联系人
void addPerson(Addressbooks* ads) {
	if (ads->m_Size == MAX) {
		cout << "通讯录已满，无法添加"<<endl;
	}
	else {
		//姓名
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		ads->personArray[ads->m_Size].m_Name = name;
		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1 man" << endl;
		cout << "2 woman" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				ads->personArray[ads->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请输入1或者2" << endl;
			}
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		ads->personArray[ads->m_Size].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ads->m_Size].m_Phone= phone;
		//地址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		ads->personArray[ads->m_Size].m_Addr = address;
		//新增人数
		ads->m_Size++;
		cout << "new successful" << endl;
		system("pause");
		system("cls");
		
	}

}
//显示联系人
void showPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "当前通讯录没有人" << endl;
	}
	else {
		for (int i = 0; i < ads->m_Size; i++) {
			cout << ads->personArray[i].m_Name<<"\t" << (ads->personArray[i].m_Sex == 1 ? "男" : "女") << "\t" << ads->personArray[i].m_Age << "\t" << ads->personArray[i].m_Phone << "\t"<< ads->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在 return数组下标i
int isExist(Addressbooks* ads, string name) {
	for (int i = 0; i < ads->m_Size; i++) {
		if (ads->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "当前通讯录没有人" << endl;
		return;
	}
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret!=-1) {
		for (int i = ret; i < ads->m_Size; i++) {
			ads->personArray[i] = ads->personArray[i + 1];
		}
		ads->m_Size--;
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
//查找联系人
void findPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "当前通讯录没有人" << endl;
		return;
	}
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1) {
		cout << ads->personArray[ret].m_Name << endl;
		cout << (ads->personArray[ret].m_Sex==1?"男":"女") << endl;
		cout << ads->personArray[ret].m_Age << endl;
		cout << ads->personArray[ret].m_Phone << endl;
		cout << ads->personArray[ret].m_Addr<< endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
//修改联系人
void modifyPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "当前通讯录没有人" << endl;
		return;
	}
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(ads, name);
	if (ret != -1) {
		//姓名
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		ads->personArray[ret].m_Name = name;
		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1 man" << endl;
		cout << "2 woman" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				ads->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请输入1或者2" << endl;
			}
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		ads->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		ads->personArray[ret].m_Phone = phone;
		//地址
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		ads->personArray[ret].m_Addr = address;
		system("pause");
		system("cls");
	}
	else {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
//修改联系人
void clearPerson(Addressbooks* ads) {
	if (ads->m_Size == 0) {
		cout << "当前通讯录没有人" << endl;
		return;
	}
	cout << "您确定要清空" << endl;
	cout << "1 确定" << endl;
	cout << "0 取消" << endl;
	cout << "您确定要清空" << endl;
	int confirm;
	cin >> confirm;
	if (confirm == 1) {
		ads->m_Size = 0;
		cout << "已清空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "已取消清空" << endl;
		system("pause");
		system("cls");

	}
}