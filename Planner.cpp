// Planner.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <cstdint>

#include <sstream>

# ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
# endif
# ifndef VC_EXTRALEAN
#   define VC_EXTRALEAN
# endif
# ifndef NOMINMAX
#   define NOMINMAX
# endif
#include <windows.h>

std::string startClass = "zZvc";
std::string endClass = "cZvz";
std::string startHomework = "zZvh";
std::string endHomework = "hZvz";

bool cinInputValidation();
bool cinNumber(int &var, int numberCheck = -10);

void exiting() {
	std::ofstream file{ "Hello.txt" };
}

std::vector<std::vector<std::string>> data;
std::vector<std::string> classes;

void displayClasses();
void storeToVector()
{
	std::ifstream file("saveData.txt");
	std::string temp;
	std::getline(file, temp);
	file.close();
	if (temp == "")
	{
		return;
	}
	std::size_t findClassB = temp.find(startClass);
	std::size_t findHomeworkB = temp.find(startHomework);
	std::size_t findClassE = temp.find(endClass);
	std::size_t findHomeworkE = temp.find(endHomework);
	while (findClassB != -1)
	{
		if ((findHomeworkB < findClassE) && (findHomeworkB != -1))
		{
			std::string classToAdd = temp.substr(findClassB+startClass.size(), (findHomeworkB - findClassB)-endHomework.size());     
			data.push_back(std::vector<std::string>());
			classes.push_back(classToAdd);
			while (findHomeworkE < findClassE)
			{
				std::string homeworkToAdd = temp.substr(findHomeworkB+startClass.size(), (findHomeworkE - findHomeworkB)-endHomework.size());
				data[classes.size()-1].push_back(homeworkToAdd);
				findHomeworkB = temp.find(startHomework,findHomeworkE);
				findHomeworkE = temp.find(endHomework, findHomeworkB);
			}
		}
		else
		{
			std::string classToAdd = temp.substr(findClassB+startClass.size(), (findClassE - findClassB) - endClass.size());  
			data.push_back(std::vector<std::string>());
			classes.push_back(classToAdd);
		}
		findClassB = temp.find(startClass, findClassE);
		findClassE = temp.find(endClass, findClassB);
	}

	
}
void updateTextFile()
{
	std::ofstream testing;
	testing.open("saveData.txt");
	for (int i = 0; i < classes.size(); i++)
	{
		testing << startClass << classes[i];
		for (int j = 0; j < data[i].size(); j++)
		{
			testing << startHomework << data[i][j] << endHomework;
		}
		testing << endClass;
	}
	testing.close();
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
	if (!(classes.size() > 0))
	{
		std::cout << "Please Add a Class First\n";
		system("pause");
		return;
	}
	int pickedClass = 0;
	std::string homework;
	displayClasses();
	std::cout << "\nEnter Class Number To Add Homework To:";
	if(!cinNumber(pickedClass, classes.size()))
	{
		return;
	}
	std::cout << "Enter Homework:";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, homework);
	data[(pickedClass - 1)].push_back(homework);
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
	if (number == 1)
	{
		std::cout << "Please Add Homework First\n";
		system("pause");
		return;
	}
	number = 0;
	std::cout << "Enter Homework Number to Remove:";
	int removeNumber = 0;
	if (!cinNumber(removeNumber))
	{
		return;
	}
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
	std::cout << "\nEnter Class Number to Remove:";
	int classNumber;
	if (!cinNumber(classNumber, classes.size()))
	{
		return;
	}
	
	classNumber--;

	data.erase(data.begin() + classNumber);
	classes.erase(classes.begin() + classNumber);
}

void displayClasses()
{
	for (int i = 0; i < classes.size(); i++)
	{
		std::cout << i+1 << ".";
		std::cout << classes[i] << " ";
	}
}

bool cinNumber(int &var, int numberCheck)
{
	std::cin >> var;
	if (!cinInputValidation())
	{
		system("CLS");
		std::cout << "Please Enter a Valid Input\n";
		system("pause");
		return false;
	}
	if (numberCheck < -9)
	{
		return true;
	}
	else
	{
		if (var > numberCheck)
		{
			system("CLS");
			std::cout << "Please Enter a Valid Selection\n";
			system("pause");
			return false;
		}
	}
	return true;
}



bool cinInputValidation()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

void removeScrollbars()
{
	try {
		HANDLE console2 = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(console2, &csbi);
		COORD scrollbar = {
			csbi.srWindow.Right - csbi.srWindow.Left + 1,
			csbi.srWindow.Bottom - csbi.srWindow.Top + 1
		};

		if (console2 == 0) {
			throw 0;
		}
		else {
			SetConsoleScreenBufferSize(console2, scrollbar);
		}
	}
	catch (...) {
		std::cout << "Error removing scrollbar";
	}
}
int main()
{
	storeToVector();
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 450, 460, TRUE);
	removeScrollbars();
	while (1)
	{
		removeScrollbars();
		std::cout << "Select Operation to Preform:\n";
		std::cout <<
			"[1] = Display Homework\n"
			"[2] = Add Homework\n"
			"[3] = Remove Homework\n"
			"[4] = Add Class\n"
			"[5] = Remove Class\n"
			"Selection:";
		int option = 0;
		if (!cinNumber(option, 5))
		{
			option = 6;
		}
		removeScrollbars();
		system("CLS");
		switch (option)
		{
		case 1:
			displayHomework();
			break;
		case 2:
			addHomework();
			updateTextFile();
			break;
		case 3:
			removeHomework();
			updateTextFile();
			break;
		case 4:
			addClass();
			updateTextFile();
			break;
		case 5:
			removeClass();
			updateTextFile();
			break;
		default:
			break;
		}
		system("CLS");
	}
    return 0; 
}