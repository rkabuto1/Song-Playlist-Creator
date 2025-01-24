#include <iostream>
#include <stdlib.h>
#include "objectsCP2.h"
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------------------------
Album::Album() {
  albumId = 0;
  albumName = "";
  nummusic = 0;
  capacity = 1;  
}
Album::Album(int num, int size) {
  nummusic = num;
  capacity = size;
}
Album::Album(int albumid, string albumname) {
  albumId = albumid;
  albumName = albumname;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Album::setId(int albumid) {
  albumId = albumid;
}
void Album::setName(string albumname) {
  albumName = albumname;
}
bool Album::contains(int songid) {
  for (int i = 0; i < nummusic; i++) {
    if (songid == album[i].musicId) {
      return true;
    }
  }
  return false;
}
music Album::get(int songid) {
  for (int i = 0; i < nummusic; i++) {
    if (songid == album[i].musicId) {
      return album[i];
    }
  }
  return music();
}
music* Album::getPointer(int songid) {
  for (int i = 0; i < nummusic; i++) {
    if (songid == album[i].musicId) {
      return &(album[i]);
    }
  }
  return nullptr;
}
int Album::findIdx(int songid) {
  int idx = 0;
  for (int i = 0; i < nummusic; i++) {
    if (songid > album[i].musicId) {
      idx = i+1;
    }
  }
  return idx;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Album::resize() 
{
  music *tmpCollection = new music[capacity*2];
  int count = 0;
  for (int i = 0; i < capacity; i++) {
    tmpCollection[i] = album[i];
    count++;
  }
  delete[] album;
  album = tmpCollection;
  capacity *= 2;
  nummusic = count;
}
void Album::insert(const music& song) {
  int idx = findIdx(song.musicId);
  for (int i = nummusic; i >= idx; i--) {
    if (i == idx) {
      album[idx] = song;
      nummusic++;
      break;
    }
    album[i] = album[i-1];
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Album::printSongs(){
    for (int i = 0; i < nummusic; i++){
    music tmpmusic = album[i];
    cout << "song " << tmpmusic.musicId << " " << tmpmusic.musicTitle << " by " << tmpmusic.artistName << endl;
    }
}

void Album::seeSong(int songid) {
  if (contains(songid)) {
    music tmpmusic = get(songid);
    cout << "song " << tmpmusic.musicId << " " << tmpmusic.musicTitle << " by " << tmpmusic.artistName << endl;
  } else {
    cout << "song " << songid << " does not exist" << endl;
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void Album::removeSong(int songid) {
  if (nummusic == 1) {
    resize();
  }
    
  if (contains(songid)) {
    int idx = findIdx(songid);
    music tmpSong = album[idx];

    for (int i = idx; i < nummusic; i++) {
      album[i] = album[i+1];
    } 
    nummusic--;
    cout << "song " << tmpSong.musicId << " " << tmpSong.musicTitle << " by " << tmpSong.artistName << ", removed" << endl;
    return;
  } else {
    cout << "song " << songid << " not found" << endl;
  }
}

void Album::addSong(const music& song) {
  if (nummusic == capacity) {
    resize(); 
  }
  if (nummusic == 0) {
    album[nummusic] = song;
    nummusic++;
    return;
  }
  if (contains(song.musicId)) {
      cout << "song id " << song.musicId << " already used for " << song.musicTitle << " by " << song.artistName << endl;
      return;
    }
    insert(song);
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------


