// Major_task_criminal_system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct Crime {
	string name;
	int id = 0;
	string crime;
	string officer;

};

string login();
int printOptions();
void addCrime(Crime[]);
void deleteCrime(Crime[]);
void updateCrime(Crime[]);
void search_by_id(Crime[], string);
void search_by_name(Crime[], string);
void display_all(Crime[]);




int main()
{
	Crime criminals[100] = { {"Marwan", 1, "vandalism", "officer1"}, {"Yehia", 2, "murder", "officer2"},
							{"Habil", 3, "thief", "officer1"}, {"Omar", 4, "dealer", "officer2"},                         //creating dummy variables
							{"Mark", 5, "fraud", "officer1"} };
	string userName;     //initializing a string to save username

label:
	userName = login();
	if (userName == "terminate") {                 //for logging in and sees if user tried to login more than 3 times and if so shuts programs
		return 0;
	}

	while (true) {
		int num = 0;

		num = printOptions();



		if (userName == "admin" && num == 1) {
			addCrime(criminals);

		}


		if (userName == "admin" && num == 2) {
			deleteCrime(criminals);

		}


		if (userName == "admin" && num == 3) {
			updateCrime(criminals);

		}

		if (userName == "admin" && num == 4) {
			display_all(criminals);
		}

		if ((userName == "officer1" || userName == "officer2") && (num == 1 || num == 2 || num == 3 || num == 4)) {       //check if officer and tried doing admin commands
			cout << "Access Denied\n";

		}


		if (num == 5) {
			search_by_id(criminals, userName);
		}


		if (num == 6) {
			search_by_name(criminals, userName);
		}



		if (num == 7) {
			cout << "Logging out\n";         //logging out and returning to the begining of program
			goto label;
		}


		if (num == 8) {
			cout << "Exiting program\n";          //exiting the program
			return 0;
		}

	}
	

}



string login()
{
	int loginAttempt = 0;
	string userName;                                  //initializing a string to save username
	string userPassword;                              //initializing a string to save password
	while (loginAttempt < 3)                          // while loop to exit after 3 wrong attempts
	{


		cout << "Please enter your username: ";
		cin >> userName;                                   // Enter username
		cout << "Please enter your user password: ";
		cin >> userPassword;                               // Enter password

		if (userName == "admin" && userPassword == "omar")         //condition to compare entry
		{
			cout << "\n\nWelcome admin!\n";
			break;
		}
		else if (userName == "officer1" && userPassword == "marwan")    // condition to compare entry
		{
			cout << "\n\nWelcome officer1!\n";
			break;
		}
		else if (userName == "officer2" && userPassword == "yehia") {   // condition to compare entry

			cout << "\n\nWelcome officer2!\n";
			break;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n";
			loginAttempt++;
		}
	}
	if (loginAttempt == 3)                                          // condition for wrong attempts
	{
		cout << "Too many login attempts! The program will now terminate.";
		return "terminate";
	}

	cout << "\nThank you for logging in.\n";
	return userName;

}


int printOptions()
{
	int num = 0;
	while (!(num > 0 && num <= 8)) {              //number of command must be in range from 1 to 8

		cout << "\n________________________________\nSelect an operation\n";
		cout << "1: Add crime\n";
		cout << "2: Delete crime\n";
		cout << "3: Update a crime\n";
		cout << "4: display all criminals\n";
		cout << "5: search for a criminal by id\n";
		cout << "6: Search for a criminal by name\n";
		cout << "7: Log out\n";
		cout << "8: Exit program\n________________________________\n";
		cin >> num;
	}
	return num;

}
void addCrime(Crime criminals[])
{
	int i = 0;                                   
	while (true) {                                           //loop to find the first vacant place in the array to store the new criminal in and store its index in i
		if (criminals[i].id == 0) {                     
			break;
		}
		i++;
	}
	cout << "\nEnter name: ";
	cin >> criminals[i].name;

	
	bool correct_id = true;                              
	while (correct_id) {                                           //loop to check if the criminal id is already assigned to another criminal or id equal 0 
		                                                           //and if so user enters another id
		correct_id = false;
		cout << "Enter a unique id and id can't be 0: ";
		cin >> criminals[i].id;                                                       
		for (int x = 0; x < i; x++) {
			if ((criminals[x].id == criminals[i].id) || (criminals[i].id == 0)) {
				correct_id = true;
				break;
			}
		}

	}
	cout << "enter description of crime: ";
	cin >> criminals[i].crime;


	while (criminals[i].officer != "officer1" && criminals[i].officer != "officer2") {           //loop to check if name of officer entered correctly

		cout << "which officer in charge (type 'officer1' or 'officer2'):  ";
		cin >> criminals[i].officer;
	}

	cout << "\n\ncriminal was saved successfully! \n ";
}


