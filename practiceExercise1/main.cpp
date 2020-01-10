#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Music {
    string artist_name;
    string music_id;
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
    }

    Song(string new_artist_name, unsigned int new_year, string new_music_id, string new_genre, string new_song_name, unsigned int new_song_length) {
        Music(new_artist_name, new_music_id, new_year);
        genre = new_genre;
        song_name = new_song_name;
        song_length = new_song_length;
    }

    bool operator==( Song& target) { //TODO: how do we implement const in an overloaded operator
       bool are_equal = true;
       are_equal = are_equal && (static_cast<Music>(target) == static_cast<Music>(*this));
       are_equal = are_equal && genre == target.get_genre();
       are_equal = are_equal && song_name == target.get_song_name();
       are_equal = are_equal && song_length == target.get_song_length();

        return are_equal;
    }

    string get_genre() {
        return genre;
    }
    string get_song_name() {
        return song_name;
    }
    unsigned int get_song_length() {
        return song_length;
    }
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

        vector<int> new_order;
        Playlist shuffled_playlist();



        for(int i=0; new_order.size() <= my_playlist.size(); i++ ) {
            int random = ( rand() % my_playlist.size());


            if(is_random(random, new_order)) {
                new_order.push_back(random);
            }
        }

        for(vector<int>::iterator my_it = new_order.begin(); my_it != new_order.end(); ++my_it) {
            shuffled_playlist().insert_song(my_playlist[*my_it]);
        }

        return shuffled_playlist();



    };
private:
    bool is_valid(vector<Song>& my_playlist, Song& song_info) {
        int artist_count = 0;
        bool is_valid = true;
        for (vector<Song>::iterator my_it = my_playlist.begin(); my_it != my_playlist.end() && is_valid; ++ my_it) {
            if (*my_it == song_info) {
                is_valid = false;
            }
            if (*my_it == song_info.get_artist()) {
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

        for(vector<int>::iterator my_it = existing_values.begin(); my_it != existing_values.end() && is_random; ++my_it) {
            if (*my_it == value) {
                is_random = false;
            }
        }

        return is_random;
    }




};

//TODO: ask about implicit constructor

Playlist operator+(const Playlist& playlist1, const Playlist& playlist2) {
    vector<Song> combined_playlist;
    combined_playlist.insert(combined_playlist.end(), playlist1.my_playlist.begin(), playlist1.my_playlist.end());
    combined_playlist.insert(combined_playlist.end(), playlist2.my_playlist.begin(), playlist2.my_playlist.end());
//TODO: ask if using insert is ok if not use a for loop to popback each element of second vector
    return combined_playlist;
}


int main () {
    srand(time(0));
    return 0;
};

