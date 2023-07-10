//bullet.cpp
#include "bullet.h"
#include "renderer.h"
#include "ship.h"

Bullet::Bullet(int start_x, int start_y) {
	bullet_x = start_x;
	bullet_y = start_y;
}

void Bullet::shot() {
	if (bullet_y >= 0)
		bullet_y--;
}

void Bullet::drawBullet() {
	drawString(bullet_x, bullet_y, "       *", frontBuffer);
}