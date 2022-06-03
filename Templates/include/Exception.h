#pragma once

class EmptyList : public std::exception
{
public:
	EmptyList(const char* str) : m_str(str) {}
	const char* what() const noexcept { return m_str; }

private:
	const char* m_str;
};
//--------------------------------------------

