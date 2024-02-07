#include "Scene/Particle.h"
#include "Core/Application.h"

#include <SFML/Window/Mouse.hpp>
#include <stdlib.h>

namespace Engine
{
    static Application* appInstance = NULL;

    Particle::Particle()
    {
        appInstance = Application::Get();

        m_position = sf::Vector2f(0.f, 0.f);
        m_velocity = sf::Vector2f((rand() % 10) - 5.f, (rand() % 10));
        m_acceleration = sf::Vector2f(0.f, 0.15f);

        m_shape.setRadius(10.f);
        m_shape.setPointCount(32);
        m_shape.setOutlineThickness(5.f);
        m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
    }

    void Particle::Update()
    {
        m_velocity += m_acceleration;
        m_position += m_velocity;

        m_lifeSpan -= 10.f;
    }

    void Particle::Render(sf::RenderWindow* window, const ParticleState& state)
    {
        if (m_lifeSpan > 0.f)
        {
            m_shape.setPosition(m_position);
            m_shape.setFillColor(sf::Color(state.fillColor.r, state.fillColor.g,
                state.fillColor.b, (u8)m_lifeSpan));
            m_shape.setOutlineColor(sf::Color(state.outlineColor.r, state.outlineColor.g, 
                state.outlineColor.b, (u8)m_lifeSpan));
        }

        window->draw(m_shape);
    }

    void SpawnParticles(std::vector<Particle*>& particles, const ParticleState& state)
    {
        Particle* particle = new Particle();
        if (particles.size() < state.maxParticles)
        {
            particle->SetPosition(state.spawnPosition.x, state.spawnPosition.y);
            particle->GetShape().setFillColor(state.fillColor);
            particle->GetShape().setOutlineColor(state.outlineColor);
            
            particles.push_back(particle);
        }
    }

    void UpdateParticles(std::vector<Particle*>& particles)
    { 
        for (int i = 0; i < particles.size(); i++)
        {
            particles[i]->Update();

            if (particles[i]->IsDead())
                particles.erase(particles.begin() + i);
        } 
    }

    void DrawParticles(std::vector<Particle*>& particles, const ParticleState& state)
    {
        for (int i = 0; i < particles.size(); i++)
        {
            Particle* particle = particles[i];
            particle->Render(&appInstance->GetWindow(), state);
        }
    }

    void FreeParticles(std::vector<Particle*>& particles)
    { 
        for (int i = 0; i < particles.size(); i++)	
            delete particles[i];
    }
}
