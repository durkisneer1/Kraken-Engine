#include <algorithm>
#include <filesystem>

#include "ErrorLogger.hpp"
#include "Sound.hpp"

namespace kn
{
Sound::Sound(const std::string& fileDir)
{
    const std::filesystem::path filePath(fileDir);

    if (const std::string extension = filePath.extension().string();
        extension == ".ogg" || extension == ".mp3" || extension == ".wav")
    {
        m_sound = Mix_LoadWAV(fileDir.c_str());
        if (!m_sound)
            FATAL("Failed to load sound: " + fileDir)
    }
    else
    {
        FATAL("Unsupported file format: " + fileDir)
    }
}

void Sound::play(const int loops, const int playTime, const int fadeMs) const
{
    int channelNum;

    if (fadeMs > 0)
        channelNum = Mix_FadeInChannelTimed(-1, m_sound, loops, fadeMs, playTime);
    else
        channelNum = Mix_PlayChannelTimed(-1, m_sound, loops, playTime);

    if (channelNum == -1)
    {
        FATAL("Failed to play sound: " + std::string(Mix_GetError()))
        return;
    }

    Mix_Volume(channelNum, static_cast<int>(m_volume));
}

void Sound::setVolume(const float volume)
{
    m_volume = MIX_MAX_VOLUME * std::clamp(volume, 0.0f, 1.0f);
}

float Sound::getVolume() const { return m_volume / MIX_MAX_VOLUME; }

void Sound::unload() const
{
    if (m_sound)
        Mix_FreeChunk(m_sound);
}
} // namespace kn
