#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "objectsCP2.h"
using namespace std;

void print_menu() {
  cout << "Enter [\"song <musicid> <artist> <duration> <title>\"" << endl;
  cout << "       " << "\"remove <musicid>\"" << endl;
  cout << "       " << "\"playlist <playlistid> <name>\"" << endl;
  cout << "       " << "\"add <musicid> <playlistid>\"" << endl;
  cout << "       " << "\"drop <musicid> <playlistid>\"" << endl;
  cout << "       " << "\"seesong <musicid>\"" << endl;
  cout << "       " << "\"seeplaylist <playlistid>\"" << endl;
  cout << "       " << "\"deleteplaylist <playlist id>\"" << endl;
  cout << "       " << "\"copyplaylist <playlist id> <new playlist id> <new playlist name>\"" << endl;
  cout << "       " << "\"renameplaylist <playlist id> <new playlist name>\"" << endl;
  cout << "       " << "\"quit\"" << endl;
  cout << ": ";

}
//=======================================================================================================================
bool isInt(string input) {
  try {
    int tmp = stoi(input);
  } catch(...) {
    cout << "Cannot convert to int" << endl;
    return false;
  }
  return true;
}
string t(int time) {
  int x = time / 60;
  int y = time % 60;
  stringstream ss;

  if (y == 0) {
    ss << x << ":00";
  } else if (y < 10) {
    ss << x << ":0" << y;
  } else {
    ss << x << ":" << y;
  }
  return ss.str();
}
//=======================================================================================================================
int main() {
    groups *as = new groups();
    pgroup *ap = new pgroup(); 
  while (true) {
    print_menu(); 
    string command;
    getline(cin, command);
    stringstream ss (command);
    ss >> command;
    if (command == "song") {  
      string musicid;
      string artist;
      string duration;
      string title;     
      ss >> musicid;
      ss >> quoted(artist);
      ss >> duration;
      ss >> quoted(title); 
      if ((!isInt(musicid)) && ((!isInt(duration)))) {
	  cout << "musicid " << musicid << " is not an integer" << endl;
	  cout << "duration " << duration << " is not an integer" << endl;
	  continue;
	} else {
	  if(!isInt(musicid)) {
	    cout << "musicid " << musicid << " is not an integer" << endl;
	    continue;
	  }
	  if(!isInt(duration)) {
	    cout << "duration " << duration << " is not an integer" << endl;
	    continue;
	  }
      }      
      int intMusicId = stoi(musicid);
      int intDuration = stoi(duration);     
      music newSong(intMusicId, artist, t(intDuration), title);
      as->addmusic(newSong);
    }
//=======================================================================================================================
//=======================================================================================================================
//=======================================================================================================================
    else if (command == "playlist") {   
      string Albumid;
      string Albumname;
      ss >> Albumid;
      ss >> quoted(Albumname);
      if(!isInt(Albumid)) {
	cout << "playlistid " << Albumid << " is not an integer" << endl;
	continue;
      }
      int intAlbumId = stoi(Albumid);
      ap->newAlbum(intAlbumId, Albumname);      
    }
    else if (command == "remove") {     
      string musicid;
      ss >> musicid;     
      if(!isInt(musicid)) {
	cout << "musicid " << musicid << " is not an integer" << endl;
	continue;
      }
      int intMusicId = stoi(musicid);      
      as->removemusic(intMusicId);
      ap->removeSong(intMusicId);
    }
    else if (command == "add") {    
      string musicid;
      string Albumid;
      ss >> musicid;
      ss >> Albumid;      
      if ((!isInt(musicid)) && ((!isInt(Albumid)))) {
	  cout << "musicid " << musicid << " is not an integer" << endl;
	  cout << "playlistid " << Albumid << " is not an integer" << endl;
	  continue;
	} else {
	  if(!isInt(musicid)) {
	    cout << "musicid " << musicid << " is not an integer" << endl;
	    continue;
	  }
	  if(!isInt(Albumid)) {
	    cout << "playlistid " << Albumid << " is not an integer" << endl;
	    continue;
	  }
	}
	int intMusicId = stoi(musicid);
	int intAlbumId = stoi(Albumid);
	ap->addSongtoAlbum(intMusicId, intAlbumId, as);
    }
    else if (command == "drop") {    
      string musicid;
      string Albumid;
      ss >> musicid;
      ss >> Albumid;
      if ((!isInt(musicid)) && ((!isInt(Albumid)))) {
	  cout << "musicid " << musicid << " is not an integer" << endl;
	  cout << "playlistid " << Albumid << " is not an integer" << endl;
	  continue;
	} else {
	  if(!isInt(musicid)) {
	    cout << "musicid " << musicid << " is not an integer" << endl;
	    continue;
	  }
	  if(!isInt(Albumid)) {
	    cout << "playlistid " << Albumid << " is not an integer" << endl;
	    continue;
	  }
	}
	int intMusicId = stoi(musicid);
	int intAlbumId = stoi(Albumid);	
	ap->drop(intMusicId, intAlbumId, as);     
    }   
    else if (command == "seeplaylist") {
      string Albumid;
      ss >> Albumid;

      if(!isInt(Albumid)) {
	cout << "playlistid " << Albumid << " is not an integer" << endl;
	continue;
      }
      int intAlbumId = stoi(Albumid);
      ap->seeAlbum(intAlbumId);    
    }
    else if (command == "seesong") {      
      string musicid;
      ss >> musicid;
      if(!isInt(musicid)) {
	cout << "songid " << musicid << " is not an integer" << endl;
	continue;
      }
      int intMusicId = stoi(musicid);
      cout << "song " << intMusicId << endl;
      as->seemusic(intMusicId);    
    }
    else if (command == "deleteplaylist") {
      string Albumid;
      ss >> Albumid;

      if(!isInt(Albumid)) {
	cout << "playlistid " << Albumid << " is not an integer" << endl;
	continue;
      }
      int intAlbumId = stoi(Albumid);
      ap->deleteAlbum(intAlbumId);     
    }
    else if (command == "renameplaylist") {  
      string Albumid;
      string Albumname;
      ss >> Albumid;
      ss >> quoted(Albumname);
      if(!isInt(Albumid)) {
	cout << "playlistid " << Albumid << " is not an integer" << endl;
	continue;
      }
      int intAlbumId = stoi(Albumid);
      ap->renameAlbum(intAlbumId, Albumname);      
    }
    else if (command == "copyplaylist") {
      string Albumid;
      string newId;
      string newName;
      ss >> Albumid;
      ss >> newId;
      ss >> quoted(newName);
      if ((!isInt(Albumid)) && ((!isInt(newId)))) {
	  cout << "playlist id " << Albumid << " is not an integer" << endl;
	  cout << "new playlist id " << newId << " is not an integer" << endl;
	  continue;
	} else {
	  if(!isInt(Albumid)) {
	    cout << "playlist id " << Albumid << " is not an integer" << endl;
	    continue;
	  }
	  if(!isInt(newId)) {
	    cout << "new playlist id " << newId << " is not an integer" << endl;
	    continue;
	  }
	}
      int intAlbumId = stoi(Albumid);
      int intNewId = stoi(newId);
      ap->copyAlbum(intAlbumId, intNewId, newName);      
    }
    else if (command == "quit") {
      delete as;
      delete ap;
      break;
    }
    else {
      cout << "Command not recognized, please try again." << endl;
    }
  }
}

