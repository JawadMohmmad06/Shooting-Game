
# Shooting Game

This project is a simple shooting game implemented using OpenGL and GLUT libraries in C++. The objective of the game is to shoot down three enemy objects.

## Dependencies:
- cstdio
- GL/gl.h
- GL/glut.h
- iostream
## Gameplay:
- The player controls a rocket using the 'a' and 'd' keys to move left and right,respectively.
- Pressing the 'w' key fires a laser from the rocket towards the enemies.
- The player must aim and shoot down all three enemy objects to win the game.
- Collision detection is implemented, and the game will detect when the player's rocket collides with an enemy object.
## Game Elements:
    1. Rocket:
    - The player controls a rocket using the 'a' and 'd' keys.
    - The rocket can move horizontally within the game window.
    - It is represented by a red rectangle on the screen.

    2. Enemies:
    - There are three enemy objects that appear on the screen.
    - The enemies move vertically from the top to the bottom of the screen.
    - Each enemy has a different color: blue, green, and red.
    - The enemies are represented by triangles on the screen.

    3. Laser:
    - The player can fire a laser from the rocket by pressing the 'w' key.
    - The laser moves vertically upward from the rocket's position.
    - The laser is represented by yellow triangles on the screen.
    - The player must aim and hit the enemies with the laser to destroy them
## Game Logic:
- The game window is updated at regular intervals to create animation.
- The position and speed variables control the movement of the rocket and enemies.
- Collision detection is implemented to detect if the rocket collides with an enemy.
- If a collision occurs, the game ends.
- When the laser intersects with an enemy, that enemy is destroyed.
- Once all three enemies are destroyed, the player wins the game.