void deleteCrime(Crime criminals[])
{
	int id;                                      //variable to store id entered by user 
	int k = 0;
	cout << "Enter crime id \n";
	cin >> id;

	while (criminals[k].id != 0) {                                      //loop to find the criminal and store its index in k
		if (criminals[k].id == id) {
			break;
		}
	k++;
	}
	if (criminals[k].id == 0) {
		cout << "\n\ncriminal was not found";                                 // reached the last criminal and criminal not found
	}
	else                                                                       // criminal found
	{

		while (criminals[k].id != 0) {
			criminals[k].name = criminals[k + 1].name;                          //loop to delete the criminal and shifts position of every criminal after him 1 place backwards
			criminals[k].id = criminals[k + 1].id;
			criminals[k].crime = criminals[k + 1].crime;
			k++;
		}
		cout << "\n\nCrime deleted successfully! ";
	}

}


void updateCrime(Crime criminals[])
{
	int id;                                //variable to store id entered by user
	int unum;                              // variable to store which field to update
	int x = 0;
	cout << "Enter crime id \n";
	cin >> id;
	while (criminals[x].id != 0) {                                       //loop to find the criminal and store its index in x
		if (criminals[x].id == id) {
			break;
		}
		x++;
	}
	if (criminals[x].id == 0) {         
		cout << "\n\ncriminal was not found";                                 // reached the last criminal and criminal not found
	}
	else                                                                     // criminal found
	{

		cout << "Select which field to update\n";                      
		cout << "1:Name\n";
		cout << "2:id\n";
		cout << "3:crime\n";
		cout << "4:officer in charge\n";
		cin >> unum;
		if (unum == 1) {
			cout << "Name: ";
			cin >> criminals[x].name;
		}
		else if (unum == 2) {

			bool correct_id = true;
			while (correct_id) {                                    //loop to check if the criminal id is already assigned to another criminal or id equal 0 
																    //and if so user enters another id							
				correct_id = false;
				cout << "Enter a unique id and id can't be 0: ";
				cin >> criminals[x].id;
				for (int z = 0; z < x; z++) {
					if ((criminals[z].id == criminals[x].id) || (criminals[x].id == 0)) {
						correct_id = true;
						break;
					}
				}

			}
		}
		else if (unum == 3) {
			cout << "crime: ";
			cin >> criminals[x].crime;
		}
		else if (unum == 4) {
			while (criminals[x].officer != "officer1" && criminals[x].officer != "officer2") {

				cout << "which officer in charge (type 'officer1' or 'officer2'):  ";
				cin >> criminals[x].officer;
			}
		}
		cout << "\n\nCrime updated successfully! ";

	}
}
void search_by_id(Crime criminals[], string userName)
{

	int j = 0;
	int id;
	cout << "search criminal by id: ";
	cin >> id;
	while (criminals[j].id != 0) {
		if (criminals[j].id == id) {
			break;
		}
		j++;

	}
	if (criminals[j].id == 0) {
		cout << "\n\ncriminal was not found";

	}
	else {

		if (userName == "admin" || userName == criminals[j].officer) {
			cout << "\n\nName: " << criminals[j].name << endl;
			cout << "\nid: " << criminals[j].id << endl;
			cout << "\nCrime: " << criminals[j].crime << endl;
			cout << "\nofficer in charge: " << criminals[j].officer << endl;
		}
		else {
			cout << "\n\ncriminal is assigned to another officer access denied!";
		}
	}

}
void search_by_name(Crime criminals[], string userName)
{

	int z = 0;
	string cname;
	cout << "\nsearch criminal by name: ";
	cin >> cname;
	while (criminals[z].id != 0) {
		if (criminals[z].name == cname) {
			break;
		}
		z++;
	}
	if (criminals[z].id == 0) {
		cout << "\n\ncriminal was not found";
	}
	else {

		if (userName == "admin" || userName == criminals[z].officer) {
			cout << "\n\nName: " << criminals[z].name << endl;
			cout << "\nid: " << criminals[z].id << endl;
			cout << "\ncrime: " << criminals[z].crime << endl;
			cout << "\nofficer in charge: " << criminals[z].officer << endl;
		}
		else {
			cout << "\n\ncriminal is assigned to another officer access denied!";
		}
	}

}

void display_all(Crime criminals[])
{
	int i = 0;
	cout << "Name" << setw(20) << "Criminal id"<< setw(20) << "crime" << setw(20) << "officer" << endl;
	while (criminals[i].id != 0) {
		cout << i + 1 << " " << criminals[i].name << setw(20) << criminals[i].id << setw(20) << criminals[i].crime << setw(20) << criminals[i].officer << endl;
		i++;
	}

}

