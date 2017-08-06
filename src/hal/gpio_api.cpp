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
#include "gpio_api.h"

#include <Arduino.h>

namespace mbino {

    void gpio_init_in(gpio_t* obj, PinName pin, PinMode pull)
    {
        uint8_t port = digitalPinToPort(pin);
        uint8_t mask = digitalPinToBitMask(pin);
        port_init_in(obj, port, mask, pull);
    }

    void gpio_init_out(gpio_t* obj, PinName pin, bool value)
    {
        uint8_t port = digitalPinToPort(pin);
        uint8_t mask = digitalPinToBitMask(pin);
        port_init_out(obj, port, mask, value ? mask : 0);
    }

}