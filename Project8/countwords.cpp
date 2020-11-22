// countwords.cpp
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-11-21
// Updated: 2020-11-21

// For CS 311 Fall 2020
// Source file for Project 8, Exercise A

#include <iostream>
#include <string> 	// for std::string, std::getline
using std::string;
#include <fstream> 	// for std::fstream
#include <map>
#include <set>

int main()
{
	string file;
	std::fstream fin;

	// Will repeat until a valid file is opened.
	while (true)
	{
		std::cout << "Please enter the name of the file:\n";
		std::getline(std::cin, file);
		fin.open(file);

		// If file opens correctly exit loop.
		if(fin.is_open())
		{
			break;
		}

		std::cout << "Invalid file." << std::endl;
	}

	std::map<string, std::set<string>> wordmap;
	string current;
	string next;

	if(fin.is_open())
	{
		while (true)
		{
			if (current == "")
			{
				fin >> current;
			}

			fin >> next;
			if (!fin)
			{
				if (fin.eof())
				{
					wordmap[current].insert("");
					break;
				}
			}
			wordmap[current].insert(next);
			current = next;
		}
	}
	else
	{
		std::cout << "Invalid file." << std::endl;
		// Break or something here?
	}

	std::cout << "Number of distinct words: " << wordmap.size() << std::endl;


}