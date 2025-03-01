#pragma once

#include <SDL_mixer.h>
#include <string>

namespace kn
{
class Sound final
{
  public:
    /**
     * @brief Load a sound from an audio file.
     * Accepts .ogg, .mp3, and .wav files.
     *
     * @param fileDir The directory of the sound file.
     *
     * @note If the sound file fails to load, a `kn::Exception` will be thrown.
     */
    explicit Sound(const std::string& fileDir);
    Sound() = default;
    ~Sound();

    /**
     * @brief Load a sound from an audio file.
     * Accepts .ogg, .mp3, and .wav files.
     *
     * @param fileDir The directory of the sound file.
     *
     * @return ``true`` if the sound was loaded successfully, ``false`` otherwise.
     */
    [[maybe_unused]] bool loadFromFile(const std::string& fileDir);

    /**
     * @brief Play the sound.
     *
     * @param loops The number of times to loop the sound.
     * @param playTime The number of milliseconds to play the sound for.
     * @param fadeMs The number of milliseconds to fade in.
     *
     * @note If the loops parameter is set to ``-1``, the sound will loop indefinitely.
     */
    void play(int loops = 0, int playTime = -1, int fadeMs = 0) const;

    /**
     * @brief Set the volume of the sound.
     *
     * @param volume The volume to set.
     */
    void setVolume(float volume);

    /**
     * @brief Get the volume of the sound.
     *
     * @return The volume of the sound. Between ``0.0f`` and ``1.0f``.
     */
    [[nodiscard]] float getVolume() const;

  private:
    Mix_Chunk* m_sound = nullptr;
    float m_volume = MIX_MAX_VOLUME;
};
} // namespace kn
