/************************************************************************************************
Copyright (c) <year>, <copyright holders>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "digital.h"
#include "chip.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */
struct digital_output_s {
    uint8_t port;
    uint8_t pin;
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
digital_output_t DigitalOutputCreate(uint8_t port, uint8_t pin) {
    static struct digital_output_s output;
    output.port = port;
    output.pin = pin;
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, output.port, output.pin, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, output.port, output.pin, true);

    return &output;
}

void DigitalOutputToggle(digital_output_t output) {

    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->port, output->pin);
}

/* === Public function implementation ========================================================== */

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */