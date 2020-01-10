//
// Created by Yonael Miheret Debebe on 2020-01-10.
//

#include "main.hpp"

#include <iostream>
using namespace std

class Music:
        vars: string artist name, unsigned int year of made, string music
        empty constructor: default year 0, all else empty string
        parametric constructor
        overloaded operator==
public: string get_artist()

child class of music: Song:
vars: string genre, string song name, unsigned int song length
empty constructor, uint 0, empty strings
parametric constructor
overloaded operator==
getter optional

to use song instance as music, use static_cast<Music>(song_info) <-- this is probably for a comparison


class Playlist:
        vars: vector of Song instances: vector<Song> my_playlist;
        no explicit constructor
        methods: bool insert_song(Song& song_info), Playlist shuffle_songs()
        for insert_song method: no duplicate Songs, no more than 3 songs by same artist, returns true if succeeds in adding, false otherwise
        for shuffle_songs method: returns a Playlist in random order

        randomization: srand(time(0))

overloaded operator+ as non-member friend function: combines 2 playlists and returns 1 Playlist instance with all Songs

class TestDriver: runs through all scenarios with assertions