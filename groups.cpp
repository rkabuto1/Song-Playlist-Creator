#include <iostream>
#include <stdlib.h>
#include "objectsCP2.h"

using namespace std;
groups::groups() {
  nummusic = 0;
  capacity = 1;
}
groups::groups(int num, int size) {
  nummusic = num;
  capacity = size;
}
bool groups::contains(int musicid) {
  for (int i = 0; i < nummusic; i++) {
    if (musicid == allmusic[i].musicId) {
      return true;
    }
  }
  return false;
}
music groups::get(int musicid) {
  for (int i = 0; i < nummusic; i++) {
    if (musicid == allmusic[i].musicId) {
      return allmusic[i];
    }
  }
  return music();
}
music* groups::getPointer(int musicid) {
  for (int i = 0; i < nummusic; i++) {
    if (musicid == allmusic[i].musicId) {
      return &(allmusic[i]);
    }
  }
  return nullptr;
}
int groups::findIdx(int musicid) {
  int idx = 0;
  for (int i = 0; i < nummusic; i++) {
    if (musicid > allmusic[i].musicId) {
      idx = i + 1;
    }
  }
  return idx;
}
void groups::resize() {
  music *tmpmusic = new music[capacity * 2];
  int count = 0;
  for (int i = 0; i < capacity; i++) {
    tmpmusic[i] = allmusic[i];
    count++;
  }
  delete[] allmusic;
  allmusic = tmpmusic;
  capacity *= 2;
  nummusic = count;
}
void groups::addmusic(const music& music) {
  if (nummusic == capacity) {
    resize();
  }
  if (nummusic == 0) {
    allmusic[nummusic] = music;
    nummusic++;
    cout << "new song  " << music.musicId << " " << music.musicTitle << " by " << music.artistName << " " << music.musicLength << endl;
    return;
  }
  for (int i = 0; i < nummusic; i++) {
    if (music.musicId == allmusic[i].musicId) {
      cout << "song  id " << allmusic[i].musicId << " already used for " << allmusic[i].musicTitle << " by " << allmusic[i].artistName << endl;
      return;
    }
    insert(music);
    cout << "new song  " << music.musicId << " " << music.musicTitle << " by " << music.artistName << " " << music.musicLength << endl;
    return;
  }
}
void groups::insert(const music& music) {
  int idx = findIdx(music.musicId);
  for (int i = nummusic; i >= idx; i--) {
    if (i == idx) {
      allmusic[idx] = music;
      nummusic++;
      break;
    }
    allmusic[i] = allmusic[i - 1];
  }
}
void groups::seemusic(int musicid) {
  if (contains(musicid)) {
    music tmpmusic = get(musicid);
    cout << "song " << tmpmusic.musicId << " " << tmpmusic.musicTitle << " by " << tmpmusic.artistName << endl;
  } else {
    cout << "song  " << musicid << " does not exist" << endl;
  }
}
void groups::removemusic(int musicid) {
  if (contains(musicid)) {
    int idx = findIdx(musicid);
    music tmpmusic = allmusic[idx];

    for (int i = idx; i < nummusic - 1; i++) {
      allmusic[i] = allmusic[i + 1];
    }
    nummusic--;
    cout << "song " << tmpmusic.musicId << " " << tmpmusic.musicTitle << " by " << tmpmusic.artistName << ", removed" << endl;
    return;
  } else {
    cout << "song  " << musicid << " not found" << endl;
  }
}

