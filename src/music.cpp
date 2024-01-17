#include "Music.hpp"
#include "ErrorLogger.hpp"

#include <algorithm>
#include <filesystem>

namespace kn
{
namespace music
{

static Mix_Music* m_music = nullptr;
static float m_volume = MIX_MAX_VOLUME;

void load(const std::string& fileDir)
{
    unload();

    std::filesystem::path filePath(fileDir);
    std::string extension = filePath.extension().string();

    if (extension == ".ogg" || extension == ".mp3" || extension == ".wav")
    {
        m_music = Mix_LoadMUS(fileDir.c_str());
        if (!m_music)
            FATAL("Failed to load music: " + fileDir);
    }
    else
    {
        FATAL("Unsupported file format: " + fileDir);
    }
}

void unload()
{
    if (m_music)
    {
        Mix_FreeMusic(m_music);
        m_music = nullptr;
    }
}

void play(int loops, int fadeMs)
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    if (fadeMs > 0)
    {
        if (Mix_FadeInMusic(m_music, loops, fadeMs) == -1)
        {
            FATAL("Failed to play music: " + std::string(Mix_GetError()));
            return;
        }
    }
    else
    {
        if (Mix_PlayMusic(m_music, loops) == -1)
        {
            FATAL("Failed to play music: " + std::string(Mix_GetError()));
            return;
        }
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

void fadeOut(int fadeMs)
{
    if (!m_music)
    {
        FATAL("No music loaded.");
        return;
    }

    Mix_FadeOutMusic(fadeMs);
}

void setVolume(float volume)
{
    m_volume = volume;
    Mix_VolumeMusic(MIX_MAX_VOLUME * std::clamp(m_volume, 0.0f, 1.0f));
}

float getVolume() { return m_volume; }

} // namespace music
} // namespace kn
