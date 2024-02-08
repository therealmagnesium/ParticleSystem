#include "Sandbox.h"

#include <Core/Timer.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

Sandbox::Sandbox(const AppInfo& info) : Application(info)
{
    // Define particle state attributes
    m_particleState.spawnRate = 0.02f;
    m_particleState.dieSpeed = 600.f;
    m_particleState.spawnPosition = sf::Vector2i(0, 0);
    m_particleState.fillColor = sf::Color(0x00, 0xFF, 0xDD);
    m_particleState.outlineColor = sf::Color(0x00, 0xFF, 0xBB);

    // Set how long to wait before creating the first particle
    StartTimer(&m_particleState.timer, m_particleState.spawnRate);
}

Sandbox::~Sandbox()
{
    // Free memory from particles vector
    FreeParticles(m_particles);
}

void Sandbox::Update()
{
    /* Get the mouse position relative to the window,
     * and then set the particle state's spawn position
     * to be the mouse position */
    sf::Vector2i mousePosition = sf::Mouse::getPosition(GetWindow());
    m_particleState.spawnPosition = mousePosition;

    // Only spawn particles if the left mouse button is held
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        SpawnParticles(m_particles, m_particleState);

    // Always update the particles
    UpdateParticles(m_particles, m_particleState);
}

void Sandbox::Render()
{
    // Draw the particles every frame
    DrawParticles(m_particles, m_particleState);
}
