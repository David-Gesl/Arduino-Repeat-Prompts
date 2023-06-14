#include <Adafruit_CircuitPlayground.h>
#include <Arduino.h>
#include "Talkie.h"
#include "Vocab_US_Large.h"

Talkie voice;

//This is the level and will be increased or decreased depending on if the level is beat. 
int level = 1;  ////ChNGE TO LEVEL 1
//This is used so that once levels are randomly generated one time, they will not be displayed over and over as the loop continues: A better user experience.
volatile bool levels_generated = 0;
int Score = 6;

//This will store the userinput which is based off what flag is triggered
String userinput;



const byte switchPin = 7;
volatile bool switchState = 0;
volatile bool switchFlag = 0;

const int buttonA = 4;
volatile bool A_flag = 0;

volatile bool B_flag = 0;
const int buttonB = 5;

//Used to increase the user input index for the current index in the arrary
int user_input_index = 0;

//All of these are so that if you sit in the serial monitor, it does not repeat the print level over and over. Quality of life
volatile bool level_1_showed = 0;
volatile bool level_2_showed = 0;
volatile bool level_3_showed = 0;
volatile bool level_4_showed = 0;
volatile bool level_5_showed = 0;
volatile bool level_6_showed = 0;


//This gives a list of possible inputs and is used to randomly generated Required_Inputs array using only the below options. Can also add to it for more functions/buttons.
String possible_inputs[] = {"Left Button", "Right Button", "Slide Switch"};

//Generates a 2D array: 6 levels of user_inputs each with a length of 5 Strings
String user_input[6][5];

//Generates a 2D array: 6 levels of required inputs each with a length of 5 strings
String Required_Inputs[6][5];

//Starts Circuit Playground, serial, seeds the random function, and creates the interupts and attaches them to both buttons and the switch

void setup() {
CircuitPlayground.begin();
Serial.begin(9600);
randomSeed(analogRead(0));

pinMode(switchPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(switchPin), switchChanged, CHANGE);

pinMode(buttonA, INPUT_PULLDOWN);
attachInterrupt(digitalPinToInterrupt(buttonA), button_A_pressed, FALLING);

pinMode(buttonB, INPUT_PULLDOWN); //Must be pulldown for buttons
attachInterrupt(digitalPinToInterrupt(buttonB), button_B_pressed, FALLING);

//Part of the voice library used to make speaker louder on certain boards- not sure if it works here or not.
#if defined(TEENSYDUINO)
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH); //Enable Amplified PROP shield
#endif
}

void loop() {

//Stops levels from displaying while user does not have the serial monitor open
while(!Serial)
//Failcase in case user fails the first level
if (level == 0){
  level = 1;
}
//Stops levels from generating over and over again as program loops
if (!levels_generated){
  generate_levels();
}

//Determines which level to display (only once due to the if statement!), checks all flags for that level, and checks if level is complete if user_input_index = 5, then resets it and increments level.
switch (level) {
  case 1:
    check_flags();
    if (!level_1_showed){
      show_level_1();
    }
    check_if_level_complete();
    break;
    
  case 2:
    check_flags();
    if (!level_2_showed){
      show_level_2();
    }
    check_if_level_complete();
    break;

  case 3:
    check_flags();
    if (!level_3_showed){
      show_level_3();
    }
    check_if_level_complete();
    break;    

  case 4:
    check_flags();
    if (!level_4_showed){
      show_level_4();
    }
    check_if_level_complete();
    break;    

  case 5:
    check_flags();
    if (!level_5_showed){
      show_level_5();
    }
    check_if_level_complete();
    break;    

  case 6:
    check_flags();
    if (!level_6_showed){
      show_level_6();
    }
    check_if_level_complete();
    break;

  case 7:
    Serial.println();
    Serial.println();
    Serial.println("You Beat the Game! Your Score is:");
    Serial.println(Score);
    break;
    
}
  delay(50);
}

//Nested loops to populate the required input array for each level
void generate_levels(){
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5; j++){
      Required_Inputs[i][j] = possible_inputs[random(3)];      
    }
  }
  levels_generated = 1;
  delay(50);

}

//Declare the interrupt flags: These will be used to store userinput into the userinput 2D array at [level][user_input_index]
void switchChanged()
{
  switchFlag = 1;
}

void button_A_pressed()
{
  A_flag = 1;
}

void button_B_pressed()
{
  B_flag = 1; 
}

