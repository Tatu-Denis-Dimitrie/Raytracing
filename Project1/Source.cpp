#include <SDL.h>
#include <cmath>
#include <iostream>
#include <vector>

#define COLOR_WHITE 0xFFFFFFFF
#define RAY_COUNT 360

struct Circle
{
	int x, y, r;
	Circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

struct Ray {
	double xStart, yStart;
	double angle;
};
void FillCircle(SDL_Surface* surface, Circle circle)
{
	for (double x = circle.x - circle.r; x <= circle.x + circle.r; x++)
	{
		for (double y = circle.y - circle.r; y <= circle.y + circle.r; y++)
		{
			if (std::pow(x - circle.x, 2) + std::pow(y - circle.y, 2) <= std::pow(circle.r, 2))
			{
				SDL_Rect pixel = { (int)x, (int)y, 1, 1 };
				SDL_FillRect(surface, &pixel, COLOR_WHITE);
			}
		}
	}
}
void generateRays(Circle circle, Ray rays[RAY_COUNT]) {
	for (int i = 0; i < RAY_COUNT; i++)
	{
		double angle = ((double) i / RAY_COUNT)* 2 * M_PI;
		Ray ray = { circle.x,circle.y,angle};
		rays[i] = ray;
	}
}

void FillRays(SDL_Surface* surface, Ray rays[RAY_COUNT], Uint32 color,Circle circle)
{
	for (int i = 0; i < RAY_COUNT; i++)
	{
		Ray ray = rays[i];

		int endOfScreen = 0;
		int objectHit = 0;

		double pace = 1;

		double x_draw = ray.xStart;
		double y_draw = ray.yStart;

		while (!endOfScreen && !objectHit)
		{
			x_draw += pace*cos(ray.angle);
			y_draw += pace*sin(ray.angle);

			SDL_Rect pixel = { (int)x_draw, (int)y_draw, 1, 1 };
			SDL_FillRect(surface, &pixel, color);
			if (x_draw<0 || x_draw > 800 || y_draw < 0 || y_draw > 600)
			{
				endOfScreen = 1;
			}
			if (std::pow(x_draw - circle.x, 2) + std::pow(y_draw - circle.y, 2) <= std::pow(circle.r, 2))
			{
				break;
			}
		}
	}
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Raytracing SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	Circle circle(300, 300, 100);
	Circle shadowCircle(600, 300, 140);
	Ray rays[360];
	generateRays(circle, rays);

	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.motion.type == SDL_MOUSEMOTION && event.motion.state != 0)
			{
				circle.x = event.motion.x;
				circle.y = event.motion.y;
				generateRays(circle, rays);
			}
		}
	SDL_FillRect(surface, NULL, 0);
	FillCircle(surface, circle);

	FillCircle(surface, shadowCircle);
	FillRays(surface, rays, COLOR_WHITE,shadowCircle);

    SDL_UpdateWindowSurface(window);
	SDL_Delay(10);
	}
    return 0;
}