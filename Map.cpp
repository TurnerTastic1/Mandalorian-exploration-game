// Map.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include "map.h"

using namespace std; 

Map::Map()
{
    resetMap();
}


/*
 * Algorithm: Resets positions of player, NPC, misfortunes, sites to -1 and clears mapData  
 * Set Player position coordinates to 0
 * Set NPC position coordinates to -1
 * Set npc_on_map to false
 * Set misfortune_count to 0
 * Set site_count to 0
 * loop i from 0 to num_misfortunes
 *      Set row, col and type of misfortune location to -1
 * loop i from 0 to num_sites
 *      Set row, col and type of site location to -1
 * loop i from 0 to num_rows
 *      loop i from 0 to num_cols
 *          Set (x,y) location on mapData to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap() {
    // resets player position, count values, and initializes values in position arrays to -1
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    npc_on_map = false;
    misfortune_count = 0;
    site_count = 0;

    for (int i = 0; i < num_misfortunes; i++) {
        misfortunes[i][0] = -1;
        misfortunes[i][1] = -1;
        misfortunes[i][2] = -1;
    }

    for (int i = 0; i < num_sites; i++) {
        sites[i][0] = -1;
        sites[i][1] = -1;
        sites[i][2] = -1;
    }

    npcPosition[0] = -1;
    npcPosition[1] = -1;

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getSiteCount() {
    return site_count;
}

int Map::getMisfortuneType(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] != -1){
                return misfortunes[i][2];
            }
        }
    }
    return 0;
}

int Map::getMisfortuneCount() {
    return misfortune_count;
}

int Map::getSiteTrait() {
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] != -1){
                return sites[i][2];
            }
        }
    }
    return 0;
}

/*
 * Algorithm: Checks if the location is an NPC location  
 * if player position is NPC location and npc_on_map is true
 *      return true
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isNPCLocation(){
    if (playerPosition[0] == npcPosition[0] && playerPosition[1] == npcPosition[1] && npc_on_map == true){
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is misfortune  
 * loop i from 0 to misfortune_count
 *      if player position is a misfortune location
 *          if misfortune type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isMisfortuneLocaton(){
    for(int i = 0; i < misfortune_count; i++){
        if (playerPosition[0] == misfortunes[i][0] && playerPosition[1] == misfortunes[i][1]){
            if (misfortunes[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the location is site  
 * loop i from 0 to num_sites
 *      if player position is a site location
 *          if site type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isSiteLocation(){
    for(int i = 0; i < num_sites; i++){
        if (playerPosition[0] == sites[i][0] && playerPosition[1] == sites[i][1]){
            if (sites[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if a planet is habitable or not
 * Set water, oxygen and fertile_soil to false
 * Set non_habitable_traits to 0 
 * loop i from 0 to num_sites
 *      if site type is 1
 *          Set water to true
 *      else if site type is 2
 *          Set oxygen to true
 *      else if site type is 3
 *          Set fertile_soil to true 
 *      else if site type is between 4 and 6
 *          Increment non_habitable_traits 
 * if water, oxygen, fertile_soil are true and non_habitable_traits <=1
 *      set habitable to true
 * else
 *      set habitable to false
 * return habitable
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isHabitable(){
    bool water = false;
    bool oxygen = false;
    bool fertile_soil = false;
    int non_habitable_traits = 0;
    for (int i = 0; i < num_sites; i++){
        if (sites[i][2] == 1){
            water = true;
        } 
        else if (sites[i][2] == 2){
            oxygen = true;
        }
        else if (sites[i][2] == 3){
            fertile_soil = true;
        }
        else if (sites[i][2] >= 4 && sites[i][2] <= 6){
            non_habitable_traits++;
        }
    }
    if (water && oxygen && fertile_soil && (non_habitable_traits <= 1)){
        habitable = true;
    }
    else{
        habitable = false;
    }
    return habitable;
}

/*
 * Algorithm: Checks if the given row and column on map is a free space 
 * if row and column is not within the map boundaries
 *      return false
 * loop i from 0 to misfortune_count
 *      if (row,col) is a misfortune location
 *          return false
 * loop i from 0 to num_sites
 *      if (row,col) is a site location
 *          return false
 * if (row,col) is a npc position
 *      return false
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col){
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }
    for(int i = 0; i < misfortune_count; i++){
        if (row == misfortunes[i][0] && col == misfortunes[i][1]){
            return false;
        }
    }
    for(int i = 0; i < num_sites; i++){
        if (row == sites[i][0] && col == sites[i][1]){
            return false;
        }
    }
    if (row == npcPosition[0] && col == npcPosition[1]){
        return false;
    }
    return true;
}

void Map::setMisfortuneCount(int num_misfortunes){
    misfortune_count = num_misfortunes;
}

void Map::setNPC(bool isNpc){
    npc_on_map = isNpc;
}


void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}


void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

/*
 * Algorithm: Create an NPC on the map 
 * if npc is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in npcPosition array
 * set (row,col) value in mapData to 'A'
 * set npc_on_map to true
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::spawnNPC(int row, int col) {
    if (npc_on_map) {
        return false;
    }

    if (!isFreeSpace(row, col)) {
        return false;
    }

    npcPosition[0] = row;
    npcPosition[1] = col;
    mapData[row][col] = 'A';
    npc_on_map = true;
    return true;
}

/*
 * Algorithm: Create a misfortune on the map 
 * if misfortune_count is more than or equal to number of misfortunes
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in misfortunes matrix is -1 -1
 *      store row, col and type values in the current row of misfortunes matrix
 *      increment misfortune_count
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnMisfortune(int row, int col, int type) {

    if (misfortune_count >= num_misfortunes) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (misfortunes[misfortune_count][0] == -1 && misfortunes[misfortune_count][1] == -1) {
        misfortunes[misfortune_count][0] = row;
        misfortunes[misfortune_count][1] = col;
        misfortunes[misfortune_count][2] = type;
        misfortune_count++;
        return true;
    }

    return false;
}

/*
 * Algorithm: Create a site on the map 
 * if site_count is more than or equal to number of sites
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in sites matrix is -1 -1
 *      store row, col and type values in the current row of sites matrix
 *      increment site_count
 *      Set (row,col) value in mapData to 'S'
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnSite(int row, int col, int type) {

    if (site_count >= num_sites) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (sites[site_count][0] == -1 && sites[site_count][1] == -1) {
        sites[site_count][0] = row;
        sites[site_count][1] = col;
        sites[site_count][2] = type;
        site_count++;
        mapData[row][col] = 'S';
        return true;
    }

    return false;
}

/*
 * Algorithm: This function prints "*" to reveal a position of misfortune
 * Set the value of (row, col) in mapData to '*'
 * Parameters: row (int), col (int)
 * Return: nothing (void)
 */
void Map::revealMisfortune(int row, int col) {
    mapData[row][col] = '*';
}

/*
 * Algorithm: Make the player move based on the given command 
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 *      return true
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 *      return true
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 *      return true
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 *      return true
 * Parameters: move (char)
 * Return: boolean (bool)
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print "x"
 *          else if Hacker is at (i,j)
 *              print "-"
 *          else
 *              print the value of (i,j) in mapData
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'H') {  // don't show hacker on the map
                cout << "-";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}
