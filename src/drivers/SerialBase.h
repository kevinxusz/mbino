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
#ifndef MBINO_SERIAL_BASE_H
#define MBINO_SERIAL_BASE_H

#include "platform/platform.h"

#if defined(DEVICE_SERIAL) || defined(DOXYGEN_ONLY)

#include "hal/serial_api.h"
#include "platform/NonCopyable.h"

namespace mbino {

    class SerialBase : private NonCopyable<SerialBase> {
        serial_t _serial;

    public:

        enum Parity {
            None = ParityNone,
            Odd = ParityOdd,
            Even = ParityEven
        };

        void baud(int baudrate) {
            serial_baud(&_serial, baudrate);
        }

        void format(int bits = 8, Parity parity = SerialBase::None, int stop_bits = 1) {
            serial_format(&_serial, bits, (SerialParity)parity, stop_bits);
        }

        int readable() {
            return serial_readable(&_serial);
        }

        int writeable() {
            return serial_writable(&_serial);
        }

    protected:

        SerialBase(PinName tx, PinName rx, long baud) {
            serial_init(&_serial, tx, rx);
            serial_baud(&_serial, baud);
        }

        SerialBase(PinNameMonitorTX, PinNameMonitorRX, long baud) {
            serial_monitor_init(&_serial);
            serial_baud(&_serial, baud);
        }

        ~SerialBase() {
            // FIXME: serial_free(&_serial) not called in mbed?
        }

        int _base_getc() {
            return serial_getc(&_serial);
        }

        int _base_putc(int c) {
            serial_putc(&_serial, c);
            return c;
        }

        // mbino extension
        int _base_puts(const char* s) {
            serial_puts(&_serial, s);
            return 0;
        }
    };

}

#endif

#endif
