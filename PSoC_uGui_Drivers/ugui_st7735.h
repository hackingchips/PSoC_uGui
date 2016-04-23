/*******************************************************************************
* File Name: ugui_st7735.h  
*
* Description:
*  This is a driver for the uGui graphical library developed by 
*  Achim Döbler.
*  It is for ST7735 graphic controller found in a lot of low cost graphics 
*  chinese displays an to be used with PSoC microcontrollers from Cypress.
*  At the time of writting this, developing and testing with PSoC 4 micros.
*  Will test it with other PSoC micros as soon as i can.
*
* Note:
*  For more information about uGui...
*  Website: http://www.embeddedlightning.com/ugui/
*  Git: https://github.com/achimdoebler/UGUI
*  Forum: http://www.embeddedlightning.com/forum/
*  PDF Reference manual (excellent): http://www.embeddedlightning.com/download/reference-guide/?wpdmdl=205
*
*  Thanks to Achim Döbler for such a god job.
*
* Log version:
*  1.0 - April, 2016.       First version.
*
********************************************************************************
* Copyright (c) 2015 Jesús Rodríguez Cacabelos
* This driver follows the same license than the uGui library.
* http:
*******************************************************************************/

#if !defined(PSOC_UGUI_ST7735_H)
#define PSOC_UGUI_ST7735_H

#include "..\PSoC_uGui_Library\ugui.h"
    
/* *** Configuration. *** */

    /* Select SPI mode used. SCB mode or UDB based. Uncomment used mode and comment the other. */
#define USING_SPI_SCB
//#define USING_SPI_UDB
    /* Put here the same name of the SPI bus module you have used in schematic. */
#define SPI_NAME                SPI 
    /* Set here the name you have given to display CD and RESET signals in your schematic. */
#define DISPLAY_RESET           DISP_RESET
#define DISPLAY_CD              DISP_CD
    
    /* Set here your display resolution. */
#define DISPLAY_WIDTH       128
#define DISPLAY_HEIGHT      160
    
/* *** Configuration <END>. *** */
    
    /* Text substitution macros to avoid changing function names related to SPI API
       if SPI module name is changed in schematic. */

#define CONCATENATE(name, function)                 CONCAT(name, function)
#define CONCAT(name, function)                      name##function

#if (CY_PSOC4)

    #if defined USING_SPI_SCB
        #define mmSPI_SpiUartPutArray(a, b)                 CONCATENATE(SPI_NAME, _SpiUartPutArray(a, b)) 
        #define mmSPI_SpiUartWriteTxData(value)             CONCATENATE(SPI_NAME, _SpiUartWriteTxData(value))
        #define mmSPI_SpiUartGetTxBufferSize()              CONCATENATE(SPI_NAME, _SpiUartGetTxBufferSize())
    #endif
    
    #if defined USING_SPI_UDB
        #define mmSPI_SpiUartPutArray(a, b)                 CONCATENATE(SPI_NAME, _PutArray(a, b)) 
        #define mmSPI_SpiUartWriteTxData(value)             CONCATENATE(SPI_NAME, _WriteTxData(value))
        #define mmSPI_SpiUartGetTxBufferSize()              CONCATENATE(SPI_NAME, _GetTxBufferSize())
    #endif
    
#endif    

#if (CY_PSOC5LP) 
    #define mmSPI_SpiUartClearTxBuffer                  CONCATENATE(SPI_NAME, _ClearTxBuffer)
    #define mmSPI_SpiUartClearRxBuffer                  CONCATENATE(SPI_NAME, _ClearRxBuffer)    
    #define mmSPI_SpiUartPutArray(a, b)                 CONCATENATE(SPI_NAME, _PutArray(a, b)) 
    #define mmSPI_SpiUartWriteTxData(value)             CONCATENATE(SPI_NAME, _WriteTxData(value))
    #define mmSPI_SpiUartReadRxData                     CONCATENATE(SPI_NAME, _ReadRxData)
    #define mmSPI_GetMasterInterruptSource              CONCATENATE(SPI_NAME, _GetMasterInterruptSource)
    #define mmSPI_ClearMasterInterruptSource(value)     CONCATENATE(SPI_NAME, _ClearMasterInterruptSource(value)) 
    #define mmSPI_INTR_MASTER_SPI_DONE                  CONCATENATE(SPI_NAME, _INTR_MASTER_SPI_DONE)    
#endif 

#define mmDisplayReset_Write(value) CONCATENATE(DISPLAY_RESET, _Write(value))
#define mmDisplayCD_Write(value)    CONCATENATE(DISPLAY_CD, _Write(value))
    
/* *** Glogal GUI structure for this. *** */
UG_GUI gui7735;

/* *** Function prototypes. *** */
void Display_Init();
void Display_PSet(UG_S16 x, UG_S16 y, UG_COLOR c);

    // Accelerators.
UG_RESULT HW_FillFrame (UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c);
UG_RESULT HW_FillArea(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR c);

#endif /* End PSOC_UGUI_ST7735_H */    

/* [] END OF FILE */

