#include "CSVEditor.hpp"

template <typename T>
string to_string(const T &t)
{
	ostringstream os;
	os << t;
	return os.str();
}

template <typename T>
T from_string(string& s)
{
	istringstream is(s);
	int t;
	if (!(is >> t))
	{
		throw "bad";
	}
	return t;
}

CSVEditor::CSVEditor(string &inputPath, string &rosterPath, string &outputPath, regex expr, int m)
{
	//IMPLEMENT
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);

	regexPattern = expr;
	//std::smatch inputreg;
	//std::smatch rosterreg;

	hashTable = new HashTable<string>(m);
}

CSVEditor::~CSVEditor()
{
	//IMPLEMENT
	delete hashTable;
}

void CSVEditor::readCSVToTable()
{
	cout << "Reading to Table\n\n";
	//IMPLEMENT
	std::string str;
	smatch inputreg;
	while (!input.eof())
	{
		getline(input, str);
		if (std::regex_search(str, inputreg, regexPattern))
		{
			std::cout << "R0: " << inputreg[0] << "\nR1: " << inputreg[1] << "\tR2: " << inputreg[2] << "\n\n";
			string temp = inputreg[1];
			int UIN = stoi(temp); // need from_string to work here
			string quiz = to_string(inputreg[2]);
			hashTable->insert(UIN, quiz);
		}
	}
}

void CSVEditor::writeCSVToFile()
{
	cout << "\nWriting from table\n\n";
	//IMPLEMENT
	int count = 0;
	string str;
	smatch rosterreg;
	while (!roster.eof())
	{
		getline(roster, str);
		if (regex_search(str, rosterreg, regexPattern))
		{
			int UIN = stoi(rosterreg[1]); // need from_string to work here
			//cout << "R1: " << rosterreg[0] << endl;
			if (hashTable->search(UIN) == nullptr)
			{
				output << rosterreg[0] << endl;
				cout << rosterreg[0] << endl;
			}
			else
			{
				output << rosterreg[0] << *hashTable->search(UIN) << endl;
				cout << rosterreg[0] << *hashTable->search(UIN) << endl;
			}
		}
	}
}

std::tuple<int, int, double> CSVEditor::getStats()
{
	//IMPLEMENT
	return std::make_tuple(hashTable->minChainLen(), hashTable->maxChainLen(), hashTable->averageChainLen());
}
