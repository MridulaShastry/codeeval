#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>

using namespace std;

string calculate_sum(string input_str)
{
  int sum = 0;
  string result;
  for(int i = 0; i < input_str.length(); i++)
  {
    int val = (int)(input_str.at(i) - '0');
    sum += val * val;
  }
  ostringstream op_str;
  op_str << sum;
  result = op_str.str();
  return result;
}

int main(int argc, char *argv[])
{
	string lineBuffer, output_string;
	ifstream file;
	file.open(argv[1]);
	
	while (!file.eof()) 
   	{
      getline(file, lineBuffer);
      if (lineBuffer.length() == 0)
          continue; //ignore all empty lines
      else
      {
        string init_val = calculate_sum(lineBuffer);
        int val = atoi(init_val.c_str());
        int condition = (val >= 0) && (val <= 9);

        while(!condition)
        {
          string further_sum = calculate_sum(init_val);
          val = atoi(further_sum.c_str());
          condition = (val >= 0) && (val <= 9);
          init_val = further_sum;
        }
        if(val == 1)
        {
          cout << "1" << endl;
        }
        else
        {
          cout << "0" << endl;
        }
      }        
    }
    return 0;
}
