/*
 * json.cpp
 *
 *  Created on: 2014-10-7
 *      Author: acm
 */
#include "json.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//JSON���ʵ��
void JSON::show() const {
	cout << "hello" << endl;
}
JSON::~JSON() {
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONObject���ʵ��
JSONObject::JSONObject() {
	this->colnum = 0;
}
JSONObject::~JSONObject() {
	for (int i = 0; i < colnum; i++) {
		JSONCollection* p = this->cols[i];
		if (p) {
			delete p;
		}
	}
}
int JSONObject::getSize() {
	return this->colnum;
}
void JSONObject::add(JSONCollection* j) {
	this->cols[colnum++] = j;
}
void JSONObject::show() const {
	for (int i = 0; i < colnum; i++) {
		JSONCollection* jc = cols[i];
		jc->show();
		cout << "\n*******************************************" << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONCollection���ʵ��
JSONCollection::JSONCollection() {
	this->value = NULL;
}
void JSONCollection::setName(string n) {
	this->name = string(n);
}
void JSONCollection::setValue(JSON* j) {
	this->value = j;
}
JSONCollection::~JSONCollection() {
	if (value) {
		delete value;
	}
}
void JSONCollection::show() const {
	cout << name << ":\t";
	value->show();
	cout << endl;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONString���ʵ��
JSONString::JSONString(string s) {
	this->str = string(s);
}
void JSONString::show() const {
	cout << str;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONNum���ʵ��
JSONNum::JSONNum(int n) {
	this->num = n;
}
void JSONNum::show() const {
	cout << num;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONBool���ʵ��
JSONBool::JSONBool(bool b) {
	this->flag = b;
}
void JSONBool::show() const {
	cout << (flag ? "true" : "false");
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//JSONArray���ʵ��
JSONArray::JSONArray() {
	this->size = 0;
}
JSONArray::~JSONArray() {
	for (int i = 0; i < size; i++) {
		JSON* p = arr[i];
		if (p) {
			delete p;
		}
	}
}
void JSONArray::add(JSON* j) {
	arr[size++] = j;
}
int JSONArray::getSize() {
	return this->size;
}
void JSONArray::show() const {
	for (int i = 0; i < size; i++) {
		JSON* jn = arr[i];
		jn->show();
		cout << endl;
	}
}
///////////////////////////////////////////////////////////////////////////////

