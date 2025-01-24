#ifndef MUSIC_MANAGEMENT_H
#define MUSIC_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Definitions for music class
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class music {
public:
    music();
    music(int songid, string artist, string duration, string title);
    int musicId = 0;
    string artistName;
    string musicLength;
    string musicTitle;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Definitions for groups
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class groups {
public:
    groups();
    groups(int num, int size);
    void resize();
    void insert(const music& song);
    void addmusic(const music& song);
    void removemusic(int songid);
    void seemusic(int songid);
    bool contains(int songid);
    int findIdx(int songid);
    int nummusic = 0;
    int capacity = 1;
    music get(int songid);
    music* getPointer(int songid);
    music* allmusic = new music[1];
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Definitions for Album
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class Album {
public:
    Album();
    Album(int albumid, string albumname);
    Album(int num, int size);
    void setId(int albumid);
    void setName(string albumname);
    void insert(const music& song);
    void addSong(const music& song);
    void removeSong(int songid);
    void seeSong(int songid);
    void printSongs();
    void resize();
    int nummusic = 0;
    int capacity = 1;
    int albumId = 0;
    int findIdx(int songid);
    bool contains(int songid);
    music get(int songid);
    music* getPointer(int songid);
    music* album = new music[1];
    string albumName;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//Definitions for Pgroup
//--------------------------------------------------------------------------------------------------------------------------------------------------------
class pgroup {
public:
    pgroup();
    Album get(int albumid);
    Album* getPointer(int albumid);
    bool contains(int albumid);
    int findIdx(int albumid);
    void seeAlbum(int albumid);
    void addSongtoAlbum(int songid, int albumid, groups* allSongs);
    void drop(int songid, int albumid, groups* allSongs);
    void deleteAlbum(int albumid);
    void copyAlbum(int albumid, int newAlbumId, string newAlbumName);
    void renameAlbum(int albumid, string newAlbumName);
    void removeSong(int songid);
    void newAlbum(int albumid, string albumname);
    vector<Album> library;
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------
#endif // MUSIC_MANAGEMENT_H

