#pragma once

#include <string>

namespace kn::music
{
/**
 * @brief Loads an audio file.
 *
 * @param fileDir The directory of the audio file.
 */
void load(const std::string& fileDir);

/**
 * @brief Unloads the currently loaded audio file.
 */
void unload();

/**
 * @brief Plays the currently loaded audio file.
 *
 * @param loops The number of times to loop the music. ``-1`` loops forever.
 * @param fadeMs The number of milliseconds to fade in the music.
 */
void play(int loops = 0, int fadeMs = 0);

/**
 * @brief Rewinds the music back to the start.
 */
void rewind();

/**
 * @brief Stops the music.
 */
void stop();

/**
 * @brief Pauses the music.
 */
void pause();

/**
 * @brief Resumes the music.
 */
void resume();

/**
 * @brief Fades out the music to a stop.
 *
 * @param fadeMs The number of milliseconds to fade out the music.
 */
void fadeOut(int fadeMs);

/**
 * @brief Sets the volume of the music.
 *
 * @param volume The volume to set the music to. ``0.0f`` is silent, ``1.0f`` is full volume.
 */
void setVolume(float volume);

/**
 * @brief Gets the volume of the music.
 *
 * @return The volume of the music.
 */
float getVolume();
} // namespace kn::music
