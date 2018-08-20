/*
Copyright (C) 2018  Mehmet ÖZGÜN

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#define print(x) std::cout << "\t\t\t" << x << "\n" << std::endl
#define printn(x) std::cout << x << std::endl
#define input(x) std::cin >> x
#define pause system("pause")
#define clearscreen system("cls")
using namespace std;
short cityid;
bool quit;
template < typename c>
void certificate(c cid)
{
	

	short ds;
	vector<string> certificates;
	std::string fname = std::to_string(cid) + ".cert";

	ifstream load;
	load.open(fname.c_str());

	load >> ds;
	string d;
	for (int i = 0; i <= (ds - 1); i++)
	{

		load >> d;

		certificates.push_back(d);

	}

	load.close();
	
	if (certificates.size() > 0)
	{
		print("certificates");
		for (int i = 0; i < certificates.size(); i++)
		{
			print(certificates[i]);
		}
	}
	else
	{
		print("These disease information are NOT Certificated. The correctness of information is UNKNOWN");
	}
	
	pause;
	
	
}
template <typename v>
void showdisease(v cid)
{
	clearscreen;
	short bc;
	bool breakloop = false;
	short ds;
	vector<string> diseases;
	std::string fname = std::to_string(cid) + ".cityreport";

	ifstream load;
	load.open(fname.c_str());

	load >> ds;
	string d;
	for (int i = 0; i <= (ds - 1); i++)
	{

		load >> d;

		diseases.push_back(d);

	}


	print("Biggest diseases in current city");
	for (int i = 0; i < diseases.size(); i++)
	{
		print(diseases[i]);
	}
	load.close();
	
	print("would you like to view certificates ? y/n");
	do
	{
		switch (_getch())
		{
		case 'y':
		{
			certificate(cityid);
			breakloop = true;
		} break;
		case 'n':
		{
			breakloop = true;
			/// return to main menu
		} break;
		} // switch
		
	} while (!breakloop);
	if (_kbhit())
	{

	
	}
	

}

bool login()
{
	short a;
	short b;

	lstart:
	printn("-----Welcome to DTS(Disease Tracking System). Please login with the password your local hospital gave you------");
	input(a);

	ifstream yukle;
	yukle.open("pass.userpass");

	yukle >> b;
	yukle.close();
	if (b == a)
	{
		printn("Enter your city id:");
		input(cityid);

		return true;

	}
	else if (b != a)
	{
		
		printn("incorrect password !");
		pause;
		system("cls");
		goto lstart;

	}
	pause;


}
void mainmenu()
{
	
	print("Disease Tracking System v1.0");
	print("Press 'S' Show diseases in current city");
	print("Press 'Q' to exit the program");
	print("Press 'R' to re-enter the city id");
	print("Press 'C' to credits");

	/// would you like to use number or character mode ?

		switch (_getch())
		{
		case 's':
		{

			showdisease(cityid);

		} break;
		case 'q':
		{
			quit = true;
		} break;
		case 'r':
		{
			print("Enter your city id:");
			input(cityid);
		} break;
		case 'c':
		{
			print("Copyright (C) 2018 Mehmet ÖZGÜN (Mehmet OZGUN)");
			pause;
		} break;
		} // switch
	
	
}

int main()
{
	if (login() == true)
	{
		while (!quit)
		{
			clearscreen;
			mainmenu();
		}
	

	}




}
