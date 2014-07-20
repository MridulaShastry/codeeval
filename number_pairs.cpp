#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

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
        vector <int> numbers;
        int val, sum;
        std::string value;
        string sum_val;

        stringstream line_original(lineBuffer);
        while(getline(line_original, sum_val, ';'))
        {
          istringstream sum_str(sum_val);
          sum_str >> sum;
        }

        
        int pos = lineBuffer.find_first_of(';');
        lineBuffer.erase(pos, lineBuffer.length() - pos + 1);

        std::stringstream line(lineBuffer);

        while(getline(line,value,','))
        {
            istringstream num(value);
            num >> val;
            numbers.push_back(val);
        }      
       
        string output = "";
        for(int i = 0; i < numbers.size() - 1; i++)
        {
          for(int j = i + 1; j < numbers.size(); j++)
          {
            if(numbers[i] + numbers[j] == sum)
            {

              if(output.length() != 0)
              {
                output.append(";");
              }

              stringstream os_stream;
              os_stream << numbers[i];
              string num1 = os_stream.str();
              output.append(num1);
              output.append(",");
              stringstream os_stream_2;
              os_stream_2 << numbers[j];
              string num2 = os_stream_2.str();
              output.append(num2);                       
              
            }
            else
            {
              continue;
            }
          }
        }

        if(output.length() == 0)
        {
          output = "NULL";
        }

        cout << output << endl;
       }       
    }
    return 0;
}