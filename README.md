<h1 align="center">Ray Tracing Simulation with SDL2</h1>  
<h3 align="center">  
This C++ project demonstrates a simple ray tracing effect using SDL2. A light source (represented as a circle) emits rays in 360 directions. When the user moves the mouse while holding a button, the light source follows the cursor, dynamically updating the rays' positions. The rays stop when they collide with an obstacle (another circle), creating a basic shadow effect.

**Features:**  
✔ Uses SDL2 to render graphics.  
✔ Simulates light rays interacting with an obstacle.  
✔ Real-time mouse movement detection to update the light source.  
</h3>
## How to Run

1. Open the project in **Visual Studio**, **Code::Blocks**, or another C++ IDE that supports SDL2.
2. Make sure you have **SDL2** installed and properly configured in your IDE.  
   - You can download SDL2 from [here](https://github.com/libsdl-org/SDL).
3. Set up the correct **SDL2 include** and **library** paths in your IDE’s project settings.
4. Compile and run the project.
5. Use the mouse to move the light source, and hold the left mouse button to see the rays follow the cursor and interact with obstacles.

**Note**: The rays will stop when they collide with an obstacle (another circle) and create a shadow effect.

## Dependencies
- **SDL2** (for rendering graphics and handling events)
- **C++ Standard Library**

## Future Enhancements
- Add more complex obstacles, like rectangles or polygons.
- Implement reflection and refraction for more realistic lighting effects.
- Add color variations to the rays and obstacles.
- Optimize performance for rendering multiple light sources and obstacles.

This project is a simple yet powerful demonstration of basic ray tracing and SDL2 rendering! 🚀