#include "Sandbox.h"

#include <Core/Timer.h>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

#include <time.h>
#include <math.h>

Sandbox::Sandbox(const AppInfo& info) : Application(info)
{
    srand(time(NULL));

    // Define particle state attributes
    m_blueParticleState.spawnRate = 0.02f;
    m_blueParticleState.dieSpeed = 300.f;
    m_blueParticleState.spawnPosition = sf::Vector2i(0, 0);
    m_blueParticleState.fillColor = sf::Color(0x00, 0xFF, 0xDD);
    m_blueParticleState.outlineColor = sf::Color(0x00, 0xFF, 0xBB);

    m_orangeParticleState.spawnRate = 0.03f;
    m_orangeParticleState.dieSpeed = 200.f;
    m_orangeParticleState.spawnPosition = sf::Vector2i(400, 200);
    m_orangeParticleState.fillColor = sf::Color(0xfc, 0xdc, 0x58);
    m_orangeParticleState.outlineColor = sf::Color(0xbd, 0xa3, 0x39);

    // Set how long to wait before creating the first particle
    StartTimer(&m_blueParticleState.timer, m_blueParticleState.spawnRate);
    StartTimer(&m_orangeParticleState.timer, m_orangeParticleState.spawnRate);
}

Sandbox::~Sandbox()
{
    // Free memory from particles vector
    FreeParticles(m_blueParticles);
    FreeParticles(m_orangeParticles);
}

void Sandbox::Update()
{
    // LOG("%d\n", (u16)ceil(1.f / GetDT()));

    // Set the velocity and acceleration of the particle state every frame
    m_blueParticleState.velocity = sf::Vector2f((rand() % 400) - 200.f, (rand() % 200) - 500.f);
    m_blueParticleState.acceleration = sf::Vector2f(0.f, 1000.f);

    m_orangeParticleState.velocity = sf::Vector2f((rand() % 400) - 200.f, (rand() % 200) - 500.f);
    m_orangeParticleState.acceleration = sf::Vector2f(0.f, 1000.f);

    /* Get the mouse position relative to the window,
     * and then set the particle state's spawn position
     * to be the mouse position */
    sf::Vector2i mousePosition = sf::Mouse::getPosition(GetWindow());
    m_blueParticleState.spawnPosition = mousePosition;

    // Only spawn particles if the left mouse button is held
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        SpawnParticles(m_blueParticles, m_blueParticleState);

    SpawnParticles(m_orangeParticles, m_orangeParticleState);

    // Always update the particles
    UpdateParticles(m_blueParticles, m_blueParticleState);
    UpdateParticles(m_orangeParticles, m_orangeParticleState);
}

void Sandbox::Render()
{
    // Draw the particles every frame
    DrawParticles(m_blueParticles, m_blueParticleState);
    DrawParticles(m_orangeParticles, m_orangeParticleState);
}
