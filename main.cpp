#include <iostream>
#include <string>
#include "Mapper.h"
#include "Reducer.h"

using namespace std;

int main()
{
	cout << "Hello All!!!";

	Mapper mp;
	Reducer re;

	string graphname;

	cout << "Please enter the name of the graph file: \n ";
	cin >> graphname;
	mp.writeinter(graphname);		//write to intermediate file
	cout << "\nMapper task done..\n";

	re.computedegree(graphname);
	cout << "\nReducer task done..\n";

	return 0;

}
