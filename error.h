#ifndef _ERROR_H_
#define _ERROR_H_

#include <exception>
#include <cstdio>

struct base: std::exception
{
	virtual void format_error_message()const = 0;
	const char* what() const throw()
	{
		format_error_message();
		return error_message_buffer;
	}
	mutable char error_message_buffer[256];
};

struct invalid_character:
	base
{
	void format_error_message() const
	{
		std::snprintf(error_message_buffer, sizeof(error_message_buffer),
			"Special characters not allowed in table.");
	}
};

#endif