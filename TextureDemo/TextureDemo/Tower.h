#pragma once
#include "GameObject.h"
#include "Unit.h"
#include "Projectile.h"

using namespace std;
class Tower :
	public GameObject
{
public:
	Tower(int type, 
		  bool playerControlled, 
		  glm::vec3 towerScale, 
		  glm::vec3 &entityPosition, 
		  GLuint entityTexture, 
		  GLuint projectileTexture,
		  GLint entityNumElements);
	~Tower();
	void update(double deltaTime, vector<Unit*> enemies);
	void render(Shader &shader);
	void shoot(glm::vec3 target);
	void removeProjectile(int index);
	inline vector<Projectile*> getProjectiles() { return projectiles; }
private:
	int type = 0;
	bool playerControlled;
	double health;
	GLuint projectileTexture;
	GLuint size;
	vector<Projectile*> projectiles;
	float shootingRange = 0.5, 
		  projectileTimer = glfwGetTime(), 
		  projectileDelay = 2;
};

