#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <cmath>

#include "world.h"

#define TICK_30HZ 30
#define TICK_60HZ 60
#define TICK_120HZ 120

#define FRAME_RATE_30HZ	30
#define FRAME_RATE_60HZ	60
#define FRAME_RATE_120HZ 120

//======================================
// Window Properties

#define WINDOW_RES_X 1280
#define WINDOW_RES_Y 720

#define WINDOW_TITLE "Ant Simulator"

//======================================

class window {
public:
	/// <summary>
	/// Displays the window that will run the program
	/// </summary>
	/// <param name="_x">The width of the window</param>
	/// <param name="_y">The height of the window</param>
	/// <param name="frame_rate">The base frame rate that the program should run, methods scale as the actual frame rate changes from this value</param>
	window(int resX, int resY, float tickRate);


};





#endif // !WINDOW_H

