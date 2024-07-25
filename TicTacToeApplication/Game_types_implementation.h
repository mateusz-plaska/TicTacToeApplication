#pragma once

#include <string>

char* create_board();
void two_players(char &pstarting_char);
void one_player_game(bool &if_player_starts, char player_char, std::string subheading, short level);

int computer_turn_easy(char* board);
int computer_turn_medium(char* board, bool if_draw_turn, char computer_char);
int computer_turn_hard(char* board, char computer_char);
