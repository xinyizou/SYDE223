#include <iostream>
#include <string>
#include <vector>
#include <time.h>
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

    bool operator==(const Music& target) {
//        if (artist_name == target.artist_name && music_id == target.music_id && year == target.year) {
//            return true;
//        }
//
//        else {
//            return false;
//        }
        bool is_same = true;
        is_same = is_same && (artist_name == target.artist_name);
        is_same = is_same && (music_id == target.music_id);
        is_same = is_same && (year == target.year);
        return is_same;
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
        Music(new_artist_name, new_music_id, new_year);
        genre = new_genre;
        song_name = new_song_name;
        song_length = new_song_length;
    };

    bool operator==(Song& target) { //TODO: how do we implement const in an overloaded operator
        bool are_equal = true;
        are_equal = are_equal && (static_cast<Music>(target) == static_cast<Music>(*this));
//       are_equal = static_cast<Music>(target) == static_cast<Music>(*this);
       are_equal = are_equal && genre == target.get_genre();
       are_equal = are_equal && song_name == target.get_song_name();
       are_equal = are_equal && song_length == target.get_song_length();

        return are_equal;
    };

    string get_genre() {
        return genre;
    };
    string get_song_name() {
        return song_name;
    };
    unsigned int get_song_length() {
        return song_length;
    };
};


class Playlist {
    vector<Song> my_playlist;

public:
    friend Playlist operator+(const Playlist& playlist1, const Playlist& playlist2);

    Playlist () : my_playlist(vector<Song>()){}

    Playlist(vector<Song> new_playlist) : my_playlist(new_playlist) {}

    bool insert_song (Song& song_info) {
        if (is_valid(my_playlist, song_info)) {
            my_playlist.push_back(song_info);
            return true;
        }
        else {
            return false;
        }

    }

    Playlist shuffle_songs() {

    int random = ( rand() % my_playlist.size());
    vector<int> existing_values;
    Playlist shuffled_playlist();

    if(is_random(random, existing_values)) {

    }

    };
private:
    bool is_valid(vector<Song>& my_playlist, Song& song_info) {
        int artist_count = 0;
        bool is_valid = true;
        for (vector<Song>::iterator my_iterator = my_playlist.begin(); my_iterator != my_playlist.end() && is_valid; ++ my_iterator) {
            if (*my_iterator == song_info) {
                is_valid = false;
            }
            if (my_iterator->get_artist() == song_info.get_artist()) {
                artist_count += 1;
            }
            if (artist_count >= 3) {
                return false;
            }
        }
        return is_valid;
    }

    bool is_random(int value, vector<int> existing_values) {
        bool is_random= true;

    }




};

//TODO: ask about implicit constructor

Playlist operator+(const Playlist& playlist1, const Playlist& playlist2) {

}


int main () {
    srand(time(0));
    return 0;
};

