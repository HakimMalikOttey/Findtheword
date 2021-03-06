// Findtheword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Record.h"
#include <algorithm>
#include <sstream> 
#include <exception>
using namespace std;
//using std::getline;
int main()
{
	//Stores player made words
	vector<string>store;
	//Stores words within Hobbit.txt
	vector<string>file;
	vector<string>whatfound;
	string get;
	string word;
	ifstream infile;
	string wordstore;
	string test;
	int line = 0;
	int user = 0;
	int counter = 0;
	//Takes each word from Hobbit.txt an stores them in a file to be ran through when searching for a word
	//New word defined by whitespace after it in the file
	try {									// First instance of an exception. 
		infile.open("Hobbit.txt");			//Checks to see if the file exists within the folder that the program is in.
		if (!infile.is_open()) {			//If program does not detect a file, then it will inform the user and continue operations
			throw "file does not exist";	//Things that were supposed to be written from the program will not be taken from it
		}									//
		else {								// 
			while (infile >> word) {		//
				file.push_back(word);		// 1 
			}								//
		}									//
		infile.close();						//
	}										//
		catch (const char* msg) {			//
			cout << msg << endl;			//
		}									//

		while (true) {
			//Gives player selectable options
			line = 0;																												//fifth instance of an exception. 
			cout << "\n\n\nType 1 to type in your words \nType 2 to see if your words are in the lord of the rings" << endl;		//Checks to see if the user inputs a character ( a , b , c ,d) or anything that just isn't a number ( /, ., #)
			try {																													//If user inputs these illegal inputs, program will write the error onto console and restart from the point before the error
				cin >> test;																										// Also picks up when user inputs anything that is not 1 or 2
				user = stoi(test);																									// 
				if (user < 1 || user > 2) {																							//
					throw 1;																										// 5 
				}																													//
				else {																												//

					switch (user) {
						//Option 1 
					case 1:
					{
						store.clear();
						line = 0;
						//Stores user made words into vector
						do {															//second instance of an exception. 
							cout << "type in a word. " << line << " to go" << endl;		//Checks to see if the user has inputted something into the field
							try {														//if user tries to submit an empty field, then an error will be written out on console and the program will to restart to before the error was made
								getline(cin, get);										//
								if (get.empty()) {										//
									throw "Please input something into the field";		//
								}														//
								else {													//
									if (line == 10) break;								// 2 
									store.push_back(get);								//
									line++;												//
								}														//
							}															//
							catch (const char* msg) {									//
								cout << msg << endl;									//
							}															//
						} while (line != 10);
						cout << "These words will be saved" << endl;
						for (unsigned int a = 0; a < store.size(); a++) {
							cout << "Word " << a << " " << store[a] << endl;
							//Takes words out of vector<string>store and stores them into file
						}
						cout << "Saving!" << endl;
						try {															//third instance of an exception. 
							ofstream outfile("Wordstore.txt");							//Checks to see if the file is available to be accessed 
							if (!outfile.is_open()) {									//if it is not, then an error will be sent out, whatever the user wrote before will not be saved, and the program will go back to the main menu
								throw "Can not print to file";							//
							}															//
							else {														//
								for (unsigned int a = 0; a < store.size(); a++) {		//
									outfile << store[a] << endl;						//
								}														//3 
								store.clear();											//
								outfile.close();										//
							}															//
						}																//
						catch (const char* msg) {										//
							cout << msg << endl;										//
						}																//
					}																	//
					continue;
					//option 2
					case 2:
						store.clear();																		//Fourth instance of an exception. 
						try {																				// Checks to see if the file "wordstore" is available
							infile.open("Wordstore.txt");													// if wordstore is not available than an error will be written and the program will boot back to the main menu 
							if (!infile.is_open()) {														//
								throw "file does not exist";												//
							}																				//
							else {																			//
								//Takes words out of the file and stores them into vector<string>store		//
								//New line/word defined by present whitespace on file						//
								cout << "Reading from file" << endl;										//
								while (getline(infile, get)) {												// 4 
									infile >> get;															//
									store.push_back(get);													//
																											//
								}																			//
								infile.close();																//
							}																				//
																											//
						}																					//
						catch (const char* msg) {															//
							cout << msg << endl;															//
						}																					//
						{
							ofstream outfile("whatfound.txt");
							//Selects the next word in vector<string>store to be used to find a duplicate in Hobbit file 
							for (unsigned int i = 0; i < store.size(); i++) {
								//Stores result of search in file
								outfile << wordstore << " was present " << counter << " times in the first three paragraphs of the Lord of the rings\n" << endl;
								counter = 0;
								//Stores selected word 
								wordstore = store[i];
								for (unsigned int i = 0; i < file.size(); i++) {
									if (wordstore == file[i]) {
										//tracks how many times selected word has appeared in Hobbit file
										counter++;
									}
								}
								cout << wordstore << " was present " << counter << " times in the first three paragraphs of the Lord of the rings\n" << endl;
							}
							outfile.close();
						}


						continue;
						//Exception. Prevents bad input from player from going through
					default:
						continue;
						cin.get();
					} while (true);
				}
				return 0;
			}
			catch (int x) {											//
				cout << "This is not a valid input" << endl;		//
			}														//
			catch (exception& e) {									//
				cout << "Exception:  " << e.what() << endl;			//5 
			}														//
			catch (...) {											//
				cout << "Bad input" << endl;						//
			}														//

		}
	}
