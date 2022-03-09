#pragma once
#include "pch.h"

//	Plugin varable, wraps a cvar and variable
template<typename T>
struct pvar {
	pvar(){}
	pvar(T val, std::string cname);

	void Set(T val);
	T GetVal();
	std::string GetStr();
	CVarWrapper GetCW();

	bool operator==(const pvar& rhs) { return this->GetVal() == rhs.GetVal(); }

private:
	T val = 0;
	std::string cname = "";
	bool is_string = false;
};