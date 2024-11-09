#include <SDL_mixer.h>
#include <algorithm>
#include <filesystem>

#include "ErrorLogger.hpp"
#include "Music.hpp"

namespace kn::music
{
static Mix_Music* m_music = nullptr;
static float m_volume = MIX_MAX_VOLUME;

void load(const std::string& fileDir)
{
    unload();

    const std::filesystem::path filePath(fileDir);

    if (const std::string extension = filePath.extension().string();
        extension == ".ogg" || extension == ".mp3" || extension == ".wav")
    {
        m_music = Mix_LoadMUS(fileDir.c_str());
        if (!m_music)
            FATAL("Failed to load music: " + fileDir);
    }
    else
        FATAL("Unsupported file format: " + fileDir);
}

void unload()
{
    if (m_music)
    {
        Mix_FreeMusic(m_music);
        m_music = nullptr;
    }
}

void play(const int loops, const int fadeMs)
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    if (fadeMs > 0)
    {
        if (Mix_FadeInMusic(m_music, loops, fadeMs) == -1)
            FATAL("Failed to play music: " + std::string(Mix_GetError()));
    }
    else
    {
        if (Mix_PlayMusic(m_music, loops) == -1)
            FATAL("Failed to play music: " + std::string(Mix_GetError()));
    }
}

void rewind()
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_RewindMusic();
}

void stop()
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_HaltMusic();
}

void pause()
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_PauseMusic();
}

void resume()
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_ResumeMusic();
}

void fadeOut(const int fadeMs)
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_FadeOutMusic(fadeMs);
}

void setVolume(const float volume)
{
    m_volume = volume;
    Mix_VolumeMusic(static_cast<int>(MIX_MAX_VOLUME * std::clamp(m_volume, 0.0f, 1.0f)));
}

float getVolume() { return m_volume; }

} // namespace kn::music
