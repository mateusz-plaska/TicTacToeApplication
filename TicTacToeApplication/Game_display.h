#pragma once

class Display
{
public:
	int bufferinfo(int& width, int&height);
	void clear_screen();
	void print_headline();
	void print_menu();
	int print_subheadings_and_choose_level(int index);
	void print_thanks_for_using();
};
