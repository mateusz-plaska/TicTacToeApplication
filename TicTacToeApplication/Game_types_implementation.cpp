#include "Game_types_implementation.h"
#include "Implementing_algorithms.h"
#include "Game_display.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

char* create_board()
{
	char* board = new char[9];
	for (int i = 0; i <= 8; ++i)
		board[i] = ' ';
	return board;
}

void two_players(char &starting_char)
{
	Display game_display;
	Tcontact_with_the_user field_number_text;

	char* board = create_board();
	char player_turn_char = starting_char;

	while (1)
	{
		game_display.clear_screen();
		game_display.print_headline();
		game_display.print_subheadings_and_choose_level(2);

		print_board(board);

		if (check_possible_win(board, 'O'))
		{
			cout << endl << endl << "\t\tPlayer 'O' wins!" << endl << endl;
			break;
		}
		if (check_possible_win(board, 'X'))
		{
			cout << endl << endl << "\t\tPlayer 'X' wins" << endl << endl;
			break;
		}
		if (check_possible_draw(board))
		{
			cout << endl << endl << "\t\tDraw!" << endl << endl;
			break;
		}

		cout << "\t\tPlayer '" << player_turn_char << "' move, enter field number (1-9)  :  ";

		try
		{
			field_number_text.load_number();
		}
		catch (Tinvalid_char& ex)
		{
			cout << ex.what() << endl;
			cout << endl << setw(36) << "Enter chosen number again" << endl << endl;
			system("pause");
			continue;
		}

		int field_number = stoi(field_number_text.str());
		
		if (field_number < 1 || field_number > 9 || board[field_number - 1] != ' ')
		{
			std::cout << std::endl << std::setw(49) << "Incorrect number. Enter chosen numer again" << endl << endl;
			system("pause");
			continue;
		}

		board[field_number - 1] = player_turn_char;
		player_turn_char == 'O' ? player_turn_char = 'X' : player_turn_char = 'O';
	}

	starting_char == 'O' ? starting_char = 'X' : starting_char = 'O';
}

int computer_turn_easy(char* board)
{
	srand(time(NULL));

	int field_number;
	while (1)
	{
		field_number = rand() % 9 + 1;
		if (board[field_number - 1] != ' ')
			continue;
		break;
	}
	return field_number;
}

int computer_turn_medium(char* board, bool if_draw_turn, char computer_char)
{
	if (if_draw_turn)
		return computer_turn_easy(board);
	return computer_turn_hard(board, computer_char);
}

int computer_turn_hard(char* board, char computer_char)
{
	int field_number;
	int max_profit = -10;
	for (int i = 0; i <= 8; ++i)
	{
		if (board[i] != ' ')
			continue;
		board[i] = computer_char;
		int current_profit = minimax(board, computer_char, computer_char);
		board[i] = ' ';
		if (current_profit > max_profit)
		{
			max_profit = current_profit;
			field_number = i + 1;
		}
	}
	return field_number;
}

void one_player_game(bool& if_player_starts, char player_char, string subheading, short level)
{
	char computer_char;
	player_char == 'O' ? computer_char = 'X' : computer_char = 'O';

	Display game_display;
	Tcontact_with_the_user field_number_text;

	char* board = create_board();
	bool if_player_turn = if_player_starts;
	bool if_draw_turn = true;

	while (1)
	{
		game_display.clear_screen();
		game_display.print_headline();
		cout << "\t" << subheading << endl << endl; 

		print_board(board);

		if (check_possible_win(board, player_char))
		{
			cout << endl << endl << "\t\tYou win!" << endl << endl;
			break;
		}
		if (check_possible_win(board, computer_char))
		{
			cout << endl << endl << "\t\tComputer wins!" << endl << endl;
			break;
		}
		if (check_possible_draw(board))
		{
			cout << endl << endl << "\t\tDraw!" << endl << endl;
			break;
		}

		if (if_player_turn)
		{
			cout << "\t\tYour turn, enter field number (1-9)  :  ";

			try
			{
				field_number_text.load_number();
			}
			catch (Tinvalid_char& ex)
			{
				cout << ex.what() << endl;
				cout << endl << setw(36) << "Enter chosen number again" << endl << endl;
				system("pause");
				continue;
			}

			int field_number = stoi(field_number_text.str());

			if (field_number < 1 || field_number > 9 || board[field_number - 1] != ' ')
			{
				std::cout << std::endl << std::setw(49) << "Incorrect number. Enter chosen numer again" << endl << endl;
				system("pause");
				continue;
			}

			board[field_number - 1] = player_char;
		}
		else
		{
			cout << "\t\tComputer turn, wait";
			Sleep(2000);

			int field_number;
			if (level == 1)
				field_number = computer_turn_easy(board);
			else if (level == 2)
				field_number = computer_turn_medium(board, if_draw_turn, computer_char);
			else if (level == 3)
				field_number = computer_turn_hard(board, computer_char);

			board[field_number - 1] = computer_char;
		}
		if_player_turn = !if_player_turn;
		if_draw_turn = !if_draw_turn;
	}

	if_player_starts = !if_player_starts;
}