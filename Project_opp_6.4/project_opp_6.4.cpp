#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	try
	{
		Array<int> V(5);
		cin >> V;
		cout << V;
		if (V.MyTask() == true)
		{
			cout << "the array contain the same neighboring elements" << endl;
		}
		else
		{
			cout << "the array doesn't contain the same neighboring elements" << endl;
		}
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}
