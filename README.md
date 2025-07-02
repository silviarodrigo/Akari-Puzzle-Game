# Akari - A "Light Up" Puzzle Game
This project is a console-based implementation of the famous logic puzzle game **Akari** (also known as "Light Up"). It was developed as a project for a first-year university programming course.

  # How to play
The objective of Akari is to illuminate every white square in a grid by placing light bulbs. The rules are simple:
- A light bulb illuminates all squares in its row and column, unless its light is blocked by a black cell.
- No light bulb can be placed on a black cell.
- No light bulb can illuminate another light bulb.
- Some black cells have numbers (0-4), which indicate exactly how many light bulbs must be placed in the adjacent (horizontally or vertically) squares.

  # Features
- **Level Selection**: Choose a board to play from a predefined list of levels.
- **Interactive Gameplay**: Place light bulbs on the grid by entering their coordinates.
- **Game Controls**: Easily reset the current puzzle or quit the game (enter -1 -1).
- **Save on Exit**: After winning or quitting (enter -1 0), you have the option to save the final state of the board to a text file for review.
