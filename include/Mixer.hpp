#pragma once

#include <string>

#include <SDL.h>
#include <SDL_mixer.h>

namespace kn
{
namespace mixer
{

/**
 * @brief A sound object.
 */
class Sound final
{
  public:
    /**
     * @brief Create a sound.
     *
     * @param fileDir The directory of the sound file.
     */
    explicit Sound(const std::string& fileDir);
    ~Sound()
    {
        if (sound)
            Mix_FreeChunk(sound);
    }

    /**
     * @brief Play the sound.
     *
     * @param loops The number of times to loop the sound.
     * @param playTime The number of milliseconds to play the sound for.
     * @param fadeMs The number of milliseconds to fade in.
     *
     * @warning ``fadeMS`` is currently not working.
     */
    void play(int loops = 0, int playTime = -1, int fadeMs = 0);

    /**
     * @brief Set the volume of the sound.
     *
     * @param volume The volume to set.
     */
    void setVolume(float volume);

    /**
     * @brief Free the sound from memory.
     */
    void unload();

  private:
    Mix_Chunk* sound = nullptr;
    float volume = MIX_MAX_VOLUME;
};

class Music final
{
};

} // namespace mixer
} // namespace kn