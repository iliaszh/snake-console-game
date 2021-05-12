#pragma once

#include <string>

inline std::wstring to_ws(const char* s)
{
	std::wstring ws;
	for (char* pc = const_cast<char*>(s); *pc != '\0'; ++pc)
	{
		ws.push_back(wchar_t(*pc));
	}
	return ws;
}

// may not work properly, i don't know shit about unicode
inline size_t count_codepoints(const std::u8string& str)
{
	size_t count = 0;
	for (auto& c : str)
		if ((c & 0b1100'0000) != 0b1000'0000) // Not a trailing byte
			++count;
	return count;
}