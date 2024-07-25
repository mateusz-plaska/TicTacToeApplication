#include "Tinvalid_char.h"

#include <string>
#include <iostream>
#include <locale.h>
#include <sstream>

Tinvalid_char::Tinvalid_char() : error_code("")
{}

void Tinvalid_char::add_error_text(const std::string text)
{
	error_code += text;
	return;
}

std::string Tinvalid_char::what()
{
	std::ostringstream info;
	info << std::endl << "ERROR! Information: " << std::endl << std::endl << error_code << std::endl;

	return info.str();
}