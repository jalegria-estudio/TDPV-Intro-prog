/**
 * Introducción a C++.
 * Practica Unidad 3.2 - Actividad 05
 * Consigna: Ingresar con el teclado las flechas de dirección, indicar si se presionó Derecha, Izquierda, Arriba o Abajo.
 * El ingreso debe finalizar cuando se presiona Q. Nota: Usar el código de ejemplo adjuntado en el Aula.
 * Fecha: 2023/06/01
 */

#include <iostream>
#include <conio.h>

using namespace std;

/**
 * KEYBOARD INPUT
 * The keyboard is used for several distinct types of input, including:
 *
 *
 *  Character input. Text that the user types into a document or edit box.
 *  Keyboard shortcuts. Key strokes that invoke application functions; for example, CTRL + O to open a file.
 *  System commands. Key strokes that invoke system functions; for example, ALT + TAB to switch windows.
 *  When thinking about keyboard input, it is important to remember that a key stroke is not the same as a character. For example, pressing the A key could result in any of the following characters.
 *    a
 *    A
 *    á (if the keyboard supports combining diacritics)
 *
 *  Further, if the ALT key is held down, pressing the A key produces ALT+A, which the system does not treat as a character at all, but rather as a system command.
 *  Key Codes:
 *       When you press a key, the hardware generates a scan code. Scan codes vary from one keyboard to the next, and there are separate scan codes for key-up and key-down events. You will almost never care about scan codes. The keyboard driver translates scan codes into virtual-key codes. Virtual-key codes are device-independent. Pressing the A key on any keyboard generates the same virtual-key code.
 *       In general, virtual-key codes do not correspond to ASCII codes or any other character-encoding standard. This is obvious if you think about it, because the same key can generate different characters (a, A, á), and some keys, such as function keys, do not correspond to any character.
 *       That said, the following virtual-key codes do map to ASCII equivalents:
 *           0 through 9 keys = ASCII '0' – '9' (0x30 – 0x39)
 *           A through Z keys = ASCII 'A' – 'Z' (0x41 – 0x5A)
 *  In some respects this mapping is unfortunate, because you should never think of virtual-key codes as characters, for the reasons discussed.
 *  The header file WinUser.h defines constants for most of the virtual-key codes. For example, the virtual-key code for the LEFT ARROW key is VK_LEFT (0x25). For the complete list of virtual-key codes, see Virtual-Key Codes. No constants are defined for the virtual-key codes that match ASCII values. For example, the virtual-key code for the A key is 0x41, but there is no constant named VK_A. Instead, just use the numeric value.
 * 
 *  Source:https://learn.microsoft.com/en-us/windows/win32/learnwin32/keyboard-input
*/

/**
 *  kbhit
 *  Syntax:
 *      #include <pc.h>
 *  
 *      int kbhit(void);
 *  
 *  Description
 *      If the user has hit a key, this function will detect it. This function is very fast when there is no key waiting, so it may be used inside loops as needed.
 *      If you test shift/alt/ctrl status with bios calls (e.g., using bioskey (2) or bioskey (0x12)) then you should also use bios calls for testing for keys. This can be done with by bioskey (1) or bioskey (0x11). Failing to do so can cause trouble in multitasking environments like DESQview/X.
 *  
 *  Return Value
 *      Nonzero if a key has been hit, else zero.
 *  
 *  Portability
 *      ANSI/ISO C 	No
 *      POSIX 	No
 * 
 *  Source: http://www.delorie.com/djgpp/doc/libc/libc_518.html
*/

/**
 * Cursor Positioning
 *    The following tables encompass Control Sequence Introducer (CSI) type sequences. 
 *    All CSI sequences start with ESC (0x1B) followed by [ (left bracket, 0x5B) and may contain parameters of variable length to specify more information for each operation. This will be represented by the shorthand <n>. Each table below is grouped by functionality with notes below each table explaining how the group works.
 *    For all parameters, the following rules apply unless otherwise noted:
 *        <n> represents the distance to move and is an optional parameter
 *        If <n> is omitted or equals 0, it will be treated as a 1
 *        <n> cannot be larger than 32,767 (maximum short value)
 *        <n> cannot be negative
 *
 *    vt sequences:
 *    <esc>[1~    - Home        <esc>[16~   -             <esc>[31~   - F17
 *    <esc>[2~    - Insert      <esc>[17~   - F6          <esc>[32~   - F18
 *    <esc>[3~    - Delete      <esc>[18~   - F7          <esc>[33~   - F19
 *    <esc>[4~    - End         <esc>[19~   - F8          <esc>[34~   - F20
 *    <esc>[5~    - PgUp        <esc>[20~   - F9          <esc>[35~   - 
 *    <esc>[6~    - PgDn        <esc>[21~   - F10         
 *    <esc>[7~    - Home        <esc>[22~   -             
 *    <esc>[8~    - End         <esc>[23~   - F11         
 *    <esc>[9~    -             <esc>[24~   - F12         
 *    <esc>[10~   - F0          <esc>[25~   - F13         
 *    <esc>[11~   - F1          <esc>[26~   - F14         
 *    <esc>[12~   - F2          <esc>[27~   -             
 *    <esc>[13~   - F3          <esc>[28~   - F15         
 *    <esc>[14~   - F4          <esc>[29~   - F16         
 *    <esc>[15~   - F5          <esc>[30~   -
 *
 *    xterm sequences:
 *    <esc>[A     - Up          <esc>[K     -             <esc>[U     -
 *    <esc>[B     - Down        <esc>[L     -             <esc>[V     -
 *    <esc>[C     - Right       <esc>[M     -             <esc>[W     -
 *    <esc>[D     - Left        <esc>[N     -             <esc>[X     -
 *    <esc>[E     -             <esc>[O     -             <esc>[Y     -
 *    <esc>[F     - End         <esc>[1P    - F1          <esc>[Z     -
 *    <esc>[G     - Keypad 5    <esc>[1Q    - F2       
 *    <esc>[H     - Home        <esc>[1R    - F3       
 *    <esc>[I     -             <esc>[1S    - F4       
 *    <esc>[J     -             <esc>[T     - 
 *
 *    Source: 
 *        https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
 *        https://en.wikipedia.org/wiki/ANSI_escape_code
 */

const string KEY_UP =    {0x1b, 0x5b, 0x41}; //Equivalente a: "\e[A" o {27,91,65}
const string KEY_DOWN =  {0x1b, 0x5b, 0x42};
const string KEY_RIGHT = {0x1b, 0x5b, 0x43};
const string KEY_LEFT =  {0x1b, 0x5b, 0x44};

int main()
{
    cout<<"Press keyboard arrows, press \'q\' to exit."<<endl;
    string specialKey;

    while(specialKey != "q"){
        if(kbhit()){
            specialKey = "";
            
            while(kbhit()){
                char key = getchar();
                //printf("INT: %i CHAR: %c HEX:%x\n", key, key, key); //DEBUG
                specialKey += key;
            }

            //cout<<"Size Special Key:"<<size(specialKey)<<endl; //DEBUG

            if(size(specialKey) == 3 and specialKey[0] == '\e' and specialKey[1] == '['){
                switch ( specialKey[2]){
                    case 0x41:
                        cout<<"Pressed key-UP"<<endl;
                        break;
                    case 0x42:
                        cout<<"Pressed key-DOWN"<<endl;
                        break;
                    case 0x43:
                        cout<<"Pressed key-RIGHT"<<endl;
                        break;
                    case 0x44:
                        cout<<"Pressed key-LEFT"<<endl;
                        break;
                }
            }
        }
    }

    return 0;
}