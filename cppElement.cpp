#include "wrs/WCore/CppElement" include <iostream> using namespace std; int
#main() { wrs::hfstream fout("cppElementExample", WRS); wrs::CppElement element;
#element.set(wrs::typestring{'f',  "<T>void pertinence(T element, vector<>
#elementSet)" }); fout.begin(); fout.include("string"); fout.include("vector");
#fout.begin_namespace(); fout << "using std::string;\nusing std::vector;\n";
#element.declaration(fout); element.definition(fout); fout.finish(); cout <<
#"Fim!"; return 0;
}
