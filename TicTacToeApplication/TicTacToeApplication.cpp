// CalculatorApplication.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>
#include<locale.h>
#include <iomanip>

#include "Game_display.h"
#include "Tcontact_with_the_user.h"
#include "Tinvalid_char.h"
#include "Game_types_implementation.h"

using namespace std;

void onePlayerGame(Display game_display, Tcontact_with_the_user selected_action_text, char player_char, string game_name);

int main()
{
    system("color 1a");

    Display game_display;
    Tcontact_with_the_user selected_action_text;

    while (1)
    {
        game_display.clear_screen();
        game_display.print_headline();
        game_display.print_menu();

        try
        {
           selected_action_text.load_number();
        }
        catch (Tinvalid_char& ex)
        {
            cout << ex.what() << endl;
            cout << endl << setw(36) << "Enter chosen number again" << endl << endl;
            system("pause");
            continue;
        }

        int selected_action = stoi(selected_action_text.str());
        if (!selected_action)
            break;

        switch (selected_action)
        {
            case 1:
            {
                char player_char;
                while (1)
                {
                    cout << endl << "\tSelect a character 'O' or 'X'  :  ";
                    cin >> player_char;

                    if (!cin.good())
                    {
                        cin.clear();
                        cout << endl << setw(61) << "Given input is not a character! Enter correct character" << endl << endl;
                        continue;
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (player_char != 'O' && player_char != 'X')
                    {
                        cout << endl << setw(54) << "Given character is not correct! Enter 'O' or 'X'" << endl << endl;
                        continue;
                    }
                    break;
                }

                switch (game_display.print_subheadings_and_choose_level(1))
                {
                    case 1:
                    {
                        onePlayerGame(game_display, selected_action_text, player_char, "\t* 1 player game  (Easy)");
                        break;
                    }
                    case 2:
                    {
                        onePlayerGame(game_display, selected_action_text, player_char, "\t* 1 player game  (Medium)");
                        break;
                    }
                    case 3:
                    {
                        onePlayerGame(game_display, selected_action_text, player_char, "\t* 1 player game  (ProHard)");
                        break;
                    }
                    default:
                        break;
                }
                
                break;
            }
            case 2:
            {
                game_display.print_subheadings_and_choose_level(2);

                char starting_char = 'O';

                while (1)
                {
                    two_players(starting_char);

                    while (1)
                    {
                        cout << "\tDo you want to play again? (0 - no, other digits - yes)  :  ";
                        try
                        {
                            selected_action_text.load_number();
                        }
                        catch (Tinvalid_char& ex)
                        {
                            cout << ex.what() << endl;
                            cout << endl << setw(36) << "Enter chosen number again" << endl << endl;
                            system("pause");
                            continue;
                        }
                        break;
                    }
                    
                    if(!stoi(selected_action_text.str()))
                        break;
                }

                break;
            }
            default:
            {
                std::cout << std::endl << std::setw(49) << "Incorrect number. Enter chosen numer again" << endl << endl;
                system("pause");
                break;
            }
        }
    }

    game_display.clear_screen();
    game_display.print_thanks_for_using();

    return 0;
}

void onePlayerGame(Display game_display, Tcontact_with_the_user selected_action_text, char player_char, string game_name)
{
    game_display.clear_screen();
    game_display.print_headline();

    cout << game_name << endl << endl;

    bool if_player_starts = true;

    while (1)
    {
        one_player_game(if_player_starts, player_char, game_name, 2);

        while (1)
        {
            cout << "\tDo you want to play again? (0 - no, other digits - yes)  :  ";
            try
            {
                selected_action_text.load_number();
            }
            catch (Tinvalid_char& ex)
            {
                cout << ex.what() << endl;
                cout << endl << setw(36) << "Enter chosen number again" << endl << endl;
                system("pause");
                continue;
            }
            break;
        }

        if (!stoi(selected_action_text.str()))
            break;
    }
}
