#include "wrs/WFolder/filemanip"
#include "wrs/WFolder/WDirmanip"
using namespace wrs;
using namespace std;
int main(){
	string input;
	typestrings y;
	cout << "Folder: ";
	cin >> input;
	parsePaths(input, y);
	show(y, cout);
	cout << "Write these lines on which file? ";
	cin >> input;
	writeObjs(input, y);
	cout << "Finished!";
	return 0;
}