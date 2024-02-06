#pragma once
#include <Core/Base.h>
#include <Core/Application.h>
#include <Scene/Particle.h>

#include <vector>

using namespace Engine;

class Sandbox : public Application
{
public:
	Sandbox(const AppInfo& info);
	~Sandbox() override;

	void Update() override;
	void Render() override;

private:
	u64 m_currentFrame = 0;
	std::vector<Particle*> m_particles;
};