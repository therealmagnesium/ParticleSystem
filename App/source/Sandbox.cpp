#include "Sandbox.h"

#include <SFML/Window/Mouse.hpp>
#include <math.h>

Sandbox::Sandbox(const AppInfo& info) : Application(info)
{
}

Sandbox::~Sandbox()
{
	for (int i = 0; i < m_particles.size(); i++)	
		delete m_particles[i];
}

void Sandbox::Update()
{
	Particle* particle = new Particle();
	if (m_particles.size() < 30 && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
		particle->SetPosition(mousePosition.x, mousePosition.y);
		m_particles.push_back(particle);
	}
	
	for (int i = 0; i < m_particles.size(); i++)
	{
		m_particles[i]->Update();

		if (m_particles[i]->IsDead())
			m_particles.erase(m_particles.begin() + i);
	}	

	m_currentFrame++;
}

void Sandbox::Render()
{
	for (int i = 0; i < m_particles.size(); i++)
	{
		Particle* particle = m_particles[i];
		particle->Render(&m_window);
	}	
}