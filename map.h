// map.h
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#ifndef MAP_H
#define MAP_H

#include <iostream>

using namespace std; 

class Map
{
     private:
          static const int num_rows = 12;
          static const int num_cols = 12;
          static const int num_misfortunes = 8;
          static const int num_sites = 7;

          bool habitable;
          int playerPosition[2];
          int npcPosition[2];
          int misfortunes[num_misfortunes][3];
          int sites[num_sites][3];
          char mapData[num_rows][num_cols];

          bool npc_on_map;
          int misfortune_count;
          int site_count;

     public:
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getSiteCount();
          int getMisfortuneType();
          int getMisfortuneCount();
          int getSiteTrait();
          bool isNPCLocation();
          bool isMisfortuneLocaton();
          bool isSiteLocation();
          bool isHabitable();
          bool isFreeSpace(int, int);

          // setters
          void setMisfortuneCount(int);
          void setNPC(bool);
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);

          // other
          void displayMap();
          bool executeMove(char);
          bool spawnNPC(int, int);
          bool spawnMisfortune(int, int, int);
          bool spawnSite(int, int, int);
          void revealMisfortune(int, int);

};
 
#endif