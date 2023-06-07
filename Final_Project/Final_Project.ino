#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>
//#include <string.h>

//int possible_inputs[]= {1, 2, 3, 4, 5};
//possible_inputs[]= {"Left Button", "Right Button", "Double Tap", "Slide Switch", "Cover Light Sensor"};

char* possible_inputs[] = {"Left Button", "Right Button", "Double Tap", "Slide Switch", "Cover Light Sensor"};

void setup() {
  
Serial.begin(9600);
randomSeed(analogRead(0));

}

void loop() {




}



void generate_level_X(){
  char *level_X_Rquired_Inputs[5];
    for (int i = 0; i < 5; i++){
      level_X_Rquired_Inputs[i] = possible_inputs[random(6)];
  }
//  Serial.print()
}






//Do I need to reseed random for each function or just once in the setup?

//POSSIBLE FOR SCORING Timer starts each level and finishes when the user passes or fails the level. If they pass, the time is added to score,
//if they fail, current time is added and a +5 penalty is added and the level is moved back once. The goal is to have the lowest score.


//First 5 levels will be testing inputs for user: level 1: right button. Level 2, left button. Level 3, light sensor, etc?

//Create string arry with all total inputs

//Generate level array with random 


//Display level: Serialprint all requried inputs, 


//Save user inputs to variable and save them to array

/*Attach an interrupt to each input method of the user, once the interrupt is triggered, add a 1 to a counter variable indicating that 
it has been pressed. Save this input (done interrupt function) to an array called Check_Array_LevelX. 

Each level will be generated via a generate level funtcion, which will pick increasing elemetns from an array that lists the userinputs, 
and create a new level array for the user inputs to be comapred to.

Scoring will be done via a timer, X seconds per level and whatever is left on the clock is added to a score: this can perhaps be done with an
async delay. If the delay timer for the level expires before the user has input all the listed comands from the terminal, they will fail the level
and will be moved back a level. If they succeed, they move forward a level*/


//Arduino doesn't allow for string arrays?


//Create array of pointers that list possible user inputs,


//Incompatible/type errors, problem with dereferncing: Two types are different (incompatible pointer type)

//have each input match an integer inside of an int array. 
