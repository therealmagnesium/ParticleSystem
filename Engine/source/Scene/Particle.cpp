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
        m_velocity = sf::Vector2f((rand() % 800) - 400.f, (rand() % 200) + 600.f);
        m_acceleration = sf::Vector2f(0.f, 1.5f);

        m_shape.setRadius(10.f);
        m_shape.setPointCount(32);
        m_shape.setOutlineThickness(5.f);
        m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
    }

    void Particle::Update(const ParticleState& state)
    {
        m_velocity += m_acceleration;
        m_position += m_velocity * appInstance->GetDT();

        m_lifeSpan -= state.dieSpeed * appInstance->GetDT();
    }

    void Particle::Render(sf::RenderWindow* window, const ParticleState& state)
    {
        if (m_lifeSpan > 0.f)
        {
            m_shape.setPosition(m_position);
            m_shape.setFillColor(sf::Color(state.fillColor.r, state.fillColor.g, state.fillColor.b, (u8)m_lifeSpan));
            m_shape.setOutlineColor(
                sf::Color(state.outlineColor.r, state.outlineColor.g, state.outlineColor.b, (u8)m_lifeSpan));
        }

        window->draw(m_shape);
    }

    void SpawnParticles(std::vector<Particle*>& particles, ParticleState& state)
    {
        if (IsTimerDone(&state.timer))
        {
            Particle* particle = new Particle();
            particle->SetPosition(state.spawnPosition.x, state.spawnPosition.y);
            particle->GetShape().setFillColor(state.fillColor);
            particle->GetShape().setOutlineColor(state.outlineColor);

            particles.push_back(particle);

            StartTimer(&state.timer, state.spawnRate);
        }
    }

    void UpdateParticles(std::vector<Particle*>& particles, ParticleState& state)
    {
        UpdateTimer(&state.timer);

        for (int i = 0; i < particles.size(); i++)
        {
            particles[i]->Update(state);

            if (particles[i]->IsDead())
                particles.erase(particles.begin() + i);
        }
    }

    void DrawParticles(std::vector<Particle*>& particles, ParticleState& state)
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
