#pragma once

#include "Vec2.h"
#include "Rect.h"

class Player
{
public:
	Player();
	Player( class Random& rng );
	Player( const Vec2& pos );
	void Update( class Keyboard& kbd,float dt );
	void Draw( class Graphics& gfx ) const;

	const Vec2& GetPos() const;
private:
	static constexpr float moveSpeed = 3.5f;
	const Vec2 size;
	Vec2 pos;
	Rect hitbox;
	const Rect scrRect;
};