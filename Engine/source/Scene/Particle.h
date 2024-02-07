#pragma once
#include "Core/Base.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

namespace Engine
{
    struct ParticleState
    {
        u32 maxParticles;
        sf::Vector2i spawnPosition;         
        sf::Color fillColor;
        sf::Color outlineColor;
    };
    
    class Particle
    {
    public:
        Particle();

        inline bool IsDead() const { return (m_lifeSpan < 0.f); }
        inline sf::CircleShape& GetShape() { return m_shape; }

        inline void SetPosition(float x, float y) { m_position = sf::Vector2f(x, y); }
        inline void SetVelocity(float x, float y) { m_velocity = sf::Vector2f(x, y); }
        inline void SetAcceleration(float x, float y) { m_acceleration = sf::Vector2f(x, y); }

        void Update();
        void Render(sf::RenderWindow* window, const ParticleState& state);

    private:
        float m_lifeSpan = 255.f;

        sf::Vector2f m_position;
        sf::Vector2f m_velocity;
        sf::Vector2f m_acceleration;
        sf::CircleShape m_shape;
    };

    void SpawnParticles(std::vector<Particle*>& particles, const ParticleState& state);
    void UpdateParticles(std::vector<Particle*>& particles);
    void DrawParticles(std::vector<Particle*>& particles, const ParticleState& state);
    void FreeParticles(std::vector<Particle*>& particles);
}
