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
    Song();

    Song(string new_artist_name, unsigned int new_year, string new_music_id, string new_genre, string new_song_name, unsigned int new_song_length);

    bool operator == (Song& target) const;

    string get_genre();
};


class Playlist {
    vector<Song> my_playlist;

public:
    friend Playlist operator+(const Playlist& playlist1, const Playlist& playlist2);

    Playlist () : my_playlist(vector<Song>()){}

    Playlist(vector<Song> new_playlist) : my_playlist(new_playlist) {}

    bool insert_song (Song& song_info) {
        if (is_valid()) {
            my_playlist.push_back(song_info);
            return true;
        }
        else {
            return false;
        }

    }

private:
    bool is_valid() {
        int artist_count = 0;
        for (vector<Song>::iterator my_iterator = my_playlist.begin(); my_iterator != my_playlist.end(); ++ my_iterator) {
            if (my_iterator == song_info) {
                return false;
            }
            if (my_iterator.get_artist() == song_info.get_artist()) {
                artist_count += 1;
            }
            if (artist_count >= 3) {
                return false;
            }
        }
    }
    Playlist shuffle_songs();


};

//TODO: ask about implicit constructor


#endif //TEST_MAIN_HPP

