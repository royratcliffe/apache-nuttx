/****************************************************************************
 * boards/arm/stm32h7/h747ai/src/stm32_spi.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <debug.h>

#include <arch/board/board.h>
#include <nuttx/spi/spi.h>
#include <nuttx/spi/spi_transfer.h>

#include "arm_internal.h"
#include "chip.h"
#include "stm32_spi.h"
#include "stm32_gpio.h"

#include "h747ai.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_spi1/2/3/4/5/6select and stm32_spi1/2/3/4/5/6status
 *
 * Description:
 *   The external functions, stm32_spi1/2/3/4/5/6select and
 *   stm32_spi1/2/3/4/5/6status must be provided by board-specific logic.
 *   They are implementations of the select and status methods of the SPI
 *   interface defined by struct spi_ops_s (see include/nuttx/spi/spi.h). All
 *   other methods (including stm32_spibus_initialize()) are provided by
 *   common STM32 logic. To use this common SPI logic on your board:
 *
 *   1. Provide logic in stm32_boardinitialize() to configure SPI chip select
 *      pins.
 *   2. Provide stm32_spi1/2/3/4/5/6select() and stm32_spi1/2/3/4/5/6status()
 *      functions in your board-specific logic.  These functions will perform
 *      chip selection and status operations using GPIOs in the way your
 *      board is configured.
 *   3. Add a calls to stm32_spibus_initialize() in your low level
 *      application initialization logic
 *   4. The handle returned by stm32_spibus_initialize() may then be used to
 *      bind the SPI driver to higher level logic (e.g., calling
 *      mmcsd_spislotinitialize(), for example, will bind the SPI driver to
 *      the SPI MMC/SD driver).
 *
 ****************************************************************************/

#ifdef CONFIG_STM32H7_SPI1
void stm32_spi1select(struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %d CS: %s\n",
         (int)devid, selected ? "assert" : "de-assert");

  stm32_gpiowrite(GPIO_SPI1_NSS, !selected);
}

uint8_t stm32_spi1status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_STM32H7_SPI2
void stm32_spi2select(struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %d CS: %s\n",
         (int)devid, selected ? "assert" : "de-assert");
}

uint8_t stm32_spi2status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_STM32H7_SPI3
void stm32_spi3select(struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %d CS: %s\n",
         (int)devid, selected ? "assert" : "de-assert");
}

uint8_t stm32_spi3status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_STM32H7_SPI4
void stm32_spi4select(struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %d CS: %s\n",
         (int)devid, selected ? "assert" : "de-assert");
}

uint8_t stm32_spi4status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_STM32H7_SPI5
void stm32_spi5select(struct spi_dev_s *dev, uint32_t devid,
                      bool selected)
{
  spiinfo("devid: %d CS: %s\n",
         (int)devid, selected ? "assert" : "de-assert");
}

uint8_t stm32_spi5status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

/****************************************************************************
 * Name: stm32_spi1/2/3/4/5cmddata
 *
 * Description:
 *   This function must be provided by platform-specific logic. This is an
 *   implementation of the cmddata method of the SPI interface defined by
 *   struct spi_ops_s (see include/nuttx/spi/spi.h).
 *
 * Input Parameters:
 *   spi   - SPI device that controls the bus the device that requires the
 *           CMD/DATA selection.
 *   devid - If there are multiple devices on the bus, this selects which one
 *           to select cmd or data.  NOTE:  This design restricts, for
 *           example, one SPI display per SPI bus.
 *   cmd   - true: select command; false: select data
 *
 * Returned Value:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_SPI_CMDDATA
#ifdef CONFIG_STM32H7_SPI1
int stm32_spi1cmddata(struct spi_dev_s *dev, uint32_t devid,
                      bool cmd)
{
  return -ENODEV;
}
#endif

#ifdef CONFIG_STM32H7_SPI2
int stm32_spi2cmddata(struct spi_dev_s *dev, uint32_t devid,
                      bool cmd)
{
  return -ENODEV;
}
#endif

#ifdef CONFIG_STM32H7_SPI3
int stm32_spi3cmddata(struct spi_dev_s *dev, uint32_t devid,
                      bool cmd)
{
  return -ENODEV;
}
#endif

#ifdef CONFIG_STM32H7_SPI4
int stm32_spi4cmddata(struct spi_dev_s *dev, uint32_t devid,
                      bool cmd)
{
  return -ENODEV;
}
#endif

#ifdef CONFIG_STM32H7_SPI5
int stm32_spi5cmddata(struct spi_dev_s *dev, uint32_t devid,
                      bool cmd)
{
  return -ENODEV;
}
#endif
#endif /* CONFIG_SPI_CMDDATA */
