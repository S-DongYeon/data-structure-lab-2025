#pragma once
#include <iostream>		//입출력
#include <string>		//문자열
#include <vector>

using namespace std;

class Music
{
private:
	string title;
	string artist;
	string album;
	int year;

public:
	//생성자
	Music(string title, string artist, string album, int year)
	{
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}

	//Getters
	string getTitle()
	{
		return title;
	}
	string getArtist()
	{
		return artist;
	}
	string getAlbum()
	{
		return album;
	}
	int getYear()
	{
		return year;
	}
};

class MusicStreamingService
{
private:
	string service_name;
	vector<Music> music_list;

public:
	//생성자
	MusicStreamingService(string service_name)
	{
		this->service_name = service_name;
	}
	//음악 추가 기능
	void addMusic(string title, string artist, string album, int year)
	{
		Music new_music(title, artist, album, year);
		music_list.push_back(new_music);
		cout << title << " by " << artist << " added to " << service_name << endl;
	}
	//음악 찾아주는 서비스(Title로 검색)
	Music* searchbyTitle(string title)
	{
		for (int i = 0; i < music_list.size(); i++)
		{
			if (music_list[i].getTitle() == title)
			{
				return &music_list[i];
			}
		}
		return NULL;
	}
	//음악 찾아주는 서비스(Artist로 검색)
	vector<Music*> searchbyArtist(string artist)
	{
		vector<Music*> result;
		for (int i = 0; i < music_list.size(); i++)
		{
			if (music_list[i].getArtist() == artist)
			{
				result.push_back(&music_list[i]); //music_list + i도 가능
			}
		}
		return result;
	}
};