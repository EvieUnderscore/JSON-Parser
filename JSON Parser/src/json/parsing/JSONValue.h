#pragma once
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

	JSONValueType type;
;
};

