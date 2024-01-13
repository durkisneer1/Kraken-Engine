#include <filesystem>
#include <algorithm>

#include "Mixer.hpp"
#include "ErrorLogger.hpp"

namespace kn
{
namespace mixer
{

Sound::Sound(const std::string& fileDir)
{   
    std::filesystem::path filePath(fileDir);
    std::string extension = filePath.extension().string();

    if (extension == ".ogg" || extension == ".mp3" || extension == ".wav") {
        sound = Mix_LoadWAV(fileDir.c_str());
        if (!sound)
            FATAL("Failed to load sound: " + fileDir);
    } else {
        FATAL("Unsupported file format: " + fileDir);
    }

    setVolume(0.8f);
}

void Sound::play(int loops, int maxMs, int fadeMs)
{   
    int channelNum = -1;

    if (fadeMs > 0)
        channelNum = Mix_FadeInChannelTimed(-1, sound, loops, maxMs, fadeMs);
    else
        channelNum = Mix_PlayChannelTimed(-1, sound, loops, maxMs);

    if (channelNum == -1)
    {
        FATAL("Failed to play sound: " + std::string(Mix_GetError()));
        return;
    }

    Mix_Volume(channelNum, volume);
    
}

void Sound::setVolume(float newVolume)
{
    volume = MIX_MAX_VOLUME * std::clamp(newVolume, 0.0f, 1.0f);
}

void Sound::unload()
{
    if (sound)
        Mix_FreeChunk(sound);
}

} // namespace mixer
} // namespace kn
