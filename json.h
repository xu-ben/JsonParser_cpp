#pragma once

/*
 * json.h
 *
 *  Created on: 2014-10-7
 *      Author: acm
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAXN = 100;

class JSON {
public:
	virtual ~JSON();
	virtual void show() const;
};

class JSONCollection : public JSON {
public:
	JSONCollection();
	void setName(const string);
	void show() const;
	void setValue(JSON*);
	virtual ~ JSONCollection();
private:
	string name;
	JSON* value;
};

class JSONObject : public JSON {
public:
	JSONObject();
	void show() const;
	void add(JSONCollection *);
	int getSize();
	virtual ~ JSONObject();
private:
	int colnum;
	JSONCollection* cols[MAXN];
};

class JSONString : public JSON {
public:
	JSONString(string);
	void show() const;
private:
	string str;
};

class JSONNum : public JSON {
public:
	JSONNum(int);
	void show() const;
private:
	int num;
};

class JSONBool : public JSON {
public:
	JSONBool(bool);
	void show() const;
private:
	bool flag;
};

class JSONArray : public JSON {
public:
	JSONArray();
	virtual ~ JSONArray();
	int getSize();
	void show() const;
	void add(JSON*);
private:
	int size;
	JSON* arr[MAXN];
};
