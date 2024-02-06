#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace Engine
{
	class Particle
	{
	public:
		Particle();

        inline bool IsDead() const { return (m_lifeSpan < 0.f); }
    
		inline void SetPosition(float x, float y) { m_position = sf::Vector2f(x, y); }
		inline void SetVelocity(float x, float y) { m_velocity = sf::Vector2f(x, y); }
		inline void SetAcceleration(float x, float y) { m_acceleration = sf::Vector2f(x, y); }
	
		void Update();
		void Render(sf::RenderWindow* window);

	private:
		void HandleCollisions();
	
	private:
        float m_lifeSpan = 255.f;
    
		sf::Vector2f m_position;
		sf::Vector2f m_velocity;
		sf::Vector2f m_acceleration;
		sf::CircleShape m_shape;	
	};
}