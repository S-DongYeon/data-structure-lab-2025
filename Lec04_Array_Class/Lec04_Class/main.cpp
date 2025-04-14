#include "Complex.h"
// #include "Car.h" 해도 되는데 굳이 안해도됨
//#include "SportsCar.h"
#include "Music.h"

int main()
{
	//music streaming service 생성
	MusicStreamingService my_service("spotify");
	//add music to music streaming service
	my_service.addMusic("Home_Sweet_Home", "G-DRAGON", "HOME_SWEET_HOME", 2025);
	my_service.addMusic("Home_Sweet_Home", "CarTheGarden", "APARTMENT", 2022);
	my_service.addMusic("Holiday", "Green Day", "American_Idiot", 2004);
	my_service.addMusic("Dont_Stop_Believin", "Journey", "Time3", 1992);
	my_service.addMusic("Lost_in_my_room", "Offical_HIGE_DANdism", "Editorial", 2021);
	my_service.addMusic("Soul_Soup", "Offical_HIGE_DANdism", "Editorial", 2021);

	//add music to music streaming service by user input
	string title, artist, album;
	int year;
	cout << "Enter the title of the music: ";
	cin >> title;
	cout << "Enter the artist of the music: ";
	cin >> artist;
	cout << "Enter the album of the music: ";
	cin >> album;
	cout << "Enter the year of the music: ";
	cin >> year;
	my_service.addMusic(title, artist, album, year);

	//search music by title
	string music_title;
	cout << "Enter the title of the music: ";
	cin >> music_title;
	Music* result = my_service.searchbyTitle(music_title);
	if (result != NULL)
	{
		cout << "Found: " << result->getTitle() << " by " << result->getArtist() << endl;
	}
	else
	{
		cout << "Music not found!" << endl;
	}

	//search music by artist
	string artist_name;
	cout << "Enter the artist of the music: ";
	cin >> artist_name;
	vector<Music*> artist_results = my_service.searchbyArtist(artist_name);
	if (artist_results.size() > 0)
	{
		cout << "Found " << artist_results.size() << " song by " << artist_name << ":" << endl;
		for (int i = 0; i < artist_results.size(); i++)
		{
			cout << artist_results[i]->getTitle() << endl;
		}
	}
	else
	{
		cout << "No music found by this artist!" << endl;
	}
}