/*
 * lexical.cpp
 *
 *  Created on: 2014-10-7
 *      Author: acm
 */

#include "lexical.h"

#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

char buf[4096];
int curc;

void initLexical() {
	buf[curc = 0] = getchar();
}

void skip() {
	while(buf[curc] == ' ' || buf[curc] == '\t' || buf[curc] == '\n' || buf[curc] == '\f' || buf[curc] == '\b' || buf[curc] == '\r') {
		buf[curc] = getchar();
	}
}

string getToken() {
	skip();

	if (buf[curc] == EOF) {
		return string("-1");//防出错临时写法
	}

	/**
	 * 单字符token
	 */
	const char kws[] = "{},:[]";
	int index = 0;
	for (; index < 6; index++) {
		if (kws[index] == buf[curc]) {
			break;
		}
	}
	if (index < 6) {
		string ret(1, buf[curc]);
		buf[curc = 0] = getchar();
		return ret;
	}

	/**
	 * 双引号开头
	 */
	if(buf[curc] == '\"') {
		buf[++curc] = getchar();
		while(buf[curc] != '\"') {
			if(buf[curc] == '\\') {
				buf[++curc] = getchar();
			}
			buf[++curc] = getchar();
		}
		string ret(buf, 0, curc + 1);
		buf[curc = 0] = getchar();
		return ret;
	}

	while(buf[curc] != ',' && buf[curc] != '}') {
		buf[++curc] = getchar();
	}
	string ret(buf, 0, curc + 1);
	return ret;
}
