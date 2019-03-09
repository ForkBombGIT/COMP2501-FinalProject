#include "Projectile.h"

Projectile::Projectile(glm::vec3 &entityPos, GLuint texture, GLint entityNumElements, glm::vec2 dir, float speed, double damage)
	: GameObject(entityPos, texture, entityNumElements), speed(speed), direction(dir), damage(damage)
{
	scale = glm::vec3(0.1f);
}

void Projectile::update(double deltaTime) {
	// Update object position
	position.x += (direction.x * speed) * deltaTime;
	position.y += (direction.y * speed) * deltaTime;
}