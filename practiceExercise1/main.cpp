//
// Created by Yonael Miheret Debebe on 2020-01-10.
//

#include "main.hpp"

#include <iostream>
using namespace std

class Music {
    string artist_name;
    unsigned int year;
    string music_id;

public:

    Music();

    Music(string new_artist_name, unsigned int new_year, string new_music_id);

    bool operator == (Music& target) const;

    //TODO: look up constant member function and constant parameters
    string get_artist();
};

class Song : public Music {
    string genre;
    string song_name;
    unsigned int song_length;

public:
    Song();

    Song(string new_artist_name, unsigned int new_year, string new_music_id, string new_genre, string new_song_name, unsigned int new_song_length);

    bool operator == (Song& target) const;

    string get_genre();
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


#endif //TEST_MAIN_HPP

