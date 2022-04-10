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

#ifndef FFMPEG_KIT_SESSION_H
#define FFMPEG_KIT_SESSION_H

#include "Log.h"
#include "LogCallback.h"
#include "LogRedirectionStrategy.h"
#include "ReturnCode.h"
#include "SessionState.h"
#include <time.h>

namespace com {

    namespace arthenica {

        namespace ffmpegkit {

            /**
             * <p>Common interface for all <code>FFmpegKit</code> sessions.
             */
            class Session {

                public:

                    /**
                     * Returns the session specific log callback.
                     *
                     * @return session specific log callback
                     */
                    virtual LogCallback getLogCallback() = 0;

                    /**
                     * Returns the session identifier.
                     *
                     * @return session identifier
                     */
                    virtual long getSessionId() = 0;

                    /**
                     * Returns session create time.
                     *
                     * @return session create time
                     */
                    virtual time_t getCreateTime() = 0;

                    /**
                     * Returns session start time.
                     *
                     * @return session start time
                     */
                    virtual time_t getStartTime() = 0;

                    /**
                     * Returns session end time.
                     *
                     * @return session end time
                     */
                    virtual time_t getEndTime() = 0;

                    /**
                     * Returns the time taken to execute this session.
                     *
                     * @return time taken to execute this session in milliseconds or zero (0) if the session is
                     * not over yet
                     */
                    virtual long getDuration() = 0;

                    /**
                     * Returns command arguments as an array.
                     *
                     * @return command arguments as an array
                     */
                    virtual char** getArguments() = 0;

                    /**
                     * Returns command arguments as a concatenated string.
                     *
                     * @return command arguments as a concatenated string
                     */
                    virtual const char* getCommand() = 0;

                    /**
                     * Returns all log entries generated for this session. If there are asynchronous
                     * messages that are not delivered yet, this method waits for them until the given timeout.
                     *
                     * @param waitTimeout wait timeout for asynchronous messages in milliseconds
                     * @return list of log entries generated for this session
                     */
                    virtual const char* getAllLogsWithTimeout(const int waitTimeout) = 0;

                    /**
                     * Returns all log entries generated for this session. If there are asynchronous
                     * messages that are not delivered yet, this method waits for them.
                     *
                     * @return list of log entries generated for this session
                     */
                    virtual Log[] getAllLogs() = 0;

                    /**
                     * Returns all log entries delivered for this session. Note that if there are asynchronous
                     * messages that are not delivered yet, this method will not wait for them and will return
                     * immediately.
                     *
                     * @return list of log entries received for this session
                     */
                    virtual Log[] getLogs() = 0;

                    /**
                     * Returns all log entries generated for this session as a concatenated string. If there are
                     * asynchronous messages that are not delivered yet, this method waits for them until
                     * the given timeout.
                     *
                     * @param waitTimeout wait timeout for asynchronous messages in milliseconds
                     * @return all log entries generated for this session as a concatenated string
                     */
                    virtual const char* getAllLogsAsStringWithTimeout(const int waitTimeout) = 0;

                    /**
                     * Returns all log entries generated for this session as a concatenated string. If there are
                     * asynchronous messages that are not delivered yet, this method waits for them.
                     *
                     * @return all log entries generated for this session as a concatenated string
                     */
                    virtual const char* getAllLogsAsString() = 0;

                    /**
                     * Returns all log entries delivered for this session as a concatenated string. Note that if
                     * there are asynchronous messages that are not delivered yet, this method will not wait
                     * for them and will return immediately.
                     *
                     * @return list of log entries received for this session
                     */
                    virtual const char* getLogsAsString() = 0;

                    /**
                     * Returns the log output generated while running the session.
                     *
                     * @return log output generated
                     */
                    virtual const char* getOutput() = 0;

                    /**
                     * Returns the state of the session.
                     *
                     * @return state of the session
                     */
                    virtual SessionState getState() = 0;

                    /**
                     * Returns the return code for this session. Note that return code is only set for sessions
                     * that end with SessionStateCompleted state. If a session is not started, still running or failed then
                     * this method returns nil.
                     *
                     * @return the return code for this session if the session has completed, nil if session is
                     * not started, still running or failed
                     */
                    virtual ReturnCode* getReturnCode() = 0;

                    /**
                     * Returns the stack trace of the exception received while executing this session.
                     * <p>
                     * The stack trace is only set for sessions that end with SessionStateFailed state. For sessions that has
                     * SessionStateCompleted state this method returns nil.
                     *
                     * @return stack trace of the exception received while executing this session, nil if session
                     * is not started, still running or completed
                     */
                    virtual const char* getFailStackTrace() = 0;

                    /**
                     * Returns session specific log redirection strategy.
                     *
                     * @return session specific log redirection strategy
                     */
                    virtual LogRedirectionStrategy getLogRedirectionStrategy() = 0;

                    /**
                     * Returns whether there are still asynchronous messages being transmitted for this
                     * session or not.
                     *
                     * @return true if there are still asynchronous messages being transmitted, false
                     * otherwise
                     */
                    virtual bool thereAreAsynchronousMessagesInTransmit() = 0;

                    /**
                     * Adds a new log entry for this session.
                     *
                     * It is invoked internally by <code>FFmpegKit</code> library methods. Must not be used by user
                     * applications.
                     *
                     * @param log log entry
                     */
                    virtual void addLog(const Log* log) = 0;

                    /**
                     * Starts running the session.
                     */
                    virtual void startRunning() = 0;

                    /**
                     * Completes running the session with the provided return code.
                     *
                     * @param returnCode return code of the execution
                     */
                    virtual void complete(const ReturnCode* returnCode) = 0;

                    /**
                     * Ends running the session with a failure.
                     *
                     * @param exception execution received
                     */
                    // void fail:(NSException*)exception;

                    /**
                     * Returns whether it is an <code>FFmpeg</code> session or not.
                     *
                     * @return true if it is an <code>FFmpeg</code> session, false otherwise
                     */
                    virtual bool isFFmpeg() = 0;

                    /**
                     * Returns whether it is an <code>FFprobe</code> session or not.
                     *
                     * @return true if it is an <code>FFprobe</code> session, false otherwise
                     */
                    virtual bool isFFprobe() = 0;

                    /**
                     * Returns whether it is a <code>MediaInformation</code> session or not.
                     *
                     * @return true if it is a <code>MediaInformation</code> session, false otherwise
                     */
                    virtual bool isMediaInformation() = 0;

                    /**
                     * Cancels running the session.
                     */
                    virtual void cancel() = 0;

            };

        }
    }
}

#endif // FFMPEG_KIT_SESSION_H
