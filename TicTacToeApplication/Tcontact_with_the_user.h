#pragma once

#include <string>

class Tcontact_with_the_user
{
	std::string input_action_as_text;
public:
	Tcontact_with_the_user();

	std::string str();

	void copy(const std::string& original);

	bool check_if_no_error();

	void load_number();

	friend std::istream& operator>> (std::istream& input_s, Tcontact_with_the_user& text);
};

