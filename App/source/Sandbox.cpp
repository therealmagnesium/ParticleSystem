#include "Sandbox.h"
#include <SFML/Window/Mouse.hpp>

#include <math.h>

Sandbox::Sandbox(const AppInfo& info) : Application(info)
{
	m_particleState.maxParticles = 30;
	m_particleState.spawnPosition = sf::Vector2i(0, 0);
	m_particleState.fillColor = sf::Color(0x00, 0xFF, 0xDD);
	m_particleState.outlineColor = sf::Color(0x00, 0xFF, 0xBB);
}

Sandbox::~Sandbox()
{
	FreeParticles(m_particles);
}

void Sandbox::Update()
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(GetWindow());
	m_particleState.spawnPosition = mousePosition;
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		SpawnParticles(m_particles, m_particleState);

	UpdateParticles(m_particles);
}

void Sandbox::Render()
{
	DrawParticles(m_particles, m_particleState);
}