#include <iostream>
#include <fstream>
#include "wrs/WList/WDir"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using wrs::WDir;
using wrs::getPath;
int main()
{
	string x, y, line;
	WDir dir1, dir2;
	cout << "Folder 1: ";
	cin >> x;
	cout << "Folder 2: ";
	cin >> y;
	getDirContent(x, dir1);
	getDirContent(y, dir2);
	if (dir1 == dir2)
		cout << "The two folders have the same names of files and folders.";
	else
		cout << "The folders have one, or more and/or all folders and files differents";
	cout << endl;
	system("pause");
	cout << endl << "Folder 1: " << endl << dir1 << endl << "Folder 2: " << endl << dir2 << endl;
	cout << "Path: ";
	cout << getPath(dir1) << endl;
	for (int i = 0; i < dir2.size(); i++)
		cout << getPath(dir2[i]) << endl;
	cout << "Fim!\n";
	return 0;
}