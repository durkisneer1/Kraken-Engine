#pragma once

#include <SDL_mixer.h>
#include <string>

namespace kn
{
namespace music
{
/**
 * @brief Loads a music file.
 *
 * @param fileDir The directory of the music file.
 */
void load(const std::string& fileDir);

/**
 * @brief Unloads the currently loaded music file.
 */
void unload();

/**
 * @brief Plays the currently loaded music file.
 *
 * @param loops The number of times to loop the music. -1 loops forever.
 * @param fadeMs The number of milliseconds to fade in the music.
 */
void play(int loops = 0, int fadeMs = 0);

/**
 * @brief Rewinds the currently loaded music file back to the start.
 */
void rewind();

/**
 * @brief Stops the currently loaded music file.
 */
void stop();

/**
 * @brief Pauses the currently loaded music file.
 */
void pause();

/**
 * @brief Resumes the currently loaded music file.
 */
void resume();

/**
 * @brief Fades out the currently loaded music file to the a stop.
 *
 * @param fadeMs The number of milliseconds to fade out the music.
 */
void fadeOut(int fadeMs);

/**
 * @brief Sets the volume of the currently loaded music file.
 *
 * @param volume The volume to set the music to. 0.0f is silent, 1.0f is full volume.
 */
void setVolume(float volume);

/**
 * @brief Gets the volume of the currently loaded music file.
 *
 * @return The volume of the currently loaded music file.
 */
float getVolume();

} // namespace music
} // namespace kn