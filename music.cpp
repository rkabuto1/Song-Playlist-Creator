#include <iostream>
#include <stdlib.h>
#include "objectsCP2.h"
//---------------------------------------------------------------------------------------------------------------------------------------------------
using namespace std;
music::music(int songid, string artist, string duration, string title) {
  musicId = songid;
  artistName = artist;
  musicLength = duration;
  musicTitle = title;
 }
music::music() {
  musicId = 0;
  artistName = "";
  musicLength = "";
  musicTitle = "";
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
