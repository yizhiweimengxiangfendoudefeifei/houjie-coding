
#ifndef __STRING
#define __STRING
#pragma once
#pragma warning(disable:4996)
#include <string.h>
#include<iostream>
using namespace std;

class String
{
public:
	String(const char* cha = 0);
	String(const String& ch);
	String& operator=(const String& ch);
	~String();
	char* getchar() const{ return m_char; }
private:
	char* m_char;
};


inline
String::String(const char* cha) {
	if (cha) {
		m_char = new char[strlen(cha) + 1];
		strcpy(m_char, cha);
	}
	else {
		m_char = new char[1];
		*m_char = '\0';
	}
	
}

inline
String::~String() {
	delete[] m_char;
}

inline
String& String::operator=(const String& ch) {
	if (this == &ch) {
		return *this;
	}
	delete[] m_char;
	m_char = new char[strlen(ch.m_char) + 1];
	strcpy(m_char, ch.m_char);
	return *this;
}

inline
String::String(const String& ch) {
	m_char = new char[strlen(ch.m_char) + 1];
	strcpy(m_char, ch.m_char);
}

ostream& operator<<(ostream& os,const String& ch) {
	os << ch.getchar();
	return os;
	
}

#endif // !__STRING
