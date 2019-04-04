#include"Vector.h"
#include"function.h"

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector v; //по сути это динамический массив типа Vector, называется v
	v.push_back(100);
	v.push_back(5);
	v.push_back(8);

	int n;
	cout << "Enter n: ";
	cin >> n;
	for (int i = 3; i < n; i++) 
		v.push_back(rand() % 101); // заполнение случайнными числами через метод push_back;

	for (int i = 0; i < v.size(); i++) //v.size=cur_size
		cout << v.at(i) << " "; //v.at(i)=v[i];
	cout << endl;

	Vector v1(v);//v1 точная копия вектора v
	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i) << " ";
	cout << endl;

	menu(v);

	system("pause");
}

