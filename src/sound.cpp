#include <algorithm>
#include <filesystem>

#include "ErrorLogger.hpp"
#include "Sound.hpp"

namespace kn
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

float Sound::getVolume() const { return m_volume / MIX_MAX_VOLUME; }

void Sound::unload()
{
    if (m_sound)
        Mix_FreeChunk(m_sound);
}

} // namespace kn
