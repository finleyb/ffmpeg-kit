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

#ifndef FFMPEG_KIT_ABSTRACT_SESSION_H
#define FFMPEG_KIT_ABSTRACT_SESSION_H

#include "Session.h"

namespace com {

    namespace arthenica {

        namespace ffmpegkit {

            /**
             * Defines how long default "getAll" methods wait, in milliseconds.
             */
            extern int const AbstractSessionDefaultTimeoutForAsynchronousMessagesInTransmit;

            /**
             * Abstract session implementation which includes common features shared by <code>FFmpeg</code>,
             * <code>FFprobe</code> and <code>MediaInformation</code> sessions.
             */
            class AbstractSession {
                static AtomicLong *sessionIdGenerator = NULL;
                long _sessionId;
                LogCallback _logCallback;
                time_t _createTime;
                time_t _startTime;
                time_t _endTime;
                char** _arguments;
                Log[] _logs;
                pthread_mutex_t _logsLock;
                SessionState _state;
                ReturnCode* _returnCode;
                char* _failStackTrace;
                LogRedirectionStrategy _logRedirectionStrategy;

                public:

                    /**
                     * Creates a new abstract session.
                     *
                     * @param arguments              command arguments
                     * @param logCallback            session specific log callback
                     * @param logRedirectionStrategy session specific log redirection strategy
                     */
                    AbstractSession(const char** arguments, const LogCallback logCallback, const LogRedirectionStrategy logRedirectionStrategy);

                    /**
                     * Destructor for a session.
                     */
                    ~AbstractSession();

                    /**
                     * Waits for all asynchronous messages to be transmitted until the given timeout.
                     *
                     * @param timeout wait timeout in milliseconds
                     */
                    void waitForAsynchronousMessagesInTransmit(const int timeout) override;
            };

        }
    }
}

#endif // FFMPEG_KIT_ABSTRACT_SESSION_H
