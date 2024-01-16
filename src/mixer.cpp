#include <algorithm>
#include <filesystem>

#include "ErrorLogger.hpp"
#include "Mixer.hpp"

namespace kn
{
namespace mixer
{

Sound::Sound(const std::string& fileDir)
{
    std::filesystem::path filePath(fileDir);
    std::string extension = filePath.extension().string();

    if (extension == ".ogg" || extension == ".mp3" || extension == ".wav")
    {
        m_sound = Mix_LoadWAV(fileDir.c_str());
        if (!m_sound)
            FATAL("Failed to load sound: " + fileDir);
    }
    else
    {
        FATAL("Unsupported file format: " + fileDir);
    }
}

void Sound::play(int loops, int playTime, int fadeMs)
{
    int channelNum = -1;

    if (fadeMs > 0)
        channelNum = Mix_FadeInChannelTimed(-1, m_sound, loops, fadeMs, playTime);
    else
        channelNum = Mix_PlayChannelTimed(-1, m_sound, loops, playTime);

    if (channelNum == -1)
    {
        FATAL("Failed to play sound: " + std::string(Mix_GetError()));
        return;
    }

    Mix_Volume(channelNum, (int)m_volume);
}

void Sound::setVolume(float newVolume)
{
    m_volume = MIX_MAX_VOLUME * std::clamp(newVolume, 0.0f, 1.0f);
}

void Sound::unload()
{
    if (m_sound)
        Mix_FreeChunk(m_sound);
}

Music::Music(const std::string& fileDir)
{
    load(fileDir);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
}

void Music::setVolume(float newVolume)
{
    Mix_VolumeMusic((int)(MIX_MAX_VOLUME * std::clamp(newVolume, 0.0f, 1.0f)));
}

void Music::play(int loops, int fadeMs)
{
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

void Music::pause(int fadeMs)
{
    if (fadeMs > 0)
        Mix_FadeOutMusic(fadeMs);
    else
        Mix_PauseMusic();
}

void Music::resume() { Mix_ResumeMusic(); }

void Music::load(const std::string& fileDir)
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

void Music::unload()
{
    if (m_music)
        Mix_FreeMusic(m_music);
}

} // namespace mixer
} // namespace kn
