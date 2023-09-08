// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

//����������� ��� ������, ����� ������ - ��������� �� ������ ������ ������ ��� ���
enum StatusEr
{
	OK, Err
};

//�������� ������ �����
class Cats
{
public:
	Cats(string p, string cl, int v, int yb); // ����������� - ������ ������, ����, ��� � ��� ��������, ������� ���� ��� ��������, 
											  // ��� ��� �������, ��� �� ����� ���� ����� � ������ �������, ����������, � ������� ����� � ��� ��������
	Cats() { Status = Err; }				  // ����������� �� ��������� - ����������� ��� ������ � ����������� - ����� ������ ��� �������� ������������� �������, 
											  // ������� �� ����� ������������ � ������ �������!
	~Cats();
//�������/��������� - ������ �������� �������� (����, �������������� �������)
	string getPoroda();
	int getYearBirth();
	int getVes();
	string getColor();
	string getName();
// �����������
	bool getStatus(); //������ ��� ������ ������ � ������ - ������, � ����� �� � ��� ��������
//�������/������������ - ���������� (��������) �������� �������� (����, �������������� �������), ���� ��� ���������
	bool setUpVes(int v); //����� ����� ��������� ���
	bool setDownVes(int v); //����� ����� ��������� ���
	bool setName(string nm); //����� ���� ���, ��� �������� ���
//��������
	void Go();    // ����� ����
	void Voice(); // ����� ������� 
	void Print(); //����� ���������� � ���������� �������, � ���������� ����� �������� �� ���������� ���������� ������!

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
Cats::Cats(string p, string cl, int v, int yb)
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

Cats::~Cats()
{
}

string Cats::getPoroda()
{
	if (Status == OK) return Poroda;
	else return "";
}

int Cats::getYearBirth()
{
	if (Status == OK) return YearBirth;
	else return 0;
}

int Cats::getVes()
{
	if (Status == OK) return Ves;
	else return 0;
}

string Cats::getColor() 
{
	if (Status == OK) return Color;
	else return "";
}

string Cats::getName()
{
	if (Status == OK) return Name;
	else return "";
}

bool Cats::getStatus()
{
	return Status;
}


bool Cats::ChangeVes(int v)
{
	int tmpV = Ves + v;
	bool result = (tmpV >= 0); //�� ����� � ����� ���� ������������� ���
	if (result) Ves = tmpV; // ��� ������� ������������� � ��������� �� �������� v
	return result; // ��� �� ���������, � ����� ������ ����
}

bool Cats::setUpVes(int v) //����� ����� ��������� ���
{
	if (Status == OK)
		if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ���������� ���� �������� ��� ����������
			return false;
		else return ChangeVes(v);
	else false;
}

bool Cats::setDownVes(int v) //����� ����� ��������� ���
{
	if (Status == OK) 
		if (v <= 0) //�������� ����������� ������ ������������� ��� ��������� ����, � ��������� ������ ����� ������ ����������� ���� �������� ��� ����������
			return false;
		else return ChangeVes(-v);
	else false;
}

bool Cats::setName(string nm) //����� ���� ���, ��� �������� ���
{
	if (Status == OK)
		if (nm  == "")   // ������ ���� ����� ������ ���
			return false;
		else { 
			Name = nm;
			return true;
		}
	else false;
}

void Cats::Go()    // ����� ����. ������ ����� ������ ���������� ����� (��, ������� �������)
{
	if (Status == OK) {
		cout << Name.c_str() << " ����� ������\n";
		cout << "@  \n";
		cout << "   @\n";
		cout << "@  \n";
		cout << "   @\n";
	}
}

void Cats::Voice() // ����� �������. ������� ����� ������ ���������� ����� (��, ������� �������)
{
	if (Status == OK) {
		cout << Name.c_str() <<" ������ " << "M-r-r-r!\n";
	}
}

void Cats::Print() // ����� ���������� � ���������� ������� ������ �����. ������� ����� ���������� ������ � ���������� �����
{
	if (Status == OK) {
		cout << "\n��������� ������ �����: " << "��� - " << Name.c_str() << ", ������ - " << Poroda.c_str() << ",\n";
		cout << "��� �������� - " << YearBirth << ", ��� - " << Ves << ".\n";
		cout << "�� ��, � ���� ������� - " << Color.c_str() << "\n\n";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//����������� ��������� �����
	cout << "������� 1-� ������ ����� � ���������� � ���\n"; 
	Cats Cat1("", "", -3, 2016); // ������� ��������� ������ �����, �� ������ �������� �������� ���
	//�������� � ��� ����������
		Cat1.setName("������");
		Cat1.Print();
		Cat1.Voice();
		Cat1.Go();
		if (Cat1.setDownVes(-5))
			cout << Cat1.getName().c_str() << " ������� �� " << Cat1.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat1.getName().c_str() << "!\n";

	
	
	cout << "\n������� 2-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Cats Cat2("����", "�����", 2, 2015);

		Cat2.setName("������");
		Cat2.Print();
		Cat2.Voice();
		Cat2.Go();
		int StepV; //��� ��������� ����

		StepV = -1; //�������� �� �����, �� �� ���������
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " ������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� "<< Cat2.getName().c_str() << "!\n";
		StepV = 1;//�������� �� ����� ���������
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " ������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";

		StepV = -1; // ����� �������, �� �� ���������
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " ���������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";
		StepV = 1; //������ ���������
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " ���������� �� " << Cat2.getVes() << " ��. \n";
		else cout << "������ ����� ��� ���������� ���� ���� " << Cat2.getName().c_str() << "!\n";


	cout << "\n������� 3-� ������ ����� � ���������� � ���\n"; // ������� ��������� ������ �����
	Cats Cat3("������", "�����", 3, 2001);

	Cat3.Print();

	//� ������ ��� ����� ����� ���-�� ������ ������!
	cout << "\n\n � ������ ��� ����� ����� ���-�� ������ ������!\n\n";
	Cats* lCats;
	lCats = new Cats[3];
	
	lCats[0] = Cat1;
	lCats[1] = Cat2;
	lCats[2] = Cat3;

	for (int i = 0; i < 3; i++)  
		{
			lCats[i].Voice();
			lCats[i].Go();
		}

	system("pause");
    return 0;
}

