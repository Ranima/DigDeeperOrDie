#pragma once

#include "Entity.h"
#include <time.h>

class Factory
{	
	ObjectPool<Entity>	  entities;
	
	// The factory will store an object pool for each component type
	ObjectPool<Transform> transforms;
	ObjectPool<Rigidbody> rigidbodies;
	ObjectPool<Collider>  colliders;
	ObjectPool<Sprite>    sprites;
	ObjectPool<Lifetime>  lifetimes;
	ObjectPool<Camera>    cameras;
	ObjectPool<Text>	  texts;
	ObjectPool<PlayerController> controllers;

public:

	// iterators to access the entity pool
	ObjectPool<Entity>::iterator begin() { return entities.begin(); }
	ObjectPool<Entity>::iterator end() { return entities.end(); }

	// for now, they're all the same size
	Factory(size_t size = 512)
								: entities(size), transforms(size), rigidbodies(size),
								  colliders(size), sprites(size), lifetimes(size),
								  cameras(size), controllers(size), texts(size)
	{
	}

	// What follows are specialized spawning functions
	// just observe the steps taken and replicate for your own usages

	ObjectPool<Entity>::iterator spawnCamera(float w2, float h2, float zoom)
	{
		auto e = entities.push();
		e->transform = transforms.push();
		e->camera = cameras.push();
		e->camera->offset = vec2{w2,h2};
		e->camera->scale = vec2{ zoom,zoom };
		return e;
	}

	ObjectPool<Entity>::iterator spawnStaticImage(unsigned sprite, float x, float y, float w, float h)
	{
		auto e = entities.push();
		e->transform = transforms.push();
		e->sprite = sprites.push();
		e->sprite->sprite_id = sprite;
		e->sprite->dimensions = vec2{w,h};
		e->transform->setLocalPosition(vec2{ x,y });	
		return e;
	}

	ObjectPool<Entity>::iterator spawnBullet(unsigned sprite, vec2 pos, vec2 dim, float ang, float impulse, unsigned faction)
	{
		auto e = entities.push();

		e->transform = transforms.push();
		e->rigidbody = rigidbodies.push();
		e->sprite = sprites.push();
		e->lifetime = lifetimes.push();
		e->collider = colliders.push();

		e->transform->setLocalPosition(pos);
		e->transform->setLocalScale(dim);
		e->transform->setLocalAngle(ang);

		e->sprite->sprite_id = sprite;
		e->sprite->dimensions = vec2{1.2f, 1.2f};

		e->rigidbody->addImpulse(e->transform->getGlobalUp() * impulse);

		e->rigidbody->addSpin(-90 * DEG2RAD);

		e->lifetime->lifespan = 1.6f;
		
		return e;
	}

	ObjectPool<Entity>::iterator spawnPlayer(unsigned sprite, unsigned font)
	{
		auto e = entities.push();

		e->transform = transforms.push();
		e->rigidbody = rigidbodies.push();
		e->sprite = sprites.push();
		e->collider = colliders.push();
		e->controller = controllers.push();
		e->text = texts.push();

		e->text->sprite_id = font;
		e->text->offset = vec2{ -24,-24 };
		e->text->off_scale = vec2{.5f,.5f};
		e->text->setString("Player1");

		e->transform->setLocalScale(vec2{48,48});

		e->transform->setLocalAngle(-90 * DEG2RAD);

		e->sprite->sprite_id = sprite;

		return e;
	}

	ObjectPool<Entity>::iterator spawnGameOver( unsigned font )
	{
		auto e = entities.push();

		e->transform = transforms.push();
		e->text = texts.push();

		e->text->sprite_id = font;
		e->text->offset = vec2{ -400, -100};
		e->text->off_scale = vec2{ 0.5f,0.5f };
		e->text->setString("Game Over");

		e->transform->setLocalScale(vec2{ 48,48 });

		return e;
	}

	ObjectPool<Entity>::iterator spawnstartbutton(unsigned sprite)
	{
		auto e = entities.push();

		e->transform = transforms.push();
		e->rigidbody = rigidbodies.push();
		e->sprite = sprites.push();
		e->collider = colliders.push();
		e->lifetime = lifetimes.push();

		e->sprite->sprite_id = sprite;
		e->sprite->dimensions = vec2{ 1.0f,1.0f };

		e->transform->setLocalScale(vec2{ 48,48 });
		e->transform->setLocalPosition(vec2{ -400, -300 });

		return e;
	}

	ObjectPool<Entity>::iterator spawnAsteroid(unsigned sprite, vec2 offset)
	{
		auto e = entities.push();

		e->transform = transforms.push();
		e->rigidbody = rigidbodies.push();
		e->sprite = sprites.push();
		e->collider = colliders.push();
		e->lifetime = lifetimes.push();

		e->transform->setLocalScale(vec2{ 48,48 });

		//e->transform->setGlobalPosition(vec2{ offset.x + 50 , randRange(0, 1) + offset.y });
		e->rigidbody->addImpulse((e->transform->getGlobalRight() * -1) * 50);
		std::cout << e->transform->getGlobalPosition().x << " " << e->transform->getGlobalPosition().y << std::endl;
		std::cout << offset.x << " " << offset.y << std::endl;
		//srand(time(0));

		std::cout << time(NULL); 
		float value = rand() % 10 + 1;
		e->transform->setGlobalPosition(vec2{ 450, rand01() * 600 - 300 });

		e->rigidbody->addSpin(45 * DEG2RAD);

		e->lifetime->lifespan = 25;

		e->sprite->sprite_id = sprite;

		return e;
	}
};


