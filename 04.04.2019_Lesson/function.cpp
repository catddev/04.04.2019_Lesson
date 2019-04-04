#include "Vector.h"
#include"function.h"

void menu(Vector v)
{
	int el, n;
	while (true) {
		int choice;
		cout << " Enter 1 to push back" << endl;
		cout << " Enter 2 to insert by position" << endl;
		cout << " Enter 3 to erase by position" << endl;
		cout << " Enter 4 to edit by position" << endl;
		cout << " Enter 5 to print the array" << endl;
		cout << " Enter 0 exit" << endl;
		cin >> choice;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			cout << "Enter new element: ";
			cin >> el;
			v.push_back(el);
			v.print();
			break;
		case 2:
			cout << "Enter new element and its position: ";
			cin >> el >> n;
			v.insert_by_position(el, n);
			v.print();
			break;
		case 3:
			cout << "Enter position to erase: ";
			cin >> n;
			v.erase_by_position(n);
			v.print();
			break;
		case 4:
			cout << "Enter position to edit: ";
			cin >> n;
			v.edit_by_position(n);
			v.print();
			break;
		case 5:
			v.print();
			break;
		}
	}
}