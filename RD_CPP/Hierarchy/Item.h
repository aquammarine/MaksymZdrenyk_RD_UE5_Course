#pragma once
#include <string>

class Item {
protected:
	std::string icon;

public:
	Item(const std::string& icon);
	virtual ~Item() = default;
};