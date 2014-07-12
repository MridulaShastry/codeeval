#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string lineBuffer, input_string;
	ifstream file;
	file.open(argv[1]);
	
	while (!file.eof()) 
   	{
       getline(file, lineBuffer);
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else {
       	char letter = lineBuffer.at(lineBuffer.length() - 1);
       	stringstream line_buffer(lineBuffer);
       	getline(line_buffer, input_string, ',');
       	int found = input_string.find_last_of(letter);
       	cout << found << endl;
       }
    }
  	return 0;
}