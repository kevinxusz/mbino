/* mbino - basic mbed APIs for the Arduino platform
 * Copyright (c) 2017 Thomas Kemmer
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
#ifndef MBINO_HAL_DEVICE_H
#define MBINO_HAL_DEVICE_H

#if defined(ARDUINO_ARCH_AVR)
#include "targets/TARGET_ARDUINO_ARCH_AVR/device.h"
#elif defined(ARDUINO_ARCH_SAM)
#include "targets/TARGET_ARDUINO_ARCH_SAM/device.h"
#elif defined(ARDUINO_ARCH_SAMD)
#include "targets/TARGET_ARDUINO_ARCH_SAMD/device.h"
#else
#error "This library only supports boards with an AVR, SAM or SAMD processor."
#endif

#endif