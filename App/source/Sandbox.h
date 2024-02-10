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
    ParticleState m_blueParticleState;
    ParticleState m_orangeParticleState;

    std::vector<Particle*> m_blueParticles;
    std::vector<Particle*> m_orangeParticles;
};
