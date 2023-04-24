#include "Token.h"

Token::Token(TokenType type, char* start, unsigned len)
	: type(type)
	, start(start)
	, len(len)
{

}

bool Token::isLetter(char character)
{
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

bool Token::isNumber(char character)
{
	return character >= '0' && character <= '9';
}

bool Token::isWhitespace(char character)
{
	return character == ' ';
}

bool Token::isNewline(char character)
{
	return character == '\n';
}

bool Token::isUnderscore(char character)
{
    return character == '_';
}

bool Token::isEOF(char character)
{
	return character == '\0';
}

bool Token::cmpstr(char* origin, const char* value)
{
	if (strlen(value) > strlen(origin))
		return false;

	for (unsigned i = 0; i < strlen(value); i++)
	{
		if (*value != *origin)
			return false;

		origin++;
		value++;
	}

	return true;
}

std::string Token::toString(TokenType tokenType)
{
    std::string enumName;

    switch (tokenType)
    {
    case IDENTIFIER:
        enumName = "IDENTIFIER";
        break;
    case NUMBER:
        enumName = "NUMBER";
        break;
    case INTEGER:
        enumName = "INTEGER";
        break;
    case FLOATING_POINT:
        enumName = "FLOATING_POINT";
        break;
    case STRING:
        enumName = "STRING";
        break;
    case BOOL:
        enumName = "BOOL";
        break;
    case IF:
        enumName = "IF";
        break;
    case ELSE:
        enumName = "ELSE";
        break;
    case WHILE:
        enumName = "WHILE";
        break;
    case RETURN:
        enumName = "RETURN";
        break;
    case EXCLAMATION_MARK:
        enumName = "EXCLAMATION_MARK";
        break;
    case AT_SIGN:
        enumName = "AT_SIGN";
        break;
    case POUND_SIGN:
        enumName = "POUND_SIGN";
        break;
    case DOLLAR_SIGN:
        enumName = "DOLLAR_SIGN";
        break;
    case PERCENT_SIGN:
        enumName = "PERCENT_SIGN";
        break;
    case CARET:
        enumName = "CARET";
        break;
    case AMPERSAND:
        enumName = "AMPERSAND";
        break;
    case ASTERISK:
        enumName = "ASTERISK";
        break;
    case HYPHEN:
        enumName = "HYPHEN";
        break;
    case UNDERSCORE:
        enumName = "UNDERSCORE";
        break;
    case CROSS:
        enumName = "CROSS";
        break;
    case EQUALS:
        enumName = "EQUALS";
        break;
    case DOUBLE_EQUALS:
        enumName = "DOUBLE EQUALS";
        break;
    case COMMA:
        enumName = "COMMA";
        break;
    case DOT:
        enumName = "DOT";
        break;
    case SINGLE_QUOTE:
        enumName = "SINGLE_QUOTE";
        break;
    case DOUBLE_QUOTE:
        enumName = "DOUBLE_QUOTE";
        break;
    case BACK_SLASH:
        enumName = "BACK_SLASH";
        break;
    case PIPE:
        enumName = "PIPE";
        break;
    case FORWARD_SLASH:
        enumName = "FORWARD_SLASH";
        break;
    case QUESTION_MARK:
        enumName = "QUESTION_MARK";
        break;
    case COLON:
        enumName = "COLON";
        break;
    case SEMICOLON:
        enumName = "SEMICOLON";
        break;
    case L_PARENTHESIS:
        enumName = "L_PARENTHESIS";
        break;
    case R_PARENTHESIS:
        enumName = "R_PARENTHESIS";
        break;
    case L_SQUARE_BRACKET:
        enumName = "L_SQUARE_BRACKET";
        break;
    case R_SQUARE_BRACKET:
        enumName = "R_SQUARE_BRACKET";
        break;
    case L_CURLY_BRACKET:
        enumName = "L_CURLY_BRACKET";
        break;
    case R_CURLY_BRACKET:
        enumName = "R_CURLY_BRACKET";
        break;
    case L_ANGLE_BRACKET:
        enumName = "L_ANGLE_BRACKET";
        break;
    case R_ANGLE_BRACKET:
        enumName = "R_ANGLE_BRACKET";
        break;
    case BACK_TICK:
        enumName = "BACK_TICK";
        break;
    case TILDE:
        enumName = "TILDE";
        break;
    case _EOF:
        enumName = "_EOF";
        break;
    case UNKNOWN:
        enumName = "UNKNOWN";
        break;
    case INVALID:
        enumName = "INVALID";
        break;
    default:
        enumName = "???";
        break;
    }

    return enumName;
}