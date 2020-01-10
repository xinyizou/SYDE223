//
// Created by Yonael Miheret Debebe on 2020-01-10.
//


#include <iostream>
#include <vector>
using namespace std;

class Music {
    string artist_name, music_id;
    unsigned int year;

public:
    Music() {
        artist_name = "";
        music_id = "";
        year = 0;
    }

    Music(string new_artist_name, string new_music_id, unsigned int new_year) {
        artist_name = new_artist_name;
        music_id = new_music_id;
        year = new_year;
    }

    bool operator == (Music& target) const {
        if (artist_name == target.artist_name && music_id == target.music_id && year == target.year) {
            return true;
        }

        else {
            return false;
        }
    }

    //TODO: look up constant member function and constant parameters
    string get_artist() {
        return artist_name;
    }
};

class Song : public Music {
    string genre;
    string song_name;
    unsigned int song_length;

public:
    Song() {
        genre = "";
        song_name = "";
        song_length = 0;
    };

    Song(string new_artist_name, unsigned int new_year, string new_music_id, string new_genre, string new_song_name, unsigned int new_song_length) {
        Music(new_artist_name,  new_year, new_music_id);
        genre = new_genre;
        song_name = new_song_name;
        song_length = new_song_length;
    };

    bool operator == (Song& target) const {

        bool are_equal = false;


       are_equal = static_cast<Music>(target) == static_cast<Music>(*this);
       are_equal = are_equal && genre == target.get_genre();
       are_equal = are_equal && song_name == target.get_song_name();
       are_equal = are_equal && song_length == target.get_song_length();

        return are_equal;
    };

    string get_genre() {
        return genre;
    };
    string get_song_name() {
        return  song_name;
    };

    unsigned int get_song_length() {
        return song_length;
    };
};


class Playlist {
    vector<Song> my_playlist;

public:
    friend Playlist operator+(const Playlist& playlist1, const Playlist& playlist2);

    Playlist () : my_playlist(vector<Song>){};

    bool insert_song (Song& song_info);
    Playlist shuffle_songs();


};

//TODO: ask about implicit constructor


int main ();

