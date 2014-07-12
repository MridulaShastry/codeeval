#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{

	string lineBuffer;
	ifstream file;
	file.open(argv[1]);
	

	cout << "Print contents of array " << endl;
	
	cout << endl;
	while (!file.eof()) 
   	{
       getline(file, lineBuffer);
       if (lineBuffer.length() == 0)
           continue; //ignore all empty lines
       else 
       {
       		int count = 0;
       		int arr[10];
			cout << "initializing array " << endl;
			for(int i = 0; i < 10; i++)
			{
				arr[i] = 0;
			}
       		cout << "length: " << lineBuffer.length() << endl;
           for(int i = 0; i < lineBuffer.length(); i++)
           {
           		cout << " Linebuffer " << lineBuffer.at(i) << " ";
           		int subscript = (int)(lineBuffer.at(i) - '0');
           		cout << " subscript " << subscript << endl;
           		arr[(int)(lineBuffer.at(i)) - '0']++;
           }

           for(int i = 0; i < 10; i++)
           {
           		cout << arr[i] << " ";
           }

           cout << "Verifying if the number is self describing " << endl;
           for(int i = 0; i < lineBuffer.length(); i++)
           {
           		cout << (int)(lineBuffer.at(i) - '0') << "== " << arr[(int)(lineBuffer.at(i) - '0')] << endl;
           		if(((int)(lineBuffer.at(i) - '0')) == arr[i])
           		{
           			count++;	
           			cout << "Count " << count << endl;
           			
           			
           		}

           		else
           		{
           			cout << "0" << endl;
           			break;
           		}
           }
           cout << endl;

           if(count == lineBuffer.length())
           {
           		cout << "1" << endl;
           }
       }
}

	return 0;
}