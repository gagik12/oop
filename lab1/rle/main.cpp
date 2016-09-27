#include <iostream>
#include <fstream>
#include <string>

using namespace std;



void PackFile(ifstream & inputFile, ofstream & outputFile)
{
	char ch;
	int countChar = 0;
	while (!inputFile.eof())
	{
		inputFile.read((char*)&ch, sizeof(char));
		++countChar;
		if ((ch != (char)inputFile.peek()) || (countChar == 255))
		{
			outputFile.write((char*)&countChar, sizeof(char));
			outputFile.write(&ch, sizeof(char));
			countChar = 0;
		}
	}
}

void UnpackFile(ifstream & inputFile, ofstream & outputFile)
{
	char ch;
	char value;
	while (!inputFile.eof())
	{
		inputFile.read((char*)&value, sizeof(char));
		inputFile.read((char*)&ch, sizeof(char));
		if (ch == (char)'h')
		{
			cout << "1" << value << endl;
		}
		int digit = unsigned char(value);
		for (int i = 0; i < digit; ++i)
		{
			outputFile << ch;
		}
		if (inputFile.peek() == EOF)
		{
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: rle.exe unpack <input file> <output file>\n";
		return 1;
	}

	ifstream inputFile(argv[2], ios::binary | ios::in);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	ofstream outputFile(argv[3], ios::binary | ios::out);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return 1;
	}

	string mode = argv[1];
	if (mode == "pack")
	{
		PackFile(inputFile, outputFile);
	}
	else if (mode == "unpack")
	{
		UnpackFile(inputFile, outputFile);
	}
	else
	{
		cout << "You have not correctly specified the parameter <unpack || pack>\n";
		return 1;
	}
	return 0;

}