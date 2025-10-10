![image](https://github.com/diogo-adao/libft/assets/142692185/63ed68a2-74a6-4958-8d49-bf8d36a2d98e)

# 🎮 So_Long

A small 2D game developed in **C** as part of the **42 curriculum**, using **MiniLibX** for graphics.  
The project focuses on **game logic**, **map parsing**, and **player interaction** in a simple grid-based environment.


## 📖 Overview

In **So_Long**, the player navigates a rectangular map collecting items and reaching an exit:

- The map is represented as a **2D grid** from a `.ber` file  
- The player can move **up, down, left, and right**  
- The goal is to **collect all collectibles** (`C`) and reach the exit (`E`)  
- Walls (`1`) block movement, while empty spaces (`0`) allow passage  

The project requires **parsing the map**, checking for validity, and implementing **movement mechanics** with a **graphical interface**.


## ⚙️ Features

- 2D grid-based game with **real-time player movement**  
- **Map parsing** from `.ber` files with validation  
- Collectibles and exit tracking  
- Player movement with **keyboard input** (arrow keys)  
- **Win condition**: collect all items and reach the exit  
- **Graphical interface** using MiniLibX  


## 🧠 Key Concepts

- **2D arrays** – representing the game map and objects  
- **File parsing** – reading `.ber` map files and validating content  
- **Event handling** – responding to keyboard inputs for player movement  
- **Graphics with MiniLibX** – drawing the map, player, and collectibles  
- **Game logic** – handling collisions, win condition, and movement constraints  


## 🧩 Installation & Usage

```bash
# Clone the repository
git clone https://github.com/diogo-adao/so_long.git

# Go to the folder
cd so_long && cd so_long

# Build the program
make
(it automatically clones the MiniLibX library)

# Run the game
./so_long maps/big_map.ber
```

## 👨‍💻 Author
[Diogo Adão](https://github.com/diogo-adao)


