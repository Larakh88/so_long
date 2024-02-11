# so_long

## Introduction
So_Long is the first graphical project at School 42, introducing students to the MiniLibX graphical library for developing interactive applications.
In this project, we create a game where a character must collect all collectibles and find an exit to complete the game. 
The challenge lies in implementing the game mechanics, graphics, and user interaction using MiniLibX.

## Features
* **`Controls`**: Use the W, A, S, and D keys (or arrow keys) to move the character in the four directions: up, down, left, and right.
* **`Movement Restrictions`**: Characters cannot move through walls.
* **`Movement Counter`**: Display the current number of movements in the shell after each move.
* **`Map Construction`**: Maps consist of walls, collectibles, and free space, represented by specific characters. Maps must be rectangular and surrounded by walls.

## Usage
1. **Compiling**: Run **`make`** to compile the project.
2. **Running**: Execute the program with a map file as a parameter:

   ```./so_long map.ber```
3. **Controls**: Use the W, A, S, and D keys or arrow keys to navigate the character through the map.
4. **Objective**: Collect all collectibles and reach the exit to win the game.

## Demo
![so_long](https://github.com/Larakh88/so_long/assets/88907380/ee20c290-eda2-4bd7-8fa1-48b3a1c991df)