//The followinig show_level_X functions will display the required inputs for that level to the user based on the level-1 since arrays are 0 indexed. Only shows once per level b/c level_X_showed becomes true.
void show_level_1(){
  Serial.println();
  Serial.println();
  Serial.println("Level 1: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_1_showed = 1;
}

void show_level_2(){
    Serial.println();
    Serial.println();
    Serial.println("Level 2: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_2_showed = 1;
}

void show_level_3(){
    Serial.println();
    Serial.println();
    Serial.println("Level 3: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_3_showed = 1;
}

void show_level_4(){
    Serial.println();
    Serial.println();
    Serial.println("Level 4: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_4_showed = 1;
}

void show_level_5(){
    Serial.println();
    Serial.println();
    Serial.println("Level 5: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_5_showed = 1;
}

void show_level_6(){
    Serial.println();
    Serial.println();
    Serial.println("Level 6: ");
  for (int i = 0; i < 5; i++){
    Serial.println(Required_Inputs[(level - 1)][i]);
  }
  level_6_showed = 1;
}

//Checks to see if any button has been pressed and will debounce, set the userinput, display the input, and store the input to the current level index, then reset the flag to false and increment index.
//Does this for all 3 buttons.
void check_flags(){
  if(switchFlag){
    delay(20);
    userinput = "Slide Switch";
    Serial.println();
    Serial.println("Your input is: ");
    Serial.println(userinput);
    Serial.println();
    user_input[level - 1 ][user_input_index] = userinput;
    switchFlag = 0;
    user_input_index += 1;

  } else if (A_flag) {
    delay(20);
    userinput = "Left Button";
    Serial.println();
    Serial.println("Your input is: ");
    Serial.println(userinput);
    Serial.println();
    user_input[level - 1 ][user_input_index] = userinput;
    A_flag = 0;
    user_input_index += 1;

  } else if (B_flag){
    delay(20);
    userinput = "Right Button";
    Serial.println();
    Serial.println("Your input is: ");
    Serial.print(userinput);
    Serial.println();
    user_input[level - 1 ][user_input_index] = userinput;
    B_flag = 0;
    user_input_index +=1;
  }
}

//Checks if the user has entered 5 inputs, if they have, it will check each input against the relative required input for that level. If they all match, it will play the level passed function, 
//otherwise it will play the level failed function. Also will tell you if you failed/passed that level. If you fail, your score decreases. user_input_index resets to 0 for the next level indexing purposes.
void check_if_level_complete(){
  if (user_input_index == 5){  
    if (user_input[level - 1][0] == Required_Inputs[level - 1][0] &&
    user_input[level - 1][1] == Required_Inputs[level - 1][1] && 
    user_input[level - 1][2] == Required_Inputs[level - 1][2] && 
    user_input[level - 1][3] == Required_Inputs[level - 1][3] && 
    user_input[level - 1][4] == Required_Inputs[level - 1][4] )
    {
      Serial.println("You beat the level!");
      level_passed();
    } else {
        Serial.println("You failed the level!");
        level_failed();
    }
    user_input_index = 0;
  }

}


//Plays a green LED Pattern and level complete sound to indicate that the level has been passed, then progresses to the next level
void level_passed(){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 45, 0);
    delay(50);
  }

  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
    delay(50);
  }

  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 45, 0);
  }
  delay(200);
  CircuitPlayground.clearPixels();
  delay(200);
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 0, 45, 0);
  }
  delay(200);
  CircuitPlayground.clearPixels();

  voice.say(sp2_ALERT); 
  voice.say(sp2_ALERT);
  voice.say(sp4_LEVEL);
  voice.say(sp2_PAST);
  level +=1;
}

//Plays a red LED Pattern and level failed sound to indicate that the level has been failed, then moves to the next level and decreases score.
void level_failed(){
  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 45, 0, 0);
    delay(50);
  }

  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 45, 0, 0);
    delay(50);
  }

  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 45, 0, 0);
  }
  delay(200);
  CircuitPlayground.clearPixels();
  delay(200);

  for(int led = 0; led < 10; led++){
    CircuitPlayground.setPixelColor(led, 45, 0, 0);
  }

  delay(200);
  CircuitPlayground.clearPixels();
  
  voice.say(sp2_ALERT); 
  voice.say(sp2_ALERT);
  voice.say(sp4_LEVEL);
  voice.say(sp4_FAILURE);
  level+=1; 
  Score --;
}
