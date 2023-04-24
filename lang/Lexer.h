#pragma once

#include "Token.h"

#include <string.h>
#include <vector>
#include <iostream>

class Lexer
{
private:
	Token find_next_token(char* begin);

public:
	std::vector<Token> tokenize(char* str);
};