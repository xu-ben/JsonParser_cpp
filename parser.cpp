/*
 * parser.cpp
 *
 *  Created on: 2014-10-7
 *      Author: acm
 */

#include "lexical.h"
#include "json.h"
#include "parser.h"

#include <string>
#include <cstring>
#include <vector>
using namespace std;


string curToken;

void initParser() {
	initLexical();
	curToken = getToken();
}

inline bool equals(string s, const char *str) {
	return strcmp(s.c_str(), str) == 0;
}

JSONArray* parseArray() {
	JSONArray* ret = new JSONArray();
	//读掉[
	curToken = getToken();

	while (!equals(curToken, "]")) {
		JSON* val = parseValue();
		ret->add(val);
		if (equals(curToken, ",")) {
			curToken = getToken();
		}
	}

	//读掉]
	curToken = getToken();
	return ret;
}

JSON* parseValue() {
	if (equals(curToken, "{")) {//接下来是个对象
		JSONObject* ret = parseObject();
		return ret;
	}
	if (equals(curToken, "[")) {//接下来是个数组
		JSONArray* ret = parseArray();
		return ret;
	}
	if (equals(curToken, "true")) {
		JSONBool* ret = new JSONBool(true);
		curToken = getToken();
		return ret;
	}

	if (equals(curToken, "false")) {
		JSONBool* ret = new JSONBool(false);
		curToken = getToken();
		return ret;
	}
	if (curToken[0] == '\"') {//接下来是个字符串
		int len = curToken.size();
		JSONString* ret = new JSONString(string(curToken, 1, len - 2));
		curToken = getToken();
		return ret;
	}
	int d;
	sscanf(curToken.c_str(), "%d", &d);
	JSONNum* ret = new JSONNum(d);
	curToken = getToken();
	return ret;
}

JSONCollection* parseCollection() {
	JSONCollection* ret = new JSONCollection();

	string name(curToken, 1, curToken.size() - 2);

	curToken = getToken();

	//读掉冒号
	curToken = getToken();

	ret->setName(name);
	ret->setValue(parseValue());
	return ret;
}

JSONObject* parseObject() {
	JSONObject* obj = new JSONObject();
	//读掉{
	curToken = getToken();

	while (!equals(curToken, "}")) {
		JSONCollection* col = parseCollection();
		obj->add(col);
		if (equals(curToken, ",")) {
			curToken = getToken();
		}
	}

	//读掉}
	curToken = getToken();

	return obj;
}
