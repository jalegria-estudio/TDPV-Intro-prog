#!/usr/bin/sh

# SHELL SCRIPT TO INSTALL CONIO4LINUX.
# Copyright (C) 2023 by Juan P. Alegria.
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
# You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 

# @author Juan P. Alegria.
# @date 2023-06-01.

#REQUIRE PACKAGES: c++ compiler and wget. You can install them from your distro's repository.

# HOW TO INSTALL CONIO:
# $ chmod 764 installer_conio.sh
# $ ./installer_conio.sh

# HOW TO UNINSTALL CONIO:
# $ sudo rm -v /usr/include/conio.h

#WHAT DOES IT DO IN THE SHADOWS?: It just only downloads conio.h (v0.3) from repository and moves that file to /usr/include folder. It changes file permissions to a more secure mode. Then itself creates, executes and deletes a testing program for conio library.

wget https://downloads.sourceforge.net/project/conio4linux/0.3/conio.h
sudo mv ./conio.h /usr/include/
sudo chmod 644 /usr/include/conio.h
touch testconio.cpp 
echo '#include<conio.h>
int main(int argc, char *argv[]){
  textcolor(CYAN);
  cprintf("TESTING CONIO4LINUX.\\n");
  textcolor(LIGHTBLUE);
  cprintf("If you can read this text and look colors in hello-world sentences is because Conio s Library was installed successfully!\\n");
  textcolor(LIGHTGREEN);
  cprintf("Press enter to continue...");
  getch();
  textbackground(BLUE);
  clrscr();  
  textcolor(WHITE);
  gotoxy(30,5);
  cprintf("Hello World WHITE");
  textcolor(YELLOW);
  gotoxy(30,6);
  cprintf("Hello World YELLOW");    
  for(int i=0;i<16;i++){
    textcolor(i);
    gotoxy(1,2+i);
    cprintf("Hello World"); 
  }
  cprintf("\\nPRESS ANY KEY TO EXIT!\\n");
  getch();
  return 0;
  }
' >> testconio.cpp

g++ testconio.cpp -o testconio.app -Wall

if [ $? -eq 0 ]
then
    ./testconio.app
    rm ./testconio.app
    rm ./testconio.cpp
else
    echo "SOMETHING WAS WRONG!";
fi