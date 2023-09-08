// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string.h>

using namespace std;

//специальный тип данных, чтобы узнать - правильно ли создан объект класса или нет
enum StatusEr
{
	OK, Err
};

//Описание класса Кошки
class Companys
{
public:
	Companys(string name, int schet, string owner, int num_employees, int oborot); // конструктор - задаем породу, цвет, вес и год рождения, сделать надо при создании, 
											  // так как считаем, что не может быть кошка с пустой породой, бесцветная, с нулевым весом и без возраста
	Companys() { Status = Err; }				  // конструктор по умолчанию - добавляется для работы с указателями - нужен только для создания динамического объекта, 
											  // поэтому не может использовать в других случаях!
	~Companys();
//геттеры/селекторы - узнать значение атрибута (поля, характеристики объекта)
	string getname();
	int getschet();
	string getowner();
	int getnum_employees();
	int oborot();
// специальный
	bool getStatus(); //прежде чем начать работу с кошкой - узнать, а можно ли с ней работать
//сеттеры/модификаторы - установить (изменить) значение атрибута (поля, характеристики объекта), если это разрешено
	bool set_owner(string o); //кошка может увеличить вес
	bool set_down_employees(int v); //кошка может уменьшить вес
	bool set_up_employees(int v); //кошка может уменьшить вес
	bool set_down_oborot(int v); //кошка может уменьшить вес
	bool set_up_oborot(int v); //кошка может уменьшить вес
//действия
	void make_a_product();    // кошка идет
	void sell_a_product(); // кошка мяукает 
	void print(); //вывод информации о конкретном объекте, в дальнейшем лучше заменить на перегрузку операторов вывода!

private:
	string Poroda;
	int YearBirth;
	int Ves;
	string Color;
	string Name;
	int Status; //а можно ли с кошкой работать, или есть неверно определенные параметры

	bool ChangeVes(int v); //служебный метод класса, недоступен извне! Сделан для того, чтобы единым образом проверять на допустимость попытку изменить вес кошки
};

//реализация
Companys::Companys(string p, string cl, int v, int yb)
{
	if (p == "" || cl == "" || v <= 0 || yb <= 0) //заданы недопустимые значения полей - объект будет создан со статусом ошибка, чтобы нельзя было его использовать
		Status = Err;
	else {
		Poroda = p;
		YearBirth = yb;
		Ves = v;
		Color = cl;
		Name = "Безымянный кот";
		Status = OK; // всё в порядке, кошка создана
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
	bool result = (tmpV >= 0); //не может у кошки быть отрицательный вес
	if (result) Ves = tmpV; // вес остался положительным и изменился на величину v
	return result; // вес не изменится, а метод вернет ложь
}

bool Companys::setUpVes(int v) //кошка может увеличить вес
{
	if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо увеличения веса получить его уменьшение
		return false;
	else return ChangeVes(v);
}

bool Companys::setDownVes(int v) //кошка может уменьшить вес
{
	if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо уменьшенияя веса получить его увеличение
		return false;
	else return ChangeVes(-v);
}

bool Companys::setName(string nm) //кошка дали имя, или изменили его
{
	if (nm  == "")   // нельзя дать кошке пустое имя
		return false;
	else { 
		Name = nm;
		return true;
	}
	
	
}

void Companys::Go()    // кошка идет. 
{
		cout << Name.c_str() << " пошел гулять\n";
		cout << "@  \n";
		cout << "   @\n";
		cout << "@  \n";
		cout << "   @\n";
}

void Companys::Voice() // кошка мяукает. 
{
		cout << Name.c_str() <<" сказал " << "M-r-r-r!\n";
}

void Companys::Print() // вывод информации о конкретном объекте класса Кошка. Вывести можно информацию только о правильной кошке
{
		cout << "\nЭкземпляр класса Кошки: " << "Имя - " << Name.c_str() << ", порода - " << Poroda.c_str() << ",\n";
		cout << "год рождения - " << YearBirth << ", вес - " << Ves << ".\n";
		cout << "Ах да, и цвет шёрстки - " << Color.c_str() << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//неправильно созданная кошка
	cout << "Создать 1-й объект кошка и поработать с ней\n"; 
	Companys Company1("", "", -3, 2016); // создаем экземпляр класса Кошка, на задаем неверное значение вес
	//пытаемся с ней поработать
	if (Company1.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	}
	else {
		Company1.setName("Барсик");
		Company1.Print();
		Company1.Voice();
		Company1.Go();
		if (Company1.setDownVes(-5))
			cout << Company1.getName().c_str() << " похудел на " << Company1.getVes() << "кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Company1.getName().c_str() << "!\n";
	}
	
	
	cout << "\nСоздать 2-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	Companys Company2("Перс", "Белый", 2, 2015);

	if (Company2.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	}
	else {
		Company2.setName("Мурзик");
		Company2.Print();
		Company2.Voice();
		Company2.Go();
		int StepV; //шаг изменения веса

		StepV = -1; //посадили на диету, но не правильно
		if (Company2.setDownVes(StepV))
			cout << Company2.getName().c_str() << " похудел на " << Company2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота "<< Company2.getName().c_str() << "!\n";
		StepV = 1;//посадили на диету правильно
		if (Company2.setDownVes(StepV))
			cout << Company2.getName().c_str() << " похудел на " << Company2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Company2.getName().c_str() << "!\n";

		StepV = -1; // стали кормить, но не правильно
		if (Company2.setUpVes(StepV))
			cout << Company2.getName().c_str() << " поправился на " << Company2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Company2.getName().c_str() << "!\n";
		StepV = 1; //кормят правильно
		if (Company2.setUpVes(StepV))
			cout << Company2.getName().c_str() << " поправился на " << Company2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Company2.getName().c_str() << "!\n";
	}

	cout << "\nСоздать 3-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	Companys Company3("Сиамка", "Серая", 3, 2001);

	if (Company3.getStatus() != OK) // прежде чем начать работу с объектом проверяем - создан он или нет 
	{
		cout << "Кошка не создана!\n";
	} 
	else Company3.Print();

	//А теперь все кошки будут что-то делать вместе!
	cout << "\n\n А теперь все кошки будут что-то делать вместе!\n\n";
	Companys* lCompanys;
	lCompanys = new Companys[3];
	
	lCompanys[0] = Company1;
	lCompanys[1] = Company2;
	lCompanys[2] = Company3;

	for (int i = 0; i < 3; i++ )  // Цикл организован таким образом, что если кошка задана неправильно, то сделать с ней ничего нельзя
		if (lCompanys[i].getStatus() == OK)
		{
			lCompanys[i].Voice();
			lCompanys[i].Go();
		}

	system("pause");
    return 0;
}
