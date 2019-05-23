#include <vector>
#include <algorithm>
#include <iostream>
// #include <ctype.h>
using namespace std;
bool isEqual(char i, char j)
{
	if ( i == j)
		return true;
	else
		return false;
}

int main()
{
	string a = "bbb#aah", b = "bbb";
	bool t;
	string::iterator c = find_end(a.begin(), a.end(), b.begin(), b.end(), isEqual);
	cout << a.substr(distance(a.begin(), c), b.size());
}