/*
 * Reducer.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: tks
 */

#include "Reducer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <iterator>
#include <unordered_map>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0

void Reducer::computedegree(std::string filename)
{
	std::string line,dummyline;
	std::ifstream infile (filename+"_inter.txt");
	std::ofstream outfile (filename+"_degree.txt");
	std::unordered_map <int, int> degree;

	int node,value;

	if (infile.is_open())
	{
		while (std::getline(infile, line))
		{
			std::istringstream iss(line);
			while (iss >> node >> value)
			{
				auto it = degree.find(node);
				if(it != degree.end())		//if key exists increase value by 1.
					degree[node] = degree[node]+1;
				else
					degree[node] = value;	//else if key doesn;t exists assign value as 1
			}
		}
		infile.close();
	}
	else
		std::cout << "\nUnable to open intermediate file for reading..\n";

	/*for ( auto it = degree.begin(); it != degree.end(); ++it )
	    std::cout << " " << it->first << ":" << it->second;*/

	if (outfile.is_open())
	{
		for ( auto it = degree.begin(); it != degree.end(); ++it )
			outfile << it->first << ":" << it->second << "\n";
		outfile.close();
	}
	else
		std::cout << "\nUnable to open final output file for writing degree..\n";

}




