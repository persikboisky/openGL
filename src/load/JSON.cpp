/*
 * JSON.cpp
 *
 * Created on Nov 26, 2024
 *         Author: persikboisky
 */

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "JSON.hpp"

int json::getValueFromJSON(const char *PATH, const char *object)
{
	int value = 0;
	std::fstream file;
	file.open(PATH);

	if (file.is_open())
	{
		std::cout << "Ok read file: " << PATH << std::endl;
		nlohmann::json objJSON;
		file >> objJSON;
		value = objJSON[object].get<int>();
	}
	else
	{
		std::cerr << "Failed read file: " << PATH << std::endl;
	}

	return value;
}