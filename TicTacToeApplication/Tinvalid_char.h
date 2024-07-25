#pragma once

#include <string>

class Tinvalid_char
{
	std::string error_code;
public:
	Tinvalid_char();

	void add_error_text(const std::string text);

	std::string what();
};

