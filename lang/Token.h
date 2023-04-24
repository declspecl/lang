#pragma once

#include <string>
#include <iostream>

enum TokenType
{
	IDENTIFIER,

	// literals
	INTEGER_LITERAL,
	FLOATING_POINT_LITERAL,
	STRING_LITERAL,
	BOOL_LITERAL,

	// keywords
	IF,
	ELSE,
	WHILE,
	RETURN,
	FOR,
	CLASS,
	FN,
	LET,

	// type keywords
	I8,
	I16,
	I32,
	I64,
	U8,
	U16,
	U32,
	U64,
	F32,
	F64,
	BOOL,
	STRING,
	CHAR,

	// operators
	CROSS,
	HYPHEN,
	ASTERISK,
	FORWARD_SLASH,
	EQUALS,
	DOUBLE_EQUALS,
	L_ANGLE_BRACKET,
	R_ANGLE_BRACKET,
	PERCENT_SIGN,
	DOT,

	// symbols
	EXCLAMATION_MARK,
	AT_SIGN,
	POUND_SIGN,
	DOLLAR_SIGN,
	CARET,
	AMPERSAND,
	UNDERSCORE,
	COMMA,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	BACK_SLASH,
	PIPE,
	QUESTION_MARK,
	COLON,
	SEMICOLON,
	L_PARENTHESIS,
	R_PARENTHESIS,
	L_SQUARE_BRACKET,
	R_SQUARE_BRACKET,
	L_CURLY_BRACKET,
	R_CURLY_BRACKET,
	BACK_TICK,
	TILDE,

	_EOF,
	UNKNOWN,
	INVALID
};

class Token
{
public:
	TokenType type;
	char* start;
	unsigned len;

	Token(TokenType type, char* start, unsigned len);
	
	static bool isLetter(char character);
	static bool isNumber(char character);
	static bool isWhitespace(char character);
	static bool isNewline(char character);
	static bool isUnderscore(char character);
	static bool isEOF(char character);

	static std::string toString(TokenType tokenType);

	static bool cmpstr(char* origin, const char* value);
};