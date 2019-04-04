#include"Vector.h"

Vector::Vector(int size)
{
	buf_size = size;
	cur_size = 0;
	els = new int[buf_size];
}

Vector::Vector(int size, int value)
{
	cur_size = buf_size = size;
	els = new int[buf_size];
	for (int i = 0; i < cur_size; i++)
		els[i] = value;
}

Vector::Vector(const Vector & obj)
{
	this->buf_size = this->cur_size = obj.cur_size;
	this->els = new int[buf_size];
	for (int i = 0; i < cur_size; i++)
		this->els[i] = obj.els[i];
}

Vector::~Vector()
{
	cout << "Destructor" << endl;
	delete[] els; //явно прописываем деструктор
}

void Vector::push_back(int el)
{
	if (buf_size == 0) {
		buf_size = 4;
		els = new int[buf_size];
	}
	else {
		if (cur_size == buf_size)
			buf_size *= 2;
		int *tmp = new int[buf_size];
		for (int i = 0; i < cur_size; i++)
			tmp[i] = els[i];
		delete[] els;
		els = tmp;
	}
	els[cur_size++] = el;
}

void Vector::insert_by_position(int el, int pos)
{
	int*tmp;
	if (buf_size == 0) {
		push_back(el);
	}
	else {
		if (cur_size == buf_size)
			buf_size *= 2;

		tmp = new int[buf_size];
		for (int i = 0; i < cur_size + 1; i++) {
			if (i < pos) {
				tmp[i] = els[i];
			}
			else if (i == pos)
				tmp[i] = el;
			else {
				tmp[i] = els[i-1];
			}
		}
		delete[] els;
		els = tmp;
		cur_size++;
	}
}

void Vector::erase_by_position(int pos)
{
	for (int i = pos; i < cur_size; i++)
		els[i] = els[i + 1];

	cur_size--;
}

void Vector::edit_by_position(int pos) //работает по типу сеттера
{
	cout << "Enter new value" << endl;
	cin >> els[pos];

}

int Vector::at(int pos) //работает по типу геттера
{
	return els[pos];
}

int Vector::size() //as getter for cur_size to run by array in the programme
{
	return cur_size;
}

void Vector::print()
{
	for (int i = 0; i < cur_size; i++)
		cout << els[i] << " ";
	cout << endl;
}

