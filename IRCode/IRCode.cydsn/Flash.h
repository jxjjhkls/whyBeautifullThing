#ifndef _FLASH_H_
#define _FLASH_H_


#define CY_TEST_SFLASH_ROW       (CY_SFLASH_NUMBER_USERROWS - 1u)

/* Defines absolute address of ROW */
#define CY_TEST_SFLASH_ADDR      (CY_SFLASH_USERBASE + CY_TEST_SFLASH_ROW * CY_SFLASH_SIZEOF_USERROW)

#endif
