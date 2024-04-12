#include <iostream>
using namespace std;
int main ()
{
	const int SIZE = 5;
	int numbers [SIZE];
	
	for(int &val : numbers)
	{
		cout<< "enter an integer value: "<<endl;
		cin  >> val;
		
		
	}
	
	cout << "here are the values you entered"<< endl;
	
	for (int val : numbers)
	cout << val<<" ";
	
	cout <<endl;
	return 0;
	
}