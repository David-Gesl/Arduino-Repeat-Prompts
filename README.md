# Arduino-Repeat-Prompts
Final ENGR 103 Arduino project: Create your own Arduino game

# Game Description:
The game will generate a 2D array with 6 (level) elements each containing 5 (required inputs) elements. The serial monitor will display a level  and the required user inputs for that level. The user will have to repeat the required inputs in the given order. If the user inputs match the required inputs, a green LED pattern and a voice prompt will activate and the level counter will increment. If the user inputs do not match the required inputs for that level, a red LED pattern will play and a failure voice prompt will activate. The level will still progress, but the score will decrease for each level failed. 

All 6 levels will be randomly generated and be a mixture of all required inputs. 

# Rules:
The rules are straightforward. Repeat the displayed inputs as they pop up on the screen. 

# Inputs and how they will be used:
#### -Left Button (Press)
#### -Right Button (Press)
#### -Slide Switch (Slide)

# Outputs and how they will be used:
#### Serial Print: Used to show level, required inputs, user input, failed/passed level, and score
#### Green LED pattern: Plays to indicate user inputs match required inputs and level is passed
#### Level Pass tone: Plays along with Green LED pattern indicating level is passed
#### Red LED pattern: Plays to indicate user inputs do NOT match required inputs and level is failed
#### Level Failed tone: Plays along with Red LED pattern indicating level is failed
