/*********************************************************************************************************************
* DAVE APP Name : GUI_SEGGERLIBRARY       APP Version: 4.1.8
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version<br>
 *
 * 2015-10-09:
 *     - Added RTOS macro check
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "gui_seggerlibrary.h"

/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/
#if (!USER_DEFINED_LCD && SPI_INTERFACE == 1)
const XMC_GPIO_CONFIG_t GUI_SEGGERLIBRARY_0_gpio_pin_config   =
{ 
  .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
  .output_level   = XMC_GPIO_OUTPUT_LEVEL_HIGH,
#if (UC_FAMILY == XMC4)
  .output_strength = XMC_GPIO_OUTPUT_STRENGTH_MEDIUM
#endif
}; 

const GUI_SEGGERLIBRARY_CONFIG_t GUI_SEGGERLIBRARY_0_config  = 
{
  .gpio = &GUI_SEGGERLIBRARY_0_gpio_pin_config,
  .portNo = (XMC_GPIO_PORT_t*)PORT5_BASE,
  .pinNo = 11
};
#endif
	
GUI_SEGGERLIBRARY_t GUI_SEGGERLIBRARY_0 =
{
#if (GUI_SEGGERLIBRARY_RTOS_PRESENT == 0)
  .systimer_handler   = &SYSTIMER_0,
#endif
#if (SPI_INTERFACE == 1)
  .spi_master_handler = &SPI_MASTER_0,
#endif
#if (!USER_DEFINED_LCD && SPI_INTERFACE == 1)
  .config = &GUI_SEGGERLIBRARY_0_config,
#endif
  .enable_at_init = true
};

