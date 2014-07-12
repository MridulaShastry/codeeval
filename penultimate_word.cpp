#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

	ifstream file;
	file.open(argv[1]);
	string lineBuffer;
	string word;

	while (!file.eof()) 
   	{
       getline(file, lineBuffer);
       string in_word;
    
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else 
       {
       		stringstream input_line;
       		input_line.str(lineBuffer);	
       		vector<string> words;
       		while(getline(input_line,word,' '))
       		{
       			 words.push_back(word);       			
       		} 

       		cout << words[words.size() - 2] << endl;        	        	

       }
	}
	return 0;
}