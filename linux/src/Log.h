/*
 * Copyright (c) 2022 Taner Sener
 *
 * This file is part of FFmpegKit.
 *
 * FFmpegKit is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FFmpegKit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General License for more details.
 *
 *  You should have received a copy of the GNU Lesser General License
 *  along with FFmpegKit.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FFMPEG_KIT_LOG_H
#define FFMPEG_KIT_LOG_H

namespace com {

    namespace arthenica {

        namespace ffmpegkit {

            /**
             * <p>Log entry for an <code>FFmpegKit</code> session.
             */
            class Log {
                long _sessionId;
                int _level;
                const char* _message;

                public:
                    Log(const long sessionId, const int level, const char* message);
                    ~Log();
                    long getSessionId();
                    int getLevel();
                    const char* getMessage();
            };

        }

    }

}

#endif // FFMPEG_KIT_LOG_H
