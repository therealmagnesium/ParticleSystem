#pragma once
#include "Core/Base.h"

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Engine
{
	struct AppInfo
	{
		std::string name;
		std::string version;	
		std::string author;
		u32 width;
		u32 height;
		u16 targetFPS;
	};
	
	class Application
	{
	public:
		Application(const AppInfo& info);
		virtual ~Application();	

		static inline Application* Get() { return m_instance; }
		inline AppInfo& GetInfo() { return m_info; }

		void Run();	
		void Quit();
	
		virtual void Update() = 0;
		virtual void Render() = 0;

	protected:
		bool m_running = true;
		AppInfo m_info;
		sf::RenderWindow m_window;

	private:
		void HandleEvents();

	private:
		static Application* m_instance;
	};
}