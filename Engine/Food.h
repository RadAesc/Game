#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "Surface.h"

class Food
{
public:
	Food();
	Food( class Random& rng );
	Food( const Vec2& pos );
	Food( const Vec2& pos,const Vec2& size );

	void Update( float dt );
	void Draw( class Graphics& gfx ) const;

	const Vec2& GetPos() const;
	const Rect& GetRect() const;
protected:
	const Vec2 size;
	Vec2 pos;
	Rect hitbox;
private:
};

class HotDog : public Food
{
public:
	HotDog();

	void Update( float dt );
	void Draw( class Graphics& gfx ) const;

	void Target( const Vec2& targetPos );
private:
	static constexpr float speed = 30.5f;
	const Surface spr = { "../../HotDog.bmp" };
	Vec2 target;
};