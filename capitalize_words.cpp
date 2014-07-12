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
        lineBuffer.at(0) = toupper(lineBuffer.at(0));
       	for(int i = 0; i < lineBuffer.length(); i++)
        {
          if(lineBuffer.at(i) == ' ')
          {
            lineBuffer.at(i + 1) = toupper(lineBuffer.at(i+1));
          }
        }
        cout << lineBuffer << endl;
       }
    }
    return 0;
}
