#include <iostream>
#include <cctype>
#include <string>    // std::string
#include <sstream>
#include <functional>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
ifstream file;
file.open(argv[1]);
string lineBuffer;
while (!file.eof()) 
   {
       getline(file, lineBuffer);
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else 
       {
       		int upper = 0, lower = 0, total = 0;
        	for(int i = 0; i < lineBuffer.length(); i++)
        	{
        		if(isupper(lineBuffer[i]))
        		{
        			upper++;
        		}
        		else if(islower(lineBuffer[i]))
        		{
        			lower++;
        		}
        	}

        	total = upper + lower;
        	float percentage_upper = (float)upper/total * 100;
        	float percentage_lower = (float)lower/total * 100;
        	
			cout << fixed << setprecision(2);
			cout << "lowercase: " << percentage_lower << " uppercase: "  << percentage_upper << endl;
     }
}

return 0;
}