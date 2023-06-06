# Arduino-Repeat-Prompts
Final ENGR 103 Arduino project: Create your own arduino game

# Game Description:
The serial monitor will display a level counter along with required user inputs for that level. The user will have to repeat the requried inputs in the given order. If the user inputs match the required inputs, a green LED pattern and success playtone will activate and the level counter will increment. If the user inputs do not match the required inputs for that level, a red LED pattern will play and a failure platone will activate. 

The first 5 levels will be repeating the one of the 5 possible inputs so that the user knows which inputs they will be mimicing in the coming levels. After this, the next 5 levels will be randomly generated and be a mixture of all required inputs. 

# Rules:
The rules are very simple. Repeat the displayed inputs in the least amount of time possible. 

# Inputs and how they will be used:
#### -Left Button (Press)
#### -Right Button (Press)
#### -Slide Switch (Slide)
#### -Light Sensor (Cover)
#### -Accelerometer (Double-tap)

# Outputs and how they will be used:
Serial Print: Used to show required inputs, level, and score
Green LED pattern: Plays to indicate user inputs match required inputs and level is passed
Level Pass tone: Plays along with Green LED pattern indicating level is passed
Red LED pattern: Plays to indicate user inputs do NOT match required inputs and level is failed
Level Failed tone: Plays along with Red LED pattern indicating level is failed
