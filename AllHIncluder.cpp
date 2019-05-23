 #include <iostream>
#include <fstream>
#include "wrs/WHeader/hmanip"
using namespace std;
using wrs::WDir;
using wrs::allri;
int main()
{
	string folder, line;
	ofstream fout;
	ifstream fin;
	WDir dir;
	cout << "Folder: ";
	cin >> folder;
	getDirContent(folder, dir);
	cout << dir << endl;
	cout << WRS_VERSION << endl;
	cin.ignore();
	cout << "Press enter to continue...";
	cin.get();
	fout.open(allri);
	includeHeaders(dir, fout);
	fout.close();
	fin.open(allri);
	while (!fin.eof())
	{
		getline(fin, line);
		cout << line << endl;
	}
	cout << "Fim!";
	return 0;
}