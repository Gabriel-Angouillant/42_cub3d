## Cub3d
### About the 42 Norm:
- Each file must contain no more than 5 functions.
- Each function must not exceed 25 lines.
- The project must be written solely in C.
- Global variables are not allowed.
- Allowed external functions are: `read`, `write`, `malloc`, `free`, `exit`, `open`, `close`, `perror`, `strerror`, `gettimeofday`.

### Project Overview:
This project aims to implement a **3D graphical representation of the inside of a maze** using raycasting methods.
Instead of relying on classic angle calculations, I decided to use the DDA - Digital Differential Analysis - algorithm, which allows minimal calculations for maximum precision.

Another challenge was to implement a thorough map parsing, making it possible for the user to customize the shape of the maze without risk.
The walls textures are defined in each map settings, along with the colour of the floor and the ceiling. It is possible to move in any direction and look sideways.

We were asked to do this project in a group of two, thus I focused on the implementation of the algorithm while [my teammate](https://github.com/une-nerd-parmi-d-autres) preferred the parsing of the maps.
She also created a tester together with a set of valid and invalid maps, which made the eventual problems much easier to detect and fix.

## Preview:

![image](https://github.com/user-attachments/assets/af23340a-2c57-4351-89dc-da463c764890)

![image](https://github.com/user-attachments/assets/7cec5735-a543-490c-96ea-e5143d8ffd25)

![image](https://github.com/user-attachments/assets/a7dab1a5-f716-41b2-bf07-274741ff2b28)
