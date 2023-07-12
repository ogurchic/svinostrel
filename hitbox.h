//hitbox.h
#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
public:
	int X, Y, Width, Height;
	Hitbox(int startX, int startY, int width, int height);
	bool checkCollision(Hitbox other);
};

#endif
