# Multipage EEPROM emulation for STM32
<br />
<br />
Based on EEPROM emulation of nimaltd.
<br />
<br />
How to use :
<br />
1- Include the Files in your project.
<br />
2- Edit eepromConfig.h based on your needs.
<br />
3- include the correct HAL header in eeprom.h
<br />
4- your EEPROM variables will have a virtual address starting from 0 and ending at the size of your MCU page size / 4 * total number of pages in use (excluding transfer page).
<br />
<br />
WARNING !!
<br />
1- This code does not have flash wear level algorithm. you should be careful how much you write in a specific address. if you don't know what this is refer to ST document about EEPROM emulation and preferebly use that code.
<br />
2- Page trasfer is done automatically. if you need to fully erase a page , you should do it by it's PAGE Number not virtual Address !
