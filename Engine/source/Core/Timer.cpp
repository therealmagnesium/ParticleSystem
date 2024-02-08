#include "Core/Timer.h"
#include "Core/Application.h"

namespace Engine
{
    static Application* appInstance = NULL;

    void StartTimer(Timer* timer, float lifetime)
    {
        appInstance = Application::Get();

        if (timer != NULL && lifetime > 0.f)
            timer->lifetime = lifetime;
    }

    void UpdateTimer(Timer* timer)
    {
        if (appInstance == NULL)
            appInstance = Application::Get();

        if (timer != NULL && timer->lifetime > 0.f)
            timer->lifetime -= appInstance->GetDT();
    }

    bool IsTimerDone(Timer* timer)
    {
        if (timer != NULL)
            return timer->lifetime <= 0.f;

        return false;
    }
}
