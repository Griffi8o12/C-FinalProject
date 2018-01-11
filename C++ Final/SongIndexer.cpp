#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

void addSong(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far);
void searchSong(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far);
void searchDiff(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far);
void displayIndex(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far);
void setList(ofstream& list ,string band, string song, string c, string far);
void displaySet(ifstream& list, string band, string song, string c, string far);
void searchBand(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far);

int main() 
{
	int menu = 0;
	string band;
	string song;
	string difficulty;
	string c;
	string entry;
	string far;
		
	ofstream songs;
	ifstream songsOut;
	ofstream list;
	ifstream listOut;
	
	while(menu != -1)
		{
			cout << endl;
			cout << "Welcome to your Song Indexer" << endl;
			cout << "Enter a -1 if you are finished with the program." << endl << endl;
			cout << "1 - Add Song & Band" << endl;
			cout << "2 - Search song by band" << endl;
			cout << "3 - Search by Difficulty" << endl;
			cout << "4 - Display Index" << endl;
			cout << "5 - Create a 10 song set-list" << endl;
			cout << "6 - Display 10 song set-list" << endl;
			cout << "7 - Search Band by Song " << endl << endl;
			cout << "-";
			cin >> menu;
			cin.ignore(100, '\n');
			
			if(menu == 1)
			{
				addSong(songs, songsOut, band, song, difficulty, c, far);
			}
			else if (menu == 2)
			{
				searchSong(songs, songsOut, band, song, difficulty, c, far);	
			}
			else if (menu == 3)
			{
				searchDiff(songs, songsOut, band, song, difficulty, c, far);		
			}
			else if (menu == 4)
			{
				displayIndex(songs, songsOut, band, song, difficulty, c, far);		
			}
			else if(menu == 5)
			{
				setList(list,band, song, c, far);
			}
			else if(menu == 6)
			{
				displaySet(listOut,band, song, c, far);
			}
			else if(menu == 7)
			{
				searchBand(songs,songsOut ,band, song,difficulty,c,far);
			}
		
		}//end of while

}//end of Main

void addSong(ofstream& songs, ifstream& songsOut , string band, string song, string difficulty, string c, string far)
{	
	
	songs.open("Index.txt", ios::app);
	
	cout << "Enter band name: ";
	getline(cin, band);
	
	cout << "Enter song name: ";
	getline(cin, song);
		
	cout << "How difficult was the song for you (1-5 stars): ";
	getline(cin, difficulty);
	
	if(difficulty == "1")
	{
		c = "*";
	}
	else if(difficulty == "2")
	{
		c = "**";
	}
	else if(difficulty == "3")
	{
		c = "***";
	}
	else if(difficulty == "4")
	{
		c = "****";
	}
	else if(difficulty == "5")
	{
		c = "*****";
	}
	else
	{
		while(difficulty != "1" && difficulty != "2" && difficulty != "3" && difficulty != "4" && difficulty != "5")
		{
			cout << "Rating not recognized, please re-enter your difficulty rating(1-5): ";
			getline(cin, difficulty);
			if(difficulty == "1")
				{
					c = "*";
				}
				else if(difficulty == "2")
				{
					c = "**";
				}
				else if(difficulty == "3")
				{
					c = "***";
				}
				else if(difficulty == "4")
				{
					c = "****";
				}
				else if(difficulty == "5")
				{
					c = "*****";
				}
		}			
	}
		
	cout << "How much of the song do you know : ";
	getline(cin,far);
	
	songs << band << '#' << song << '?' << c << '^' << far << '(' << endl;
	
	songs.close();
}//end of addSong function

void searchSong(ofstream& songs, ifstream& songsOut , string band, string song, string difficulty, string c, string far)
{
	bool isFound;
	string bandEntry;
	
	songsOut.open("Index.txt");
	
	cout << "Enter the band: ";
	getline(cin, bandEntry); 
		
	isFound = false;
	while(!songsOut.eof())
	{
		getline(songsOut, band, '#');
		getline(songsOut, song, '?');
		getline(songsOut, c, '^');
		getline(songsOut, far);
		if(band == bandEntry)
		{
			isFound = true;
			cout << band << "--" << song << " " << c << endl;
		}
	}
	
	if (isFound == false)
	{
		cout << "Band not found in index.";
	}
	songsOut.close();
}//end of Search Song function

