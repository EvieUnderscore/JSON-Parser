#pragma once
#include <any>

class JSONValue
{
public:
	enum JSONValueType {
		VAL_STRING,
		VAL_NUM,
		VAL_JSON,
		VAL_ARRAY,
		VAL_BOOL,
		VAL_NULL
	};

	enum JSONBoolValues {
		TRUE = true,
		FALSE = false
	};

	JSONValueType type;

	std::any value = "";
;
};

