#include "Tile.h"



Tile::Tile(string tex_ID, int x, int y)
{
	tile.SetTexture(tex_ID);
	tile.SetSpriteDimension(64, 64);
	tile.SetTextureDimension(1, 1, 64, 64);
	worldPos.x = x;
	worldPos.y = y;
}

void Tile::Draw()
{
	tile.Draw(worldPos.x, worldPos.y);
}

void Tile::Update()
{
}


Tile::~Tile()
{
}
