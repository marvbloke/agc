/* 
 *  Arduboy Game Changer
 *  Menu software
 *  version 0.1
 *  Matthew Begg
 *  2017-03-28
 */


#include <Arduboy2.h>
/* Edit the GAMES_LENGTH below with the number of games in your
   Raspberry Pi 'Games' folder */
#define GAMES_LENGTH 21
Arduboy2 arduboy;
byte selectedGame = 0;

// Edit the list below with the games in your Raspberry Pi 'Games' folder
String games[GAMES_LENGTH] = { "ArduMiner", 
                     "Begemmed",
                     "BlobAttack", 
                     "CastleBoy", 
                     "CircuitDude", 
                     "DiceOfFate",
                     "EpicCratesOfDestruction", 
                     "Evade", 
                     "FantasyRampage",
                     "Glove", 
                     "HollowSeeker", 
                     "JetPac", 
                     "LittleRook", 
                     "MysticBalloon", 
                     "ReverseMermaidHockey",
                     "ShadowRunner",
                     "Sirene",
                     "Squario", 
                     "TrainDodge",
                     "TrollyFish", 
                     "VirusLQP79" 
                   };

void drawMenu() {
  arduboy.clear();
  // draw select arrow
  arduboy.setCursor(0,0);
  arduboy.print(F(">"));
  // show games titles
  for (byte i=0; i<(GAMES_LENGTH-selectedGame); i++) {
    arduboy.setCursor(8,i*8);
    arduboy.print(games[i+selectedGame]);
  }
  arduboy.display();
}

void aboutScreen() {
  // First screen
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("Arduboy Game Changer\nby Matthew Begg\n\nVersion 1.0\n\nRequires Raspberry Pi\nto change games"));
  arduboy.display();
  while(!(arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON))) {
    ;
  }
  while (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)) {
    ;
  }
  // Second screen
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("INSTRUCTIONS\n\nUp/down/left/right\nto choose your game.\nPress A to start."));
  arduboy.display();
  while(!(arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON))) {
    ;
  }
  while (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON)) {
    ;
  }
}

void launchGame() {
  arduboy.clear();
  arduboy.setCursor(8,24);
  arduboy.print(F("Launching"));
  arduboy.setCursor(8,34);
  arduboy.print(games[selectedGame] + "...");
  arduboy.display();
  Serial.begin(9600); // start connection with the Pi
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println(games[selectedGame]);
  Serial.end();
  delay(6000);
  arduboy.setCursor(8,24);
  arduboy.print(F("Game not found"));
  arduboy.display();
  delay(3000);
  arduboy.clear();
}

void setup() {
  arduboy.begin(); // initialise the ArduBoy
  arduboy.setFrameRate(15); // save battery life
  arduboy.clear(); // clear the screen

  // draw initial menu
  drawMenu();
}

void loop() {
  // if UP is pressed, go back one game
  if(arduboy.pressed(UP_BUTTON) && (selectedGame>0)) {
    while(arduboy.pressed(UP_BUTTON)) {
      ;
    }
    selectedGame--;
    drawMenu();
  }
  // if DOWN is pressed, go forward one game
  if(arduboy.pressed(DOWN_BUTTON) && (selectedGame<(GAMES_LENGTH-1))) {
    while(arduboy.pressed(DOWN_BUTTON)) {
      ;
    }
    selectedGame++;
    drawMenu();
  }
  // if LEFT is pressed, go back 8 games
  if(arduboy.pressed(LEFT_BUTTON) && (selectedGame>0)) {
    while(arduboy.pressed(LEFT_BUTTON)) {
      ;
    }
    if(selectedGame>7) {
      selectedGame = selectedGame - 8;
    } else {
      selectedGame = 0;
    }
    drawMenu();
  }
  // if RIGHT is pressed, go forward 8 games
  if (arduboy.pressed(RIGHT_BUTTON) && (selectedGame<(GAMES_LENGTH))) {
    while(arduboy.pressed(RIGHT_BUTTON)) {
      ;
    }
    if(selectedGame<(GAMES_LENGTH-8)) {
      selectedGame = selectedGame + 8;
    } else {
      selectedGame = GAMES_LENGTH-1;
    }
    drawMenu();
  }
  // if A is pressed, launch game
  if (arduboy.pressed(A_BUTTON)) {
    while(arduboy.pressed(A_BUTTON)) {
      ;
    }
    launchGame();
  }
  // if B is pressed, show About screen
  if (arduboy.pressed(B_BUTTON)) {
    while(arduboy.pressed(B_BUTTON)) {
      ;
    }
    aboutScreen();
    drawMenu();
  }
}
