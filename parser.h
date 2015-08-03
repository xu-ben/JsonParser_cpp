/*
 * parser.h
 *
 *  Created on: 2014-10-7
 *      Author: acm
 */

#pragma once

JSONArray* parseArray();

JSON* parseValue();

JSONCollection* parseCollection();

JSONObject* parseObject();

void initParser();
