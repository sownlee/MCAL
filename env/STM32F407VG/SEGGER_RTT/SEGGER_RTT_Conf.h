/*********************************************************************
*              SEGGER MICROCONTROLLER SYSTEME GmbH                   *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996-2014 SEGGER Microcontroller Systeme GmbH           *
*                                                                    *
* Internet: www.segger.com Support: support@segger.com               *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File    : SEGGER_RTT_Conf.h
Date    : 17 Dec 2014
Purpose : Implementation of SEGGER real-time terminal which allows
          real-time terminal communication on targets which support
          debugger memory accesses while the CPU is running.
---------------------------END-OF-HEADER------------------------------
*/

/*********************************************************************
*
*       Defines, configurable
*
**********************************************************************
*/

#define SEGGER_RTT_MAX_NUM_UP_BUFFERS             (2)
#define SEGGER_RTT_MAX_NUM_DOWN_BUFFERS           (2)

#define BUFFER_SIZE_UP                            (1024)
#define BUFFER_SIZE_DOWN                          (16)

#define SEGGER_RTT_PRINTF_BUFFER_SIZE             (64)

#define SEGGER_RTT_LOCK()
#define SEGGER_RTT_UNLOCK()

#define SEGGER_RTT_IN_RAM                         (0)

/*************************** End of file ****************************/
