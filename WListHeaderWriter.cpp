#include <iostream>
#include <fstream>
#include <vector>
#include "wrs/WHeader/hstream"
#include "wrs/WHeader/hmanip"
#include "wrs/WFolder/dirmanip"
#include "wrs/WFolder/filemanip"
using namespace wrs;
void showTitle(const string &, const string &, ostream &);
// shows the actual file working on, and if there is nothing, shows "empty".
template < class T > void getInput(T &, istream &, ostream &);
// shows a filled line folowed by the user space cursor to get keyboard
// inputs.
int main()
{
	WDir dir;
	hfstream fout("", WRS);
	string line;
	string content, listFile;
	int num;
	vector < string > lines, another_file;
	// contents;
	typestrings paths, container;
	ifstream fin;
	do
	{
		showTitle("List", listFile, cout);
		cout <<
			"1 - New list\t\t"
			"2 - Load list\n"
			"3 - Write list\n"
			"4 - Erase a line from the list\n"
			"5 - Save\t\t6 - Show list\n"
			"7 - Continue List\t8 - Help\n"
			"9 - Open a plain text file\n\t\t\t0 - Exit\n\nChoose:\n";
		getInput(num, cin, cout);
		cin.ignore();
		switch (num)
		{
		case 0:
			if (lines.size() > 0)
			{
				cout << "Save the progress? y/n\n";
				getInput(line, cin, cout);
				if (line == "y")
				{
					cin.putback('5');
					cin.putback('0');
				}
				else
					exit(1);
			}
			else
				exit(1);
		case 1:
			system("clear");
			cout << "File name: # to cancel\n";
			getInput(line, cin, cout);
			if (line == "#")
			{
				cout << "\ncanceling...\n";
				system("clear");
			}
			else
			{
				listFile = line;
				// saveFile(listFile, lines);
				cin.putback('7');
			}
			break;
		case 2:
			system("clear");
			cout << "File to open: # to cancel\n";
			getInput(line, cin, cout);
			if (line == "#")
			{
				cout << "\ncanceling...\n";
				system("clear");
				break;
			}
			else
			{
				if (getlines(line, lines))
				{
					listFile = line;
					show(lines, cout);
					cout << "End list (1) or continue (2)?\n";
					getInput(num, cin, cout);
					switch (num)
					{
					case 1:
						parseDirList(listFile, dir);
						cout << dir << endl;
						paths.clear();
						parsePaths(dir, paths, wrs::all);
						show(paths, cout);
						cout << "Save? y/n\n";
						cin >> line;
						system("clear");
						if (line == "y")
							saveFile(".paths", paths);
						else;
						break;
					case 2:
						cin.putback('7');
						break;
					default:
						break;
					}
				}
				else
				{
					system("clear");
					cout << "File not opened! Try again!\n";
				}
			}
			break;
		case 3:
			system("clear");
			if (listFile.size() == 0)
				cout << "Load a list first!\n";
			else
			{
				cout << "1 - whw to hpp\n2 - paths to hpp\n3 - paths to whw\n";
				getInput(num, cin, cout);
				switch (num)
				{
				case 3:
					parseDirList(listFile, dir);
					show(paths, cout);
					saveFile(".paths", paths);
					cout << dir << endl << "Write header files? y/n\n";
					getInput(line, cin, cout);
					if (line == "y")
					{
						for (int i = 0; i < paths.size(); i++)
							if (paths[i].first == DIR_)
								dirKeep(paths[i].second);
							else if (paths[i].first == FILE_)
							{
								cout << paths[i].second;
								fin.open(paths[i].second + ".whw");
								if (fin.fail())
								{

									fout.open(paths[i].second + ".whw");
									if (!fout.fail())
									{
										fout.close();
										cout << " done!\n";
									}
									else
										cout << " fail!\n";
								}
								else
								{
									cout << " exist!\n";
									fin.close();
								}
							}
							else;
					}
					else;
					break;
				case 2:
					for (int i = 0; i < paths.size(); i++)
					{
						if (paths[i].first == FILE_)
						{
							cout << paths[i].second;
							if (create_hpp_file(paths[i], fout))
								cout << " created!\n";
							else
								cout << " faulted!\n";
						}
						else if (paths[i].first == DIR_)
							dirKeep(paths[i].second);
					}
					break;
				case 1:
					cout << "Convert a single file(1) \nor the entire list(0)? ";
					cin >> line;
					if (line == "1")
					{
						int index;
						show(paths, cout);
						cout << "Choose which file to convert from the list: ";
						cin >> index;
						system("clear");
						cout << paths[index];
						if (paths[index].first == FILE_)
						{
							if (getlines(paths[index].second + ".whw", container))
							{
								if (create_hpp_file(paths[index], fout))
									cout << " done!";
								else
									cout << " fail!";
							}
							else
								cout << " none!";
							cout << endl;

						}
						else
							cout << "The choose is not a file! Try again!\n";
					}
					else if (line == "0")
					{
						if (paths.size() > 0)
							for (int i = 0; i < paths.size(); i++)
							{
								if (paths[i].first == FILE_)
								{
									container.clear();
									cout << paths[i];
									if (getlines(paths[i].second + ".whw", container))
									{
										if (create_hpp_file(paths[i], fout))
											cout << " done!";
										else
											cout << " fail!";
									}
									else
										cout << " none!";
									cout << endl;

								}
								else;
							}
						else
							cout << "Load list first!";
					}
					else
						cout << "Wrong choose, try again!\n";
				default:
					break;
				}
			}
			break;
		case 4:
			system("clear");
			int iter;
			if (lines.size() > 0)
			{
				show(lines, cout);
				cout << "Erase whitch line? -1 to cancel\n";
				getInput(iter, cin, cout);
				if (iter < 0)
				{
					system("clear");
					cout << "canceled!\n";
				}
				else
				{
					lines.erase(lines.begin() + iter);
					show(lines, cout);
				}
			}
			else
				cout << "Load a list first!\n";
			break;
		case 5:
			system("clear");
			if (lines.size() > 0)
			{
				saveFile(listFile, lines);
			}
			else
				cout << "Load a list first!\n";
			break;
		case 6:
			system("clear");
			show(lines, cout);
			break;
		case 7:
			system("clear");
			showTitle("List", listFile, cout);
			if (listFile.size() == 0)
			{
				cout << "Choose a new file name or # to cancel\n";
				getInput(line, cin, cout);
				if (line != "#")
				{
					listFile = line;
					cin.putback('7');
				}
				else
				{
					system("clear");
					cout << "Canceled!\n";
				}
			}
			else
			{
				if (lines.size() > 0)
					while (lines[lines.size() - 1].size() == 0)
						lines.erase(lines.begin() + lines.size() - 1);
				else;
				show(lines, cout);
				cout << "Write: # to save . to finish\n";
				do
				{
					getline(cin, line);
					if (line == "#")
					{
						saveFile(listFile, lines);
						cout << "Continue:\n";
					}
					else if (line == ".")
					{
						saveFile(listFile, lines);
						break;
					}
					else
						lines.push_back(line);
				}
				while (true);
			}
			break;
		case 8:
			system("clear");
			cout << "All you need is learn whw pseudo c++ programing language!\n\n";
			break;
		case 9:
			system("clear");
			cout << "Plain text to open: # to cancel \n";
			getInput(line, cin, cout);
			if (line != "#")
			{
				if (getlines(line, another_file))
				{
					showTitle("File", line, cout);
					show(another_file, cout);
					cout << "\nOpen another one(1) or close(2)?\n";
					getInput(line, cin, cout);
					if (line == "1")
						cin.putback('9');
					else
						system("clear");
				}
				else
				{
					system("clear");
					cout << "Unable to open " << line << "!\n";
				}
			}
			else
			{
				system("clear");
				cout << "Canceled!\n";
			}
			break;
		default:
			system("clear");
			cout << "Wrong choose, try again!\n";
			break;
		}
	}
	while (true);
	return 0;
}

void showTitle(const string & fileType, const string & fileName, ostream & out)
{
	out << fileType << ": ";
	if (fileName.size() > 0)
		out << fileName;
	else
		out << "Empty";
	out << endl;
}

using std::setfill;
template < class T > void getInput(T & obj, istream & in, ostream & out)
{
	out << setfill('_') << setw(20) << "|~> ";
	in >> obj;
}