#include "Core/Application.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>

namespace Engine
{
    Application* Application::m_instance = NULL;

    Application::Application(const AppInfo& info) : m_info(info)
    {
        // Set the application's instance
        m_instance = this;

        // Create the window
        std::string windowTitle = m_info.name + " v" + m_info.version;
        m_window.create(sf::VideoMode(m_info.windowWidth, m_info.windowHeight), windowTitle);
        m_window.setFramerateLimit(m_info.targetFPS);
    }

    Application::~Application() {}

    void Application::HandleEvents()
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    LOG("Quitting application...\n");
                    Quit();
                    break;
                }

                case sf::Event::Resized:
                {
                    LOG("Resizing window to %dx%d\n", event.size.width, event.size.height);

                    sf::View view(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height));
                    m_window.setView(view);

                    break;
                }

                default:
                    break;
            }

            if (event.type == sf::Event::Closed)
                Quit();
        }
    }

    void Application::Run()
    {
        LOG("Application starting...\n");

        while (m_running)
        {
            m_deltaTime = m_deltaClock.restart();

            HandleEvents();

            m_window.clear(sf::Color(0x11, 0x13, 0x20)); // Begin rendering

            Update();
            Render();

            m_window.display(); // End rendering
        }
    }

    void Application::Quit()
    {
        m_running = false;
        m_window.close();
    }
}
