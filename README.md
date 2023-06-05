
### National University Of Litoral
### Technical Disegn and Programming Videogames 🕹️
# __Introduction to Programming__

| My repository of exercicies for signature Introduction to Programming.

### Construction 🛠️
In this subject We work with language C++ and a IDE [Zinjai](https://sourceforge.net/projects/zinjai/). Personally I work under a GNU/Linux environment only with a console and any text-editor. Sometimes I use a IDE for debug.
* [GNU/Linux OS](https://www.linuxmint.com) - LinuxMint
_This is enought to develop in C++ but if you want use any IDE or complex text processor... use it!_

## Execute 🚀
If you want execute any exercise, first compile the source code with the next command:

```$g++ -o my_exec_file path_to_source_file.cpp -Wall```

Help:

```g++ --help=warnings|common```
 
Parameters:
 * -o \<file>  _Place the output into <file>._
 * -Wall       _Enable most warning messages._

## Execute with additional libraries 🧁
Sometimes in the subject we work with additionals libraries to make more easy and enjoyable the learning programming.

Until this moment, we use Conio's library. This a old library for input/output streams console: (con)sole (i)nput (o)utput. It works for M$-DOS but in Linux-like systems It isn't exist a equivalent. Because conio.h provides simple and easy to use functions for programming learning, a lot of developers tried to migrate and clone it.

Some files includes conio.h, this is "conio.h" library in our subject. To compile the exercices files you need copy conio.h in you /usr/includes folder, for that you can use my installer (it's in /utils) o copy it manually.
Others files uses conio_am.h, It's a other Borland-style conio implementation but I think is better implementation than "the subject official library" because conio_am.h has more functions and file-documentation is good and It has developed with teaching idea in mind.

In other way, if you want to use similar functions on GNU/Linux you can  learns about ncurses library. It's a powerfull library to make UI in console or text-based user interfaces. You can use it in your code installing libncurses-dev from official repository in your distro.

Resources for conio and ncurses libraries:
 - [ncurses documentation](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
 - [conioAM](https://sourceforge.net/projects/coniohcloneturboccpp/)
 - ["official signature" conio.h](https://sourceforge.net/projects/conio4linux/)
 - [borland-style conio implementation for MinGW/Dev-C++](https://conio.sourceforge.net/)


 ## Notice ⚠️
This source codes are solutions for programming subject's exercices, be careful if you copy&paste. Maybe the code works but It isn't the best or It has a lot personal annotation.

Exits a lot of ways resolve a same problem. I don't care if You 've can resolve a better(good for you!) or I'm wrong with my coding way because I'm always learning in my career and life. I will better in next commit!

## Books & References 📖
 + Subject material reading for Introduction to Programming.

Check this sites maybe it can help you:

 + https://en.cppreference.com/w/
 + https://www.learncpp.com/
 + https://learn.microsoft.com/es-es/cpp/cpp/cpp-language-reference?view=msvc-170/
 + https://www.w3schools.com/cpp/default.asp/
 + http://www.delorie.com/djgpp/doc/libc/libc_toc.html


### To-Do:
_Roadmap in my development:_
+ Learn to about class in c++.
+ Learn to about assembler language.
+ Understand reading C++ Handbook References.
+ ~~Install Zinjai~~ 👉👈🙆🤷


## Autor ⌨️
_Development by:_ **Juan Alegría**

@copyright (c) 2023 May

---
¡Thanks! 😊 The time is life, don't waste it! ☮️