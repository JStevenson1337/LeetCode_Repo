window\["GUARDIO\_SENSOR\_CONF"\] = {"click":true} NCURSES Programming HOWTO 

NCURSES Programming HOWTO
=========================

### Pradeep Padala

<[ppadala@gmail.com](mailto:ppadala@gmail.com)\>

v1.9, 2005-06-20  

**Revision History**

Revision 1.9

2005-06-20

Revised by: ppadala

The license has been changed to the MIT-style license used by NCURSES. Note that the programs are also re-licensed under this.

Revision 1.8

2005-06-17

Revised by: ppadala

Lots of updates. Added references and perl examples. Changes to examples. Many grammatical and stylistic changes to the content. Changes to NCURSES history.

Revision 1.7.1

2002-06-25

Revised by: ppadala

Added a README file for building and instructions for building from source.

Revision 1.7

2002-06-25

Revised by: ppadala

Added "Other formats" section and made a lot of fancy changes to the programs. Inlining of programs is gone.

Revision 1.6.1

2002-02-24

Revised by: ppadala

Removed the old Changelog section, cleaned the makefiles

Revision 1.6

2002-02-16

Revised by: ppadala

Corrected a lot of spelling mistakes, added ACS variables section

Revision 1.5

2002-01-05

Revised by: ppadala

Changed structure to present proper TOC

Revision 1.3.1

2001-07-26

Revised by: ppadala

Corrected maintainers paragraph, Corrected stable release number

Revision 1.3

2001-07-24

Revised by: ppadala

Added copyright notices to main document (LDP license) and programs (GPL), Corrected printw\_example.

Revision 1.2

2001-06-05

Revised by: ppadala

Incorporated ravi's changes. Mainly to introduction, menu, form, justforfun sections

Revision 1.1

2001-05-22

Revised by: ppadala

Added "a word about window" section, Added scanw\_example.

_This document is intended to be an "All in One" guide for programming with ncurses and its sister libraries. We graduate from a simple "Hello World" program to more complex form manipulation. No prior experience in ncurses is assumed. Send comments to [this address](mailto:ppadala@gmail.com)_

* * *

**Table of Contents**

