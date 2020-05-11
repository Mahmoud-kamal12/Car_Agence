#include <iostream>
#include<fstream>
#include <string>
#include"Person.h"
using namespace std;
string convertToString(char* a, int size)
{
	string s = a;
	return s;
}
int main()
{
	int op, m, f = 0;
	string SearchWord;
	char deletWord[30], userN[50], pass[50], buycar[50];

	Person* ptr = nullptr, person;	Admins admin;	users use;	Car car;

	cout << "\t\t\t*************************************************\n" << "\t\t\t\t     Welcome To Car Agence \n" << "\t\t\t*************************************************\n\n";

	do
	{
		op = 0;
		cout << "\t\t\t\t1-) Admin.\n";
		cout << "\t\t\t\t2-) Customer.\n";
		cout << "Enter Your Choice  ( 1 - 2 ): ";
		cin >> op;	system("cls");
		switch (op)
		{
		case 1:
			ptr = &admin;		// Polymorphism
			cout << "\t\t\t\t1-) Add Account.\n";
			cout << "\t\t\t\t2-) Login.\n";
			cout << "Enter Your Choice  ( 1 - 2 ): ";
			cin >> op;	system("cls");
			if (op == 1)
			{
				do
				{
					cout << "\t\t\t\t1-) Enter user name.\n";		cin.ignore();	cin.getline(userN, 50, '\n');	person.setuser(userN);
					cout << "\t\t\t\t2-) Enter Password.\n";		cin.getline(pass, 50, '\n');	person.setpass(pass);
					ptr->addaccount(person);

					cout << "\n+ To add another account, enter (\" 2 \")  Enter 0 To continue : ";		cin >> op;	system("cls");
				} while (op == 2);
			}
			else if (op == 2)
			{
				cout << "\t\t\t\t1-) Enter user name.\n";		cin.ignore();	cin.getline(userN, 50, '\n');	person.setuser(userN);
				cout << "\t\t\t\t2-) Enter Password.\n";		cin.getline(pass, 50, '\n');	person.setpass(pass);
				if (ptr->check(person))
				{
					do
					{
						cout << "\t\t\t\t1-) Add Car.\n";
						cout << "\t\t\t\t2-) Delet Car.\n";
						cout << "\t\t\t\t3-) Show Car.\n";
						cout << "\t\t\t\t4-) UpDate Car.\n";
						cout << "\t\t\t\t4-) Show All Cars\n\n\n";
						cout << "Enter Your Choice  ( 1 - 5 ): ";
						cin >> op;	system("cls");
						if (op == 1)
						{
							ptr->addCar(car);
						}
						else if (op == 2)
						{
							ptr->showall();
							cout << "+ Enter model to delet it : ";  cin.ignore(); cin.getline(deletWord, 30, '\n');
							int a_size = sizeof(deletWord) / sizeof(char);
							string Word = convertToString(deletWord, a_size);
							ptr->DeletCar(Word);
						}
						else if (op == 3)
						{
							cout << "+Enter Maker to  Show models and there information (\" honda \") : ";		cin >> SearchWord;
							ptr->Search(SearchWord, f);
						}
						else if (op == 4)
						{
							ptr->showall();
							cout << "+ Enter model to update it : ";  cin.ignore(); cin.getline(deletWord, 30, '\n');
							int a_size = sizeof(deletWord) / sizeof(char);
							string Word = convertToString(deletWord, a_size);
							ptr->updataCar(Word, car);
						}
						else if (op == 5)
						{
							ptr->showall();
						}
						else { cout << "\n\t\t+++++++++++ Enter a valid number ++++++++++++++ \n" << endl; }

						cout << "\n+ To return to the previous list (\" 2 \") Enter 0 to continue : ";		cin >> op;	system("cls");

					} while (op == 2);
				}
				else { cout << "\n\t\t++++++++++++ Password or user name wrong +++++++++++++\n" << endl; }
			}
			else { cout << "\n\t\t+++++++++++++++++++ Enter a valid number +++++++++++++++++++++++++\n " << endl; }
			break;
		case 2:
			ptr = &use;		// Polymorphism
			cout << "\t\t\t\t1-)  Add Account.\n";
			cout << "\t\t\t\t2-) Login.\n";
			cout << "Enter Your Choice  ( 1 - 2 ): ";
			cin >> op;	system("cls");
			if (op == 1)
			{
				do
				{
					cout << "\t\t\t\t1-) Enter user name.\n";		cin.ignore();	cin.getline(userN, 50, '\n');	person.setuser(userN);
					cout << "\t\t\t\t2-) Enter Password.\n";		cin.getline(pass, 50, '\n');	person.setpass(pass);

					ptr->addaccount(person);

					cout << "\n+ To add another account, enter (\" 2 \") Enter 0 To continue : ";		cin >> op;		system("cls");
				} while (op == 2);
			}
			else if (op == 2)
			{
				cout << "\t\t\t\t1-) Enter user name.\n";		cin.ignore();	cin.getline(userN, 50, '\n');	person.setuser(userN);
				cout << "\t\t\t\t2-) Enter Password.\n";		cin.getline(pass, 50, '\n');	person.setpass(pass);

				if (ptr->check(person))
				{
					do
					{
						cout << "\t\t\t\t1-) Search in Agence to buy.\n";
						cout << "\t\t\t\t2-) Show All Cars.\n";
						cout << "\t\t\t\t3-) To Show Order List.\n";
						cout << "Enter Your Choice  ( 1 - 3 ): ";
						cin >> op;	system("cls");
						if (op == 1)
						{
							do
							{
								cout << "+ Enter Maker to  Show models and there information (\" Honda \") : ";		cin >> SearchWord;

								ptr->Search(SearchWord, f);
								if (f != 0) {
									cout << "\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
									cout << "\t\t\t\t1-) Buy.\n";
									cout << "\t\t\t\t2-) Search again.\n";
									cout << "\t\t\t\t3-) To continue.\n";
									cout << "Enter Your Choice  ( 1 - 3 ): ";
									cin >> m;
									if (m == 1)
									{
										cout << "\n Enter Model Name : ";	cin.ignore();	cin.getline(buycar, 50);
										ptr->Buy(buycar, person);
										cout << "\n+ To Search Again Enter 2 Enter 0 to continue : ";		cin >> op;			system("cls");
									}
									else if (m == 2)
									{
										op = 2;
									}
									else if (m == 3)
									{
										op = 0;
									}
									else
									{
										cout << "\n\t\t++++++++++++++++++++++ Enter a valid number +++++++++++++++++++++++++++++++\n" << endl;
									}
								}
								else 
								{
									cout << "\n+ To Search Again Enter 10 Enter 2 bedore : ";		cin >> op;			system("cls");
								}

							} while (op == 10 );
						}
						else if (op == 2)
						{
							ptr->showall();
							cout << "\t\t\t\t1-) Buy.\n";
							cout << "\t\t\t\t2-) Search again.\n";
							cout << "\t\t\t\t3-) To continue.\n";
							cout << "Enter Your Choice  ( 1 - 3 ): ";
							cin >> m;
							if (m == 1)
							{
								cout << "\n Enter Model Name : ";	cin.ignore();	cin.getline(buycar, 50);
								ptr->Buy(buycar, person);
								cout << "\n+ To Search Again Enter 2 Enter 0 to continue : ";		cin >> op;			system("cls");
							}
							else if (m == 2)
							{
								op = 2;
								system("cls");
							}
							else if (m == 3)
							{
								op = 0;
								system("cls");
							}
							else
							{
								cout << "\n\t\t++++++++++++++++++++++ Enter a valid number +++++++++++++++++++++++++++++++\n" << endl;
							}
						}
						else if (op == 3)
						{

							ptr->orderList(person);
							cout<<"+ To return to the previous list enter 2 to continue 0 : ";		cin >> op;			system("cls");
						}
						else { cout << "\n\t\t++++++++++++++++++++++ Enter a valid number +++++++++++++++++++++++++++++++\n" << endl; }
					} while (op == 2);
					

				}
				else { cout << "\n\t\t++++++++++++++ Password or user name wrong +++++++++++++++++++++\n"; }
			}
			else { cout << "\n+ Enter a valid number \n" << endl; }
			break;
		default:
			cout << "\n\t\t++++++++++++++++++ Enter a Valid Number +++++++++++++++++++++++\n " << endl;
			break;
		}
		cout << "\n+ To return to the main menu enter (\" 3 \") Enter 0 To Exit : ";	cin >> op;		if (op == 3) { system("cls"); }
	} while (op == 3);

	return 0;
}