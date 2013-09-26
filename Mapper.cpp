/*
 * Mapper.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: tks
 */
#include "Mapper.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <iterator>

void Mapper::writeinter(std::string filename)
{
	std::string line,dummyline;
	std::ifstream infile (filename);
	std::ofstream outfile (filename+"_inter.txt");
	std::vector<int> temp;
	int node;

	if (infile.is_open())
	{
		infile.ignore (10000, '\n' );//ignore the first line containing no of edges and vertices
		while (std::getline(infile, line))
		{
		  std::istringstream iss(line);
		  while (iss >> node)
		  {
		    temp.push_back(node);
		  }
		}
		infile.close();
	}
	else
			std::cout << "\nUnable to open input file for reading..\n";


	/*for(int i = 0; i < temp.size(); i++ ) {
	   std::cout << temp[i] << " ";
	 }*/

	if (outfile.is_open())
	{
		for(int i = 0; i < temp.size(); i++ )
			outfile << temp[i] << " " << 1 << "\n";
		outfile.close();
	}
	else
		std::cout << "\nUnable to open intermediate file for writing..\n";


}

