#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <cassert>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
    		size_t numLetters = k.size(); // determine how many letters

				unsigned long long w[5] = {0, 0, 0, 0, 0}; // create an array of size 5 

				// determine how many 6 letter substrings need to be processed:

				size_t num_iterations = 0;

				if (numLetters <= 6)
				{
					num_iterations = 1;
				}
				else if (numLetters > 6 && numLetters <= 12)
				{
					num_iterations = 2;
				}
				else if (numLetters > 12 && numLetters <= 18)
				{
					num_iterations = 3;
				}
				else if (numLetters > 18 && numLetters <= 24)
				{
					num_iterations = 4;
				}
				else
				{
					num_iterations = 5;
				}

				// create and process substring

				int numLettersRemaining = numLetters; // numLetters that have not been processed

					// go through and deal with each 6 letter substring

					//std::cout << "num_iterations = " << num_iterations << std::endl;

				size_t widx = 0;

				for(size_t i = 0; i < num_iterations; i++)
				{

					char subString[6] = {'a', 'a', 'a', 'a', 'a'};
					size_t base36SS[6];

				
					if (numLettersRemaining >= 6) // there are 6 letters to copy
					{
						for(int j = 0; j < 6; j++) // fill substring
						{
							 subString[5 - j] = k[numLettersRemaining - 1];
							 numLettersRemaining--;
						}
					}
					else if (numLettersRemaining < 6) // less than six letters to process
					{

			//			std::cout << "numLettersRemaining = " << numLettersRemaining << std::endl;
						
						int temp = numLettersRemaining;
						
						for (int j = 0; j < temp; j++)
						{
							 subString[5 - j] = k[numLettersRemaining - 1]; // -1
							 numLettersRemaining--;
						}

					}

					// map substring to base 36

					for (int j = 0; j < 6; j++)
					{
						base36SS[j] = letterDigitToNumber(subString[j]);
					}

					// convert to base 10

					for (int j = 0; j < 6; j++)
					{
					//	std::cout << "subString" << j << "] = " << subString[j] << std::endl;
					}

					for (int j = 0; j < 6; j++)
					{
						//std::cout << "base36SS[" << j << "] = " << base36SS[j] << std::endl;
					}

					//std::cout << "widx = " << widx << std::endl;

					w[4 - widx] = ((((((base36SS[0])*36 + base36SS[1])*36 + base36SS[2])*36 + base36SS[3])*36 + base36SS[4])*36 + base36SS[5]);

					widx++;

				}

				HASH_INDEX_T hash = 0;

        for (size_t i = 0; i < 5; i++)
        {
            hash += rValues[i] * w[i];
        }

					for (int i = 0; i < 5; i++)
				{
				//	std::cout << "w[" << i << "] = " << w[i] << std::endl;
				}

        return hash;

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it

			//	std::cout << "letter = " << letter << std::endl;

			if (letter >= 'A' && letter <= 'z') // likely upper case or lower case letter
			{
				if (letter == 'a' || letter == 'A')
				{
						return 0;
				}
				else if (letter == 'b' || letter == 'B')
				{
						return 1;
				}
				else if (letter == 'c' || letter == 'C')
				{
						return 2;
				}
				else if (letter == 'd' || letter == 'D')
				{
						return 3;
				}
				else if (letter == 'e' || letter == 'E')
				{
						return 4;
				}
				else if (letter == 'f' || letter == 'F')
				{
						return 5;
				}
				else if (letter == 'g' || letter == 'G')
				{
						return 6;
				}
				else if (letter == 'h' || letter == 'H')
				{
						return 7;
				}
				else if (letter == 'i' || letter == 'I')
				{
						return 8;
				}
				else if (letter == 'j' || letter == 'J')
				{
						return 9;
				}
				else if (letter == 'k' || letter == 'K')
				{
						return 10;
				}
				else if (letter == 'l' || letter == 'L')
				{
						return 11;
				}
				else if (letter == 'm' || letter == 'M')
				{
						return 12;
				}
				else if (letter == 'n' || letter == 'N')
				{
						return 13;
				}
				else if (letter == 'o' || letter == 'O')
				{
						return 14;
				}
				else if (letter == 'p' || letter == 'P')
				{
						return 15;
				}
				else if (letter == 'q' || letter == 'Q')
				{
						return 16;
				}
				else if (letter == 'r' || letter == 'R')
				{
						return 17;
				}
				else if (letter == 's' || letter == 'S')
				{
						return 18;
				}
				else if (letter == 't' || letter == 'T')
				{
						return 19;
				}
				else if (letter == 'u' || letter == 'U')
				{
						return 20;
				}
				else if (letter == 'v' || letter == 'V')
				{
						return 21;
				}
				else if (letter == 'w' || letter == 'W')
				{
						return 22;
				}
				else if (letter == 'x' || letter == 'X')
				{
						return 23;
				}
				else if (letter == 'y' || letter == 'Y')
				{
						return 24;
				}
				else if (letter == 'z' || letter == 'Z')
				{
						return 25;
				}

			}
			else if(letter >= '0' && letter <= '9') // letter is a digit '0' through '9'
			{
				if (letter == '0')
				{
					return 26;
				}
				else if (letter == '1')
				{
					return 27;
				}
				else if (letter == '2')
				{
					return 28;
				}
				else if (letter == '3')
				{
					return 29;
				}
				else if (letter == '4')
				{
					return 30;
				}
				else if (letter == '5')
				{
					return 31;
				}
				else if (letter == '6')
				{
					return 32;
				}
				else if (letter == '7')
				{
					return 33;
				}
				else if (letter == '8')
				{
					return 34;
				}
				else if (letter == '9')
				{
					return 35;
				}
			}

    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
