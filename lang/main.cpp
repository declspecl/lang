#include "Lexer.h"

#include <iostream>

char* rangeToStr(char* start, char* end)
{
	char* new_str = new char[100];
	memset(new_str, 0x00, 100);

	memcpy_s(new_str, 100, start, end - start);

	return new_str;
}

int main()
{
	Lexer lexer;

	const char* test = "if(help < 10) { print(\"hi\"); }";

	std::vector<Token> tokens = lexer.tokenize((char*)test);

	for (Token& token : tokens)
	{
		std::cout << Token::toString(token.type) << ": " << (const char*)rangeToStr(token.start, token.start + token.len) << std::endl;
	}

	return 0;
}