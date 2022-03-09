#include "pch.h"
#include "plugin_varable.h"
#include "defines.h"

extern std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

template<typename T>
pvar<T>::pvar(T val, std::string cname) {
	this->val = val;
	this->cname = cname;

	std::string type = typeid(val).name();

	if (type == "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >") {
		NewCvar(cname, val).addOnValueChanged([this](std::string old, CVarWrapper cvar) {
			this->val = cvar.getStringValue();
		});
		is_string = true;
	}
	else {
		NewCvar(cname, std::to_string(val)).addOnValueChanged([this](std::string old, CVarWrapper cvar) {
			switch (type) {
				case "int":
					this->val = cvar.getIntValue();
				case "double" || "float":
					this->val = cvar.getFloatValue();
				case "bool":
					this->val = cvar.getBoolValue();
			}
		});
	}
}

template<typename T>
void pvar<T>::Set(T val) {
	this->val = val;
	GetCvar(cname).setValue(val); //error check
}

template<typename T>
T pvar<T>::GetVal() {
	return val;
}

template<typename T>
CVarWrapper pvar<T>::GetCW() {
	return cm->getCvar(cname);
}

template<typename T>
std::string pvar<T>::GetStr() {
	return GetCvar(cname).getStringValue();
}