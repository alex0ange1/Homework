// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <string.h>

using namespace std;

//����������� ��� ������, ����� ������ - ��������� �� ������ ������ ������ ��� ���
enum StatusEr
{
	OK, Err
};

//�������� ������ �����
class Companys
{
public:
	Companys(string name, int schet, string owner, int num_employees, int oborot); // ����������� - ������ ������, ����, ��� � ��� ��������, ������� ���� ��� ��������, 
											  // ��� ��� �������, ��� �� ����� ���� ����� � ������ �������, ����������, � ������� ����� � ��� ��������
	Companys() { Status = Err; }				  // ����������� �� ��������� - ����������� ��� ������ � ����������� - ����� ������ ��� �������� ������������� �������, 
											  // ������� �� ����� ������������ � ������ �������!
	~Companys();
//�������/��������� - ������ �������� �������� (����, �������������� �������)
	string getname();
	int getschet();
	string getowner();
	int getnum_employees();
	int oborot();
// �����������
	bool getStatus(); //������ ��� ������ ������ � ������ - ������, � ����� �� � ��� ��������
//�������/������������ - ���������� (��������) �������� �������� (����, �������������� �������), ���� ��� ���������
	bool set_owner(string o); //����� ����� ��������� ���
	bool set_down_employees(int v); //����� ����� ��������� ���
	bool set_up_employees(int v); //����� ����� ��������� ���
	bool set_down_oborot(int v); //����� ����� ��������� ���
	bool set_up_oborot(int v); //����� ����� ��������� ���
//��������
	void make_a_product();    // ����� ����
	void sell_a_product(); // ����� ������� 
	void print(); //����� ���������� � ���������� �������, � ���������� ����� �������� �� ���������� ���������� ������!

private:
	string Poroda;
	int YearBirth;
	int Ves;
	string Color;
	string Name;
	int Status; //� ����� �� � ������ ��������, ��� ���� ������� ������������ ���������

	bool ChangeVes(int v); //��������� ����� ������, ���������� �����! ������ ��� ����, ����� ������ ������� ��������� �� ������������ ������� �������� ��� �����
};

//����������
Companys::Companys(string p, string cl, int v, int yb)
{
	if (p == "" || cl == "" || v <= 0 || yb <= 0) //������ ������������ �������� ����� - ������ ����� ������ �� �������� ������, ����� ������ ���� ��� ������������
		Status = Err;
	else {
		Poroda = p;
		YearBirth = yb;
		Ves = v;
		Color = cl;
		Name = "���������� ���";
		Status = OK; // �� � �������, ����� �������
	}
}

Companys::~Companys()
{
}

string Companys::getPoroda()
{
	return Poroda;
}

int Companys::getYearBirth()
{
	return YearBirth;
}

int Companys::getVes()
{
	return Ves;
}

string Companys::getColor() 
{
	return Color;
}

string Companys::getName()
{
	return Name;
}

bool Companys::getStatus()
{
	return Status;
}


bool Companys::ChangeVes(int v)
{
	int tmpV = Ves + v;
	bool result = (tmpV >= 0); //�� ����� � ����� ���� ������������� ���
	if (result) Ves = tmpV; // ��� ������� ������������� � ��������� �� �������� v
	return result; // ��� �� ���������, � ����� ������ ����
}

bool Companys::setUpVes(int v) //����� ����� ��������� ���
{
	if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ���������� ���� �������� ��� ����������
		return false;
	else return ChangeVes(v);
}

bool Companys::setDownVes(int v) //����� ����� ��������� ���
{
	if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ����������� ���� �������� ��� ����������
		return false;
	else return ChangeVes(-v);
}

bool Companys::setName(string nm) //����� ���� ���, ��� �������� ���
{
	if (nm  == "")   // ������ ���� ����� ������ ���
		return false;
	else { 
		Name = nm;
		return true;
	}
	
	
}

void Companys::Go()    // ����� ����. 
{
		cout << Name.c_str() << " ����� ������\n";
		cout << "@  \n";
		cout << "   @\n";
		cout << "@  \n";
		cout << "   @\n";
}

void Companys::Voice() // ����� �������. 
{
		cout << Name.c_str() <<" ������ " << "M-r-r-r!\n";
}

void Companys::Print() // ����� ���������� � ���������� ������� ������ �����. ������� ����� ���������� ������ � ���������� �����
{
		cout << "\n��������� ������ �����: " << "��� - " << Name.c_str() << ", ������ - " << Poroda.c_str() << ",\n";
		cout << "��� �������� - " << YearBirth << ", ��� - " << Ves << ".\n";
		cout << "�� ��, � ���� ������� - " << Color.c_str() << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//����������� ��������� �����
	cout << "������� 1-� ������ ����� � ���������� � ���\n"; 
	Companys Company1("", "", -3, 2016); // ������� ��������� ������ �����, �� ������ �������� �������� ���
	//�������� � ��� ����������
	if (Company1.getStatus() != OK) // ������ ��� ������ ������ � �������� ��������� - ������ �� ��� ��� 
	{
		cout << "����� �� �������!\n";
	}
	else {
		Company1.setName("������");
		Company1.Print();
		Company1.Voice();
		Company1.Go();
		if (Company1.setDownVes(-5))
			cout << Company1.getName().c_str() << " ������� �� " << Company1.getVes() << "��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Company1.getName().c_str() << "!\n";
	}
	
	
	cout << "\n������� 2-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Companys Company2("����", "�����", 2, 2015);

	if (Company2.getStatus() != OK) // ������ ��� ������ ������ � �������� ��������� - ������ �� ��� ��� 
	{
		cout << "����� �� �������!\n";
	}
	else {
		Company2.setName("������");
		Company2.Print();
		Company2.Voice();
		Company2.Go();
		int StepV; //��� ��������� ����

		StepV = -1; //�������� �� �����, �� �� ���������
		if (Company2.setDownVes(StepV))
			cout << Company2.getName().c_str() << " ������� �� " << Company2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� "<< Company2.getName().c_str() << "!\n";
		StepV = 1;//�������� �� ����� ���������
		if (Company2.setDownVes(StepV))
			cout << Company2.getName().c_str() << " ������� �� " << Company2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Company2.getName().c_str() << "!\n";

		StepV = -1; // ����� �������, �� �� ���������
		if (Company2.setUpVes(StepV))
			cout << Company2.getName().c_str() << " ���������� �� " << Company2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Company2.getName().c_str() << "!\n";
		StepV = 1; //������ ���������
		if (Company2.setUpVes(StepV))
			cout << Company2.getName().c_str() << " ���������� �� " << Company2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Company2.getName().c_str() << "!\n";
	}

	cout << "\n������� 3-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Companys Company3("������", "�����", 3, 2001);

	if (Company3.getStatus() != OK) // ������ ��� ������ ������ � �������� ��������� - ������ �� ��� ��� 
	{
		cout << "����� �� �������!\n";
	} 
	else Company3.Print();

	//� ������ ��� ����� ����� ���-�� ������ ������!
	cout << "\n\n � ������ ��� ����� ����� ���-�� ������ ������!\n\n";
	Companys* lCompanys;
	lCompanys = new Companys[3];
	
	lCompanys[0] = Company1;
	lCompanys[1] = Company2;
	lCompanys[2] = Company3;

	for (int i = 0; i < 3; i++ )  // ���� ����������� ����� �������, ��� ���� ����� ������ �����������, �� ������� � ��� ������ ������
		if (lCompanys[i].getStatus() == OK)
		{
			lCompanys[i].Voice();
			lCompanys[i].Go();
		}

	system("pause");
    return 0;
}
