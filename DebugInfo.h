#pragma once

#include <string>
#include "Singleton.h"

class DebugInfo : public Singleton<DebugInfo>
{
public:
	DebugInfo(void);
	~DebugInfo(void);
public:
	void write(const std::wstring&);
	void write(const std::string&);
	void write(const std::string&, size_t errorNumber);
};

