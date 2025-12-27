# Tic-Tac-Toe Game (C++)

## 📌 Overview

This project is a **terminal-based Tic-Tac-Toe game** developed in **C++** as an **academic project for the first semester** of a Computer Science-related course.

The game runs entirely in the terminal and supports two game modes:
- **Player vs Player**
- **Player vs Computer**

The focus of this project is to practice **structured programming**, **functions**, **arrays**, **structs**, **control flow**, and **basic input/output** in C++.

---

## 🎯 Features

- 3x3 Tic-Tac-Toe board displayed in the terminal  
- Player name input  
- Choice of symbols (X or O)  
- Turn-based system  
- Input validation for moves  
- Victory detection (rows, columns, diagonals)  
- Draw detection  
- Randomized computer moves (basic AI)  

---

## 🕹️ Game Modes

### 1️⃣ Player vs Player
- Two players enter their names
- The first player chooses the symbol (X or O)
- Players alternate turns until a win or draw occurs

### 2️⃣ Player vs Computer
- The user plays against the computer
- The computer selects random valid positions on the board
- The game continues until a win or draw

---

## 🧠 Program Structure

The project is organized using:

- **Struct**
  - Stores player names and symbols
- **Functions**
  - Board printing
  - Board reset
  - Menu handling
  - Player move validation
  - Computer move generation
  - Match analysis (win/draw detection)
- **2D Arrays**
  - Represent the Tic-Tac-Toe board

---

## ⚙️ Technologies Used

- **Language:** C++
- **Libraries:**
  - `<iostream>` for input/output
  - `<cstring>` for string manipulation
  - `<ctime>` for random number seeding

---

## ▶️ How to Run

1. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp -o tic_tac_toe

---

## Run the executable:
   ```bash
./tic_tac_toe
   ```
Follow the on-screen instructions to select the game mode and play.

---

## 📚 Academic Notes

- This project was built without advanced algorithms such as backtracking.
- The computer opponent uses simple random logic, suitable for beginner-level programming.
- All logic respects the concepts typically taught in a first-semester C++ course.

---

## 👤 Author

- Gustavo Borges
- Academic project — First Semester
- Language: C++

---

## 📄 License

- This project is intended for educational purposes.
- Feel free to study, modify, and improve it.



