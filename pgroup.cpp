#include <iostream>
#include <stdlib.h>
#include <vector>
#include "objectsCP2.h"
using namespace std;
pgroup::pgroup() { 
}
Album pgroup::get(int albumid) {
  for (int i = 0; i < library.size(); i++) {
    if (library.at(i).albumId == albumid) {
      return library.at(i);
    }
  }
  cout << "returns empty" << endl;
  return Album();
}
Album* pgroup::getPointer(int albumid) {
  for (int i = 0; i < library.size(); i++) {
    if (library.at(i).albumId == albumid) {
      return &(library.at(i));
    }
  }
  cout << "returns empty" << endl;
  return nullptr;
}
int pgroup::findIdx(int albumid) {
  for (int i = 0; i < library.size(); i++) {
    if (library.at(i).albumId < albumid) {
      return i+1;
    }
  }
  return 0;
}
void pgroup::drop(int songid, int albumid, groups *allSongs) {
  Album *tmpAL = getPointer(albumid);
  if ((allSongs->contains(songid)) && (contains(albumid)) && (tmpAL->contains(songid))) {
    tmpAL->removeSong(songid);
    cout << "song " << songid << " successfully dropped from playlist " << albumid << endl;
  } else {
    if (!allSongs->contains(songid)) {
      cout << "song " << songid << " does not exist" << endl;
    }   
    if (!contains(albumid)) {
      cout << "playlist " << albumid << " does not exist" << endl;
    }
    if(!tmpAL->contains(songid)) {
      cout << "song " << songid << " is not in playlist " << albumid << endl;
    }
  }
}
bool pgroup::contains(int albumid) {
  for (int i = 0; i < library.size(); i++) {
    if (library.at(i).albumId == albumid) {
      return true;
    }
  }
  return false;
}
void pgroup::newAlbum(int albumid, string albumname) {
  if (contains(albumid)) {
    cout << "playlist " << albumid << " already exists" << endl;
    return;
  }
  Album tmpAlbum(albumid, albumname);
  library.push_back(tmpAlbum);
  cout << "new playlist " << albumid << " called " << albumname << endl;
}
void pgroup::removeSong(int songid) {
    for (int i = 0; i < library.size(); i++) {
        if (library.at(i).contains(songid)) {
            library.at(i).removeSong(songid);
        }
    }
}
void pgroup::renameAlbum(int albumid, string newAlbumName) {
    if (contains(albumid)) {
        Album *tmpAL = getPointer(albumid);
        tmpAL->setName(newAlbumName);
        cout << "playlist" << albumid << " name successfully changed to " << newAlbumName << endl;
    } else {
        cout << "playlist " << albumid << " does not exist" << endl;
    }
}
void pgroup::addSongtoAlbum(int songid, int albumid, groups *allSongs) {
    Album *tmpAL = getPointer(albumid);
    if ((allSongs->contains(songid)) && (contains(albumid)) && (!tmpAL->contains(songid))) {

        music tmpSong = allSongs->get(songid);
        tmpAL->addSong(tmpSong);
        cout << "song " << songid << " successfully added to playlist " << albumid << endl;
    } else {

        if (!allSongs->contains(songid)) {
            cout << "song " << songid << " does not exist" << endl;
        }    
        if (!contains(albumid)) {
            cout << "playlist " << albumid << " does not exist" << endl;
        }
        if(tmpAL->contains(songid)) {
            cout << "song " << songid << " is already in playlist " << albumid << endl;
        }
    }
}
void pgroup::seeAlbum(int albumid) {
    if (contains(albumid)) {
        Album *tmpAL = getPointer(albumid);
        cout << "Songs in playlist " << tmpAL->albumId << " " << tmpAL->albumName << endl;
        tmpAL->printSongs();
    } else {
        cout << "playlist " << albumid << " does not exist" << endl;
    }
}
void pgroup::deleteAlbum(int albumid) {
    if (contains(albumid)) {
        int idx = findIdx(albumid);
        library.erase(library.begin() + idx);
        cout << "playlist " << albumid << " successfully deleted" << endl;
    } else {
        cout << "playlist " << albumid << " does not exist" << endl;
    }
}
void pgroup::copyAlbum(int albumid, int newAlbumId, string newAlbumName) {
    if (contains(newAlbumId)) {
        cout << "playlist " << newAlbumId << " already exists" << endl;
        return;
    }
    if (contains(albumid)) {
        Album tmpAL = get(albumid);
        tmpAL.setId(newAlbumId);
        tmpAL.setName(newAlbumName);
        library.push_back(tmpAL);
        cout << "playlist " << albumid << " successfully copied to playlist " << tmpAL.albumId << " " << tmpAL.albumName << endl;

    } else {
        cout << "playlist " << albumid << " does not exist" << endl;
    }
}
