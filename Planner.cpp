// Planner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
//getline(ifs, str);
//std::string option;
//std::cin >> option;
void displayHomework()
{
}
void addHomework()
{
}
void removeHomework()
{
}
void addClass()
{
}
void openSettings()
{
}

int main()
{
	std::cout << "What Pick Operation to Preform:";
	std::cout <<
		"[1] = Display Homework"
		"[2] = Add Homework"
		"[3] = Remove Homework"
		"[4] = Add Class"
		"[5] = Open Settings";
	short option;
	std::cin >> option;

	switch(option)
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
		openSettings();
		break;
	default:
		std::cout << "Please Enter a Valid Number";
		break;
	}
    return 0; 
}

