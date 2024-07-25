#pragma once

void print_board(char* board);
bool check_possible_win(char* board, char checked_char);
bool check_possible_draw(char* board);
int minimax(char* board, char current_turn_char, char computer_char);
