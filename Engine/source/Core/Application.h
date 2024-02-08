#pragma once
#include "Core/Base.h"

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace Engine
{
    struct AppInfo
    {
        std::string name;
        std::string version;
        std::string author;
        u32 windowWidth;
        u32 windowHeight;
        u16 targetFPS;
    };

    class Application
    {
    public:
        Application(const AppInfo& info);
        virtual ~Application();

        static inline Application* Get() { return m_instance; }

        inline float GetDT() const { return m_deltaTime.asSeconds(); }
        inline u64 GetCurrentFrame() const { return m_currentFrame; }
        inline AppInfo& GetInfo() { return m_info; }
        inline sf::RenderWindow& GetWindow() { return m_window; }

        void Run();
        void Quit();

        virtual void Update() = 0;
        virtual void Render() = 0;

    private:
        void HandleEvents();

    protected:
        sf::RenderWindow m_window;

    private:
        bool m_running = true;
        u64 m_currentFrame = 0;

        AppInfo m_info;

        sf::Time m_deltaTime;
        sf::Clock m_deltaClock;

        static Application* m_instance;
    };
}
