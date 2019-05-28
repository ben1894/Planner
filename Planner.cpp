// Planner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>

void exiting() {
	std::ofstream file{ "Hello.txt" };
}

std::vector<std::vector<std::string>> data;
std::vector<std::string> classes;

//load text file in initially to vextors and then save to it from there. 
//getline(ifs, str);
//std::string option;
//std::cin >> option;
//Start of Classes
//End of Classes Line
//load into 2d vector memory and print over current file every timed
//Start of Print     //replace the first 
//End of Print      


/*
normal.push_back(std::vector<int>());
myvector.erase(myvector.begin() + 5);
myvector.erase(myvector.begin(), myvector.begin() + 3)
myvector.push_back(i);
myVector[i].erase(myVector[i].begin() + columnToDelete);
if (myVector[i].size() > columnToDelete)
*/
void displayClasses();

void storeToVector()
{
}
void updateText()
{
}
void displayHomework()
{
	system("CLS");
	if (classes.size() == 0)
	{
		std::cout << "Nothing to Display\n";
		system("pause");
		return;
	}

	for (int i = 0; i < classes.size(); i++)
	{
		std::cout << classes[i] << "\n";
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << "   " << data[i][j] << "\n";
		}
	}
	std::cout << "\n\n";
	system("pause");
	system("CLS");
}
void addHomework()
{
	if (classes.size() > 0)
	{
		int pickedClass;
		std::string homework;
		displayClasses();
		std::cout << "\nEnter Class Number To Add Homework To:";
		std::cin >> pickedClass;
		std::cout << "Enter Homework:";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, homework);
		data[(pickedClass - 1)].push_back(homework);
	}
	else
	{
		std::cout << "Please Add a Class First\n";
		system("pause");
	}
}
void removeHomework()
{
	int number = 1;
	for (int i = 0; i < classes.size(); i++)
	{
		std::cout << classes[i] << "\n";
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << "   " << number << "." << data[i][j] << "\n";
			number++;
		}
	}
	int removeNumber;
	if (number == 1)
	{
		std::cout << "Please Add Homework First\n";
		system("pause");
		return;
	}
	number = 0;
	std::cout << "Enter Homework Number to Remove:";
	std::cin >> removeNumber;
	removeNumber--;
	for (int i = 0; i < classes.size(); i++)
	{
		std::cout << classes[i] << "\n";
		for (int j = 0; j < data[i].size(); j++)
		{
			if (removeNumber == number)
			{
				data[i].erase(data[i].begin() + j);
			}
			number++;
		}
	}
}
void addClass()
{
	std::cout << "Enter Class Name:";
	std::string newClass;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, newClass);
	data.push_back(std::vector<std::string>());
	classes.push_back(newClass);	
}
void removeClass()
{
	if (classes.size() == 0)
	{
		std::cout << "Please Enter a Class First\n";
		system("pause");
		return;
	}
	displayClasses();
	std::cout << "\n";
	int classNumber;
	std::cin >> classNumber;
	classNumber--;

	if (classNumber > classes.size())
	{
		std::cout << "Please Enter a Valid Class Number\n";
		system("pause");
		return;
	}

	data.erase(data.begin() + classNumber);
	classes.erase(classes.begin() + classNumber);
}

void displayClasses()      //remember to subtract 1 from classes though
{
	for (int i = 0; i < classes.size(); i++)
	{
		std::cout << i+1 << ".";
		std::cout << classes[i] << " ";
	}
}


int main()
{
	std::atexit(exiting);
	while (1)
	{
		std::cout << "What Pick Operation to Preform:\n";
		std::cout <<
			"[1] = Display Homework\n"
			"[2] = Add Homework\n"
			"[3] = Remove Homework\n"
			"[4] = Add Class\n"
			"[5] = Remove Class\n"
			"Selection:";
		short option;
		std::cin >> option;
		system("CLS");
		switch (option)
		{
		case 1:
			displayHomework();
			break;
		case 2:
			addHomework();
			break;
		case 3:
			removeHomework();
			break;
		case 4:
			addClass();
			break;
		case 5:
			removeClass();
			break;
		default:
			system("CLS");
			std::cout << "Please Enter a Valid Number";
			system("pause");
			break;
		}
		system("CLS");
	}
    return 0; 
}
