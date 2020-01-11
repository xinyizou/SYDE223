#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cassert>
#include <limits>
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

    unsigned int get_year() {
        return year;
    }
    string get_music_id() {
        return music_id;
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

    Song(Music new_music, string new_genre, string new_song_name, unsigned int new_song_length) : Music(new_music), genre(new_genre), song_name(new_song_name), song_length(new_song_length) { }

    bool operator==(Song& target) { //TODO: how do we implement const in an overloaded operator
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
        Playlist shuffled_playlist;

        for(int i=0; new_order.size() < my_playlist.size(); i++ ) {
            int random = rand() % my_playlist.size();

            if(is_random(random, new_order)) {
                new_order.push_back(random);
            }
        }

        for(vector<int>::iterator my_it = new_order.begin(); my_it != new_order.end(); ++my_it) {
            shuffled_playlist.insert_song(my_playlist[*my_it]);
        }

        return shuffled_playlist;
    }

    vector<Song> get_my_playlist() {
        return my_playlist;
    }

private:
    bool is_valid(vector<Song>& my_playlist, Song& song_info) {
        int artist_count = 0;
        bool is_valid = true;
        for (vector<Song>::iterator my_it = my_playlist.begin(); my_it != my_playlist.end() && is_valid; ++ my_it) {
            if (*my_it == song_info) {
                is_valid = false;
            }
            if (my_it->get_artist() == song_info.get_artist()) { //TODO: Research get_artist and pointer iterator stuff
                artist_count += 1;
            }
            if (artist_count >= 3) {
                is_valid = false;
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

class MusicTest {
    Music music;
    Music empty_music;

public:
    void setup() {
       music = Music("Annie", "223", 2020);
    };

    bool test_default_constructor() {
        assert(empty_music.get_artist() == "" && empty_music.get_music_id() == "" && empty_music.get_year() == 0);
        return true;
    };

    bool test_parametric_constructor() {
        assert(music.get_artist() == "Annie" && music.get_music_id() == "223" && music.get_year() == 2020);
        return true;
    };

    bool test_equals() {
        Music new_music("Igor", "121", 2018);
        Music same_music("Annie", "223", 2020);

        bool equal = music == same_music;
        bool not_equal = !(new_music == music);

        assert( equal && not_equal);
        return true;
    };

    bool test_get_artist() {
        assert(music.get_artist() == "Annie");
        return true;
    };

    bool test_get_music_id() {
        assert(music.get_music_id() == "223");
        return true;
    };

    bool test_get_year() {
        assert(music.get_year() == 2020);
        return true;
    }
};

class SongTest {
    Song test_empty_song;
    Song test_song;
    Song same_song;
    Song different_song;

public:
    void setup() {
        test_song = Song(Music("Celine Dion", "123abc", 2020), "Soul", "Ashes", 123);
        same_song = test_song;
        different_song = Song(Music("Michael Jackson", "456def", 1980),"Pop", "Smooth Criminal", 456);
    }

    bool test_get_genre() {
        assert(test_song.get_genre() == "Soul");
        return true;
    }
    bool test_get_song_name() {
        assert(test_song.get_song_name() == "Ashes");
        return true;
    }
    bool test_get_song_length() {
        assert(test_song.get_song_length() == 123);
        return true;
    }

    bool test_default_constructor() {
        assert(test_empty_song.get_artist() == "" && test_empty_song.get_year() == 0 && test_empty_song.get_music_id() == "" && test_empty_song.get_genre() == "" && test_empty_song.get_song_name() == "" && test_empty_song.get_song_length() == 0);
        return true;
    }
    bool test_parametric_constructor() {
        assert(test_song.get_artist() == "Celine Dion" && test_song.get_year() == 2020 && test_song.get_music_id() == "123abc" && test_song.get_genre() == "Soul" && test_song.get_song_name() == "Ashes" && test_song.get_song_length() == 123);
        return true;
    }

    bool test_operator() {
        bool is_equal = test_song == same_song;
        bool not_equal = test_song == different_song;
        assert(is_equal == true);
        assert(not_equal == false);
        return true;
    }

    void tear_down() {}

    void run_test() {
        setup();
        cout << (test_get_genre() ? "Test Get Genre Passed" : "Test Get Genre Failed") << endl;
        cout << (test_get_song_name() ? "Test Get Song Name Passed" : "Test Get Song Name Failed") << endl;
        cout << (test_get_song_length() ? "Test Get Song Length Passed" : "Test Get Song Length Failed") << endl;
        cout << (test_default_constructor() ? "Test Default Constructor Passed" : "Test Default Constructor Failed") << endl;
        cout << (test_parametric_constructor() ? "Test Parametric Constructor Passed" : "Test Parametric Constructor Failed") << endl;
        cout << (test_operator() ? "Test Operator== Passed" : "Test Operator== Failed") << endl;
        tear_down();
    }
};

class PlaylistTest() {

Playlist empty_playlist;
Playlist playlist;

public:
void setup() {
    playlist.insert_song(test_song);
}

bool test_empty_constructor() {
    Playlist test_playlist;
    assert(empty_playlist.get_my_playlist() == test_playlist);
    return true;
};

}


class ConcatenatePlaylistTest {
    Song song;
    Playlist playlist1;
    Playlist playlist2;
    Playlist concat_playlist;

public:
    void setup() {
        vector<Song> new_playlist1(3, song);
        vector<Song> new_playlist2(5, song);
        playlist1 = Playlist(new_playlist1);
        playlist2 = Playlist(new_playlist2);
    }

    bool testConcatentation() {
        concat_playlist = playlist1 + playlist2;
        assert(concat_playlist.get_my_playlist().size() == playlist1.get_my_playlist().size() + playlist2.get_my_playlist().size());
        return true;
    }

    void tear_down() {}

    void run_test() {
        setup();
        cout << (testConcatentation() ? "Test Operator+ Passed" : "Test Operator+ Failed") << endl;
        tear_down();
    }
};

int main () {
    srand(time(0));

    cout << "Testing" << endl;
    SongTest st;
    st.run_test();
    ConcatenatePlaylistTest cpt;
    cpt.run_test();

    cout << "\nProgram is ready" << endl;
    bool exit = false;
    int command = 0;
    do {
        cout << "Enter a command.\n1 = insert a song\n2 = shuffle playlist\nEnter 9 to exit" << endl;

        while(!(cin >> command)){
            cout << "Bad value!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while(command != 9);

    cout << "Program exited" << endl;

    return 0;
};