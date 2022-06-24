#include <cstring>

#include "String/String.h"

namespace CustomSTL
{
	String::String() : m_Count(0), m_Size(sizeof(char) * 15), m_Buffer(new char[m_Size] {})
	{
		std::cout << "Constructed " << m_Size << " bytes!\n";
	}

	String::String(const char* string) : m_Count(strlen(string) + 1), m_Size(sizeof(char)* m_Count), m_Buffer(new char[m_Size])
	{
		std::cout << "Constructed " << m_Size << " bytes!\n";
		strcpy_s(m_Buffer, m_Size, string);
	}

	String::String(size_t count) : m_Count(count + 1), m_Size(sizeof(char)* m_Count), m_Buffer(new char[m_Size] {})
	{
		std::cout << "Constructed " << m_Size << " bytes!\n";
	}

	String::String(const String& other) : m_Count(other.m_Count), m_Size(other.m_Size), m_Buffer(new char[m_Size])
	{
		std::cout << "Copied " << m_Size << " bytes!\n";

		strcpy_s(m_Buffer, m_Size, other.m_Buffer);
	}

	String::String(const std::string& string)
	{
		m_Size = string.size() + 1;
		m_Count = m_Size / sizeof(char);
		m_Buffer = new char[m_Size];

		strcpy_s(m_Buffer, m_Size, string.data());
	}

	String String::operator+(const String& other) const
	{
		String newStr{ (m_Count + other.m_Count) - 2 };

		strcat_s(newStr.m_Buffer, newStr.m_Size, m_Buffer);
		strcat_s(newStr.m_Buffer, newStr.m_Size, other.m_Buffer);

		return newStr;
	}

	String String::operator+(const char* string) const
	{
		String newStr{ (m_Count + strlen(string)) - 1 };

		strcat_s(newStr.m_Buffer, newStr.m_Size, m_Buffer);
		strcat_s(newStr.m_Buffer, newStr.m_Size, string);

		return newStr;
	}

	String String::operator+(const std::string& string) const
	{
		return this->operator+(string.data());
	}


	String::~String()
	{
		std::cout << "Destructing " << m_Size << " bytes!\n";

		delete[] m_Buffer;
		m_Buffer = nullptr;
	}

	std::ostream& operator<<(std::ostream& stream, const String& data)
	{
		stream << data.m_Buffer;
		return stream;
	}
};
