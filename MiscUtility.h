#pragma once
#include<string>


static class MiscUtility {
public:
	static std::wstring ConvertString(const std::string& str);

	static std::string ConvertString(const std::wstring& str);
};
