#include<iostream>
using namespace std;
#include<string>
#define MAX 1000 //�������


        //��ʾ�˵� showmenu
void showmenu() {
	cout << "************************\n"
		<< "****  1.�����ϵ��  ****\n"
		<< "****  2.��ʾ��ϵ��  ****\n"
		<< "****  3.ɾ����ϵ��  ****\n"
		<< "****  4.������ϵ��  ****\n"
		<< "****  5.�޸���ϵ��  ****\n"
		<< "****  6.�����ϵ��  ****\n"
		<< "****  0.�˳�ͨѶ¼  ****\n"
		<< "************************\n"
		<< endl;
}

//��ϵ�˽ṹ
struct person {
	string name;   //����
	int sex;    //�Ա� 1�� 2Ů
	int age;       //����
	string number;    //��ϵ�绰
	string address;//��ͥסַ
};

//ͨѶ¼�ṹ
struct addressbook {
	//ͨѶ¼�б������ϵ�˵�����
	struct person personarr[MAX];
	//ͨѶ¼�б������ϵ�˵ĸ���
	int size;
};



//�����ϵ�˺���
void addperson(addressbook* abs) {
         //�ж�ͨѶ¼�Ƿ�����
	if (abs->size == MAX) {
	
		cout << "ͨѶ¼����" << endl;
		system("pause");
		return;
	
	}
	else {

		string name;
		cout << "��ϵ��������";
		cin >> name;              //��������
		abs->personarr[abs->size].name = name; //��������ӵ�ͨѶ¼

		//�Ա�
		cout << "��ϵ���Ա�\n" << "1.��  2.Ů  " << endl;
		int sex;
		cin >> sex;
		// ��������Ƿ�Ϊ1��2���������ʱ��������
		while (true) {
			if (sex == 1 || sex == 2)
			{
				abs->personarr[abs->size].sex = sex;
				break;
			}
			else { 
				cout << "��������ȷ��ֵ��" << endl;
				cin >> sex; }
		}
		//����
		cout << "��ϵ�����䣺";
		int age;
		cin >> age;
		abs->personarr[abs->size].age = age;
		//����
		cout << "��ϵ���룺";
		string number;
		cin >> number;
		abs->personarr[abs->size].number = number;
		//סַ
		cout << "��ͥסַ��";
		string address;
		cin >> address;
		abs->personarr[abs->size].address = address;
		//����ͨѶ¼����
		abs->size++;

		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//����
	}


}
//��ʾ������ϵ��
void showperson(addressbook * abs) {
	if (abs->size == 0) {
			cout << "����û�б������ϵ��" << endl;
			system("pause");
			system("cls");
	}
	else
	{
		for (int i = 0; i < abs->size; i++) 
		{
			cout << "������  " << abs->personarr[i].name << "\t"
				<< "�Ա�  " << (abs->personarr[i].sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺  " << abs->personarr[i].age << "\t"
				<< "��ϵ���룺" << abs->personarr[i].number << "\t"
				<< "��ͥסַ:" << abs->personarr[i].address << endl;
			
		}

		system("pause");
		system("cls");
	}
	


}

//�����ϵ���Ƿ����
int searchperson(addressbook * abs , string name) 
{
	for (int i = 0; i < abs->size; i++) 
	{
		if (abs->personarr[i].name == name)
		{
			return i;//������ ������ϵ����������λ�ñ��
		}
		return -1;//������ ���� -1
	
	}

}

//ɾ����ϵ��

void deletperson(addressbook* abs) {

	{cout << "��������Ҫɾ������ϵ�����֣� " << endl;
	string d_name;
	cin >> d_name;
	int i = searchperson(abs, d_name);
	if (i == -1)
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else {

		cout << "�ҵ��ˣ� \n" << "������  " << abs->personarr[i].name << "\t"
			<< "�Ա�  " << (abs->personarr[i].sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺  " << abs->personarr[i].age << "\t"
			<< "��ϵ���룺" << abs->personarr[i].number << "\t"
			<< "��ͥסַ:" << abs->personarr[i].address << endl;
		cout << "ȷ��ɾ����\n"
			<< "1.ȷ�� 2.ȡ��" << endl;
		int r;
		cin >> r;
		if (r != 1 && r != 2) {
			cout << "��������ȷ��ֵ:  " << endl;
			cin >> r;
		}

		else if (r == 1) {
			for (int n = i; n < abs->size; n++) {
				abs->personarr[n] = abs->personarr[n + 1];//����ǰ�� ���ǵ�Ҫɾ��������
				abs->size--;
				cout << "ɾ���ɹ�" << endl;
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

//������ϵ��
void findperson(addressbook * abs ){
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string f_name;
	cin >> f_name;
	int i = searchperson(abs, f_name);
	if (i == -1)
	{
		cout << "δ�ҵ���ϵ��" << endl;
		

	}
	else {
		cout << "�ҵ���ϵ�ˣ� \n" << "������  " << abs->personarr[i].name << "\t"
			<< "�Ա�  " << (abs->personarr[i].sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺  " << abs->personarr[i].age << "\t"
			<< "��ϵ���룺" << abs->personarr[i].number << "\t"
			<< "��ͥסַ:" << abs->personarr[i].address << endl;
	
	}
	system("pause");
	system("cls");

}

//�޸���ϵ��
void reviseperson(addressbook* abs) {
	cout << "��Ҫ�޸ĵ���ϵ��������" << endl;
	string s_name;
	cin >> s_name;
	int i = searchperson(abs, s_name);
	if (i == -1)
	{
		cout << "δ�ҵ���ϵ��" << endl;


	}
	else {
	
		cout << "��ϵ��������";
		string name;
		cin >> name;              
		abs->personarr[i].name = name; 

		
		cout << "��ϵ���Ա�\n" << "1.��  2.Ů  " << endl;
		int sex;
		cin >> sex;
		
		while (true) {
			if (sex == 1 || sex == 2)
			{
				abs->personarr[i].sex = sex;
				break;
			}
			else {
				cout << "��������ȷ��ֵ��" << endl;
				cin >> sex;
			}
		}
		
		cout << "��ϵ�����䣺";
		int age;
		cin >> age;
		abs->personarr[i].age = age;
		
		cout << "��ϵ���룺";
		string number;
		cin >> number;
		abs->personarr[i].number = number;
		
		cout << "��ͥסַ��";
		string address;
		cin >> address;
		abs->personarr[i].address = address;
		cout << "�޸����" << endl;
	}


	system("pause");
	system("cls");


}


//�����ϵ��
void clearperson(addressbook* abs) {
	cout << "ȷ��Ҫ�����ϵ����" << endl;
	cout << "1.ȷ�� 2.ȡ��"<<endl;
	int i;
	cin >> i;
		if (i != 1 && i != 2) {
			cout << "��������ȷ��ֵ:  " << endl;
			cin >> i;
		}

		else if (i == 1) {
			abs->size = 0;
			cout << "ͨѶ¼�����" << endl;
				system("pause");
				system("cls");
			}
		else if (i == 2) {
			system("cls");
		}
	


}



int main()
{
	//����ͨѶ¼
	addressbook abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.size = 0;

	while (true) {        //ֻ��0�˳� ��������ѭ��
		showmenu();
		int in;
		cin >> in;     //����
		//switch���ʵ�ֶ�ѡ���֧��Ҳ����if...else��
		switch (in)
		{
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1://�����ϵ��
			addperson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletperson(&abs);

			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			reviseperson(&abs);

			break;
		case 6://�����ϵ��
			clearperson(&abs);
			break;

		default:

			break;
		}
	}
	system ("pause");
	return 0;
}
