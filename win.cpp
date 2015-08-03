/*
 * json/win.cpp
 * Created on: 2014-10-4
 * Author    : ben
 */

#include "json.h"
#include "parser.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

int main() {
	freopen("jsonexp.txt", "r", stdin);

	initParser();

	JSONObject* obj = parseObject();
	obj->show();
	delete obj;
	return 0;
}
