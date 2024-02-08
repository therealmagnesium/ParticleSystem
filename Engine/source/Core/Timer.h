#pragma once

namespace Engine
{
    struct Timer
    {
        float lifetime;
    };

    void StartTimer(Timer* timer, float lifetime);
    void UpdateTimer(Timer* timer);
    bool IsTimerDone(Timer* timer);
}