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
#ifndef MBINO_INTERRUPT_IN_H
#define MBINO_INTERRUPT_IN_H

#include "hal/gpio_api.h"
#include "hal/gpio_irq_api.h"
#include "platform/Callback.h"
#include "platform/NonCopyable.h"

namespace mbino {

    class InterruptIn : private NonCopyable<InterruptIn> {
        Callback<void()> _rise;
        Callback<void()> _fall;

    public:
        InterruptIn(PinName pin);
        virtual ~InterruptIn();

        int read() {
            return gpio_read(&gpio);
        }

        void rise(Callback<void()> func);

        void fall(Callback<void()> func);

        void mode(PinMode pull) {
            gpio_mode(&gpio, pull);
        }

        void enable_irq() {
            gpio_irq_enable(&gpio_irq);
        }

        void disable_irq() {
            gpio_irq_disable(&gpio_irq);
        }

        operator int() {
            return read();
        }

    protected:
        gpio_t gpio;
        gpio_irq_t gpio_irq;

    private:
        static void _irq_handler(intptr_t id);
    };

}

#endif