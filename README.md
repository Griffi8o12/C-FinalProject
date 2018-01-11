# C-FinalProject
SongIndexer

## Synopsis

This is a song indexing program that will assist musicians learn a plethora of songs, being able to visualize a long list and practice accordingly.
Code Example

cout << "Enter band name: ";
getline(cin, band);

cout << "Enter song name: ";
getline(cin, song);
	
cout << "How difficult was the song for you (1-5 stars): ";
getline(cin, difficulty);

cout << "How much of the song do you know : "; getline(cin,far);

songs << band << '#' << song << '?' << c << '^' << far << '(' << endl;

## Motivation

I personally, had difficulty remembering songs I had practiced in my early days playing the guitar, with this program, I aim to help strengthen muscle memory, and keep a diverse and numerous "song bank" to play at will.
Installation
Tests

The menu displayed will add, search, and display songs by a couple different categories

Adding Entries:

cout << "Enter band name: "; getline(cin, band);

cout << "Enter song name: ";
getline(cin, song);
	
cout << "How difficult was the song for you (1-5 stars): ";
getline(cin, difficulty);

cout << "How much of the song do you know : "; getline(cin,far);

songs << band << '#' << song << '?' << c << '^' << far << '(' << endl;

Searching by Band name:

cout << "Enter the band: "; getline(cin, bandEntry);

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

## Contributors

Add and start creating your list of song, and set-lists that you need to get perfect before the next gig.
