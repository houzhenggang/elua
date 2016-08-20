/**
 * @file gui_seggerlibrary.h
 * @date 2015-10-09
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is
 * regenerated.
 */
/**
 * @cond
 ***********************************************************************************************************************
 * GUI_SEGGERLIBRARY v4.1.8 - Displays the text or graphics on OLED/LCD
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
 * 2015-05-18:
 *     - SYSTIMER_INIT_t* is changed to SYSTEMR_t*
 *
 * 2015-10-09:
 *     - Added RTOS macro check
 * @endcond
 *
 */

#ifndef GUI_SEGGERLIBRARY_H
#define GUI_SEGGERLIBRARY_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include <xmc_common.h>
#include <xmc_gpio.h>

#include "GUI.h"
#include "gui_seggerlibrary_conf.h"
#if (GUI_SEGGERLIBRARY_RTOS_PRESENT == 0)
#include "systimer.h"
#endif
#if (SPI_INTERFACE == 1)
#include "spi_master.h"
#endif
#include "DAVE_common.h"

/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/
#if (!((XMC_LIB_MAJOR_VERSION == 2U) && \
       (XMC_LIB_MINOR_VERSION >= 0U) && \
       (XMC_LIB_PATCH_VERSION >= 0U)))
#error "GUI_SEGGERLIBRARY requires XMC Peripheral Library v2.0.0 or higher"
#endif

/*********************************************************************************************************************
 * ENUMS
 ********************************************************************************************************************/

/**
 * @ingroup GUI_SEGGERLIBRARY_enumerations
 * @{
 */
/**
 * @brief enumeration status for GUI_SEGGERLIBRARY APP
 */
typedef enum GUI_SEGGERLIBRARY_STATUS
{
  GUI_SEGGERLIBRARY_STATUS_SUCCESS = 0U,      /**< APP initialization success */
  GUI_SEGGERLIBRARY_STATUS_FAILURE = 1U       /**< APP initialization failure */
} GUI_SEGGERLIBRARY_STATUS_t;
/**
 * @}
 */
/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/

/**
 * @ingroup GUI_SEGGERLIBRARY_datastructures
 * @{
 */
/**
 * @brief Configuration structure for GUI_SEGGERLIBRARY APP
 */
#if (!USER_DEFINED_LCD && SPI_INTERFACE == 1)
typedef struct GUI_SEGGERLIBRARY_CONFIG
{
  const XMC_GPIO_CONFIG_t *gpio;   				   /**< Basic IO configuration*/
  XMC_GPIO_PORT_t* portNo;	                       /**< Port number */
  uint8_t pinNo;                                   /**< Pin number */
} GUI_SEGGERLIBRARY_CONFIG_t;
#endif

typedef struct GUI_SEGGERLIBRARY
{
#if (GUI_SEGGERLIBRARY_RTOS_PRESENT == 0)
  SYSTIMER_t* systimer_handler;                   /**< pointer which is used to
                                                       hold SYSTIMER instance
                                                       handle */
#endif
#if (SPI_INTERFACE == 1)
   SPI_MASTER_t* const spi_master_handler;        /**< pointer which is used to
                                                       hold SPI_MASTER instance
                                                       handle */
#endif
#if (!USER_DEFINED_LCD && SPI_INTERFACE == 1)
  const GUI_SEGGERLIBRARY_CONFIG_t* const config;  /**< config pointer*/
#endif
  bool enable_at_init; 							   /**< Starts GUI_Init after
                                                        initialization */
} GUI_SEGGERLIBRARY_t;

/**
 * @}
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup GUI_SEGGERLIBRARY_apidoc
 * @{
 */
/**********************************************************************************************************************
 * API PROTOTYPES
***********************************************************************************************************************/
/**
 * @brief Get GUI_SEGGERLIBRARY APP version.
 * @return \a DAVE_APP_VERSION_t APP version information (major, minor and
 *                                                        patch number)
 *
 * \par<b>Description: </b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 *
 * @code
 * #include <DAVE.h>
 *
 *  int main(void)
 *  {
 *    DAVE_APP_VERSION_t version;
 *    DAVE_Init();
 *    version = GUI_SEGGERLIBRARY_GetAppVersion();
 *    if(version.major != 4U)
 *    {
 *    }
 *    return 0;
 *  }
 * @endcode<BR> </p>
 */
DAVE_APP_VERSION_t GUI_SEGGERLIBRARY_GetAppVersion(void);

/**
 * @brief Initializes GUI_SEGGERLIBRARY APP.
 * @param handle Pointer for the structure @ref GUI_SEGGERLIBRARY_t
 * @return @ref GUI_SEGGERLIBRARY_STATUS_t
 * @code
 * #include <DAVE.h>
 *  int main(void)
 *  {
 *    DAVE_Init();	// GUI_SEGGERLIBRARY(&GUI_SEGGERLIBRARY_0) is called
 *                  // inside DAVE_Init()
 *    return 0;
 *  }
 * @endcode<BR> </p>
 */

GUI_SEGGERLIBRARY_STATUS_t GUI_SEGGERLIBRARY_Init(GUI_SEGGERLIBRARY_t *handle);

/* Syncoam display with spi */
#if (!USER_DEFINED_LCD && SPI_INTERFACE == 1)

/**
 * @brief This routine writes to display controller using SPI bus, with A0 = 0
 * @param Cmd Command to be sent to the display driver.
 * @return void
 */
void GUI_SEGGERLIBRARY_WriteCmdByte(uint8_t cmd);

/**
 * @brief This routine Writes to display controller using SPI bus, with A0 = 1
 * @param Data Single byte of data to be displayed at the display driver.
 * @return void
 */
void GUI_SEGGERLIBRARY_WriteDataByte(uint8_t data);
/**
 * @brief This routine Writes to display controller using SPI bus, with A0 = 1
 * @param Data Multiple bytes of data to be displayed at the display driver.
 * @param NumItems Number of bytes to be displayed.
 * @return void
 */
void GUI_SEGGERLIBRARY_WriteMultipleBytes(uint8_t *data, int numitems);
/**
 * @brief This routine reads from display controller using SPI bus, with A0 = 1
 * @param Data Multiple bytes of data to be read from the display driver.
 * @param NumItems Number of bytes to be read.
 * @return void
 */
void GUI_SEGGERLIBRARY_ReadMultipleBytes(uint8_t *data, int numitems);
#endif

/* Other Display with 8-bit / Syncoam Display with 8-bit and no-spi*/
#if ((USER_DEFINED_LCD == 1 && DISPLAY_8BPP == 1) || \
     (USER_DEFINED_LCD == 0 && DISPLAY_8BPP == 1) && (SPI_INTERFACE == 0))
void User_LCD_8_WriteCmd(uint8_t cmd);
void User_LCD_8_WriteData(uint8_t data);
void User_LCD_8_WriteMultiple(uint8_t *dta, int count);
void User_LCD_8_Read(uint8_t *data, int count);
#endif

/* Other Display with 16-bit with or without spi */
#if ((USER_DEFINED_LCD == 1) && (DISPLAY_16BPP == 1))
void User_LCD_16_WriteCmd(uint16_t cmd);
void User_LCD_16_WriteData(uint16_t data);
void User_LCD_16_WriteMultiple(uint16_t *dta, int count);
void User_LCD_16_Read(uint16_t *data, int count);
#endif
#endif
/**
 * @}
 */

#include "gui_seggerlibrary_extern.h"

#ifdef __cplusplus
}
#endif

