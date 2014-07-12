#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	string delimiter = ",";

	while (!file.eof()) 
   	{
       getline(file, lineBuffer);
       int line_int_arr[3];
       string number;
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else 
       {
       		int j = 0;
         	stringstream input_line;
         	input_line.str(lineBuffer);
         	while(getline(input_line, number, ','))
         	{
                istringstream(number) >> line_int_arr[j];
         		j++;     		        		
         	}

         	unsigned int bit_1 = (line_int_arr[0] >> line_int_arr[1] - 1) & 0x01;
         	unsigned int bit_2 = (line_int_arr[0] >> line_int_arr[2] - 1) & 0x01;

         	if(bit_1 == bit_2)
         	{
         		cout << "true" << endl;
         	}
         	else
         	{
         		cout << "false" << endl;
         	}

        }
}
	return 0;
}