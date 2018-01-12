#include <iostream>


using namespace std;



int f(int &i)
{
	i = 10;
	return(5 * i);
}
int main()
{
	int n = 5;
	f(n);
	cout << n << "\n";
	return 0;
}