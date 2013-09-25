#include <iostream>
#include <string>
#include "Mapper.h"

using namespace std;

int main()
{
	cout << "Hello All!!!";

	Mapper mp;
	string graphname;

	cout << "Please enter the name of the graph file: \n ";
	cin >> graphname;
	mp.writeinter(graphname);		//write to intermediate file
	cout << "\nMapper task done..\n";

	return 0;

}
