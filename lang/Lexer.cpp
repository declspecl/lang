#include "Lexer.h"

Token Lexer::find_next_token(char* begin)
{
	switch (*begin)
	{
	case '!':
		return Token(TokenType::EXCLAMATION_MARK, begin, 1);
	case '@':
		return Token(TokenType::AT_SIGN, begin, 1);
	case '#':
		return Token(TokenType::POUND_SIGN, begin, 1);
	case '%':
		return Token(TokenType::PERCENT_SIGN, begin, 1);
	case '^':
		return Token(TokenType::CARET, begin, 1);
	case '&':
		return Token(TokenType::AMPERSAND, begin, 1);
	case '*':
		return Token(TokenType::ASTERISK, begin, 1);
	case '(':
		return Token(TokenType::L_PARENTHESIS, begin, 1);
	case ')':
		return Token(TokenType::R_PARENTHESIS, begin, 1);
	case '-':
		return Token(TokenType::HYPHEN, begin, 1);
	case '+':
		return Token(TokenType::CROSS, begin, 1);
	case '=':
		if (*(begin + 1) == '=')
			return Token(TokenType::DOUBLE_EQUALS, begin, 2);
		else
			return Token(TokenType::EQUALS, begin, 1);
	case '[':
		return Token(TokenType::L_SQUARE_BRACKET, begin, 1);
	case ']':
		return Token(TokenType::R_SQUARE_BRACKET, begin, 1);
	case '{':
		return Token(TokenType::L_CURLY_BRACKET, begin, 1);
	case '}':
		return Token(TokenType::R_CURLY_BRACKET, begin, 1);
	case ':':
		return Token(TokenType::COLON, begin, 1);
	case ';':
		return Token(TokenType::SEMICOLON, begin, 1);
	case '\'':
		return Token(TokenType::SINGLE_QUOTE, begin, 1);
	case '\"':
	{
		char* end_of_string = begin + 1;

		while (*end_of_string != '\"')
		{
			end_of_string++;

			if (*end_of_string == '\0')
				return Token(TokenType::INVALID, begin, end_of_string - begin + 1);
		}

		// add one to go past the last quote
		return Token(TokenType::STRING_LITERAL, begin, end_of_string - begin + 1);
	}
	case '\\':
		return Token(TokenType::BACK_SLASH, begin, 1);
	case '|':
		return Token(TokenType::PIPE, begin, 1);
	case ',':
		return Token(TokenType::COMMA, begin, 1);
	case '.':
		return Token(TokenType::DOT, begin, 1);
	case '?':
		return Token(TokenType::QUESTION_MARK, begin, 1);
	case '/':
		return Token(TokenType::FORWARD_SLASH, begin, 1);
	case '<':
		return Token(TokenType::L_ANGLE_BRACKET, begin, 1);
	case '>':
		return Token(TokenType::R_ANGLE_BRACKET, begin, 1);
	case '`':
		return Token(TokenType::BACK_TICK, begin, 1);
	case '~':
		return Token(TokenType::TILDE, begin, 1);
	default:
		if (Token::cmpstr(begin, "if"))
			return Token(TokenType::IF, begin, 2);
		else if (Token::cmpstr(begin, "else"))
			return Token(TokenType::ELSE, begin, 4);
		else if (Token::cmpstr(begin, "for"))
			return Token(TokenType::FOR, begin, 3);
		else if (Token::cmpstr(begin, "while"))
			return Token(TokenType::WHILE, begin, 5);
		else if (Token::cmpstr(begin, "return"))
			return Token(TokenType::RETURN, begin, 6);
		else if (Token::cmpstr(begin, "class"))
			return Token(TokenType::CLASS, begin, 5);
		else if (Token::cmpstr(begin, "let"))
			return Token(TokenType::ELSE, begin, 3);
		else if (Token::cmpstr(begin, "fn"))
			return Token(TokenType::FN, begin, 2);
		else if (Token::cmpstr(begin, "i8"))
			return Token(TokenType::I8, begin, 2);
		else if (Token::cmpstr(begin, "i16"))
			return Token(TokenType::I16, begin, 3);
		else if (Token::cmpstr(begin, "i32"))
			return Token(TokenType::I32, begin, 3);
		else if (Token::cmpstr(begin, "i64"))
			return Token(TokenType::I64, begin, 3);
		else if (Token::cmpstr(begin, "u8"))
			return Token(TokenType::U8, begin, 2);
		else if (Token::cmpstr(begin, "u16"))
			return Token(TokenType::U16, begin, 3);
		else if (Token::cmpstr(begin, "u32"))
			return Token(TokenType::U32, begin, 3);
		else if (Token::cmpstr(begin, "u64"))
			return Token(TokenType::U64, begin, 3);
		else if (Token::cmpstr(begin, "bool"))
			return Token(TokenType::BOOL, begin, 4);
		else if (Token::isLetter(*begin) || Token::isUnderscore(*begin))
		{
			char* end_of_stream = begin;

			while (Token::isLetter(*end_of_stream) || Token::isNumber(*end_of_stream) || Token::isUnderscore(*end_of_stream))
				end_of_stream++;

			return Token(TokenType::IDENTIFIER, begin, end_of_stream - begin);
		}
		else if (Token::isNumber(*begin))
		{
			bool is_float_literal = false;
			char* end_of_stream = begin;

			while (Token::isNumber(*end_of_stream) || *end_of_stream == '.')
			{
				if (*end_of_stream == '.')
					is_float_literal = true;

				end_of_stream++;
			}

			if (is_float_literal)
				return Token(TokenType::FLOATING_POINT_LITERAL, begin, end_of_stream - begin);
			else
				return Token(TokenType::INTEGER_LITERAL, begin, end_of_stream - begin);
		}
		else
		{
			return Token(TokenType::UNKNOWN, begin, 1);
		}
	}
}

std::vector<Token> Lexer::tokenize(char* str)
{
	std::vector<Token> tokens;
	tokens.reserve(strlen(str) / 3);

	char* current = str;

	while (*current != '\0')
	{
		if (Token::isWhitespace(*current))
			current++;
		else if (Token::cmpstr(current, "//"))
		{
			while (!Token::isNewline(*current) && !*current == '\0')
				current++;
		}
		else if (Token::cmpstr(current, "/*"))
		{
			while (!Token::cmpstr(current, "*/") && !*current == '\0')
				current++;
		}
		else
		{
			Token next_token = this->find_next_token(current);

			current += next_token.len;

			tokens.push_back(next_token);
		}
	}

	return tokens;
}