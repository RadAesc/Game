#pragma once

#include "Vec2.h"
#include "Rect.h"
#include "Surface.h"

class Food
{
protected:
	enum class MoveState
	{
		Moving,
		Waiting,
		Hurting
	};
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
	void RandomizeState( class Random& rng );
protected:
	const Vec2 size;
	Vec2 pos;
	Rect hitbox;
	static constexpr int unhitTime = 2;
	int hitTimer = 0;
	MoveState state = MoveState::Waiting;
private:
};

class HotDog : public Food
{
public:
	HotDog();
	
	HotDog( const HotDog& other );
	HotDog& operator=( const HotDog& other );

	void Update( class Random& rng,float dt );
	void Draw( class Graphics& gfx ) const;

	void Hurt( int amount );
	void Target( const Vec2& targetPos );
	void BounceOffOf( const Vec2& pos );

	operator bool() const;
private:
	static constexpr float speed = 30.5f;
	static const Surface spr;
	Vec2 target;
	static constexpr int maxHP = 10;
	int hp = maxHP;
};

class Meatball : public Food
{
public:
	Meatball( const Vec2& pos );

	Meatball( const Meatball& other );
	Meatball& operator=( const Meatball& other );

	void Update( class Random& rng,float dt );
	void Draw( class Graphics& gfx ) const;

	void Target( const Vec2& targetPos );
	void Hurt( int damage );

	bool IsAlive() const;
private:
	static constexpr float speed = 220.5f;
	Vec2 target;
	Vec2 vel;
	bool canRetarget = true;
	static constexpr int waitTime = 10;
	int moveTimer = waitTime;
	static constexpr int maxHP = 15;
	int hp = maxHP;
};