1\. [Introduction](#INTRO)

1.1. [What is NCURSES?](#WHATIS)

1.2. [What we can do with NCURSES](#WHATCANWEDO)

1.3. [Where to get it](#WHERETOGETIT)

1.4. [Purpose/Scope of the document](#PURPOSE)

1.5. [About the Programs](#ABOUTPROGRAMS)

1.6. [Other Formats of the document](#OTHERFORMATS)

1.7. [Credits](#CREDITS)

1.8. [Wish List](#WISHLIST)

1.9. [Copyright](#COPYRIGHT)

2\. [Hello World !!!](#HELLOWORLD)

2.1. [Compiling With the NCURSES Library](#COMPILECURSES)

2.2. [Dissection](#DISSECTION)

3\. [The Gory Details](#GORY)

4\. [Initialization](#INIT)

4.1. [Initialization functions](#ABOUTINIT)

4.2. [raw() and cbreak()](#RAWCBREAK)

4.3. [echo() and noecho()](#ECHONOECHO)

4.4. [keypad()](#KEYPAD)

4.5. [halfdelay()](#HALFDELAY)

4.6. [Miscellaneous Initialization functions](#MISCINIT)

4.7. [An Example](#INITEX)

5\. [A Word about Windows](#AWORDWINDOWS)

6\. [Output functions](#PRINTW)

6.1. [addch() class of functions](#ADDCHCLASS)

6.2. [mvaddch(), waddch() and mvwaddch()](#AEN298)

6.3. [printw() class of functions](#PRINTWCLASS)

6.4. [addstr() class of functions](#ADDSTRCLASS)

6.5. [A word of caution](#ACAUTION)

7\. [Input functions](#SCANW)

7.1. [getch() class of functions](#GETCHCLASS)

7.2. [scanw() class of functions](#SCANWCLASS)

7.3. [getstr() class of functions](#GETSTRCLASS)

7.4. [Some examples](#GETSTREX)

8\. [Attributes](#ATTRIB)

8.1. [The details](#ATTRIBDETAILS)

8.2. [attron() vs attrset()](#ATTRONVSATTRSET)

8.3. [attr\_get()](#ATTR_GET)

8.4. [attr\_ functions](#ATTR_FUNCS)

8.5. [wattr functions](#WATTRFUNCS)

8.6. [chgat() functions](#CHGAT)

9\. [Windows](#WINDOWS)

9.1. [The basics](#WINDOWBASICS)

9.2. [Let there be a Window !!!](#LETBEWINDOW)

9.3. [Explanation](#BORDEREXEXPL)

9.4. [The other stuff in the example](#OTHERSTUFF)

9.5. [Other Border functions](#OTHERBORDERFUNCS)

10\. [Colors](#COLOR)

10.1. [The basics](#COLORBASICS)

10.2. [Changing Color Definitions](#CHANGECOLORDEFS)

10.3. [Color Content](#COLORCONTENT)

11\. [Interfacing with the key board](#KEYS)

11.1. [The Basics](#KEYSBASICS)

11.2. [A Simple Key Usage example](#SIMPLEKEYEX)

12\. [Interfacing with the mouse](#MOUSE)

12.1. [The Basics](#MOUSEBASICS)

12.2. [Getting the events](#GETTINGEVENTS)

12.3. [Putting it all Together](#MOUSETOGETHER)

12.4. [Miscellaneous Functions](#MISCMOUSEFUNCS)

13\. [Screen Manipulation](#SCREEN)

13.1. [getyx() functions](#GETYX)

13.2. [Screen Dumping](#SCREENDUMP)

13.3. [Window Dumping](#WINDOWDUMP)

14\. [Miscellaneous features](#MISC)

14.1. [curs\_set()](#CURSSET)

14.2. [Temporarily Leaving Curses mode](#TEMPLEAVE)

14.3. [ACS\_ variables](#ACSVARS)

15\. [Other libraries](#OTHERLIB)

16\. [Panel Library](#PANELS)

16.1. [The Basics](#PANELBASICS)

16.2. [Compiling With the Panels Library](#COMPILEPANELS)

16.3. [Panel Window Browsing](#PANELBROWSING)

16.4. [Using User Pointers](#USERPTRUSING)

16.5. [Moving and Resizing Panels](#PANELMOVERESIZE)

16.6. [Hiding and Showing Panels](#PANELSHOWHIDE)

16.7. [panel\_above() and panel\_below() Functions](#PANELABOVE)

17\. [Menus Library](#MENUS)

17.1. [The Basics](#MENUBASICS)

17.2. [Compiling With the Menu Library](#COMPILEMENUS)

17.3. [Menu Driver: The work horse of the menu system](#MENUDRIVER)

17.4. [Menu Windows](#MENUWINDOWS)

17.5. [Scrolling Menus](#SCROLLMENUS)

17.6. [Multi Columnar Menus](#MULTICOLUMN)

17.7. [Multi Valued Menus](#MULTIVALUEMENUS)

17.8. [Menu Options](#MENUOPT)

17.9. [The useful User Pointer](#MENUUSERPTR)

18\. [Forms Library](#FORMS)

18.1. [The Basics](#FORMBASICS)

18.2. [Compiling With the Forms Library](#COMPILEFORMS)

18.3. [Playing with Fields](#PLAYFIELDS)

18.4. [Form Windows](#FORMWINDOWS)

18.5. [Field Validation](#FILEDVALIDATE)

18.6. [Form Driver: The work horse of the forms system](#FORMDRIVER)

19\. [Tools and Widget Libraries](#TOOLS)

19.1. [CDK (Curses Development Kit)](#CDK)

19.2. [The dialog](#DIALOG)

19.3. [Perl Curses Modules CURSES::FORM and CURSES::WIDGETS](#PERLCURSES)

20\. [Just For Fun !!!](#JUSTFORFUN)

20.1. [The Game of Life](#GAMEOFLIFE)

20.2. [Magic Square](#MAGIC)

20.3. [Towers of Hanoi](#HANOI)

20.4. [Queens Puzzle](#QUEENS)

20.5. [Shuffle](#SHUFFLE)

20.6. [Typing Tutor](#TT)

21\. [References](#REF)

1\. Introduction
================

In the olden days of teletype terminals, terminals were away from computers and were connected to them through serial cables. The terminals could be configured by sending a series of bytes. All the capabilities (such as moving the cursor to a new location, erasing part of the screen, scrolling the screen, changing modes etc.) of terminals could be accessed through these series of bytes. These control seeuqnces are usually called escape sequences, because they start with an escape(0x1B) character. Even today, with proper emulation, we can send escape sequences to the emulator and achieve the same effect on a terminal window.

Suppose you wanted to print a line in color. Try typing this on your console.

echo "^\[\[0;31;40mIn Color"

The first character is an escape character, which looks like two characters ^ and \[. To be able to print it, you have to press CTRL+V and then the ESC key. All the others are normal printable characters. You should be able to see the string "In Color" in red. It stays that way and to revert back to the original mode type this.

echo "^\[\[0;37;40m"

Now, what do these magic characters mean? Difficult to comprehend? They might even be different for different terminals. So the designers of UNIX invented a mechanism named termcap. It is a file that lists all the capabilities of a particular terminal, along with the escape sequences needed to achieve a particular effect. In the later years, this was replaced by terminfo. Without delving too much into details, this mechanism allows application programs to query the terminfo database and obtain the control characters to be sent to a terminal or terminal emulator.

* * *

1.1. What is NCURSES?
---------------------

You might be wondering, what the import of all this technical gibberish is. In the above scenario, every application program is supposed to query the terminfo and perform the necessary stuff (sending control characters etc.). It soon became difficult to manage this complexity and this gave birth to 'CURSES'. Curses is a pun on the name "cursor optimization". The Curses library forms a wrapper over working with raw terminal codes, and provides highly flexible and efficient API (Application Programming Interface). It provides functions to move the cursor, create windows, produce colors, play with mouse etc. The application programs need not worry about the underlying terminal capabilities.

So what is NCURSES? NCURSES is a clone of the original System V Release 4.0 (SVr4) curses. It is a freely distributable library, fully compatible with older version of curses. In short, it is a library of functions that manages an application's display on character-cell terminals. In the remainder of the document, the terms curses and ncurses are used interchangeably.

A detailed history of NCURSES can be found in the NEWS file from the source distribution. The current package is maintained by [Thomas Dickey](mailto:dickey@his.com). You can contact the maintainers at [bug-ncurses@gnu.org](mailto:bug-ncurses@gnu.org).

* * *

1.2. What we can do with NCURSES
--------------------------------

NCURSES not only creates a wrapper over terminal capabilities, but also gives a robust framework to create nice looking UI (User Interface)s in text mode. It provides functions to create windows etc. Its sister libraries panel, menu and form provide an extension to the basic curses library. These libraries usually come along with curses. One can create applications that contain multiple windows, menus, panels and forms. Windows can be managed independently, can provide 'scrollability' and even can be hidden.

Menus provide the user with an easy command selection option. Forms allow the creation of easy-to-use data entry and display windows. Panels extend the capabilities of ncurses to deal with overlapping and stacked windows.

These are just some of the basic things we can do with ncurses. As we move along, We will see all the capabilities of these libraries.

* * *

1.3. Where to get it
--------------------

All right, now that you know what you can do with ncurses, you must be rearing to get started. NCURSES is usually shipped with your installation. In case you don't have the library or want to compile it on your own, read on.

_Compiling the package_

NCURSES can be obtained from [ftp://ftp.gnu.org/pub/gnu/ncurses/ncurses.tar.gz](ftp://ftp.gnu.org/pub/gnu/ncurses/ncurses.tar.gz) or any of the ftp sites mentioned in [http://www.gnu.org/order/ftp.html](http://www.gnu.org/order/ftp.html).

Read the README and INSTALL files for details on to how to install it. It usually involves the following operations.

    tar zxvf ncurses<version>.tar.gz  # unzip and untar the archive
    cd ncurses<version>               # cd to the directory
    ./configure                             # configure the build according to your 
                                            # environment
    make                                    # make it
    su root                                 # become root
    make install                            # install it

_Using the RPM_

NCURSES RPM can be found and downloaded from [http://rpmfind.net](http://rpmfind.net) . The RPM can be installed with the following command after becoming root.

    rpm -i <downloaded rpm>

* * *

1.4. Purpose/Scope of the document
----------------------------------

This document is intended to be a "All in One" guide for programming with ncurses and its sister libraries. We graduate from a simple "Hello World" program to more complex form manipulation. No prior experience in ncurses is assumed. The writing is informal, but a lot of detail is provided for each of the examples.

* * *

1.5. About the Programs
-----------------------

All the programs in the document are available in zipped form [here](http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/ncurses_programs.tar.gz). Unzip and untar it. The directory structure looks like this.

ncurses
   |
   |----> JustForFun     -- just for fun programs
   |----> basics         -- basic programs
   |----> demo           -- output files go into this directory after make
   |          |
   |          |----> exe -- exe files of all example programs
   |----> forms          -- programs related to form library
   |----> menus          -- programs related to menus library
   |----> panels         -- programs related to panels library
   |----> perl           -- perl equivalents of the examples (contributed
   |                            by Anuradha Ratnaweera)
   |----> Makefile       -- the top level Makefile
   |----> README         -- the top level README file. contains instructions
   |----> COPYING        -- copyright notice

The individual directories contain the following files.

Description of files in each directory
--------------------------------------
JustForFun
    |
    |----> hanoi.c   -- The Towers of Hanoi Solver
    |----> life.c    -- The Game of Life demo
    |----> magic.c   -- An Odd Order Magic Square builder 
    |----> queens.c  -- The famous N-Queens Solver
    |----> shuffle.c -- A fun game, if you have time to kill
    |----> tt.c      -- A very trivial typing tutor

  basics
    |
    |----> acs\_vars.c            -- ACS\_ variables example
    |----> hello\_world.c         -- Simple "Hello World" Program
    |----> init\_func\_example.c   -- Initialization functions example
    |----> key\_code.c            -- Shows the scan code of the key pressed
    |----> mouse\_menu.c          -- A menu accessible by mouse
    |----> other\_border.c        -- Shows usage of other border functions apa
    |                               -- rt from box()
    |----> printw\_example.c      -- A very simple printw() example
    |----> scanw\_example.c       -- A very simple getstr() example
    |----> simple\_attr.c         -- A program that can print a c file with 
    |                               -- comments in attribute
    |----> simple\_color.c        -- A simple example demonstrating colors
    |----> simple\_key.c          -- A menu accessible with keyboard UP, DOWN 
    |                               -- arrows
    |----> temp\_leave.c          -- Demonstrates temporarily leaving curses mode
    |----> win\_border.c          -- Shows Creation of windows and borders
    |----> with\_chgat.c          -- chgat() usage example

  forms 
    |
    |----> form\_attrib.c     -- Usage of field attributes
    |----> form\_options.c    -- Usage of field options
    |----> form\_simple.c     -- A simple form example
    |----> form\_win.c        -- Demo of windows associated with forms

  menus 
    |
    |----> menu\_attrib.c     -- Usage of menu attributes
    |----> menu\_item\_data.c  -- Usage of item\_name() etc.. functions
    |----> menu\_multi\_column.c    -- Creates multi columnar menus
    |----> menu\_scroll.c     -- Demonstrates scrolling capability of menus
    |----> menu\_simple.c     -- A simple menu accessed by arrow keys
    |----> menu\_toggle.c     -- Creates multi valued menus and explains
    |                           -- REQ\_TOGGLE\_ITEM
    |----> menu\_userptr.c    -- Usage of user pointer
    |----> menu\_win.c        -- Demo of windows associated with menus

  panels 
    |
    |----> panel\_browse.c    -- Panel browsing through tab. Usage of user 
    |                           -- pointer
    |----> panel\_hide.c      -- Hiding and Un hiding of panels
    |----> panel\_resize.c    -- Moving and resizing of panels
    |----> panel\_simple.c    -- A simple panel example

  perl
    |----> 01-10.pl          -- Perl equivalents of first ten example programs

There is a top level Makefile included in the main directory. It builds all the files and puts the ready-to-use exes in demo/exe directory. You can also do selective make by going into the corresponding directory. Each directory contains a README file explaining the purpose of each c file in the directory.

For every example, I have included path name for the file relative to the examples directory.

If you prefer browsing individual programs, point your browser to [http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ncurses\_programs/](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ncurses_programs/)

All the programs are released under the same license that is used by ncurses (MIT-style). This gives you the ability to do pretty much anything other than claiming them as yours. Feel free to use them in your programs as appropriate.

* * *

1.6. Other Formats of the document
----------------------------------

This howto is also availabe in various other formats on the tldp.org site. Here are the links to other formats of this document.

* * *

### 1.6.1. Readily available formats from tldp.org

*   [Acrobat PDF Format](http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/pdf/NCURSES-Programming-HOWTO.pdf)
    
*   [PostScript Format](http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/ps/NCURSES-Programming-HOWTO.ps.gz)
    
*   [In Multiple HTML pages](http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/html/NCURSES-Programming-HOWTO-html.tar.gz)
    
*   [In One big HTML format](http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/html_single/NCURSES-Programming-HOWTO.html)
    

* * *

### 1.6.2. Building from source

If above links are broken or if you want to experiment with sgml read on.

    Get both the source and the tar,gzipped programs, available at
        http://cvsview.tldp.org/index.cgi/LDP/howto/docbook/
        NCURSES-HOWTO/NCURSES-Programming-HOWTO.sgml
        http://cvsview.tldp.org/index.cgi/LDP/howto/docbook/
        NCURSES-HOWTO/ncurses\_programs.tar.gz

    Unzip ncurses\_programs.tar.gz with
    tar zxvf ncurses\_programs.tar.gz

    Use jade to create various formats. For example if you just want to create
    the multiple html files, you would use
        jade -t sgml -i html -d <path to docbook html stylesheet>
        NCURSES-Programming-HOWTO.sgml
    to get pdf, first create a single html file of the HOWTO with 
        jade -t sgml -i html -d <path to docbook html stylesheet> -V nochunks
        NCURSES-Programming-HOWTO.sgml > NCURSES-ONE-BIG-FILE.html
    then use htmldoc to get pdf file with
        htmldoc --size universal -t pdf --firstpage p1 -f <output file name.pdf>
        NCURSES-ONE-BIG-FILE.html
    for ps, you would use
        htmldoc --size universal -t ps --firstpage p1 -f <output file name.ps>
        NCURSES-ONE-BIG-FILE.html

See [LDP Author guide](http://www.tldp.org/LDP/LDP-Author-Guide/) for more details. If all else failes, mail me at [ppadala@gmail.com](ppadala@gmail.com)

* * *

1.7. Credits
------------

I thank [Sharath](mailto:sharath_1@usa.net) and Emre Akbas for helping me with few sections. The introduction was initially written by sharath. I rewrote it with few excerpts taken from his initial work. Emre helped in writing printw and scanw sections.

Perl equivalents of the example programs are contributed by [Anuradha Ratnaweera](mailto:Aratnaweera@virtusa.com).

Then comes [Ravi Parimi](mailto:parimi@ece.arizona.edu), my dearest friend, who has been on this project before even one line was written. He constantly bombarded me with suggestions and patiently reviewed the whole text. He also checked each program on Linux and Solaris.

* * *

1.8. Wish List
--------------

This is the wish list, in the order of priority. If you have a wish or you want to work on completing the wish, mail [me](mailto:ppadala@gmail.com).

*   Add examples to last parts of forms section.
    
*   Prepare a Demo showing all the programs and allow the user to browse through description of each program. Let the user compile and see the program in action. A dialog based interface is preferred.
    
*   Add debug info. \_tracef, \_tracemouse stuff.
    
*   Accessing termcap, terminfo using functions provided by ncurses package.
    
*   Working on two terminals simultaneously.
    
*   Add more stuff to miscellaneous section.
    

* * *

1.9. Copyright
--------------

Copyright © 2001 by Pradeep Padala.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, distribute with modifications, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name(s) of the above copyright holders shall not be used in advertising or otherwise to promote the sale, use or other dealings in this Software without prior written authorization.

* * *

2\. Hello World !!!
===================

Welcome to the world of curses. Before we plunge into the library and look into its various features, let's write a simple program and say hello to the world.

* * *

2.1. Compiling With the NCURSES Library
---------------------------------------

To use ncurses library functions, you have to include ncurses.h in your programs. To link the program with ncurses the flag -lncurses should be added.

    #include <ncurses.h>
    .
    .
    .

    compile and link: gcc <program file> -lncurses

**Example 1. The Hello World !!! Program**

#include <ncurses.h>

int main()
{	
	initscr();			/\* Start curses mode 		  \*/
	printw("Hello World !!!");	/\* Print Hello World		  \*/
	refresh();			/\* Print it on to the real screen \*/
	getch();			/\* Wait for user input \*/
	endwin();			/\* End curses mode		  \*/

	return 0;
}

* * *

2.2. Dissection
---------------

The above program prints "Hello World !!!" to the screen and exits. This program shows how to initialize curses and do screen manipulation and end curses mode. Let's dissect it line by line.

* * *

### 2.2.1. About initscr()

The function initscr() initializes the terminal in curses mode. In some implementations, it clears the screen and presents a blank screen. To do any screen manipulation using curses package this has to be called first. This function initializes the curses system and allocates memory for our present window (called stdscr) and some other data-structures. Under extreme cases this function might fail due to insufficient memory to allocate memory for curses library's data structures.

After this is done, we can do a variety of initializations to customize our curses settings. These details will be explained [later](#INIT) .

* * *

### 2.2.2. The mysterious refresh()

The next line printw prints the string "Hello World !!!" on to the screen. This function is analogous to normal printf in all respects except that it prints the data on a window called stdscr at the current (y,x) co-ordinates. Since our present co-ordinates are at 0,0 the string is printed at the left hand corner of the window.

This brings us to that mysterious refresh(). Well, when we called printw the data is actually written to an imaginary window, which is not updated on the screen yet. The job of printw is to update a few flags and data structures and write the data to a buffer corresponding to stdscr. In order to show it on the screen, we need to call refresh() and tell the curses system to dump the contents on the screen.

The philosophy behind all this is to allow the programmer to do multiple updates on the imaginary screen or windows and do a refresh once all his screen update is done. refresh() checks the window and updates only the portion which has been changed. This improves performance and offers greater flexibility too. But, it is sometimes frustrating to beginners. A common mistake committed by beginners is to forget to call refresh() after they did some update through printw() class of functions. I still forget to add it sometimes :-)

* * *

### 2.2.3. About endwin()

And finally don't forget to end the curses mode. Otherwise your terminal might behave strangely after the program quits. endwin() frees the memory taken by curses sub-system and its data structures and puts the terminal in normal mode. This function must be called after you are done with the curses mode.

* * *

3\. The Gory Details
====================

Now that we have seen how to write a simple curses program let's get into the details. There are many functions that help customize what you see on screen and many features which can be put to full use.

Here we go...

* * *

4\. Initialization
==================

We now know that to initialize curses system the function initscr() has to be called. There are functions which can be called after this initialization to customize our curses session. We may ask the curses system to set the terminal in raw mode or initialize color or initialize the mouse etc.. Let's discuss some of the functions that are normally called immediately after initscr();

* * *

4.1. Initialization functions
-----------------------------

* * *

4.2. raw() and cbreak()
-----------------------

Normally the terminal driver buffers the characters a user types until a new line or carriage return is encountered. But most programs require that the characters be available as soon as the user types them. The above two functions are used to disable line buffering. The difference between these two functions is in the way control characters like suspend (CTRL-Z), interrupt and quit (CTRL-C) are passed to the program. In the raw() mode these characters are directly passed to the program without generating a signal. In the cbreak() mode these control characters are interpreted as any other character by the terminal driver. I personally prefer to use raw() as I can exercise greater control over what the user does.

* * *

4.3. echo() and noecho()
------------------------

These functions control the echoing of characters typed by the user to the terminal. noecho() switches off echoing. The reason you might want to do this is to gain more control over echoing or to suppress unnecessary echoing while taking input from the user through the getch() etc. functions. Most of the interactive programs call noecho() at initialization and do the echoing of characters in a controlled manner. It gives the programmer the flexibility of echoing characters at any place in the window without updating current (y,x) co-ordinates.

* * *

4.4. keypad()
-------------

This is my favorite initialization function. It enables the reading of function keys like F1, F2, arrow keys etc. Almost every interactive program enables this, as arrow keys are a major part of any User Interface. Do keypad(stdscr, TRUE) to enable this feature for the regular screen (stdscr). You will learn more about key management in later sections of this document.

* * *

4.5. halfdelay()
----------------

This function, though not used very often, is a useful one at times. halfdelay()is called to enable the half-delay mode, which is similar to the cbreak() mode in that characters typed are immediately available to program. However, it waits for 'X' tenths of a second for input and then returns ERR, if no input is available. 'X' is the timeout value passed to the function halfdelay(). This function is useful when you want to ask the user for input, and if he doesn't respond with in certain time, we can do some thing else. One possible example is a timeout at the password prompt.

* * *

4.6. Miscellaneous Initialization functions
-------------------------------------------

There are few more functions which are called at initialization to customize curses behavior. They are not used as extensively as those mentioned above. Some of them are explained where appropriate.

* * *

4.7. An Example
---------------

Let's write a program which will clarify the usage of these functions.

**Example 2. Initialization Function Usage example**

#include <ncurses.h>

int main()
{	int ch;

	initscr();			/\* Start curses mode 		\*/
	raw();				/\* Line buffering disabled	\*/
	keypad(stdscr, TRUE);		/\* We get F1, F2 etc..		\*/
	noecho();			/\* Don't echo() while we do getch \*/

    	printw("Type any character to see it in bold\\n");
	ch = getch();			/\* If raw() hadn't been called
					 \* we have to press enter before it
					 \* gets to the program 		\*/
	if(ch == KEY\_F(1))		/\* Without keypad enabled this will \*/
		printw("F1 Key pressed");/\*  not get to us either	\*/
					/\* Without noecho() some ugly escape
					 \* charachters might have been printed
					 \* on screen			\*/
	else
	{	printw("The pressed key is ");
		attron(A\_BOLD);
		printw("%c", ch);
		attroff(A\_BOLD);
	}
	refresh();			/\* Print it on to the real screen \*/
    	getch();			/\* Wait for user input \*/
	endwin();			/\* End curses mode		  \*/

	return 0;
}

This program is self-explanatory. But I used functions which aren't explained yet. The function getch() is used to get a character from user. It is equivalent to normal getchar() except that we can disable the line buffering to avoid <enter> after input. Look for more about getch()and reading keys in the [key management section](#KEYS) . The functions attron and attroff are used to switch some attributes on and off respectively. In the example I used them to print the character in bold. These functions are explained in detail later.

* * *

5\. A Word about Windows
========================

Before we plunge into the myriad ncurses functions, let me clear few things about windows. Windows are explained in detail in following [sections](#WINDOWS)

A Window is an imaginary screen defined by curses system. A window does not mean a bordered window which you usually see on Win9X platforms. When curses is initialized, it creates a default window named stdscr which represents your 80x25 (or the size of window in which you are running) screen. If you are doing simple tasks like printing few strings, reading input etc., you can safely use this single window for all of your purposes. You can also create windows and call functions which explicitly work on the specified window.

For example, if you call

    printw("Hi There !!!");
    refresh();

It prints the string on stdscr at the present cursor position. Similarly the call to refresh(), works on stdscr only.

Say you have created [windows](#WINDOWS) then you have to call a function with a 'w' added to the usual function.

    wprintw(win, "Hi There !!!");
    wrefresh(win);

As you will see in the rest of the document, naming of functions follow the same convention. For each function there usually are three more functions.

    printw(string);        /\* Print on stdscr at present cursor position \*/
    mvprintw(y, x, string);/\* Move to (y, x) then print string     \*/
    wprintw(win, string);  /\* Print on window win at present cursor position \*/
                           /\* in the window \*/
    mvwprintw(win, y, x, string);   /\* Move to (y, x) relative to window \*/
                                    /\* co-ordinates and then print         \*/

Usually the w-less functions are macros which expand to corresponding w-function with stdscr as the window parameter.

* * *

6\. Output functions
====================

I guess you can't wait any more to see some action. Back to our odyssey of curses functions. Now that curses is initialized, let's interact with world.

There are three classes of functions which you can use to do output on screen.

1.  addch() class: Print single character with attributes
    
2.  printw() class: Print formatted output similar to printf()
    
3.  addstr() class: Print strings
    

These functions can be used interchangeably and it's a matter of style as to which class is used. Let's see each one in detail.

* * *

6.1. addch() class of functions
-------------------------------

These functions put a single character into the current cursor location and advance the position of the cursor. You can give the character to be printed but they usually are used to print a character with some attributes. Attributes are explained in detail in later [sections](#ATTRIB) of the document. If a character is associated with an attribute(bold, reverse video etc.), when curses prints the character, it is printed in that attribute.

In order to combine a character with some attributes, you have two options:

*   By OR'ing a single character with the desired attribute macros. These attribute macros could be found in the header file ncurses.h. For example, you want to print a character ch(of type char) bold and underlined, you would call addch() as below.
    
        addch(ch | A\_BOLD | A\_UNDERLINE);
    
*   By using functions like attrset(),attron(),attroff(). These functions are explained in the [Attributes](#ATTRIB) section. Briefly, they manipulate the current attributes of the given window. Once set, the character printed in the window are associated with the attributes until it is turned off.
    

Additionally, curses provides some special characters for character-based graphics. You can draw tables, horizontal or vertical lines, etc. You can find all avaliable characters in the header file ncurses.h. Try looking for macros beginning with ACS\_ in this file.

* * *

6.2. mvaddch(), waddch() and mvwaddch()
---------------------------------------

mvaddch() is used to move the cursor to a given point, and then print. Thus, the calls:

    move(row,col);    /\* moves the cursor to row_th_ row and col_th_ column \*/
    addch(ch);

can be replaced by

    mvaddch(row,col,ch);

waddch() is similar to addch(), except that it adds a character into the given window. (Note that addch() adds a character into the window stdscr.)

In a similar fashion mvwaddch() function is used to add a character into the given window at the given coordinates.

Now, we are familiar with the basic output function addch(). But, if we want to print a string, it would be very annoying to print it character by character. Fortunately, ncurses provides printf_\-like_ or puts_\-like_ functions.

* * *

6.3. printw() class of functions
--------------------------------

These functions are similar to printf() with the added capability of printing at any position on the screen.

* * *

### 6.3.1. printw() and mvprintw

These two functions work much like printf(). mvprintw() can be used to move the cursor to a position and then print. If you want to move the cursor first and then print using printw() function, use move() first and then use printw() though I see no point why one should avoid using mvprintw(), you have the flexibility to manipulate.

* * *

### 6.3.2. wprintw() and mvwprintw

These two functions are similar to above two except that they print in the corresponding window given as argument.

* * *

### 6.3.3. vwprintw()

This function is similar to vprintf(). This can be used when variable number of arguments are to be printed.

* * *

### 6.3.4. A Simple printw example

**Example 3. A Simple printw example**

#include <ncurses.h>			/\* ncurses.h includes stdio.h \*/  
#include <string.h> 
 
int main()
{
 char mesg\[\]="Just a string";		/\* message to be appeared on the screen \*/
 int row,col;				/\* to store the number of rows and \*
					 \* the number of colums of the screen \*/
 initscr();				/\* start the curses mode \*/
 getmaxyx(stdscr,row,col);		/\* get the number of rows and columns \*/
 mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                                	/\* print the message at the center of the screen \*/
 mvprintw(row-2,0,"This screen has %d rows and %d columns\\n",row,col);
 printw("Try resizing your window(if possible) and then run this program again");
 refresh();
 getch();
 endwin();

 return 0;
}

Above program demonstrates how easy it is to use printw. You just feed the coordinates and the message to be appeared on the screen, then it does what you want.

The above program introduces us to a new function getmaxyx(), a macro defined in ncurses.h. It gives the number of columns and the number of rows in a given window. getmaxyx() does this by updating the variables given to it. Since getmaxyx() is not a function we don't pass pointers to it, we just give two integer variables.

* * *

6.4. addstr() class of functions
--------------------------------

addstr() is used to put a character string into a given window. This function is similar to calling addch() once for each character in a given string. This is true for all output functions. There are other functions from this family such as mvaddstr(),mvwaddstr() and waddstr(), which obey the naming convention of curses.(e.g. mvaddstr() is similar to the respective calls move() and then addstr().) Another function of this family is addnstr(), which takes an integer parameter(say n) additionally. This function puts at most n characters into the screen. If n is negative, then the entire string will be added.

* * *

6.5. A word of caution
----------------------

All these functions take y co-ordinate first and then x in their arguments. A common mistake by beginners is to pass x,y in that order. If you are doing too many manipulations of (y,x) co-ordinates, think of dividing the screen into windows and manipulate each one separately. Windows are explained in the [windows](#WINDOWS) section.

* * *

7\. Input functions
===================

Well, printing without taking input, is boring. Let's see functions which allow us to get input from user. These functions also can be divided into three categories.

1.  getch() class: Get a character
    
2.  scanw() class: Get formatted input
    
3.  getstr() class: Get strings
    

* * *

7.1. getch() class of functions
-------------------------------

These functions read a single character from the terminal. But there are several subtle facts to consider. For example if you don't use the function cbreak(), curses will not read your input characters contiguously but will begin read them only after a new line or an EOF is encountered. In order to avoid this, the cbreak() function must used so that characters are immediately available to your program. Another widely used function is noecho(). As the name suggests, when this function is set (used), the characters that are keyed in by the user will not show up on the screen. The two functions cbreak() and noecho() are typical examples of key management. Functions of this genre are explained in the [key management section](#KEYS) .

* * *

7.2. scanw() class of functions
-------------------------------

These functions are similar to scanf() with the added capability of getting the input from any location on the screen.

* * *

### 7.2.1. scanw() and mvscanw

The usage of these functions is similar to that of sscanf(), where the line to be scanned is provided by wgetstr() function. That is, these functions call to wgetstr() function(explained below) and uses the resulting line for a scan.

* * *

### 7.2.2. wscanw() and mvwscanw()

These are similar to above two functions except that they read from a window, which is supplied as one of the arguments to these functions.

* * *

### 7.2.3. vwscanw()

This function is similar to vscanf(). This can be used when a variable number of arguments are to be scanned.

* * *

7.3. getstr() class of functions
--------------------------------

These functions are used to get strings from the terminal. In essence, this function performs the same task as would be achieved by a series of calls to getch() until a newline, carriage return, or end-of-file is received. The resulting string of characters are pointed to by str, which is a character pointer provided by the user.

* * *

7.4. Some examples
------------------

**Example 4. A Simple scanw example**

#include <ncurses.h>			/\* ncurses.h includes stdio.h \*/  
#include <string.h> 
 
int main()
{
 char mesg\[\]="Enter a string: ";		/\* message to be appeared on the screen \*/
 char str\[80\];
 int row,col;				/\* to store the number of rows and \*
					 \* the number of colums of the screen \*/
 initscr();				/\* start the curses mode \*/
 getmaxyx(stdscr,row,col);		/\* get the number of rows and columns \*/
 mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                     		/\* print the message at the center of the screen \*/
 getstr(str);
 mvprintw(LINES - 2, 0, "You Entered: %s", str);
 getch();
 endwin();

 return 0;
}

* * *

8\. Attributes
==============

We have seen an example of how attributes can be used to print characters with some special effects. Attributes, when set prudently, can present information in an easy, understandable manner. The following program takes a C file as input and prints the file with comments in bold. Scan through the code.

**Example 5. A Simple Attributes example**

/\* pager functionality by Joseph Spainhour" <spainhou@bellsouth.net> \*/
#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char \*argv\[\])
{ 
  int ch, prev, row, col;
  prev = EOF;
  FILE \*fp;
  int y, x;

  if(argc != 2)
  {
    printf("Usage: %s <a c file name>\\n", argv\[0\]);
    exit(1);
  }
  fp = fopen(argv\[1\], "r");
  if(fp == NULL)
  {
    perror("Cannot open input file");
    exit(1);
  }
  initscr();				/\* Start curses mode \*/
  getmaxyx(stdscr, row, col);		/\* find the boundaries of the screeen \*/
  while((ch = fgetc(fp)) != EOF)	/\* read the file till we reach the end \*/
  {
    getyx(stdscr, y, x);		/\* get the current curser position \*/
    if(y == (row - 1))			/\* are we are at the end of the screen \*/
    {
      printw("<-Press Any Key->");	/\* tell the user to press a key \*/
      getch();
      clear();				/\* clear the screen \*/
      move(0, 0);			/\* start at the beginning of the screen \*/
    }
    if(prev == '/' && ch == '\*')    	/\* If it is / and \* then only
                                     	 \* switch bold on \*/    
    {
      attron(A\_BOLD);			/\* cut bold on \*/
      getyx(stdscr, y, x);		/\* get the current curser position \*/
      move(y, x - 1);			/\* back up one space \*/
      printw("%c%c", '/', ch); 		/\* The actual printing is done here \*/
    }
    else
      printw("%c", ch);
    refresh();
    if(prev == '\*' && ch == '/')
      attroff(A\_BOLD);        		/\* Switch it off once we got \*
                                 	 \* and then / \*/
    prev = ch;
  }
  endwin();                       	/\* End curses mode \*/
  fclose(fp);
  return 0;
}

Don't worry about all those initialization and other crap. Concentrate on the while loop. It reads each character in the file and searches for the pattern /\*. Once it spots the pattern, it switches the BOLD attribute on with attron() . When we get the pattern \*/ it is switched off by attroff() .

The above program also introduces us to two useful functions getyx() and move(). The first function gets the co-ordinates of the present cursor into the variables y, x. Since getyx() is a macro we don't have to pass pointers to variables. The function move() moves the cursor to the co-ordinates given to it.

The above program is really a simple one which doesn't do much. On these lines one could write a more useful program which reads a C file, parses it and prints it in different colors. One could even extend it to other languages as well.

* * *

8.1. The details
----------------

Let's get into more details of attributes. The functions attron(), attroff(), attrset() , and their sister functions attr\_get() etc.. can be used to switch attributes on/off , get attributes and produce a colorful display.

The functions attron and attroff take a bit-mask of attributes and switch them on or off, respectively. The following video attributes, which are defined in <curses.h> can be passed to these functions.

    
    A\_NORMAL        Normal display (no highlight)
    A\_STANDOUT      Best highlighting mode of the terminal.
    A\_UNDERLINE     Underlining
    A\_REVERSE       Reverse video
    A\_BLINK         Blinking
    A\_DIM           Half bright
    A\_BOLD          Extra bright or bold
    A\_PROTECT       Protected mode
    A\_INVIS         Invisible or blank mode
    A\_ALTCHARSET    Alternate character set
    A\_CHARTEXT      Bit-mask to extract a character
    COLOR\_PAIR(n)   Color-pair number n 
    

The last one is the most colorful one :-) Colors are explained in the [next sections](#color).

We can OR(|) any number of above attributes to get a combined effect. If you wanted reverse video with blinking characters you can use

    attron(A\_REVERSE | A\_BLINK);

* * *

8.2. attron() vs attrset()
--------------------------

Then what is the difference between attron() and attrset()? attrset sets the attributes of window whereas attron just switches on the attribute given to it. So attrset() fully overrides whatever attributes the window previously had and sets it to the new attribute(s). Similarly attroff() just switches off the attribute(s) given to it as an argument. This gives us the flexibility of managing attributes easily.But if you use them carelessly you may loose track of what attributes the window has and garble the display. This is especially true while managing menus with colors and highlighting. So decide on a consistent policy and stick to it. You can always use standend() which is equivalent to attrset(A\_NORMAL) which turns off all attributes and brings you to normal mode.

* * *

8.3. attr\_get()
----------------

The function attr\_get() gets the current attributes and color pair of the window. Though we might not use this as often as the above functions, this is useful in scanning areas of screen. Say we wanted to do some complex update on screen and we are not sure what attribute each character is associated with. Then this function can be used with either attrset or attron to produce the desired effect.

* * *

8.4. attr\_ functions
---------------------

There are series of functions like attr\_set(), attr\_on etc.. These are similar to above functions except that they take parameters of type attr\_t.

* * *

8.5. wattr functions
--------------------

For each of the above functions we have a corresponding function with 'w' which operates on a particular window. The above functions operate on stdscr.

* * *

8.6. chgat() functions
----------------------

The function chgat() is listed in the end of the man page curs\_attr. It actually is a useful one. This function can be used to set attributes for a group of characters without moving. I mean it !!! without moving the cursor :-) It changes the attributes of a given number of characters starting at the current cursor location.

We can give -1 as the character count to update till end of line. If you want to change attributes of characters from current position to end of line, just use this.

    chgat(-1, A\_REVERSE, 0, NULL);

This function is useful when changing attributes for characters that are already on the screen. Move to the character from which you want to change and change the attribute.

Other functions wchgat(), mvchgat(), wchgat() behave similarly except that the w functions operate on the particular window. The mv functions first move the cursor then perform the work given to them. Actually chgat is a macro which is replaced by a wchgat() with stdscr as the window. Most of the "w-less" functions are macros.

**Example 6. Chgat() Usage example**

#include <ncurses.h>

int main(int argc, char \*argv\[\])
{	initscr();			/\* Start curses mode 		\*/
	start\_color();			/\* Start color functionality	\*/
	
	init\_pair(1, COLOR\_CYAN, COLOR\_BLACK);
	printw("A Big string which i didn't care to type fully ");
	mvchgat(0, 0, -1, A\_BLINK, 1, NULL);	
	/\* 
	 \* First two parameters specify the position at which to start 
	 \* Third parameter number of characters to update. -1 means till 
	 \* end of line
	 \* Forth parameter is the normal attribute you wanted to give 
	 \* to the charcter
	 \* Fifth is the color index. It is the index given during init\_pair()
	 \* use 0 if you didn't want color
	 \* Sixth one is always NULL 
	 \*/
	refresh();
    	getch();
	endwin();			/\* End curses mode		  \*/
	return 0;
}

This example also introduces us to the color world of curses. Colors will be explained in detail later. Use 0 for no color.

* * *

9\. Windows
===========

Windows form the most important concept in curses. You have seen the standard window stdscr above where all the functions implicitly operated on this window. Now to make design even a simplest GUI, you need to resort to windows. The main reason you may want to use windows is to manipulate parts of the screen separately, for better efficiency, by updating only the windows that need to be changed and for a better design. I would say the last reason is the most important in going for windows. You should always strive for a better and easy-to-manage design in your programs. If you are writing big, complex GUIs this is of pivotal importance before you start doing anything.

* * *

9.1. The basics
---------------

A Window can be created by calling the function newwin(). It doesn't create any thing on the screen actually. It allocates memory for a structure to manipulate the window and updates the structure with data regarding the window like it's size, beginy, beginx etc.. Hence in curses, a window is just an abstraction of an imaginary window, which can be manipulated independent of other parts of screen. The function newwin() returns a pointer to structure WINDOW, which can be passed to window related functions like wprintw() etc.. Finally the window can be destroyed with delwin(). It will deallocate the memory associated with the window structure.

* * *

9.2. Let there be a Window !!!
------------------------------

What fun is it, if a window is created and we can't see it. So the fun part begins by displaying the window. The function box() can be used to draw a border around the window. Let's explore these functions in more detail in this example.

**Example 7. Window Border example**

#include <ncurses.h>


WINDOW \*create\_newwin(int height, int width, int starty, int startx);
void destroy\_win(WINDOW \*local\_win);

int main(int argc, char \*argv\[\])
{	WINDOW \*my\_win;
	int startx, starty, width, height;
	int ch;

	initscr();			/\* Start curses mode 		\*/
	cbreak();			/\* Line buffering disabled, Pass on
					 \* everty thing to me 		\*/
	keypad(stdscr, TRUE);		/\* I need that nifty F1 	\*/

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;	/\* Calculating for a center placement \*/
	startx = (COLS - width) / 2;	/\* of the window		\*/
	printw("Press F1 to exit");
	refresh();
	my\_win = create\_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_LEFT:
				destroy\_win(my\_win);
				my\_win = create\_newwin(height, width, starty,--startx);
				break;
			case KEY\_RIGHT:
				destroy\_win(my\_win);
				my\_win = create\_newwin(height, width, starty,++startx);
				break;
			case KEY\_UP:
				destroy\_win(my\_win);
				my\_win = create\_newwin(height, width, --starty,startx);
				break;
			case KEY\_DOWN:
				destroy\_win(my\_win);
				my\_win = create\_newwin(height, width, ++starty,startx);
				break;	
		}
	}
		
	endwin();			/\* End curses mode		  \*/
	return 0;
}

WINDOW \*create\_newwin(int height, int width, int starty, int startx)
{	WINDOW \*local\_win;

	local\_win = newwin(height, width, starty, startx);
	box(local\_win, 0 , 0);		/\* 0, 0 gives default characters 
					 \* for the vertical and horizontal
					 \* lines			\*/
	wrefresh(local\_win);		/\* Show that box 		\*/

	return local\_win;
}

void destroy\_win(WINDOW \*local\_win)
{	
	/\* box(local\_win, ' ', ' '); : This won't produce the desired
	 \* result of erasing the window. It will leave it's four corners 
	 \* and so an ugly remnant of window. 
	 \*/
	wborder(local\_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/\* The parameters taken are 
	 \* 1. win: the window on which to operate
	 \* 2. ls: character to be used for the left side of the window 
	 \* 3. rs: character to be used for the right side of the window 
	 \* 4. ts: character to be used for the top side of the window 
	 \* 5. bs: character to be used for the bottom side of the window 
	 \* 6. tl: character to be used for the top left corner of the window 
	 \* 7. tr: character to be used for the top right corner of the window 
	 \* 8. bl: character to be used for the bottom left corner of the window 
	 \* 9. br: character to be used for the bottom right corner of the window
	 \*/
	wrefresh(local\_win);
	delwin(local\_win);
}

* * *

9.3. Explanation
----------------

Don't scream. I know it's a big example. But I have to explain some important things here :-). This program creates a rectangular window that can be moved with left, right, up, down arrow keys. It repeatedly creates and destroys windows as user press a key. Don't go beyond the screen limits. Checking for those limits is left as an exercise for the reader. Let's dissect it by line by line.

The create\_newwin() function creates a window with newwin() and displays a border around it with box. The function destroy\_win() first erases the window from screen by painting a border with ' ' character and then calling delwin() to deallocate memory related to it. Depending on the key the user presses, starty or startx is changed and a new window is created.

In the destroy\_win, as you can see, I used wborder instead of box. The reason is written in the comments (You missed it. I know. Read the code :-)). wborder draws a border around the window with the characters given to it as the 4 corner points and the 4 lines. To put it clearly, if you have called wborder as below:

    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');

it produces some thing like

    +------------+
    |            |
    |            |
    |            |
    |            |
    |            |
    |            |
    +------------+

* * *

9.4. The other stuff in the example
-----------------------------------

You can also see in the above examples, that I have used the variables COLS, LINES which are initialized to the screen sizes after initscr(). They can be useful in finding screen dimensions and finding the center co-ordinate of the screen as above. The function getch() as usual gets the key from keyboard and according to the key it does the corresponding work. This type of switch- case is very common in any GUI based programs.

* * *

9.5. Other Border functions
---------------------------

Above program is grossly inefficient in that with each press of a key, a window is destroyed and another is created. So let's write a more efficient program which uses other border related functions.

The following program uses mvhline() and mvvline() to achieve similar effect. These two functions are simple. They create a horizontal or vertical line of the specified length at the specified position.

**Example 8. More border functions**

#include <ncurses.h>

typedef struct \_win\_border\_struct {
	chtype 	ls, rs, ts, bs, 
	 	tl, tr, bl, br;
}WIN\_BORDER;

typedef struct \_WIN\_struct {

	int startx, starty;
	int height, width;
	WIN\_BORDER border;
}WIN;

void init\_win\_params(WIN \*p\_win);
void print\_win\_params(WIN \*p\_win);
void create\_box(WIN \*win, bool flag);

int main(int argc, char \*argv\[\])
{	WIN win;
	int ch;

	initscr();			/\* Start curses mode 		\*/
	start\_color();			/\* Start the color functionality \*/
	cbreak();			/\* Line buffering disabled, Pass on
					 \* everty thing to me 		\*/
	keypad(stdscr, TRUE);		/\* I need that nifty F1 	\*/
	noecho();
	init\_pair(1, COLOR\_CYAN, COLOR\_BLACK);

	/\* Initialize the window parameters \*/
	init\_win\_params(&win);
	print\_win\_params(&win);

	attron(COLOR\_PAIR(1));
	printw("Press F1 to exit");
	refresh();
	attroff(COLOR\_PAIR(1));
	
	create\_box(&win, TRUE);
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_LEFT:
				create\_box(&win, FALSE);
				--win.startx;
				create\_box(&win, TRUE);
				break;
			case KEY\_RIGHT:
				create\_box(&win, FALSE);
				++win.startx;
				create\_box(&win, TRUE);
				break;
			case KEY\_UP:
				create\_box(&win, FALSE);
				--win.starty;
				create\_box(&win, TRUE);
				break;
			case KEY\_DOWN:
				create\_box(&win, FALSE);
				++win.starty;
				create\_box(&win, TRUE);
				break;	
		}
	}
	endwin();			/\* End curses mode		  \*/
	return 0;
}
void init\_win\_params(WIN \*p\_win)
{
	p\_win->height = 3;
	p\_win->width = 10;
	p\_win->starty = (LINES - p\_win->height)/2;	
	p\_win->startx = (COLS - p\_win->width)/2;

	p\_win->border.ls = '|';
	p\_win->border.rs = '|';
	p\_win->border.ts = '-';
	p\_win->border.bs = '-';
	p\_win->border.tl = '+';
	p\_win->border.tr = '+';
	p\_win->border.bl = '+';
	p\_win->border.br = '+';

}
void print\_win\_params(WIN \*p\_win)
{
#ifdef \_DEBUG
	mvprintw(25, 0, "%d %d %d %d", p\_win->startx, p\_win->starty, 
				p\_win->width, p\_win->height);
	refresh();
#endif
}
void create\_box(WIN \*p\_win, bool flag)
{	int i, j;
	int x, y, w, h;

	x = p\_win->startx;
	y = p\_win->starty;
	w = p\_win->width;
	h = p\_win->height;

	if(flag == TRUE)
	{	mvaddch(y, x, p\_win->border.tl);
		mvaddch(y, x + w, p\_win->border.tr);
		mvaddch(y + h, x, p\_win->border.bl);
		mvaddch(y + h, x + w, p\_win->border.br);
		mvhline(y, x + 1, p\_win->border.ts, w - 1);
		mvhline(y + h, x + 1, p\_win->border.bs, w - 1);
		mvvline(y + 1, x, p\_win->border.ls, h - 1);
		mvvline(y + 1, x + w, p\_win->border.rs, h - 1);

	}
	else
		for(j = y; j <= y + h; ++j)
			for(i = x; i <= x + w; ++i)
				mvaddch(j, i, ' ');
				
	refresh();

}

* * *

10\. Colors
===========

10.1. The basics
----------------

Life seems dull with no colors. Curses has a nice mechanism to handle colors. Let's get into the thick of the things with a small program.

**Example 9. A Simple Color example**

#include <ncurses.h>

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string);
int main(int argc, char \*argv\[\])
{	initscr();			/\* Start curses mode 		\*/
	if(has\_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\\n");
		exit(1);
	}
	start\_color();			/\* Start color 			\*/
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);

	attron(COLOR\_PAIR(1));
	print\_in\_middle(stdscr, LINES / 2, 0, 0, "Viola !!! In color ...");
	attroff(COLOR\_PAIR(1));
    	getch();
	endwin();
}
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

As you can see, to start using color, you should first call the function start\_color(). After that, you can use color capabilities of your terminals using various functions. To find out whether a terminal has color capabilities or not, you can use has\_colors() function, which returns FALSE if the terminal does not support color.

Curses initializes all the colors supported by terminal when start\_color() is called. These can be accessed by the define constants like COLOR\_BLACK etc. Now to actually start using colors, you have to define pairs. Colors are always used in pairs. That means you have to use the function init\_pair() to define the foreground and background for the pair number you give. After that that pair number can be used as a normal attribute with COLOR\_PAIR()function. This may seem to be cumbersome at first. But this elegant solution allows us to manage color pairs very easily. To appreciate it, you have to look into the the source code of "dialog", a utility for displaying dialog boxes from shell scripts. The developers have defined foreground and background combinations for all the colors they might need and initialized at the beginning. This makes it very easy to set attributes just by accessing a pair which we already have defined as a constant.

The following colors are defined in curses.h. You can use these as parameters for various color functions.

        COLOR\_BLACK   0
        COLOR\_RED     1
        COLOR\_GREEN   2
        COLOR\_YELLOW  3
        COLOR\_BLUE    4
        COLOR\_MAGENTA 5
        COLOR\_CYAN    6
        COLOR\_WHITE   7

* * *

10.2. Changing Color Definitions
--------------------------------

The function init\_color()can be used to change the rgb values for the colors defined by curses initially. Say you wanted to lighten the intensity of red color by a minuscule. Then you can use this function as

    init\_color(COLOR\_RED, 700, 0, 0);
    /\* param 1     : color name
     \* param 2, 3, 4 : rgb content min = 0, max = 1000 \*/

If your terminal cannot change the color definitions, the function returns ERR. The function can\_change\_color() can be used to find out whether the terminal has the capability of changing color content or not. The rgb content is scaled from 0 to 1000. Initially RED color is defined with content 1000(r), 0(g), 0(b).

* * *

10.3. Color Content
-------------------

The functions color\_content() and pair\_content() can be used to find the color content and foreground, background combination for the pair.

* * *

11\. Interfacing with the key board
===================================

11.1. The Basics
----------------

No GUI is complete without a strong user interface and to interact with the user, a curses program should be sensitive to key presses or the mouse actions done by the user. Let's deal with the keys first.

As you have seen in almost all of the above examples, it's very easy to get key input from the user. A simple way of getting key presses is to use getch() function. The cbreak mode should be enabled to read keys when you are interested in reading individual key hits rather than complete lines of text (which usually end with a carriage return). keypad should be enabled to get the Functions keys, arrow keys etc. See the initialization section for details.

getch() returns an integer corresponding to the key pressed. If it is a normal character, the integer value will be equivalent to the character. Otherwise it returns a number which can be matched with the constants defined in curses.h. For example if the user presses F1, the integer returned is 265. This can be checked using the macro KEY\_F() defined in curses.h. This makes reading keys portable and easy to manage.

For example, if you call getch() like this

    int ch;

    ch = getch();

getch() will wait for the user to press a key, (unless you specified a timeout) and when user presses a key, the corresponding integer is returned. Then you can check the value returned with the constants defined in curses.h to match against the keys you want.

The following code piece will do that job.

    if(ch == KEY\_LEFT)
        printw("Left arrow is pressed\\n");

Let's write a small program which creates a menu which can be navigated by up and down arrows.

* * *

11.2. A Simple Key Usage example
--------------------------------

**Example 10. A Simple Key Usage example**

#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char \*choices\[\] = { 
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };
int n\_choices = sizeof(choices) / sizeof(char \*);
void print\_menu(WINDOW \*menu\_win, int highlight);

int main()
{	WINDOW \*menu\_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();	/\* Line buffering disabled. pass on everything \*/
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
		
	menu\_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu\_win, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
	print\_menu(menu\_win, highlight);
	while(1)
	{	c = wgetch(menu\_win);
		switch(c)
		{	case KEY\_UP:
				if(highlight == 1)
					highlight = n\_choices;
				else
					--highlight;
				break;
			case KEY\_DOWN:
				if(highlight == n\_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print\_menu(menu\_win, highlight);
		if(choice != 0)	/\* User did a choice come out of the infinite loop \*/
			break;
	}	
	mvprintw(23, 0, "You chose choice %d with choice string %s\\n", choice, choices\[choice - 1\]);
	clrtoeol();
	refresh();
	endwin();
	return 0;
}


void print\_menu(WINDOW \*menu\_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu\_win, 0, 0);
	for(i = 0; i < n\_choices; ++i)
	{	if(highlight == i + 1) /\* High light the present choice \*/
		{	wattron(menu\_win, A\_REVERSE); 
			mvwprintw(menu\_win, y, x, "%s", choices\[i\]);
			wattroff(menu\_win, A\_REVERSE);
		}
		else
			mvwprintw(menu\_win, y, x, "%s", choices\[i\]);
		++y;
	}
	wrefresh(menu\_win);
}

* * *

12\. Interfacing with the mouse
===============================

Now that you have seen how to get keys, lets do the same thing from mouse. Usually each UI allows the user to interact with both keyboard and mouse.

* * *

12.1. The Basics
----------------

Before you do any thing else, the events you want to receive have to be enabled with mousemask().

    mousemask(  mmask\_t newmask,    /\* The events you want to listen to \*/
                mmask\_t \*oldmask)    /\* The old events mask                \*/

The first parameter to above function is a bit mask of events you would like to listen. By default, all the events are turned off. The bit mask ALL\_MOUSE\_EVENTS can be used to get all the events.

The following are all the event masks:

    Name            Description
       ---------------------------------------------------------------------
       BUTTON1\_PRESSED          mouse button 1 down
       BUTTON1\_RELEASED         mouse button 1 up
       BUTTON1\_CLICKED          mouse button 1 clicked
       BUTTON1\_DOUBLE\_CLICKED   mouse button 1 double clicked
       BUTTON1\_TRIPLE\_CLICKED   mouse button 1 triple clicked
       BUTTON2\_PRESSED          mouse button 2 down
       BUTTON2\_RELEASED         mouse button 2 up
       BUTTON2\_CLICKED          mouse button 2 clicked
       BUTTON2\_DOUBLE\_CLICKED   mouse button 2 double clicked
       BUTTON2\_TRIPLE\_CLICKED   mouse button 2 triple clicked
       BUTTON3\_PRESSED          mouse button 3 down
       BUTTON3\_RELEASED         mouse button 3 up
       BUTTON3\_CLICKED          mouse button 3 clicked
       BUTTON3\_DOUBLE\_CLICKED   mouse button 3 double clicked
       BUTTON3\_TRIPLE\_CLICKED   mouse button 3 triple clicked
       BUTTON4\_PRESSED          mouse button 4 down
       BUTTON4\_RELEASED         mouse button 4 up
       BUTTON4\_CLICKED          mouse button 4 clicked
       BUTTON4\_DOUBLE\_CLICKED   mouse button 4 double clicked
       BUTTON4\_TRIPLE\_CLICKED   mouse button 4 triple clicked
       BUTTON\_SHIFT             shift was down during button state change
       BUTTON\_CTRL              control was down during button state change
       BUTTON\_ALT               alt was down during button state change
       ALL\_MOUSE\_EVENTS         report all button state changes
       REPORT\_MOUSE\_POSITION    report mouse movement

* * *

12.2. Getting the events
------------------------

Once a class of mouse events have been enabled, getch() class of functions return KEY\_MOUSE every time some mouse event happens. Then the mouse event can be retrieved with getmouse().

The code approximately looks like this:

    MEVENT event;

    ch = getch();
    if(ch == KEY\_MOUSE)
        if(getmouse(&event) == OK)
            .    /\* Do some thing with the event \*/
            .
            .

getmouse() returns the event into the pointer given to it. It's a structure which contains

    typedef struct
    {
        short id;         /\* ID to distinguish multiple devices \*/
        int x, y, z;      /\* event coordinates \*/
        mmask\_t bstate;   /\* button state bits \*/
    }    

The bstate is the main variable we are interested in. It tells the button state of the mouse.

Then with a code snippet like the following, we can find out what happened.

    if(event.bstate & BUTTON1\_PRESSED)
        printw("Left Button Pressed");

* * *

12.3. Putting it all Together
-----------------------------

That's pretty much interfacing with mouse. Let's create the same menu and enable mouse interaction. To make things simpler, key handling is removed.

**Example 11. Access the menu with mouse !!!**

#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10 

int startx = 0;
int starty = 0;

char \*choices\[\] = { 	"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };

int n\_choices = sizeof(choices) / sizeof(char \*);

void print\_menu(WINDOW \*menu\_win, int highlight);
void report\_choice(int mouse\_x, int mouse\_y, int \*p\_choice);

int main()
{	int c, choice = 0;
	WINDOW \*menu\_win;
	MEVENT event;

	/\* Initialize curses \*/
	initscr();
	clear();
	noecho();
	cbreak();	//Line buffering disabled. pass on everything

	/\* Try to put the window in the middle of screen \*/
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
	
	attron(A\_REVERSE);
	mvprintw(23, 1, "Click on Exit to quit (Works best in a virtual console)");
	refresh();
	attroff(A\_REVERSE);

	/\* Print the menu for the first time \*/
	menu\_win = newwin(HEIGHT, WIDTH, starty, startx);
	print\_menu(menu\_win, 1);
	/\* Get all the mouse events \*/
	mousemask(ALL\_MOUSE\_EVENTS, NULL);
	
	while(1)
	{	c = wgetch(menu\_win);
		switch(c)
		{	case KEY\_MOUSE:
			if(getmouse(&event) == OK)
			{	/\* When the user clicks left mouse button \*/
				if(event.bstate & BUTTON1\_PRESSED)
				{	report\_choice(event.x + 1, event.y + 1, &choice);
					if(choice == -1) //Exit chosen
						goto end;
					mvprintw(22, 1, "Choice made is : %d String Chosen is \\"%10s\\"", choice, choices\[choice - 1\]);
					refresh(); 
				}
			}
			print\_menu(menu\_win, choice);
			break;
		}
	}		
end:
	endwin();
	return 0;
}


void print\_menu(WINDOW \*menu\_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu\_win, 0, 0);
	for(i = 0; i < n\_choices; ++i)
	{	if(highlight == i + 1)
		{	wattron(menu\_win, A\_REVERSE); 
			mvwprintw(menu\_win, y, x, "%s", choices\[i\]);
			wattroff(menu\_win, A\_REVERSE);
		}
		else
			mvwprintw(menu\_win, y, x, "%s", choices\[i\]);
		++y;
	}
	wrefresh(menu\_win);
}

/\* Report the choice according to mouse position \*/
void report\_choice(int mouse\_x, int mouse\_y, int \*p\_choice)
{	int i,j, choice;

	i = startx + 2;
	j = starty + 3;
	
	for(choice = 0; choice < n\_choices; ++choice)
		if(mouse\_y == j + choice && mouse\_x >= i && mouse\_x <= i + strlen(choices\[choice\]))
		{	if(choice == n\_choices - 1)
				\*p\_choice = -1;		
			else
				\*p\_choice = choice + 1;	
			break;
		}
}

* * *

12.4. Miscellaneous Functions
-----------------------------

The functions mouse\_trafo() and wmouse\_trafo() can be used to convert to mouse co-ordinates to screen relative co-ordinates. See curs\_mouse(3X) man page for details.

The mouseinterval function sets the maximum time (in thousands of a second) that can elapse between press and release events in order for them to be recognized as a click. This function returns the previous interval value. The default is one fifth of a second.

* * *

13\. Screen Manipulation
========================

In this section, we will look into some functions, which allow us to manage the screen efficiently and to write some fancy programs. This is especially important in writing games.

* * *

13.1. getyx() functions
-----------------------

The function getyx() can be used to find out the present cursor co-ordinates. It will fill the values of x and y co-ordinates in the arguments given to it. Since getyx() is a macro you don't have to pass the address of the variables. It can be called as

    getyx(win, y, x);
    /\* win: window pointer
     \*   y, x: y, x co-ordinates will be put into this variables 
     \*/

The function getparyx() gets the beginning co-ordinates of the sub window relative to the main window. This is some times useful to update a sub window. When designing fancy stuff like writing multiple menus, it becomes difficult to store the menu positions, their first option co-ordinates etc. A simple solution to this problem, is to create menus in sub windows and later find the starting co-ordinates of the menus by using getparyx().

The functions getbegyx() and getmaxyx() store current window's beginning and maximum co-ordinates. These functions are useful in the same way as above in managing the windows and sub windows effectively.

* * *

13.2. Screen Dumping
--------------------

While writing games, some times it becomes necessary to store the state of the screen and restore it back to the same state. The function scr\_dump() can be used to dump the screen contents to a file given as an argument. Later it can be restored by scr\_restore function. These two simple functions can be used effectively to maintain a fast moving game with changing scenarios.

* * *

13.3. Window Dumping
--------------------

To store and restore windows, the functions putwin() and getwin() can be used. putwin() puts the present window state into a file, which can be later restored by getwin().

The function copywin() can be used to copy a window completely onto another window. It takes the source and destination windows as parameters and according to the rectangle specified, it copies the rectangular region from source to destination window. It's last parameter specifies whether to overwrite or just overlay the contents on to the destination window. If this argument is true, then the copying is non-destructive.

* * *

14\. Miscellaneous features
===========================

Now you know enough features to write a good curses program, with all bells and whistles. There are some miscellaneous functions which are useful in various cases. Let's go headlong into some of those.

* * *

14.1. curs\_set()
-----------------

This function can be used to make the cursor invisible. The parameter to this function should be

    0 : invisible      or
    1 : normal    or
    2 : very visible.

* * *

14.2. Temporarily Leaving Curses mode
-------------------------------------

Some times you may want to get back to cooked mode (normal line buffering mode) temporarily. In such a case you will first need to save the tty modes with a call to def\_prog\_mode() and then call endwin() to end the curses mode. This will leave you in the original tty mode. To get back to curses once you are done, call reset\_prog\_mode() . This function returns the tty to the state stored by def\_prog\_mode(). Then do refresh(), and you are back to the curses mode. Here is an example showing the sequence of things to be done.

**Example 12. Temporarily Leaving Curses Mode**

#include <ncurses.h>

int main()
{	
	initscr();			/\* Start curses mode 		  \*/
	printw("Hello World !!!\\n");	/\* Print Hello World		  \*/
	refresh();			/\* Print it on to the real screen \*/
	def\_prog\_mode();		/\* Save the tty modes		  \*/
	endwin();			/\* End curses mode temporarily	  \*/
	system("/bin/sh");		/\* Do whatever you like in cooked mode \*/
	reset\_prog\_mode();		/\* Return to the previous tty mode\*/
					/\* stored by def\_prog\_mode() 	  \*/
	refresh();			/\* Do refresh() to restore the	  \*/
					/\* Screen contents		  \*/
	printw("Another String\\n");	/\* Back to curses use the full    \*/
	refresh();			/\* capabilities of curses	  \*/
	endwin();			/\* End curses mode		  \*/

	return 0;
}

* * *

14.3. ACS\_ variables
---------------------

If you have ever programmed in DOS, you know about those nifty characters in extended character set. They are printable only on some terminals. NCURSES functions like box() use these characters. All these variables start with ACS meaning alternative character set. You might have noticed me using these characters in some of the programs above. Here's an example showing all the characters.

**Example 13. ACS Variables Example**

#include <ncurses.h>

int main()
{
        initscr();

        printw("Upper left corner           "); addch(ACS\_ULCORNER); printw("\\n"); 
        printw("Lower left corner           "); addch(ACS\_LLCORNER); printw("\\n");
        printw("Lower right corner          "); addch(ACS\_LRCORNER); printw("\\n");
        printw("Tee pointing right          "); addch(ACS\_LTEE); printw("\\n");
        printw("Tee pointing left           "); addch(ACS\_RTEE); printw("\\n");
        printw("Tee pointing up             "); addch(ACS\_BTEE); printw("\\n");
        printw("Tee pointing down           "); addch(ACS\_TTEE); printw("\\n");
        printw("Horizontal line             "); addch(ACS\_HLINE); printw("\\n");
        printw("Vertical line               "); addch(ACS\_VLINE); printw("\\n");
        printw("Large Plus or cross over    "); addch(ACS\_PLUS); printw("\\n");
        printw("Scan Line 1                 "); addch(ACS\_S1); printw("\\n");
        printw("Scan Line 3                 "); addch(ACS\_S3); printw("\\n");
        printw("Scan Line 7                 "); addch(ACS\_S7); printw("\\n");
        printw("Scan Line 9                 "); addch(ACS\_S9); printw("\\n");
        printw("Diamond                     "); addch(ACS\_DIAMOND); printw("\\n");
        printw("Checker board (stipple)     "); addch(ACS\_CKBOARD); printw("\\n");
        printw("Degree Symbol               "); addch(ACS\_DEGREE); printw("\\n");
        printw("Plus/Minus Symbol           "); addch(ACS\_PLMINUS); printw("\\n");
        printw("Bullet                      "); addch(ACS\_BULLET); printw("\\n");
        printw("Arrow Pointing Left         "); addch(ACS\_LARROW); printw("\\n");
        printw("Arrow Pointing Right        "); addch(ACS\_RARROW); printw("\\n");
        printw("Arrow Pointing Down         "); addch(ACS\_DARROW); printw("\\n");
        printw("Arrow Pointing Up           "); addch(ACS\_UARROW); printw("\\n");
        printw("Board of squares            "); addch(ACS\_BOARD); printw("\\n");
        printw("Lantern Symbol              "); addch(ACS\_LANTERN); printw("\\n");
        printw("Solid Square Block          "); addch(ACS\_BLOCK); printw("\\n");
        printw("Less/Equal sign             "); addch(ACS\_LEQUAL); printw("\\n");
        printw("Greater/Equal sign          "); addch(ACS\_GEQUAL); printw("\\n");
        printw("Pi                          "); addch(ACS\_PI); printw("\\n");
        printw("Not equal                   "); addch(ACS\_NEQUAL); printw("\\n");
        printw("UK pound sign               "); addch(ACS\_STERLING); printw("\\n");

        refresh();
        getch();
        endwin();

	return 0;
}

* * *

15\. Other libraries
====================

Apart from the curses library, there are few text mode libraries, which provide more functionality and a lot of features. The following sections explain three standard libraries which are usually distributed along with curses.

* * *

16\. Panel Library
==================

Now that you are proficient in curses, you wanted to do some thing big. You created a lot of overlapping windows to give a professional windows-type look. Unfortunately, it soon becomes difficult to manage these. The multiple refreshes, updates plunge you into a nightmare. The overlapping windows create blotches, whenever you forget to refresh the windows in the proper order.

Don't despair. There's an elegant solution provided in panels library. In the words of developers of ncurses

_When your interface design is such that windows may dive deeper into the visibility stack or pop to the top at runtime, the resulting book-keeping can be tedious and difficult to get right. Hence the panels library._

If you have lot of overlapping windows, then panels library is the way to go. It obviates the need of doing series of wnoutrefresh(), doupdate() and relieves the burden of doing it correctly(bottom up). The library maintains information about the order of windows, their overlapping and update the screen properly. So why wait? Let's take a close peek into panels.

* * *

16.1. The Basics
----------------

Panel object is a window that is implicitly treated as part of a deck including all other panel objects. The deck is treated as a stack with the top panel being completely visible and the other panels may or may not be obscured according to their positions. So the basic idea is to create a stack of overlapping panels and use panels library to display them correctly. There is a function similar to refresh() which, when called , displays panels in the correct order. Functions are provided to hide or show panels, move panels, change its size etc.. The overlapping problem is managed by the panels library during all the calls to these functions.

The general flow of a panel program goes like this:

1.  Create the windows (with newwin()) to be attached to the panels.
    
2.  Create panels with the chosen visibility order. Stack them up according to the desired visibility. The function new\_panel() is used to created panels.
    
3.  Call update\_panels() to write the panels to the virtual screen in correct visibility order. Do a doupdate() to show it on the screen.
    
4.  Mainpulate the panels with show\_panel(), hide\_panel(), move\_panel() etc. Make use of helper functions like panel\_hidden() and panel\_window(). Make use of user pointer to store custom data for a panel. Use the functions set\_panel\_userptr() and panel\_userptr() to set and get the user pointer for a panel.
    
5.  When you are done with the panel use del\_panel() to delete the panel.
    

Let's make the concepts clear, with some programs. The following is a simple program which creates 3 overlapping panels and shows them on the screen.

* * *

16.2. Compiling With the Panels Library
---------------------------------------

To use panels library functions, you have to include panel.h and to link the program with panels library the flag -lpanel should be added along with -lncurses in that order.

    #include <panel.h>
    .
    .
    .

    compile and link: gcc <program file> -lpanel -lncurses

**Example 14. Panel basics**

#include <panel.h>

int main()
{	WINDOW \*my\_wins\[3\];
	PANEL  \*my\_panels\[3\];
	int lines = 10, cols = 40, y = 2, x = 4, i;

	initscr();
	cbreak();
	noecho();

	/\* Create windows for the panels \*/
	my\_wins\[0\] = newwin(lines, cols, y, x);
	my\_wins\[1\] = newwin(lines, cols, y + 1, x + 5);
	my\_wins\[2\] = newwin(lines, cols, y + 2, x + 10);

	/\* 
	 \* Create borders around the windows so that you can see the effect
	 \* of panels
	 \*/
	for(i = 0; i < 3; ++i)
		box(my\_wins\[i\], 0, 0);

	/\* Attach a panel to each window \*/ 	/\* Order is bottom up \*/
	my\_panels\[0\] = new\_panel(my\_wins\[0\]); 	/\* Push 0, order: stdscr-0 \*/
	my\_panels\[1\] = new\_panel(my\_wins\[1\]); 	/\* Push 1, order: stdscr-0-1 \*/
	my\_panels\[2\] = new\_panel(my\_wins\[2\]); 	/\* Push 2, order: stdscr-0-1-2 \*/

	/\* Update the stacking order. 2nd panel will be on top \*/
	update\_panels();

	/\* Show it on the screen \*/
	doupdate();
	
	getch();
	endwin();
}

As you can see, above program follows a simple flow as explained. The windows are created with newwin() and then they are attached to panels with new\_panel(). As we attach one panel after another, the stack of panels gets updated. To put them on screen update\_panels() and doupdate() are called.

* * *

16.3. Panel Window Browsing
---------------------------

A slightly complicated example is given below. This program creates 3 windows which can be cycled through using tab. Have a look at the code.

**Example 15. Panel Window Browsing Example**

#include <panel.h>

#define NLINES 10
#define NCOLS 40

void init\_wins(WINDOW \*\*wins, int n);
void win\_show(WINDOW \*win, char \*label, int label\_color);
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);

int main()
{	WINDOW \*my\_wins\[3\];
	PANEL  \*my\_panels\[3\];
	PANEL  \*top;
	int ch;

	/\* Initialize curses \*/
	initscr();
	start\_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize all the colors \*/
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_GREEN, COLOR\_BLACK);
	init\_pair(3, COLOR\_BLUE, COLOR\_BLACK);
	init\_pair(4, COLOR\_CYAN, COLOR\_BLACK);

	init\_wins(my\_wins, 3);
	
	/\* Attach a panel to each window \*/ 	/\* Order is bottom up \*/
	my\_panels\[0\] = new\_panel(my\_wins\[0\]); 	/\* Push 0, order: stdscr-0 \*/
	my\_panels\[1\] = new\_panel(my\_wins\[1\]); 	/\* Push 1, order: stdscr-0-1 \*/
	my\_panels\[2\] = new\_panel(my\_wins\[2\]); 	/\* Push 2, order: stdscr-0-1-2 \*/

	/\* Set up the user pointers to the next panel \*/
	set\_panel\_userptr(my\_panels\[0\], my\_panels\[1\]);
	set\_panel\_userptr(my\_panels\[1\], my\_panels\[2\]);
	set\_panel\_userptr(my\_panels\[2\], my\_panels\[0\]);

	/\* Update the stacking order. 2nd panel will be on top \*/
	update\_panels();

	/\* Show it on the screen \*/
	attron(COLOR\_PAIR(4));
	mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
	attroff(COLOR\_PAIR(4));
	doupdate();

	top = my\_panels\[2\];
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case 9:
				top = (PANEL \*)panel\_userptr(top);
				top\_panel(top);
				break;
		}
		update\_panels();
		doupdate();
	}
	endwin();
	return 0;
}

/\* Put all the windows \*/
void init\_wins(WINDOW \*\*wins, int n)
{	int x, y, i;
	char label\[80\];

	y = 2;
	x = 10;
	for(i = 0; i < n; ++i)
	{	wins\[i\] = newwin(NLINES, NCOLS, y, x);
		sprintf(label, "Window Number %d", i + 1);
		win\_show(wins\[i\], label, i + 1);
		y += 3;
		x += 7;
	}
}

/\* Show the window with a border and a label \*/
void win\_show(WINDOW \*win, char \*label, int label\_color)
{	int startx, starty, height, width;

	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS\_LTEE); 
	mvwhline(win, 2, 1, ACS\_HLINE, width - 2); 
	mvwaddch(win, 2, width - 1, ACS\_RTEE); 
	
	print\_in\_middle(win, 1, 0, width, label, COLOR\_PAIR(label\_color));
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

* * *

16.4. Using User Pointers
-------------------------

In the above example I used user pointers to find out the next window in the cycle. We can attach custom information to the panel by specifying a user pointer, which can point to any information you want to store. In this case I stored the pointer to the next panel in the cycle. User pointer for a panel can be set with the function set\_panel\_userptr(). It can be accessed using the function panel\_userptr() which will return the user pointer for the panel given as argument. After finding the next panel in the cycle It's brought to the top by the function top\_panel(). This function brings the panel given as argument to the top of the panel stack.

* * *

16.5. Moving and Resizing Panels
--------------------------------

The function move\_panel() can be used to move a panel to the desired location. It does not change the position of the panel in the stack. Make sure that you use move\_panel() instead mvwin() on the window associated with the panel.

Resizing a panel is slightly complex. There is no straight forward function just to resize the window associated with a panel. A solution to resize a panel is to create a new window with the desired sizes, change the window associated with the panel using replace\_panel(). Don't forget to delete the old window. The window associated with a panel can be found by using the function panel\_window().

The following program shows these concepts, in supposedly simple program. You can cycle through the window with <TAB> as usual. To resize or move the active panel press 'r' for resize 'm' for moving. Then use arrow keys to resize or move it to the desired way and press enter to end your resizing or moving. This example makes use of user data to get the required data to do the operations.

**Example 16. Panel Moving and Resizing example**

#include <panel.h>

typedef struct \_PANEL\_DATA {
	int x, y, w, h;
	char label\[80\]; 
	int label\_color;
	PANEL \*next;
}PANEL\_DATA;

#define NLINES 10
#define NCOLS 40

void init\_wins(WINDOW \*\*wins, int n);
void win\_show(WINDOW \*win, char \*label, int label\_color);
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);
void set\_user\_ptrs(PANEL \*\*panels, int n);

int main()
{	WINDOW \*my\_wins\[3\];
	PANEL  \*my\_panels\[3\];
	PANEL\_DATA  \*top;
	PANEL \*stack\_top;
	WINDOW \*temp\_win, \*old\_win;
	int ch;
	int newx, newy, neww, newh;
	int size = FALSE, move = FALSE;

	/\* Initialize curses \*/
	initscr();
	start\_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize all the colors \*/
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_GREEN, COLOR\_BLACK);
	init\_pair(3, COLOR\_BLUE, COLOR\_BLACK);
	init\_pair(4, COLOR\_CYAN, COLOR\_BLACK);

	init\_wins(my\_wins, 3);
	
	/\* Attach a panel to each window \*/ 	/\* Order is bottom up \*/
	my\_panels\[0\] = new\_panel(my\_wins\[0\]); 	/\* Push 0, order: stdscr-0 \*/
	my\_panels\[1\] = new\_panel(my\_wins\[1\]); 	/\* Push 1, order: stdscr-0-1 \*/
	my\_panels\[2\] = new\_panel(my\_wins\[2\]); 	/\* Push 2, order: stdscr-0-1-2 \*/

	set\_user\_ptrs(my\_panels, 3);
	/\* Update the stacking order. 2nd panel will be on top \*/
	update\_panels();

	/\* Show it on the screen \*/
	attron(COLOR\_PAIR(4));
	mvprintw(LINES - 3, 0, "Use 'm' for moving, 'r' for resizing");
	mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
	attroff(COLOR\_PAIR(4));
	doupdate();

	stack\_top = my\_panels\[2\];
	top = (PANEL\_DATA \*)panel\_userptr(stack\_top);
	newx = top->x;
	newy = top->y;
	neww = top->w;
	newh = top->h;
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case 9:		/\* Tab \*/
				top = (PANEL\_DATA \*)panel\_userptr(stack\_top);
				top\_panel(top->next);
				stack\_top = top->next;
				top = (PANEL\_DATA \*)panel\_userptr(stack\_top);
				newx = top->x;
				newy = top->y;
				neww = top->w;
				newh = top->h;
				break;
			case 'r':	/\* Re-Size\*/
				size = TRUE;
				attron(COLOR\_PAIR(4));
				mvprintw(LINES - 4, 0, "Entered Resizing :Use Arrow Keys to resize and press <ENTER> to end resizing");
				refresh();
				attroff(COLOR\_PAIR(4));
				break;
			case 'm':	/\* Move \*/
				attron(COLOR\_PAIR(4));
				mvprintw(LINES - 4, 0, "Entered Moving: Use Arrow Keys to Move and press <ENTER> to end moving");
				refresh();
				attroff(COLOR\_PAIR(4));
				move = TRUE;
				break;
			case KEY\_LEFT:
				if(size == TRUE)
				{	--newx;
					++neww;
				}
				if(move == TRUE)
					--newx;
				break;
			case KEY\_RIGHT:
				if(size == TRUE)
				{	++newx;
					--neww;
				}
				if(move == TRUE)
					++newx;
				break;
			case KEY\_UP:
				if(size == TRUE)
				{	--newy;
					++newh;
				}
				if(move == TRUE)
					--newy;
				break;
			case KEY\_DOWN:
				if(size == TRUE)
				{	++newy;
					--newh;
				}
				if(move == TRUE)
					++newy;
				break;
			case 10:	/\* Enter \*/
				move(LINES - 4, 0);
				clrtoeol();
				refresh();
				if(size == TRUE)
				{	old\_win = panel\_window(stack\_top);
					temp\_win = newwin(newh, neww, newy, newx);
					replace\_panel(stack\_top, temp\_win);
					win\_show(temp\_win, top->label, top->label\_color); 
					delwin(old\_win);
					size = FALSE;
				}
				if(move == TRUE)
				{	move\_panel(stack\_top, newy, newx);
					move = FALSE;
				}
				break;
			
		}
		attron(COLOR\_PAIR(4));
		mvprintw(LINES - 3, 0, "Use 'm' for moving, 'r' for resizing");
	    	mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
	    	attroff(COLOR\_PAIR(4));
	        refresh();	
		update\_panels();
		doupdate();
	}
	endwin();
	return 0;
}

/\* Put all the windows \*/
void init\_wins(WINDOW \*\*wins, int n)
{	int x, y, i;
	char label\[80\];

	y = 2;
	x = 10;
	for(i = 0; i < n; ++i)
	{	wins\[i\] = newwin(NLINES, NCOLS, y, x);
		sprintf(label, "Window Number %d", i + 1);
		win\_show(wins\[i\], label, i + 1);
		y += 3;
		x += 7;
	}
}

/\* Set the PANEL\_DATA structures for individual panels \*/
void set\_user\_ptrs(PANEL \*\*panels, int n)
{	PANEL\_DATA \*ptrs;
	WINDOW \*win;
	int x, y, w, h, i;
	char temp\[80\];
	
	ptrs = (PANEL\_DATA \*)calloc(n, sizeof(PANEL\_DATA));

	for(i = 0;i < n; ++i)
	{	win = panel\_window(panels\[i\]);
		getbegyx(win, y, x);
		getmaxyx(win, h, w);
		ptrs\[i\].x = x;
		ptrs\[i\].y = y;
		ptrs\[i\].w = w;
		ptrs\[i\].h = h;
		sprintf(temp, "Window Number %d", i + 1);
		strcpy(ptrs\[i\].label, temp);
		ptrs\[i\].label\_color = i + 1;
		if(i + 1 == n)
			ptrs\[i\].next = panels\[0\];
		else
			ptrs\[i\].next = panels\[i + 1\];
		set\_panel\_userptr(panels\[i\], &ptrs\[i\]);
	}
}

/\* Show the window with a border and a label \*/
void win\_show(WINDOW \*win, char \*label, int label\_color)
{	int startx, starty, height, width;

	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS\_LTEE); 
	mvwhline(win, 2, 1, ACS\_HLINE, width - 2); 
	mvwaddch(win, 2, width - 1, ACS\_RTEE); 
	
	print\_in\_middle(win, 1, 0, width, label, COLOR\_PAIR(label\_color));
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

Concentrate on the main while loop. Once it finds out the type of key pressed, it takes appropriate action. If 'r' is pressed resizing mode is started. After this the new sizes are updated as the user presses the arrow keys. When the user presses <ENTER> present selection ends and panel is resized by using the concept explained. While in resizing mode the program doesn't show how the window is getting resized. It's left as an exercise to the reader to print a dotted border while it gets resized to a new position.

When the user presses 'm' the move mode starts. This is a bit simpler than resizing. As the arrow keys are pressed the new position is updated and pressing of <ENTER> causes the panel to be moved by calling the function move\_panel().

In this program the user data which is represented as PANEL\_DATA, plays very important role in finding the associated information with a panel. As written in the comments, the PANEL\_DATA stores the panel sizes, label, label color and a pointer to the next panel in the cycle.

* * *

16.6. Hiding and Showing Panels
-------------------------------

A Panel can be hidden by using the function hide\_panel(). This function merely removes it form the stack of panels, thus hiding it on the screen once you do update\_panels() and doupdate(). It doesn't destroy the PANEL structure associated with the hidden panel. It can be shown again by using the show\_panel() function.

The following program shows the hiding of panels. Press 'a' or 'b' or 'c' to show or hide first, second and third windows respectively. It uses a user data with a small variable hide, which keeps track of whether the window is hidden or not. For some reason the function panel\_hidden() which tells whether a panel is hidden or not is not working. A bug report was also presented by Michael Andres [here](http://www.geocrawler.com/archives/3/344/1999/9/0/2643549/)

**Example 17. Panel Hiding and Showing example**

#include <panel.h>

typedef struct \_PANEL\_DATA {
	int hide;	/\* TRUE if panel is hidden \*/
}PANEL\_DATA;

#define NLINES 10
#define NCOLS 40

void init\_wins(WINDOW \*\*wins, int n);
void win\_show(WINDOW \*win, char \*label, int label\_color);
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);

int main()
{	WINDOW \*my\_wins\[3\];
	PANEL  \*my\_panels\[3\];
	PANEL\_DATA panel\_datas\[3\];
	PANEL\_DATA \*temp;
	int ch;

	/\* Initialize curses \*/
	initscr();
	start\_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize all the colors \*/
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_GREEN, COLOR\_BLACK);
	init\_pair(3, COLOR\_BLUE, COLOR\_BLACK);
	init\_pair(4, COLOR\_CYAN, COLOR\_BLACK);

	init\_wins(my\_wins, 3);
	
	/\* Attach a panel to each window \*/ 	/\* Order is bottom up \*/
	my\_panels\[0\] = new\_panel(my\_wins\[0\]); 	/\* Push 0, order: stdscr-0 \*/
	my\_panels\[1\] = new\_panel(my\_wins\[1\]); 	/\* Push 1, order: stdscr-0-1 \*/
	my\_panels\[2\] = new\_panel(my\_wins\[2\]); 	/\* Push 2, order: stdscr-0-1-2 \*/

	/\* Initialize panel datas saying that nothing is hidden \*/
	panel\_datas\[0\].hide = FALSE;
	panel\_datas\[1\].hide = FALSE;
	panel\_datas\[2\].hide = FALSE;

	set\_panel\_userptr(my\_panels\[0\], &panel\_datas\[0\]);
	set\_panel\_userptr(my\_panels\[1\], &panel\_datas\[1\]);
	set\_panel\_userptr(my\_panels\[2\], &panel\_datas\[2\]);

	/\* Update the stacking order. 2nd panel will be on top \*/
	update\_panels();

	/\* Show it on the screen \*/
	attron(COLOR\_PAIR(4));
	mvprintw(LINES - 3, 0, "Show or Hide a window with 'a'(first window)  'b'(Second Window)  'c'(Third Window)");
	mvprintw(LINES - 2, 0, "F1 to Exit");

	attroff(COLOR\_PAIR(4));
	doupdate();
	
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case 'a':			
				temp = (PANEL\_DATA \*)panel\_userptr(my\_panels\[0\]);
				if(temp->hide == FALSE)
				{	hide\_panel(my\_panels\[0\]);
					temp->hide = TRUE;
				}
				else
				{	show\_panel(my\_panels\[0\]);
					temp->hide = FALSE;
				}
				break;
			case 'b':
				temp = (PANEL\_DATA \*)panel\_userptr(my\_panels\[1\]);
				if(temp->hide == FALSE)
				{	hide\_panel(my\_panels\[1\]);
					temp->hide = TRUE;
				}
				else
				{	show\_panel(my\_panels\[1\]);
					temp->hide = FALSE;
				}
				break;
			case 'c':
				temp = (PANEL\_DATA \*)panel\_userptr(my\_panels\[2\]);
				if(temp->hide == FALSE)
				{	hide\_panel(my\_panels\[2\]);
					temp->hide = TRUE;
				}
				else
				{	show\_panel(my\_panels\[2\]);
					temp->hide = FALSE;
				}
				break;
		}
		update\_panels();
		doupdate();
	}
	endwin();
	return 0;
}

/\* Put all the windows \*/
void init\_wins(WINDOW \*\*wins, int n)
{	int x, y, i;
	char label\[80\];

	y = 2;
	x = 10;
	for(i = 0; i < n; ++i)
	{	wins\[i\] = newwin(NLINES, NCOLS, y, x);
		sprintf(label, "Window Number %d", i + 1);
		win\_show(wins\[i\], label, i + 1);
		y += 3;
		x += 7;
	}
}

/\* Show the window with a border and a label \*/
void win\_show(WINDOW \*win, char \*label, int label\_color)
{	int startx, starty, height, width;

	getbegyx(win, starty, startx);
	getmaxyx(win, height, width);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS\_LTEE); 
	mvwhline(win, 2, 1, ACS\_HLINE, width - 2); 
	mvwaddch(win, 2, width - 1, ACS\_RTEE); 
	
	print\_in\_middle(win, 1, 0, width, label, COLOR\_PAIR(label\_color));
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

* * *

16.7. panel\_above() and panel\_below() Functions
-------------------------------------------------

The functions panel\_above() and panel\_below() can be used to find out the panel above and below a panel. If the argument to these functions is NULL, then they return a pointer to bottom panel and top panel respectively.

* * *

17\. Menus Library
==================

The menus library provides a nice extension to basic curses, through which you can create menus. It provides a set of functions to create menus. But they have to be customized to give a nicer look, with colors etc. Let's get into the details.

A menu is a screen display that assists the user to choose some subset of a given set of items. To put it simple, a menu is a collection of items from which one or more items can be chosen. Some readers might not be aware of multiple item selection capability. Menu library provides functionality to write menus from which the user can chose more than one item as the preferred choice. This is dealt with in a later section. Now it is time for some rudiments.

* * *

17.1. The Basics
----------------

To create menus, you first create items, and then post the menu to the display. After that, all the processing of user responses is done in an elegant function menu\_driver() which is the work horse of any menu program.

The general flow of control of a menu program looks like this.

1.  Initialize curses
    
2.  Create items using new\_item(). You can specify a name and description for the items.
    
3.  Create the menu with new\_menu() by specifying the items to be attached with.
    
4.  Post the menu with menu\_post() and refresh the screen.
    
5.  Process the user requests with a loop and do necessary updates to menu with menu\_driver.
    
6.  Unpost the menu with menu\_unpost()
    
7.  Free the memory allocated to menu by free\_menu()
    
8.  Free the memory allocated to the items with free\_item()
    
9.  End curses
    

Let's see a program which prints a simple menu and updates the current selection with up, down arrows.

* * *

17.2. Compiling With the Menu Library
-------------------------------------

To use menu library functions, you have to include menu.h and to link the program with menu library the flag -lmenu should be added along with -lncurses in that order.

    #include <menu.h>
    .
    .
    .

    compile and link: gcc <program file> -lmenu -lncurses

**Example 18. Menu Basics**

#include <curses.h>
#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                  };

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
	int n\_choices, i;
	ITEM \*cur\_item;
	
	
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	n\_choices = ARRAY\_SIZE(choices);
	my\_items = (ITEM \*\*)calloc(n\_choices + 1, sizeof(ITEM \*));

	for(i = 0; i < n\_choices; ++i)
	        my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);
	my\_items\[n\_choices\] = (ITEM \*)NULL;

	my\_menu = new\_menu((ITEM \*\*)my\_items);
	mvprintw(LINES - 2, 0, "F1 to Exit");
	post\_menu(my\_menu);
	refresh();

	while((c = getch()) != KEY\_F(1))
	{   switch(c)
	    {	case KEY\_DOWN:
		        menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
		}
	}	

	free\_item(my\_items\[0\]);
	free\_item(my\_items\[1\]);
	free\_menu(my\_menu);
	endwin();
}
	

This program demonstrates the basic concepts involved in creating a menu using menus library. First we create the items using new\_item() and then attach them to the menu with new\_menu() function. After posting the menu and refreshing the screen, the main processing loop starts. It reads user input and takes corresponding action. The function menu\_driver() is the main work horse of the menu system. The second parameter to this function tells what's to be done with the menu. According to the parameter, menu\_driver() does the corresponding task. The value can be either a menu navigational request, an ascii character, or a KEY\_MOUSE special key associated with a mouse event.

The menu\_driver accepts following navigational requests.

     REQ\_LEFT\_ITEM         Move left to an item.
     REQ\_RIGHT\_ITEM      Move right to an item.
     REQ\_UP\_ITEM         Move up to an item.
     REQ\_DOWN\_ITEM       Move down to an item.
     REQ\_SCR\_ULINE       Scroll up a line.
     REQ\_SCR\_DLINE          Scroll down a line.
     REQ\_SCR\_DPAGE          Scroll down a page.
     REQ\_SCR\_UPAGE         Scroll up a page.
     REQ\_FIRST\_ITEM     Move to the first item.
     REQ\_LAST\_ITEM         Move to the last item.
     REQ\_NEXT\_ITEM         Move to the next item.
     REQ\_PREV\_ITEM         Move to the previous item. 
     REQ\_TOGGLE\_ITEM     Select/deselect an item.
     REQ\_CLEAR\_PATTERN     Clear the menu pattern buffer.
     REQ\_BACK\_PATTERN      Delete the previous character from the pattern buffer.
     REQ\_NEXT\_MATCH     Move to the next item matching the pattern match.
     REQ\_PREV\_MATCH     Move to the previous item matching the pattern match.

Don't get overwhelmed by the number of options. We will see them slowly one after another. The options of interest in this example are REQ\_UP\_ITEM and REQ\_DOWN\_ITEM. These two options when passed to menu\_driver, menu driver updates the current item to one item up or down respectively.

* * *

17.3. Menu Driver: The work horse of the menu system
----------------------------------------------------

As you have seen in the above example, menu\_driver plays an important role in updating the menu. It is very important to understand various options it takes and what they do. As explained above, the second parameter to menu\_driver() can be either a navigational request, a printable character or a KEY\_MOUSE key. Let's dissect the different navigational requests.

*   _REQ\_LEFT\_ITEM and REQ\_RIGHT\_ITEM_
    
    A Menu can be displayed with multiple columns for more than one item. This can be done by using the menu\_format()function. When a multi columnar menu is displayed these requests cause the menu driver to move the current selection to left or right.
    
*   _REQ\_UP\_ITEM and REQ\_DOWN\_ITEM_
    
    These two options you have seen in the above example. These options when given, makes the menu\_driver to move the current selection to an item up or down.
    
*   _REQ\_SCR\_\* options_
    
    The four options REQ\_SCR\_ULINE, REQ\_SCR\_DLINE, REQ\_SCR\_DPAGE, REQ\_SCR\_UPAGE are related to scrolling. If all the items in the menu cannot be displayed in the menu sub window, then the menu is scrollable. These requests can be given to the menu\_driver to do the scrolling either one line up, down or one page down or up respectively.
    
*   _REQ\_FIRST\_ITEM, REQ\_LAST\_ITEM, REQ\_NEXT\_ITEM and REQ\_PREV\_ITEM_
    
    These requests are self explanatory.
    
*   _REQ\_TOGGLE\_ITEM_
    
    This request when given, toggles the present selection. This option is to be used only in a multi valued menu. So to use this request the option O\_ONEVALUE must be off. This option can be made off or on with set\_menu\_opts().
    
*   _Pattern Requests_
    
    Every menu has an associated pattern buffer, which is used to find the nearest match to the ascii characters entered by the user. Whenever ascii characters are given to menu\_driver, it puts in to the pattern buffer. It also tries to find the nearest match to the pattern in the items list and moves current selection to that item. The request REQ\_CLEAR\_PATTERN clears the pattern buffer. The request REQ\_BACK\_PATTERN deletes the previous character in the pattern buffer. In case the pattern matches more than one item then the matched items can be cycled through REQ\_NEXT\_MATCH and REQ\_PREV\_MATCH which move the current selection to the next and previous matches respectively.
    
*   _Mouse Requests_
    
    In case of KEY\_MOUSE requests, according to the mouse position an action is taken accordingly. The action to be taken is explained in the man page as,
    
           _If  the  second argument is the KEY\_MOUSE special key, the
           associated mouse event is translated into one of the above
           pre-defined  requests.   Currently only clicks in the user
           window (e.g. inside the menu display area or  the  decora­
           tion  window)  are handled. If you click above the display
           region of the menu, a REQ\_SCR\_ULINE is generated,  if  you
           doubleclick  a  REQ\_SCR\_UPAGE  is  generated  and  if  you
           tripleclick a REQ\_FIRST\_ITEM is generated.  If  you  click
           below  the  display region of the menu, a REQ\_SCR\_DLINE is
           generated, if you doubleclick a REQ\_SCR\_DPAGE is generated
           and  if  you  tripleclick a REQ\_LAST\_ITEM is generated. If
           you click at an item inside the display area of the  menu,
           the menu cursor is positioned to that item._
    

Each of the above requests will be explained in the following lines with several examples whenever appropriate.

* * *

17.4. Menu Windows
------------------

Every menu created is associated with a window and a sub window. The menu window displays any title or border associated with the menu. The menu sub window displays the menu items currently available for selection. But we didn't specify any window or sub window in the simple example. When a window is not specified, stdscr is taken as the main window, and then menu system calculates the sub window size required for the display of items. Then items are displayed in the calculated sub window. So let's play with these windows and display a menu with a border and a title.

**Example 19. Menu Windows Usage example**

#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
                        "Exit",
                        (char \*)NULL,
                  };
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        WINDOW \*my\_menu\_win;
        int n\_choices, i;
	
	/\* Initialize curses \*/
	initscr();
	start\_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);

	/\* Create items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
                my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);

	/\* Crate menu \*/
	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Create the window to be associated with the menu \*/
        my\_menu\_win = newwin(10, 40, 4, 4);
        keypad(my\_menu\_win, TRUE);
     
	/\* Set main window and sub window \*/
        set\_menu\_win(my\_menu, my\_menu\_win);
        set\_menu\_sub(my\_menu, derwin(my\_menu\_win, 6, 38, 3, 1));

	/\* Set menu mark to the string " \* " \*/
        set\_menu\_mark(my\_menu, " \* ");

	/\* Print a border around the main window and print a title \*/
        box(my\_menu\_win, 0, 0);
	print\_in\_middle(my\_menu\_win, 1, 0, 40, "My Menu", COLOR\_PAIR(1));
	mvwaddch(my\_menu\_win, 2, 0, ACS\_LTEE);
	mvwhline(my\_menu\_win, 2, 1, ACS\_HLINE, 38);
	mvwaddch(my\_menu\_win, 2, 39, ACS\_RTEE);
	mvprintw(LINES - 2, 0, "F1 to exit");
	refresh();
        
	/\* Post the menu \*/
	post\_menu(my\_menu);
	wrefresh(my\_menu\_win);

	while((c = wgetch(my\_menu\_win)) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
		}
                wrefresh(my\_menu\_win);
	}	

	/\* Unpost and free all the memory taken up \*/
        unpost\_menu(my\_menu);
        free\_menu(my\_menu);
        for(i = 0; i < n\_choices; ++i)
                free\_item(my\_items\[i\]);
	endwin();
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

This example creates a menu with a title, border, a fancy line separating title and the items. As you can see, in order to attach a window to a menu the function set\_menu\_win() has to be used. Then we attach the sub window also. This displays the items in the sub window. You can also set the mark string which gets displayed to the left of the selected item with set\_menu\_mark().

* * *

17.5. Scrolling Menus
---------------------

If the sub window given for a window is not big enough to show all the items, then the menu will be scrollable. When you are on the last item in the present list, if you send REQ\_DOWN\_ITEM, it gets translated into REQ\_SCR\_DLINE and the menu scrolls by one item. You can manually give REQ\_SCR\_ operations to do scrolling. Let's see how it can be done.

**Example 20. Scrolling Menus example**

#include <curses.h>
#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
			"Choice 5",
			"Choice 6",
			"Choice 7",
			"Choice 8",
			"Choice 9",
			"Choice 10",
                        "Exit",
                        (char \*)NULL,
                  };
void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        WINDOW \*my\_menu\_win;
        int n\_choices, i;
	
	/\* Initialize curses \*/
	initscr();
	start\_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_CYAN, COLOR\_BLACK);

	/\* Create items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
                my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);

	/\* Crate menu \*/
	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Create the window to be associated with the menu \*/
        my\_menu\_win = newwin(10, 40, 4, 4);
        keypad(my\_menu\_win, TRUE);
     
	/\* Set main window and sub window \*/
        set\_menu\_win(my\_menu, my\_menu\_win);
        set\_menu\_sub(my\_menu, derwin(my\_menu\_win, 6, 38, 3, 1));
	set\_menu\_format(my\_menu, 5, 1);
			
	/\* Set menu mark to the string " \* " \*/
        set\_menu\_mark(my\_menu, " \* ");

	/\* Print a border around the main window and print a title \*/
        box(my\_menu\_win, 0, 0);
	print\_in\_middle(my\_menu\_win, 1, 0, 40, "My Menu", COLOR\_PAIR(1));
	mvwaddch(my\_menu\_win, 2, 0, ACS\_LTEE);
	mvwhline(my\_menu\_win, 2, 1, ACS\_HLINE, 38);
	mvwaddch(my\_menu\_win, 2, 39, ACS\_RTEE);
        
	/\* Post the menu \*/
	post\_menu(my\_menu);
	wrefresh(my\_menu\_win);
	
	attron(COLOR\_PAIR(2));
	mvprintw(LINES - 2, 0, "Use PageUp and PageDown to scoll down or up a page of items");
	mvprintw(LINES - 1, 0, "Arrow Keys to navigate (F1 to Exit)");
	attroff(COLOR\_PAIR(2));
	refresh();

	while((c = wgetch(my\_menu\_win)) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
			case KEY\_NPAGE:
				menu\_driver(my\_menu, REQ\_SCR\_DPAGE);
				break;
			case KEY\_PPAGE:
				menu\_driver(my\_menu, REQ\_SCR\_UPAGE);
				break;
		}
                wrefresh(my\_menu\_win);
	}	

	/\* Unpost and free all the memory taken up \*/
        unpost\_menu(my\_menu);
        free\_menu(my\_menu);
        for(i = 0; i < n\_choices; ++i)
                free\_item(my\_items\[i\]);
	endwin();
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

This program is self-explanatory. In this example the number of choices has been increased to ten, which is larger than our sub window size which can hold 6 items. This message has to be explicitly conveyed to the menu system with the function set\_menu\_format(). In here we specify the number of rows and columns we want to be displayed for a single page. We can specify any number of items to be shown, in the rows variables, if it is less than the height of the sub window. If the key pressed by the user is a PAGE UP or PAGE DOWN, the menu is scrolled a page due to the requests (REQ\_SCR\_DPAGE and REQ\_SCR\_UPAGE) given to menu\_driver().

* * *

17.6. Multi Columnar Menus
--------------------------

In the above example you have seen how to use the function set\_menu\_format(). I didn't mention what the cols variable (third parameter) does. Well, If your sub window is wide enough, you can opt to display more than one item per row. This can be specified in the cols variable. To make things simpler, the following example doesn't show descriptions for the items.

**Example 21. Milt Columnar Menus Example**

#include <curses.h>
#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1", "Choice 2", "Choice 3", "Choice 4", "Choice 5",
			"Choice 6", "Choice 7", "Choice 8", "Choice 9", "Choice 10",
			"Choice 11", "Choice 12", "Choice 13", "Choice 14", "Choice 15",
			"Choice 16", "Choice 17", "Choice 18", "Choice 19", "Choice 20",
                        "Exit",
                        (char \*)NULL,
                  };

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        WINDOW \*my\_menu\_win;
        int n\_choices, i;
	
	/\* Initialize curses \*/
	initscr();
	start\_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_CYAN, COLOR\_BLACK);

	/\* Create items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
                my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);

	/\* Crate menu \*/
	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Set menu option not to show the description \*/
	menu\_opts\_off(my\_menu, O\_SHOWDESC);

	/\* Create the window to be associated with the menu \*/
        my\_menu\_win = newwin(10, 70, 4, 4);
        keypad(my\_menu\_win, TRUE);
     
	/\* Set main window and sub window \*/
        set\_menu\_win(my\_menu, my\_menu\_win);
        set\_menu\_sub(my\_menu, derwin(my\_menu\_win, 6, 68, 3, 1));
	set\_menu\_format(my\_menu, 5, 3);
	set\_menu\_mark(my\_menu, " \* ");

	/\* Print a border around the main window and print a title \*/
        box(my\_menu\_win, 0, 0);
	
	attron(COLOR\_PAIR(2));
	mvprintw(LINES - 3, 0, "Use PageUp and PageDown to scroll");
	mvprintw(LINES - 2, 0, "Use Arrow Keys to navigate (F1 to Exit)");
	attroff(COLOR\_PAIR(2));
	refresh();

	/\* Post the menu \*/
	post\_menu(my\_menu);
	wrefresh(my\_menu\_win);
	
	while((c = wgetch(my\_menu\_win)) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
			case KEY\_LEFT:
				menu\_driver(my\_menu, REQ\_LEFT\_ITEM);
				break;
			case KEY\_RIGHT:
				menu\_driver(my\_menu, REQ\_RIGHT\_ITEM);
				break;
			case KEY\_NPAGE:
				menu\_driver(my\_menu, REQ\_SCR\_DPAGE);
				break;
			case KEY\_PPAGE:
				menu\_driver(my\_menu, REQ\_SCR\_UPAGE);
				break;
		}
                wrefresh(my\_menu\_win);
	}	

	/\* Unpost and free all the memory taken up \*/
        unpost\_menu(my\_menu);
        free\_menu(my\_menu);
        for(i = 0; i < n\_choices; ++i)
                free\_item(my\_items\[i\]);
	endwin();
}

Watch the function call to set\_menu\_format(). It specifies the number of columns to be 3, thus displaying 3 items per row. We have also switched off the showing descriptions with the function menu\_opts\_off(). There are couple of functions set\_menu\_opts(), menu\_opts\_on() and menu\_opts() which can be used to manipulate menu options. The following menu options can be specified.

       O\_ONEVALUE
            Only one item can be selected for this menu.

       O\_SHOWDESC
            Display  the  item  descriptions  when  the  menu  is
            posted.

       O\_ROWMAJOR
            Display the menu in row-major order.

       O\_IGNORECASE
            Ignore the case when pattern-matching.

       O\_SHOWMATCH
            Move the cursor to within the item  name  while  pat­
            tern-matching.

       O\_NONCYCLIC
            Don't   wrap   around  next-item  and  previous-item,
            requests to the other end of the menu.

All options are on by default. You can switch specific attributes on or off with menu\_opts\_on() and menu\_opts\_off() functions. You can also use set\_menu\_opts() to directly specify the options. The argument to this function should be a OR ed value of some of those above constants. The function menu\_opts() can be used to find out a menu's present options.

* * *

17.7. Multi Valued Menus
------------------------

You might be wondering what if you switch off the option O\_ONEVALUE. Then the menu becomes multi-valued. That means you can select more than one item. This brings us to the request REQ\_TOGGLE\_ITEM. Let's see it in action.

**Example 22. Multi Valued Menus example**

#include <curses.h>
#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
			"Choice 5",
			"Choice 6",
			"Choice 7",
                        "Exit",
                  };

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        int n\_choices, i;
	ITEM \*cur\_item;
	
	/\* Initialize curses \*/	
	initscr();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);

	/\* Initialize items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices + 1, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
                my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);
	my\_items\[n\_choices\] = (ITEM \*)NULL;

	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Make the menu multi valued \*/
	menu\_opts\_off(my\_menu, O\_ONEVALUE);

	mvprintw(LINES - 3, 0, "Use <SPACE> to select or unselect an item.");
	mvprintw(LINES - 2, 0, "<ENTER> to see presently selected items(F1 to Exit)");
	post\_menu(my\_menu);
	refresh();

	while((c = getch()) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
			case ' ':
				menu\_driver(my\_menu, REQ\_TOGGLE\_ITEM);
				break;
			case 10:	/\* Enter \*/
			{	char temp\[200\];
				ITEM \*\*items;

				items = menu\_items(my\_menu);
				temp\[0\] = '\\0';
				for(i = 0; i < item\_count(my\_menu); ++i)
					if(item\_value(items\[i\]) == TRUE)
					{	strcat(temp, item\_name(items\[i\]));
						strcat(temp, " ");
					}
				move(20, 0);
				clrtoeol();
				mvprintw(20, 0, temp);
				refresh();
			}
			break;
		}
	}	

	free\_item(my\_items\[0\]);
        free\_item(my\_items\[1\]);
	free\_menu(my\_menu);
	endwin();
}
	

Whew, A lot of new functions. Let's take them one after another. Firstly, the REQ\_TOGGLE\_ITEM. In a multi-valued menu, the user should be allowed to select or un select more than one item. The request REQ\_TOGGLE\_ITEM toggles the present selection. In this case when space is pressed REQ\_TOGGLE\_ITEM request is sent to menu\_driver to achieve the result.

Now when the user presses <ENTER> we show the items he presently selected. First we find out the items associated with the menu using the function menu\_items(). Then we loop through the items to find out if the item is selected or not. The function item\_value() returns TRUE if an item is selected. The function item\_count() returns the number of items in the menu. The item name can be found with item\_name(). You can also find the description associated with an item using item\_description().

* * *

17.8. Menu Options
------------------

Well, by this time you must be itching for some difference in your menu, with lots of functionality. I know. You want Colors !!!. You want to create nice menus similar to those text mode [dos games](http://www.jersey.net/~debinjoe/games/). The functions set\_menu\_fore() and set\_menu\_back() can be used to change the attribute of the selected item and unselected item. The names are misleading. They don't change menu's foreground or background which would have been useless.

The function set\_menu\_grey() can be used to set the display attribute for the non-selectable items in the menu. This brings us to the interesting option for an item the one and only O\_SELECTABLE. We can turn it off by the function item\_opts\_off() and after that that item is not selectable. It's like a grayed item in those fancy windows menus. Let's put these concepts in practice with this example

**Example 23. Menu Options example**

#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
			"Choice 5",
			"Choice 6",
			"Choice 7",
                        "Exit",
                  };

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        int n\_choices, i;
	ITEM \*cur\_item;
	
	/\* Initialize curses \*/	
	initscr();
	start\_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_GREEN, COLOR\_BLACK);
	init\_pair(3, COLOR\_MAGENTA, COLOR\_BLACK);

	/\* Initialize items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices + 1, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
                my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);
	my\_items\[n\_choices\] = (ITEM \*)NULL;
	item\_opts\_off(my\_items\[3\], O\_SELECTABLE);
	item\_opts\_off(my\_items\[6\], O\_SELECTABLE);

	/\* Create menu \*/
	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Set fore ground and back ground of the menu \*/
	set\_menu\_fore(my\_menu, COLOR\_PAIR(1) | A\_REVERSE);
	set\_menu\_back(my\_menu, COLOR\_PAIR(2));
	set\_menu\_grey(my\_menu, COLOR\_PAIR(3));

	/\* Post the menu \*/
	mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (F1 to Exit)");
	post\_menu(my\_menu);
	refresh();

	while((c = getch()) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
			case 10: /\* Enter \*/
				move(20, 0);
				clrtoeol();
				mvprintw(20, 0, "Item selected is : %s", 
						item\_name(current\_item(my\_menu)));
				pos\_menu\_cursor(my\_menu);
				break;
		}
	}	
	unpost\_menu(my\_menu);
	for(i = 0; i < n\_choices; ++i)
		free\_item(my\_items\[i\]);
	free\_menu(my\_menu);
	endwin();
}
	

* * *

17.9. The useful User Pointer
-----------------------------

We can associate a user pointer with each item in the menu. It works the same way as user pointer in panels. It's not touched by menu system. You can store any thing you like in that. I usually use it to store the function to be executed when the menu option is chosen (It's selected and may be the user pressed <ENTER>);

**Example 24. Menu User Pointer Usage**

#include <curses.h>
#include <menu.h>

#define ARRAY\_SIZE(a) (sizeof(a) / sizeof(a\[0\]))
#define CTRLD 	4

char \*choices\[\] = {
                        "Choice 1",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
			"Choice 5",
			"Choice 6",
			"Choice 7",
                        "Exit",
                  };
void func(char \*name);

int main()
{	ITEM \*\*my\_items;
	int c;				
	MENU \*my\_menu;
        int n\_choices, i;
	ITEM \*cur\_item;
	
	/\* Initialize curses \*/	
	initscr();
	start\_color();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init\_pair(1, COLOR\_RED, COLOR\_BLACK);
	init\_pair(2, COLOR\_GREEN, COLOR\_BLACK);
	init\_pair(3, COLOR\_MAGENTA, COLOR\_BLACK);

	/\* Initialize items \*/
        n\_choices = ARRAY\_SIZE(choices);
        my\_items = (ITEM \*\*)calloc(n\_choices + 1, sizeof(ITEM \*));
        for(i = 0; i < n\_choices; ++i)
	{       my\_items\[i\] = new\_item(choices\[i\], choices\[i\]);
		/\* Set the user pointer \*/
		set\_item\_userptr(my\_items\[i\], func);
	}
	my\_items\[n\_choices\] = (ITEM \*)NULL;

	/\* Create menu \*/
	my\_menu = new\_menu((ITEM \*\*)my\_items);

	/\* Post the menu \*/
	mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (F1 to Exit)");
	post\_menu(my\_menu);
	refresh();

	while((c = getch()) != KEY\_F(1))
	{       switch(c)
	        {	case KEY\_DOWN:
				menu\_driver(my\_menu, REQ\_DOWN\_ITEM);
				break;
			case KEY\_UP:
				menu\_driver(my\_menu, REQ\_UP\_ITEM);
				break;
			case 10: /\* Enter \*/
			{	ITEM \*cur;
				void (\*p)(char \*);

				cur = current\_item(my\_menu);
				p = item\_userptr(cur);
				p((char \*)item\_name(cur));
				pos\_menu\_cursor(my\_menu);
				break;
			}
			break;
		}
	}	
	unpost\_menu(my\_menu);
	for(i = 0; i < n\_choices; ++i)
		free\_item(my\_items\[i\]);
	free\_menu(my\_menu);
	endwin();
}

void func(char \*name)
{	move(20, 0);
	clrtoeol();
	mvprintw(20, 0, "Item selected is : %s", name);
}	

* * *

18\. Forms Library
==================

Well. If you have seen those forms on web pages which take input from users and do various kinds of things, you might be wondering how would any one create such forms in text mode display. It's quite difficult to write those nifty forms in plain ncurses. Forms library tries to provide a basic frame work to build and maintain forms with ease. It has lot of features(functions) which manage validation, dynamic expansion of fields etc.. Let's see it in full flow.

A form is a collection of fields; each field can be either a label(static text) or a data-entry location. The forms also library provides functions to divide forms into multiple pages.

* * *

18.1. The Basics
----------------

Forms are created in much the same way as menus. First the fields related to the form are created with new\_field(). You can set options for the fields, so that they can be displayed with some fancy attributes, validated before the field looses focus etc.. Then the fields are attached to form. After this, the form can be posted to display and is ready to receive inputs. On the similar lines to menu\_driver(), the form is manipulated with form\_driver(). We can send requests to form\_driver to move focus to a certain field, move cursor to end of the field etc.. After the user enters values in the fields and validation done, form can be unposted and memory allocated can be freed.

The general flow of control of a forms program looks like this.

1.  Initialize curses
    
2.  Create fields using new\_field(). You can specify the height and width of the field, and its position on the form.
    
3.  Create the forms with new\_form() by specifying the fields to be attached with.
    
4.  Post the form with form\_post() and refresh the screen.
    
5.  Process the user requests with a loop and do necessary updates to form with form\_driver.
    
6.  Unpost the menu with form\_unpost()
    
7.  Free the memory allocated to menu by free\_form()
    
8.  Free the memory allocated to the items with free\_field()
    
9.  End curses
    

As you can see, working with forms library is much similar to handling menu library. The following examples will explore various aspects of form processing. Let's start the journey with a simple example. first.

* * *

18.2. Compiling With the Forms Library
--------------------------------------

To use forms library functions, you have to include form.h and to link the program with forms library the flag -lform should be added along with -lncurses in that order.

    #include <form.h>
    .
    .
    .

    compile and link: gcc <program file> -lform -lncurses

**Example 25. Forms Basics**

#include <form.h>

int main()
{	FIELD \*field\[3\];
	FORM  \*my\_form;
	int ch;
	
	/\* Initialize curses \*/
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize the fields \*/
	field\[0\] = new\_field(1, 10, 4, 18, 0, 0);
	field\[1\] = new\_field(1, 10, 6, 18, 0, 0);
	field\[2\] = NULL;

	/\* Set field options \*/
	set\_field\_back(field\[0\], A\_UNDERLINE); 	/\* Print a line for the option 	\*/
	field\_opts\_off(field\[0\], O\_AUTOSKIP);  	/\* Don't go to next field when this \*/
						/\* Field is filled up 		\*/
	set\_field\_back(field\[1\], A\_UNDERLINE); 
	field\_opts\_off(field\[1\], O\_AUTOSKIP);

	/\* Create the form and post it \*/
	my\_form = new\_form(field);
	post\_form(my\_form);
	refresh();
	
	mvprintw(4, 10, "Value 1:");
	mvprintw(6, 10, "Value 2:");
	refresh();

	/\* Loop through to get user requests \*/
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_DOWN:
				/\* Go to next field \*/
				form\_driver(my\_form, REQ\_NEXT\_FIELD);
				/\* Go to the end of the present buffer \*/
				/\* Leaves nicely at the last character \*/
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			case KEY\_UP:
				/\* Go to previous field \*/
				form\_driver(my\_form, REQ\_PREV\_FIELD);
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			default:
				/\* If this is a normal character, it gets \*/
				/\* Printed				  \*/	
				form\_driver(my\_form, ch);
				break;
		}
	}

	/\* Un post form and free the memory \*/
	unpost\_form(my\_form);
	free\_form(my\_form);
	free\_field(field\[0\]);
	free\_field(field\[1\]); 

	endwin();
	return 0;
}

Above example is pretty straight forward. It creates two fields with new\_field(). new\_field() takes height, width, starty, startx, number of offscreen rows and number of additional working buffers. The fifth argument number of offscreen rows specifies how much of the field to be shown. If it is zero, the entire field is always displayed otherwise the form will be scrollable when the user accesses not displayed parts of the field. The forms library allocates one buffer per field to store the data user enters. Using the last parameter to new\_field() we can specify it to allocate some additional buffers. These can be used for any purpose you like.

After creating the fields, back ground attribute of both of them is set to an underscore with set\_field\_back(). The AUTOSKIP option is turned off using field\_opts\_off(). If this option is turned on, focus will move to the next field in the form once the active field is filled up completely.

After attaching the fields to the form, it is posted. Here on, user inputs are processed in the while loop, by making corresponding requests to form\_driver. The details of all the requests to the form\_driver() are explained later.

* * *

18.3. Playing with Fields
-------------------------

Each form field is associated with a lot of attributes. They can be manipulated to get the required effect and to have fun !!!. So why wait?

* * *

### 18.3.1. Fetching Size and Location of Field

The parameters we have given at the time of creation of a field can be retrieved with field\_info(). It returns height, width, starty, startx, number of offscreen rows, and number of additional buffers into the parameters given to it. It is a sort of inverse of new\_field().

int field\_info(     FIELD \*field,              /\* field from which to fetch \*/
                    int \*height, \*int width,   /\* field size \*/ 
                    int \*top, int \*left,       /\* upper left corner \*/
                    int \*offscreen,            /\* number of offscreen rows \*/
                    int \*nbuf);                /\* number of working buffers \*/

* * *

### 18.3.2. Moving the field

The location of the field can be moved to a different position with move\_field().

int move\_field(    FIELD \*field,              /\* field to alter \*/
                   int top, int left);        /\* new upper-left corner \*/

As usual, the changed position can be queried with field\_infor().

* * *

### 18.3.3. Field Justification

The justification to be done for the field can be fixed using the function set\_field\_just().

    int set\_field\_just(FIELD \*field,          /\* field to alter \*/
               int justmode);         /\* mode to set \*/
    int field\_just(FIELD \*field);          /\* fetch justify mode of field \*/

The justification mode valued accepted and returned by these functions are NO\_JUSTIFICATION, JUSTIFY\_RIGHT, JUSTIFY\_LEFT, or JUSTIFY\_CENTER.

* * *

### 18.3.4. Field Display Attributes

As you have seen, in the above example, display attribute for the fields can be set with set\_field\_fore() and setfield\_back(). These functions set foreground and background attribute of the fields. You can also specify a pad character which will be filled in the unfilled portion of the field. The pad character is set with a call to set\_field\_pad(). Default pad value is a space. The functions field\_fore(), field\_back, field\_pad() can be used to query the present foreground, background attributes and pad character for the field. The following list gives the usage of functions.

int set\_field\_fore(FIELD \*field,        /\* field to alter \*/
                   chtype attr);        /\* attribute to set \*/ 

chtype field\_fore(FIELD \*field);        /\* field to query \*/
                                        /\* returns foreground attribute \*/

int set\_field\_back(FIELD \*field,        /\* field to alter \*/
                   chtype attr);        /\* attribute to set \*/ 

chtype field\_back(FIELD \*field);        /\* field to query \*/
                                        /\* returns background attribute \*/

int set\_field\_pad(FIELD \*field,         /\* field to alter \*/
                  int pad);             /\* pad character to set \*/ 

chtype field\_pad(FIELD \*field);         /\* field to query \*/  
                                        /\* returns present pad character \*/

Though above functions seem quite simple, using colors with set\_field\_fore() may be frustrating in the beginning. Let me first explain about foreground and background attributes of a field. The foreground attribute is associated with the character. That means a character in the field is printed with the attribute you have set with set\_field\_fore(). Background attribute is the attribute used to fill background of field, whether any character is there or not. So what about colors? Since colors are always defined in pairs, what is the right way to display colored fields? Here's an example clarifying color attributes.

**Example 26. Form Attributes example**

#include <form.h>

int main()
{	FIELD \*field\[3\];
	FORM  \*my\_form;
	int ch;
	
	/\* Initialize curses \*/
	initscr();
	start\_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize few color pairs \*/
	init\_pair(1, COLOR\_WHITE, COLOR\_BLUE);
	init\_pair(2, COLOR\_WHITE, COLOR\_BLUE);

	/\* Initialize the fields \*/
	field\[0\] = new\_field(1, 10, 4, 18, 0, 0);
	field\[1\] = new\_field(1, 10, 6, 18, 0, 0);
	field\[2\] = NULL;

	/\* Set field options \*/
	set\_field\_fore(field\[0\], COLOR\_PAIR(1));/\* Put the field with blue background \*/
	set\_field\_back(field\[0\], COLOR\_PAIR(2));/\* and white foreground (characters \*/
						/\* are printed in white 	\*/
	field\_opts\_off(field\[0\], O\_AUTOSKIP);  	/\* Don't go to next field when this \*/
						/\* Field is filled up 		\*/
	set\_field\_back(field\[1\], A\_UNDERLINE); 
	field\_opts\_off(field\[1\], O\_AUTOSKIP);

	/\* Create the form and post it \*/
	my\_form = new\_form(field);
	post\_form(my\_form);
	refresh();
	
	set\_current\_field(my\_form, field\[0\]); /\* Set focus to the colored field \*/
	mvprintw(4, 10, "Value 1:");
	mvprintw(6, 10, "Value 2:");
	mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");
	refresh();

	/\* Loop through to get user requests \*/
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_DOWN:
				/\* Go to next field \*/
				form\_driver(my\_form, REQ\_NEXT\_FIELD);
				/\* Go to the end of the present buffer \*/
				/\* Leaves nicely at the last character \*/
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			case KEY\_UP:
				/\* Go to previous field \*/
				form\_driver(my\_form, REQ\_PREV\_FIELD);
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			default:
				/\* If this is a normal character, it gets \*/
				/\* Printed				  \*/	
				form\_driver(my\_form, ch);
				break;
		}
	}

	/\* Un post form and free the memory \*/
	unpost\_form(my\_form);
	free\_form(my\_form);
	free\_field(field\[0\]);
	free\_field(field\[1\]); 

	endwin();
	return 0;
}

Play with the color pairs and try to understand the foreground and background attributes. In my programs using color attributes, I usually set only the background with set\_field\_back(). Curses simply doesn't allow defining individual color attributes.

* * *

### 18.3.5. Field Option Bits

There is also a large collection of field option bits you can set to control various aspects of forms processing. You can manipulate them with these functions:

int set\_field\_opts(FIELD \*field,          /\* field to alter \*/
                   int attr);             /\* attribute to set \*/ 

int field\_opts\_on(FIELD \*field,           /\* field to alter \*/
                  int attr);              /\* attributes to turn on \*/ 

int field\_opts\_off(FIELD \*field,          /\* field to alter \*/
                  int attr);              /\* attributes to turn off \*/ 

int field\_opts(FIELD \*field);             /\* field to query \*/ 

The function set\_field\_opts() can be used to directly set attributes of a field or you can choose to switch a few attributes on and off with field\_opts\_on() and field\_opts\_off() selectively. Anytime you can query the attributes of a field with field\_opts(). The following is the list of available options. By default, all options are on.

O\_VISIBLE

Controls whether the field is visible on the screen. Can be used during form processing to hide or pop up fields depending on the value of parent fields.

O\_ACTIVE

Controls whether the field is active during forms processing (i.e. visited by form navigation keys). Can be used to make labels or derived fields with buffer values alterable by the forms application, not the user.

O\_PUBLIC

Controls whether data is displayed during field entry. If this option is turned off on a field, the library will accept and edit data in that field, but it will not be displayed and the visible field cursor will not move. You can turn off the O\_PUBLIC bit to define password fields.

O\_EDIT

Controls whether the field's data can be modified. When this option is off, all editing requests except REQ\_PREV\_CHOICE and REQ\_NEXT\_CHOICEwill fail. Such read-only fields may be useful for help messages.

O\_WRAP

Controls word-wrapping in multi-line fields. Normally, when any character of a (blank-separated) word reaches the end of the current line, the entire word is wrapped to the next line (assuming there is one). When this option is off, the word will be split across the line break.

O\_BLANK

Controls field blanking. When this option is on, entering a character at the first field position erases the entire field (except for the just-entered character).

O\_AUTOSKIP

Controls automatic skip to next field when this one fills. Normally, when the forms user tries to type more data into a field than will fit, the editing location jumps to next field. When this option is off, the user's cursor will hang at the end of the field. This option is ignored in dynamic fields that have not reached their size limit.

O\_NULLOK

Controls whether validation is applied to blank fields. Normally, it is not; the user can leave a field blank without invoking the usual validation check on exit. If this option is off on a field, exit from it will invoke a validation check.

O\_PASSOK

Controls whether validation occurs on every exit, or only after the field is modified. Normally the latter is true. Setting O\_PASSOK may be useful if your field's validation function may change during forms processing.

O\_STATIC

Controls whether the field is fixed to its initial dimensions. If you turn this off, the field becomes dynamic and will stretch to fit entered data.

A field's options cannot be changed while the field is currently selected. However, options may be changed on posted fields that are not current.

The option values are bit-masks and can be composed with logical-or in the obvious way. You have seen the usage of switching off O\_AUTOSKIP option. The following example clarifies usage of some more options. Other options are explained where appropriate.

**Example 27. Field Options Usage example**

#include <form.h>

#define STARTX 15
#define STARTY 4
#define WIDTH 25

#define N\_FIELDS 3

int main()
{	FIELD \*field\[N\_FIELDS\];
	FORM  \*my\_form;
	int ch, i;
	
	/\* Initialize curses \*/
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize the fields \*/
	for(i = 0; i < N\_FIELDS - 1; ++i)
		field\[i\] = new\_field(1, WIDTH, STARTY + i \* 2, STARTX, 0, 0);
	field\[N\_FIELDS - 1\] = NULL;

	/\* Set field options \*/
	set\_field\_back(field\[1\], A\_UNDERLINE); 	/\* Print a line for the option 	\*/
	
	field\_opts\_off(field\[0\], O\_ACTIVE); /\* This field is a static label \*/
	field\_opts\_off(field\[1\], O\_PUBLIC); /\* This filed is like a password field\*/
	field\_opts\_off(field\[1\], O\_AUTOSKIP); /\* To avoid entering the same field \*/
					      /\* after last character is entered \*/
	
	/\* Create the form and post it \*/
	my\_form = new\_form(field);
	post\_form(my\_form);
	refresh();
	
	set\_field\_just(field\[0\], JUSTIFY\_CENTER); /\* Center Justification \*/
	set\_field\_buffer(field\[0\], 0, "This is a static Field"); 
						  /\* Initialize the field  \*/
	mvprintw(STARTY, STARTX - 10, "Field 1:");
	mvprintw(STARTY + 2, STARTX - 10, "Field 2:");
	refresh();

	/\* Loop through to get user requests \*/
	while((ch = getch()) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_DOWN:
				/\* Go to next field \*/
				form\_driver(my\_form, REQ\_NEXT\_FIELD);
				/\* Go to the end of the present buffer \*/
				/\* Leaves nicely at the last character \*/
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			case KEY\_UP:
				/\* Go to previous field \*/
				form\_driver(my\_form, REQ\_PREV\_FIELD);
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			default:
				/\* If this is a normal character, it gets \*/
				/\* Printed				  \*/	
				form\_driver(my\_form, ch);
				break;
		}
	}

	/\* Un post form and free the memory \*/
	unpost\_form(my\_form);
	free\_form(my\_form);
	free\_field(field\[0\]);
	free\_field(field\[1\]); 

	endwin();
	return 0;
}

This example, though useless, shows the usage of options. If used properly, they can present information very effectively in a form. The second field being not O\_PUBLIC, does not show the characters you are typing.

* * *

### 18.3.6. Field Status

The field status specifies whether the field has got edited or not. It is initially set to FALSE and when user enters something and the data buffer gets modified it becomes TRUE. So a field's status can be queried to find out whether it has been modified or not. The following functions can assist in those operations.

int set\_field\_status(FIELD \*field,      /\* field to alter \*/
                   int status);         /\* status to set \*/

int field\_status(FIELD \*field);         /\* fetch status of field \*/

It's better to check the field's status only after after leaving the field, as data buffer might not have been updated yet as the validation is still due. To guarantee that right status is returned, call field\_status() either (1) in the field's exit validation check routine, (2) from the field's or form's initialization or termination hooks, or (3) just after a REQ\_VALIDATION request has been processed by the forms driver

* * *

### 18.3.7. Field User Pointer

Every field structure contains one pointer that can be used by the user for various purposes. It is not touched by forms library and can be used for any purpose by the user. The following functions set and fetch user pointer.

int set\_field\_userptr(FIELD \*field,   
           char \*userptr);      /\* the user pointer you wish to associate \*/
                                /\* with the field    \*/

char \*field\_userptr(FIELD \*field);      /\* fetch user pointer of the field \*/

* * *

### 18.3.8. Variable-Sized Fields

If you want a dynamically changing field with variable width, this is the feature you want to put to full use. This will allow the user to enter more data than the original size of the field and let the field grow. According to the field orientation it will scroll horizontally or vertically to incorporate the new data.

To make a field dynamically growable, the option O\_STATIC should be turned off. This can be done with a

    field\_opts\_off(field\_pointer, O\_STATIC);

But it's usually not advisable to allow a field to grow infinitely. You can set a maximum limit to the growth of the field with

int set\_max\_field(FIELD \*field,    /\* Field on which to operate \*/
                  int max\_growth); /\* maximum growth allowed for the field \*/

The field info for a dynamically growable field can be retrieved by

int dynamic\_field\_info( FIELD \*field,     /\* Field on which to operate \*/
            int   \*prows,     /\* number of rows will be filled in this \*/
            int   \*pcols,     /\* number of columns will be filled in this\*/
            int   \*pmax)      /\* maximum allowable growth will be filled \*/
                              /\* in this \*/

Though field\_info work as usual, it is advisable to use this function to get the proper attributes of a dynamically growable field.

Recall the library routine new\_field; a new field created with height set to one will be defined to be a one line field. A new field created with height greater than one will be defined to be a multi line field.

A one line field with O\_STATIC turned off (dynamically growable field) will contain a single fixed row, but the number of columns can increase if the user enters more data than the initial field will hold. The number of columns displayed will remain fixed and the additional data will scroll horizontally.

A multi line field with O\_STATIC turned off (dynamically growable field) will contain a fixed number of columns, but the number of rows can increase if the user enters more data than the initial field will hold. The number of rows displayed will remain fixed and the additional data will scroll vertically.

The above two paragraphs pretty much describe a dynamically growable field's behavior. The way other parts of forms library behaves is described below:

1.  The field option O\_AUTOSKIP will be ignored if the option O\_STATIC is off and there is no maximum growth specified for the field. Currently, O\_AUTOSKIP generates an automatic REQ\_NEXT\_FIELD form driver request when the user types in the last character position of a field. On a growable field with no maximum growth specified, there is no last character position. If a maximum growth is specified, the O\_AUTOSKIP option will work as normal if the field has grown to its maximum size.
    
2.  The field justification will be ignored if the option O\_STATIC is off. Currently, set\_field\_just can be used to JUSTIFY\_LEFT, JUSTIFY\_RIGHT, JUSTIFY\_CENTER the contents of a one line field. A growable one line field will, by definition, grow and scroll horizontally and may contain more data than can be justified. The return from field\_just will be unchanged.
    
3.  The overloaded form driver request REQ\_NEW\_LINE will operate the same way regardless of the O\_NL\_OVERLOAD form option if the field option O\_STATIC is off and there is no maximum growth specified for the field. Currently, if the form option O\_NL\_OVERLOAD is on, REQ\_NEW\_LINE implicitly generates a REQ\_NEXT\_FIELD if called from the last line of a field. If a field can grow without bound, there is no last line, so REQ\_NEW\_LINE will never implicitly generate a REQ\_NEXT\_FIELD. If a maximum growth limit is specified and the O\_NL\_OVERLOAD form option is on, REQ\_NEW\_LINE will only implicitly generate REQ\_NEXT\_FIELD if the field has grown to its maximum size and the user is on the last line.
    
4.  The library call dup\_field will work as usual; it will duplicate the field, including the current buffer size and contents of the field being duplicated. Any specified maximum growth will also be duplicated.
    
5.  The library call link\_field will work as usual; it will duplicate all field attributes and share buffers with the field being linked. If the O\_STATIC field option is subsequently changed by a field sharing buffers, how the system reacts to an attempt to enter more data into the field than the buffer will currently hold will depend on the setting of the option in the current field.
    
6.  The library call field\_info will work as usual; the variable nrow will contain the value of the original call to new\_field. The user should use dynamic\_field\_info, described above, to query the current size of the buffer.
    

Some of the above points make sense only after explaining form driver. We will be looking into that in next few sections.

* * *

18.4. Form Windows
------------------

The form windows concept is pretty much similar to menu windows. Every form is associated with a main window and a sub window. The form main window displays any title or border associated or whatever the user wishes. Then the sub window contains all the fields and displays them according to their position. This gives the flexibility of manipulating fancy form displaying very easily.

Since this is pretty much similar to menu windows, I am providing an example with out much explanation. The functions are similar and they work the same way.

**Example 28. Form Windows Example**

#include <form.h>

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color);

int main()
{
	FIELD \*field\[3\];
	FORM  \*my\_form;
	WINDOW \*my\_form\_win;
	int ch, rows, cols;
	
	/\* Initialize curses \*/
	initscr();
	start\_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/\* Initialize few color pairs \*/
   	init\_pair(1, COLOR\_RED, COLOR\_BLACK);

	/\* Initialize the fields \*/
	field\[0\] = new\_field(1, 10, 6, 1, 0, 0);
	field\[1\] = new\_field(1, 10, 8, 1, 0, 0);
	field\[2\] = NULL;

	/\* Set field options \*/
	set\_field\_back(field\[0\], A\_UNDERLINE);
	field\_opts\_off(field\[0\], O\_AUTOSKIP); /\* Don't go to next field when this \*/
					      /\* Field is filled up 		\*/
	set\_field\_back(field\[1\], A\_UNDERLINE); 
	field\_opts\_off(field\[1\], O\_AUTOSKIP);
	
	/\* Create the form and post it \*/
	my\_form = new\_form(field);
	
	/\* Calculate the area required for the form \*/
	scale\_form(my\_form, &rows, &cols);

	/\* Create the window to be associated with the form \*/
        my\_form\_win = newwin(rows + 4, cols + 4, 4, 4);
        keypad(my\_form\_win, TRUE);

	/\* Set main window and sub window \*/
        set\_form\_win(my\_form, my\_form\_win);
        set\_form\_sub(my\_form, derwin(my\_form\_win, rows, cols, 2, 2));

	/\* Print a border around the main window and print a title \*/
        box(my\_form\_win, 0, 0);
	print\_in\_middle(my\_form\_win, 1, 0, cols + 4, "My Form", COLOR\_PAIR(1));
	
	post\_form(my\_form);
	wrefresh(my\_form\_win);

	mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");
	refresh();

	/\* Loop through to get user requests \*/
	while((ch = wgetch(my\_form\_win)) != KEY\_F(1))
	{	switch(ch)
		{	case KEY\_DOWN:
				/\* Go to next field \*/
				form\_driver(my\_form, REQ\_NEXT\_FIELD);
				/\* Go to the end of the present buffer \*/
				/\* Leaves nicely at the last character \*/
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			case KEY\_UP:
				/\* Go to previous field \*/
				form\_driver(my\_form, REQ\_PREV\_FIELD);
				form\_driver(my\_form, REQ\_END\_LINE);
				break;
			default:
				/\* If this is a normal character, it gets \*/
				/\* Printed				  \*/	
				form\_driver(my\_form, ch);
				break;
		}
	}

	/\* Un post form and free the memory \*/
	unpost\_form(my\_form);
	free\_form(my\_form);
	free\_field(field\[0\]);
	free\_field(field\[1\]); 

	endwin();
	return 0;
}

void print\_in\_middle(WINDOW \*win, int starty, int startx, int width, char \*string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

* * *

18.5. Field Validation
----------------------

By default, a field will accept any data input by the user. It is possible to attach validation to the field. Then any attempt by the user to leave the field, while it contains data that doesn't match the validation type will fail. Some validation types also have a character-validity check for each time a character is entered in the field.

Validation can be attached to a field with the following function.

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   FIELDTYPE \*ftype,      /\* type to associate \*/
                   ...);                  /\* additional arguments\*/

Once set, the validation type for a field can be queried with

FIELDTYPE \*field\_type(FIELD \*field);      /\* field to query \*/

The form driver validates the data in a field only when data is entered by the end-user. Validation does not occur when

*   the application program changes the field value by calling set\_field\_buffer.
    
*   linked field values are changed indirectly -- by changing the field to which they are linked
    

The following are the pre-defined validation types. You can also specify custom validation, though it's a bit tricky and cumbersome.

TYPE\_ALPHA
===========

This field type accepts alphabetic data; no blanks, no digits, no special characters (this is checked at character-entry time). It is set up with:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_ALPHA,            /\* type to associate \*/
                   int width);            /\* maximum width of field \*/

The width argument sets a minimum width of data. The user has to enter at-least width number of characters before he can leave the field. Typically you'll want to set this to the field width; if it's greater than the field width, the validation check will always fail. A minimum width of zero makes field completion optional.

TYPE\_ALNUM
===========

This field type accepts alphabetic data and digits; no blanks, no special characters (this is checked at character-entry time). It is set up with:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_ALNUM,            /\* type to associate \*/
                   int width);            /\* maximum width of field \*/

The width argument sets a minimum width of data. As with TYPE\_ALPHA, typically you'll want to set this to the field width; if it's greater than the field width, the validation check will always fail. A minimum width of zero makes field completion optional.

TYPE\_ENUM
==========

This type allows you to restrict a field's values to be among a specified set of string values (for example, the two-letter postal codes for U.S. states). It is set up with:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_ENUM,             /\* type to associate \*/
                   char \*\*valuelist;      /\* list of possible values \*/
                   int checkcase;         /\* case-sensitive? \*/
                   int checkunique);      /\* must specify uniquely? \*/

The valuelist parameter must point at a NULL-terminated list of valid strings. The checkcase argument, if true, makes comparison with the string case-sensitive.

When the user exits a TYPE\_ENUM field, the validation procedure tries to complete the data in the buffer to a valid entry. If a complete choice string has been entered, it is of course valid. But it is also possible to enter a prefix of a valid string and have it completed for you.

By default, if you enter such a prefix and it matches more than one value in the string list, the prefix will be completed to the first matching value. But the checkunique argument, if true, requires prefix matches to be unique in order to be valid.

The REQ\_NEXT\_CHOICE and REQ\_PREV\_CHOICE input requests can be particularly useful with these fields.

TYPE\_INTEGER
=============

This field type accepts an integer. It is set up as follows:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_INTEGER,          /\* type to associate \*/
                   int padding,           /\* # places to zero-pad to \*/
                   int vmin, int vmax);   /\* valid range \*/

Valid characters consist of an optional leading minus and digits. The range check is performed on exit. If the range maximum is less than or equal to the minimum, the range is ignored.

If the value passes its range check, it is padded with as many leading zero digits as necessary to meet the padding argument.

A TYPE\_INTEGER value buffer can conveniently be interpreted with the C library function atoi(3).

TYPE\_NUMERIC
=============

This field type accepts a decimal number. It is set up as follows:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_NUMERIC,          /\* type to associate \*/
                   int padding,           /\* # places of precision \*/
                   int vmin, int vmax);   /\* valid range \*/

Valid characters consist of an optional leading minus and digits. possibly including a decimal point. The range check is performed on exit. If the range maximum is less than or equal to the minimum, the range is ignored.

If the value passes its range check, it is padded with as many trailing zero digits as necessary to meet the padding argument.

A TYPE\_NUMERIC value buffer can conveniently be interpreted with the C library function atof(3).

TYPE\_REGEXP
============

This field type accepts data matching a regular expression. It is set up as follows:

int set\_field\_type(FIELD \*field,          /\* field to alter \*/
                   TYPE\_REGEXP,           /\* type to associate \*/
                   char \*regexp);         /\* expression to match \*/

The syntax for regular expressions is that of regcomp(3). The check for regular-expression match is performed on exit.

* * *

18.6. Form Driver: The work horse of the forms system
-----------------------------------------------------

As in the menu system, form\_driver() plays a very important role in forms system. All types of requests to forms system should be funneled through form\_driver().

int form\_driver(FORM \*form,     /\* form on which to operate     \*/
                int request)    /\* form request code         \*/

As you have seen some of the examples above, you have to be in a loop looking for user input and then decide whether it's a field data or a form request. The form requests are then passed to form\_driver() to do the work.

The requests roughly can be divided into following categories. Different requests and their usage is explained below:

* * *

### 18.6.1. Page Navigation Requests

These requests cause page-level moves through the form, triggering display of a new form screen. A form can be made of multiple pages. If you have a big form with lot of fields and logical sections, then you can divide the form into pages. The function set\_new\_page() to set a new page at the field specified.

int set\_new\_page(FIELD \*field,/\* Field at which page break to be set or unset \*/
         bool new\_page\_flag); /\* should be TRUE to put a break \*/

The following requests allow you to move to different pages

*   _REQ\_NEXT\_PAGE_ Move to the next form page.
    
*   _REQ\_PREV\_PAGE_ Move to the previous form page.
    
*   _REQ\_FIRST\_PAGE_ Move to the first form page.
    
*   _REQ\_LAST\_PAGE_ Move to the last form page.
    

These requests treat the list as cyclic; that is, REQ\_NEXT\_PAGE from the last page goes to the first, and REQ\_PREV\_PAGE from the first page goes to the last.

* * *

### 18.6.2. Inter-Field Navigation Requests

These requests handle navigation between fields on the same page.

*   _REQ\_NEXT\_FIELD_ Move to next field.
    
*   _REQ\_PREV\_FIELD_ Move to previous field.
    
*   _REQ\_FIRST\_FIELD_ Move to the first field.
    
*   _REQ\_LAST\_FIELD_ Move to the last field.
    
*   _REQ\_SNEXT\_FIELD_ Move to sorted next field.
    
*   _REQ\_SPREV\_FIELD_ Move to sorted previous field.
    
*   _REQ\_SFIRST\_FIELD_ Move to the sorted first field.
    
*   _REQ\_SLAST\_FIELD_ Move to the sorted last field.
    
*   _REQ\_LEFT\_FIELD_ Move left to field.
    
*   _REQ\_RIGHT\_FIELD_ Move right to field.
    
*   _REQ\_UP\_FIELD_ Move up to field.
    
*   _REQ\_DOWN\_FIELD_ Move down to field.
    

These requests treat the list of fields on a page as cyclic; that is, REQ\_NEXT\_FIELD from the last field goes to the first, and REQ\_PREV\_FIELD from the first field goes to the last. The order of the fields for these (and the REQ\_FIRST\_FIELD and REQ\_LAST\_FIELD requests) is simply the order of the field pointers in the form array (as set up by new\_form() or set\_form\_fields()

It is also possible to traverse the fields as if they had been sorted in screen-position order, so the sequence goes left-to-right and top-to-bottom. To do this, use the second group of four sorted-movement requests.

Finally, it is possible to move between fields using visual directions up, down, right, and left. To accomplish this, use the third group of four requests. Note, however, that the position of a form for purposes of these requests is its upper-left corner.

For example, suppose you have a multi-line field B, and two single-line fields A and C on the same line with B, with A to the left of B and C to the right of B. A REQ\_MOVE\_RIGHT from A will go to B only if A, B, and C all share the same first line; otherwise it will skip over B to C.

* * *

### 18.6.3. Intra-Field Navigation Requests

These requests drive movement of the edit cursor within the currently selected field.

*   _REQ\_NEXT\_CHAR_ Move to next character.
    
*   _REQ\_PREV\_CHAR_ Move to previous character.
    
*   _REQ\_NEXT\_LINE_ Move to next line.
    
*   _REQ\_PREV\_LINE_ Move to previous line.
    
*   _REQ\_NEXT\_WORD_ Move to next word.
    
*   _REQ\_PREV\_WORD_ Move to previous word.
    
*   _REQ\_BEG\_FIELD_ Move to beginning of field.
    
*   _REQ\_END\_FIELD_ Move to end of field.
    
*   _REQ\_BEG\_LINE_ Move to beginning of line.
    
*   _REQ\_END\_LINE_ Move to end of line.
    
*   _REQ\_LEFT\_CHAR_ Move left in field.
    
*   _REQ\_RIGHT\_CHAR_ Move right in field.
    
*   _REQ\_UP\_CHAR_ Move up in field.
    
*   _REQ\_DOWN\_CHAR_ Move down in field.
    

Each word is separated from the previous and next characters by whitespace. The commands to move to beginning and end of line or field look for the first or last non-pad character in their ranges.

* * *

### 18.6.4. Scrolling Requests

Fields that are dynamic and have grown and fields explicitly created with offscreen rows are scrollable. One-line fields scroll horizontally; multi-line fields scroll vertically. Most scrolling is triggered by editing and intra-field movement (the library scrolls the field to keep the cursor visible). It is possible to explicitly request scrolling with the following requests:

*   _REQ\_SCR\_FLINE_ Scroll vertically forward a line.
    
*   _REQ\_SCR\_BLINE_ Scroll vertically backward a line.
    
*   _REQ\_SCR\_FPAGE_ Scroll vertically forward a page.
    
*   _REQ\_SCR\_BPAGE_ Scroll vertically backward a page.
    
*   _REQ\_SCR\_FHPAGE_ Scroll vertically forward half a page.
    
*   _REQ\_SCR\_BHPAGE_ Scroll vertically backward half a page.
    
*   _REQ\_SCR\_FCHAR_ Scroll horizontally forward a character.
    
*   _REQ\_SCR\_BCHAR_ Scroll horizontally backward a character.
    
*   _REQ\_SCR\_HFLINE_ Scroll horizontally one field width forward.
    
*   _REQ\_SCR\_HBLINE_ Scroll horizontally one field width backward.
    
*   _REQ\_SCR\_HFHALF_ Scroll horizontally one half field width forward.
    
*   _REQ\_SCR\_HBHALF_ Scroll horizontally one half field width backward.
    

For scrolling purposes, a page of a field is the height of its visible part.

* * *

### 18.6.5. Editing Requests

When you pass the forms driver an ASCII character, it is treated as a request to add the character to the field's data buffer. Whether this is an insertion or a replacement depends on the field's edit mode (insertion is the default.

The following requests support editing the field and changing the edit mode:

*   _REQ\_INS\_MODE_ Set insertion mode.
    
*   _REQ\_OVL\_MODE_ Set overlay mode.
    
*   _REQ\_NEW\_LINE_ New line request (see below for explanation).
    
*   _REQ\_INS\_CHAR_ Insert space at character location.
    
*   _REQ\_INS\_LINE_ Insert blank line at character location.
    
*   _REQ\_DEL\_CHAR_ Delete character at cursor.
    
*   _REQ\_DEL\_PREV_ Delete previous word at cursor.
    
*   _REQ\_DEL\_LINE_ Delete line at cursor.
    
*   _REQ\_DEL\_WORD_ Delete word at cursor.
    
*   _REQ\_CLR\_EOL_ Clear to end of line.
    
*   _REQ\_CLR\_EOF_ Clear to end of field.
    
*   _REQ\_CLR\_FIELD_ Clear entire field.
    

The behavior of the REQ\_NEW\_LINE and REQ\_DEL\_PREV requests is complicated and partly controlled by a pair of forms options. The special cases are triggered when the cursor is at the beginning of a field, or on the last line of the field.

First, we consider REQ\_NEW\_LINE:

The normal behavior of REQ\_NEW\_LINE in insert mode is to break the current line at the position of the edit cursor, inserting the portion of the current line after the cursor as a new line following the current and moving the cursor to the beginning of that new line (you may think of this as inserting a newline in the field buffer).

The normal behavior of REQ\_NEW\_LINE in overlay mode is to clear the current line from the position of the edit cursor to end of line. The cursor is then moved to the beginning of the next line.

However, REQ\_NEW\_LINE at the beginning of a field, or on the last line of a field, instead does a REQ\_NEXT\_FIELD. O\_NL\_OVERLOAD option is off, this special action is disabled.

Now, let us consider REQ\_DEL\_PREV:

The normal behavior of REQ\_DEL\_PREV is to delete the previous character. If insert mode is on, and the cursor is at the start of a line, and the text on that line will fit on the previous one, it instead appends the contents of the current line to the previous one and deletes the current line (you may think of this as deleting a newline from the field buffer).

However, REQ\_DEL\_PREV at the beginning of a field is instead treated as a REQ\_PREV\_FIELD.

If the O\_BS\_OVERLOAD option is off, this special action is disabled and the forms driver just returns E\_REQUEST\_DENIED.

* * *

### 18.6.6. Order Requests

If the type of your field is ordered, and has associated functions for getting the next and previous values of the type from a given value, there are requests that can fetch that value into the field buffer:

*   _REQ\_NEXT\_CHOICE_ Place the successor value of the current value in the buffer.
    
*   _REQ\_PREV\_CHOICE_ Place the predecessor value of the current value in the buffer.
    

Of the built-in field types, only TYPE\_ENUM has built-in successor and predecessor functions. When you define a field type of your own (see Custom Validation Types), you can associate our own ordering functions.

* * *

### 18.6.7. Application Commands

Form requests are represented as integers above the curses value greater than KEY\_MAX and less than or equal to the constant MAX\_COMMAND. A value within this range gets ignored by form\_driver(). So this can be used for any purpose by the application. It can be treated as an application specific action and take corresponding action.

* * *

19\. Tools and Widget Libraries
===============================

Now that you have seen the capabilities of ncurses and its sister libraries, you are rolling your sleeves up and gearing for a project that heavily manipulates screen. But wait.. It can be pretty difficult to write and maintain complex GUI widgets in plain ncurses or even with the additional libraries. There are some ready-to-use tools and widget libraries that can be used instead of writing your own widgets. You can use some of them, get ideas from the code, or even extend them.

* * *

19.1. CDK (Curses Development Kit)
----------------------------------

In the author's words

_CDK stands for 'Curses Development Kit' and it currently contains 21 ready to use widgets which facilitate the speedy development of full screen curses programs._

The kit provides some useful widgets, which can be used in your programs directly. It's pretty well written and the documentation is very good. The examples in the examples directory can be a good place to start for beginners. The CDK can be downloaded from [http://invisible-island.net/cdk/](http://invisible-island.net/cdk/) . Follow the instructions in README file to install it.

* * *

### 19.1.1. Widget List

The following is the list of widgets provided with cdk and their description.

Widget Type           Quick Description
===========================================================================
Alphalist             Allows a user to select from a list of words, with
                      the ability to narrow the search list by typing in a
                      few characters of the desired word.
Buttonbox             This creates a multiple button widget. 
Calendar              Creates a little simple calendar widget.
Dialog                Prompts the user with a message, and the user
                      can pick an answer from the buttons provided.
Entry                 Allows the user to enter various types of information.
File Selector         A file selector built from Cdk base widgets. This
                      example shows how to create more complicated widgets
                      using the Cdk widget library.
Graph                 Draws a graph.
Histogram             Draws a histogram.
Item List             Creates a pop up field which allows the user to select
                      one of several choices in a small field. Very useful
                      for things like days of the week or month names.
Label                 Displays messages in a pop up box, or the label can be
                      considered part of the screen.
Marquee               Displays a message in a scrolling marquee.
Matrix                Creates a complex matrix with lots of options.
Menu                  Creates a pull-down menu interface.
Multiple Line Entry   A multiple line entry field. Very useful
                      for long fields. (like a description
                      field)
Radio List            Creates a radio button list.
Scale                 Creates a numeric scale. Used for allowing a user to
                      pick a numeric value and restrict them to a range of 
                      values.
Scrolling List        Creates a scrolling list/menu list.
Scrolling Window      Creates a scrolling log file viewer. Can add 
                      information into the window while its running. 
                      A good widget for displaying the progress of
                      something. (akin to a console window)
Selection List        Creates a multiple option selection list.
Slider                Akin to the scale widget, this widget provides a
                      visual slide bar to represent the numeric value.
Template              Creates a entry field with character sensitive 
                      positions. Used for pre-formatted fields like
                      dates and phone numbers.
Viewer                This is a file/information viewer. Very useful
                      when you need to display loads of information.
===========================================================================

A few of the widgets are modified by Thomas Dickey in recent versions.

* * *

### 19.1.2. Some Attractive Features

Apart from making our life easier with readily usable widgets, cdk solves one frustrating problem with printing multi colored strings, justified strings elegantly. Special formatting tags can be embedded in the strings which are passed to CDK functions. For Example

If the string

"</B/1>This line should have a yellow foreground and a blue
background.<!1>"

given as a parameter to newCDKLabel(), it prints the line with yellow foreground and blue background. There are other tags available for justifying string, embedding special drawing characters etc.. Please refer to the man page cdk\_display(3X) for details. The man page explains the usage with nice examples.

* * *

### 19.1.3. Conclusion

All in all, CDK is a well-written package of widgets, which if used properly can form a strong frame work for developing complex GUI.

* * *

19.2. The dialog
----------------

Long long ago, in September 1994, when few people knew linux, Jeff Tranter wrote an [article](http://www2.linuxjournal.com/lj-issues/issue5/2807.html) on dialog in Linux Journal. He starts the article with these words..

_Linux is based on the Unix operating system, but also features a number of unique and useful kernel features and application programs that often go beyond what is available under Unix. One little-known gem is "dialog", a utility for creating professional-looking dialog boxes from within shell scripts. This article presents a tutorial introduction to the dialog utility, and shows examples of how and where it can be used_

As he explains, dialog is a real gem in making professional-looking dialog boxes with ease. It creates a variety of dialog boxes, menus, check lists etc.. It is usually installed by default. If not, you can download it from [Thomas Dickey](http://invisible-island.net/dialog/)'s site.

The above-mentioned article gives a very good overview of its uses and capabilites. The man page has more details. It can be used in variety of situations. One good example is building of linux kernel in text mode. Linux kernel uses a modified version of dialog tailored for its needs.

dialog was initially designed to be used with shell scripts. If you want to use its functionality in a c program, then you can use libdialog. The documentation regarding this is sparse. Definitive reference is the dialog.h header file which comes with the library. You may need to hack here and there to get the required output. The source is easily customizable. I have used it on a number of occasions by modifying the code.

* * *

19.3. Perl Curses Modules CURSES::FORM and CURSES::WIDGETS
----------------------------------------------------------

The perl module Curses, Curses::Form and Curses::Widgets give access to curses from perl. If you have curses and basic perl is installed, you can get these modules from [CPAN All Modules page](http://www.cpan.org/modules/01modules.index.html). Get the three zipped modules in the Curses category. Once installed you can use these modules from perl scripts like any other module. For more information on perl modules see perlmod man page. The above modules come with good documentation and they have some demo scripts to test the functionality. Though the widgets provided are very rudimentary, these modules provide good access to curses library from perl.

Some of my code examples are converted to perl by Anuradha Ratnaweera and they are available in the perl directory.

For more information see man pages Curses(3) , Curses::Form(3) and Curses::Widgets(3). These pages are installed only when the above modules are acquired and installed.

* * *

20\. Just For Fun !!!
=====================

This section contains few programs written by me just for fun. They don't signify a better programming practice or the best way of using ncurses. They are provided here so as to allow beginners to get ideas and add more programs to this section. If you have written a couple of nice, simple programs in curses and want them to included here, contact [me](mailto:ppadala@gmail.com).

* * *

20.1. The Game of Life
----------------------

Game of life is a wonder of math. In [Paul Callahan](http://www.math.com/students/wonders/life/life.html)'s words

_The Game of Life (or simply Life) is not a game in the conventional sense. There
are no players, and no winning or losing. Once the "pieces" are placed in the
starting position, the rules determine everything that happens later.
Nevertheless, Life is full of surprises! In most cases, it is impossible to look
at a starting position (or pattern) and see what will happen in the future. The
only way to find out is to follow the rules of the game._

This program starts with a simple inverted U pattern and shows how wonderful life works. There is a lot of room for improvement in the program. You can let the user enter pattern of his choice or even take input from a file. You can also change rules and play with a lot of variations. Search on [google](http://www.google.com) for interesting information on game of life.

_File Path: JustForFun/life.c_

* * *

20.2. Magic Square
------------------

Magic Square, another wonder of math, is very simple to understand but very difficult to make. In a magic square sum of the numbers in each row, each column is equal. Even diagnol sum can be equal. There are many variations which have special properties.

This program creates a simple magic square of odd order.

_File Path: JustForFun/magic.c_

* * *

20.3. Towers of Hanoi
---------------------

The famous towers of hanoi solver. The aim of the game is to move the disks on the first peg to last peg, using middle peg as a temporary stay. The catch is not to place a larger disk over a small disk at any time.

_File Path: JustForFun/hanoi.c_

* * *

20.4. Queens Puzzle
-------------------

The objective of the famous N-Queen puzzle is to put N queens on a N X N chess board without attacking each other.

This program solves it with a simple backtracking technique.

_File Path: JustForFun/queens.c_

* * *

20.5. Shuffle
-------------

A fun game, if you have time to kill.

_File Path: JustForFun/shuffle.c_

* * *

20.6. Typing Tutor
------------------

A simple typing tutor, I created more out of need than for ease of use. If you know how to put your fingers correctly on the keyboard, but lack practice, this can be helpful.

_File Path: JustForFun/tt.c_

* * *

21\. References
===============

*   NCURSES man pages
    
*   NCURSES FAQ at [http://invisible-island.net/ncurses/ncurses.faq.html](http://invisible-island.net/ncurses/ncurses.faq.html)
    
*   Writing programs with NCURSES by Eric Raymond and Zeyd M. Ben-Halim at [http://invisible-island.net/ncurses/ncurses-intro.html](http://invisible-island.net/ncurses/ncurses-intro.html) - somewhat obsolete. I was inspired by this document and the structure of this HOWTO follows from the original document