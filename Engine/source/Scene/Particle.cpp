#include "Scene/Particle.h"
#include "Core/Application.h"

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

    void Particle::Render(sf::RenderWindow* window)
    {
        if (m_lifeSpan > 0.f)
        {
            m_shape.setPosition(m_position);
            m_shape.setFillColor(sf::Color(0xFF, 0xDD, 0x00, (u8)m_lifeSpan));
            m_shape.setOutlineColor(sf::Color(0xFF, 0xBB, 0x00, (u8)m_lifeSpan));
        }

        window->draw(m_shape);
    }

    void Particle::HandleCollisions()
    {
        bool horizontalCheck = (m_position.x < 0.f + m_shape.getRadius()) ||
                               (m_position.x > appInstance->GetInfo().width - m_shape.getRadius());

        bool verticalCheck = (m_position.y < 0.f + m_shape.getRadius()) ||
                             (m_position.y > appInstance->GetInfo().height - m_shape.getRadius());

        if (horizontalCheck)
            m_velocity.x *= -1.f;

        if (verticalCheck)
            m_velocity.y *= -1.f;
    }

}
