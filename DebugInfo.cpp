#include "StdAfx.h"
#include "DebugInfo.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

DebugInfo::DebugInfo(void)
{
}


DebugInfo::~DebugInfo(void)
{
}

wstring formatTime()
{
	SYSTEMTIME time;
	GetLocalTime(&time);
	wstringstream ss;
	ss << time.wYear << "-" 
		<< time.wMonth << "-"
		<< time.wDay << " "
		<< time.wHour << ":"
		<< time.wMinute << ":"
		<< time.wSecond << "."
		<< time.wMilliseconds;
	return ss.str();
}

void writeToFile(const wstring& fileName, const wstring& content)
{
	wofstream file(fileName);
	file << formatTime() << L" " << content;
}

void DebugInfo::write(const std::wstring& s)
{
	writeToFile(L"debugInfo.log", s);
}

void DebugInfo::write(const std::string& s)
{
	vector<wchar_t> buffer(s.size() + 1);
	mbstowcs(&buffer[0], s.c_str(), s.size());
	write(&buffer[0]);
}

void DebugInfo::write(const std::string& info, size_t errorNumber)
{
	stringstream ss;
	ss << info << ":" << errorNumber;
	write(ss.str());
}
