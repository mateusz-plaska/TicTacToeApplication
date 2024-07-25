#include "Implementing_algorithms.h"
#include <iostream>

using namespace std;
void print_board(char* board)
{
	cout << endl << endl;
	for (int i = 1; i <= 9; ++i)
	{
		if (i == 1 || i == 4 || i == 7)
			cout << "\t\t\t";
		cout << " " << board[i - 1] << " ";
		if (i % 3)
			cout << "|";
		else if (i != 9)
			cout << endl << "\t\t\t" << "---+---+---" << endl;
		else
			cout << endl << endl << endl;
	}
}

bool check_possible_win(char* board, char checked_char)
{
	for (int i = 0; i <= 6; i += 3)
		if (board[i] == checked_char && board[i + 1] == checked_char && board[i + 2] == checked_char)
			return true;

	for (int i = 0; i <= 2; ++i)
		if (board[i] == checked_char && board[i + 3] == checked_char && board[i + 6] == checked_char)
			return true;

	if (board[0] == checked_char && board[4] == checked_char && board[8] == checked_char)
		return true;
	if (board[2] == checked_char && board[4] == checked_char && board[6] == checked_char)
		return true;

	return false;
}

bool check_possible_draw(char* board)
{
	for (int i = 0; i <= 8; ++i)
	{
		if (board[i] == ' ')
			return false;
	}
	return true;
}

int minimax(char* board, char current_turn_char, char computer_char)
{
	if (check_possible_win(board, current_turn_char))
		return current_turn_char == computer_char ? 1 : -1;

	if (check_possible_draw(board))
		return 0;

	current_turn_char == 'O' ? current_turn_char = 'X' : current_turn_char = 'O';

	int max_profit;
	current_turn_char == computer_char ? max_profit = -10 : max_profit = 10;

	for (int i = 0; i <= 8; ++i)
	{
		if (board[i] != ' ')
			continue;

		board[i] = current_turn_char;
		int current_profit = minimax(board, current_turn_char, computer_char);
		board[i] = ' ';

		if ((current_turn_char == computer_char && current_profit > max_profit) || (current_turn_char != computer_char && current_profit < max_profit))
			max_profit = current_profit;
	}
	return max_profit;
}