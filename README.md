# Snake 2D Game - README  

## Overview  
This repository contains the source code for a 2D Snake Game implemented using OpenGL and GLUT. The game features smooth animations, a menu system, and a high score tracker. Players control the snake, avoid collisions, and aim to eat food to grow and score points.  

---

## Requirements  

To run this project, ensure you have the following:  

### 1. **Development Environment**  
- **Microsoft Visual Studio** (Recommended version: 2019 or later).  
- Ensure that the **Desktop development with C++** workload is installed in Visual Studio.

### 2. **Required Libraries**  
- **OpenGL**: Built-in support in Visual Studio.  
- **GLUT**: Install the FreeGLUT library for handling OpenGL rendering and input.  

---

## Setting Up FreeGLUT in Visual Studio / Installation

### 1. Install Helper Libraries

To set up the necessary OpenGL libraries, follow these steps:

1. **Create OpenGLwrappers Folder**
   - Create a folder named `OpenGLwrappers` in the `C:` drive:
     ```
     C:\OpenGLwrappers
     ```
   - This specific name and location ensure that all programs in `ExperimenterSource` run out of the box.

2. **Download and Install FreeGLUT**
   - Download FreeGLUT from [FreeGLUT-MSVC-2.8.1-1.mp.zip](http://files.transmissionzero.co.uk/software/development/GLUT/older/freeglut-MSVC-2.8.1-1.mp.zip).
   - Unzip the file and save the folder `freeglut-MSVC-2.8.1-1.mp` in `C:\OpenGLwrappers`.

3. **Download and Install GLEW**
   - Download GLEW from [glew-1.10.0-win32.zip](https://sourceforge.net/projects/glew/files/glew/1.10.0/glew-1.10.0-win32.zip/download).
   - Unzip the file and save the folder `glew-1.10.0-win32` in `C:\OpenGLwrappers`.

4. **Download and Install GLM**
   - Download GLM from [glm-0.9.7.5.zip](https://github.com/g-truc/glm/releases/download/0.9.7.5/glm-0.9.7.5.zip).
   - Unzip the file and save the folder `glm-0.9.7.5` in `C:\OpenGLwrappers`.

5. **Copy DLL Files**
   - **FreeGLUT DLL**:
     - Copy `freeglut.dll` from:
       ```
       C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\bin
       ```
     - Paste it into:
       ```
       C:\Windows\SysWOW64
       ```
   - **GLEW DLL**:
     - Copy `glew32.dll` from:
       ```
       C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\bin\Release\Win32
       ```
     - Paste it into:
       ```
       C:\Windows\SysWOW64
       ```
   - **GLU32 DLL**:
     - Ensure `glu32.dll` is present in `C:\Windows\SysWOW64`. If not, search online resources to reinstall it.

### 2. Integrate with Visual Studio

To streamline future OpenGL projects, create and use an OpenGL project template in Visual Studio 2019:

#### Create an OpenGL Project Template

1. **Create a New Project**
   - Open Visual Studio 2019.
   - Click **Create a new project**.
   - Search for **C++ Console App** and select it. Click **Next**.
   - Configure the project:
     - **Project Name**: `OpenGLProjectTemplate`
     - **Location**: Choose a convenient folder.
     - Check **Place solution and project in the same directory**.
     - Click **Create**.

2. **Set Up Project Files**
   - In **Solution Explorer**, locate `OpenGLProjectTemplate.cpp` under **Source Files**.
   - Open `OpenGLProjectTemplate.cpp` and replace its contents with your desired OpenGL code. For example, you can use the contents from an existing `square.cpp` file or any starter OpenGL code.

3. **Configure Project Properties**
   - Go to:
     ```
     Project → OpenGLProjectTemplate Properties
     ```
   - **Include Directories**:
     - Navigate to:
       ```
       Configuration Properties → C/C++ → General → Additional Include Directories → Edit
       ```
     - Add the following paths:
       ```
       C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\include
       C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\include
       C:\OpenGLwrappers\glm-0.9.7.5\glm
       ```
   - **Library Directories**:
     - Navigate to:
       ```
       Configuration Properties → Linker → General → Additional Library Directories → Edit
       ```
     - Add the following paths:
       ```
       C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\lib
       C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\lib\Release\Win32
       ```
   - **Additional Dependencies**:
     - Navigate to:
       ```
       Configuration Properties → Linker → Input → Additional Dependencies → Edit
       ```
     - Add the following libraries, one per line:
       ```
       glew32.lib
       opengl32.lib
       ```
   - Click **OK** to apply the settings.

4. **Build and Test the Template**
   - Build the solution by selecting:
     ```
     Build → Build Solution
     ```
     - Ensure the build succeeds.
   - Start debugging:
     ```
     Debug → Start Debugging
     ```
     - Verify that the application runs without errors and displays the expected OpenGL output.

5. **Finalize the Template**
   - In **Solution Explorer**, right-click `OpenGLProjectTemplate.cpp` under **Source Files** and select:
     ```
     Remove → Delete
     ```
   - Save all changes:
     ```
     File → Save All
     ```
   - Export the project as a template:
     ```
     Project → Export Template
     ```
     - In the wizard:
       - Select **Project template**.
       - Click **Next**.
       - **Template Name**: `OpenGLProjectTemplate`
       - Check **Automatically import the template into Visual Studio**.
       - Uncheck **Display an explorer window on the output files folder**.
       - Click **Finish**.
   - You can now delete the original `OpenGLProjectTemplate` project from its folder.

#### Use the OpenGL Project Template

1. **Create a New Project from Template**
   - Open Visual Studio 2019.
   - Click **Create a new project**.
   - Search for and select the `OpenGLProjectTemplate`.
   - Click **Next**.
   - Name your project and choose a suitable location.
   - Click **Create**.

2. **Add New C++ File**
   - In **Solution Explorer**, right-click **Source Files**.
   - Select:
     ```
     Add → New Item
     ```
   - Choose **C++ File**, name it appropriately, and click **Add**.
   - A new `.cpp` file will open, ready for you to write your C++/OpenGL code.

With these steps, your development environment is fully configured for OpenGL projects in Visual Studio 2019. You can now start building and running your own OpenGL applications seamlessly.

---

## Running the Game  

1. **Download the Repository**:  
   - Clone the repository or download it as a ZIP file.  
   - Extract the contents of the ZIP file to a folder on your computer.  

2. **Locate the Solution File (`.sln`)**:  
   - Open the extracted folder.  
   - Find the file with the `.sln` extension (e.g., `SnakeGame.sln`).  

3. **Run the Game**:  
   - Double-click the `.sln` file to open it in Microsoft Visual Studio.  
   - Once the project loads, press **Ctrl+F5** (or **Run without Debugging**) to start the game.  

---

## How the Game Works  

- **Controls**:  
  - Use `W`, `A`, `S`, `D` keys to control the snake's movement.  
  - Press `P` to pause/resume the game.  
  - Press `R` to restart the game.  
  - Press `M` to change the game difficulty.  
  - Use `+` or `-` to increase or decrease the map size.  

- **Objective**:  
  - Control the snake to eat food and grow in size.  
  - Avoid collisions with the walls or the snake's own body.  
  - Score as many points as possible.  

- **Game Features**:  
  - Persistent high score saved to a file (`high_score.txt`).  
  - A graphical user interface with a menu and heads-up display (HUD).  
  - Dynamic difficulty adjustment based on player input.  

---

## Troubleshooting  

- Ensure that the required libraries (e.g., FreeGLUT) are correctly installed and configured.  
- If the game does not run, ensure you are running the `.sln` file in Microsoft Visual Studio with the correct configuration (`Debug` or `Release`).  
- Make sure the `freeglut.dll` file is in the same directory as the game executable.  

---

## Credits  

- **Developers**:  
  - Nada Ashraf Gomaa  
  - Sally Reda Zeineldeen  
- **Course**: Computer Graphics (December 2024)  

Enjoy the game!

# code file content
## Main.cpp: Core Setup and Execution
### Purpose:

main.cpp initializes the game and sets up its two primary windows: the menu window and the game window. It links the GLUT functions to manage user input, rendering, and game timing.
 ### Key Functions
**1. glutInit**

    What it Does:
        Initializes the GLUT (OpenGL Utility Toolkit) library.
        Takes command-line arguments (from argc and argv) to configure GLUT settings.
    Why It’s Used:
        Necessary for GLUT to function. Without it, no GLUT-based rendering or input handling can occur.

**2. glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)**

    What it Does:
        Specifies how the display should behave:
            GLUT_RGB: Enables RGB color mode (instead of indexed color).
            GLUT_DOUBLE: Enables double buffering to avoid flickering during rendering.
    Why It’s Used:
        Double buffering ensures smooth animations for the snake's movement and game rendering.

**3. glutInitWindowSize and glutInitWindowPosition**

    What They Do:
        Set the initial size (glutInitWindowSize) and position (glutInitWindowPosition) of the window on the screen.
    Why They’re Used:
        To control the visual layout of the menu and game windows.

**4. glutCreateWindow**

    What it Does:
        Creates a new window with the specified title (e.g., "Menu", "Snake Game").
    Why It’s Used:
        Each window (menu and game) has distinct rendering and functionality. This separation allows the menu to act as a user-friendly entry point and the game to function independently.

**5. glutMainLoop**

    What it Does:
        Enters the main event-processing loop for GLUT.
        The program remains in this loop until explicitly terminated.
    Why It’s Used:
        Ensures continuous interaction with the user through keyboard inputs, rendering updates, and timers.

## Initialization (init.cpp)
### Purpose:
Sets up the game's variables, windows, and configurations before gameplay begins.
Key Functions
**1. initMenuWindow**

    What it Does:
        Configures the menu window's display (displayMenu) and keyboard handling (menuKeyboard).
        Sets a black background using glClearColor.
    Why It’s Used:
        Prepares the menu window for rendering and interaction.

**2. initGameWindow**

    What it Does:
        Configures the game window’s display (displayGame), keyboard input (keyboard), and timer (TimerFunc).
        Sets the game background color (mapBgColor).
    Why It’s Used:
        Initializes game-specific configurations, such as rendering functions and event handlers.

**3. initializeGame**

    What it Does:
        Resets the game state to start fresh:
            Clears and repositions the snake.
            Resets the score, food availability, and game direction.
            Pauses the game until resumed.
    Why It’s Used:
        Ensures the game is properly reset when starting or restarting.

**4. reshape**

    What it Does:
        Adjusts the game window’s size to match the map size dynamically.
    Why It’s Used:
        Prevents distorted visuals when resizing the game window.

## 3. Game Logic (gamelogic.cpp)
### Purpose:
Implements the rules and mechanics of the game, such as moving the snake, handling collisions, and scoring.
Key Functions
**1. moveSnake**

    What it Does:
        Updates the snake's position based on its current direction.
        Checks for collisions with walls or the snake's body.
        Detects if food has been eaten and grows the snake accordingly.
        Adjusts the score and checks for game-over conditions.
    Why It’s Used:
        Core mechanic of the game. It drives gameplay by managing the snake’s movement and interactions with the environment.

**2. TimerFunc**

    What it Does:
        Periodically calls moveSnake to update the game state.
        Uses glutTimerFunc to create a game loop tied to the game's speed (gameSpeed).
    Why It’s Used:
        Ensures the game updates at a consistent pace.

## 4. Rendering (draw.cpp)
### Purpose:
Handles the visual representation of the game, including the snake, food, walls, and HUD.
Key Functions
**1. draw_body_part**

    What it Does:
        Renders a circular segment to represent a part of the snake’s body.
    Why It’s Used:
        Adds realism and aesthetics to the snake.

**2. drawWalls**

    What it Does:
        Draws the boundary walls using repeated calls to drawBrick.
    Why It’s Used:
        Marks the play area’s limits and defines collision boundaries.

**3. drawFood**

    What it Does:
        Places food at a random position, avoiding overlaps with the snake.
        Differentiates between regular and special food.
    Why It’s Used:
        Adds an objective to the game (eating food).

**4. displayGame**

    What it Does:
        Combines all rendering functions to update the game window.
        Uses glClear to clear the screen and glutSwapBuffers to swap buffers for smooth rendering.
    Why It’s Used:
        Displays the current game state visually.

## 5. HUD (hud.cpp)
### Purpose:

Displays useful game information, such as the score, high score, and instructions.
Key Functions
**1. drawText**

    What it Does:
        Renders text on the screen using GLUT's bitmap fonts.
    Why It’s Used:
        Necessary for displaying dynamic information, such as the score and instructions.

**2. drawHUD**

    What it Does:
        Renders the HUD with lives, scores, and instructions.
    Why It’s Used:
        Enhances gameplay by keeping players informed.

## 6. Keyboard Handling (keyboard.cpp)
 ### Purpose:
Maps user inputs to game actions.
Key Functions
**1. Movement (W, A, S, D)**

    What it Does:
        Changes the snake’s direction unless it results in a reverse movement.
    Why It’s Used:
        Enables player control of the snake.

**2. Game Controls (P, R, +, -)**

    What They Do:
        Pause/resume the game, restart, and adjust map size.
    Why They’re Used:
        Provide additional gameplay options.

## 7. Menu (menu.cpp)
### Purpose:

Manages the high score system and menu interface.
Key Functions
**1. loadHighScore & saveHighScore**

    What They Do:
        Read/write the high score to a file.
    Why They’re Used:
        Ensures player progress is saved.

**2. displayMenu**

    What it Does:
        Renders the main menu.
    Why It’s Used:
        Acts as the starting interface.
