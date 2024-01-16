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
        if (m_sound)
            Mix_FreeChunk(m_sound);
    }

    /**
     * @brief Play the sound.
     *
     * @param loops The number of times to loop the sound.
     * @param playTime The number of milliseconds to play the sound for.
     * @param fadeMs The number of milliseconds to fade in.
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
    Mix_Chunk* m_sound = nullptr;
    float m_volume = MIX_MAX_VOLUME;
};

/**
 * @brief A music object.
 *
 * @warning This class is planned to become a singleton.
 */
class Music final
{
  public:
    /**
     * @brief Create a music object.
     *
     * @param fileDir The directory of the music file.
     */
    explicit Music(const std::string& fileDir);
    ~Music() { unload(); }

    /**
     * @brief Set the volume of the music.
     *
     * @param volume The volume to set.
     */
    void setVolume(float volume);

    /**
     * @brief Play the music.
     *
     * @param loops The number of times to loop the music.
     * @param fadeMs The number of milliseconds to fade in.
     */
    void play(int loops = 0, int fadeMs = 0);

    /**
     * @brief Pause the music.
     *
     * @param fadeMs The number of milliseconds to fade out.
     */
    void pause(int fadeMs = 0);

    /**
     * @brief Resume the music.
     */
    void resume();

    /**
     * @brief Load a music file.
     *
     * @param fileDir The directory of the music file.
     */
    void load(const std::string& fileDir);

    /**
     * @brief Free the music from memory.
     */
    void unload();

  private:
    Mix_Music* m_music = nullptr;
};

} // namespace mixer
} // namespace kn