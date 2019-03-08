#include "Board.h"

Board::Board(Camera* camera, vector<Castle*> castles) : camera(camera),castles(castles)
{
}

Board::~Board()
{
}

void Board::update(double deltaTime)
{
	glm::vec2 mousePosition = camera->getMousePosition();
	glm::vec2 cameraPosition = glm::vec2(camera->getPosition().x, camera->getPosition().y);
	//calls castle updates
	for (int i = 0; i < castles.size(); i++)
	{
		castles.at(i)->update(deltaTime, (mousePosition - cameraPosition), castles.at((i) ? 0 : 1));
	}
}

//renders all board entities 
void Board::render(Shader &shader)
{
	for (int i = 0; i < castles.size(); i++)
	{
		castles.at(i)->render(shader);
	}
}
