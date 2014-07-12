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
  int max_size = 0;

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
          string max_length_word;
          while(getline(input_line,word,' '))
          {
            if (word.size() > max_size)
            {
              max_length_word = word;
              max_size = word.size();
            }
            else
            {
              continue;
            }              

          } 
          max_size = 0;
          cout << max_length_word << endl;         
      }
  }
  return 0;
}