void searchDiff(ofstream& songs, ifstream& songsOut , string band, string song, string difficulty, string c, string far)
{
	bool diffFound;
	string diffEntry;
	string fileDiff;
	
	songsOut.open("Index.txt", ios::in);
	
	cout << "Enter the difficulty rating of the songs you want to search: ";
	cin >> diffEntry;
	
	if(diffEntry == "1")
	{
		fileDiff = "*";
	}
	else if(diffEntry == "2")
	{
		fileDiff = "**";
	}
	else if(diffEntry == "3")
	{
		fileDiff = "***";
	}
	else if(diffEntry == "4")
	{
		fileDiff = "****";
	}
	else if(diffEntry == "5")
	{
		fileDiff = "*****";
	}	
	
	diffFound = false;
	while(!songsOut.eof())
	{
		getline(songsOut, band, '#');
		getline(songsOut, song, '?');
		getline(songsOut, c, '^');
		getline(songsOut, far);
		if(c == fileDiff)
		{
			diffFound = true;
			cout << endl;
			cout << band << "--" << song << " " << c <<  endl;
		}
	}
	
	if(diffFound == false)
	{
		cout << "Difficulty not found, or difficulty rating has not yet been entered";
		cout << endl;
	}
	songsOut.close();	
}// end of Search Difficulty function

void displayIndex(ofstream& songs, ifstream& songsOut , string band, string song, string difficulty, string c, string far)
{
	int display = 1;
	int display2 = 1;
	bool disIndex;
	
	songsOut.open("Index.txt", ios::in);
	
	disIndex = false;
	while(!songsOut.eof())
	{
		getline(songsOut, band, '#');
		getline(songsOut, song, '?');
		getline(songsOut, c, '^');
		getline(songsOut, far);
		if(display == display2)
		{
			disIndex = true;
			cout << band << "--" << song << " " << c << " " << far << endl;
		}
	}
	songsOut.close();
}//end of Display Index function

void setList(ofstream& list , string band, string song, string c, string far)
{
	int num = 1;
	
	list.open("setlist.txt", ios::out);
	
	for(int count = 1; count <= 10; count++)
	{
		cout << "Enter song number " << num << " for your setlist" << endl;
		
		cout << "Enter band name: ";
		getline(cin, band);
		
		cout << "Enter song name: ";
		getline(cin, song);
		
		list << band << '#' << song << "?" << endl;
		
		num++;
	}//end of for loop
		
	list.close();
}//end of setList function

void displaySet(ifstream& listOut, string band, string song, string c, string far)
{
	int display3 = 1;
	int display4 = 1;
	bool disIndex;
		
	listOut.open("setlist.txt", ios::in);
		
	disIndex = false;
	while(!listOut.eof())
	{
		getline(listOut, band, '#');
		getline(listOut, song, '?');
		if(display3 == display4)
		{
			disIndex = true;
			cout << band << "--" << song;
		}
	}
	listOut.close();
}// end of displaySet function

void searchBand(ofstream& songs,ifstream& songsOut , string band, string song, string difficulty, string c,string far)
{
	bool isFound;
	string songEntry;
		
		songsOut.open("Index.txt");
		
		cout << "Enter the song: ";
		getline(cin, songEntry); 
			
		isFound = false;
		while(!songsOut.eof())
		{
			getline(songsOut, band, '#');
			getline(songsOut, song, '?');
			getline(songsOut, c, '^');
			getline(songsOut, far);
			if(song == songEntry)
			{
				isFound = true;
				cout << endl << band << endl;
			}
		}
		
		if (isFound == false)
		{
			cout << "Song not found in index.";
		}
		songsOut.close();
}//end of searchBand function