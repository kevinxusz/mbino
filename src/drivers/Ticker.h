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
#ifndef MBINO_TICKER_H
#define MBINO_TICKER_H

#include "drivers/TimerEvent.h"
#include "platform/Callback.h"
#include "platform/NonCopyable.h"

namespace mbino {

    class Ticker : public TimerEvent, private NonCopyable<Ticker> {
    public:

        Ticker() {}

        Ticker(const ticker_data_t *data) : TimerEvent(data) {}

        virtual ~Ticker() {
            detach();
        }

        // mbino extension: pass const reference to func
        void attach(const Callback<void()>& func, float t) {
            attach_us(func, t * 1000000.0f);
        }

        // mbino extension: pass const reference to func
        void attach_us(const Callback<void()>& func, us_timestamp_t t);

        void detach();

    protected:
        /* TODO: setup() support?
        void setup(us_timestamp_t t);
        */
        virtual void handler();

    protected:
        us_timestamp_t _delay;
        Callback<void()> _function;
    };

}

#endif
