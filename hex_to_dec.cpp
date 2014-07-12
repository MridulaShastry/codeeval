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
       	stringstream number(lineBuffer);
       	int value;
       	number >> hex >> value;
       	cout << value << endl;
       }
    }
    return 0;
}
