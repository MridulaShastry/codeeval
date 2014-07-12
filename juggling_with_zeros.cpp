#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string lineBuffer, output_string;
	ifstream file;
  int val = 0;
	file.open(argv[1]);
	
	while (!file.eof()) 
   	{
      getline(file, lineBuffer);
      if (lineBuffer.length() == 0)
          continue; //ignore all empty lines
      else
      {
        vector<string> zero_vector;
        stringstream zero_buffer(lineBuffer);
        string token;
   
        while(getline(zero_buffer,token,' '))
        {
          zero_vector.push_back(token); 
        }

        for(int i = 0; i < zero_vector.size(); i++)
        {
          cout << zero_vector[i] << ",";
        }

        cout << endl;

        string result = "";

        string flag, seq, inverted_seq;

        for(int i = 0, j = 1; j < zero_vector.size(); i+=2, j+=2)
        {
          flag = zero_vector[i];
          seq = zero_vector[j];

          if(flag == "00")
          {
            inverted_seq = seq.replace(seq.begin(), seq.end(), seq.length(), '1');
            
            result = result + inverted_seq;
          }

          if(flag == "0")
          {
            result = result + seq;
          }
        }
        cout << result << endl;
      }


   
}
 return 0;
}
