/* mbino - basic mbed APIs for the Arduino platform
 * Copyright (c) 2017 Thomas Kemmer
 *
 * mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You
 * may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.  See the License for the specific language governing
 * permissions and limitations under the License.
 */
#ifndef MBINO_SERIAL_H
#define MBINO_SERIAL_H

#include "platform/platform.h"

#if defined(DEVICE_SERIAL) || defined(DOXYGEN_ONLY)

#include "drivers/SerialBase.h"
#include "platform/NonCopyable.h"
#include "platform/Stream.h"

namespace mbino {

    class Serial : public SerialBase, public Stream, private NonCopyable<Serial> {
    public:
        // mbino extension: change baud type to long
        Serial(PinName tx, PinName rx, long baud = 9600) : SerialBase(tx, rx, baud) {}

        bool readable() {
            return SerialBase::readable();
        }

        bool writable() {
            return SerialBase::writeable();
        }

        bool writeable() {
            return SerialBase::writeable();
        }

    protected:
        virtual int _getc() {
            return _base_getc();
        }

        virtual int _putc(int c) {
            return _base_putc(c);
        }

        /* mbino restriction: no lock methods
        virtual void lock();
        virtual void unlock();
        */
    };

}

#endif

#endif
