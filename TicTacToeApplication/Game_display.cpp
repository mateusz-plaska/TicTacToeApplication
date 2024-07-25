#include "Game_display.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <locale.h>

using namespace std;

int Display::bufferinfo(int& width, int& height)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbi);
	width = csbi.dwSize.X;
	height = csbi.dwSize.Y;

	return 0;
}

void Display::clear_screen()
{
	system("cls");
}

void Display::print_headline()
{
	int width_console, height_console;
	string headline("TIC TAC TOE GAME");

	bufferinfo(width_console, height_console);
	cout << setw((40 + width_console) / 2) << "***************************************" << endl;
	cout << setw((headline.length() + width_console) / 2) << headline << endl;
	cout << setw((40 + width_console) / 2) << "***************************************" << endl << endl;
}

void Display::print_menu()
{
	cout << R"(
    Game :
    1) 1-player
    2) 2-players
    0) Exit 
        Choice : )";
}

int Display::print_subheadings_and_choose_level(int index)
{
	Tcontact_with_the_user selected_level_text;
	int selected_level;

	switch (index)
	{
		case 1:
		{
			while (1)
			{
				clear_screen();
				print_headline();

				cout << R"(
	Level :
	1) Easy
	2) Medium
	3) ProHard
	0) Back to menu 
		Choice : )";

				try
				{
					selected_level_text.load_number();
				}
				catch (Tinvalid_char& ex)
				{
					std::cout << ex.what() << std::endl;
					std::cout << std::endl << std::setw(36) << "Enter chosen number again" << endl << endl;
					system("pause");
					continue;
				}

				selected_level = stoi(selected_level_text.str());

				if (selected_level < 0 || selected_level > 3)
				{
					std::cout << std::endl << std::setw(49) << "Incorrect number. Enter chosen numer again" << endl << endl;
					system("pause");
					continue;
				}
				break;
			}
			
			return selected_level;
		}
		case 2:
		{
			clear_screen();
			print_headline();
			cout << "\t* 2 players game" << endl << endl;
			return 4;
		}
	}
}

void Display::print_thanks_for_using()
{
	cout << endl << endl << endl<< "\tThanks for playing :)" << endl << endl;
}