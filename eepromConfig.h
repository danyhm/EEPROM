#ifndef __EEPROMCONFIG_H
#define __EEPROMCONFIG_H

/*
References for further development:
https://github.com/whatcall/stm32f0-emulated-eeprom
https://github.com/nimaltd/EEPROM

@TODO check for compiler options to reserve the flash space.
@TODO Check for 16 bit Flash Writing
@TODO implement way to detect data being written on overlapping pages
*/
/*
Low Density 	  : From Page 0 to Page 31  , Page Size : 0x400 = 1024
Medium Density    : From Page 0 to Page 63  , Page Size : 0x400 = 1024
High Density 	  : From Page 0 to Page 127 , Page Size : 0x800 = 2048
*/

//  Use RTOS so be carefull not to interrupt in critical areas
#ifndef _USE_RTOS
#define _USE_RTOS 0
#endif

//	Valid Values:	M0 , M0P , M3 , M7
#define _CORTEX_	M0

//  Valid Values: LOW , MEDIUM , HIGH
#define _DENSITY_	LOW

#define     _EEPROM_PAGES_TO_USE					2			//The number of pages needed to be used (excluding the transfer page)
#define		_EEPROM_START_FLASH_PAGE				29
#define		_EEPROM_TRANSFER_PAGE					31		    //Should be last page of memory - this is the temp page for updating other pages without using RAM

/*################################################################################################################################*/
/*######################DO NOT EDIT ANYTHING BELOW THIS LINE UNLESS YOU KNOW WHAT YOU ARE DOING!!!!!!#############################*/
/*################################################################################################################################*/
#if(_EEPROM_PAGES_TO_USE+_EEPROM_START_FLASH_PAGE>_EEPROM_TRANSFER_PAGE)
	#error  "Transfer Page is overlapping Data Pages"
#endif
#if(_EEPROM_PAGES_TO_USE+_EEPROM_START_FLASH_PAGE!=_EEPROM_TRANSFER_PAGE)
	#warning  "Page Gap between User Data and Transfer Page"
#endif

/* Emulated data and virtual address bits */
#define EE_DATA_16BIT         16
#define EE_DATA_32BIT         32
#define EE_DATA_WIDTH 		 (uint32_t)EE_DATA_32BIT

//  Valid Values: 0x400 , 0x800 
#define		_EEPROM_FLASH_PAGE_SIZE  				(uint32_t)FLASH_PAGE_SIZE  /* Page size --> From HAL Library */ 

#define		_EEPROM_Num_VirtualAdd_IN_PAGE	((uint32_t)FLASH_PAGE_SIZE)/(EE_DATA_WIDTH/8)

//	Virtual Address points to uint32_t types of data so we divide it by 32bits=4byes
#define		_EEPROM_End_VirtualAddr	 (_EEPROM_FLASH_PAGE_SIZE/4)*_EEPROM_PAGES_TO_USE

/* Base address of the Flash sectors */
#define ADDR_FLASH_PAGE_0     ((uint32_t)0x08000000) /* Base @ of Page 0 */
#define _EEPROM_START_FLASH_PAGE_ADDRESS (uint32_t)(ADDR_FLASH_PAGE_0|(_EEPROM_FLASH_PAGE_SIZE*_EEPROM_START_FLASH_PAGE))
#define _EEPROM_TRANSFER_PAGE_ADDRESS    (uint32_t)(ADDR_FLASH_PAGE_0|(_EEPROM_FLASH_PAGE_SIZE*_EEPROM_TRANSFER_PAGE))

#if(_DENSITY_==LOW&&_EEPROM_USE_FLASH_PAGE>31)
	#error  "Please Enter currect value _EEPROM_USE_FLASH_PAGE  (0 to 31)"
#elseif(_DENSITY_==MEDIUM&&_EEPROM_USE_FLASH_PAGE>63)
	#error  "Please Enter currect value _EEPROM_USE_FLASH_PAGE  (0 to 63)"
#elseif(_DENSITY_==HIGH&&_EEPROM_USE_FLASH_PAGE>127)
	#error  "Please Enter currect value _EEPROM_USE_FLASH_PAGE  (0 to 127)"
#endif

#endif
