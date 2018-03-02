# Multipage EEPROM emulation for STM32
<br />
<br />
Based on EEPROM emulation of nimaltd. unlike his code this library uses a transfer page instead of RAM to change the contents of an unerased flash page.
<br />
PROs : it uses no RAM.
<br />
Cons : The transfer page will wear out pretty quick if too much data is changed.
<br />
this library is useful when the amount of data to be writen is very much but they are not going to be changed often.
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
<br />
TODO:
<br />
1- Add a preprocessor option to change between RAM transfer and page trasfer
<br />
2- Add compiler options in readme to preserve the flash space.
<br />
3- Inspect possible option to add functions to handle 16 bit flash writing.
<br />
4- implement a way to detect data being written in overlapping pages.
<br />
