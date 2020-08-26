#include <string>
#include <regex>

#include "HashTable.hpp"
#include "CSVEditor.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    regex expr(".*,.*,(.*),(.*)"); 
    /*
    some list of characters , somelist of characters ,  
    () - optional , may or may not exist but with this format
    */
	
    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";
	
	int m = 0; 
	
	//OBTAIN M HERE

    m = 19;

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();
	
	std::tuple<int, int, double> stats = editor.getStats();
	
	cout << "minimum chain len = " << std::get<0>(stats) << endl;
	cout << "maximum chain len = " << std::get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;

    editor.printHashTable();

    return 0;
}
