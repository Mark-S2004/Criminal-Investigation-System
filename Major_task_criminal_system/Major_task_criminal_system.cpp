// Major_task_criminal_system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Crime {
	string name;
	int id=0;
	string crime;
	
};
int main()
{
	Crime criminals[4];
	int id;
	string cname;
	
	while (true) {
		int num=0;
		int unum = 0;
		while (!(num > 0 && num <=6)) {

			cout << "Select an operation\n";
			cout << "1: Add crime\n";
			cout << "2: Delete crime\n";
			cout << "3: Update a crime\n";
			cout << "4: View a crime\n";
			cout << "5: Search for a criminal\n";
			cout << "6: Exit program\n";
			cin >> num;
		}
			int i = 0;
			
			if (num == 1) {
				while (true) {
					if (criminals[i].id == 0) {
						break;
					}
					i++;
				}
				cout << "Enter name\n";
				cin >> criminals[i].name;
				cout << "Enter id\n";
				cin >> criminals[i].id;
				cout << "enter description of crime\n";
				cin >> criminals[i].crime;
				
			}
			int k = 0;
			if (num == 2) {
				cout << "Enter crime id \n";
				cin >> id;
				while (true) {
					if (criminals[k].id == id) {
						break;
					}
					k++;
				}
				criminals[k].name = "";
				criminals[k].id = 0;
				criminals[k].crime = "";
				
			}
			int x = 0;
			if (num == 3) {
				cout << "Enter crime id \n";
				cin >> id;
				while (true) {
					if (criminals[x].id == id) {
						break;
					}
					x++;
				}
				cout << "Select which field to update\n";
				cout << "1:Name\n";
				cout << "2:id\n";
				cout << "3:crime\n";
				cin >> unum;
				if (unum == 1) {
					cout << "Name: ";
					cin >> criminals[x].name;
				}
				if (unum == 2) {
					cout << "id: ";
					cin >> criminals[x].id;
				}
				if (unum == 3) {
					cout << "crime: ";
					cin >> criminals[x].crime;
				}

			}
			int j=0;
			if (num == 4) {
				cout <<"Enter crime id \n";
				cin >> id;
				while (true) {
					if (criminals[j].id == id) {
						break;
					}
					j++;
				}
				cout <<"Name:"<< criminals[j].name << endl;
				cout <<"id:"<< criminals[j].id << endl;
				cout <<"Crime:"<< criminals[j].crime << endl;
			}
			int z = 0;
			if (num == 5) {
				cout << "Enter criminal name \n";
				cin >> cname;
				while (true) {
					if (criminals[z].name == cname) {
						break;
					}
					z++;
				}
				cout << "Name: " << criminals[z].name << endl;
				cout << "id: " << criminals[z].id << endl;
				cout << "crime: " << criminals[z].crime << endl;

			}
				
			




			if (num == 6) {
				cout << "Exiting program!";
				break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
