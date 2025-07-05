/* rogue.c - ECL Rogue */
/* rogue.c, 20-Apr-04 11:01:16, Edit by relph */
/* <RELPH.ROGUE>ROGUE.PAS.2290,  9-Jan-88 12:51:02, Edit by RELPH */
/* **************************************************************************

                              ECL ROGUE

          A pseudo Dungeons and Dragons Game for the PDP-10.
                 Written by: Gary Craig and Jay Skeer
                        and: Oscar Erickson, John Relph.

      Thanks to: Bob Schwartzkopf, Maurice Wuts, and Mark Brown
                   May-December, 1982 --- Version 4

Edit History:  Many until now:

3:48am  Friday, 10 December 1982 -- JMR
     Make GIGI terminals work right.
     Change scrolls, potions, monsters, etc., to constants In
     the file ROGUE.CONSTANTS.
     Change mailing addresses for comments and Bug reports.

8:00pm  Saturday, 11 December 1982 -- GAC
     Removed 'the bolt shoots forward' and fixed up wand-attack echoing
     Made scrolls and potions unidentifiable when blind, can't read when
       blind either.

12:48am  Thursday, 16 December 1982  -- JMR
     Fixed ring of resurrection problem.

6:30pm Saturday, 19 December 1982 -- GAC
     Made inventory use the echo line if it can.  Slow inventory switch
     still needs to be put it (I will do it shortly).

8:30pm Sunday, 20 December 1982 -- GAC
     Put in slow inventory switch, updated doc file, help, and init-instr. file
     Put in slow inventory command, 'I'. Re-init-terminal is now ^I.
     Slow inventory is default on ttys with speed <= 300 baud (or unknown).

9:36pm  Monday, 20 December 1982 -- JMR
     Fixed slow inventory, inventory In slow mode, and fixed bug With
     umpleby & arrow traps, wasn't echoing 'which kills you..' message.

1:30pm Saturday, 8 January 1983 -- GAC
     Fixed the problem Oscar mentioned about Alchemy (wearing potions, etc.).
     Other random diddling (personal_scores, curing, wonder).

12:55am  Friday, 4 March 1983 -- JMR
     Make save File just play the game without being able To keep the score
     If the score File has been tampered With.

5:03pm  Saturday, 5 March 1983 -- JMR
     Fix purple worms To give you six turns inside Of them.  You can
     teleport out or hack your way out.

12:36am  Monday, 14 March 1983 -- JMR
     Add Trap_Identify Function To identify traps....duh

11:43pm  Monday, 14 March 1983 -- JMR
     Fix Nothing Appropriate complaint.

11:38am  Tuesday, 15 March 1983 -- JMR
     add staff of Searching

     Fix cancellation To save

2:54am  Friday, 25 March 1983 -- JMR
     No more ' ' To heal.   Changed To '.' by request.
     Also fix staff Of searching problem. and Generation
     Of monsters when no monsters can be on level.

6:02pm Saturday, April 2 1983 -- GAC
     Undid previous ' ' to '.' change.  Heal is now both, people
     who don't like ' ' can go to hell. Also adjusted monster levels
     to make middle harder in preparation for the Juiblex fix.

11:06pm Sunday, April 3 1983 -- OJE
     Put in Juiblex fix.  Instead of having to kill Juiblex to win the game
     we now place the amulet in a random location and then put Juiblex on
     top of it (asleep).  Also make it so that there are no trapdoors on
     level of the amulet.

3:26am  Friday, 15 April 1983 -- JMR
     Change staffy and trmchk routines To be keyword File,
     change term To be non-monitor specific enumerated Type.

4:29am  Friday, 15 April 1983 -- JMR
     Fix Phantom Stalker special attack...

7:07pm Saturday, 16 April 1983 -- GAC
     Added ^T (systat) command

1:56am  Wednesday, 20 April 1983 -- JMR
     Changed Bug-address To String variable;  changed Staffy To only
     be check Procedure, Procedure Init_Staffy sets it up and sets bug-address

8:22pm  Thursday, 21 April 1983 -- JMR
     Fixing Place_Next_to To Do something a little more reasonable

10:55pm  Saturday, 23 April 1983 -- JMR/OJE
     Fix parts To Read filenames from terminal,
     and Got TURN around corners and move diagonal working.
     Still a few weird things, though.
     OH YEAH:  CHANGE VERSION TO REFLECT EDIT LEVEL!!!!
     In future edits, that is...

11:15pm  Saturday, 23 April 1983 -- JMR
     Take out the SIBEs For redisplay reasons; now With fast run
     you aren't doing that much redisplay anyway.
     Also added Type_Version call For NEW Players.

1:10pm Sunday, 24 April 1983 -- GAC
     Fixed Name file handling, added WHOIS (^W) command.

2:42pm  Monday, 25 April 1983 -- JMR
     Added help For WHOIS, fixed problem With Init_Staffy.

1:46am  Tuesday, 26 April 1983 -- JMR/OJE
     Mimics and Intellect devourers...hahaha

3:27pm  Tuesday, 26 April 1983 --  OJE
     Make optimal turning.

12:08pm Saturday, 30 April 1983 -- GAC
     Made Whois do substrings.

8:49pm  Monday, 2 May 1983 -- JMR
     Cut down size Of save File and take out date checking.

9:20pm  Tuesday, 3 May 1983 -- JMR/OJE
     Fix turning bug.

Recently -- JMR
     Fix bug With creating mimics With no objs on level, and make
     killmoulies same as no monster.

12:06pm  Thursday, 5 May 1983 -- JMR
     Fix Can_Carry bugs, and add 'another' message when finding an object.
     Also, a couple of mimic fixes.

8:45pm  Friday, 6 May 1983 -- JMR
     Fix mimic bug, add hold portal scroll, add ring buffer Of echoes.

1:15am Saturday, 7 May 1983 -- GAC
     Made high intelligence make you 'know' a scroll, made 'unknown object
     type' an illusion object, in case that still happens...

1:51pm Sunday, 8 May 1983 -- J'
     FIX GET OBJ CODE ONCE AND FOR ALL.

1:09am  Sunday, 15 May 1983 -- JMR/OJE
     Fix Place_Next_To code.  Change monster/human hit messages.
     Many other random changes

2:17pm  Monday, 16 May 1983 -- JMR
     Fix complaint about ^T/^C bug from Rutgers.

11:31pm  Tuesday, 17 May 1983 -- JMR
     Try To fix Restore_game bug.  Don't know If it did anything.
     But I gave it a shot.  Also, make Identify more common.

12:37am  Wednesday, 1 June 1983 -- JMR
     Fix player.eaten stuff, Redisplay.  Make hurled objects go thru doors.
     Also Player.Blind Stuff.  Purple worm polymorph stuff.

1:05am  Wednesday, 1 June 1983 -- JMR
     Add Datamedia-2500 terminal handling stuff.

sometime -- JMR
     Fix Githyanki probability.

1:57am  Sunday, 5 June 1983 -- JMR
     Fix Towards/Away_From/Random_Move For monster stuff.

10:16pm  Sunday, 5 June 1983 -- JMR
     Fix Detect Gold/Magic/Monsters

3:41pm  Sunday, 12 June 1983 -- JMR
     Fix Remove_Ring stuff. Fix other Ring stuff.  Purple Worm FIx.

4:31pm 29-jun-83 -- JMR
     Fix save file problem.  HAHAHAHAHAHA! very funny.
     also fix problem with w_para...

7:19pm  Wednesday, 6 July 1983 -- JMR
#46  Add Infoton-400 terminal handling.

10:40am  Thursday, 14 July 1983 -- JMR
#47  add denial Of access by accounts.

1:00pm Saturday, 17 July 1983 -- GAC
#48  add Concept-108 terminal handling

10:32pm  Tuesday, 9 August 1983 -- JMR
#49  Fix bugs With DM2500 terminal handling, and bugs With
     restore_game failure.  Fix Inf400 stuff.  Fix Rings.  Fix arrow wielding.

12:11pm  Saturday, 19 November 1983 -- JMR
#50  add support For hazeltine-1500, version stuff

3:08pm Saturday, 21 January 1984 -- GAC
#51  Fix NIL pointer in Call_obj - got it when typing 'C','*','<esc>'.

12:10pm  Monday, 6 February 1984 -- JMR
#52  Fix problem With mimics, violet fungi, and purple worm death.

9:52pm  Thursday, 1 March 1984 -- JMR
#53  Fix 'f','F' move stuff, and change Set_Options

2:42am  Thursday, 22 March 1984 -- JMR
#54  Found bug In THROW.  It figgers.  also Put Get_Line routine In.

2:48pm  Tuesday, 27 March 1984 -- JMR
#55  Add Captain Fantastic''s Secret Decoder ring.  Fix some things.
     Change log File slightly, and ^T.  Fix some strange bugs.

1:11pm  Friday, 30 March 1984 -- JMR
#56  Fix bug In moving onto door diagonally from within dark room.
     Add HP terminal Type.

4:13pm  Tuesday, 3 April 1984 -- JMR
#57  Put In load checker, and startup version Text.
     Allow healing While sleeping.

5:52pm  Friday, 13 April 1984 -- JMR
#58  Fix a horrible bug that awoke a mimic but did Not change it
     To a 'M' If you were attacking With a bow, sling, or crossbow.
     Also fix bug In place_next_to (again).

1:59am  Sunday, 29 April 1984 -- JMR
#59  Fix bug In Zap_Wand that gave monsters a move after <ESC>.
     Also fix problems With NEW:PASCAL.  And confirm when load too high.

6:32pm  Thursday, 10 May 1984 -- JMR
#60  Change redisplay to include stats lines and echo line.  Some other
     optimization.  Fix purple worm stuff

8:45pm  Friday, 15 June 1984 -- JMR
#61  Put in padding For Con100 terminals.

7:14pm  Tuesday, 3 July 1984 -- JMR
#62  Fix bug With hitting escape from Slow_inventory.
     Parse the four File names from the CONFIGURATION FILE instead of from
     the terminal.

5:33pm  Wednesday, 29 August 1984 -- JMR
#63  Change random number generator.  Move terminal handling to Extern.
     Fix initialization stuff.  Change score File, Names File formats.
     Try to satisfy people who think there isn't enough food.
     Fix bugs With restore_game.

6:39pm  Tuesday, 4 September 1984 -- JMR
#64  Fix Monster stuff.  Bummer, have to make this version 4 (because of
     limitations in the implementation of version numbers on Tops-20).
     I undid this hack in #71.

5:36pm  Wednesday, 31 October 1984 -- JMR
#65  Fix inventory to ask For letter of object when doing inventory.
     Fix bug With wand of blunder.

2:36pm  Saturday, 10 November 1984 -- JMR
#66  lowercase all names, add tombstone/switch.  Change TRMCHK.

11:28pm  Wednesday, 18 February 1987 -- JMR
#67  fix tombstonage
     fix abort from Put on ring

10:57pm  Tuesday, 31 March 1987
#68  Fix reaching level 13 problem.

#69  First attempt at fixing DISPOSE already clobbered object bug.
     It's in Lose_Old_World in the object dispose loop.  Don't know
     why it's so confused, but it has already disposed of one of the
     objects somewhere in the past...  Sometimes...

#70  try to make monsters move a little smahter.  fix erroneous monster moving
     routine which got lost If monsters died in middle of moving especially If
     person moving slow.
     Add trap finding routine to magic_mapping.
     HEY!  CHANGE THE FIRST TWO VERSION CONSTANTS FOR EVERY CHANGE!!!.

3:51pm  Tuesday, 9 March 2004
#71  Convert to C for Linux.  Fix minor bugs.  Reimplement some external
     functions originally written in DEC20 Macro.

****************************************************************************/

#include <curses.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/times.h>
#include <pwd.h>
#include <errno.h>

#ifndef true
#define true 1
#define false 0
#endif

#include "rogue.h"

/* HEY!  CHANGE THE FIRST TWO VERSION CONSTANTS FOR EVERY CHANGE!!! */
#define Rogue_Update	71
#define Rogue_Edit	2292
#define Rogue_Version	4

/* --------------------------------------------------------- */
/* static initializers */

Monsters Monster[Max_Monster] = {

  {
    /* m_ant */
    "giant ant",		/* Long_Name */
    'A',			/* Name */
    2,				/* Hit_Dice */
    3,				/* Ac */
    16,				/* Th0 */
    6,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    3,				/* Min_Level */
    9,				/* Max_Level */
    15,				/* Sleep */
    false,			/* Large */
    11,				/* XPVal */
  },

  {
    /* m_bat */
    "bat",			/* Long_Name */
    'B',			/* Name */
    1,				/* Hit_Dice */
    7,				/* Ac */
    20,				/* Th0 */
    3,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    5,				/* Max_Level */
    25,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_centaur */
    "centaur",			/* Long_Name */
    'C',			/* Name */
    4,				/* Hit_Dice */
    5,				/* Ac */
    15,				/* Th0 */
    6,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    7,				/* Min_Level */
    15,				/* Max_Level */
    10,				/* Sleep */
    true,			/* Large */
    15,				/* XPVal */
  },

  {
    /* m_dragon */
    "dragon",			/* Long_Name */
    'D',			/* Name */
    11,				/* Hit_Dice */
    -2,				/* Ac */
    9,				/* Th0 */
    12,				/* Dam */
    4,				/* Num */
    1,				/* Special */
    21,				/* Min_Level */
    INT_MAX,			/* Max_Level */
    30,				/* Sleep */
    true,			/* Large */
    250,			/* XPVal */
  },

  {
    /* m_eye */
    "floating eye",		/* Long_Name */
    'E',			/* Name */
    1,				/* Hit_Dice */
    9,				/* Ac */
    20,				/* Th0 */
    200,			/* Dam */
    0,				/* Num */
    2,				/* Special */
    3,				/* Min_Level */
    7,				/* Max_Level */
    100,			/* Sleep */
    false,			/* Large */
    8,				/* XPVal */
  },

  {
    /* m_fungi */
    "violet fungi",		/* Long_Name */
    'F',			/* Name */
    6,				/* Hit_Dice */
    7,				/* Ac */
    16,				/* Th0 */
    8,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    16,				/* Min_Level */
    22,				/* Max_Level */
    100,			/* Sleep */
    false,			/* Large */
    15,				/* XPVal */
  },

  {
    /* m_gnoll */
    "gnoll",			/* Long_Name */
    'G',			/* Name */
    2,				/* Hit_Dice */
    5,				/* Ac */
    16,				/* Th0 */
    4,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    4,				/* Min_Level */
    12,				/* Max_Level */
    15,				/* Sleep */
    true,			/* Large */
    5,				/* XPVal */
  },

  {
    /* m_hob */
    "hobgoblin",		/* Long_Name */
    'H',			/* Name */
    1,				/* Hit_Dice */
    5,				/* Ac */
    18,				/* Th0 */
    8,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    7,				/* Max_Level */
    15,				/* Sleep */
    false,			/* Large */
    3,				/* XPVal */
  },

  {
    /* m_invis */
    "invisible stalker",	/* Long_Name */
    'I',			/* Name */
    8,				/* Hit_Dice */
    3,				/* Ac */
    12,				/* Th0 */
    4,				/* Dam */
    4,				/* Num */
    1,				/* Special */
    15,				/* Min_Level */
    20,				/* Max_Level */
    0,				/* Sleep */
    true,			/* Large */
    45,				/* XPVal */
  },

  {
    /* m_jackal */
    "jackal",			/* Long_Name */
    'J',			/* Name */
    1,				/* Hit_Dice */
    7,				/* Ac */
    20,				/* Th0 */
    2,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    5,				/* Max_Level */
    15,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_kobold */
    "kobold",			/* Long_Name */
    'K',			/* Name */
    1,				/* Hit_Dice */
    7,				/* Ac */
    20,				/* Th0 */
    4,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    6,				/* Max_Level */
    15,				/* Sleep */
    false,			/* Large */
    2,				/* XPVal */
  },

  {
    /* m_lep */
    "leprechaun",		/* Long_Name */
    'L',			/* Name */
    2,				/* Hit_Dice */
    8,				/* Ac */
    200,			/* Th0 */
    200,			/* Dam */
    0,				/* Num */
    2,				/* Special */
    7,				/* Min_Level */
    16,				/* Max_Level */
    100,			/* Sleep */
    false,			/* Large */
    12,				/* XPVal */
  },

  {
    /* m_mimic */
    "mimic",			/* Long_Name */
    'M',			/* Name */
    9,				/* Hit_Dice */
    7,				/* Ac */
    12,				/* Th0 */
    4,				/* Dam */
    3,				/* Num */
    3,				/* Special */
    12,				/* Min_Level */
    INT_MAX,			/* Max_Level */
    100,			/* Sleep */
    true,			/* Large */
    35,				/* XPVal */
  },

  {
    /* m_nymph */
    "nymph",			/* Long_Name */
    'N',			/* Name */
    3,				/* Hit_Dice */
    9,				/* Ac */
    200,			/* Th0 */
    200,			/* Dam */
    0,				/* Num */
    2,				/* Special */
    10,				/* Min_Level */
    15,				/* Max_Level */
    100,			/* Sleep */
    false,			/* Large */
    10,				/* XPVal */
  },

  {
    /* m_orc */
    "orc",			/* Long_Name */
    'O',			/* Name */
    1,				/* Hit_Dice */
    6,				/* Ac */
    19,				/* Th0 */
    6,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    2,				/* Min_Level */
    10,				/* Max_Level */
    15,				/* Sleep */
    false,			/* Large */
    5,				/* XPVal */
  },

  {
    /* m_purple */
    "purple worm",		/* Long_Name */
    'P',			/* Name */
    15,				/* Hit_Dice */
    6,				/* Ac */
    8,				/* Th0 */
    12,				/* Dam */
    2,				/* Num */
    3,				/* Special */
    22,				/* Min_Level */
    INT_MAX,			/* Max_Level */
    15,				/* Sleep */
    true,			/* Large */
    200,			/* XPVal */
  },

  {
    /* m_quasit */
    "quasit",			/* Long_Name */
    'Q',				/* Name */
    3,				/* Hit_Dice */
    2,				/* Ac */
    16,				/* Th0 */
    4,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    9,				/* Min_Level */
    15,				/* Max_Level */
    10,				/* Sleep */
    false,			/* Large */
    15,				/* XPVal */
  },

  {
    /* m_rust */
    "rust monster",		/* Long_Name */
    'R',			/* Name */
    5,				/* Hit_Dice */
    2,				/* Ac */
    15,				/* Th0 */
    200,			/* Dam */
    0,				/* Num */
    2,				/* Special */
    9,				/* Min_Level */
    16,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    25,				/* XPVal */
  },

  {
    /* m_snake */
    "snake",			/* Long_Name */
    'S',			/* Name */
    2,				/* Hit_Dice */
    5,				/* Ac */
    17,				/* Th0 */
    3,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    6,				/* Max_Level */
    30,				/* Sleep */
    true,			/* Large */
    2,				/* XPVal */
  },

  {
    /* m_troll */
    "troll",			/* Long_Name */
    'T',			/* Name */
    7,				/* Hit_Dice */
    4,				/* Ac */
    13,				/* Th0 */
    4,				/* Dam */
    7,				/* Num */
    1,				/* Special */
    14,				/* Min_Level */
    18,				/* Max_Level */
    10,				/* Sleep */
    true,			/* Large */
    50,				/* XPVal */
  },

  {
    /* m_umber */
    "umber hulk",		/* Long_Name */
    'U',			/* Name */
    9,				/* Hit_Dice */
    2,				/* Ac */
    12,				/* Th0 */
    4,				/* Dam */
    8,				/* Num */
    3,				/* Special */
    18,				/* Min_Level */
    22,				/* Max_Level */
    10,				/* Sleep */
    true,			/* Large */
    85,				/* XPVal */
  },

  {
    /* m_vampire */
    "vampire",			/* Long_Name */
    'V',			/* Name */
    8,				/* Hit_Dice */
    1,				/* Ac */
    12,				/* Th0 */
    2,				/* Dam */
    5,				/* Num */
    3,				/* Special */
    19,				/* Min_Level */
    24,				/* Max_Level */
    40,				/* Sleep */
    false,			/* Large */
    90,				/* XPVal */
  },

  {
    /* m_wraith */
    "wraith",			/* Long_Name */
    'W',			/* Name */
    5,				/* Hit_Dice */
    4,				/* Ac */
    15,				/* Th0 */
    6,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    13,				/* Min_Level */
    17,				/* Max_Level */
    30,				/* Sleep */
    false,			/* Large */
    55,				/* XPVal */
  },

  {
    /* m_xorn */
    "xorn",			/* Long_Name */
    'X',			/* Name */
    8,				/* Hit_Dice */
    -2,				/* Ac */
    12,				/* Th0 */
    8,				/* Dam */
    4,				/* Num */
    1,				/* Special */
    17,				/* Min_Level */
    23,				/* Max_Level */
    10,				/* Sleep */
    false,			/* Large */
    75,				/* XPVal */
  },

  {
    /* m_yeti */
    "yeti",			/* Long_Name */
    'Y',			/* Name */
    4,				/* Hit_Dice */
    6,				/* Ac */
    15,				/* Th0 */
    6,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    11,				/* Min_Level */
    16,				/* Max_Level */
    25,				/* Sleep */
    true,			/* Large */
    30,				/* XPVal */
  },

  {
    /* m_zombie */
    "zombie",			/* Long_Name */
    'Z',			/* Name */
    2,				/* Hit_Dice */
    8,				/* Ac */
    16,				/* Th0 */
    8,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    4,				/* Min_Level */
    9,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    8,				/* XPVal */
  },

  {
    /* m_almiraj */
    "al-mi\'raj",		/* Long_Name */
    'a',			/* Name */
    1,				/* Hit_Dice */
    6,				/* Ac */
    15,				/* Th0 */
    4,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    4,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_blind */
    "blindheim",		/* Long_Name */
    'b',			/* Name */
    4,				/* Hit_Dice */
    3,				/* Ac */
    15,				/* Th0 */
    8,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    5,				/* Min_Level */
    12,				/* Max_Level */
    85,				/* Sleep */
    false,			/* Large */
    20,				/* XPVal */
  },

  {
    /* m_crypt */
    "crypt thing",		/* Long_Name */
    'c',			/* Name */
    8,				/* Hit_Dice */
    3,				/* Ac */
    13,				/* Th0 */
    8,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    8,				/* Min_Level */
    10,				/* Max_Level */
    100,				/* Sleep */
    false,			/* Large */
    25,				/* XPVal */
  },

  {
    /* m_death */
    "death knight",		/* Long_Name */
    'd',			/* Name */
    11,				/* Hit_Dice */
    0,				/* Ac */
    13,				/* Th0 */
    20,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    20,				/* Min_Level */
    20,				/* Max_Level */
    10,				/* Sleep */
    false,			/* Large */
    90,				/* XPVal */
  },

  {
    /* m_ettin */
    "ettin",			/* Long_Name */
    'e',			/* Name */
    10,				/* Hit_Dice */
    3,				/* Ac */
    16,				/* Th0 */
    16,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    19,				/* Min_Level */
    24,				/* Max_Level */
    5,				/* Sleep */
    true,			/* Large */
    75,				/* XPVal */
  },

  {
    /* m_flind */
    "flind",			/* Long_Name */
    'f',			/* Name */
    2,				/* Hit_Dice */
    5,				/* Ac */
    16,				/* Th0 */
    6,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    3,				/* Min_Level */
    8,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    9,				/* XPVal */
  },

  {
    /* m_gith */
    "githyanki",		/* Long_Name */
    'g',			/* Name */
    9,				/* Hit_Dice */
    2,				/* Ac */
    13,				/* Th0 */
    12,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    14,				/* Min_Level */
    16,				/* Max_Level */
    20,				/* Sleep */
    false,			/* Large */
    60,				/* XPVal */
  },

  {
    /* m_homon */
    "homonculus",		/* Long_Name */
    'h',			/* Name */
    2,				/* Hit_Dice */
    6,				/* Ac */
    18,				/* Th0 */
    3,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    4,				/* Min_Level */
    7,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    10,				/* XPVal */
  },

  {
    /* m_int */
    "intellect devourer",	/* Long_Name */
    'i',			/* Name */
    7,				/* Hit_Dice */
    4,				/* Ac */
    13,				/* Th0 */
    4,				/* Dam */
    4,				/* Num */
    3,				/* Special */
    17,				/* Min_Level */
    22,				/* Max_Level */
    10,				/* Sleep */
    false,			/* Large */
    65,				/* XPVal */
  },

  {
    /* m_juiblex */
    "Juiblex",			/* Long_Name */
    'j',			/* Name */
    15,				/* Hit_Dice */
    -7,				/* Ac */
    8,				/* Th0 */
    10,				/* Dam */
    4,				/* Num */
    1,				/* Special */
    0,				/* Min_Level */
    0,				/* Max_Level */
    1,				/* Sleep */
    true,			/* Large */
    500,			/* XPVal */
  },

  {
    /* m_kill */
    "killmoulis",		/* Long_Name */
    'k',			/* Name */
    1,				/* Hit_Dice */
    6,				/* Ac */
    15,				/* Th0 */
    2,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    INT_MAX,			/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_larva */
    "larva",			/* Long_Name */
    'l',			/* Name */
    1,				/* Hit_Dice */
    7,				/* Ac */
    17,				/* Th0 */
    5,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    3,				/* Min_Level */
    7,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_minotaur */
    "minotaur",			/* Long_Name */
    'm',			/* Name */
    7,				/* Hit_Dice */
    6,				/* Ac */
    13,				/* Th0 */
    4,				/* Dam */
    3,				/* Num */
    1,				/* Special */
    11,				/* Min_Level */
    14,				/* Max_Level */
    20,				/* Sleep */
    true,			/* Large */
    25,				/* XPVal */
  },

  {
    /* m_norker */
    "norker",			/* Long_Name */
    'n',			/* Name */
    2,				/* Hit_Dice */
    5,				/* Ac */
    19,				/* Th0 */
    5,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    4,				/* Min_Level */
    9,				/* Max_Level */
    50,				/* Sleep */
    false,			/* Large */
    6,				/* XPVal */
  },

  {
    /* m_owlbear */
    "owlbear",			/* Long_Name */
    'o',			/* Name */
    5,				/* Hit_Dice */
    5,				/* Ac */
    15,				/* Th0 */
    12,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    16,				/* Min_Level */
    21,				/* Max_Level */
    20,				/* Sleep */
    true,			/* Large */
    40,				/* XPVal */
  },

  {
    /* m_phantom */
    "phantom stalker",		/* Long_Name */
    'p',			/* Name */
    6,				/* Hit_Dice */
    3,				/* Ac */
    14,				/* Th0 */
    4,				/* Dam */
    2,				/* Num */
    3,				/* Special */
    11,				/* Min_Level */
    16,				/* Max_Level */
    70,				/* Sleep */
    true,			/* Large */
    37,				/* XPVal */
  },

  {
    /* m_quaggoth */
    "quaggoth",			/* Long_Name */
    'q',			/* Name */
    1,				/* Hit_Dice */
    6,				/* Ac */
    17,				/* Th0 */
    4,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    4,				/* Max_Level */
    10,				/* Sleep */
    true,			/* Large */
    3,				/* XPVal */
  },

  {
    /* m_revenant */
    "revenant",			/* Long_Name */
    'r',			/* Name */
    8,				/* Hit_Dice */
    10,				/* Ac */
    15,				/* Th0 */
    8,				/* Dam */
    2,				/* Num */
    3,				/* Special */
    18,				/* Min_Level */
    21,				/* Max_Level */
    30,				/* Sleep */
    false,			/* Large */
    50,				/* XPVal */
  },

  {
    /* m_sand */
    "sandman",			/* Long_Name */
    's',			/* Name */
    4,				/* Hit_Dice */
    3,				/* Ac */
    14,				/* Th0 */
    0,				/* Dam */
    0,				/* Num */
    2,				/* Special */
    10,				/* Min_Level */
    14,				/* Max_Level */
    100,			/* Sleep */
    false,			/* Large */
    25,				/* XPVal */
  },

  {
    /* m_tira */
    "tirapheg",			/* Long_Name */
    't',			/* Name */
    2,				/* Hit_Dice */
    10,				/* Ac */
    17,				/* Th0 */
    4,				/* Dam */
    3,				/* Num */
    1,				/* Special */
    5,				/* Min_Level */
    9,				/* Max_Level */
    30,				/* Sleep */
    false,			/* Large */
    8,				/* XPVal */
  },

  {
    /* m_umpleby */
    "umpleby",			/* Long_Name */
    'u',			/* Name */
    6,				/* Hit_Dice */
    4,				/* Ac */
    14,				/* Th0 */
    4,				/* Dam */
    1,				/* Num */
    3,				/* Special */
    8,				/* Min_Level */
    11,				/* Max_Level */
    25,				/* Sleep */
    true,			/* Large */
    30,				/* XPVal */
  },

  {
    /* m_vodyanoi */
    "vodyanoi",			/* Long_Name */
    'v',			/* Name */
    8,				/* Hit_Dice */
    2,				/* Ac */
    13,				/* Th0 */
    11,				/* Dam */
    3,				/* Num */
    1,				/* Special */
    21,				/* Min_Level */
    26,				/* Max_Level */
    40,				/* Sleep */
    true,			/* Large */
    65,				/* XPVal */
  },

  {
    /* m_werewolf */
    "werewolf",			/* Long_Name */
    'w',			/* Name */
    5,				/* Hit_Dice */
    5,				/* Ac */
    13,				/* Th0 */
    4,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    15,				/* Min_Level */
    20,				/* Max_Level */
    20,				/* Sleep */
    true,			/* Large */
    45,				/* XPVal */
  },

  {
    /* m_xvart */
    "xvart",			/* Long_Name */
    'x',			/* Name */
    1,				/* Hit_Dice */
    7,				/* Ac */
    18,				/* Th0 */
    5,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    1,				/* Min_Level */
    5,				/* Max_Level */
    0,				/* Sleep */
    false,			/* Large */
    1,				/* XPVal */
  },

  {
    /* m_yulgrin */
    "yulgrin",			/* Long_Name */
    'y',			/* Name */
    4,				/* Hit_Dice */
    7,				/* Ac */
    16,				/* Th0 */
    10,				/* Dam */
    1,				/* Num */
    1,				/* Special */
    7,				/* Min_Level */
    10,				/* Max_Level */
    30,				/* Sleep */
    false,			/* Large */
    12,				/* XPVal */
  },

  {
    /* m_zallige */
    "zallige",			/* Long_Name */
    'z',			/* Name */
    9,				/* Hit_Dice */
    0,				/* Ac */
    10,				/* Th0 */
    18,				/* Dam */
    2,				/* Num */
    1,				/* Special */
    24,				/* Min_Level */
    40,				/* Max_Level */
    10,				/* Sleep */
    true,			/* Large */
    150,			/* XPVal */
  }
};

Potions Potion[Max_Potion] = {
  /* Name, Id, Called */
  /* p_gold_det */
  { "gold detection", false, false },
  /* p_mon_det */
  { "monster detection", false, false },
  /* p_magic_det */
  { "magic detection", false, false },
  /* p_reg_str */
  { "regain strength", false, false },
  /* p_reg_int */
  { "regain intelligence", false, false },
  /* p_reg_dex */
  { "regain dexterity", false, false },
  /* p_poison */
  { "poison", false, false },
  /* p_feeble */
  { "feeblemindedness", false, false },
  /* p_fumble */
  { "fumbling", false, false },
  /* p_incr_str */
  { "increase strength", false, false },
  /* p_incr_int */
  { "increase intelligence", false, false },
  /* p_inc_dex */
  { "increase dexterity", false, false },
  /* p_skill */
  { "skillfulness", false, false },
  /* p_healing */
  { "healing", false, false },
  /* p_ex_healing */
  { "extra healing", false, false },
  /* p_invis */
  { "see invisible", false, false },
  /* p_haste */
  { "haste self", false, false },
  /* p_slow */
  { "slow self", false, false },
  /* p_blind */
  { "blindness", false, false },
  /* p_confuse */
  { "confusion", false, false },
  /* p_confuse_mon */
  { "confuse monster", false, false },
  /* p_sleep */
  { "sleep", false, false },
  /* p_paralysis */
  { "paralysis", false, false },
  /* p_nothing */
  { "nothing", false, false },
  /* p_sustenance */
  { "sustenance", false, false } /* #54 */
};

Scrolls Scroll[Max_Scroll] = {
  /* Name, Id, Called, Can_Id */
  /* s_armor */
  { "enchant armor", false, false, true },
  /* s_weapon */
  { "enchant weapon", false, false, true },
  /* s_curse */
  { "remove curse", false, false, true },
  /* s_mapping */
  { "magic mapping", false, false, true },
  /* s_identify */
  { "identify", false, false, true },
  /* s_genocide */
  { "genocide", false, false, true },
  /* s_scare */
  { "scare monster", false, false, true },
  /* s_nothing */
  { "nothing", false, false, true },
  /* s_teleport */
  { "teleportation", false, false, true },
  /* s_summon */
  { "summon monster", false, false, true },
  /* s_light */
  { "light", false, false, true },
  /* s_hold */
  { "hold portal", false, false, true }
};

Wands Wand[Max_Wand] = {
  /* Name, Id, Called, Dam, Num */
  /* w_drain */
  { "drain life", false, false, 10, 20 },
  /* w_fire */
  { "fire", false, false, 6, 8 },
  /* w_lightning */
  { "lightning", false, false, 6, 8 },
  /* w_cold */
  { "cold", false, false, 6, 8 },
  /* w_light */
  { "light", false, false, 0, 0 },
  /* w_poly */
  { "polymorph", false, false, 0, 0 },
  /* w_tele_to */
  { "teleport to", false, false, 0, 0 },
  /* w_tele_away */
  { "teleport away", false, false, 0, 0 },
  /* w_missile */
  { "magic missile", false, false, 4, 1 },
  /* w_nothing */
  { "nothing", false, false, 0, 0 },
  /* w_striking */
  { "striking", false, false, 6, 2 },
  /* w_slow */
  { "slow monster", false, false, 0, 0 },
  /* w_haste */
  { "haste monster", false, false, 0, 0 },
  /* w_cancel */
  { "cancellation", false, false, 0, 0 },
  /* w_alchemy */
  { "alchemy", false, false, 0, 0 },
  /* w_wonder */
  { "wonder", false, false, 0, 0 },
  /* w_paralyze */
  { "paralyzation", false, false, 0, 0 },
  /* w_curing */
  { "curing", false, false, 0, 0 },
  /* w_search */
  { "searching", false, false, 0, 0 },
  /* w_blunder */
  { "blunder", false, false, 0, 0 }
};

Armors Armor[Max_Armor] = {
  /* Name, Ac */
  /* a_leather */
  { "leather armor", 8 },
  /* a_stud */
  { "studded leather armor", 7 },
  /* a_ring */
  { "ring mail", 7 },
  /* a_scale */
  { "scale mail", 6 },
  /* a_chain */
  { "chain mail", 5 },
  /* a_splint */
  { "splint mail", 4 },
  /* a_banded */
  { "banded mail", 4 },
  /* a_plate */
  { "plate mail", 3 },
};

Rings Ring[Max_Ring] = {
  /* Name, Id, Called */
  /* r_regen */
  { "regeneration", false, false },
  /* r_digest */
  { "slow digestion", false, false },
  /* r_sustain */
  { "sustain strength", false, false },
  /* r_protect */
  { "protection", false, false },
  /* r_dex */
  { "dexterity", false, false },
  /* r_str */
  { "strength", false, false },
  /* r_int */
  { "intelligence", false, false },
  /* r_see_inv */
  { "see invisible", false, false },
  /* r_teleport */
  { "teleportation", false, false },
  /* r_stealth */
  { "stealth", false, false },
  /* r_aggra */
  { "aggravate monster", false, false },
  /* r_search */
  { "searching", false, false },
  /* r_incr_dam */
  { "increase damage", false, false },
  /* r_resur */
  { "resurrection", false, false },
  /* r_vampiric */
  { "vampiric regeneration", false, false },
  /* r_invis */
  { "invisibility", false, false },
  /* r_decode */
  { "secret decoding", false, false }, /* #55 */
};

Weapons Weapon[Max_Weapon] = {
  /* Name, S_Dam, S_Num, L_Dam, L_Num */
  /* wp_two_sword */
  { "two handed sword", 10, 1, 6, 3 },
  /* wp_long_sword */
  { "long sword", 8, 1, 12, 1 },
  /* wp_dagger */
  { "dagger", 4, 1, 3, 1 },
  /* wp_sling */
  { "sling", 1, 1, 1, 1 },
  /* wp_rocks */
  { "rock", 4, -wp_sling, 4, -wp_sling },
  /* wp_crossbow */
  { "crossbow", 1, 1, 1, 1 },
  /* wp_bolts */
  { "bolt", 6, -wp_crossbow, 6, -wp_crossbow },
  /* wp_Bow */
  { "short bow", 1, 1, 1, 1 },
  /* wp_arrows */
  { "arrow", 6, -wp_bow, 6, -wp_bow },
  /* wp_mace */
  { "mace", 8, 1, 7, 1 },
  /* wp_sil_sword */
  { "silver long sword", 8, 1, 12, 1 },
  /* wp_sil_arrows */
  { "silver arrow", 6, -wp_bow, 6, -wp_bow },
};

/* #71 Colors, Stones, Woods, Metals must be < 30 characters */

char *Color[] = {
  "red",
  "blue",
  "yellow",
  "green",
  "orange",
  "violet",
  "black",
  "white",
  "brown",
  "pink",
  "clear",
  "tan",
  "aquamarine",
  "purple",
  "vermilion",
  "gold",
  "silver",
  "gray",
  "beige",
  "olive",
  "sparkling",
  "cloudy",
  "foaming",
  "plaid",
  "milky",			/* #54 */
  "bubbly",			/* #71 allow lots of potions */
  "soupy",
  "viscous",
  "effervescent",
  "glowing",
  "chartreuse",
  "puce",
  "noisome",
  NULL				/* #71 last entry must be NULL */
};

char *Stone[] = {
  "ruby",
  "diamond",
  "emerald",
  "sapphire",
  "topaz",
  "jade",
  "obsidian",
  "onyx",
  "pearl",
  "carnelian",
  "amethyst",
  "bloodstone",
  "tigereye",
  "opal",
  "jet",
  "coral",
  "moonstone",			/* #55 */
  "aquamarine",			/* #71 allow lots of stones */
  "garnet",
  "cubic zirconium",
  "amber",
  "beryl",
  "lapis lazuli",
  "peridot",
  "tourmaline",
  "turqoise",
  "sardonyx",
  "agate",
  "citrine",
  NULL				/* #71 last entry must be NULL */
};

char *Wood[] = {
  "maple",
  "ebony",
  "oak",
  "spruce",
  "redwood",
  "birch",
  "ironwood",
  "hemlock",
  "balsa",
  "teak",
  "cherry",
  "pine",
  "manzanita",
  "mahogany",
  "walnut",
  "rosewood",
  "sycamore",
  "hickory",
  "bamboo",
  "fir",
  "bubinga",			/* #71 allow lots of woods */
  "larch",
  "eucalyptus",
  "olive",
  "poplar",
  "applewood",
  "koa",
  "cedar",
  "ash",
  "boxwood",
  "yew",
  NULL				/* #71 last entry must be NULL */
};

char *Metal[] = {
  "steel",
  "lead",
  "tin",
  "iron",
  "zinc",
  "platinum",
  "aluminium",
  "brass",
  "ivory",
  "bone",
  "silver",
  "gold",
  "magnesium",
  "copper",
  "bronze",
  "electrum",
  "glass",
  "crystal",
  "pewter",
  "rusty",
  "carbon fiber",		/* #71 allow lots of metals */
  "titanium",
  "bakelite",
  "fiberglass",
  "star-tipped",
  "fossilized wood",
  "zircon-encrusted",
  "chrome-plated",
  "pinchbeck",
  "porcelain",
  "nickel",
  "duralumin",
  NULL				/* #71 last entry must be NULL */
};

/* Look carefully, my children. */
/* In these words you can read The History of the World. */
char *Word[] = {
  "xo",
  "meilrahc",
  "nelg",
  "ulooloo",
  "fris",
  "ah-clem",
  "dobne",
  "ixchotl",
  "brachnild",
  "oorne",
  "mojwinq",
  "pribanic",
  "bhatti",
  "moni-q",
  "goezor",
  "trelch",
  "eddbaka",
  "merkbron",
  "gareeprtz",
  "jskiere",
  "moriwutz",
  "qonsitte",
  "mazinga",
  "manabe",
  "j-rlph",
  "ni-pep",
  "ma-aqqu",
  "usskahr",
  "okeeninam",
  "mariesch",
  "kaamatang",
  "pog-mahon",
  "quang-tx",
  "omvidadis",
  "wol",
  "zqwtu-axt",
  "merk",
  "ta-alli",
  "ouizzkoie",
  "oo-ouille",
  "eno-ytrof",
  "juq",
  "oi",
  "yraggiarc",
  "eugorsnett",
  "ttengs",
  "phtheifes",
  "nyarteri",
  "moht-reeks",
  "goud",
  "rotinom",
  "smoortser",
  "cidre",
  "oknridx",
  "yyrthum",
  "descytsem",
  "bruhmschh",
  "einwaf",
  "jupe",
  "kaupatie",
  "ugerbaaui",
  "bhaf",
  "ka-ille",
  "maknam",
  "gnesyme",
  "xis-ytxis",
  "nyp",
  "deuki",
  "ghodrat",
  "tansik",
  "machale",
  "dwinity",
  "taqwe-ere",
  "wurdilst",
  "watinj",
  "moirdblat",
  "yttriun",
  "sadiub-lat",
  "nytrok-o",
  "khan",
  "ackhhtng",
  "dragoljub",
  "sirg",
  "pne-relli",
  "bhutta",
  "treb",
  "dalli",
  "gibstit",
  "giirf",
  "waq-aqille",
  "zilnath",
  "ylavlrig",
  "ysyzygy",
  "los-de-jae",
  "evif",
  "rouf",
  "scamette",
  "laxap",
  "rhemulak",
  "ta-fieenal",
  "domokos",
  "glyrehs",
  "draalmon",
  "shiavax",
  "blas",
  "majal",
  "bobkof",
  "scamee",
  "teardublu",
  "aristar",
  "amaragh",
  "glissaragh",
  "clongowes",
  "maghanagh",
  "malahide",
  "clonliffey",
  "ballyrock",
  "grafton",
  "armagh",
  "gillevans",
  "otais",
  "ozzaxx",
  "likid-len",
  "eyebeem",
  "mor-dweo",
  "thlayli",
  "dawkcid",
  "zandru",
  "jetsons",
  "wally-beav",
  "laran",
  "heures",
  "craindre",
  "taquine",
  "orly-sont",
  "surgele",
  "gnippird",
  "fromages",
  "fitarepmi",
  "engapmahc",
  "regnad",
  "bhagavad",
  "destrier",
  "triskele",
  "racktingh",
  "nabrubus",
  "guasacht",
  "fusil",
  "jezail",
  "yromem",
  "hornsby",
  "jae-pi-dee",
  "nye-nart",
  "wianal",
  "illetni",
  "sciteneg",
  "ipotco",
  "shotnicam",
  "normumb",
  "cablecar",
  "grrrllee",
  "polmon",
  NULL				/* last entry must be NULL */
};

/* Chances of finding a Treasure */
Treasures Treasure[Max_Treasure] = {
  /* Chance, Typ, Index */
  { 780, Gold_T, 0 },
  {  70, Food_T, 0 },
  {  50, Scroll_T, s_identify },
  {  35, Food_T, 1 },
  {  32, Scroll_T, s_curse },
  {  30, Potion_T, p_healing },
  {  24, Scroll_T, s_armor },
  {  24, Scroll_T, s_weapon },
  {  20, Scroll_T, s_mapping },
  {  20, Scroll_T, s_scare },
  {  20, Scroll_T, s_light },
  {  20, Scroll_T, s_hold },
  {  18, Scroll_T, s_teleport },
  {  14, Potion_T, p_reg_str },
  {  14, Potion_T, p_reg_int },
  {  14, Scroll_T, s_summon },
  {  13, Potion_T, p_reg_dex },
  {  12, Potion_T, p_ex_healing },
  {  10, Potion_T, p_gold_det },
  {  10, Potion_T, p_mon_det },
  {  10, Potion_T, p_magic_det },
  {  10, Potion_T, p_poison },
  {  10, Potion_T, p_feeble },
  {  10, Potion_T, p_fumble },
  {  10, Potion_T, p_incr_str },
  {  10, Potion_T, p_incr_int },
  {  10, Potion_T, p_inc_dex },
  {  10, Potion_T, p_invis },
  {  10, Potion_T, p_haste },
  {  10, Potion_T, p_slow },
  {  10, Potion_T, p_confuse },
  {  10, Potion_T, p_confuse_mon },
  {  10, Potion_T, p_sleep },
  {  10, Potion_T, p_paralysis },
  {  10, Scroll_T, s_nothing },
  {   9, Armor_T, a_leather },
  {   8, Weapon_T, wp_mace },
  {   7, Armor_T, a_stud },
  {   7, Armor_T, a_ring },
  {   7, Armor_T, a_scale },
  {   6, Wand_T, w_light },
  {   6, Weapon_T, wp_long_sword },
  {   6, Weapon_T, wp_dagger },
  {   6, Weapon_T, wp_sling },
  {   6, Weapon_T, wp_rocks },
  {   6, Weapon_T, wp_crossbow },
  {   6, Weapon_T, wp_bolts },
  {   6, Weapon_T, wp_bow },
  {   6, Weapon_T, wp_arrows },
  {   6, Wand_T, w_search },
  {   5, Potion_T, p_blind },
  {   5, Armor_T, a_chain },
  {   5, Armor_T, a_banded },
  {   5, Armor_T, a_splint },
  {   5, Wand_T, w_curing },
  {   4, Wand_T, w_poly },
  {   4, Wand_T, w_tele_to },
  {   4, Wand_T, w_tele_away },
  {   4, Wand_T, w_missile },
  {   4, Wand_T, w_nothing },
  {   4, Wand_T, w_slow },
  {   4, Wand_T, w_paralyze },
  {   4, Wand_T, w_haste },
  {   4, Weapon_T, wp_two_sword },
  {   3, Armor_T, a_plate },
  {   3, Potion_T, p_nothing },
  {   2, Potion_T, p_skill },
  {   2, Scroll_T, s_genocide },
  {   2, Wand_T, w_drain },
  {   2, Wand_T, w_fire },
  {   2, Wand_T, w_lightning },
  {   2, Wand_T, w_cold },
  {   2, Wand_T, w_striking },
  {   2, Wand_T, w_cancel },
  {   2, Ring_T, r_regen },
  {   2, Ring_T, r_digest },
  {   2, Ring_T, r_sustain },
  {   2, Ring_T, r_protect },
  {   2, Ring_T, r_dex },
  {   2, Ring_T, r_str },
  {   2, Ring_T, r_int },
  {   2, Ring_T, r_see_inv },
  {   2, Ring_T, r_teleport },
  {   2, Ring_T, r_stealth },
  {   2, Ring_T, r_aggra },
  {   2, Ring_T, r_search },
  {   2, Ring_T, r_incr_dam },
  {   2, Wand_T, w_alchemy },
  {   2, Weapon_T, wp_sil_arrows },
  {   2, Wand_T, w_wonder },
  {   2, Potion_T, p_sustenance }, /* #54 */
  {   1, Weapon_T, wp_sil_sword },
  {   1, Ring_T, r_vampiric },
  {   1, Ring_T, r_invis },
  {   1, Wand_T, w_blunder },
  {   1, Ring_T, r_resur },
  {   1, Ring_T, r_decode },	/* #55 */
};

#if 0
    Delta_Dir[-1,-1] := '7'; /* #70 */
    Delta_Dir[-1,0] := '4';
    Delta_Dir[-1,1] := '1';
    Delta_Dir[0,-1] := '8';
    Delta_Dir[0,0] := '5';
    Delta_Dir[0,1] := '2';
    Delta_Dir[1,-1] := '9';
    Delta_Dir[1,0] := '6';
    Delta_Dir[1,1] := '3';
#endif

char Delta_Dir[3][3] = { /* #70 */
  { '7', '4', '1' },
  { '8', '5', '2' },
  { '9', '6', '3' }
};

int Orig_X[Max_Room] = {
  1, 27, 53,
  1, 27, 53,
  1, 27, 53
};
int Orig_Y[Max_Room] = {
   1,  1,  1,			/* #71 all values were +1 */
   8,  8,  8,
  15, 15, 15
};

View_Array Old_World = { '&', '&', '&' }; /* This is an empty */

#if 0
bool Virgin = true;
bool Setup = true;
#endif
time_t Inidat;			/* #71 time and date game was started  */
struct tms Inirun;		/* #71 initial process runtime */
FILE *logfp = NULL;

/* * * * * * * * * * * * */
/* Start of actual code  */
/* * * * * * * * * * * * */

/* Screen handling routines */

/* Screen is 24 lines:
   0: echo
   1-21: map
   22: status line 1
   23: status line 2
*/

void Move_To_Echo() {
  move(Echo_Y, Echo_Pos_X);
}

void Clear_Echo() {
  move(Echo_Y, Echo_X);
  clrtoeol();
}

bool Are_same_type(char Ch1, char Ch2) {

  if (isalpha(Ch1))
    return isalpha(Ch2);
  else if (isdigit(Ch1))
    return isdigit(Ch2);
  else
    return false;
}

int Comand() {
  int ch;
  for (ch = getch(); ch < 0 || ch > 0177; ch = getch()) {
    if (logfp)
      fprintf(logfp, "Comand bogus %d\n", ch);
    flushinp();
    beep();
  }
  if (logfp)
    fprintf(logfp, "Comand good %d\n", ch);
  return(ch & 0177);
}

/* #54 Put this In To Read line Of shit from terminal */
bool Get_Line(Name_string NewName, int *Index) {

  int ix, iy, oldindex;
  char Dummy, Ch;
  bool More, Ok;

  Ok = true;
  *Index = 0;
  do {
    Ch = Comand();
    if (*Index == 0)
      clrtoeol();
    if (Ch == CHDEL) {
      Ch = CHBSP;
    }
    if (Ch >= SPACE) {
      if (*Index < Name_Len) {
	  NewName[(*Index)++] = Ch;
	  addch(Ch);
      } else {
	beep();
      }
    } else {
      switch (Ch) {

      case CHFFD:		/* C-L */
      case CHCTR:		/* C-R */
	clearok(stdscr, TRUE);	/* redraw */
	refresh();
	break;

      case CHBSP:
	if (*Index > 0) {	/* BS */
	  BKSP;			/* #63 */
	  addch(SPACE);
	  BKSP;
	  --(*Index);
	}
	break;

      case CHCTU:		/* C-U */
	getyx(stdscr, iy, ix);
	move(iy, ix - *Index);
	clrtoeol();
	refresh();
	*Index = 0;
	break;

      case CHCTW:		/* ^W */
	if (*Index == 0)
	  break;
	oldindex = *Index;
	Dummy = NewName[*Index - 1];
	More = true;
	while (More) {
	  --(*Index);
	  if (*Index == 0)
	    break;
	  if (Dummy == SPACE)
	    Dummy = NewName[*Index];
	  else
	    More = Are_same_type(Dummy, NewName[*Index]);
	}
	getyx(stdscr, iy, ix);
	move(iy, ix - (oldindex - *Index));
	clrtoeol();
	refresh();
	break;

      case CHESC:
	*Index = 0;
	Ok = false;
	break;

      case CHEOL:
      case CHLFD:
	break;

      default:
	if (logfp)
	  fprintf(logfp, "Get_Line: bogus char %d\n", Ch);
      }
    }
  } while (Ch != CHEOL && Ch != CHLFD && Ch != CHESC);
  NewName[*Index] = '\0';
  *Index = strlen(NewName);	/* #71 just in case */
  return Ok;
} /* Get_Line */

/* Waits for the player to type a space before typing out another line
   in the echo area (top line). */
bool Wait_For_Space(bool Any_Char) {
  char Ch;

  move(Echo_Y, 70);
  addstr("--More--");
  refresh();
  if (Any_Char)
    Ch = Comand();
  else {
    do {
      Ch = Comand();
    } while (Ch != SPACE &&
	     Ch != '0' &&
	     Ch != CHEOL &&
	     Ch != CHESC &&
	     Ch != CHDEL);	/* #54 add DEL */
  }
  move(Echo_Y, 70);
  clrtoeol();
  refresh();
  return (Ch != CHESC && Ch != CHDEL); /* #54 add DEL */
}

bool Has_on_ring(int Which_ind) {

  Hand_Type Hand;

  for (Hand = Left_H; Hand <= Right_H; Hand++) {
    if (Player.Cur_Ring[Hand] &&
	Player.Cur_Ring[Hand]->Index == Which_ind)
      return true;
  }
  return false;
} /* Has_on_ring */

	  /* * * * * * * * * * * * */
	  /* The display routines  */
	  /* * * * * * * * * * * * */

	  /*  Some Notes:					      */
	  /*     World.Seeable is an array of booleans.  Positions In */
	  /* this array are those that can be seen by the player.     */
	  /*     World.Seen are those places where the player has     */
	  /* been, i.e., has mapped.  He can see walls and floors and */
	  /* objects there, but not monsters.			      */
	  /*     World.Lines indicates which lines of the screen have */
	  /* changed for some reason or other. *NO LONGER USED*	      */
	  /*     World.S_World : Map				      */
	  /*     World.Mon : Monsters/Player			      */
	  /*     World.Obj : Objects				      */

	  /* So, to make something mapped, turn on world.seen;	       */
	  /*     to make something visible to the player, turn on      */
	  /*         world.seeable				       */
	  /* In either Case, turn on world.lines if a change is made.  */
	  /* however, for something to be seeable, its location should */
	  /* also be seen.					       */

char New_Char(int X, int Y, bool Show_Mon) {
  char ch;
  if (Show_Mon && World.Mon[X][Y]) {
    if (World.Mon[X][Y] == 'I' ||
	World.Mon[X][Y] == 'p') {
      /* It''s an invis. stalker or Phantom Stalker */
      if ((Player.Invis_count > 0) || (Has_on_ring(r_see_inv))) {
	/* for some reason they may see invisible things */
	ch = World.Mon[X][Y];
      }
      /* They mayn''t see it so handle normally */
      else if (World.Obj[X][Y]) {
	ch = World.Obj[X][Y];
      } else {
	ch = World.S_World[X][Y];
      }
    } else {
      ch = World.Mon[X][Y];
    }
  } else if (World.Obj[X][Y]) {
    ch = World.Obj[X][Y];
  } else {
    ch = World.S_World[X][Y];
  }
  return ch;
} /* New_Char */

void Redisplay() {
  move(Player.Loc.y, Player.Loc.x - 1);
  refresh();
} /* Redisplay */

void Gen_Screen() {

  int ii, ij;

  for (ij = Y_Orig; ij < S_Max_Y; ++ij) {
    move(ij, 0);
    for (ii = X_Orig; ii < S_Max_X; ++ii) {
      if (Player.Blind_count) {
	addch(' ');
      } else if (World.Seeable[ii][ij]) {
	/* Monsters may be seen in this case (Within sight) */
	addch(New_Char(ii, ij, true));
      } else if (World.Seen[ii][ij]) {
	/* But may not be seen in this case (in a place that has been seen) */
	addch(New_Char(ii, ij, false));
      } else {
	/* NOTHING may be seen in this case */
	addch(' ');
      }
    }
  }
} /* Gen_Screen */

void Show_Stats() {
  char status[80];

  /*  With Player do */

  if (Player.Level >= 5 && ((Change_stats & S_Top) != 0)) {
    move(Status_Y, Status_X);
    sprintf(status, "St: %d(%d) Dex: %d(%d) Int: %d(%d)",
	    Player.ST, Player.Max_ST, Player.DX,
	    Player.Max_DX, Player.IQ, Player.Max_IQ);
    addstr(status); clrtoeol();
  }
  if ((Change_stats & S_Bottom) != 0) {
    move(Status_Y + 1, Status_X);
    sprintf(status, "Gold: %d Level: %d Xp: %d/%d Ac: %d Hp: %d(%d)",
	    Player.Gold, World.Level, Player.Level, Player.XP,
	    Player.AC, Player.HP, Player.Max_HP);
    addstr(status);
    if (Player.Last_meal >= Fainting_Meal)
      addstr(" Fainting");
    else if (Player.Last_meal >= Weak_Meal)
      addstr(" Weak");
    else if (Player.Last_meal >= Hungry_Meal)
      addstr(" Hungry");
    clrtoeol();
  }
  Change_stats = 0;
} /* Show_Stats */

void Update_Screen() {
  if (! (Valid_Command && Switches.Jump_swi)) {
    Gen_Screen(); /* Build the new screen setting the Lines and Show flags */
    Show_Stats();
    Redisplay();
  }
} /* Update_Screen */

void Echo_Init() {		/* #63 */
  F = Echo_Str;
  *F = '\0';
}

void StartText() {
  TextLine = Echo_Y;
}

void AddText(char *s) {
  move(TextLine++, 0);
  addstr(s);
  clrtoeol();
}

/* Procedure to echo a line on the top of the screen */
/* The procedure should NOT change the value of string S */
/* Many changes, including ring buffer of last 5 echoes */
void Echo(char *S) {

  bool More,Save_Valid;

  if (! Empty_Echo)
    More = !Wait_For_Space(false);
  Empty_Echo = false;
  if (S[0]) {
    strcpy(Last_echo[Echo_point], S);
    Clear_Echo();
    addstr(S);
    Echo_Pos_X = strlen(S) + 1;	/* #71 fencepost */
    Echo_index = Echo_point;	/* #50 */
    Echo_point = (Echo_point + 4) % 5; /* #50 make it go backwards */
  } else {
    Clear_Echo();
    addstr(Last_echo[Echo_index]);
    Echo_index = (Echo_index + 1) % 5;
  }
  Save_Valid = Valid_Command;	/* #60 */
  Valid_Command = false;
  Update_Screen();
  Valid_Command = Save_Valid;
} /* Echo */

void Scr_Text(int Y, char *S) {
  move(Y, 0);
  clrtoeol();
  addstr(S);
} /* Scr_Text */

/* This turns on/off the lights In a lit room. */
void Draw_Room(int Room, bool Lights_On) {

  int ii,ij;
  Room_Type *rp;

  if (Room < 0) {
    if (logfp)
      fprintf(logfp, "Error!! Draw_Room called With Room < 0!\n");
    return;
  }

  /* With World.Rooms[Room] Do */
  rp = &World.Rooms[Room];

  if (! rp->Light) {
    if (logfp)
      fprintf(logfp, "Error!! Draw_Room called With Dark room %d!\n", Room);
    return;
  }

  if (!rp->Seen && Lights_On) {
    for (ij = rp->Abs_Y; ij <= (rp->Abs_Y + rp->Max_Y + 1); ++ij) {
      for (ii = rp->Abs_X; ii <= (rp->Abs_X + rp->Max_X + 1); ++ii) {
	World.Seen[ii][ij] = true;
      }
    }
    rp->Seen = true;
  }
  for (ij = rp->Abs_Y; ij <= (rp->Abs_Y + rp->Max_Y + 1); ++ij) {
    for (ii = rp->Abs_X; ii <= (rp->Abs_X + rp->Max_X + 1); ++ii) {
      World.Seeable[ii][ij] =
	(Lights_On ||
	 ((Player.SeeMon_count > 0) &&
	  (World.Mon[ii][ij])));
    }
  }
} /* Draw_Room */

/* D_Hallway used While moving from hallway To hallway */
void D_Hallway() {

  int X_Dif,Y_Dif, I,J,T,U,V;

  X_Dif = Player.Loc.x - Player.Prev.x;
  Y_Dif = Player.Loc.y - Player.Prev.y;
  if ((abs(X_Dif) > 1) || (abs(Y_Dif) > 1)) {
    if (logfp)
      fprintf(logfp, "You shouldn\'t have called D_Hallway with this location.\n");
    return;
  }

  if (X_Dif != 0) {
    T = Player.Prev.x - X_Dif;
    U = Player.Loc.x + X_Dif;
    for (J = -1; J <= 1; ++J) {
      V = Player.Prev.y + J;
      World.Seeable[T][V] = ((Player.SeeMon_count > 0) && World.Mon[T][V]);
      V = Player.Loc.y + J;
      World.Seen[U][V] = (World.Seen[U][V] ||
			  World.S_World[U][V] == '#' ||
			  World.S_World[U][V] == '+');
      World.Seeable[U][V] = World.Seen[U][V];
    }
  }
  if (Y_Dif != 0) {
    T = Player.Prev.y - Y_Dif;
    U = Player.Loc.y + Y_Dif;
    for (I = -1; I <= 1; ++I) {
      V = Player.Prev.x + I;
      World.Seeable[V][T] = ((Player.SeeMon_count > 0) && World.Mon[V][T]);
      V = Player.Loc.x + I;
      World.Seen[V][U] = (World.Seen[V][U] ||
			  World.S_World[V][U] == '#' ||
			  World.S_World[V][U] == '+');
      World.Seeable[V][U] = World.Seen[V][U];
    }
  }
} /* D_Hallway */

/* D_Dark_Room is used While stepping within a dark room */
void D_Dark_Room() {

  int X_Dif,Y_Dif, I,J,T,U,V;

  X_Dif = Player.Loc.x - Player.Prev.x;
  Y_Dif = Player.Loc.y - Player.Prev.y;
  if ((abs(X_Dif) > 1) || (abs(Y_Dif) > 1)) {
    if (logfp)
      fprintf(logfp, "You shouldn\'t have called this procedure with this location.\n");
    return;
  }

  if (X_Dif) {
    T = Player.Prev.x - X_Dif;
    U = Player.Loc.x + X_Dif;
    for (J = -1; J <= 1; ++J) {
      V = Player.Prev.y + J;
      World.Seeable[T][V] = ((Player.SeeMon_count > 0) && World.Mon[T][V]);
      World.Seen[T][V] = ((World.S_World[T][V] != '.') || World.Obj[T][V]);
      V = Player.Loc.y + J;
      World.Seen[U][V] = true;
      World.Seeable[U][V] = true;
    }
  }
  if (Y_Dif) {
    T = Player.Prev.y - Y_Dif;
    U = Player.Loc.y + Y_Dif;
    for (I = -1; I <= 1; ++I) {
      V = Player.Prev.x + I;
      World.Seeable[V][T] = ((Player.SeeMon_count > 0) && World.Mon[V][T]);
      World.Seen[V][T] = ((World.S_World[V][T] != '.') || World.Obj[V][T]);
      V = Player.Loc.x + I;
      World.Seen[V][U] = true;
      World.Seeable[V][U] = true;
    }
  }
} /* D_Dark_Room */

void D_Lit_Room() {
  /* nothing to do? */
} /* D_Lit_Room */

/* Used when stepping from a doorway into the hallway */
void D_Out_Door() {
  int Oroom, T, U, I, J;

  Oroom = World.Room_array[Player.Prev.x][Player.Prev.y];
  if (World.Rooms[Oroom].Light) {
    Draw_Room(Oroom, false);	/* Turn off the lights */
  } else {
    /* was In dark room */
    for (J = -1; J <= 1; ++J) {
      U = Player.Prev.y + J;
      for (I = -1; I <= 1; ++I) {
	T = Player.Prev.x + I;
	World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
	World.Seen[T][U] = ((World.S_World[T][U] != '.') || World.Obj[T][U]);
      }
    }
  }

  for (J = -1; J <= 1; ++J) {
    U = Player.Loc.y + J;
    for (I = -1; I <= 1; ++I) {
      T = Player.Loc.x + I;
      World.Seen[T][U] =
	(World.Seen[T][U] ||
	 World.S_World[T][U] == '#' ||
	 World.S_World[T][U] == '+');
      World.Seeable[T][U] = World.Seen[T][U];
    }
  }
} /* D_Out_Door */

/* Used when stepping from hallway onto the doorway */
void D_In_Door() {
  int Room, X_Dif, Y_Dif, T, U, I, J;

  X_Dif = Player.Loc.x - Player.Prev.x;
  Y_Dif = Player.Loc.y - Player.Prev.y;
  if (X_Dif) {
    T = Player.Prev.x - X_Dif;
    for (J = -1; J <= 1; ++J) {
      U = Player.Prev.y + J;
      World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
    }
  }
  if (Y_Dif) {
    U = Player.Prev.y - Y_Dif;
    for (I = -1; I <= 1; ++I) {
      T = Player.Prev.x + I;
      World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
    }
  }
  Room = World.Room_array[Player.Loc.x][Player.Loc.y];
  if (World.Rooms[Room].Light) {
    Draw_Room(Room, true);	/* Turn on the lights */
  } else {
    for (J = -1; J <= 1; ++J) {
      U = Player.Loc.y + J;
      for (I = -1; I <= 1; ++I) {
	T = Player.Loc.x + I;
	World.Seen[T][U] = true;
	World.Seeable[T][U] = true;
      }
    }
  }
} /* D_In_Door */

/* used when stepping from the room proper onto the doorway */
void D_On_Door() {
  int Room, X_Dif, Y_Dif, T, U, I, J;

  Room = World.Room_array[Player.Prev.x][Player.Prev.y];
  if (!World.Rooms[Room].Light) {
    X_Dif = Player.Loc.x - Player.Prev.x;
    Y_Dif = Player.Loc.y - Player.Prev.y;
    if (X_Dif) {
      T = Player.Prev.x - X_Dif;
      for (J = -1; J <= 1; ++J) {
	U = Player.Prev.y + J;
	World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
	World.Seen[T][U] = ((World.S_World[T][U] != '.') || World.Obj[T][U]);
      }
    }
    if (Y_Dif) {
      U = Player.Prev.y - Y_Dif;
      for (I = -1; I <= 1; ++I) {
	T = Player.Prev.x + I;
	World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
	World.Seen[T][U] = ((World.S_World[T][U] != '.') || World.Obj[T][U]);
      }
    }
  }

  for (J = -1; J <= 1; ++J) {
    U = Player.Loc.y + J;
    for (I = -1; I <= 1; ++I) {
      T = Player.Loc.x + I;
      World.Seen[T][U] =
	(World.Seen[T][U] ||
	 World.S_World[T][U] == '#' ||
	 World.S_World[T][U] == '+');
      World.Seeable[T][U] = true; /* #56 */
    }
  }
} /* D_On_Door */

/* Used when stepping from a doorway into the room proper */
void D_Off_Door() {
  int Room, T, U, I, J;

  for (J = -1; J <= 1; ++J) {
    U = Player.Prev.y + J;
    for (I = -1; I <= 1; ++I) {
      T = Player.Prev.x + I;
      Room = World.Room_array[T][U];
      if (Room < 0) {
	World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
      } else if (!World.Rooms[Room].Light) {
	World.Seeable[T][U] = ((Player.SeeMon_count > 0) && World.Mon[T][U]);
	World.Seen[T][U] = ((World.S_World[T][U] != '.') || World.Obj[T][U]);
      }
    }
  }

  Room = World.Room_array[Player.Loc.x][Player.Loc.y];
  if (!World.Rooms[Room].Light) {
    for (J = -1; J <= 1; ++J) {
      U = Player.Loc.y + J;
      for (I = -1; I <= 1; ++I) {
	T = Player.Loc.x + I;
	if (World.Room_array[T][U] >= 0) {
	  World.Seen[T][U] = true;
	  World.Seeable[T][U] = true;
	}
      }
    }
  }
} /* D_Off_Door */

void Player_Disappears() {
  bool Dark;
  int Room,
  T, U,
  I, J;

  Room = World.Room_array[Player.Prev.x][Player.Prev.y];
  Dark = true;
  if (Room >= 0 && World.Rooms[Room].Light) {
    Draw_Room(Room, false);
    Dark = false;
  }
  for (J = -1; J <= 1; ++J) {
    T = Player.Prev.y + J;
    for (I = -1; I <= 1; ++I) {
      U = Player.Prev.x + I;
      World.Seeable[U][T] = ((Player.SeeMon_count > 0) && World.Mon[U][T]);
      if (Dark)
	World.Seen[U][T] = ((! (World.S_World[U][T] == ' ' ||
				World.S_World[U][T] == '.')) ||
			    World.Obj[U][T]);
    }
  }
} /* Player_Disappears */

void Player_Appears() {
  int Room,PRoom,
  I, J, T, U;

  PRoom = World.Room_array[Player.Loc.x][Player.Loc.y];
  if (PRoom >= 0 && World.Rooms[PRoom].Light) {
      Draw_Room(PRoom, true);	/* Turn on the lights */
  }
  for (J = -1; J <= 1; ++J) {
    T = Player.Loc.y + J;
    for (I = -1; I <= 1; ++I) {
      U = Player.Loc.x + I;
      Room = World.Room_array[U][T];
      if (Room >= 0) {
	if (World.S_World[U][T] == '-' ||
	    World.S_World[U][T] == '|')
	  World.Seen[U][T] = (World.Seen[U][T] || PRoom >= 0);
	else {
	  World.Seen[U][T] = (World.S_World[U][T] != ' ');
	  World.Seeable[U][T] = World.Seen[U][T];
	}
      } else {
	World.Seen[U][T] = (World.S_World[U][T] == '#');
	World.Seeable[U][T] = World.Seen[U][T];
      }
    }
  }
} /* Player_Appears */

void Player_Jumps() {
  Player_Disappears();
  Player_Appears();
} /* Player_Jumps */

void New_Place_Player() {
  Player.Prev = Player.Loc;
} /* New_Place_Player */

void Player_Takes_Step() {
  int Room,ORoom;

  ORoom = World.Room_array[Player.Prev.x][Player.Prev.y];
  Room  = World.Room_array[Player.Loc.x][Player.Loc.y];

  if (Room < 0) {
    if (ORoom < 0) {
      D_Hallway();		/* still In hallway */
    } else {
      D_Out_Door();		/* stepped from a room into hall */
    }
  } else if (ORoom < 0) {
    D_In_Door();		/* stepped from hall into doorway */
  } else {
    if (World.S_World[Player.Loc.x][Player.Loc.y] == '+') {
      if (World.S_World[Player.Prev.x][Player.Prev.y] == '+') {
	D_Off_Door();
      }
      D_On_Door();		/* stepped from room onto doorway */
    } else if (World.S_World[Player.Prev.x][Player.Prev.y] == '+') {
      D_Off_Door();	   /* stepped from doorway into room proper */
    } else {
      if (World.Rooms[Room].Light)
	D_Lit_Room();
      else
	D_Dark_Room();
    }
  }
} /* Player_Takes_Step */

void Restore_screen() {
  clear();
  Change_stats = S_Top|S_Bottom;
  New_Place_Player();
  Update_Screen();
}

bool Name_check(char *name) {
  struct passwd *pwp;
  uid_t uid;

  uid = getuid();
  pwp = getpwuid(uid);
  if (!strcmp(name, pwp->pw_name))
    return true;		/* hey, it's us! */

  pwp = getpwnam(name);
  if (pwp == NULL) {
    return true;
  }
  if (pwp->pw_uid != uid)
    return false;
  return true;			/* probably cannot happen */

} /* Name_check */

void Write_Killer(char *fp, char Killer) {

  int Mon_num;
  Monsters *mp;
  char ch;

  if (Killer == ' ')
    strcpy(fp, " Quit");
  else if (Killer == '$')
    strcpy(fp, " A Winner!");
  else if (Killer == ')')
    strcpy(fp, " Killed by an arrow");
  else if (Killer == '=')
    strcpy(fp, " Killed by magic");
  else if (Killer == 'j')
    strcpy(fp, " Killed by Juiblex");
  else if (isalpha(Killer)) {
    if (islower(Killer))
      Mon_num = Killer - Mon_hi_offset;
    else
      Mon_num = Killer - Mon_lo_offset;
    mp = &Monster[Mon_num];
    ch = mp->Long_Name[0];
    if (ch == 'a' ||
	ch == 'e' ||
	ch == 'h' ||
	ch == 'i' ||
	ch == 'o' ||
	ch == 'u')
      sprintf(fp, " Killed by an %s", mp->Long_Name);
    else
      sprintf(fp, " Killed by a %s", mp->Long_Name);
  }
} /* Write_killer */

int Personal_scores(bool rstat) { /* #71 */
  int I,J, level;
  bool Found;
  Personals Personal;
  char Mon[4], Day[3], Year[5], killer, best;
  Long_string line;
  char *tok;
  char *timep;
  int retval;
  FILE *F;
  time_t tt;

  for (I = 0; I < 10; ++I) {
    Personal[I].Score = 0;
    Personal[I].Rest[0] = '\0';
  }
  I = 0;
  Found = true;
  F = fopen(".rogue.scores", "r");
  if (F) {
    while (fgets(line, LONG_LEN, F) != NULL && I < 10) {
      tok = strtok(line, " \n");
      if (tok)
	Personal[I].Score = atoi(tok);
      else
	break;
      tok = strtok(NULL, "\n");
      if (tok)
	strncpy(Personal[I].Rest, tok, LONG_LEN - 1);
      else {
	Found = false;
	break;
      }
      I++;
    }
    fclose(F);
  }
  if (!Found) {			/* #71 score file is munged, clear it */
    for (I = 0; I < 10; ++I) {
      Personal[I].Score = 0;
      Personal[I].Rest[0] = '\0';
    }
  }
  I = 0;
  Found = false;
  retval = 0;
  while (I < 10 && ! Found)
    if (Player.Gold > 0 && Player.Gold > Personal[I].Score)
      Found = true;
    else
      I++;
  if (Found) {
    retval = I + 1;
    for (J = 9; J >= I + 1; --J) {
      Personal[J].Score = Personal[J - 1].Score;
      strcpy(Personal[J].Rest, Personal[J - 1].Rest);
    }
    Personal[I].Score = Player.Gold;

    tt = time(NULL);
    timep = ctime(&tt);		/* "Wed Jun 30 21:49:08 1993\n" */
    tok = strtok(timep, " ");	/* Wed */
    tok = strtok(NULL, " ");	/* Jun */
    strcpy(Mon, tok);
    tok = strtok(NULL, " ");	/* 30 */
    strcpy(Day, tok);
    tok = strtok(NULL, " ");	/* 21:49:08 */
    tok = strtok(NULL, " \n");	/* 1993 */
    J = atoi(Day);

    sprintf(Personal[I].Rest, "%s-%s-%02d %d '%c' %s", /* #71 new format... */
	    tok, Mon, J, World.Level, Killer, Player.Name);

    F = fopen(".rogue.scores", "w");
    if (F) {
      for (I = 0; I < 10; ++I)
	if (Personal[I].Score > 0)
	  fprintf(F, "%d %s\n", Personal[I].Score, Personal[I].Rest);
      fclose(F);
    }
  }

  /* #71 display list of top 10 personal scores */
  clear();
  StartText();
  AddText("  Top Ten Personal Scores");
  AddText("");
  AddText("  Score      Date         Level   How Died");
  AddText("  -----      ----         -----   --------");
  for (I = 0; I < 10; ++I) {
    if (Personal[I].Score == 0)
      break;
    best = (I == retval - 1 ? '>' : ' ');
    J = sscanf(Personal[I].Rest, "%4c-%3c-%2c %d '%c' %s",
	       Year, Mon, Day, &level, &killer, line);
    Year[4] = '\0';
    Day[2] = '\0';
    Mon[3] = '\0';
    if (J == 6) {
      Echo_Str[0] = '\0';
      Write_Killer(Echo_Str, killer);
      if (Echo_Str[0] == '\0')
	strcat(Echo_Str, " Unknown");
      sprintf(line, "%c %4d g.p.  %s-%s-%s   %4d  %s",
	      best, Personal[I].Score, Day, Mon, Year, level, Echo_Str);
    } else {
      sprintf(line, "%c %4d g.p.  %s", best, Personal[I].Score, Personal[I].Rest);
    }
    AddText(line);
  }
  if (rstat) {
    AddText("");
    AddText("[Type anything to continue] ");
    Comand();
  } else
    Wait_For_Space(true);

  return retval;
} /* Personal_scores */

void Lose_Old_World() {
  Obj_Ptr T;
  Mon_Ptr M;
  Trap_Ptr R;

  while (World.Traps) {		/* Rid the world of traps, */
    R = World.Traps;
    World.Traps = World.Traps->Next;
    free(R);
  }
  while (World.Objs) {		/* of objects, */
    T = World.Objs;
    World.Objs = World.Objs->Next;
    free(T);
  }
  while (World.Monsters) {	/* and of monsters. */
    M = World.Monsters;
    World.Monsters = World.Monsters->Next;
    free(M);
  }
} /* Lose_Old_World */

#if 0
Function Get_Names : Nam_ptr; /* #63 */
Var
  More : Boolean;
  This_un : Name_Rec;
  Names,Entry : Nam_ptr;
Begin /* Get_names */
  Lose_Old_World(); /* #70 Put it back in, maybe monster cleanup fixed it. */
/* #69 I don't know why this is dying, but somehow the object list is */
/*    getting fucked up, so Lose_Old_World dies in the Object Dispose */
/*    loop.  I guess it's not exactly important to clean this stuff up */
/*    so we'll just skip it fornaio. */
  Names := NIL;
  Reset(Nm,Files.Names^,'/I/D/F/O',0,0,[29]);
  More := true;
  While More Do
    If EOF(Nm) Then
      More := false
    Else
      Begin
	Get(Nm);
	This_Un.Num := Nm^.Num;
	This_Un.Nam := Nm^.Nam;
	If (Names = NIL) Then
	  Begin
	    New(Names);
	    Entry := Names
	  End
	Else
	  Begin
	    New(Entry^.Next);
	    Entry := Entry^.Next
	  End;
	Entry^ := This_un;
	Entry^.Next := NIL
      End;
  Close(Nm);
  Get_Names := Names
End; /* Get_names */

Procedure Write_name (Names : Nam_ptr; Usernum : Integer); /* #63 */
Var
  More : Boolean;
  Name : Long_string;
  Entry : Nam_ptr;
Begin /* Write_name */
  More := true;
  Entry := Names;
  While More Do
    If (Entry = NIL) Then
      More := false
    Else
      If (Entry^.Num = Usernum) Then
      More := false
    Else
      Entry := Entry^.Next;
  If (Entry = NIL) Then
    Begin
      JSYS(41B,1;-1:Name,Usernum); /* DIRST */
      Fix_String(Name);
      Write(tty,Name:25)
    End
  Else
    Write(tty,Entry^.Nam:25)
End; /* Write_name */
#endif

void Show_Scores(bool rstat) {
  bool Show_em;

  Show_em = (Player_Move != CHDEL && Player_Move != CHESC);
#if 0
  This_guy : Score_rec;
  I : Integer;
  Ch : Char;
  Names,Entry : Nam_ptr;
  All_time,Weekly : Score_array;
Begin /* Show_Scores */
  If Isddt Then
    Writeln(tty)
  Else
    Begin
      Names := NIL;
      JSYS(13B;;This_guy.User);	/* GJINF */
      This_guy.Score := Score;
      This_guy.Level := Level;
      This_guy.Day := '     ';
      This_guy.Killer := Killer;
      If Not Scores(All_time,Weekly,This_guy,Files.Score^) Then
	Show_em := false; /* #48 */
      Deinterrupts;
      If Show_em Then
	Begin
	  Names := Get_names; /* #63 */
	  Writeln(tty,'Weekly high scores:');
	  For I := 1 To 41 Do Write(Tty,'-'); Writeln(Tty);
	  For I := 1 To 10 Do
	    With Weekly[I] Do
	      If Score > 0 Then
		Begin
		  Write(tty,I:2,'. ',Score:5,' ');
		  Write_name(Names,User); /* #63 */
		  Write(tty,' ',Day:5);
		  Write_killer(tty,Killer);
		  Writeln(tty,' (',Level:0,')');
		End;
	  Write(tty,'[Press space to continue, delete to stop]'); /* #66 */
	  Show_em := (Comand() <> Chr(177B)); /* #50 */
	End;
      If Show_em Then
	Begin
	  Cls;
	  Writeln(tty,'All-time high scores:');
	  For I := 1 To 41 Do Write(tty,'-'); Writeln(tty);
	  For I := 1 To 10 Do
	    With All_time[I] Do
	      If Score > 0 Then
		Begin
		  Write(tty,I:2,'. ',Score:5,' ');
		  Write_name(Names,User); /* #63 */
		  Write(tty,' ',Day:5);
		  Write_killer(tty,Killer);
		  Writeln(tty,' (',Level:0,')')
		End
	End /* If Show_Em */
      Else
	Writeln(tty);
      While (Names <> NIL) Do /* #63 */
	Begin
	  Entry := Names;
	  Names := Names^.Next;
	  Dispose(Entry)
	End;
#endif
  Personal_scores(rstat);	/* #71 */
} /* Show_Scores */

/* return a number between 1 and Limit, inclusive */
int Die(int Limit) {
  int val;
  if (Limit <= 0) {
    if (logfp)
      fprintf(logfp, "Die %d\n", Limit);
    val = 0;
  } else
    val = (int)(random() % ((long int)Limit)) + 1;
  return val;
} /* Die */

int Two_to_the(int A) {
  int iX;

  iX = 1 << A;			/* quick shift! */
  return iX;
}

int Sign(int I) {
  if (I > 0)
    return 1;
  else if (I < 0)
    return -1;
  return 0;
}

/* FUL?  Why FUL? */
void FUL() {

  int  Room;

#if 0
/* these next two sets of array assignments should be in an initprocedure,
   but this will have to do until it's determined why their values get
   changed.  */

  Orig_X[1] := 1;  Orig_X[2] := 27;  Orig_X[3] := 53;
  Orig_X[4] := 1;  Orig_X[5] := 27;  Orig_X[6] := 53;
  Orig_X[7] := 1;  Orig_X[8] := 27;  Orig_X[9] := 53;

  Orig_Y[1] := 2;  Orig_Y[2] := 2;   Orig_Y[3] := 2;
  Orig_Y[4] := 9;  Orig_Y[5] := 9;   Orig_Y[6] := 9;
  Orig_Y[7] := 16; Orig_Y[8] := 16;  Orig_Y[9] := 16;
#endif

  for (Room = 0; Room < Max_Room; ++Room) {
    World.Rooms[Room].Abs_X = Die(Max_Cell_X - 4) + Orig_X[Room] - 1;
    World.Rooms[Room].Abs_Y = Die(Max_Cell_Y - 4) + Orig_Y[Room] - 1;
    World.Rooms[Room].Max_X = 0;
    World.Rooms[Room].Max_Y = 0;

    if (logfp)
      fprintf(logfp, "FUL: Room %d (%d,%d)\n", Room,
	      World.Rooms[Room].Abs_X, World.Rooms[Room].Abs_Y);
  }
} /* FUL */

/* These were all internal to Siz() */
int R_X(int Room) {
  switch (Room + 1) {
  case 1:
  case 2:
  case 4:
  case 5:
  case 7:
  case 8:
    return World.Rooms[Room + 1].Abs_X;
  case 3:
  case 6:
  case 9:
    return S_Max_X + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* R_X */

int RD_X(int Room) {
  switch (Room + 1) {
  case 1:
  case 2:
  case 4:
  case 5:
    return World.Rooms[Room + 4].Abs_X;
  case 3:
  case 6:
  case 7:
  case 8:
  case 9:
    return S_Max_X + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* RD_X */

int UR_X(int Room) {
  switch (Room + 1) {
  case 4:
  case 5:
  case 7:
  case 8:
    return World.Rooms[Room - 2].Abs_X;
  case 1:
  case 2:
  case 3:
  case 6:
  case 9:
    return S_Max_X + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* UR_X */

int RD_Y(int Room) {
  switch (Room + 1) {
  case 1:
  case 2:
  case 4:
  case 5:
    return World.Rooms[Room + 4].Abs_Y;
  case 3:
  case 6:
  case 7:
  case 8:
  case 9:
    return S_Max_Y + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* RD_Y */

int DR_Y(int Room) {
  switch (Room + 1) {
  case 2:
  case 3:
  case 5:
  case 6:
    return World.Rooms[Room + 2].Abs_Y;
  case 1:
  case 4:
  case 7:
  case 8:
  case 9:
    return S_Max_Y + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* DR_Y */

int D_Y(int Room) {
  switch (Room + 1) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    return World.Rooms[Room + 3].Abs_Y;
  case 7:
  case 8:
  case 9:
    return S_Max_Y + 1;
  }
  return -1;			/* #71 should NOT happen */
} /* D_Y */

int min(int x, int y) {
  return (x <= y ? x : y);
}

int max(int x, int y) {
  return (x >= y ? x : y);
}

void Siz() {
  int I,J,Room;
  Room_Type *rp;
  int min1, min2, range, endy, endx;

  for (Room = 0; Room < Max_Room; ++Room) {
    rp = &World.Rooms[Room];
    if (! rp->Existent) {
      rp->Max_X = 0;
      rp->Max_Y = 0;
    } else {
      min1 = min(R_X(Room), RD_X(Room));
      min2 = min(min1, UR_X(Room));
      range = min2 - 4 - rp->Abs_X;

      if (logfp)
	fprintf(logfp, "Room %d X: min1 %d min2 %d range %d\n",
		Room, min1, min2, range);

      rp->Max_X = max(Die(range) + 1, Die(range) + 1);

      min1 = min(D_Y(Room), RD_Y(Room));
      min2 = min(min1, DR_Y(Room));
      range = min2 - 4 - rp->Abs_Y;

      if (logfp)
	fprintf(logfp, "Room %d Y: min1 %d min2 %d range %d\n",
		Room, min1, min2, range);

      /* #71 allow for slightly smaller rooms */
      rp->Max_Y = /*max(*/max(Die(range) + 1, Die(range) + 1);/*),
		      max(Die(range) + 1, Die(range) + 1)); */

      /* Maybe this will catch some of the weird errors */
      /* #71 The maps are actually better if these checks are not honored */
      if (rp->Max_Y > Max_Room_Y || rp->Max_Y < Min_Room_Y) {
	if (logfp)
	  fprintf(logfp, "Room %d Max_Y==%d error\n", Room, rp->Max_Y);
	/*	rp->Max_Y = Max_Room_Y; */
      }
      if (rp->Max_X > Max_Room_X || rp->Max_X < Min_Room_X) {
	if (logfp)
	  fprintf(logfp, "Room %d Max_X==%d error\n", Room, rp->Max_X);
	/*	rp->Max_X = Max_Room_X; */
      }

      /* precalculate bottom/right end of room */
      endx = rp->Abs_X + rp->Max_X + 1;
      endy = rp->Abs_Y + rp->Max_Y + 1;

      for (I = rp->Abs_Y; I <= endy; ++I) {
	World.S_World[rp->Abs_X][I] = '|';
	World.S_World[endx][I] = '|';
	World.Room_array[rp->Abs_X][I] = Room;
	World.Room_array[endx][I] = Room;
      }
      for (I = rp->Abs_X; I <= endx; ++I) {
	World.S_World[I][rp->Abs_Y] = '-';
	World.S_World[I][endy] = '-';
	World.Room_array[I][rp->Abs_Y] = Room;
	World.Room_array[I][endy] = Room;
      }
      for (I = rp->Abs_X + 1; I < endx; ++I) {
	for (J = rp->Abs_Y + 1; J < endy; ++J) {
	  World.S_World[I][J] = '.';
	  World.Room_array[I][J] = Room;
	}
      }
    }
    if (logfp)
      fprintf(logfp, "Siz: Room %d (%d,%d) (%d,%d)\n",
	    Room, rp->Abs_X, rp->Abs_Y, rp->Max_X, rp->Max_Y);
  }
} /* Siz */

void Place_door(Room_Type *rp, int Door_num, int *x, int *y) {
  if (! rp->Existent) {
    *x = rp->Abs_X;
    *y = rp->Abs_Y;
  } else {
    switch (Door_num) {
    case Door_Up:
      *x = rp->Abs_X + Die(rp->Max_X);
      *y = rp->Abs_Y;
      break;
    case Door_Right:
      *x = rp->Abs_X + rp->Max_X + 1;
      *y = rp->Abs_Y + Die(rp->Max_Y);
      break;
    case Door_Down:
      *x = rp->Abs_X + Die(rp->Max_X);
      *y = rp->Abs_Y + rp->Max_Y + 1;
      break;
    case Door_Left:
      *x = rp->Abs_X;
      *y = rp->Abs_Y + Die(rp->Max_Y);
      break;
    default:
      if (logfp)
	fprintf(logfp, "Horrible error in Place_door\n");
    }
  }
}

void Dig(int Source, int Dest) {
  Loc_Type Start_loc,End_loc;
  int I,J,Source_door,Dest_door,Incr,Ran_dis;
  bool More,Broke;
  Room_Type *rp;

      /* Door numbering system: */
      /* up			*/
      /*      ---1---		*/
      /*      |     |		*/
      /*      4     2		*/
      /*      |     |		*/
      /* down ---3---		*/

  if (Dest == Source + Maze_Max_X)
    Source_door = Door_Down;	/* Down */
  else if (Dest == Source - Maze_Max_X)
    Source_door = Door_Up;		/* Up */
  else if (Dest == Source - 1)
    Source_door = Door_Left;	/* Left */
  else
    Source_door = Door_Right;	/* Right */

  rp = &World.Rooms[Source];
  Place_door(rp, Source_door, &Start_loc.x, &Start_loc.y);
  if (logfp)
    fprintf(logfp, "Dig: source Room %d door %s at (%d,%d)\n",
	    Source,
	    (Source_door == Door_Down ? "down" :
	     (Source_door == Door_Up ? "up" :
	      (Source_door == Door_Right ? "right" : "left"))),
	    Start_loc.x, Start_loc.y);

  rp = &World.Rooms[Dest];

  Dest_door = ((Source_door + 2) % 4);
  Place_door(rp, Dest_door, &End_loc.x, &End_loc.y);
  if (logfp)
    fprintf(logfp, "Dig: dest Room %d door %s at (%d,%d)\n",
	    Dest,
	    (Dest_door == Door_Down ? "down" :
	     (Dest_door == Door_Up ? "up" :
	      (Dest_door == Door_Right ? "right" : "left"))),
	    End_loc.x, End_loc.y);

  if ((Source_door == Door_Up) || (Source_door == Door_Down)) /* up or down */
    Ran_dis = Die(abs(End_loc.y - Start_loc.y) - 1);
  else
    Ran_dis = Die(abs(End_loc.x - Start_loc.x) - 1);

  if ((Source_door == Door_Up) || (Source_door == Door_Left)) /* up or left */
    Ran_dis = -Ran_dis;

  Broke = false;
  if ((Source_door == Door_Up) || (Source_door == Door_Down)) { /* up or down */
    if (Source_door == Door_Up)  /* up */
      Incr = -1;
    else
      Incr = 1;
    I = Start_loc.x;
    J = Start_loc.y + Incr;
    More = true;
    while (More)
      if (World.S_World[I][J] == '|' ||
	  World.S_World[I][J] == '-' ||
	  World.S_World[I][J] == '+') {
	J -= Incr;
	More = false;
      } else {
	More = (J != (Start_loc.y + Ran_dis));
	World.S_World[I][J] = '#';
	if (More)
	  J += Incr;
      }

    if (I != End_loc.x) {
      if (Start_loc.x < End_loc.x)
	Incr = 1;
      else
	Incr = -1;
      do {
	I += Incr;
	if (World.S_World[I][J] == '|' ||
	    World.S_World[I][J] == '-' ||
	    World.S_World[I][J] == '+') {
	  I -= Incr;
	  if (Start_loc.y < End_loc.y)
	    ++J;
	  else
	    --J;
	  Broke = ((J <= Y_Orig) || (J >= S_Max_Y));
	}
	World.S_World[I][J] = '#';
      } while (! (I == End_loc.x) || Broke);
    }
    if (Source_door == Door_Up)  /* up */
      Incr = -1;
    else
      Incr = 1;
    while ((J != End_loc.y) && (! Broke) &&
	   (J >= Y_Orig) && (J <= S_Max_Y)) {
      World.S_World[I][J] = '#';
      J += Incr;
    }
  } else {			/* dig right */
    if (Source_door == Door_Left)
      Incr = -1;
    else
      Incr = 1;
    I = Start_loc.x + Incr;
    J = Start_loc.y;
    More = true;
    while (More)
      if (World.S_World[I][J] == '|' ||
	  World.S_World[I][J] == '-' ||
	  World.S_World[I][J] == '+') {
	I -= Incr;
	More = false;
      } else {
	More = (I != (Start_loc.x + Ran_dis));
	World.S_World[I][J] = '#';
	if (More)
	  I += Incr;
      }
    if (J != End_loc.y) {
      if (Start_loc.y < End_loc.y)
	Incr = 1;
      else
	Incr = -1;
      do {
	J += Incr;
	if (World.S_World[I][J] == '|' ||
	    World.S_World[I][J] == '-' ||
	    World.S_World[I][J] == '+') {
	  J -= Incr;
	  if (Start_loc.x < End_loc.x)
	    I++;
	  else
	    I--;
	  Broke = ((I <= X_Orig) || (I >= S_Max_X));
	}
	World.S_World[I][J] = '#';
      } while (! (J == End_loc.y) || Broke);
    }
    if (Source_door == Door_Left)
      Incr = -1;
    else
      Incr = 1;
    while ((I != End_loc.x) && (! Broke)
	   && (I >= X_Orig) && (I <= S_Max_X)) {
      World.S_World[I][J] = '#';
      I += Incr;
    }
  }
  World.Rooms[Source].Doors[Source_door].Abs_loc = Start_loc;
  if ((Die(100) < World.Level - 2) && World.Rooms[Source].Existent)
    World.Rooms[Source].Doors[Source_door].Secret = (15 * Die(6));
  else
    World.Rooms[Source].Doors[Source_door].Secret = 0;

  if (World.Rooms[Source].Existent)
    if (World.Rooms[Source].Doors[Source_door].Secret > 0)
      if ((Source_door == Door_Up) || (Source_door == Door_Down)) /* top or bottom */
	World.S_World[Start_loc.x][Start_loc.y] = '-';
      else
	World.S_World[Start_loc.x][Start_loc.y] = '|';
    else
      World.S_World[Start_loc.x][Start_loc.y] = '+';
  else
    World.S_World[Start_loc.x][Start_loc.y] = '#';

  if (! Broke) {
    World.Rooms[Dest].Doors[Dest_door].Abs_loc = End_loc;
    if ((Die(100) < World.Level - 2) && World.Rooms[Dest].Existent)
      World.Rooms[Dest].Doors[Dest_door].Secret = (15 * Die(6));
    else
      World.Rooms[Dest].Doors[Dest_door].Secret = 0;

    if (World.Rooms[Dest].Existent)
      if (World.Rooms[Dest].Doors[Dest_door].Secret > 0)
	if ((Dest_door == Door_Up) || (Dest_door == Door_Down))
	  World.S_World[End_loc.x][End_loc.y] = '-';
	else
	  World.S_World[End_loc.x][End_loc.y] = '|';
      else
	World.S_World[End_loc.x][End_loc.y] = '+';
    else
      World.S_World[End_loc.x][End_loc.y] = '#';
  }
} /* Dig */

/* Build() was a function internal to Con_Table() */
void Build(int X, int Y) {

  Ct[X][Y].U = true;
  if (! Ct[X][Y-1].U) {
    Ct[X][Y].Up = true;
    Ct[X][Y-1].Dn = true;
    Build(X, Y-1);
  }
  if (! Ct[X][Y+1].U) {
    Ct[X][Y].Dn = true;
    Ct[X][Y+1].Up = true;
    Build(X,Y+1);
  }
  if (! Ct[X-1][Y].U) {
    Ct[X][Y].Lt = true;
    Ct[X-1][Y].Rt = true;
    Build(X-1,Y);
  }
  if (! Ct[X+1][Y].U) {
    Ct[X][Y].Rt = true;
    Ct[X+1][Y].Lt = true;
    Build(X+1,Y);
  }
} /* Build */

void Con_Table() {
  int I,J,X,Y;

  for (I = 1; I <= 3; ++I)
    for (J = 1; J <= 3; ++J) {
      Ct[I][J].U = false;
      Ct[I][J].Lt = false;
      Ct[I][J].Rt = false;
      Ct[I][J].Up = false;
      Ct[I][J].Dn = false;
    }
  for (I = 0; I <= 4; ++I) {
    Ct[I][0].U = true;
    Ct[I][4].U = true;
    Ct[0][I].U = true;
    Ct[4][I].U = true;
  }
  Build(Die(3), Die(3));
  J = Die(3);
  for (I = 1; I <= J; ++I) {
    X = Die(3);
    Y = Die(3);
    if ((! Ct[X][Y].Rt) && (X != 3)) { /* connect to rightmost neighbor  */
      Ct[X][Y].Rt = true;
      Ct[X+1][Y].Lt = true;
    } else if ((! Ct[X][Y].Lt) && (X != 1)) { /* connect to left neighbor */
      Ct[X][Y].Lt = true;
      Ct[X-1][Y].Rt = true;
    } else if ((! Ct[X][Y].Up) && (Y != 1)) { /* connect to neighbor above */
      Ct[X][Y].Up = true;
      Ct[X][Y-1].Dn = true;
    } else if ((! Ct[X][Y].Dn) && (Y != 3)) { /* connect to neighbor below */
      Ct[X][Y].Dn = true;
      Ct[X][Y+1].Up = true;
    }
  }
  for (X = 1; X <= Maze_Max_X; ++X) {
    for (Y = 1; Y <= Maze_Max_Y; ++Y) {
      if (Ct[X][Y].Rt)
	Dig((Y - 1) * Maze_Max_X + X - 1, /* #71 index -1 */
	    (Y - 1) * Maze_Max_Y + X); /* #71 index -1 */
      if (Ct[X][Y].Dn)
	Dig((Y - 1) * Maze_Max_X + X - 1, /* #71 index -1 */
	    Y * Maze_Max_Y + X - 1); /* #71 index -1 */
    }
  }
  if (logfp)
    fprintf(logfp, "\n");
} /* Con_Table */

void Pick_A_Place(int *X, int *Y) {
  int Room;
  int x,y;

  do {
    /* Find a random room */
    Room = Die(9) - 1;
    while (! World.Rooms[Room].Existent)
      Room = ((Room + 1) % 9);
    /* And then a random place in that room */
    x = Die(World.Rooms[Room].Max_X) + World.Rooms[Room].Abs_X;
    y = Die(World.Rooms[Room].Max_Y) + World.Rooms[Room].Abs_Y;
  } while (World.S_World[x][y] != '.' ||
	   World.Obj[x][y] ||
	   World.Mon[x][y]);	/* Make sure the place is virgin */
  *X = x;
  *Y = y;
} /* Pick_A_Place */

bool Weapon_is_ammo(int Idx) {
  return (Weapon[Idx].S_Num < 0 && Weapon[Idx].L_Num < 0);
}

void Magic_Aids(int Level, int Idx, Obj_Ptr P, Obj_Class_Type Typ) {
  switch (Typ) {		/* Handle special cases.. if any */

  case Gold_T:
    P->Quan = 1;
    if (Level > Amulet_level)
      P->Quan = 1 + Die(30);
    else
      P->Quan += max(Die(15 * Level), Die(15 * Level));
    break;

  case Wand_T:
    if (P->Index == w_fire ||
	P->Index == w_lightning ||
	P->Index == w_cold ||
	P->Index == w_alchemy ||
	P->Index == w_curing)
      P->Plus_Hit = 2 + Die(2);
    else if (P->Index == w_light)
      P->Plus_Hit = 10 + Die(6);
    else if (P->Index == w_wonder ||
	     P->Index == w_blunder)
      P->Plus_Hit = 15 + Die(20);
    else
      P->Plus_Hit = 5 + Die(2);
    break;

  case Ring_T:
    if (P->Index == r_teleport ||
	P->Index == r_aggra)
      P->Plus_Hit = -1;
    else if (P->Index == r_protect ||
	     P->Index == r_dex ||
	     P->Index == r_str ||
	     P->Index == r_int ||
	     P->Index == r_incr_dam)
      switch (Die(9)) {
      case 1: P->Plus_Hit = -2; break;
      case 2:
      case 3:
      case 4: P->Plus_Hit = -1; break;
      case 5:
      case 6:
      case 7:
      case 8: P->Plus_Hit = 1; break;
      case 9: P->Plus_Hit = 2;
      }
    else if (P->Index == r_resur) {
      int roll = Die(100);
      if (roll == 1)
	P->Plus_Hit = -1; /* Bad news for the team! */
      else if (roll >= 90 &&
	       roll <= 99)
	P->Plus_Hit = 2;	/* Wow two extra lives! */
      else if (roll == 100)
	P->Plus_Hit = 9;	/* Just like the cat on tv! */
      else
	P->Plus_Hit = 1;	/* Boring! */
    } else if (P->Index == r_decode) /* #55 */
      switch (Die(10)) {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
	P->Plus_Hit = (1 << Scroll_T); /* #71 simplify decode implementation */
	break;
      case 6:
      case 7:
      case 8: /* good */
	/* six bits for Ring_T|Wand_T|Scroll_T|Potion_T|Armor_T|Weapon_T */
	/* shifted over 2 bits to skip Amulet_T|Food_T */
	P->Plus_Hit = (Die(077) << 2) | (1 << Scroll_T);
	break;
      case 9:
      case 10: /* bad */
	P->Plus_Hit = -((Die(077) << 2) | (1 << Scroll_T));
	break;
      }
    P->Plus_Dam = 0;
    break;

  case Armor_T:
    switch (Die(20)) {
    case 1: P->Plus_Hit = -(Die(2) + 2); break; /* Horribly cursed */
    case 2:
    case 3: P->Plus_Hit = -(Die(2)); break; /* Cursed */
    case 4:
    case 5:
    case 6: P->Plus_Hit = Die(2); break; /* Average */
    case 7:
    case 8: P->Plus_Hit = (Die(2) + 1); break; /* Above Average */
    case 9: P->Plus_Hit = (Die(2) + 2); break; /* Incredible! */
    default: P->Plus_Hit = 0;
    }
    P->Plus_Dam = 0;
    break;

  case Weapon_T:
    P->Plus_Hit = 0;
    P->Plus_Dam = 0;
    if (Weapon_is_ammo(Idx)) {
      if (Idx == wp_sil_arrows) {
	P->Quan = 2 + Die(3);	/* silver arrows */
	P->Plus_Hit = 5 + Die(5);
	P->Plus_Dam = 5 + Die(5);
      } else if (Idx == wp_arrows)
	P->Quan = 20 + Die(20); /* Arrows */
      else
	P->Quan = 5 + Die(10);	/* Bolts and Rocks */
    } else
      P->Quan = 1;		/* only one of them */

    switch (Die(20)) {
    case 1: P->Plus_Hit -= (Die(2) + 2); break; /* Horribly cursed */
    case 2:
    case 3: P->Plus_Hit -= (Die(2)); break; /* Cursed */
    case 4:
    case 5:
    case 6: P->Plus_Hit += Die(2); break; /* Average */
    case 7:
    case 8: P->Plus_Hit += (Die(2) + 1); break; /* Above Average */
    case 9: P->Plus_Hit += (Die(2) + 2); /* Incredible! */
    }
    if (P->Plus_Hit < 0)
      P->Plus_Dam = Die(3) - 2;
    else if (P->Plus_Hit > 0)
      P->Plus_Dam = P->Plus_Hit + (Die(3) - 2);
    else
      P->Plus_Dam = 0;
    break;

  default:;			/* other types do not get aids */

  } /* Case */
  P->Cursed = (P->Plus_Hit < 0) || (P->Plus_Dam < 0);
  if (Die(30) == 1)
    P->Cursed = !P->Cursed;
} /* magic aids to game playing */

/* Rand_Obj was an internal function of Gen_Obj */
void Rand_Obj(Obj_Class_Type *Typ, int *Index) {
  int T,Idx;

  T = Die(Max_Chance);
  Idx = 0;
  while (T > Treasure[Idx].Chance) {
    T -= Treasure[Idx].Chance;
    Idx++;
  }
  /* Return the numbers */
  *Typ = Treasure[Idx].Typ;
  *Index = Treasure[Idx].Index;
} /* Rand_Obj */

void Gen_Obj(int Level, Obj_Ptr *Ptr) {
  int Idx;
  Obj_Class_Type Typ;
  Obj_Ptr P;

  P = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  *Ptr = P;

  if (Die(40) == 1) {		/* #63 */
    Typ = Food_T;
    Idx = Die(2) - 1;
  } else
    Rand_Obj(&Typ, &Idx);
  P->Obj_Typ = Typ;		/* Defaults */
  P->Index = Idx;
  P->Plus_Hit = 0;
  P->Plus_Dam = 0;
  P->Know_magic = false;
  P->Quan = 1;
  P->Cursed = 0;
  P->Next = NULL;

  Pick_A_Place(&P->Loc.x, &P->Loc.y);
  /* Try to spread out objects.  O_Used_list declared globally. */
  if (O_Used_list[World.Room_array[P->Loc.x][P->Loc.y]])
    Pick_A_Place(&P->Loc.x, &P->Loc.y);
  O_Used_list[World.Room_array[P->Loc.x][P->Loc.y]] = true;
  Magic_Aids(Level, Idx, P, Typ); /* Add magic plusses */
} /* Gen_Obj */

void Place_Obj(Obj_Ptr P) {
  char ch;
  P->Next = World.Objs;
  World.Objs = P;
  ch = World.Obj[P->Loc.x][P->Loc.y];
  switch (P->Obj_Typ) {
  case Gold_T:   ch = '*'; break;
  case Food_T:   ch = '&'; break;
  case Scroll_T: ch = '?'; break;
  case Potion_T: ch = '!'; break;
  case Wand_T:   ch = '/'; break;
  case Ring_T:   ch = '='; break;
  case Armor_T:  ch = '['; break;
  case Weapon_T: ch = ')'; break;
  case Amulet_T: ch = '$'; break;
  default:
    if (logfp)
      fprintf(logfp, "God-awful error in Place_Obj : No such object type!\n");
  }
  World.Obj[P->Loc.x][P->Loc.y] = ch;
} /* Place_Obj */

/* Get_Index was a function internal to Gen_monster */
int Get_Index() {
  int Index;
  int Count;

  Count = 0;
  do {
    Index = Die(Max_Monster) - 1;
    Count++;
  } while ((!(((World.Level >= Monster[Index].Min_Level) &&
	       (World.Level <= Monster[Index].Max_Level)) ||
	      ((Count >= 500) && (World.Level <= Monster[Index].Max_Level)))) ||
	   ((Index == m_mimic) && (World.Objs == NULL))); /* #71 */

  return Index;
} /* Get_Index */

void Gen_monster(int Level, int Avoid, Mon_Ptr *P_Mon, bool All_awake) {
  int I, Roll;
  Mon_Ptr P;

  P = (Mon_Ptr)malloc(sizeof(Monster_Typ));
  *P_Mon = P;

  P->Next = NULL;
  P->Index = Get_Index();
  P->HP = 0;
  P->Paralyzed_count = 0;
  P->Confused_count = 0;
  P->Speed = 2;
  P->Speed_count = 0;
  P->Who_first = 0;
  P->Last_Dir = '5';		/* #71 */

  /* Find out where it should go */
  /* If a mimic, Then Put it In the same place as an object */
  do {
    Pick_A_Place(&P->Loc.x, &P->Loc.y);
    if (M_Used_list[World.Room_array[P->Loc.x][P->Loc.y]])
      Pick_A_Place(&P->Loc.x, &P->Loc.y);
  } while (!((Avoid < 0) || (World.Room_array[P->Loc.x][P->Loc.y] != Avoid)));
  if (P->Index == m_mimic)
    P->Loc = World.Objs->Loc;
  M_Used_list[World.Room_array[P->Loc.x][P->Loc.y]] = true;

  /* Get monsters hit points */
  for (I = 1; I <= Monster[P->Index].Hit_Dice; ++I) {
    P->HP += Die(8);

    /* Don''t allow more than 1 leprechaun or nymph */
    /* or mimic or githyanki per level */
    if (P->Index == m_lep ||
	P->Index == m_nymph ||
	P->Index == m_mimic ||
	P->Index == m_gith)
      Monster[P->Index].Min_Level = World.Level + 1;

    /* See if the monster is asleep. */
    /* Rings of Stealth/Aggravate handled here. */
    Roll = 100;
    if (Has_on_ring(r_stealth))
      Roll = Roll / 3;
    if (Has_on_ring(r_aggra))
      Roll = Roll * 3;
    P->Awake = (((Die(Roll) >= Monster[P->Index].Sleep) || All_awake) &&
		(Monster[P->Index].Sleep != 100));
  }
} /* Gen_monster */

void Place_Monster(Mon_Ptr P) {	/* was Mon_Ptr *P */
  /*  Mon_Ptr P = *Ptr; */

  P->Next = World.Monsters;
  World.Monsters = P;
  if ((P->Index == m_mimic) && (Player.SeeMon_count == 0))
    World.Mon[P->Loc.x][P->Loc.y] =
      World.Obj[World.Objs->Loc.x][World.Objs->Loc.y];
  else
    World.Mon[P->Loc.x][P->Loc.y] = Monster[P->Index].Name;
  if (Player.SeeMon_count > 0)
    World.Seeable[P->Loc.x][P->Loc.y] = true;
} /* Place_Monster */

void Gen_traps() {
  int I;
  Trap_Ptr T;

  for (I = 1; I <= World.Level / 5; ++I) {
    T = (Trap_Ptr)malloc(sizeof(Trap_Typ));
    T->Next = World.Traps;
    World.Traps = T;
    Pick_A_Place(&T->Loc.x, &T->Loc.y);
    T->Chance = 60 + Die(20);
    switch (Die(15)) {
    case 1: T->Kind = t_dart; break;
    case 2:
    case 3: T->Kind = t_door; break;
    case 4:
    case 5:
    case 6: T->Kind = t_teleport; break;
    case 7:
    case 8:
    case 9:
    case 10: T->Kind = t_bear; break;
    default: T->Kind = t_arrow; break;
    }
    if ((World.Level == Amulet_level) && (T->Kind == t_door))
      T->Kind = t_dart;
  }
} /* Gen_traps */

void Stock_World() {
  int I,J,X,Y;
  Mon_Ptr P_Mon;
  Obj_Ptr P_Obj;

  /* Turn off some lights, re-initalize used_list */
  for (I = 0; I < Max_Room; ++I) {
    if (World.Level > Die(20))
      World.Rooms[I].Light = false;
    O_Used_list[I] = false;
    M_Used_list[I] = false;
  }

  /* Put in the stairs down... */
  Pick_A_Place(&X, &Y);
  World.S_World[X][Y] = '%';

  /* Place the character */
  Pick_A_Place(&Player.Loc.x, &Player.Loc.y);
  World.Mon[Player.Loc.x][Player.Loc.y] = '@';

  /* Check for amulet, Put Juiblex on it */
  if (World.Level == Amulet_level) {
    P_Obj = (Obj_Ptr)malloc(sizeof(Obj_Typ));
    P_Obj->Obj_Typ = Amulet_T;
    Pick_A_Place(&P_Obj->Loc.x, &P_Obj->Loc.y);
    P_Obj->Cursed = false;
    P_Obj->Index = 0;
    P_Obj->Quan = 1;
    Place_Obj(P_Obj);

    P_Mon = (Mon_Ptr)malloc(sizeof(Monster_Typ));
    P_Mon->Next = NULL;
    P_Mon->Index = m_juiblex;
    P_Mon->HP = 88;
    P_Mon->Paralyzed_count = 0;
    P_Mon->Confused_count = 0;
    P_Mon->Speed = 2;
    P_Mon->Speed_count = 0;
    P_Mon->Who_first = 0;
    P_Mon->Loc.y = P_Obj->Loc.y;
    P_Mon->Loc.x = P_Obj->Loc.x;
    P_Mon->Awake = false;

    Place_Monster(P_Mon);
  }

  /* Some Treasures... */
  I = Die(3) + Die(3);		/* 2..6 */
  for (J = 1; J <= I; ++J) {
    Gen_Obj(World.Level, &P_Obj);
    Place_Obj(P_Obj);
  }

  /* At this point, World.Obj_List != NIL and the first item is Not the  */
  /* Amulet, so If we place a mimic, it won't be on the amulet. */

  /* Some Monsters!!! */
  World.Max_mons = 2 + Die(3);	/* #63 was die(2) */
  World.Num_mons = World.Max_mons;
  J = 1;
  I = 0;
  while (J <= World.Num_mons) {
    Gen_monster(World.Level, -1, &P_Mon, false);
    Place_Monster(P_Mon);
    if ((P_Mon->Index != m_kill) && (I <= 5))
      J++;
    else
      I++;
  }

  /* And now traps too! */
  Gen_traps();
} /* Stock_World */

void Gen_Level() {
  int I,J;

  Lose_Old_World();
  World.Level++;
  for (J = Y_Orig_1; J < S_Max_Y_1; ++J) { /* #71 <= */
    for (I = X_Orig_1; I < S_Max_X_1; ++I) { /* #71 <= */
      World.S_World[I][J] = ' ';
      World.Room_array[I][J] = -1;
      World.Mon[I][J] = EMPTY;
      World.Obj[I][J] = EMPTY;
      World.Seen[I][J] = false;
      World.Seeable[I][J] = false;
    }
  }
  for (I = 0; I < Max_Room; ++I) {
    World.Rooms[I].Existent = true;
    World.Rooms[I].Light = true;
    World.Rooms[I].Seen = false;
    for (J = 0; J < Max_Doors; ++J) {
      World.Rooms[I].Doors[J].Secret = 0;
      World.Rooms[I].Doors[J].Abs_loc.x = 0;
      World.Rooms[I].Doors[J].Abs_loc.y = 0;
    }
  }
  FUL();
  J = 0;
  for (I = 0; I < Max_Room; ++I) {
    if ((Die(Chance_Of_No_Room) == 1) && (J < 4)) {
      World.Rooms[I].Existent = false;
      J++;
    }
  }
  Siz();
  Con_Table();
  Stock_World();
} /* Gen_Level */

void Figure_Ac() {
  Hand_Type Hand;

  /* With Player */

  if (Player.Cur_Arm)
    Player.AC = Armor[Player.Cur_Arm->Index].Ac - Player.Cur_Arm->Plus_Hit;
  else
    Player.AC = 10;
  for (Hand = Left_H; Hand <= Right_H; Hand++) {
    if (Player.Cur_Ring[Hand] &&
	Player.Cur_Ring[Hand]->Index == r_protect)
      Player.AC -= Player.Cur_Ring[Hand]->Plus_Hit;
  }
  Change_stats |= S_Bottom;
}

void Gen_Character() {
  Obj_Ptr Worker;

  /* With Player */

  Worker = (Obj_Ptr)malloc(sizeof(Obj_Typ));

  Worker->Obj_Typ = Food_T;
  Worker->Index = 0;
  Worker->Quan = 1;
  Player.Obj_List = Worker;

  Worker->Next = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  Worker = Worker->Next;

  Player.Cur_Arm = Worker;
  Worker->Obj_Typ = Armor_T;
  Worker->Index = a_ring;	/* Ring mail */
  Worker->Plus_Hit = 1;
  Worker->Know_magic = true;
  Worker->Quan = 1;
  Worker->Cursed = false;
  Figure_Ac();

  Worker->Next = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  Worker = Worker->Next;

  Player.Cur_Wep = Worker;
  Worker->Obj_Typ = Weapon_T;
  Worker->Index = wp_mace;	/* +1 Mace */
  Worker->Plus_Hit = 1;
  Worker->Plus_Dam = 1;
  Worker->Know_magic = true;
  Worker->Cursed = false;
  Worker->Quan = 1;

  Worker->Next = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  Worker = Worker->Next;
  Worker->Obj_Typ = Weapon_T;
  Worker->Index = wp_bow;	/* +1 Short bow */
  Worker->Plus_Hit = 1;
  Worker->Plus_Dam = 1;
  Worker->Know_magic = true;
  Worker->Cursed = false;
  Worker->Quan = 1;

  Worker->Next = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  Worker = Worker->Next;
  Worker->Obj_Typ = Weapon_T;
  Worker->Index = wp_arrows;	/* Arrows */
  Worker->Plus_Hit = 0;
  Worker->Plus_Dam = 0;
  Worker->Know_magic = true;
  Worker->Quan = 20 + Die(20);
  Worker->Cursed = false;

  Worker->Next = NULL;

  Player.Cur_Ring[Left_H] = NULL;
  Player.Cur_Ring[Right_H] = NULL;
  Player.Max_ST = 13 + Die(4);
  Player.ST = Player.Max_ST;
  Player.Max_DX = 13 + Die(4);
  Player.DX = Player.Max_DX;
  Player.Max_IQ = 13 + Die(4);
  Player.IQ = Player.Max_IQ;
  Player.HP = 12;
  Player.Max_HP = 12;
  Player.Level = 1;
  Player.XP = 0;
  Player.Speed = 2;
  Player.Speed_count = 0;
  Player.Gold = 0;
  Player.Died_count = 0;	/* #49 all from here To end */
  Player.SeeMon_count = 0;
  Player.Faint_count = 0;
  Player.Confused_count = 0;
  Player.Blind_count = 0;
  Player.Paralyzed_count = 0;
  Player.Sleep_count = 0;
  Player.Trapped_count = 0;
  Player.Fixed_count = 0;
  Player.Invis_count = 0;
  Player.Last_meal = 0;
  Player.Heal_count = 0;
  Player.Eaten_count = 0;
  Player.Stuck = false;
  Player.Will_confuse = false;
  Player.Has_amulet = false;

} /* Gen_Character */

void Swap(int Ran_array[], int A, int B) {
  int T;

  T = Ran_array[B];
  Ran_array[B] = Ran_array[A];
  Ran_array[A] = T;
}

void Init_Obj_Descriptions() {
  int *Ran_array;
  int I,A,B,J,Num,Start,Ran_max,Ran_word,
    Max_Word,Max_Metal,Max_Wood,Max_Stone,Max_Color;
  Scrolls *sp;
  char *wordp;

  for (I = 0, Max_Chance = 0; I < Max_Treasure; ++I)
    Max_Chance += Treasure[I].Chance; /* count chance of Treasure */

  /* #71 allow for more Colors than potions, more Stones than rings, etc. */
  for (Max_Word = 0;  Word[Max_Word];   ++Max_Word) ;  /* count Words */
  for (Max_Color = 0; Color[Max_Color]; ++Max_Color) ; /* count Colors */
  for (Max_Stone = 0; Stone[Max_Stone]; ++Max_Stone) ; /* count Stones */
  for (Max_Wood = 0;  Wood[Max_Wood];   ++Max_Wood) ;  /* count Woods */
  for (Max_Metal = 0; Metal[Max_Metal]; ++Max_Metal) ; /* count Metals */

  Ran_max = max(Max_Word,
		max(Max_Color,
		    max(Max_Stone,
			max(Max_Wood, Max_Metal))));

  Ran_array = (int *)malloc(Ran_max * sizeof(int));

  /* #71 do potions */
  for (I = 0; I < Max_Color; ++I)
    Ran_array[I] = I;
  for (I = 0; I < Max_Color; ++I) {
    A = Die(Max_Color) - 1;
    B = Die(Max_Color) - 1;
    Swap(Ran_array, A, B);
  }
  for (I = 0; I < Max_Potion; ++I) {
    strcpy(Potion[I].Desc, Color[Ran_array[I]]);
  }

  /* #71 do rings */
  for (I = 0; I < Max_Stone; ++I)
    Ran_array[I] = I;
  for (I = 0; I < Max_Stone; ++I) {
    A = Die(Max_Stone) - 1;
    B = Die(Max_Stone) - 1;
    Swap(Ran_array, A, B);
  }
  for (I = 0; I < Max_Ring; ++I) {
    strcpy(Ring[I].Desc, Stone[Ran_array[I]]);
  }

  /* #71 do wands and staves */
  for (I = 0; I < Max_Metal; ++I)
    Ran_array[I] = I;
  for (I = 0; I < Max_Metal; ++I) {
    A = Die(Max_Metal) - 1;
    B = Die(Max_Metal) - 1;
    Swap(Ran_array, A, B);
  }
  for (I = 0; I < Max_Wand; ++I) {
    Wand[I].Is_wand = (Die(2) == 1);
    if (Wand[I].Is_wand)	/* wands are metal */
      strcpy(Wand[I].Desc, Metal[Ran_array[I]]);
  }
  for (I = 0; I < Max_Wood; ++I)
    Ran_array[I] = I;
  for (I = 0; I < Max_Wood; ++I) {
    A = Die(Max_Wood) - 1;
    B = Die(Max_Wood) - 1;
    Swap(Ran_array, A, B);
  }
  for (I = 0; I < Max_Wand; ++I) {
    if (!Wand[I].Is_wand)	/* staves are wood */
      strcpy(Wand[I].Desc, Wood[Ran_array[I]]);
  }

  /* #71 do scrolls */
  for (I = 0; I < Max_Word; ++I)
    Ran_array[I] = I;
  for (I = 0; I < Max_Word; ++I) {
    A = Die(Max_Word) - 1;
    B = Die(Max_Word) - 1;
    Swap(Ran_array, A, B);
  }
  Ran_word = 0;
  for (I = 0; I < Max_Scroll; ++I) {

    sp = &Scroll[I];

    Start = 0;
    J = 1;
    Num = Die(4);
    while ((J <= Num) && (Start < Name_Len)) { /* #71 fencepost? */
      wordp = Word[Ran_array[Ran_word]];
      A = 0;
      while ((A < 10) && (Start < Name_Len) &&
	     (sp->Desc[Start] = wordp[A++]))
	Start++;		/* #71 smoke and mirrors */

      J++;
      Ran_word++;
      if (Start < Name_Len) {
	sp->Desc[Start] = SPACE;
	Start++;
      }
#if 0
      if (Start == Name_Len - 1) { /* #66 */
	sp->Desc[Start] = SPACE;
	Start++;
      }
#endif
    }
    sp->Desc[0] = toupper(sp->Desc[0]); /* #66 capitalize it */
    sp->Desc[Name_Len] = '\0';	/* #71 just in case */
    sp->Desc[Start--] = '\0';	/* #71 */
    if (sp->Desc[Start] == '-') /* #71 */
      sp->Desc[Start--] = '\0';
    if (sp->Desc[Start] == SPACE) /* #70 */
      sp->Desc[Start] = '\0';
  }

  free(Ran_array);

} /* Init_Obj_Descriptions */

void Second_Init() {
  World.Level = 0;		/* Initialize the first level (0th) */
  World.Objs = NULL;
  World.Monsters = NULL;
  World.Traps = NULL;
  Init_Obj_Descriptions();
  Amulet_level = 26 + Die(2);	/* #63 */
  Blank_message = Die(3);
  Gen_Character();
  Gen_Level();
  Change_stats = S_Top|S_Bottom;
  Dead = false;
} /* Second_Init */

void First_Init() {
  pid_t pp;
  int ch;
  unsigned int seed;
  struct passwd *pwp;

  Inidat = time(NULL);		/* #71 */
  times(&Inirun);		/* #71 ignore error? */

  pp = getpid();

  /* #71 this initialization suggested in perlfunc man page  */
  seed = (unsigned int)(Inidat & UINT_MAX);
  seed ^= (unsigned int)((pp & UINT_MAX) + ((pp << 15) & UINT_MAX));
  srandom(seed);

  /*  Virgin = false; */
  Dead = false;
  Quit_game = false;

  Echo_point = 4;		/* #50 */
  /* #71 Resp_chars := ['T','F','t','f',Chr(33B),Chr(15B),Chr(12B)]; */
  memset(Okmons, false, sizeof(Okmons));
  for (ch = 'a'; ch <= 'z'; ++ch) {
    Okmons[ch] = true;
    Okmons[toupper(ch)] = true;
  }
#if 0
  For I := X_orig to S_max_x
    For J := Y_orig to S_max_y
      false_array[I,J] := false;
  For I := 1 to 80
    Nulls[I] := Chr(0);
#endif
  F_temp = false;
  Fast = false;
  Want_scores = true;		/* #71 */
  Player.Loc.x = 1;
  Player.Loc.y = 1;

  strcpy(Fruit_name, "slime-mold"); /* #71 was in extern.mac */

  pwp = getpwuid(getuid());
  if (pwp == NULL) {
    fprintf(stderr, "?ROGUE: Unable to get login information\n");
    exit(1);
  }
  strcpy(Player.Name, pwp->pw_name);

  if (initscr() == NULL) {
    fprintf(stderr, "?ROGUE: Unable to initialize screen.\n");
    exit(1);
  }
  if (LINES < Status_Y + 2 || COLS < S_Max_X_1) {
    endwin();
    fprintf(stderr,
	    "?ROGUE: Screen is too small (%dx%d), must be at least %dx%d.\n",
	    LINES, COLS, Status_Y + 2, S_Max_X_1);
    exit(1);
  }

  /*  raw(); */
  cbreak();
  noecho();
  typeahead(-1);

  logfp = fopen(".rogue.log", "w"); /* #71 */
  if (logfp)
    setbuf(logfp, NULL);	/* unbuffered */
} /* First_Init */

void Insert(Obj_Ptr *List, Obj_Ptr P) {
  Obj_Ptr Q,Ptemp;
  bool U,More,Finished;

  Ptemp = NULL;
  Q = *List;
  More = true;
  Finished = false;
  Last_Item = 'a';
  while (Q && More) {
    if (P->Obj_Typ >= Q->Obj_Typ) {
      if (P->Obj_Typ == Q->Obj_Typ) {
	U = (P->Index == Q->Index);
	U = U && ((P->Obj_Typ == Food_T ||
		   P->Obj_Typ == Scroll_T ||
		   P->Obj_Typ == Potion_T) ||
		  ((P->Obj_Typ == Weapon_T) &&
		   Weapon_is_ammo(P->Index) &&
		   ((P->Plus_Hit == Q->Plus_Hit) &&
		    (P->Plus_Dam == Q->Plus_Dam))));
	if (U) {
	  Q->Quan += max(P->Quan, 1);
	  Finished = true;
	  More = false;
	  free(P);
	} else {
	  Ptemp = Q;
	  Q = Q->Next;
	  Last_Item++;
	}
      } else {			/* P->Obj_Typ > Q->Obj_Typ */
	Ptemp = Q;
	Q = Q->Next;
	Last_Item++;
      }
    } else
      More = false;
  }
  if (!Finished) {
    if (Ptemp) {
      Ptemp->Next = P;
      P->Next = Q;
    } else {
      P->Next = *List;
      *List = P;
    }
  }
} /* Insert */

void Remove_Obj(Obj_Ptr *List, Obj_Ptr Befor) {
  if (Befor)
    Befor->Next = Befor->Next->Next;
  else
    *List = (*List)->Next;
} /* Remove_Obj */

bool Has_One(Obj_Ptr P, bool Exact) {
  /* Some day pascal will have multiple EXIT loops... */
  Obj_Ptr Q;

  Q = Player.Obj_List;
  while (Q) {
    if (Q->Obj_Typ == P->Obj_Typ) {
      if (Q->Index == P->Index) {
	if (Exact) {
	  if (P->Obj_Typ == Food_T ||
	      P->Obj_Typ == Scroll_T ||
	      P->Obj_Typ == Potion_T) {
	    return(true);
	  } else if ((P->Obj_Typ == Weapon_T) &&
		     Weapon_is_ammo(P->Index)) {
	    if (Q->Plus_Dam == P->Plus_Dam) {
	      if (Q->Plus_Hit == P->Plus_Hit) {
		return(true);
	      }
	    }
	  }
	} else {
	  return(true);
	}
      }
    }
    Q = Q->Next;
  } /* WHILE */
  return false;
} /* Has_One */

/* Item_Count was a function internal to Can_Carry  */

int Item_Count() {
  int c;
  Obj_Ptr p;

  c = 0;
  p = Player.Obj_List;
  while (p) {
    c++;
    p = p->Next;
  } /* WHILE */
  return c;
} /* Item_Count */

bool Can_Carry(Obj_Ptr P) {

  if (P->Obj_Typ == Gold_T) {
    return(true);
  } /* IF */

  if (Has_One(P, true)) {
    return(true);
  } /* IF */

  if (Item_Count() < Max_Item) {
    return(true);
  } /* IF */

  return(false);
} /* Can_Carry */

/* Decoding was a procedure internal to Write_obj_name() */
void Decoding(Obj_Ptr P_Obj, bool *Is_Id, bool *Know_Da_Magick) {
  Hand_Type Hand;
  bool Good, rGood;
  int Has,Magick;

  if (P_Obj->Obj_Typ == Food_T || /* #71 short circuit */
      P_Obj->Obj_Typ == Gold_T ||
      P_Obj->Obj_Typ == Amulet_T) {
    *Is_Id = true;
    *Know_Da_Magick = true;
    return;
  }

  Has = 0;
  Good = false;
  for (Hand = Left_H; Hand <= Right_H; ++Hand)
    if (Player.Cur_Ring[Hand] && Player.Cur_Ring[Hand]->Index == r_decode) {
      Magick = Player.Cur_Ring[Hand]->Plus_Hit;
      rGood = true;
      if (Magick < 0) {		/* #71 simplify decode implementation */
	Magick = -Magick;
	rGood = false;
      }
      if ((Magick & (1 << P_Obj->Obj_Typ)) != 0) {
	if (Has) {
	  if (Good != rGood)
	    Has = false;
	} else {
	  Has = true;
	  Good = rGood;
	}
      }
    }
  if (Has) {
    *Is_Id = Good;
    *Know_Da_Magick = Good;
  } else {
    switch (P_Obj->Obj_Typ) {
    case Potion_T:
      *Is_Id = Potion[P_Obj->Index].Id;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    case Scroll_T:
      *Is_Id = Scroll[P_Obj->Index].Id;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    case Weapon_T:
      *Is_Id = true;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    case Armor_T:
      *Is_Id = true;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    case Wand_T:
      *Is_Id = Wand[P_Obj->Index].Id;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    case Ring_T:
      *Is_Id = Ring[P_Obj->Index].Id;
      *Know_Da_Magick = P_Obj->Know_magic;
      break;

    default:
      break;
    }

  }
} /* Decoding */

void Write_With_A_An_Or_Number(char *Fp, Obj_Ptr What, Name_string Name,
			       bool Another) {
  char ch;
  Long_string str;

  if (What->Obj_Typ != Armor_T) {
    if (What->Quan <= 1) {
      if (Another)
	strcat(Fp, "another ");
      else {
	ch = tolower(Name[0]);
	if (ch == 'a' || ch == 'e' || ch == 'h' ||
	    ch == 'i' || ch == 'o' || ch == 'u')
	  strcat(Fp, "an ");
	else
	  strcat(Fp, "a ");
      }
    } else {
      sprintf(str, "%d", What->Quan);
      strcat(Fp, str);
      if (Another)
	strcat(Fp, " more ");
      else
	strcat(Fp, " ");
    }

    strcat(Fp, Name);	   /* #71 no more length */
  }
} /* Write_With_A_An_Or_Number */

void Write_obj_name(char *Fp, Obj_Ptr What, bool Another) {

  int Len;
  bool Is_Id, Know_the_magic,	/* #55 */
  More;
  Long_string str;
  Wands *wp;
  Potions *pp;
  Scrolls *sp;
  Rings *rp;
  Weapons *wepp;

  /* With What^ */

  Decoding(What, &Is_Id, &Know_the_magic);
  if (Know_the_magic) {		/* #71 this could be condensed to one test */
    if ((What->Obj_Typ == Ring_T &&
	 (What->Index == r_protect ||
	  What->Index == r_dex ||
	  What->Index == r_str ||
	  What->Index == r_int ||
	  What->Index == r_incr_dam)) ||
	What->Obj_Typ == Armor_T ||
	What->Obj_Typ == Weapon_T) {
      if (Another)
	if (What->Obj_Typ == Weapon_T)
	  if (Weapon_is_ammo(What->Index))
	    strcat(Fp, "another ");
      if (What->Plus_Hit < 0)
	strcat(Fp, "-");
      else
	strcat(Fp, "+");
      sprintf(str, "%d", abs(What->Plus_Hit));
      strcat(Fp, str);
      if (What->Obj_Typ == Weapon_T) {
	if (What->Plus_Dam < 0)
	  strcat(Fp, ",-");
	else
	  strcat(Fp, ",+");
	sprintf(str, "%d", abs(What->Plus_Dam));
	strcat(Fp, str);
      }
      strcat(Fp, " ");
    }
  }

  switch (What->Obj_Typ) {

  case Wand_T:
    /* With Wand[Index] */
    wp = &Wand[What->Index];
    if (Is_Id) {
      if (What->Quan <= 1) {
	if (Another)
	  strcat(Fp, "another ");
	else
	  strcat(Fp, "a ");
	if (wp->Is_wand)
	  strcat(Fp, "wand of ");
	else
	  strcat(Fp, "staff of ");
      } else {
	sprintf(str, "%d", What->Quan);
	strcat(Fp, str);
	if (Another)
	  strcat(Fp, " more ");
	if (wp->Is_wand)
	  strcat(Fp, "wands of ");
	else
	  strcat(Fp, "staves of ");
      }
      strcat(Fp, wp->Name);	/* #71 no more length! */
    } else {			/* if Is_Id */
      Write_With_A_An_Or_Number(Fp, What, wp->Desc, Another); /* #71 */
      if (wp->Is_wand) {
	if (What->Quan <= 1)
	  strcat(Fp, " wand");
	else
	  strcat(Fp, " wands");
      } else if (What->Quan <= 1)
	strcat(Fp, " staff");
      else
	strcat(Fp, " staves");
    }
    break;

  case Potion_T:
    /* With Potion[Index] */
    pp = &Potion[What->Index];

    if (Player.Blind_count) {
      if (What->Quan > 1) {
	sprintf(str, "%d", What->Quan);
	strcat(Fp,str);
      } else
	strcat(Fp, "a");
    } else if (Is_Id)
      Write_With_A_An_Or_Number(Fp, What, pp->Name, Another); /* #71 */
    else
      Write_With_A_An_Or_Number(Fp, What, pp->Desc, Another); /* #71 */
    if (What->Quan > 1)
      strcat(Fp, " potions");
    else
      strcat(Fp, " potion");
    break;

  case Scroll_T:
    /* With Scroll[Index] */
    sp = &Scroll[What->Index];
    if (Is_Id) {
      if (Player.Blind_count) {
	if (What->Quan > 1) {
	  sprintf(str, "%d scrolls", What->Quan);
	  strcat(Fp, str);
	} else
	  strcat(Fp, "a scroll");
      } else {
	if (What->Quan > 1) {
	  if (Another)
	    sprintf(str, "%d more scrolls of ", What->Quan);
	  else
	    sprintf(str, "%d scrolls of ", What->Quan);
	  strcat(Fp, str);
	} else if (Another)
	  strcat(Fp, "another scroll of ");
	else
	  strcat(Fp, "a scroll of ");
	strcat(Fp, sp->Name);	/* #71 */
      }
    } else {
      if (What->Quan > 1) {
	sprintf(str, "%d", What->Quan);
	strcat(Fp, str);
	if (Another && Player.Blind_count == 0)
	  strcat(Fp, " more scrolls");
	else
	  strcat(Fp, " scrolls");
      } else {
	if (Another && Player.Blind_count == 0)
	  strcat(Fp, "another scroll");
	else
	  strcat(Fp, "a scroll");
      }
      if (Player.Blind_count == 0) {
	if (sp->Called)
	  strcat(Fp, " called ");
	else
	  strcat(Fp, " titled \"");
	strcat(Fp, sp->Desc);	/* #71 */
	if (! sp->Called)
	  strcat(Fp, "\"");
      }
    }
    break;

  case Ring_T:
    /* With Ring[Index] */
    rp = &Ring[What->Index];
    if (Is_Id) {
      if (What->Quan == 1) {
	if ((! Know_the_magic) && Another) /* #71 modified logic: buggy? */
	  strcat(Fp, "another ");
	else
	  strcat(Fp, "a ");
	strcat(Fp, "ring of ");
	strcat(Fp, rp->Name);	/* #71 no length */
      } else
	strcat(Fp, "Error - Ring quantity not 1");
    } else {
      Write_With_A_An_Or_Number(Fp, What, rp->Desc, Another); /* #71 */
      strcat(Fp, " ring");
    }
    break;

  case Armor_T:
    if (Another)
      strcat(Fp, "more ");
    strcat(Fp, Armor[What->Index].Name); /* #71 no length */
    break;

  case Weapon_T:
    /* With Weapon[Index] */
    wepp = &Weapon[What->Index];
    if (Know_the_magic)
      strcat(Fp, wepp->Name);	/* #71 no length */
    else
      Write_With_A_An_Or_Number(Fp, What, wepp->Name, Another);	/* #71 */
    if (What->Quan > 1)
      strcat(Fp, "s");
    break;

  case Food_T:
    if (What->Index == 0) {
      if (What->Quan <= 1) {
	if (Another)
	  strcat(Fp, "more food");
	else
	  strcat(Fp, "some food");
      } else if (Another) {
	sprintf(str, "%d more rations of food", What->Quan);
	strcat(Fp, str);
      } else {
	sprintf(str, "%d rations of food", What->Quan);
	strcat(Fp, str);
      }
    } else {
      Len = Name_Len;
      More = true;
      while (More) {
	if (Len == 0)
	  More = false;
	else if (Fruit_name[Len] != ' ')
	  More = false;
	else
	  Len--;
	Write_With_A_An_Or_Number(Fp, What, Fruit_name, Another); /* #71 */
      }
    }
    break;

  case Amulet_T:
    strcat(Fp, "the AMULET of YENDOR!!!");
    break;

  default:
    strcat(Fp, "Error - Unknown type of object in Write_obj_name");
  }
  if (Know_the_magic && (What->Obj_Typ == Wand_T)) {
    sprintf(str, " [%d]", What->Plus_Hit);
    strcat(Fp, str);
  }
  if ((What->Obj_Typ == Weapon_T) &&
      Weapon_is_ammo(What->Index) &&
      Know_the_magic && (What->Quan > 1)) {
    sprintf(str, " [%d]", What->Quan);
    strcat(Fp, str);
  }
} /* Write_obj_name */

void Get_Treasure(int X, int Y) {
  Obj_Ptr P,Q;
  bool More, Found, Silly;
  int I;
  Long_string str;

  P = World.Objs;
  Q = NULL;
  Found = false;
  More = true;
  while (More)
    if (P == NULL)
      More = false;
    else if ((P->Loc.x == X) && (P->Loc.y == Y)) {
      Found = true;
      More = false;
    } else {
      Q = P;
      P = P->Next;
    }
  if (! Found) {
    World.Obj[X][Y] = EMPTY;
    if (Switches.Terse_swi)
      Echo("It was an illusion");
    else
      Echo("The illusion wavers as you try to pick it up, and fades");
  } else {
    if (Can_Carry(P)) {
      switch (P->Obj_Typ) {

      case Gold_T:
	Echo_Init();
	if (! Switches.Terse_swi)
	  strcat(F, "You found ");
	sprintf(str, "%d pieces of gold", P->Quan);
	strcat(F, str);

	Player.Gold += P->Quan;
	Change_stats |= S_Bottom;
	Remove_Obj(&World.Objs, Q);
	free(P);
	Echo(Echo_Str);
	break;

      default:
	Echo_Init();
	if (! Switches.Terse_swi)
	  strcat(F, "You found ");
	Silly = Has_One(P, false);
	Write_obj_name(F, P, Silly);
	if (P->Obj_Typ == Amulet_T)
	  Player.Has_amulet = true;
	Remove_Obj(&World.Objs, Q);
	Insert(&Player.Obj_List, P);
	sprintf(str, " (%c)", Last_Item);
	strcat(F, str);
	F[0] = toupper(F[0]);	/* #55 */
	Echo(Echo_Str);
	if (P->Obj_Typ == Scroll_T) {
	  if ((Die(15) <= (Player.IQ - 15)) &&
	      (Player.Blind_count == 0) &&
	      (Scroll[P->Index].Can_ID) &&
	      (! Scroll[P->Index].Id)) {
	    Scroll[P->Index].Id = true;
	    Echo_Init();
	    strcat(F, "You know this to be ");
	    Write_obj_name(F, P, Silly);
	    Echo(Echo_Str);
	  }
	  Scroll[P->Index].Can_ID = false;
	}
      } /* Case */
      World.Obj[X][Y] = EMPTY;
      I = World.Room_array[X][Y];
      if (I >= 0)
	if (! World.Rooms[I].Light)
	  World.Seen[X][Y] = false;
    } else {
      if (Switches.Terse_swi)
	Echo("You\'re carrying too much already");
      else
	Echo("Your load is too heavy.  You\'ll have to drop something first");
    }
  }
} /* Get_Treasure */

char Inventory(Obj_Ptr List, Obj_Class_Type Which,
	       bool Ask_object) { /* #65 */

  char Ch,Item,Low,High;
  Obj_Ptr Worker;
  bool Have_One,More;		/* #46 */
/*  Fp : text; */
  int Line;
  char retval;

  retval = SPACE;		/* #65 */
  Item = 'a';
  Low = 'z';
  High = 'a';
  Line = Y_Orig_1;
  Have_One = false; /* #46 */
  More = true;
  Empty_Echo = true;
  Worker = List;
  if (Worker) {
    while (Worker && More) {
      /* With Worker^ */
      if (Which == All_T || Which == Worker->Obj_Typ) {
	if (Item < Low)
	  Low = Item;
	if (Item > High)
	  High = Item;
/*		S := Spaces;
		Strwrite(Fp,S); */
	Echo_Init();
	sprintf(F/*p*/, "%c) ", Item);
	Write_obj_name(F/*p*/, Worker, Not_Another);
	if (Worker == Player.Cur_Wep)
	  strcat(F/*p*/, " (in hand)");
	else if (Worker == Player.Cur_Arm)
	  strcat(F/*p*/, " (being worn)");
	else if (Worker == Player.Cur_Ring[Left_H])
	  strcat(F/*p*/, " (on left hand)");
	else if (Worker == Player.Cur_Ring[Right_H])
	  strcat(F/*p*/, " (on right hand)");
	Scr_Text(Line, Echo_Str);
	if (Switches.Slow_swi) {
	  if (Have_One)
	    More = Wait_For_Space(false);
	  if (More)
	    Redisplay();
	} else
	    Line++;
	Have_One = true;
      }
      Worker = Worker->Next;
      Item++;
    }
  }
  if (! Have_One) {
    Echo("Nothing appropriate");
    return(CHESC);
  } else {
    if (More) {
      if (Ask_object) {
	Scr_Text(Line, "--Type the letter of your choice or <Space>--");
	Redisplay();
	move(Line, 46);
	do {
	  Ch = tolower(Comand());
	} while (Ch != Space && Ch != CHESC && (Ch < Low || Ch > High));
	if (Ch == Space)
	  retval = '*';
	else
	  retval = Ch;
      } else {
	Redisplay();
	More = Wait_For_Space(false);
	retval = '*';
      }
    }
    Change_stats = S_Top|S_Bottom;
    Clear_Echo();
    Update_Screen();
    Empty_Echo = true;
  }
  return(retval);
} /* Inventory */

/* Discard : remove from Pack */
/* Only_One to remove only one of multivalued items (1 arrow) */
Obj_Ptr Take_from_pack(char *Ch, Obj_Ptr *List,
		       Obj_Class_Type Which,
		       bool Discard, bool Only_one) {

  Obj_Ptr Worker,Parent,Removed_obj;
  char Count;

  if (*Ch == '*' || *Ch == '?')	/* #54 */
    *Ch = Inventory(*List, Which, true); /* #65 Begin edit */
  if (*Ch == CHESC)
    return(NULL);
  else if (*Ch == '*')
    return(NULL);
				/* #65 End edit */

  *Ch = tolower(*Ch);
  Worker = *List;
  Parent = NULL;
  Count = 'a';
  while (Worker) {
    if (Count == *Ch) {
      if (Worker->Obj_Typ == Which || Which == All_T) {
	if (Discard) {
	  if ((Worker->Quan > 1) && Only_one) {
	    Worker->Quan--;
	    Removed_obj = (Obj_Ptr)malloc(sizeof(Obj_Typ));
	    Removed_obj->Obj_Typ = Worker->Obj_Typ;
	    Removed_obj->Loc = Worker->Loc;
	    Removed_obj->Quan = 1;
	    Removed_obj->Index = Worker->Index;
	    Removed_obj->Plus_Hit = Worker->Plus_Hit;
	    Removed_obj->Plus_Dam = Worker->Plus_Dam;
	    Removed_obj->Know_magic = Worker->Know_magic;
	    Removed_obj->Cursed = Worker->Cursed;
	    Removed_obj->Next = NULL;
	    Worker = Removed_obj;
	  } else if (Parent == NULL)
	    *List = (*List)->Next;
	  else
	    Parent->Next = Worker->Next;
	}
	return(Worker);
      }
      return(NULL);
    }
    Parent = Worker;
    Worker = Worker->Next;
    Count++;
  }
  return(NULL);
} /* Take_from_pack */

void Put_on_floor(Obj_Ptr This_one, int Xloc, int Yloc) {

  Obj_Ptr Temp;

  Temp = (Obj_Ptr)malloc(sizeof(Obj_Typ));
  Temp->Obj_Typ = This_one->Obj_Typ;
  Temp->Loc = This_one->Loc;
  Temp->Quan = This_one->Quan;
  Temp->Index = This_one->Index;
  Temp->Plus_Hit = This_one->Plus_Hit;
  Temp->Plus_Dam = This_one->Plus_Dam;
  Temp->Know_magic = This_one->Know_magic;
  Temp->Cursed = This_one->Cursed;
  Temp->Next = NULL;
  Temp->Loc.x = Xloc;
  Temp->Loc.y = Yloc;
  Place_Obj(Temp);
  /* With Player */
  if (This_one == Player.Cur_Arm) {
    Player.Cur_Arm = NULL;
    Figure_Ac();
  } else if (This_one == Player.Cur_Wep)
    Player.Cur_Wep = NULL;
  else if (This_one == Player.Cur_Ring[Left_H])
    Player.Cur_Ring[Left_H] = NULL;
  else if (This_one == Player.Cur_Ring[Right_H])
    Player.Cur_Ring[Right_H] = NULL;
} /* Put_on_floor */

void Name_obj(Obj_Ptr This_one) {

  Name_string New_Desc;
  int New_Len;

  Echo("Call it:");
  Move_To_Echo();
  if (Get_Line(New_Desc, &New_Len)) { /* #54 */
    /* With This_one^ */
    if (New_Len > 0)
      switch (This_one->Obj_Typ) {
      case Ring_T:
	strcpy(Ring[This_one->Index].Desc, New_Desc);
	Ring[This_one->Index].Called = true;
	break;
      case Wand_T:
	strcpy(Wand[This_one->Index].Desc, New_Desc);
	Wand[This_one->Index].Called = true;
	break;
      case Scroll_T:
	strcpy(Scroll[This_one->Index].Desc, New_Desc);
	Scroll[This_one->Index].Called = true;
	break;
      case Potion_T:
	strcpy(Potion[This_one->Index].Desc, New_Desc);
	Potion[This_one->Index].Called = true;
	break;
      default:
	if (logfp)
	  fprintf(logfp, "Error - Bad object type in name_obj\n");
      }
    else	 /* #54 Ok, they typed <CR>, give them the old name */
      switch (This_one->Obj_Typ) {
      case Ring_T: Ring[This_one->Index].Called = true; break;
      case Wand_T: Wand[This_one->Index].Called = true; break;
      case Scroll_T: Scroll[This_one->Index].Called = true; break;
      case Potion_T: Potion[This_one->Index].Called = true; break;
      default:
	if (logfp)
	  fprintf(logfp, "Error - Bad object type in name_obj\n");
      }
    Clear_Echo();
    Redisplay();
    Empty_Echo = true;
  }
} /* Name_obj */

/* #71 requires that Dir is a digit - a canonical direction */
/* Get_direction() returns and Delta_Dir contains canonical directions  */
void Translate_Direction(char Dir, int *Dx, int *Dy) { /* #70 new */
  int I, J;

  I = Dir - '0';		/* #71 this is the cool math */
  if (I > 6) {
    J = I - 8;
    I = -1;
  } else if (I < 4) {
    J = I - 2;
    I = 1;
  } else {
    J = I - 5;
    I = 0;
  }
  *Dx = J;
  *Dy = I;

} /* Translate_Direction */

bool isOkDir(char ch) {

  if (ch == '5')		/* #71 short circuit */
    return false;
  if (isdigit(ch))
    return true;
  if (ch == CHESC)
    return true;
  ch = tolower(ch);
  if (ch == 'h' ||
      ch == 'j' ||
      ch == 'k' ||
      ch == 'l' ||
      ch == 'y' ||
      ch == 'u' ||
      ch == 'b' ||
      ch == 'n')
    return true;
  return false;
}

/* #71 rewritten slightly to return canonical digit direction */
/* #71 since this routine is only used by Throw/Hurl/Zap */
char Get_direction() {
  char Ch;

  Empty_Echo = true;
  do {
    Echo("Direction?");
    Move_To_Echo();
    Ch = Comand();
    if (!isOkDir(Ch)) {
	Empty_Echo = true;
	Echo("Please specify a one-character direction");
    }
  } while (!isOkDir(Ch));

  if (isalpha(Ch)) {
    Ch = tolower(Ch);
    switch (Ch) {
    case 'k': Ch = '8'; break;	/* N */
    case 'j': Ch = '2'; break;	/* S */
    case 'l': Ch = '6'; break;	/* E */
    case 'h': Ch = '4'; break;	/* W */
    case 'u': Ch = '9'; break;	/* NE */
    case 'y': Ch = '7'; break;	/* NW */
    case 'n': Ch = '3'; break;	/* SE */
    case 'b': Ch = '1'; break;	/* SW */
    }
  }

  return(Ch);
}

void Place_Next_To(Loc_Type Source, Loc_Type *Dest, bool Is_Obj) {
  int I, J;
  int X_Disp[3], Y_Disp[3];
  Loc_Type Tmp;
  bool Found;

  *Dest = Source;
  do {
    if ((Dest->x < X_Orig) || (Dest->x > S_Max_X))
      Dest->x = Die(S_Max_X);
    if ((Dest->y < Y_Orig) || (Dest->y > S_Max_Y))
      Dest->y = Die(S_Max_Y);
    Tmp = *Dest;
    X_Disp[0] = Die(3) - 2;
    do {
      X_Disp[1] = Die(3) - 2;
    } while (X_Disp[0] == X_Disp[1]);
    X_Disp[2] = -(X_Disp[0] + X_Disp[1]);
    Y_Disp[0] = Die(3) - 2;
    do {
      Y_Disp[1] = Die(3) - 2;
    } while (Y_Disp[0] == Y_Disp[1]);
    Y_Disp[2] = -(Y_Disp[0] + Y_Disp[1]);
    I = 0;
    Found = false;
    do {
      Dest->x = Tmp.x + X_Disp[I];
      J = 0;			/* #58 */
      if ((Dest->x >= X_Orig) && (Dest->x <= S_Max_X))
	do {
	  Dest->y = Tmp.y + Y_Disp[J];
	  if ((Dest->y >= Y_Orig) && (Dest->y <= S_Max_Y))
	    if ((Dest->x != Source.x) || (Dest->y != Source.y))
	      if (World.S_World[Dest->x][Dest->y] == '.' ||
		  World.S_World[Dest->x][Dest->y] == '^' ||
		  World.S_World[Dest->x][Dest->y] == '#' ||
		  World.S_World[Dest->x][Dest->y] == '+') {
		if (Is_Obj) {
		  if (World.Obj[Dest->x][Dest->y] == EMPTY)
		    Found = true;
		} else if (World.Mon[Dest->x][Dest->y] == EMPTY)
		  Found = true;
	      }
	  J++;
	} while (!((J == 3) || Found));
      I++;
    } while (!((I == 3) || Found));
  } while (!Found);
} /* Place_Next_To */

void No_more_blindness() {
  Player.Blind_count = 0;
  Echo("The cloak of darkness lifts");
}

void Take_It_Off(Obj_Ptr Which); /* forward decl */

void Give_cursed_message() {
  Empty_Echo = true;
  Echo("You can\'t.  It appears to be cursed");
}

void Give_stuck_message() {
  Empty_Echo = true;
  Echo_Init();
  strcat(F, "You have been ");
  switch (Die(3)) {
  case 1: strcat(F, "entrapped "); break;
  case 2: strcat(F, "ensnared "); break;
  case 3: strcat(F, "captured "); break;
  }
  switch (Die(3)) {
  case 1: strcat(F, "by the fiend"); break;
  case 2: strcat(F, "by the monster"); break;
  case 3: strcat(F, "by the beastie"); break;
  }
  if (!Switches.Terse_swi)
    strcat(F, " and can\'t move");
  Echo(Echo_Str);
}

/* Procedure Magic_Mapping; Forward; *//* #70 debug */

void Down_a_level () {
  Gen_Level();
  New_Place_Player();
  Player_Appears();
  Change_stats |= S_Bottom;
  /*  Magic_Mapping; *//* #70 debug */
  Update_Screen();
} /* Down_a_level */

Obj_Ptr Choose_Item(Action_Type Typ, Obj_Class_Type O_Typ,
		    bool Discard, bool Only_1) { /* #54 */

  bool More;
  char Ch;
  Obj_Ptr This_one;

  This_one = NULL;
  More = true;
  while (true) {
    if (Switches.Terse_swi)
      switch (Typ) {
      case Eat_A: Echo("Eat what?"); break;
      case Put_On_A: Echo("Put on what?"); break;
      case Zap_A: Echo("Zap what?"); break;
      case Read_A: Echo("Read what?"); break;
      case Quaff_A: Echo("Quaff what?"); break;
      case Wear_A: Echo("Wear what?"); break;
      case Wield_A: Echo("Wield what?"); break;
      case Call_A: Echo("Call what?"); break;
      case Drop_A: Echo("Drop what?"); break;
      case Identify_A: Echo("Identify what?"); break;
      case Throw_A: Echo("Throw what?"); break;
      default: Echo("Oh god!  Choose_Item called illegally");
      }
    else
      switch (Typ) {
      case Eat_A: Echo("What do you wish to eat (* for list)?"); break;
      case Put_On_A: Echo("Which ring do you wish to put on (* for list)?"); break;
      case Zap_A: Echo("What to you wish to zap with (* for list)?"); break;
      case Read_A: Echo("What to you wish to read (* for list)?"); break;
      case Quaff_A: Echo("What to you wish to quaff (* for list)?"); break;
      case Wear_A: Echo("Which armor do you wish to wear (* for list)?"); break;
      case Wield_A: Echo("Which weapon do you wish to wield (* for list)?"); break;
      case Call_A: Echo("Which item do you wish to call (* for list)?"); break;
      case Drop_A: Echo("Which item do you wish to drop (* for list)?"); break;
      case Identify_A: Echo("What do you want to identify (* for list)?"); break;
      case Throw_A: Echo("What do you want to throw (* for list)?"); break;
      default: Echo("Oh god!  Choose_Item called illegally");
      }
    Move_To_Echo();
    Ch = Comand();
    More = (Ch != CHESC);
    if (More) {
      This_one = Take_from_pack(&Ch, &Player.Obj_List, O_Typ, Discard, Only_1);
      More = (This_one == NULL && Ch != CHESC);
    } else {
      Clear_Echo();
      Redisplay();
    }
    if (! More)
      break;
    if (! (Ch == '*' || Ch == '?')) {
      Empty_Echo = true;
      if (Switches.Terse_swi)
	switch (Typ) {
	case Eat_A: Echo("You can\'t eat that!"); break;
	case Put_On_A: Echo("You can\'t put that on!"); break;
	case Zap_A: Echo("You can\'t zap that!"); break;
	case Read_A: Echo("That\'s illegible!"); break;
	case Quaff_A: Echo("That\'s undrinkable!"); break;
	case Wear_A: Echo("You can\'t wear that!"); break;
	case Wield_A: Echo("You can\'t wield that!"); break;
	case Call_A:
	case Drop_A:
	case Identify_A: Echo("You don\'t have that!"); break;
	case Throw_A: Echo("You can\'t throw that!"); break;
	default: Echo("You can\'t!");
	}
      else
	switch (Typ) {
	case Eat_A: Echo("Icky-poo! Why would you want to eat that?"); break;
	case Put_On_A: Echo("You can\'t put that on your finger!"); break;
	case Zap_A: Echo("You can\'t zap with that!"); break;
	case Read_A: Echo("You can\'t read that!"); break;
	case Quaff_A: Echo("You can\'t drink that!"); break;
	case Wear_A: Echo("You can\'t wear that!"); break;
	case Wield_A: Echo("You can\'t wield that!"); break;
	case Call_A: Echo("You have no such object"); break;
	case Drop_A: Echo("That is not a valid object to drop"); break;
	case Identify_A: Echo("That is not a valid object to identify"); break;
	case Throw_A: Echo("You can\'t throw that!"); break;
	default: Echo("You can\'t and you won\'t!"); break;
	}
    }
  }
  return(This_one);
} /* Choose_Item */

bool Drop() {
  Obj_Ptr This_one;
  Hand_Type Hand;

  if (World.Obj[Player.Loc.x][Player.Loc.y]) {
    Echo("You can\'t.  There is something there already");
    return(false);
  }

  This_one = Choose_Item(Drop_A, All_T, true, false); /* #54 */
  if (This_one) {
    if (This_one == Player.Cur_Wep) {
      if (Player.Cur_Wep->Cursed) {
	Insert(&Player.Obj_List, This_one);
	Give_cursed_message();
	return(false);
      }
    } else if (This_one == Player.Cur_Arm) {
      Insert(&Player.Obj_List, This_one);
      Empty_Echo = true;
      if (Switches.Terse_swi)
	Echo("Take it off first");
      else
	Echo("You must take it off before you drop it");
      return(false);
    } else {
      for (Hand = Left_H; Hand <= Right_H; Hand++) {
	if (This_one == Player.Cur_Ring[Hand]) {
	  if (Player.Cur_Ring[Hand]->Cursed) {
	    Insert(&Player.Obj_List, This_one);
	    Give_cursed_message();
	    return(false);
	  } else
	    Take_It_Off(This_one);
	}
      }
    }

    Put_on_floor(This_one, Player.Loc.x, Player.Loc.y);
    Empty_Echo = true;
    Echo_Init();
    strcat(F, "Dropped ");
    Write_obj_name(F, This_one, Not_Another);
    Echo(Echo_Str);
    if (This_one->Obj_Typ == Amulet_T)
      Player.Has_amulet = false;
    return(true);
  }
  return(false);
} /* Drop */

			    /* *********
			     * Scrolls *
			     ***********/

void Enchant_Armor() {

  if (Player.Cur_Arm) {
    Echo_Init();
    if (!Switches.Terse_swi)	/* #54 */
      strcat(F, "As the scroll vanishes, ");
    strcat(F, "your ");
    strcat(F, Armor[Player.Cur_Arm->Index].Name); /* #71 no length */
    strcat(F, " glows blue");
    Echo_Str[0] = toupper(Echo_Str[0]);
    Echo(Echo_Str);
    Player.Cur_Arm->Plus_Hit++;
    Player.Cur_Arm->Cursed = false;
    Figure_Ac();
    Scroll[s_armor].Id = true;	/* #71 */
  }
} /* Enchant_Armor */

void Enchant_Weapon() {
  int Plus;

  if (Player.Cur_Wep) {
    Echo_Init();
    if (!Switches.Terse_swi)
      strcat(F, "As the scroll vanishes, ");
    strcat(F, "your ");
    strcat(F, Weapon[Player.Cur_Wep->Index].Name); /* #71 no length */
    strcat(F, " twists in your hand");
    Echo_Str[0] = toupper(Echo_Str[0]);
    Echo(Echo_Str);
    Plus = 1 + (Die(5) == 1 ? 1 : 0);
    if (Die(2) == 1)
      Player.Cur_Wep->Plus_Hit += Plus;
    else
      Player.Cur_Wep->Plus_Dam += Plus;
    Player.Cur_Wep->Cursed = false;
    Scroll[s_weapon].Id = true;	/* #71 */
  }
} /* Enchant_Weapon */

void Identify(bool Known) {
  Obj_Ptr This_one;

  if (! Known)
    Echo("This scroll is an identify scroll");
  Scroll[s_identify].Id = true;
  This_one = Choose_Item(Identify_A, All_T, false, false); /* #54 */
  if (This_one) {
    switch (This_one->Obj_Typ) {
    case Ring_T: Ring[This_one->Index].Id = true; break;
    case Wand_T: Wand[This_one->Index].Id = true; break;
    case Scroll_T: Scroll[This_one->Index].Id = true; break;
    case Potion_T: Potion[This_one->Index].Id = true; break;
    default: break;
    }
    Empty_Echo = true;
    Echo_Init();
    This_one->Know_magic = true;
    Write_obj_name(F, This_one, Not_Another);
    Echo(Echo_Str);
  }
} /* Identify */

void Check_Player_Level() {
  int T;

  /* With Player */
  while (Player.XP >= Two_to_the(Player.Level - 1) * 10) {
    Echo_Init();
    Player.Level++;
    sprintf(F, "Welcome to experience level %d", Player.Level);
    Echo(Echo_Str);
    T = max(Die(10),Die(10));
    Player.HP += T;
    Player.Max_HP += T;
    if (Player.Level == 5) {
      Echo("Through past experience, you now know your abilities well");
      Change_stats |= S_Top;
    }
    Change_stats |= S_Bottom;
  }
} /* Check_Player_Level */

/*  */

bool Player_Disgorged() {	/* return true if eaten */
  if (Player.Eaten_count > 0) {
    Monster[m_purple].Ac = 6;
    if (Player.Blind_count <= Player.Eaten_count) {
      Player.Blind_count = 0;
    }
    Player.Eaten_count = 0;
    Player.Stuck = false;	/* #52 */
    return true;
  }
  return false;
}

/* Remove_Monsters was internal to Genocide */
void Remove_Monsters(Mon_Ptr *L, int Idx) {
  Mon_Ptr T;

  if (*L == NULL)
    return;

  T = *L;

  if (T->Index == Idx) {
    /* Remove this monster from the Screen Arrays */
    World.Mon[T->Loc.x][T->Loc.y] = EMPTY;
    Player.XP += Monster[T->Index].Xpval;
    if (T->Index == m_mimic ||
	T->Index == m_fungi)
      Player.Stuck = false;
    else if (T->Index == m_purple)
      if (Player_Disgorged()) {
	if (World.Mon[Player.Loc.x][Player.Loc.y] == EMPTY) {
	  World.Mon[Player.Loc.x][Player.Loc.y] = '@';
	  Player_Appears();
	}
      }
    World.Num_mons--;
    /* Delink this monster */
    *L = T->Next;
    free(T);
    Remove_Monsters(L, Idx);	/* Get the rest of the icky-bobs */
  } else
    Remove_Monsters(&(*L)->Next, Idx); /* Remove the others from the list */
} /* Remove_Monsters */

void Genocide() {
  int Y_or_n,Ch;
  int Mon_Num;			/* #55 */

  Echo("You have been granted the boon of genocide");
  do {
    Y_or_n = 'n';
    Echo("Which monster?");
    Move_To_Echo();
    Ch = Comand();
    Empty_Echo = true;
    if (! Okmons[Ch])
      Echo("Please specify a letter in the alphabet");
    else
      do {
	if (Ch >= 'a')
	  Mon_Num = Ch - Mon_hi_offset; /* #55 */
	else
	  Mon_Num = Ch - Mon_lo_offset;
	Echo_Init();
	strcat(F, "You have specified: ");
	strcat(F, Monster[Mon_Num].Long_Name);
	strcat(F, "... is this correct?");
	Echo(Echo_Str);
	Move_To_Echo();
	Y_or_n = tolower(Comand());
      } while (Y_or_n != 'y' && Y_or_n != 'n');
  } while (!(Okmons[Ch] && Y_or_n == 'y'));
  if (Mon_Num == m_juiblex) {	/* #71 it doesn't work! */
    Echo("Your ears ring with the sound of booming laughter");
    return;
  }
  Monster[Mon_Num].Min_Level = INT_MAX; /* goodbyeee */
  Okmons[Ch] = false; /* #55 remove this monster from genocidable ones */
  Remove_Monsters(&World.Monsters, Mon_Num);
  Check_Player_Level();
} /* Genocide */

void Scare_monster() {
  Echo("You hear maniacal laughter in the distance");
  Scare_count += (20 + Die(10));
} /* Scare_monster */

void Remove_curse() {
  Echo("You feel as if someone is watching over you");
  /* With Player */
  if (Player.Cur_Arm)
    Player.Cur_Arm->Cursed = false;
  if (Player.Cur_Wep)
    Player.Cur_Wep->Cursed = false;
  if (Player.Cur_Ring[Left_H])
    Player.Cur_Ring[Left_H]->Cursed = false;
  if (Player.Cur_Ring[Right_H])
    Player.Cur_Ring[Right_H]->Cursed = false;
} /* Remove_curse */

void Magic_mapping() {
  int I,J;
  Trap_Ptr T;			/* #70 */
  Room_Type *rp;

  Echo("Oh, now this scroll has a map on it...");
  for (I = 0; I < Max_Room; ++I)
    if (World.Rooms[I].Existent)
      for (J = 0; J < Max_Doors; ++J) {
	/* With World.Rooms[I]*/
	rp = &World.Rooms[I];
	if (rp->Doors[J].Secret > 0) {
	  rp->Doors[J].Secret = 0;
	  World.S_World[rp->Doors[J].Abs_loc.x][rp->Doors[J].Abs_loc.y] = '+';
	}
      }

  T = World.Traps;		/* #70 add trap finding routine */
  while (T) {
    T->Chance = 0;
    World.S_World[T->Loc.x][T->Loc.y] = '^';
    World.Seen[T->Loc.x][T->Loc.y] = true;
    T = T->Next;
  } /* #70 End of New routine */

  for (J = Y_Orig; J <= S_Max_Y; ++J)
    for (I = X_Orig; I <= S_Max_X; ++I)
      if (World.S_World[I][J] == '-' ||
	  World.S_World[I][J] == '|' ||
	  World.S_World[I][J] == '+' ||
	  World.S_World[I][J] == '%' ||
	  World.S_World[I][J] == '#')
	World.Seen[I][J] = true;

  Player_Appears();		/* #54 */
  Update_Screen();
} /* Magic_mapping */

void Nothing_Scroll() {
  switch (Blank_message) {
  case 1: Echo("This scroll appears to be blank"); break;
  case 2: Echo("You hear a high-pitched humming noise in the distance"); break;
  case 3: Echo("You hear a rustling in the shadows behind you"); break;
  }
}

void Teleportation() {
  if (! Player_Disgorged())
    World.Mon[Player.Loc.x][Player.Loc.y] = EMPTY;
  Player.Prev = Player.Loc;
  Pick_A_Place(&Player.Loc.x, &Player.Loc.y);
  World.Mon[Player.Loc.x][Player.Loc.y] = '@';
  Player_Jumps();
} /* Teleportation */

Obj_Ptr Pick_Random_Object(char *Ch) {

  int I, Max;
  Obj_Ptr Object;

#if 1				/* #71 improved algorithm? */
  Max = 0;
  Object = Player.Obj_List;
  while (Object) {
    Max++;			/* count objects */
    Object = Object->Next;
  }
  Max = Die(Max);		/* choose one */
  Object = Player.Obj_List;
  I = 1;
  while (I < Max) {
    Object = Object->Next;
    I++;
  }
  *Ch = 'a' + I - 1;
#else  /* #71 old algorithm tended to favor items earlier in the list */
  Max = Die(Max_Item);
  *Ch = 'a';
  Object = Player.Obj_List;
  for (I = 1; I <= Max; ++I) {
    Object = Object->Next;
    (*Ch)++;
    if (Object == NULL) {
      Object = Player.Obj_List;
      *Ch = 'a';
    }
  }
#endif
  return(Object);
}

void Cancellation() {
  Obj_Ptr Cancel;
  bool Saved_Obj;
  Hand_Type Hand;
  char Ch;

  Echo_Init();
  Cancel = Pick_Random_Object(&Ch);
  if (! Cancel)
    return;

  /* With Cancel^ */
  switch (Cancel->Obj_Typ) {
  case Ring_T:
    Saved_Obj = (Die(20) >= 17);
    break;

  case Wand_T:
    if (Wand[Cancel->Index].Is_wand)
      Saved_Obj = (Die(20) >= 15);
    else
      Saved_Obj = (Die(20) >= 13);
    break;

  case Scroll_T:
    Saved_Obj = (Die(20) >= 19);
    break;

  case Potion_T:
    Saved_Obj = (Die(20) >= 20);
    break;

  case Armor_T:
    Saved_Obj = (Die(20) >= 11);
    break;

  case Weapon_T:
    Saved_Obj = (Die(20) >= 9);
    break;

  default:
    Saved_Obj = true;
  } /* Case Obj_Typ */

  if (!Saved_Obj) {
    Cancel->Plus_Hit = 0;
    Cancel->Plus_Dam = 0;
    Cancel->Cursed = false;
    switch (Cancel->Obj_Typ) {
    case Ring_T:
      for (Hand = Left_H; Hand <= Right_H; Hand++) {
	if (Player.Cur_Ring[Hand])
	  if (Player.Cur_Ring[Hand] == Cancel) {
	    if (Cancel->Index == r_resur) {
	      if (Cancel->Plus_Dam > 0) {
		/* He is now REALLY Dead! */
		Echo("The wand cancels the magic of your ring and you are dead!");
		Dead = true;
		Killer = '=';
	      } /* He is now REALLY Dead! */
	    } else
	      Take_It_Off(Cancel);
	  }
      }
      break;

    case Armor_T:
      Figure_Ac();
      break;

    case Scroll_T:
      Cancel->Index = s_nothing;
      break;

    case Potion_T:
      Cancel->Index = p_nothing;
      break;

    default:;
    } /* Case Obj_Typ */
  } /* If Not Saved_Obj */
} /* Cancellation */

/* Convert some item into something else */
void Alchemy() {
  Obj_Ptr Stolen;
  Obj_Class_Type Typ;
  int Index, I;
  char Ch;
  Hand_Type Hand;

  Echo_Init();
  Stolen = Pick_Random_Object(&Ch);
  if (Stolen == NULL)
    return;

  Stolen = Take_from_pack(&Ch, &Player.Obj_List, All_T, true, false);
  /* With Player */
  if (Stolen == Player.Cur_Arm) {
    Player.Cur_Arm = NULL;
    Figure_Ac();
  } else if (Stolen == Player.Cur_Wep)
    Player.Cur_Wep = NULL;
  else
    for (Hand = Left_H; Hand <= Right_H; ++Hand)
      if (!Dead)
	if (Stolen == Player.Cur_Ring[Hand]) {
	  Player.Cur_Ring[Hand] = NULL;
	  if (Stolen->Index != r_resur)
	    Take_It_Off(Stolen);
	  else if (Stolen->Plus_Dam > 0) {
	    Echo("As your ring is transformed your life force drains away");
	    Echo("You are dead!");
	    Killer = '=';
	    Dead = true;
	  }
	}

  I = 0;
  Index = 0;
  Typ = Gold_T;
  while (Typ == Gold_T || Index == 0) {
    I++;
    Rand_Obj(&Typ, &Index);	/* get a new random object */
  }

  Stolen->Obj_Typ = Typ;	/* Defaults */
  Stolen->Index = Index;
  Stolen->Plus_Hit = 0;
  Stolen->Plus_Dam = 0;
  Stolen->Know_magic = false;
  Stolen->Quan = 1;
  Magic_Aids(I, Index, Stolen, Typ); /* NOTE: I is bogus here... */
  Insert(&Player.Obj_List, Stolen);
} /* Alchemy */

void Curing() {
  if (Player.HP < Player.Max_HP) {
    Player.HP = min(Player.HP + Die(16) + 5, Player.Max_HP);
    Empty_Echo = true;
    Echo("You begin to feel better");
  } else {
    Player.Max_HP++;
    Player.HP++;
    Echo("You feel more virile now");
  }
  if (Player.Blind_count > 0)
    No_more_blindness();
  Change_stats |= S_Bottom;
} /* Curing */

void Summon_monster() {
  Loc_Type Other;
  Mon_Ptr M;

  Place_Next_To(Player.Loc, &Other, false);
  Gen_monster(World.Level, -1, &M, true);
  if (M->Index != m_mimic)
    M->Loc = Other;
  Place_Monster(M);
  Update_Screen();
} /* Summon_monster */

void Light() {
  int Room;

  Room = World.Room_array[Player.Loc.x][Player.Loc.y];
  if (Room < 0) {
    if (Player.Blind_count)
      Echo("Nothing happens");
    else
      Echo("The corridor glows and then fades");
  } else {
    if (Player.Blind_count)
      Echo("Nothing happens");
    else if (World.Rooms[Room].Light)
      Echo("The room is already lit");
    else
      Echo("The room is now lit");
    World.Rooms[Room].Light = true;
    World.Rooms[Room].Seen = false;
    Draw_Room(Room, true);
  }
  Update_Screen();
}

void Hold_Portal() {
  int I,Room;
  Room_Type *rp;

  Room = World.Room_array[Player.Loc.x][Player.Loc.y];
  if (Room >= 0) {
    /* With World.Rooms[Room]*/
    rp = &World.Rooms[Room];
    for (I = 0; I < Max_Doors; ++I)
      if ((rp->Doors[I].Abs_loc.x != 0) && (rp->Doors[I].Abs_loc.y != 0))
	if (World.Mon[rp->Doors[I].Abs_loc.x][rp->Doors[I].Abs_loc.y] == EMPTY) {
	  if (rp->Doors[I].Secret <= 0)	/* #71 */
	    rp->Doors[I].Secret = 5;
	  if ((I == Door_Up) || (I == Door_Down))
	    World.S_World[rp->Doors[I].Abs_loc.x][rp->Doors[I].Abs_loc.y] = '-';
	  else
	    World.S_World[rp->Doors[I].Abs_loc.x][rp->Doors[I].Abs_loc.y] = '|';
	}
    Update_Screen();
  }
}

bool Eat_Food() {
  Obj_Ptr This_one;

  This_one = Choose_Item(Eat_A, Food_T, true, true); /* #54 */
  if (This_one == NULL)
    return(false);

  Player.Faint_count = 0;
  Player.Last_meal = min(Player.Last_meal - Hungry_Meal, 0);
  Empty_Echo = true;
  Echo_Init();
  if (This_one->Index == 1) {
    switch (Die(5)) {
    case 1: strcat(F, "My, that was a yummy "); break;
    case 2: strcat(F, "Your eyes water as you eat the "); break;
    case 3: strcat(F, "Yecch!  That was a putrid "); break;
    case 4: strcat(F, "What a satisfying "); break;
    case 5: strcat(F, "That was a very refreshing "); break;
    }
    strcat(F, Fruit_name);
    Player.Invis_count += (75 + Die(50));
  } else
    switch (Die(8)) {		/* #71 */
    case 1: strcat(F, "My, that tasted good"); break;
    case 2: strcat(F, "Yecch!  That food tasted awful!"); break;
    case 3: strcat(F, "The repast was filling but flavorless"); break;
    case 4: strcat(F, "One Whopper, no onions, extra pickle and tomato down the hatch!"); break;
    case 5: strcat(F, "Your limited culinary expertise made the food taste awful"); break;
    case 6: strcat(F, "That ration tasted surprisingly like a Tommyburger"); break;
    case 7: strcat(F, "Your tastebuds are delighted and your stomach is filled"); break;
    case 8: strcat(F, "Mmmm.  Donuts."); break;	/* #71 */
    }
  Echo(Echo_Str);
  Change_stats |= S_Bottom;

  if (This_one->Quan == 0)
    free(This_one);
  return true;
} /* Eat_Food */

void Slow_Inventory(Obj_Ptr List) { /* #54 many changes */
  Obj_Ptr This_one;
  /*  Bogus : Boolean; */
  char Ch;

  if (Switches.Terse_swi)
    Echo("Inventory what?");
  else
    Echo("Which item do you want inventoried (* for all)?");
  Move_To_Echo();
  Ch = Comand();
  Empty_Echo = true;
  if (Ch == CHESC) {
    Clear_Echo();
    Redisplay();
    return;
  }

  if (isalpha(Ch)) {
    This_one = Take_from_pack(&Ch, &List, All_T, false, false);
    if (Ch == CHESC)
      Clear_Echo();
    else if (This_one == NULL) {
      Empty_Echo = true;
      Echo("You don\'t have such an object");
    } else {
      Empty_Echo = true;
      Echo_Init();
      if (! Switches.Terse_swi)
	strcat(F, "That is: ");
      Write_obj_name(F, This_one, Not_Another);
      Echo(Echo_Str);
    }
  } else
    switch (Ch) {
    case '*': Ch = Inventory(List, All_T, false); break; /* #65 */
    case '!': Ch = Inventory(List, Potion_T, false); break; /* #65 */
    case ')': Ch = Inventory(List, Weapon_T, false); break; /* #65 */
    case '[': Ch = Inventory(List, Armor_T, false);  break; /* #65 */
    case '&': Ch = Inventory(List, Food_T, false); break;  /* #65 */
    case '$': Ch = Inventory(List, Amulet_T, false); break; /* #65 */
    case '?': Ch = Inventory(List, Scroll_T, false); break; /* #65 */
    case '/': Ch = Inventory(List, Wand_T, false); break; /* #65 */
    case '=': Ch = Inventory(List, Ring_T, false); break; /* #65 */
    default: Echo("You have no such object");
    }

  Update_Screen();		/* #61 */
} /* Slow_Inventory */

bool Read_scroll() {
  Obj_Ptr This_one;
  Scrolls *sp;

  if (Player.Blind_count > 0) {
    if (Switches.Terse_swi)
      Echo("You are blind");
    else
      Echo("How can you do that?  You are blind, remember?");
    return(false);
  } else if (Player.Eaten_count > 0) {
    if (Switches.Terse_swi)
      Echo("It\'s dark in here");
    else
      Echo("It\'s too dark in the Purple Worm\'s stomach to see ANYTHING");
    return(false);
  }

  This_one = Choose_Item(Read_A, Scroll_T, true, true); /* #54 */
  if (This_one == NULL)
    return(false);

  Empty_Echo = true;
  Echo("As you read the scroll, it vanishes...");
  if ((Player.IQ < 7) && (Die(10) <= (7 - Player.IQ))) {
    if (Switches.Terse_swi)
      Echo("You lose your place");
    else
      Echo("You lose your place while reading the scroll, wasting it");
  } else {
    switch (This_one->Index) {
    case s_armor: Enchant_Armor(); break;
    case s_weapon: Enchant_Weapon(); break;
    case s_curse: Remove_curse(); break;
    case s_mapping: Magic_mapping(); break;
    case s_identify: Identify(Scroll[This_one->Index].Id); break;
    case s_genocide: Genocide(); break;
    case s_scare: Scare_monster(); break;
    case s_nothing: Nothing_Scroll(); break;
    case s_teleport: Teleportation(); break;
    case s_summon: Summon_monster(); break;
    case s_light: Light(); break;
    case s_hold: Hold_Portal(); break;
    default:
      if (logfp)
	fprintf(logfp, "Error - Nonexistent scroll type");
    }
    Update_Screen();		/* #60 */
    /* With Scroll[This_one->Index] */
    sp = &Scroll[This_one->Index];
    if (This_one->Index == s_mapping ||
	This_one->Index == s_identify ||
	This_one->Index == s_genocide ||
	This_one->Index == s_teleport ||
	This_one->Index == s_light)
      sp->Id = true;
    if ((! sp->Id) && (! sp->Called) && Switches.Ask_swi)
      Name_obj(This_one);
  }

  if (This_one->Quan == 0)
    free(This_one);
  return true;
} /* Read_scroll */

bool Wield_weapon() {
  Obj_Ptr This_one;

  if (Player.Cur_Wep)
    if (Player.Cur_Wep->Cursed) {
      Give_cursed_message();
      return false;
    }

  This_one = Choose_Item(Wield_A, Weapon_T, false, false); /* #54 */
  if (This_one) {
    Empty_Echo = true;
    Echo_Init();
    if (This_one == Player.Cur_Wep)
      strcat(F, "Already wielding ");
    else
      strcat(F, "Now wielding ");
    Write_obj_name(F, This_one, Not_Another);
    Echo(Echo_Str);
    Player.Cur_Wep = This_one;
    return true;
  }
  return false;
}

void Move_monsters(Mon_Ptr M); 	/* Forward */

bool Wear_armor() {
  Obj_Ptr This_one;

  if (Player.Cur_Arm) {
    Echo("You are already wearing some");
    return false;
  }

  This_one = Choose_Item(Wear_A, Armor_T, false, false); /* #54 */
  if (This_one) {
    Empty_Echo = true;
    /* a free move for monsters while player is busy */
    Move_monsters(World.Monsters);
    Echo_Init();
    strcat(F, "Now wearing ");
    Write_obj_name(F, This_one, Not_Another);
    Echo(Echo_Str);
    Player.Cur_Arm = This_one;
    Figure_Ac();
    This_one->Know_magic = true;
    return true;
  } /* got some armor */
  return false;
} /* Wear_Armor */

bool Take_off_armor() {

  if (Player.Cur_Arm)
    if (Player.Cur_Arm->Cursed) {
      Give_cursed_message();
    } else {
      /* With Player */
      /* a free move for monsters while player is busy */
      Move_monsters(World.Monsters);
      Echo_Init();
      strcat(F, "Was wearing ");
      Write_obj_name(F, Player.Cur_Arm, Not_Another);
      Echo(Echo_Str);
      Player.Cur_Arm = NULL;
      Figure_Ac();
      return(true);
    }
  else
    Echo("But you aren\'t wearing any armor!");
  return(false);
}

			    /* *******/
			    /* Rings */
			    /* *******/

void On_R_Dexterity(int How_much) {
  Player.Max_DX += How_much;
  Player.DX += How_much;
  Change_stats |= S_Top;
} /* On_R_Dexterity */

void On_R_Strength(int How_much) {
  Player.Max_ST += How_much;
  Player.ST += How_much;
  Change_stats |= S_Top;
} /* On_R_Strength */

void On_R_Intelligence(int How_much) {
  Player.Max_IQ += How_much;
  Player.IQ += How_much;
  Change_stats |= S_Top;
} /* On_R_Intelligence */

void On_R_Resurrection(int p) {
  if (p <= 0) {
    Echo("Your life force drains into the fell ring on your finger");
    Echo("You are dead!");
    Killer = '=';
    Dead = true;
  }
} /* On_R_Resurrection */

bool Put_on_ring() {		/* #54 a few changes */
  char Hand;
  Obj_Ptr This_one;

  if (Player.Cur_Ring[Left_H] && Player.Cur_Ring[Right_H]) {
    if (Switches.Terse_swi)
      Echo("You have no free hand");
    else
      Echo("You have no free hand on which to put a ring!");
    return false;
  }

  /* We have a free hand */
  This_one = Choose_Item(Put_On_A, Ring_T, false, false); /* #54 */
  if (! This_one)
    return false;

  if ((This_one == Player.Cur_Ring[Left_H]) ||
      (This_one == Player.Cur_Ring[Right_H])) {
    Empty_Echo = true;
    Echo("You already have that ring on");
    return false;
  }

  Empty_Echo = true;
  if (Player.Cur_Ring[Left_H])
    Hand = 'R';
  else if (Player.Cur_Ring[Right_H])
    Hand = 'L';
  else
    while (true) {		/* #54 */
      Echo("Which hand?");
      Move_To_Echo();
      Hand = toupper(Comand());
      if (Hand == 'L' || Hand == 'R' || Hand == CHESC)
	break;
      Empty_Echo = true;
      Echo("Please type \"L\", \"R\" or <Esc>");
    }
  if (Hand == CHESC) {		/* #67 */
    Clear_Echo();
    Redisplay();
    return false;
  }

  Empty_Echo = true;
  if (Hand == 'R')
    Player.Cur_Ring[Right_H] = This_one;
  else
    Player.Cur_Ring[Left_H] = This_one;
  Echo_Init();
  strcat(F, "Now wearing ");
  Write_obj_name(F, This_one, Not_Another);
  Echo(Echo_Str);
  switch (This_one->Index) {
  case r_protect: Figure_Ac();				 break;
  case r_dex:     On_R_Dexterity(This_one->Plus_Hit);	 break;
  case r_str:     On_R_Strength(This_one->Plus_Hit);	 break;
  case r_int:     On_R_Intelligence(This_one->Plus_Hit); break;
  case r_resur:   On_R_Resurrection(This_one->Plus_Hit); break;
  default: ;
  }
  Update_Screen();		/* #60 */
  return true;
} /* Put_on_ring */

void Off_R_Dexterity(int How_much) {
  Player.DX -= How_much;
  Player.Max_DX -= How_much;
  Change_stats |= S_Top;
} /* Off_R_Dexterity */

void Off_R_Strength(int How_much) {
  Player.Max_ST -= How_much;
  Player.ST -= How_much;
  Change_stats |= S_Top;
} /* Off_R_Strength */

void Off_R_Intelligence(int How_much) {
  Player.Max_IQ -= How_much;
  Player.IQ -= How_much;
  Change_stats |= S_Top;
} /* Off_R_Intelligence */

/* need to check if Ring of resurrection is dropped after being used */
void Off_R_Resurrection(int P) {
  if (P > 0) {
    Echo("As the ring is removed so is your life force...");
    Echo("You are dead!");
    Killer = '=';
    Dead = true;
  }
} /* Off_R_Resurrection */

void Take_It_Off(Obj_Ptr Which) {
  switch (Which->Index) {
  case r_protect: Figure_Ac(); break;
  case r_dex:     Off_R_Dexterity(Which->Plus_Hit); break;
  case r_str:     Off_R_Strength(Which->Plus_Hit); break;
  case r_int:     Off_R_Intelligence(Which->Plus_Hit); break;
  case r_resur:   Off_R_Resurrection(Which->Plus_Dam); break;
  default: ;
  }
}

bool Remove_Ring() {
  bool Bogus,More;
  char Ch;
  Hand_Type Hand;
  Obj_Ptr The_Ring;

  More = true;
  Bogus = true;
  Empty_Echo = true;
  do {
    /* With Player */
    if (Player.Cur_Ring[Right_H] == NULL && Player.Cur_Ring[Left_H] == NULL) {
      Empty_Echo = true;
      Echo("You\'re not wearing a ring");
      return false;
    } else if (Player.Cur_Ring[Left_H] == NULL)
      Ch = 'r';
    else if (Player.Cur_Ring[Right_H] == NULL)
      Ch = 'l';
    else {
      Echo("Which ring?");
      Move_To_Echo();
      Ch = tolower(Comand());
      if (Ch == '*') {
	Echo_Init();
	strcat(F, "l) ");
	Write_obj_name(F, Player.Cur_Ring[Left_H], Not_Another);
	Scr_Text(Y_Orig, Echo_Str);
	Echo_Init();
	strcat(F, "r) ");
	Write_obj_name(F, Player.Cur_Ring[Right_H], Not_Another);
	Scr_Text(Y_Orig + 1, Echo_Str);
	Redisplay();
	Bogus = Wait_For_Space(false);
	Empty_Echo = true;
	Clear_Echo();
	Update_Screen();
      } else if (Ch != 'l' && Ch != 'r' && Ch != CHESC) {
	Empty_Echo = true;
	Echo("Please type \"l\", \"r\", \"*\", or <Esc>");
      }
    }
  } while (Ch != 'l' && Ch != 'r' && Ch != CHESC && More);
  if (Ch == CHESC) {
    Clear_Echo();
    Redisplay();
    return false;
  }

  Empty_Echo = true;
  if (Ch == 'l')
    Hand = Left_H;
  else
    Hand = Right_H;
  if (Player.Cur_Ring[Hand]->Cursed)
    Give_cursed_message();
  else {
    The_Ring = Player.Cur_Ring[Hand];
    Player.Cur_Ring[Hand] = NULL;
    Echo_Init();
    strcat(F, "Was wearing ");
    Write_obj_name(F, The_Ring, Not_Another);
    Echo(Echo_Str);
    Take_It_Off(The_Ring);
    Update_Screen();		/* #60 */
    return true;
  }
  return false;
} /* Remove_Ring */

			    /* *********
			     * Potions *
			     ***********/

void Random_Potion(int Index) {

  switch (Die(8)) {
  case 1: Echo("The potion has no discernable effect"); break;
  case 2: Echo("You\'re not sure what that potion did"); break;
  case 3: Echo("You feel strange for a moment, but the feeling passes"); break;
  case 4: Echo("What an odd-tasting potion..."); break;
  case 5: Echo("That hit the spot!"); break;
  case 6: Echo("Well, you\'re not thirsty anymore..."); break;
  case 7: Echo("That was a waste of a potion"); break;
  case 8:
    Echo_Init();
    strcat(F, "A bit of ");
    strcat(F, Potion[Index].Desc);
    strcat(F, " fluid dribbles down your chin");
    Echo(Echo_Str);
    break;
  }
} /* Random_Potion */

void Gold_detection(bool *id) {
  Obj_Ptr p;
  bool found;

  found = false;
  p = World.Objs;
  while (p) {
    if (p->Obj_Typ == Gold_T) {
      World.Seen[p->Loc.x][p->Loc.y] = true;
      found = true;
    }
    p = p->Next;
  }
  *id = found || *id;
  if (found)
    Echo("You feel greedy and sense the presence of gold");
  else
    Random_Potion(p_gold_det);
}

void Monster_detection(bool *id) {
  Mon_Ptr p;
  bool found;

  found = false;
  Player.SeeMon_count = Die(100) + 100;
  Player.Invis_count = max(Player.SeeMon_count, Player.Invis_count);

  p = World.Monsters;
  while (p) {
    World.Seeable[p->Loc.x][p->Loc.y] = true;
    if (p->Index == m_mimic) {
      World.Mon[p->Loc.x][p->Loc.y] = Monster[m_mimic].Name;
      p->Awake = true;
    }
    found = true;
    p = p->Next;
  }
  *id = found || *id;
  if (found)
    Echo("Your spine chills as you sense the presence of monsters");
  else
    Echo("You feel somehow reassured");
}

void Magic_detection(bool *id) {
 Obj_Ptr p;
 bool found;

  found = false;
  p = World.Objs;
  while (p) {
    if ((p->Obj_Typ == Scroll_T ||
	 p->Obj_Typ == Potion_T ||
	 p->Obj_Typ == Ring_T ||
	 p->Obj_Typ == Wand_T) ||
	(p->Plus_Hit != 0) || (p->Plus_Dam != 0)) {
      World.Seen[p->Loc.x][p->Loc.y] = true;
      found = true;
    }
    p = p->Next;
  }
  *id = found || *id;
  if (found)
    Echo("You feel strange and sense the presence of magic");
  else
    Random_Potion(p_magic_det);
}

void Regain_Strength() {

  if (Player.ST < Player.Max_ST) {
    Player.ST = Player.Max_ST;
    Echo("Hey!  This tastes great!  It makes you feel warm all over...");
    Potion[p_reg_str].Id = true;
  } else
    Random_Potion(p_reg_str);
} /* Regain_Strength */

void Regain_Intelligence() {
  if (Player.IQ < Player.Max_IQ) {
    Player.IQ = Player.Max_IQ;
    Echo("The potion makes your head spin, but now you feel great!");
    Potion[p_reg_int].Id = true;
  } else
    Random_Potion(p_reg_int);
} /* Regain_Intelligence */

void Regain_Dexterity() {
  if (Player.DX < Player.Max_DX) {
    Player.DX = Player.Max_DX;
    Echo("The potion sends a tingling throughout your entire body. Wow!");
    Potion[p_reg_dex].Id = true;
  } else
    Random_Potion(p_reg_dex);
} /* Regain_Dexterity */

void Poison() {
  if (! Has_on_ring(r_sustain)) {
    Echo("You feel very sick now");
    Player.ST -= Die(3);
  } else
    Echo("The potion tastes very bad");
} /* Poison */

void Feeblemind() {
  Echo("You feel very stupid now");
  Player.IQ -= Die(3);
}

void Fumbling() {
  Echo("You feel very clumsy now");
  Player.DX -= Die(3);
}

void Incr_strength() {
  Echo("You feel much stronger now.  What bulging muscles!");
  Player.Max_ST++;
  Player.ST++;
}

void Incr_intelligence() {
  Echo("You feel much smarter now.  Geez, what a brain");
  Player.Max_IQ++;
  Player.IQ++;
}

void Incr_dexterity() {
  Echo("You feel much more nimble now.  Very impressive");
  Player.Max_DX++;
  Player.DX++;
}

void Skillfulness() {		/* raise exp. level */
  Echo("You suddenly feel much more skillful");
  Player.XP = Two_to_the(Player.Level - 1) * 10;
  Check_Player_Level();
} /* Skillfulness */

void Healing() {
  if (Player.HP < Player.Max_HP) {
    Player.HP = min(Player.HP + Die(8) + 10, Player.Max_HP);
    if (Switches.Terse_swi)
      Echo("You begin to feel better");
    else
      Echo("As the potion enters your blood stream you begin to feel better");
  } else {
    Echo("You feel more virile");
    Player.Max_HP++;
    Player.HP++;
  }
  if (Player.Blind_count > 0)
    No_more_blindness();
} /* Healing */

void Extra_Healing() {
  if (Player.HP < Player.Max_HP) {
    Player.HP = min(Player.HP + Die(8) + Die(8) + 20, Player.Max_HP);
    if (Switches.Terse_swi)
      Echo("You begin to feel much better");
    else
      Echo("You swallow the fluid and begin to feel much better!");
  } else {
    Echo("You feel exceptionally virile");
    Player.Max_HP++;
    Player.HP++;
  }
  if (Player.Blind_count > 0)
    No_more_blindness();
} /* Extra_Healing */

void See_invisible() {
  Echo_Init();
  strcat(F, "This potion tastes like the juice of a ");
  strcat(F, Fruit_name);
  Echo(Echo_Str);
  Player.Invis_count = 100 + Die(100);
}

void Haste_self() {
  if (Player.Speed != 1) {	/* 1 is slow */
    Echo("You feel yourself moving much faster");
    Player.Speed = 3;		/* 3 is fast */
    if (Player.Speed_count == 0)
      Player.Speed_count = -1;
    else
      Player.Speed_count = - Player.Speed_count;
  } else
    Player.Speed_count = 1;
} /* Haste_self */

void Slow_self() {
  if (Player.Speed != 3) {	/* 3 is fast */
    Echo("You become strangely sluggish");
    Player.Speed = 1;		/* 1 is slow */
    if (Player.Speed_count == 0)
      Player.Speed_count = -1;
    else
      Player.Speed_count = - Player.Speed_count;
  } else
    Player.Speed_count = 1;
} /* Slow_self */

void Blindness() {
  bool Was;

  Was = Player.Blind_count != 0;
  Player.Blind_count += 500 + Die(100);
  if (Was)
    Echo("Things seem a bit darker somehow");
  else
    Echo("A cloak of darkness falls around you");
}

void Confusion() {
  if (Switches.Terse_swi)
    Echo("You feel very confused now");
  else
    Echo("Wait, what\'s going on here. Huh? What? Who?");
  if (Player.IQ < 7)
    Player.Confused_count += 40 + Die(10);
  else if (Player.IQ > 14)
    Player.Confused_count += 10 + Die(5);
  else
    Player.Confused_count += 20 + Die(5);
}

void Confuse_monster() {
  if (Player.Blind_count > 0) 	/* #71 */
    Random_Potion(p_confuse_mon); /* #71 */
  else
    Echo("Your hands glow red for a moment, then the color fades");
  Player.Will_confuse = true;
}

void Sleep() {
  if (Switches.Terse_swi)
    Echo("You fall asleep");
  else
    Echo("The potion makes you feel very drowsy, and you collapse");
  Player.Sleep_count += Die(10) + 5;
}

void Paralysis() {
  if (Switches.Terse_swi)
    Echo("You can\'t move");
  else
    Echo("You are frozen to the spot");
  Player.Paralyzed_count += Die(10) + 5;
}

void Nothing_Potion() {
  switch (Blank_message) {
  case 1: Echo("This potion tastes like water"); break;
  case 2:
    if (Player.Blind_count > 0)	/* #71 */
      Echo("Your ears ring for a moment"); /* #71 */
    else
      Echo("Your vision blurs for a moment");
    break;
  case 3: Echo("A small insect buzzes around your head and flies away"); break;
  }
}

void Food_Potion() {		/* #54 */
  switch (Blank_message) {
  case 1: Echo("This potion makes your stomach stop grumbling"); break;
  case 2: Echo("This was a remarkably satisfying potion"); break;
  case 3 : Echo("Yum!"); break;
  }
  Player.Last_meal = min(0, Player.Last_meal) - (2 * Fainting_Meal); /* #71 */
  Player.Faint_count = 0;
} /* Food_Potion */

bool Quaff_potion() {
  Obj_Ptr This_one;

  This_one = Choose_Item(Quaff_A, Potion_T, true, true); /* #54 */
  if (This_one == NULL)
    return false;

  Echo_Init();
  Empty_Echo = true;
  switch (This_one->Index) {
  case p_gold_det:    Gold_detection(&Potion[This_one->Index].Id); break;
  case p_mon_det:     Monster_detection(&Potion[This_one->Index].Id); break;
  case p_magic_det:   Magic_detection(&Potion[This_one->Index].Id); break;
  case p_reg_str:     Regain_Strength(); break;
  case p_reg_int:     Regain_Intelligence(); break;
  case p_reg_dex:     Regain_Dexterity(); break;
  case p_poison:      Poison(); break;
  case p_feeble:      Feeblemind(); break;
  case p_fumble:      Fumbling(); break;
  case p_incr_str:    Incr_strength(); break;
  case p_incr_int:    Incr_intelligence(); break;
  case p_inc_dex:     Incr_dexterity(); break;
  case p_skill:       Skillfulness(); break;
  case p_healing:     Healing(); break;
  case p_ex_healing:  Extra_Healing(); break;
  case p_invis:       See_invisible(); break;
  case p_haste:	      Haste_self(); break;
  case p_slow:        Slow_self(); break;
  case p_blind:       Blindness(); break;
  case p_confuse:     Confusion(); break;
  case p_confuse_mon: Confuse_monster(); break;
  case p_sleep:       Sleep(); break;
  case p_paralysis:   Paralysis(); break;
  case p_nothing:     Nothing_Potion(); break;
  case p_sustenance:  Food_Potion(); break;
  default:
    if (logfp)
      fprintf(logfp, "Error - Non-existent potion type\n");
    Nothing_Potion();		/* #71 why the hell not? */
  }
  if (This_one->Index == p_reg_str ||
      This_one->Index == p_reg_int ||
      This_one->Index == p_reg_dex ||
      This_one->Index == p_poison ||
      This_one->Index == p_feeble ||
      This_one->Index == p_fumble ||
      This_one->Index == p_incr_str ||
      This_one->Index == p_incr_int ||
      This_one->Index == p_inc_dex)
    Change_stats |= S_Top;
  if (This_one->Index == p_skill ||
      This_one->Index == p_healing ||
      This_one->Index == p_ex_healing ||
      This_one->Index == p_sustenance) /* #60 */
    Change_stats |= S_Bottom;
  Update_Screen();		/* #60 */
  /* With Potion[This_one->Index] */

  if (This_one->Index == p_poison ||
      This_one->Index == p_feeble ||
      This_one->Index == p_fumble ||
      This_one->Index == p_skill ||
      This_one->Index == p_healing ||
      This_one->Index == p_ex_healing ||
      This_one->Index == p_haste ||
      This_one->Index == p_slow ||
      This_one->Index == p_blind ||
      This_one->Index == p_confuse ||
      This_one->Index == p_sleep ||
      This_one->Index == p_paralysis)
    Potion[This_one->Index].Id = true;
  if ((! Potion[This_one->Index].Id) && (! Potion[This_one->Index].Called) &&
      Switches.Ask_swi)
    Name_obj(This_one);

  if (This_one->Quan == 0)
    free(This_one);

  return true;
} /* Quaff_potion */

bool Call_obj() {
  Obj_Ptr This_one;
  Name_string New_Name;
  int Nm_Len;

  This_one = Choose_Item(Call_A, All_T, false, false); /* #54 */
  if (This_one == NULL)  /* #51 */
    return(false);

  Empty_Echo = true;
  Echo_Init();
  strcat(F, "Is now called: ");
  Write_obj_name(F, This_one, Not_Another);
  Echo(Echo_Str);
  if (! (This_one->Obj_Typ == Food_T ||
	 This_one->Obj_Typ == Armor_T ||
	 This_one->Obj_Typ == Weapon_T))
    Name_obj(This_one);
  else if ((This_one->Obj_Typ == Food_T) && (This_one->Index == 1)) { /* #55 */
    Echo("Call it:");
    Move_To_Echo();
    if (Get_Line(New_Name, &Nm_Len)) {
      if (Nm_Len > 0)
	strcpy(Fruit_name, New_Name);
    }
    Clear_Echo();
    Redisplay();
    Empty_Echo = true;
  }
  return false;
} /* Call_obj */

bool Attack(int X, int Y, Obj_Ptr Enforcer); /* Forward; */

void Hurl_obj(Obj_Ptr What, char Dir) {
  int DeltaX, DeltaY;
  Loc_Type Worker, Other;
  bool Missed, Found;

  Empty_Echo = true;
  if (Dir == CHESC) {
    Clear_Echo();
    Redisplay();
    return;
  }

  Translate_Direction(Dir, &DeltaX, &DeltaY); /* #70 */
  if (Player.Eaten_count > 0) {
    Worker.x = Player.Loc.x - DeltaX;
    Worker.y = Player.Loc.y - DeltaY;
  }
  else
    Worker = Player.Loc;
  Missed = true;
  Found = false;
  do {
    Worker.x += DeltaX;
    Worker.y += DeltaY;
    if (isalpha(World.Mon[Worker.x][Worker.y])) {
      Found = true;
      if (Attack(Worker.x, Worker.y, What)) {
	Missed = false;
	break;
      } /* #71 if it missed it keeps flying.  duh */
      if (Die(2) == 1)		/* #71 the arrow drops by the nasty */
	break;
    }
  } while (!(World.S_World[Worker.x][Worker.y] == '|' ||
	     World.S_World[Worker.x][Worker.y] == '-' ||
	     World.S_World[Worker.x][Worker.y] == ' '));

  if (Missed) {
    if (What->Obj_Typ == Wand_T) {
      if (Switches.Terse_swi)
	Echo("The bolt missed");
      else
	Echo("There is a deafening roar as the bolt hits the wall");
    } else if (What->Obj_Typ == Weapon_T) {
      if (Die(10) == 1) {
	/* With Weapon[What->Index] */
	Echo_Init();
	strcat(F, "Your ");
	strcat(F, Weapon[What->Index].Name); /* #71 */
	strcat(F, " broke against the wall");
	Echo(Echo_Str);
      } else {
	if (!Found)		/* #71 */
	  Clear_Echo();
	Place_Next_To(Worker, &Other, true);
	Put_on_floor(What, Other.x, Other.y);
      }
    }
  }
} /* Hurl_obj */

void Find_trap(Trap_Ptr T, bool Searching) {
  char M;

  T->Chance = 0;
  World.S_World[T->Loc.x][T->Loc.y] = '^';
  World.Seen[T->Loc.x][T->Loc.y] = true;
  M = World.Mon[T->Loc.x][T->Loc.y];
  World.Mon[T->Loc.x][T->Loc.y] = EMPTY;
  if (M != '@')
    Update_Screen();
  World.Mon[T->Loc.x][T->Loc.y] = M;
  if (Searching) {
      Echo_Init();
      strcat(F, "You found a");
      switch (T->Kind) {
      case t_arrow: strcat(F, "n arrow trap"); break;
      case t_bear: strcat(F, " beartrap"); break;
      case t_door: strcat(F, " trapdoor"); break;
      case t_dart: strcat(F, " dart trap"); break;
      case t_teleport: strcat(F, " teleport trap"); break;
      default: strcat(F, "Error - Unknown trap type in Find_trap");
      }
      Echo(Echo_Str);
  }
} /* Find_trap */

bool Search_Room(int x, int y) {
  Trap_Ptr T;
  int I,J,Inc,Room,K;
  bool retval = false;
  Room_Type *rp;

  Room = World.Room_array[x][y];
  T = World.Traps;
  while (T) {
    if (Room == World.Room_array[T->Loc.x][T->Loc.y]) {
      Find_trap(T, false);
      retval = true;
    }
    T = T->Next;
  }
  if (Room < 0)
    Inc = 1;
  else
    Inc = 0;
  for (I = x - Inc; I <= x + Inc; ++I) {
    for (J = y - Inc; J <= y + Inc; ++J) {
      Room = World.Room_array[I][J];
      if (Room >= 0) {
	/* With World.Rooms[Room] */
	rp = &World.Rooms[Room];
	K = 0;
	while (K < Max_Doors) {
	  if (rp->Doors[K].Secret > 0) {
	    retval = true;
	    rp->Doors[K].Secret = 0;
	    World.S_World[rp->Doors[K].Abs_loc.x][rp->Doors[K].Abs_loc.y] = '+';
	    World.Seen[rp->Doors[K].Abs_loc.x][rp->Doors[K].Abs_loc.y] = true;
	  }
	  K++;
	}
      }
    }
  }
  Player_Appears();
  return retval;
} /* Search_Room */

void Blunder() {
  int Strange;

  switch (Die(14)) {
  case 1:
  case 2:
    Echo("A stream of butterflies shoots forth from the wand");
    break;

  case 3:
    Echo("There is a blinding flash of light...");
    Echo("You find yourself at dinner with the Cleavers...");
    sleep(2);
    Player.Faint_count = 0;
    Player.Last_meal = min(Player.Last_meal - 1000, -1000); /* #54, #71 */
    Echo("You feel normal again");
    break;

  case 4:
  case 5:
    for (Strange = 1; Strange <= Die(5); ++Strange) {
      switch (Die(3)) {
      case 1: Echo("You feel strange..."); break;
      case 2: Echo("You have a strange feeling for a moment..."); break;
      case 3: Echo("You feel somewhat disoriented..."); break;
      }
      switch (Die(3)) {
      case 1: Echo("You feel normal again"); break;
      case 2: Echo("You feel better now"); break;
      case 3: Echo("The feeling passes"); break;
      }
    }
    break;

  case 6:
    Echo("You look stupid now");
    break;

  case 7:
    Echo("You feel normal");
    Echo("The feeling passes...");
    break;

  case 8:
    Echo("You DIE, buckwheat!!");
    Echo("[Press space to continue, delete to stop] "); /* #66 */
    Echo("Haha...just kidding");
    break;

  case 9:
  case 10:
    Echo("Wow");
    break;

  case 11:
  case 12:
    Echo("Nothing happens");
    break;

  case 13:
  case 14:			/* #54 */
    Echo("Poof --- You are engulfed in a cloud of orange smoke");
    Echo("Coughing and gasping, you emerge from the smoke and find...");
    Echo("Ooops, wrong game, sorry!");
  }
} /* Blunder */

void Wonder(Obj_Ptr This_One, char Dir) {

  /* With This_One^ */

  This_One->Index = Die(Max_Wand) - 1;
  switch (This_One->Index) {
  case w_drain:
  case w_fire:
  case w_lightning:
  case w_cold:
  case w_poly:
  case w_tele_away:
  case w_missile:
  case w_striking:
  case w_slow:
  case w_haste:
  case w_paralyze:
    Hurl_obj(This_One, Dir);
    break;

  case w_light: Light(); break;
  case w_tele_to: Teleportation(); break;
  case w_cancel: Cancellation(); break;
  case w_alchemy: Alchemy(); break;
  case w_curing: Curing(); break;
  case w_search: Search_Room(Player.Loc.x, Player.Loc.y); break;
  default: Blunder();
  }
  This_One->Index = w_wonder;
} /* Wonder */

bool Zap_wand() {
  bool Worked;
  char Dir;
  Obj_Ptr This_one,Bogus_one;

  Worked = true;
  This_one = Choose_Item(Zap_A, Wand_T, false, false); /* #54 */
  if (This_one == NULL)
    return(false);

  if ((! Wand[This_one->Index].Id) ||
      (This_one->Index == w_drain ||
       This_one->Index == w_fire ||
       This_one->Index == w_lightning ||
       This_one->Index == w_cold ||
       This_one->Index == w_poly ||
       This_one->Index == w_tele_away ||
       This_one->Index == w_missile ||
       This_one->Index == w_striking ||
       This_one->Index == w_slow ||
       This_one->Index == w_haste ||
       This_one->Index == w_wonder ||
       This_one->Index == w_paralyze ||
       This_one->Index == w_blunder))
    Dir = Get_direction();
  else
    Dir = SPACE;
  Clear_Echo();			/* #71 */
  if (Dir == CHESC) {
    /* Clear_Echo(); #71 */
    Redisplay();
    return(false);		/* #59 */
  } else if (This_one->Plus_Hit == 0) {
    Empty_Echo = true;
    Echo("Nothing happens");
  } else {			/* Zapping */
    Empty_Echo = true;
    Bogus_one = (Obj_Ptr)malloc(sizeof(Obj_Typ));

    Bogus_one->Obj_Typ = This_one->Obj_Typ;
    Bogus_one->Loc = This_one->Loc;
    Bogus_one->Quan = This_one->Quan;
    Bogus_one->Index = This_one->Index;
    Bogus_one->Plus_Hit = This_one->Plus_Hit;
    Bogus_one->Plus_Dam = This_one->Plus_Dam;
    Bogus_one->Know_magic = This_one->Know_magic;
    Bogus_one->Cursed = This_one->Cursed;

    This_one->Plus_Hit--;
    switch (This_one->Index) {
    case w_drain:
    case w_fire:
    case w_lightning:
    case w_cold:
    case w_poly:
    case w_tele_away:
    case w_missile:
    case w_striking:
    case w_slow:
    case w_haste:
    case w_paralyze:
      Hurl_obj(This_one, Dir);
      break;

    case w_light: Light(); break; /* just like the scroll */
    case w_tele_to: Teleportation(); break;
    case w_nothing: Echo("Nothing happens"); break;
    case w_cancel: Cancellation(); break;
    case w_alchemy: Alchemy(); break;
    case w_wonder: Wonder(Bogus_one, Dir); break;
    case w_blunder: Blunder(); break;
    case w_curing: Curing(); break;

    case w_search:
      Worked = (Search_Room(Player.Loc.x, Player.Loc.y) ||
		Wand[This_one->Index].Id);
      break;

    default:
      if (logfp)
	fprintf(logfp, "Error - Non-existent wand type\n");
    }
    /* With Wand[Bogus_one->Index] Do */ /* If alchemized */

    if (! (Bogus_one->Index == w_tele_away ||
	   Bogus_one->Index == w_nothing ||
	   Bogus_one->Index == w_striking ||
	   Bogus_one->Index == w_cancel ||
	   Bogus_one->Index == w_wonder ||
	   Bogus_one->Index == w_blunder))
      Wand[Bogus_one->Index].Id = Worked;
    if ((! Wand[Bogus_one->Index].Id) &&
	(! Wand[Bogus_one->Index].Called) &&
	Switches.Ask_swi)
      Name_obj(This_one);

    free(Bogus_one);
  } /* Zapping */
  return(true);
} /* Zap_wand */

bool Kill_Player() {
  Hand_Type Hand;

  /* With Player */
  for (Hand = Left_H; Hand <= Right_H; Hand++) {
    if (Player.HP <= 0)
      if (Player.Cur_Ring[Hand])
	if ((Player.Cur_Ring[Hand]->Index == r_resur) &&
	    (Player.Cur_Ring[Hand]->Plus_Dam < Player.Cur_Ring[Hand]->Plus_Hit)) {
	  strcat(F, ".. Which should have killed you?!?");
	  Player.Cur_Ring[Hand]->Plus_Dam++;
	  Player.HP = Player.Max_HP;
	  Player.Died_count++;
	  Change_stats |= S_Bottom;
	}
  }
  if (Player.HP <= 0) {
    switch (Die(4)) {
    case 1: strcat(F, "... you are dead!!!"); break;
    case 2: strcat(F, "... and you die!!!"); break;
    case 3: strcat(F, "... and you croak!!!"); break;
    case 4: strcat(F, "... you bite the dust!!!"); break; /* #71 */
    }
    Dead = true;
    return(true);
  }
  return false;
} /* Kill_Player */

bool Trap_at(int X, int Y) {
  Trap_Ptr T;

  T = World.Traps;
  while (T)
    if (T->Loc.x == X && T->Loc.y == Y)
      return(true);
    else
      T = T->Next;
  return(false);
} /* Trap_at */

/* Trap_arrow was internal to Step_on_trap() */
void Trap_arrow() {
  if (Die(10) == 1)
    Echo("An arrow shoots over your shoulder, falls, and breaks");
  else {
    Echo_Init();
    strcat(F, "You are hit by an arrow!");
    Player.HP -= Die(6);
    if (Kill_Player())
      Killer = ')';
    else
      Change_stats |= S_Bottom;
    Echo(Echo_Str);
  }
} /* Trap_arrow */

/* Trap_dart was internal to Step_on_trap() */
void Trap_dart() {
  if (Die(10) == 1)
    Echo("A dart whizzes past your ear");
  else {
    Echo("You feel a dart hit the back of your neck!");
    if (! Has_on_ring(r_sustain))
      Player.ST--;
    Change_stats |= S_Top;
  }
} /* Trap_dart */

/* Trap_trapdoor was internal to Step_on_trap() */
void Trap_trapdoor() {
  Echo("You fell in a trap!");
  Down_a_level();
} /* Trap_trapdoor */

/* Trap_beartrap was internal to Step_on_trap() */
void Trap_beartrap() {
  Echo("You are caught in a beartrap");
  Player.Trapped_count += 4 + Die(3);
} /* Trap_beartrap */

void Step_on_trap(int X, int Y) {
  Trap_Ptr t;
  bool found;

  t = World.Traps;
  found = false;
  while (t) {
    if (t->Loc.x == X && t->Loc.y == Y) {
      found = true;
      break;
    } else
      t = t->Next;
  }
  if (! found) {
    if (logfp)
      fprintf(logfp, "Error - NULL trap in Step_on_trap\n");
  } else {
    if (t->Chance > 0)
      Find_trap(t, false);
    Valid_Command = false;
    /* Flush TYPE ahead IF needed */
    if (Switches.Flush_swi)
      flushinp();
    switch (t->Kind) {
    case t_arrow: Trap_arrow(); break;
    case t_bear: Trap_beartrap(); break;
    case t_door: Trap_trapdoor(); break;
    case t_dart: Trap_dart(); break;
    case t_teleport: Teleportation(); break;
    default:
      if (logfp)
	fprintf(logfp, "Error - Nonexistent trap type\n");
    }
  }
} /* Step_on_trap */

bool Search(int X, int Y) {
  Trap_Ptr T;
  int i,j,room,k;
  bool found, retval;
  Room_Type *rp;
  Door_Type *dp;

  retval = false;		/* #71 */
  T = World.Traps;
  while (T) {
    if ((abs(T->Loc.x - X) <= 1) && (abs(T->Loc.y - Y) <= 1) &&
	(Die(100) <= T->Chance)) {
      Find_trap(T, true);
      retval = true;		/* #71 */
    }
    T = T->Next;
  }
  for (i = X - 1; i <= X + 1; ++i)
    for (j = Y - 1; j <= Y + 1; ++j) {
      room = World.Room_array[i][j];
      if (room >= 0) {
	rp = &World.Rooms[room];
	k = Door_Up;		/* #71 */
	found = false;
	while (k < Max_Doors) {
	  dp = &rp->Doors[k];
	  if (dp->Abs_loc.x == i && dp->Abs_loc.y == j) {
	    found = true;
	    break;
	  }
	  k++;
	}
	if (found)
	  if (dp->Secret > 0 && Die(100) > dp->Secret) {
	    dp->Secret = 0;
	    World.S_World[dp->Abs_loc.x][dp->Abs_loc.y] = '+';
	    World.Seen[dp->Abs_loc.x][dp->Abs_loc.y] = true;
	    retval = true;	/* #71 */
	  }
      }
    }
  Player_Appears();
  return (retval);		/* #71 */
} /* Search */

/* #71 this was a macro routine */
void Rdinit() {
  FILE *initfp;
  Long_string line;
  bool val;
  char *tok;

  initfp = fopen(".rogue.init", "r");
  if (initfp == NULL)
    return;

  while (fgets(line, LONG_LEN, initfp) != NULL) {
    line[LONG_LEN - 1] = '\0';
    tok = strtok(line, " \n");
    if (tok == NULL)
      continue;
    if (*tok == '#')
      continue;
    else if (! strcasecmp(tok, "name")) {
      tok = strtok(NULL, "\n");
      if (tok)
	strncpy(Player.Name, tok, Name_Len - 1);
    } else if (! strcasecmp(tok, "fruit")) {
      tok = strtok(NULL, "\n");
      if (tok)
	strncpy(Fruit_name, tok, Name_Len - 1);
    } else if (! strcasecmp(tok, "save")) {
      tok = strtok(NULL, "\n");
      strncpy(Save_file, tok, Name_Len - 1);
    } else {
      val = true;
      if (! strcasecmp(tok, "no")) {
	val = false;
	tok = strtok(NULL, " \n");
      }
      if (! strcasecmp(tok, "terse"))
	Switches.Terse_swi = val;
      else if (! strcasecmp(tok, "flush"))
	Switches.Flush_swi = val;
      else if (! strcasecmp(tok, "ask"))
	Switches.Ask_swi = val;
      else if (! strcasecmp(tok, "slow"))
	Switches.Slow_swi = val;
      else if (! strcasecmp(tok, "turn"))
	Switches.Turn_swi = val;
      else if (! strcasecmp(tok, "jump"))
	Switches.Jump_swi = val;
      else if (! strcasecmp(tok, "tomb"))
	Switches.Tomb_swi = val;
    }
  }

  fclose(initfp);
}

/* #71 this was a macro routine */
bool SaveInit() {
  FILE *initfp;
  time_t now;

  initfp = fopen(".rogue.init", "w");
  if (initfp == NULL)
    return false;

  now = time(NULL);
  fprintf(initfp, "# .rogue.init - created by ECL Rogue on %s\n", ctime(&now));
  fprintf(initfp, "name %s\n", Player.Name);
  fprintf(initfp, "fruit %s\n", Fruit_name);
  fprintf(initfp, "%sterse\n", (Switches.Terse_swi ? "" : "no "));
  fprintf(initfp, "%sflush\n", (Switches.Flush_swi ? "" : "no "));
  fprintf(initfp, "%sask\n", (Switches.Ask_swi ? "" : "no "));
  fprintf(initfp, "%sslow\n", (Switches.Slow_swi ? "" : "no "));
  fprintf(initfp, "%sturn\n", (Switches.Turn_swi ? "" : "no "));
  fprintf(initfp, "%sjump\n", (Switches.Jump_swi ? "" : "no "));
  fprintf(initfp, "%stomb\n", (Switches.Tomb_swi ? "" : "no "));

  fclose(initfp);
  return true;
}

/* #53,#63 much stuff following */
/* Get_resp was internal to Set_options() */
char Get_resp() {
  char Ch;

  while (1) {
    Ch = tolower(Comand());
    if (Ch == 't' || Ch == 'f' || Ch == CHESC || Ch == SPACE ||
	Ch == CHLFD || Ch == CHEOL)
      return Ch;
    if (Ch == 'y')		/* #71 allow yes/no */
      return 't';
    if (Ch == 'n')
      return 'f';
    beep();
  }
  /* return CHESC; */			/* #71 cannot happen */
}

/* #71 rewritten for slightly different user model */
/* TF_Option was internal to Set_options() */
bool TF_Option(bool *Swit, char *S) {

  int Line = TextLine;

  AddText(S);
  addch(' ');
  addstr(*Swit ? "true " : "false");
  move(Line, strlen(S) + 1);
  refresh();
  switch (Get_resp()) {
  case 't':
    *Swit = true;
    break;
  case 'f':
    *Swit = false;
    break;
  case CHESC:
    return false;
  }
  move(Line, strlen(S) + 1);
  addstr(*Swit ? "true " : "false");
  refresh();

  return true;
} /* TF_Option */

void Set_options() {
  Name_string New1,New2;
  int Nm_Len,Pos;

  StartText();
  AddText(" -- ECL Rogue options --");	/* #71 */
  AddText("");

  if (! (TF_Option(&Switches.Terse_swi, "Terse output:") &&
	 TF_Option(&Switches.Flush_swi, "Flush typeahead during battle:") &&
	 TF_Option(&Switches.Jump_swi, "Show position only at end of run:") &&
	 TF_Option(&Switches.Slow_swi, "Do inventories slowly:") &&
	 TF_Option(&Switches.Turn_swi, "Turn corners in fast move:") &&
	 TF_Option(&Switches.Ask_swi, "Ask me about unidentified things:") &&
	 TF_Option(&Switches.Tomb_swi, "Display tombstone when dead:"))) {
    Restore_screen();
    return;
  }

  strcpy(New2, Player.Name);
  Pos = TextLine;
  while (1) {
    TextLine = Pos;
    AddText("Name: ");
    addstr(New2);
    move(Pos, 6);
    refresh();

    if (Get_Line(New2, &Nm_Len)) {
      if (Nm_Len <= 0)
	break;
      if (Name_check(New2)) {
	strcpy(Player.Name, New2);
	break;
      }
      move(0,0);
      addstr("Your name is already in use.  Please choose another");
      clrtoeol();
      Wait_For_Space(true);
      move(0,0);
      clrtoeol();
    } else {
      Restore_screen();
      return;
    }
  }
  move(Pos, 6);			/* #71 */
  addstr(Player.Name);

  Pos = TextLine;
  AddText("Fruit: ");
  addstr(Fruit_name);
  move(Pos, 7);
  refresh();
  if (Get_Line(New1, &Nm_Len)) { /* #54 */
    if (Nm_Len > 0)
      strcpy(Fruit_name, New1);
  } else {
    Restore_screen();
    return;
  }
  move(Pos, 7);			/* #71 */
  addstr(Fruit_name);

  /* #71 prompt to create init file */
  AddText("");
  Pos = TextLine;
  AddText("Create init file? ");
  refresh();

  if (Get_resp() != 't') {
    Restore_screen();
    return;
  }
  addstr("yes");
  refresh();

  if (!SaveInit()) {
    move(0,0);
    addstr("?ROGUE: Error creating init file");
    clrtoeol();
    if (logfp)
      fprintf(logfp, "Error writing init file: %s\n",
	      strerror(errno));
  }

  Wait_For_Space(true);

#if 0
   strcpy(New1, Save_file);	/* save original */
   Line = Line + 1;
   Pos = Line;
   Repeat {
     DCA(1,Pos);
     Cll;
     Save_File = New1;
     Write(tty,'Save file: ',Save_File);
     DCA(12,Pos);
     More = true;
     If Get_Line(New2,Nm_Len)
       {
	 If Nm_Len > 0
	   Save_file = New2;
	 Name_Ok = Chk_File(Save_File);
	 If Not Name_Ok
	   {
	     Line = Pos + 1;
	     Writeln(tty);
	     Cll;
	     Write(tty,'Invalid file name, try again');
	   }
       }
     Else
       Name_Ok = true;
     DCA(12,Pos);
     Write(tty,Save_File);
   } Until Name_Ok;

   More = Wait_For_Space(true);
   For J = Redisp_y_orig to Line {
     DCA(1,J);
     Cll;
     Scr_Text(J,Spaces);
   }
   Redisplay;
   For J = Redisp_y_orig to Line
     World.Lines[J] = true;
   Update_Screen;	/* #63 */
#endif
  Restore_screen();		/* #71 */
} /* Set_Options */

bool Throw() {
  Obj_Ptr This_one;
  char Ch,Dir;
  bool retval;
  Weapons *wp;

  retval = false;

  This_one = Choose_Item(Throw_A, Weapon_T, true, true); /* #54 */
  if (This_one == NULL)
    return false;

  if (This_one == Player.Cur_Wep)
    if (This_one->Cursed) {
      Give_cursed_message();
      Insert(&Player.Obj_List, This_one);
      return(false);
    }

  Dir = Get_direction();
  Empty_Echo = true;
  if (Dir == CHESC) {
    Insert(&Player.Obj_List, This_one);
    Clear_Echo();
    Redisplay();
    return(false);
  }

  if (Weapon_is_ammo(This_one->Index)) {
    if (Player.Cur_Wep == NULL ||
	Player.Cur_Wep->Index != - Weapon[This_one->Index].L_Num) {
      Echo_Init();
      /* With Weapon[This_one->Index] */
      wp = &Weapon[This_one->Index];
      /* #71  put it down first, before telling the luser to wield */
      Place_Next_To(Player.Loc, &This_one->Loc, true);
      Put_on_floor(This_one, This_one->Loc.x, This_one->Loc.y);
      strcat(F, "You must wield a ");
      strcat(F, Weapon[-wp->L_Num].Name); /* #71 no len */
      strcat(F, " to effectively use your ");
      strcat(F, wp->Name);	/* #71 no len */
      Echo(Echo_Str);
      return(false);
    }
  } else if (This_one->Index != wp_dagger) {
    Echo_Init();
    if (Switches.Terse_swi)
      strcat(F, "Really throw your ");
    else
      strcat(F, "Are you SURE you want to throw your ");
    /* With Weapon[This_one->Index] */
    wp = &Weapon[This_one->Index];
    strcat(F, wp->Name);	/* #71 no len */
    strcat(F, "?");
    Echo(Echo_Str);
    Move_To_Echo();
    do {
      Ch = tolower(Comand());
    } while (Ch != 'y' && Ch != 'n' && Ch != CHESC);
    if (Ch != 'y') {
      Insert(&Player.Obj_List, This_one);
      Clear_Echo();
      Redisplay();
      return(false);
    }
  }
  if (This_one == Player.Cur_Wep)
    Player.Cur_Wep = NULL;
  Hurl_obj(This_one, Dir);
  return true;
} /* Throw */

bool Trap_Identify() {
  int deltax,deltay;
  Loc_Type worker;
  char Dir;
  Trap_Ptr t;
  bool found;

  Dir = Get_direction();
  Empty_Echo = true;
  if (Dir == CHESC) {
    Clear_Echo();
    Redisplay();
    return(false);
  } else if (Player.Blind_count)
    Echo("You can\'t see any traps to identify");
  else {
    Translate_Direction(Dir, &deltax, &deltay);
    worker = Player.Loc;
    do {
      worker.x += deltax;
      worker.y += deltay;
    } while (!(World.S_World[worker.x][worker.y] == '|' ||
	       World.S_World[worker.x][worker.y] == '-' ||
	       World.S_World[worker.x][worker.y] == '+' ||
	       World.S_World[worker.x][worker.y] == ' ' ||
	       World.S_World[worker.x][worker.y] == '^'));
    t = World.Traps;
    found = false;
    while (t)
      if (t->Loc.x == worker.x && t->Loc.y == worker.y) {
	found = true;
	break;
      } else
	t = t->Next;
    if (!found)
      Echo("There\'s no trap over there");
    else {
      Echo_Init();
      strcat(F, "That trap is a");
      switch (t->Kind) {
      case t_arrow: strcat(F, "n arrow trap"); break;
      case t_bear: strcat(F, " beartrap"); break;
      case t_door: strcat(F, " trapdoor"); break;
      case t_dart: strcat(F, " dart trap"); break;
      case t_teleport: strcat(F, " teleport trap"); break;
      default:
	if (logfp)
	  fprintf(logfp, "Error - Non existent trap type in Trap_Identify!\n");
      } /* case t->kind */
      Echo(Echo_Str);
      return true;
    }
  }
  return false;
} /* Trap_Identify */

Mon_Ptr Find_Mon(Mon_Ptr Q, int X, int Y) {
  Mon_Ptr L;

  L = Q;
  while (L) {
    if (L->Loc.x == X && L->Loc.y == Y) {
      return(L);
    } else
      L = L->Next;
  }
  return NULL;
} /* Find_Mon */

void Del_Mon(Mon_Ptr *M) {
  Mon_Ptr P,Q;

  /* Rid us of the character for the monster */
  World.Num_mons--;
  World.Mon[(*M)->Loc.x][(*M)->Loc.y] = EMPTY;
  /* If we have been eaten Then assume we could only kill that damn worm. */
  if (Player_Disgorged()) {
    World.Mon[(*M)->Loc.x][(*M)->Loc.y] = '@';
    Player_Appears();
  }

  /* Now de-link the stupid monster */
  Q = NULL;
  P = World.Monsters;
  while (P && (P != *M)) {
    Q = P;
    P = P->Next;
  }
  if (P == NULL) {
    if (logfp)
      fprintf(logfp, " Arghhh! Delete: Monster not found!\n");
    free(*M);			/* #69 ought to Get rid of it anyway */
  } else if (Q) {
    Q->Next = P->Next;
    free(P);			/* #69 Get rid of the one we know */
  } else {
    World.Monsters = P->Next;
    free(P);			/* #69 as above */
  }
  *M = NULL;			/* #70 */
} /* Del_Mon */

/* Break_Stomach was internal to Attack() */
/* This procedure is used If you polymorph the purple worm that ate you. */
bool Break_Stomach(Mon_Ptr *M) {
  Player.HP -= (*M)->HP / 4;
  if (Player.HP <= 0) {
    Echo_Init();
    strcat(F, "You are smashed by the shrinking monster...");
    if (Kill_Player()) {
      Killer = Monster[(*M)->Index].Name;
      return false;
    }
  } else {
    Echo("You are hurt bad by the shrinking stomach of the monster");
    Echo("But it is killed by your great bulk!!");
    Player.XP += Monster[(*M)->Index].Xpval;
    Del_Mon(M);
    Change_stats |= S_Bottom;
    Check_Player_Level();
  }
  return true;
}

int Polymorph(Mon_Ptr *NewMon) {
  Mon_Ptr M = *NewMon;
  int oldIndex, I;

  oldIndex = M->Index;
  if (oldIndex == m_fungi || oldIndex == m_mimic)
    Player.Stuck = false;
  do {
    I = Die(Max_Monster) - 1;
  } while (I == m_juiblex ||
	   I == m_mimic ||
	   I == m_nymph ||
	   I == m_gith ||
	   I == m_lep ||
	   I == oldIndex || 	/* #71 */
	   Monster[I].Min_Level == INT_MAX);
  M->HP = (M->HP * Monster[I].Hit_Dice) / Monster[oldIndex].Hit_Dice;
  M->Index = I;
  World.Mon[M->Loc.x][M->Loc.y] = Monster[M->Index].Name;

  if (oldIndex == m_purple && Player.Eaten_count > 0) {
    if (!Break_Stomach(NewMon))
      return -3;		/* attack is false, but miss */
  }
  return -1;			/* attack is false */
}

/* Wand_Attack was internal to Attack() */
int Wand_Attack(Obj_Ptr Enforcer, Mon_Ptr M) {
  int T, I;

  T = 0;
  if (Die(20) == 1) {
    T = -1;
    Echo_Init();
    strcat(F, "The ");
    if (Wand[Enforcer->Index].Is_wand)
      strcat(F, "wand ");
    else
      strcat(F, "staff ");
    if (Switches.Terse_swi)
      strcat(F, "sputters");
    else
      strcat(F, "glows faintly and sputters");
    Echo(Echo_Str);
  } else			/* #46 */
    switch (Enforcer->Index) {
    case w_drain: T = M->HP * 2; break; /* #63 */
    case w_fire:
    case w_cold:
    case w_lightning:
    case w_striking:
    case w_missile:
      for (I = 1; I <= Wand[Enforcer->Index].Num; ++I)
	T += Die(Wand[Enforcer->Index].Dam);
      break;
    case w_poly:
      /* With M^ */
      T = Polymorph(&M);
      break;

    case w_tele_away:
      T = -1;
      /* With M->Loc */
      World.Mon[M->Loc.x][M->Loc.y] = EMPTY;
      World.Seeable[M->Loc.x][M->Loc.y] = false;
      Player_Appears();
      Pick_A_Place(&M->Loc.x, &M->Loc.y);
      World.Mon[M->Loc.x][M->Loc.y] = Monster[M->Index].Name;
      if (Player.SeeMon_count > 0)
	World.Seeable[M->Loc.x][M->Loc.y] = true;
      if (M->Index == m_fungi ||
	  M->Index == m_mimic)
	Player.Stuck = false;
      if (Player_Disgorged()) { /* this too */
	Player.Prev = Player.Loc;
	Player.Loc = M->Loc;
	Player_Disappears();
	World.Seeable[Player.Loc.x][Player.Loc.y] = true;
      }
      Update_Screen();
      break;

    case w_slow:
      T = -1;
      if (M->Speed < 3) {
	M->Speed = 1;
	if (M->Speed_count == 0)
	  M->Speed_count = -1;
	else
	  M->Speed_count = -(M->Speed_count);
      }
      else
	M->Speed_count = 1;
      break;

    case w_haste:
      T = -1;
      if (M->Speed > 1) {
	M->Speed = 3;
	if (M->Speed_count == 0)
	  M->Speed_count = -1;
	else
	  M->Speed_count = -(M->Speed_count);
      } else
	M->Speed_count = 1;
      break;

    case w_paralyze:
      if (M->Index == m_zombie)
	T = -2;			/* missed */
      else {
	M->Paralyzed_count += Die(10) + 5;
	T = -1;
      }
      break;

    default:
      if (logfp)
	fprintf(logfp, "Error in parameter to Wand_Attack -- illegal wand\n");
    }

  return T;
}

/* Dead_Mon_Treasure was internal to Attack() */
void Dead_Mon_Treasure(Mon_Ptr M) {
  Obj_Ptr Nw;
  Loc_Type Other;
  bool Fini = false;

  Place_Next_To(M->Loc, &Other, true);
  switch (M->Index) {
  case m_lep:
    Nw = (Obj_Ptr)malloc(sizeof(Obj_Typ));
    Nw->Obj_Typ = Gold_T;
    Nw->Loc = Other;
    Nw->Quan = Die(250) + 50;
    if (Die(5) == 1)
      Nw->Quan += Die(300);
    Nw->Index = 0;
    Place_Obj(Nw);
    break;

  case m_int:
  case m_nymph:
  case m_troll:
    if (M->Index == m_nymph || Die(2) == 1)
      do {
	Fini = false;
	Gen_Obj(World.Level, &Nw);
	if (Nw->Obj_Typ == Gold_T ||
	    Nw->Obj_Typ == Food_T)
	  free(Nw);
	else {
	  Fini = true;
	  Nw->Loc = Other;
	  Place_Obj(Nw);
	}
      } while (! Fini);
    break;

  case m_death:
    Nw = (Obj_Ptr)malloc(sizeof(Obj_Typ));
    Nw->Obj_Typ = Weapon_T;
    Nw->Loc = Other;
    Nw->Plus_Hit = Die(3) + 2;
    Nw->Plus_Dam = Die(3) + 2; /* 2 Handed Sword */
    Nw->Cursed = false;
    Nw->Know_magic = false;
    Nw->Index = wp_two_sword;
    Nw->Quan = 1;
    Place_Obj(Nw);
    break;

  case m_gith:
    Nw = (Obj_Ptr)malloc(sizeof(Obj_Typ));
    Nw->Obj_Typ = Weapon_T;
    Nw->Loc = Other;
    Nw->Plus_Hit = Die(3) + 1;
    Nw->Plus_Dam = Die(3) + 1;	/* Silver Sword */
    Nw->Cursed = false;
    Nw->Know_magic = false;
    Nw->Index = wp_sil_sword;
    Nw->Quan = 1;
    Place_Obj(Nw);
    Monster[m_gith].Min_Level = INT_MAX; /* No more Githyankis */
  } /* Case M->Index */
}

/* Defenses was internal to Attack() */
/* procedure to handle monster special defenses */
void Defenses(Obj_Ptr Enforcer, Mon_Ptr M, int *T) {

  /* With Enforcer^ */
  switch (M->Index) {
  case m_quasit:
    if (Enforcer->Obj_Typ == Wand_T &&
	(Enforcer->Index == w_fire ||
	 Enforcer->Index == w_lightning ||
	 Enforcer->Index == w_cold))
      *T = 0;
    else if (Enforcer->Obj_Typ == Weapon_T)
      if (Enforcer->Index == wp_rocks ||
	  Enforcer->Index == wp_sil_sword ||
	  Enforcer->Index == wp_sil_arrows)
	if (Enforcer->Plus_Hit + Enforcer->Plus_Dam <= 0)
	  *T = 0;
    break;

  case m_snake:
    if (Enforcer->Obj_Typ == Wand_T && Enforcer->Index == w_cold)
      *T = 0;
    break;

  case m_troll:
    if (Enforcer->Obj_Typ == Wand_T && Enforcer->Index == w_fire)
      *T += *T / 2;
    break;

  case m_vampire:
    if (Enforcer->Obj_Typ == Weapon_T)
      if (Enforcer->Plus_Hit + Enforcer->Plus_Dam <= 0)
	*T = 0; /* must be magical weapon */
    break;

  case m_wraith:
    if (Enforcer->Obj_Typ == Weapon_T)
      if (Enforcer->Plus_Hit + Enforcer->Plus_Dam <= 0) { /* Not magic */
	if (Enforcer->Index == wp_sil_sword ||
	    Enforcer->Index == wp_sil_arrows)
	  *T /= 2;
	else
	  *T = 0;		/* is Not silver */
      }
    break;

  case m_xorn:
    if (Enforcer->Obj_Typ == Wand_T)
      switch (Enforcer->Index) {
      case w_fire:
      case w_cold:
	*T = 0;
	break;

      case w_lightning:
	if (Die(10) < 3)
	  *T = 0;
	else
	  *T /= 2;
      }
    break;

  case m_yeti:
    if (Enforcer->Obj_Typ == Wand_T)
      switch (Enforcer->Index) {
      case w_fire: *T += *T / 2; break;
      case w_cold: *T = 0;
      }
    break;

  case m_zombie:
    if (Enforcer->Obj_Typ == Wand_T && Enforcer->Index == w_cold)
      *T = 0;
    break;

  case m_death:
    if ((Enforcer->Obj_Typ == Wand_T || Enforcer->Obj_Typ == Weapon_T) &&
	(Enforcer->Plus_Hit + Enforcer->Plus_Dam > 0))
      *T /= (5 - Die(4));
    break;

  case m_int:
    if (Enforcer->Obj_Typ == Weapon_T &&
	Enforcer->Plus_Hit + Enforcer->Plus_Dam < 2)
      *T = 0;
    break;

  case m_juiblex:
    if (Enforcer->Obj_Typ == Weapon_T &&
	(Enforcer->Index == wp_sil_sword ||
	 Enforcer->Index == wp_sil_arrows))
      *T = 0;	    /* Everybody knows silver doesn''t hurt demons! */
    break;

  case m_phantom:
    if (Enforcer->Obj_Typ == Wand_T)
      switch (Enforcer->Index) {
      case w_fire:
	*T = 0;
	M->HP++;
	break;
      case w_cold:
	*T += 2;
      }
    break;

  case m_sand:
    if (((Enforcer->Obj_Typ == Weapon_T) && /* throw or missile weapons */
	 ((Player.Cur_Wep == NULL) ||
	  Weapon_is_ammo(Enforcer->Index))) ||
	((Enforcer->Obj_Typ == Wand_T) && (Enforcer->Index == w_striking)))
      *T = 0;
    break;

  case m_umpleby:
    if (Enforcer->Obj_Typ == Wand_T && Enforcer->Index == w_lightning)
      *T = 0;
    break;

  case m_werewolf:
    if ((Enforcer->Obj_Typ == Weapon_T) &&
	(!(Enforcer->Index == wp_sil_sword ||
	   Enforcer->Index == wp_sil_arrows)))
      *T = 0;
    break;

  case m_zallige:
    if ((Enforcer->Obj_Typ == Wand_T) && (Enforcer->Index == w_drain))
      *T = 0;			/* hahahaha!  Cannot Drain Life!!! */

  }
} /* Defenses */

/* Player_Max_Hit was internal to Attack() */
int Player_Max_Hit(Obj_Ptr Weap, Mon_Ptr M) {
  int Pl_Max;
  Hand_Type Hand;

  Pl_Max = 0;
  if (Weap->Obj_Typ == Wand_T) {
    Pl_Max = Wand[Weap->Index].Num * Wand[Weap->Index].Dam;
    if (Weap->Index == w_drain)
      Pl_Max = M->HP;
  } else {
    if (Monster[M->Index].Large)
      Pl_Max = max(Weapon[Weap->Index].L_Num, 1) * Weapon[Weap->Index].L_Dam;
    else
      Pl_Max = max(Weapon[Weap->Index].S_Num, 1) * Weapon[Weap->Index].S_Dam;
    if (Weapon_is_ammo(Weap->Index))
      Pl_Max += Player.Cur_Wep->Plus_Dam;
    else if (Player.ST > 14)
      Pl_Max += (Player.ST - 14);
    else if (Player.ST < 7)
      Pl_Max += (Player.ST - 7);
    Pl_Max = max(Pl_Max,1);
  }
  for (Hand = Left_H; Hand <= Right_H; Hand++)
    if (Player.Cur_Ring[Hand] && Player.Cur_Ring[Hand]->Index == r_incr_dam)
      Pl_Max = max(1, Pl_Max + Player.Cur_Ring[Hand]->Plus_Hit);
  return Pl_Max;
} /* Player_Max_Hit */

/* M_Ouch_MSG was internal to Attack() */
void M_Ouch_MSG(char *F, Mon_Ptr M, int T, Obj_Ptr Weap) {

  Long_string It;		/* Gag me. */
  int New_Hp, Ratio, M_Half,M_Qtr, M_Max;
  bool Thrown;
  Ratio = (T * 10) / Player_Max_Hit(Weap, M);
  New_Hp = M->HP - T;
  if (Weap != Player.Cur_Wep)
    Thrown = true;
  else
    Thrown = false;
  if (Switches.Terse_swi)
    strcpy(It, "it");
  else {
    strcpy(It, "the ");
    strcat(It, Monster[M->Index].Long_Name);
  }
  if (New_Hp <= 0) {		/* It dies */
    if (Player.Blind_count > 0) { /* #54 */
      switch (Die(14)) {	/* #54 */
      case 1:
      case 2:
      case 3: strcat(F, "You kill it!!"); break;
      case 4:
      case 5:
      case 6: strcat(F, "It is vanquished!!"); break;
      case 7:
      case 8:
      case 9: strcat(F, "It is defeated!!"); break;
      case 10: strcat(F, "The bugger dies!!"); break;
      case 11:
      case 12: strcat(F, "It bites the dust!!"); break;
      case 13:
      case 14: strcat(F, "It croaks!!"); break;
      }
    }
    else
      switch (Die(18)) {	/* #54 */
      case 1: sprintf(F, "You have vanquished %s!!", It); break;
      case 2: sprintf(F, "%s has gone to meet its maker!!", It); break;
      case 3: sprintf(F, "%s will draw breath no more!!", It); break;
      case 4: sprintf(F, "You deal %s a death blow!!", It); break;
      case 5: sprintf(F, "You splatter %s!!!", It); break;
      case 6: sprintf(F, "%s screams in agony and is no more!!", It); break;
      case 7: sprintf(F, "You have killed %s!!", It); break;
      case 8: sprintf(F, "Okay, you killed %s.  Wow.", It); break;
      case 9: sprintf(F, "%s is dead!!", It); break;
      case 10:
	if (Switches.Terse_swi)
	  strcat(F, "Another one bites the dust!!");
	else
	  sprintf(F, "Another %s bites the dust!!",
		  Monster[M->Index].Long_Name);
	break;
      case 11: sprintf(F, "%s is launched into eternity...", It); break;
      case 12: sprintf(F, "%s cashes in its chips!", It); break;
      case 13: sprintf(F, "You have slain %s!!", It); break;
      case 14: sprintf(F, "%s collapses in a pool of its own gore!", It); break;
      case 15: sprintf(F, "And you thought %s smelled bad on the outside!!", It); break;
      case 16: sprintf(F,"%s curses you and expires!", It); break;
      case 17: sprintf(F, "Splat!  Now you smell as bad as %s did!", It); break;
      case 18: sprintf(F, "%s disappears in a cloud of greasy black smoke!!", It); break;
      }
    /* It dies */
  } else { /* You hurt it */
    if (Player.Blind_count > 0)
      strcat(F, "You hit it");
    else if (Weap->Obj_Typ == Wand_T)
      switch (Ratio) {
      case 0:
      case 1:
      case 2: sprintf(F, "The blast strikes %s glancingly", It); break;
      case 3:
      case 4:
      case 5:
      case 6: sprintf(F, "You zap %s good", It); break;
      default: sprintf(F, "The blast maims %s terribly", It);
      }
    else
      switch (Ratio) {
      case 0:
      case 1: sprintf(F, "You scratched %s", It); break;
      case 2: sprintf(F, "You nicked %s", It); break;
      case 3: sprintf(F, "You struck %s a glancing blow", It); break;
      case 4:
      case 5:
      case 6: sprintf(F, "You strike %s a telling blow", It); break;
      case 8: sprintf(F, "You really hit %s good", It); break;
      case 7:
	if (Thrown)
	  sprintf(F, "You catch %s upside the head", It);
	else
	  sprintf(F, "You slap %s upside the head", It);
	break;
      case 9: sprintf(F, "You score an excellent hit on %s",It); break;
      case 10: sprintf(F, "You whang on %s", It); break;
      default:
	if (Thrown)
	  sprintf(F, "Your %s imbeds itself deep within %s",
		  Weapon[Weap->Index].Name, It);
	else
	  sprintf(F, "You smash %s", It);
      } /* Case Ratio */
    M_Max = Monster[M->Index].Hit_Dice * 8;
    M_Half = M_Max / 2;
    M_Qtr = M_Max / 4;
    if (! Switches.Terse_swi) {
      if (M->HP > M_Half) {
	if (New_Hp <= M_Qtr)
	  switch (Die(2)) {
	  case 1: strcat(F, "; it wails in anguish!"); break;
	  case 2:
	    if (Player.Blind_count > 0)
	      strcat(F, "; it grunts");
	    else
	      strcat(F, "; it looks pained");
	    break;
	  }
	else if (New_Hp <= M_Half)
	  switch (Die(3)) {
	  case 1: strcat(F, " which slows it"); break;
	  case 2: strcat(F, "; it\'s not happy"); break;
	  case 3:
	    if (! Thrown)
	      strcat(F, "; it fights harder");
	    else
	      strcat(F, "; it hesitates briefly");
	    break;
	  }
	else if (Die(5) == 1)
	  switch (Die(3)) {
	  case 1: strcat(F, "; it laughs!"); break;
	  case 2: strcat(F, "; it snarls..."); break;
	  case 3: strcat(F, " which only annoys it"); break;
	  }
      } else if (M->HP > M_Qtr)
	if (New_Hp <= M_Qtr)
	  switch (Die(3)) {
	  case 1 : strcat(F, "; it\'s hurting bad"); break;
	  case 2:
	    if (Player.Blind_count > 0)
	      strcat(F, "; it\'s getting desperate");
	    else
	      strcat(F, "; it looks desperate");
	    break;
	  case 3: strcat(F, "; what a mess!"); break;
	  }
    }
  } /* You hurt it */
} /* M_Ouch_MSG */

/* Check_Vampiric was internal to Attack() */
void Check_Vampiric(Obj_Ptr Enforcer, int T) {
  int How_Many;
  Hand_Type Hand;

  How_Many = T;
  if (Enforcer->Obj_Typ == Weapon_T && T > 0) {
    /* With Player */
    for (Hand = Left_H; Hand <= Right_H; ++Hand)
      if (Player.Cur_Ring[Hand])
	if (Player.Cur_Ring[Hand]->Index == r_vampiric)
	  if (Player.HP < Player.Max_HP) {
	    Change_stats |= S_Bottom;
	    Player.HP = min(Player.HP + (T + T % 2) / 2, Player.Max_HP);
	  }
  }
} /* Check_Vampiric */

bool Attack(int X, int Y, Obj_Ptr Enforcer) {
  Mon_Ptr M;
  int T,I,Hit_adj;
  Hand_Type Hand;
  char Ch;
  bool retval = false;

  T = 0;
  M = Find_Mon(World.Monsters, X, Y);
  if (Enforcer == NULL) {
    if (Switches.Terse_swi)
      Echo("You have no weapon");
    else
      Echo("You\'re not wielding any weapon!");

    if (Switches.Flush_swi)
      flushinp();
    return false;
  }

  if (M == NULL) {
    if (Switches.Terse_swi)
      Echo("It was an illusion!");
    else
      Echo("As you attack, the illusion shimmers, then fades away");
    World.Mon[X][Y] = EMPTY;

    if (Switches.Flush_swi)
      flushinp();
    return false;
  }

  if (Enforcer->Obj_Typ == Wand_T)
    T = Wand_Attack(Enforcer,M);
  else if (Enforcer->Index == wp_sling ||
	   Enforcer->Index == wp_crossbow ||
	   Enforcer->Index == wp_bow) {
    if (Enforcer == Player.Cur_Wep) {
      T = -1;			/* -1 means missed+no message */
      Echo_Init();
      /* With Weapon[Enforcer->Index] */
      sprintf(F, "Your %s does not make an effective hand-held weapon",
	      Weapon[Enforcer->Index].Name);
      Echo(Echo_Str);
    } else			/* we threw a bow-like weapon */
      T = -3;			/* Make attack false, but miss */
  }
  if (T == 0) {			/* If We did not wand hit it */
				/* #49 */
    if (Weapon_is_ammo(Enforcer->Index) &&
	Enforcer == Player.Cur_Wep) {
      T = -1;
      Echo_Init();
      /* With Weapon[Enforcer->Index] */
      sprintf(F, "Your %s", Weapon[Enforcer->Index].Name);
      if (Enforcer->Quan > 1)
	strcat(F, "s do");
      else
	strcat(F, " does");
      strcat(F, " not make an effective hand-held weapon");
      Echo(Echo_Str);
    }
  } /* did not want hit it */

  if (T >= -1)
    if ((!M->Awake) && M->Index == m_mimic) { /* woke up a mimic */
      Ch = World.Mon[X][Y];
      if (Ch == '!' || Ch == ')' || Ch == '[' || Ch == '&' || Ch == '$' ||
	  Ch == '*' || Ch == '?' || Ch == '/' || Ch == '=') {
	Echo_Init();
	strcat(F, "Oops!  That\'s no ");
	switch (Ch) {
	case '!': strcat(F, "potion"); break;
	case ')': strcat(F, "weapon"); break;
	case '[': strcat(F, "armor"); break;
	case '&': strcat(F, "food"); break;
	case '$': strcat(F, "AMULET of YENDOR"); break;
	case '*': strcat(F, "gold"); break;
	case '?': strcat(F, "scroll"); break;
	case '/':
	  switch (Die(2)) {
	  case 1: strcat(F, "staff"); break;
	  case 2: strcat(F, "wand"); break;
	  }
	  break;
	case '=': strcat(F, "ring"); break;
	}
	strcat(F, "!! That\'s a mimic!!!");
	Echo(Echo_Str);
	World.Mon[X][Y] = 'M';
	M->Awake = true;
	T = -3;

	if (Switches.Flush_swi)
	  flushinp();
	return false;
      }
    } /* If We woke up a sleeping mimic */

  if (T == 0) {		       /* We did Not hit With thrown weapon */
    if (Player.Blind_count > 0 && Player.Eaten_count == 0) /* #71 */
      Hit_adj = -2;
    else
      Hit_adj = 0;
    if (! M->Awake)
      Hit_adj += 2;
    if (Weapon_is_ammo(Enforcer->Index)) {
      /* Missile Weapon Dex Adjustment */
      Hit_adj += Player.Cur_Wep->Plus_Hit;
      if (Player.DX > 15)
	Hit_adj += Player.DX - 15;
      else if (Player.DX < 6)
	Hit_adj += Player.DX - 6;
    }
    if (Die(20) >= (20 - Monster[M->Index].Ac - Enforcer->Plus_Hit -
		    Hit_adj - ((Player.Level - 1) / 2))) {
      /* Ok, now we hit it... */
      if (Monster[M->Index].Large)
	for (I = 1; I <= max(Weapon[Enforcer->Index].L_Num,1); ++I)
	  T += Die(Weapon[Enforcer->Index].L_Dam);
      else
	for (I = 1; I <= max(Weapon[Enforcer->Index].S_Num,1); ++I)
	  T += Die(Weapon[Enforcer->Index].S_Dam);
      T += Enforcer->Plus_Dam;
      if (Weapon_is_ammo(Enforcer->Index))
	T += Player.Cur_Wep->Plus_Dam;
      else if (Player.ST > 14)
	T += (Player.ST - 14);
      else if (Player.ST < 7)
	T += (Player.ST - 7);
      if (Player.Eaten_count > 0)
	T -= (7 - Player.Eaten_count);
      T = max(T, 1);
    } /* Ok, now we hit it... */
  } /* We had Not hit it before */

  if (T > 0)
    Defenses(Enforcer, M, &T);
  Echo_Init();
  if (T > 0) {			/* We HIT IT!!! */
    /* Rings of increase damage handled here */
    for (Hand = Left_H; Hand <= Right_H; ++Hand)
      if (Player.Cur_Ring[Hand])
	if (Player.Cur_Ring[Hand]->Index == r_incr_dam)
	  T = max(1, T + Player.Cur_Ring[Hand]->Plus_Hit);
    M_Ouch_MSG(F, M, T, Enforcer);
    M->Awake = true;
    Echo_Str[0] = toupper(Echo_Str[0]);
    Echo(Echo_Str);
    M->HP -= T;
    Check_Vampiric(Enforcer, T);
    retval = true;
    if (M->HP <= 0) {		/* we killed it! */
      Player.XP += Monster[M->Index].Xpval;
      if (M->Index == m_fungi ||
	  M->Index == m_troll ||
	  M->Index == m_nymph ||
	  M->Index == m_juiblex ||
	  M->Index == m_death ||
	  M->Index == m_gith ||
	  M->Index == m_lep ||
	  M->Index == m_mimic ||
	  M->Index == m_int) {
	if (M->Index == m_fungi ||
	    M->Index == m_mimic)
	  Player.Stuck = false;
	else
	  Dead_Mon_Treasure(M);
      }
      Del_Mon(&M);
      Change_stats |= S_Bottom;
    } else {			/* ok, we did Not kill it */
      if (Player.Will_confuse) {
	M->Confused_count += 10 + Die(5);
	Player.Will_confuse = false;
	Echo_Init();
	if (Switches.Terse_swi || Player.Blind_count > 0)
	  strcat(F, "It\'s confused");
	else
	  sprintf(F, "The %s appears confused", Monster[M->Index].Long_Name);
	Echo(Echo_Str);
      }
    }
  } else {
    M->Awake = true;
    if (T == -1) /* hit, but no message, please */
      retval = true;
    else {
      if (T == -2)
	retval = true;
      else
	retval = false;
      /* With Monster[M->Index] */
      if (Player.Cur_Wep == Enforcer) { /* Not thrown */
	if (Switches.Terse_swi)
	  strcat(F, "You miss ");
	else
	  switch (Die(3)) {
	  case 1: strcat(F, "You miss "); break;
	  case 2: strcat(F, "You swing and miss "); break;
	  case 3: strcat(F, "You barely miss "); break;
	  }
	if ((Player.Blind_count != 0) || Switches.Terse_swi)
	  strcat(F, "it");
	else {
	  strcat(F, "the ");
	  strcat(F, Monster[M->Index].Long_Name);
	}
      } else {			/* Did Throw! */
	if (Switches.Terse_swi)
	  strcat(F, "You miss ");
	else
	  switch (Die(3)) {
	  case 1: strcat(F, "You miss "); break;
	  case 2: strcat(F, "You wildly miss "); break;
	  case 3: strcat(F, "You barely miss "); break;
	  }
	if ((Player.Blind_count != 0) || Switches.Terse_swi)
	  strcat(F, "it");
	else {
	  strcat(F, "the ");
	  strcat(F, Monster[M->Index].Long_Name);
	}
      } /* Did Throw! */
      Echo(Echo_Str);
    }
  }

  Check_Player_Level();

  if (Switches.Flush_swi)
    flushinp();

  return(retval);
} /* Attack */

bool Can_move_to(int X, int Y) {
  char Ch = World.S_World[X][Y];
  return((Ch == '.' || Ch == '%' || Ch == '+' ||
	  Ch == '#' || Ch == '^') &&
	 (World.Mon[X][Y] == EMPTY));
}

bool Down_Stairs() {
  int line;
  char Ch;

  if (Player.Stuck)
    Give_stuck_message();
  else if (World.S_World[Player.Loc.x][Player.Loc.y] == '%') {
    if (World.Level == Amulet_level && Player.Has_amulet) {
      clear();
      Dead = true;
      Player.Gold += 5000;
      Killer = '$';
      line = 1;
      move(line++, 0);		/* skip one line */
      addstr("As you decend the stairs, a white mist envelops you.  You feel very");
      move(line++, 0);
      addstr("strange for a moment, and when the mist clears, you find yourself");
      move(line++, 0);
      addstr("standing in the middle of the ruins at the entrance to the Dungeons");
      move(line++, 0);
      addstr("of Doom.  Congratulations!  You Made It!");
      move(line + 2, 0);
      addstr("[Press any key to continue] ");
      refresh();
      Ch = Comand();
      return true;
    } else {
      Down_a_level();
      return true;
    }
  } else
    Echo("I see no way down");
  return false;
} /* Down_Stairs */

bool Stop(bool Foo) {
  char Ch;

  Empty_Echo = true;
  Echo("Really quit (Y or N) ?");
  Move_To_Echo();
  do {
    Ch = tolower(Comand());
  } while (Ch != 'y' && Ch != 'n');
  if (Ch == 'y') {
    Quit_game = true;
    Killer = ' ';
    Want_scores = Foo;
    return true;
  }

  Clear_Echo();
  Redisplay();
  return false;
} /* Stop */

#if 0
Procedure Save_game {
Var
  S_File : Long_String;
  I,J,Arm_num,Wep_num,L_r_num,R_r_num,Disk_address,Fudge : Integer;
  P : Obj_ptr;
  Q : Mon_ptr;
  R : Trap_ptr;
  Uname : Name_string;
  Ch : Char;
  G : Text;
Begin /* Save_game */
  For I = 1 to Name_Len
    S_File[I] = Save_File[I];
  S_File[Name_Len + 1] = Chr(0);
  Fix_String(S_File);
  Echo_Init;
  Write(F,'Saving as: ',Save_File);
  Empty_Echo = true;
  Echo(S);
  rewrite(g,S_file,0,0,[2,14],60000b); /* buffered by bytes */
  getfdb(S_File,disk_address);
  writeln(g,disk_address:0);
  writeln(g,seed:0);
  fudge = (disk_address Mod 100B) + (seed Mod 40B);
  Writeln(g,fudge - 1:0);
  with world
    for i = x_orig to s_max_x
      for j = y_orig to s_max_y
	{
	  write(g,s_world[i,j],this_screen[j,i],screen[j,i]);
	  if mon[i,j] == Chr(0)
	    then write(g,' ')
	    else write(g,mon[i,j]);
	  if obj[i,j] == Chr(0)
	    then writeln(g,' ')
	    else writeln(g,obj[i,j]);
	  writeln(g,room_array[i,j]:0);
	  Writeln(g,Ord(seeable[i,j]):0);
	  Writeln(g,Ord(seen[i,j]):0);
	  Writeln(g,'1'); /* Ord(Show[i,j]):0); */
	}
  for j = y_orig to s_max_y
    Writeln(g,Ord(world.lines[j]):0);
  writeln(g,world.level:0,' ',world.num_mons:0,' ',world.max_mons:0,' ',seed:0);
  for i = 1 to max_room
    with world.rooms[i]
      {
	writeln(g,max_x:0,' ',max_y:0,' ',abs_x:0,' ',abs_y:0);
	Writeln(g,Ord(light):0);
	Writeln(g,Ord(existent):0);
	Writeln(g,Ord(seen):0);
	for j = 0 to max_doors
	  writeln(g,doors[j].abs_loc.x:0,' ',doors[j].abs_loc.y:0,' ',doors[j].secret:0);
	writeln(g,orig_x[i]:0,' ',orig_y[i]:0);
	Writeln(g,Ord(m_used_list[i]):0);
	Writeln(g,Ord(o_used_list[i]):0);
      }
  for i = 1 to max_monster
    writeln(g,monster[i].min_level:0);
  for i = 1 to max_potion
    With potion[i]
      {
	writeln(g,desc:Name_Len,d_leng:0);
      Writeln(g,Ord(called):0);
      Writeln(g,Ord(id):0);
      }
  for i = 1 to max_scroll
    With scroll[I]
      {
	writeln(g,desc:Name_Len,d_leng:0);
	Writeln(g,Ord(called):0);
	Writeln(g,Ord(id):0);
      }
  for i = 1 to max_wand
    With wand[i]
      {
	writeln(g,desc:Name_Len,d_leng:0);
	Writeln(g,Ord(called):0);
	Writeln(g,Ord(id):0);
	Writeln(g,Ord(is_wand):0);
      }
  for i = 1 to max_ring
    With ring[i]
      {
	writeln(g,desc:Name_Len,d_leng:0);
	Writeln(g,Ord(called):0);
	Writeln(g,Ord(id):0);
      }

  arm_num = 0;
  wep_num = 0;
  l_r_num = 0;
  r_r_num = 0;
  i = 1;
  p = world.objs;
  while p != NULL
    {
      writeln(g,i:0,' ',ord(p->obj_typ):0,' ',p->loc.x:0,' ',p->loc.y:0);
      writeln(g,p->quan:0,' ',p->index:0,' ',p->plus_hit:0,' ',p->plus_dam:0);
      Writeln(g,Ord(p->know_magic):0);
      Writeln(g,Ord(P->cursed):0);
      p = p->next;
    }
  p = player.obj_list;
  i = 2;
  j = 0;
  while p != NULL
    {
      j = j+1;
      if p == player.cur_arm
	arm_num = j
      Else If p == player.cur_wep
	wep_num = j
      Else If p == player.Cur_ring[Left_H]
	l_r_num = j
      Else If p == player.Cur_ring[Right_H]
	r_r_num = j;
      writeln(g,i:0,' ',ord(p->obj_typ):0,' ',p->loc.x:0,' ',p->loc.y:0);
      writeln(g,p->quan:0,' ',p->index:0,' ',p->plus_hit:0,' ',p->plus_dam:0);
      Writeln(g,Ord(p->know_magic):0);
      Writeln(g,Ord(p->cursed):0);
      p = p->next;
    }
  i = 3;
  q = world.monsters;
  while q != NULL
    {
      writeln(g,i:0,' ',q->index:0,' ',q->hp:0,' ',q->loc.x:0,' ',q->loc.y:0,' ',q->paralyzed_count:0);
      writeln(g,q->speed:0,' ',q->speed_count:0,' ',q->who_first:0,' ',q->confused_count:0);
      Writeln(g,Ord(q->awake):0);
      q = q->next;
    }
  i = 4;
  r = world.traps;
  while r != NULL
    {
      writeln(g,i:0,' ',r->loc.x:0,' ',r->loc.y:0,' ',r->chance:0,' ',r->kind:0);
      r = r->next;
    }
  writeln(g,i+1:0); /* end of lists */
  writeln(g,arm_num:0,' ',wep_num:0,' ',l_r_num:0,' ',r_r_num:0);
  with player
    {
      writeln(g,gold*fudge:0,' ',xp:0,' ',level:0,' ',hp:0,' ',name);
      Writeln(g,max_hp:0,' ',st:0,' ',max_st:0,' ',dx:0,' ',max_dx:0,' ',iq:0,' ',max_iq:0);
      writeln(g,ac-fudge:0,' ',Died_Count:0,' ',faint_count:0,' ',invis_count:0,' ',speed:0,' ',speed_count:0);
      writeln(g,confused_count:0,' ',blind_count:0,' ',last_meal:0,' ',heal_count:0,' ',loc.x:0,' ',loc.y:0);
      writeln(g,paralyzed_count:0,' ',sleep_count:0,' ',trapped_count:0,' ',fixed_count:0);
      Writeln(g,Ord(will_confuse):0);
      Writeln(g,Ord(stuck):0);
      Writeln(g,Ord(has_amulet):0);
    }
  writeln(g,player.level+player.gold+player.ST+Player.DX+disk_address:0);
  writeln(g,fruit_name);
  Writeln(g,Save_File);
  writeln(g,amulet_level+fudge:0);
  writeln(g,blank_message:0);
  writeln(g,scare_count:0);
  Writeln(g,Player.eaten_Count:0,' ',Player.Prev.X:0,' ',Player.Prev.Y:0);
  close(g);
  fiddle_fdb(S_File);
  saved = true;
  quit_game = true;
} /* Save_game */

Procedure Save_The_Game {
Var
  Ch : Char;
Begin /* Save_The_Game */
  Empty_Echo = true;
  Echo("Really save the game (Y or N) ?");
  Move_To_Echo();
  Repeat
    Ch = Comand()
  Until (Ch in ['y','n','Y','N']);
  If (Ch in ['Y','y'])
    Save_Game
  Else
    {
      Clear_Echo();
      Redisplay()
    }
} /* Save_The_Game */

Function Restore_game : Boolean {
Var
  R_File : Long_String;
  i,j,arm_num,wep_num,l_r_num,r_r_num,disk_address,fudge,checknum:integer;
  ok_restore : Boolean;
  p:obj_ptr;
  q:mon_ptr;
  r:trap_ptr;
  g:text;
  uname:name_string;
  temp:char;
begin /* Restore_game */
  For I = 1 to Name_Len
    R_File[I] = R_File_Name[I];
  R_File[Name_Len + 1] = Chr(0);
  Fix_String(R_File);
  ok_restore = true;
  fiddle_fdb(R_File);
  getfdb(R_File,disk_address);
  reset(g,r_file,0,0,[2],60000b);
  readln(g,i);
  Readln(g,seed);
  Readln(g,fudge);
  fudge = fudge + 1;
  If ((i != disk_address) || (fudge != ((disk_address Mod 100B) + (seed Mod 40B))))

      {
	close(g);
	edelete(R_File);
	ok_restore = false;
      }
    Else
      {
  CLS;
  Writeln(tty,'Restoring from: ',R_file_name);
  with world
    for i = x_orig to s_max_x
      for j = y_orig to s_max_y
	{
	  read(g,s_world[i,j],this_screen[j,i],screen[j,i]);
	  read(g,temp);
	  if temp == ' '
	    then mon[i,j] = Chr(0)
	    Else Mon[i,j] = Temp;
	  readln(g,temp);
	  if temp == ' '
	    then obj[i,j] = Chr(0)
	    Else obj[i,j] = Temp;
	  readln(g,room_array[i,j]);
	  readln(g,temp);
	  seeable[i,j] = (temp == '1');
	  readln(g,temp);
	  seen[i,j] = (temp == '1');
	  readln(g,temp);
/*	  show[i,j] = (temp == '1'); */
	}
  for j = y_orig to s_max_y
    {
      readln(g,temp);
      world.lines[j] = (temp == '1');
    }
  readln(g,world.level,world.num_mons,world.max_mons,seed);
  for i = 1 to max_room
    with world.rooms[i]
      {
	readln(g,max_x,max_y,abs_x,abs_y);
	readln(g,temp);
	light = (temp == '1');
	readln(g,temp);
	existent = (temp == '1');
	readln(g,temp);
	seen = (temp == '1');
	for j = 0 to max_doors
	  readln(g,doors[j].abs_loc.x,doors[j].abs_loc.y,doors[j].secret);
	readln(g,orig_x[i],orig_y[i]);
	readln(g,temp);
	m_used_list[i] = (temp == '1');
	readln(g,temp);
	o_used_list[i] = (temp == '1');
      }
  for i = 1 to max_monster
    readln(g,monster[i].min_level);
  for i = 1 to max_potion
    {
      readln(g,potion[i].desc,potion[i].d_leng);
      readln(g,temp);
      potion[i].called = (temp == '1');
      readln(g,temp);
      potion[i].id = (temp == '1');
    }
  for i = 1 to max_scroll
    {
      readln(g,scroll[i].desc,scroll[i].d_leng);
      readln(g,temp);
      scroll[i].called = (temp == '1');
      readln(g,temp);
      scroll[i].id = (temp == '1');
    }
  for i = 1 to max_wand
    {
      readln(g,wand[i].desc,wand[i].d_leng);
      readln(g,temp);
      wand[i].called = (temp == '1');
      readln(g,temp);
      wand[i].id = (temp == '1');
      readln(g,temp);
      wand[i].is_wand = (temp == '1');
    }
  for i = 1 to max_ring
    {
      readln(g,ring[i].desc,ring[i].d_leng);
      readln(g,temp);
      ring[i].called = (temp == '1');
      readln(g,temp);
      ring[i].id = (temp == '1');
    }

  arm_num = 0;
  wep_num = 0;
  l_r_num = 0;
  r_r_num = 0;
  world.objs = NULL;
  new(p);
  read(g,i);
  while i == 1
    {
      if world.objs == NULL
	then world.objs = p;
      read(g,j);
      case j of {
	0: p->obj_typ = amulet_t;
	1: p->obj_typ = food_t;
	2: p->obj_typ = ring_t;
	3: p->obj_typ = wand_t;
	4: p->obj_typ = scroll_t;
	5: p->obj_typ = potion_t;
	6: p->obj_typ = armor_t;
	7: p->obj_typ = weapon_t;
	8: p->obj_typ = gold_t;
	others: {
		  writeln(tty,'Error - Bad world object in restore_game');
		  ok_restore = false;
		}
      }
      readln(g,p->loc.x,p->loc.y);
      readln(g,p->quan,p->index,p->plus_hit,p->plus_dam);
      readln(g,temp);
      p->know_magic = (temp == '1');
      readln(g,temp);
      p->cursed = (temp == '1');
      read(g,i);
      if i == 1

	  {
	    new(p->next);
	    p = p->next;
	  }
	else p->next = NULL;
    } /* while i == 1 */
  new(p);
  player.obj_list = NULL;
  while i == 2
    {
      if player.obj_list == NULL
	then player.obj_list = p;
      read(g,j);
      case j of {
	0: p->obj_typ = amulet_t;
	1: p->obj_typ = food_t;
	2: p->obj_typ = ring_t;
	3: p->obj_typ = wand_t;
	4: p->obj_typ = scroll_t;
	5: p->obj_typ = potion_t;
	6: p->obj_typ = armor_t;
	7: p->obj_typ = weapon_t;
	8: p->obj_typ = gold_t;
	others: {
		  writeln(tty,'Error - Bad player possession in restore_game');
		  ok_restore = false;
		}
      }
      readln(g,p->loc.x,p->loc.y);
      readln(g,p->quan,p->index,p->plus_hit,p->plus_dam);
      readln(g,temp);
      p->know_magic = (temp == '1');
      readln(g,temp);
      p->cursed = (temp == '1');
      read(g,i);
      if i == 2

	  {
	    new(p->next);
	    p = p->next;
	  }
	else p->next = NULL;
    }

  world.monsters = NULL;
  new(q);
  while i == 3
    {
      if world.monsters == NULL
	then world.monsters = q;
      readln(g,q->index,q->hp,q->loc.x,q->loc.y,q->paralyzed_count);
      readln(g,q->speed,q->speed_count,q->who_first,q->confused_count);
      readln(g,temp);
      q->awake = (temp == '1');
      read(g,i);
      if i == 3

	  {
	    new(q->next);
	    q = q->next;
	  }
	else q->next = NULL;
    }
  world.traps = NULL;
  new(r);
  while i == 4
    {
      if world.traps == NULL
	then world.traps = r;
      readln(g,r->loc.x,r->loc.y,r->chance,r->kind);
      read(g,i);
      if i == 4

	  {
	    new(r->next);
	    r = r->next;
	  }
	else r->next = NULL;
    }
  if (i != 5)
    Then ok_restore = false;
  readln(g,arm_num,wep_num,l_r_num,r_r_num);
  with player
    {
      readln(g,gold,xp,level,hp,temp,name);
      gold = gold div fudge;
      Readln(g,max_hp,st,max_st,dx,max_dx,iq,max_iq);
      readln(g,ac,Died_Count,faint_count,invis_count,speed,speed_count);
      ac = ac + fudge;
      readln(g,confused_count,blind_count,last_meal,heal_count,loc.x,loc.y);
      readln(g,paralyzed_count,sleep_count,trapped_count,fixed_count);
      readln(g,temp);
      will_confuse = (temp == '1');
      readln(g,temp);
      stuck = (temp == '1');
      readln(g,temp);
      has_amulet = (temp == '1');
      cur_arm = NULL;
      cur_wep = NULL;
      Cur_ring[Left_H] = NULL;
      Cur_ring[Right_H] = NULL;
    }
  readln(g,checknum);
  if (checknum != player.gold+player.level+disk_address+player.ST+player.DX)
    Then ok_restore = false;
  j = 0;
  p = player.obj_list;
  while p != NULL
    {
      j = j+1;
      if j == arm_num
	player.cur_arm = p
      Else If j == wep_num
	player.cur_wep = p
      Else If j == l_r_num
	player.Cur_ring[Left_H] = p
      Else If j == r_r_num
	player.Cur_ring[Right_H] = p;
      p = p->next;
    } /* while p != NULL */

  readln(g,fruit_name);
  readln(g,save_file);
  readln(g,amulet_level);
  amulet_Level = Amulet_level - fudge;
  readln(g,blank_message);
  readln(g,scare_count);
  Readln(g,Player.eaten_Count,Player.Prev.X,Player.Prev.Y);
  If (Player.Eaten_Count > 0) {
    Monster[m_purple].AC = 9;
  }
  close(g);
  Edelete(R_File);

  F_temp = false; /* #55 Set up For restart */
  Fast = false;
  Virgin = false;
  Dead = false;
  Quit_game = false;
  Empty_Echo = true;
  For I = X_orig To S_max_x
    For J = Y_orig To S_max_y
      false_array[I,J] = false;
  For I = 1 To 80 Do Nulls[I] = Chr(0);
}
  If Not Ok_Restore
    Writeln(tty,'The save file has been tampered with and has been deleted.')
  Else
    Restore_screen;
  Restore_Game = Ok_restore
} /* Restore_game */

/* Routine to find out who is using a particular player name.
   Appropriate messages for non-existent users and unknown names. */

Procedure Whois {
Var
  Who,Uwho,Name:Name_string;
  Real_user:Long_string;
  Found,Is_user,More:Boolean;
  Usernum,Exists,Who_length,Name_length,Match:Integer;

Begin /* Whois */
  If Switches.Terse_swi
    Echo("Whois:")
  Else
    Echo("Enter player name to identify:");
  Move_To_Echo();
  If Get_Line(Who,Who_length) Then /* #54 */
    {
      Empty_Echo = true;
      Clear_Echo();
      Redisplay;
      Null_end_name(Who,UWho);
      Is_user = Valid(UWho,Usernum);
      Upcase(UWho,Uwho);
      Reset(Nm,Files.Names^,'/D/F/O',0,0,[29]);
      Found = false;
      More = true;
      While More
	If EOF(Nm)
	  More = false
	Else If Is_user
	  {
	    If (Nm->Num == Usernum)
	      {
		Found = true;
		More = false;
		Echo_init;
		JSYS(41B,1;Real_user,Nm->Num); /* DIRST */
		Fix_String(Real_User);
		Name_Length = 80;
		While (Real_user[Name_length] == ' ')
		  Name_length = Name_length - 1;
		Write(F,Real_User:Name_Length,': ',Nm->Nam);
		Echo(S)
	      }
	    Else
	      Get(Nm)
	  }
	Else
	  {
	    JSYS(41B,1,Exists;Real_user,Nm->Num); /* DIRST */
	    If (Exists == 2)
	      {
		Null_end_name(Nm->Nam,Name);
		JSYS(565B;0,-1:UWho,-1:Name;Match); /* WILD% */
		If (Match == 0)
		  {
		    Fix_String(Name);
		    Name_Length = Name_Len;
		    While (Name[Name_length] == ' ')
		      Name_length = Name_length - 1;
		    Echo_Init;
		    Write(F,Name:Name_length,': ');
		    Fix_String(Real_User); /* #60 */
		    Write(F,Real_user);
		    If Found
		      More = Wait_For_Space(false);
		    Found = true;
		    Empty_Echo = true;
		    If More
		      Echo(S)
		    Else
		      {
			Clear_Echo();
			Redisplay
		      }
		  }
	      }
	    Get(Nm)
	  }
      If Not Found
	Echo("That name is not currently in use");
      Close(Nm)
    }
  Else
    {
      Empty_Echo = true;
      Clear_echo();
    }
} /* Whois */
#endif

void Type_version() {
  Long_string vers;
  sprintf(vers, "This is ECL Rogue (for Linux), version %d.%d(%d)",
	  Rogue_Version, Rogue_Update, Rogue_Edit);
  AddText(vers);
}

void Version_Text() {
  Type_version();
  TextLine++;
  AddText(" Old features:  Bugs.");
  AddText("Last Modified:  23 March 2004.");
  TextLine++;
  AddText("   Written by:  Gary Craig, Oscar Erickson, John Relph, and Jay Skeer");
  AddText("           at:  USC-ECL May-December, 1982");
  AddText("     Modified:  Quite a bit.");
  TextLine++;
} /* Version_Text */

void Disp_Version () {
  char Ch;

  clear();
  Version_Text();
  AddText("Report bugs to: ");
  addstr(Bug_add);
  addstr(" via mail.");
  move(24,1);
  addstr("[Type anything to continue] ");
  Ch = Comand();
  Restore_screen();
} /* Disp_Version */

void Help() {
  bool Bogus;

  clear();			/* Get them a new screen */
  StartText();
  AddText(" -- ECL ROGUE command summary -- Movement --");
  AddText("");
  AddText(" b,1 - Down and Left    j,2 - Down");
  AddText(" n,3 - Down and Right   h,4 - Left");
  AddText(" f,5 - Fast prefix      l,6 - Right");
  AddText(" y,7 - Up and Left      k,8 - Up");
  AddText(" u,9 - Up and Right     5 <Direction> or f <Direction> or");
  AddText("                        <Capital direction> moves \"Fast\"");
  AddText("");
  AddText(" Fast Movement will move until you see something of interest.");
  AddText(" If it is a monster you will not automatically attack it.");
  AddText("");
  AddText(" To attack a monster (the single letters) move onto it.");
  AddText(" To pick up a treasure (almost everything else) move onto it.");
  AddText("");
  AddText(" Type <ESC> to abort any command in progress."); /* #71 */
  AddText("");
  AddText(" Type <Space> to answer the \"--More--\" prompt."); /* #71 */

  Bogus = Wait_For_Space(true);	/* #71 */

  if (! Bogus) {		/* #55 */
    Restore_screen();
    return;
  }

  StartText();
  AddText(" -- ECL ROGUE command summary -- Other commands --");
  AddText("");
  AddText("     e - To EAT food or fruit \"&\"       q - To QUAFF a potion \"!\"");
  AddText("     w - To WIELD another weapon \")\"    t - To THROW a weapon \"(\"");
  AddText("     T - To TAKE OFF armor \"[\"          W - To WEAR armor \"[\"");
  AddText("     P - To PUT ON a ring \"=\"           R - To REMOVE a ring \"=\"");
  AddText("     r - To READ a scroll \"?\"           z - To ZAP a wand or staff \"/\"");
  /*  AddText(" S - To SAVE a game                 Q - To QUIT a game"); */
  AddText("     / - To identify a screen symbol    ^ - To identify a TRAP");
  AddText("     Q - To QUIT a game"); /* #71 */
  AddText("     > - To go down the Stairs \"%\" to the next level");
  AddText("     C - To CALL an object by another name");
  AddText("     s - To SEARCH around you for traps and secret doors");
  AddText("     i - To see an INVENTORY of possessions");
  AddText("     I - To INVENTORY a single possession or type of possession");
  AddText("     o - To set your OPTIONS (Name, fruit name, switches, etc.)");
  AddText("     v - To see the ECL Rogue VERSION information");
  AddText(" Space - To rest and regain Hit-Points"); /* #71 */
  AddText("   C-I - To re-INITIALIZE your terminal");
  AddText("   C-L - To redraw the screen         C-R - To REREAD the last message");
  AddText("   C-T - TIME of day and other statistics"); /* #71 */
  /*  AddText(" Control-W - To find out WHO uses a certain ROGUE name"); */
  /*  AddText(" Read the file \"rogue-init.instructions\" to learn how to"); */
  /*  AddText("   set up an initialization file."); */
  Bogus = Wait_For_Space(true);

  clear();
  Restore_screen();
} /* Help */

void What_symbol() {
  int Ch;

  if (Switches.Terse_swi)
    Echo("Which symbol?");
  else
    Echo("Which screen symbol do you want identified?");
  Move_To_Echo();
  Ch = Comand();
  if (Ch == CHESC) {
    Clear_Echo();
    Redisplay();
    return;
  }
  Empty_Echo = true;
  Echo_Init();
  sprintf(F, "\'%c\': ", Ch);
  if (isalpha(Ch)) {
    if (Ch >= 'a')
      Ch -= Mon_hi_offset;
    else
      Ch -= Mon_lo_offset;
    strcat(F, Monster[Ch].Long_Name);
  } else
      switch (Ch) {
      case '.': strcat(F, "Floor"); break;
      case '-':
      case '|': strcat(F, "Wall"); break;
      case '#': strcat(F, "Corridor"); break;
      case '+': strcat(F, "Door"); break;
      case '%': strcat(F, "Stairway"); break;
      case '@': strcat(F, Player.Name); break;
      case '!': strcat(F, "Potion"); break;
      case '?': strcat(F, "Scroll"); break;
      case '/': strcat(F, "Staff or Wand"); break;
      case '^': strcat(F, "Trap"); break;
      case '$': strcat(F, "The Amulet of Yendor"); break;
      case '=': strcat(F, "Ring"); break;
      case '[': strcat(F, "Armor"); break;
      case ')': strcat(F, "Weapon"); break;
      case '*': strcat(F, "Gold"); break;
      case '&': strcat(F, "Food"); break;
      case ' ': strcat(F, "Rock"); break;
      default:  strcat(F, "No such symbol");
      }
  Echo(Echo_Str);
} /* What_symbol */

void Toggle_Fast() {
  if (F_temp) {
    Fast = !Fast;
    if (Fast)
      Echo("Fast mode is SET");
    else
      Echo("Fast mode is RESET");
    F_temp = false;
  } else
    F_temp = true;
  Valid_Command = false;
  Do_Done = false;
}

void Bl_Old_World() {
  int I;

  for (I = 0; I <= 2; ++I)
    Old_World[I] = '&';		/* empty */
}

char Get_Map(int Y, int X) {	/* They ARE backwards */
  char Ch;

  Ch = World.S_World[X][Y];
  if (World.Obj[X][Y])
    Ch = '!';			/* signal object */
  if (World.Mon[X][Y] && World.Mon[X][Y] != '@')
    Ch = 'M';			/* signal monster */
  return Ch;
} /* Get_Map */

void Set_World(View_Array *World, int X, int Y, char Ch) {
  int Dir;
  if (logfp)
    fprintf(logfp, "Set_World: %c\n", Ch);
  Dir = (Ch - '0');
  Valid_Command = true;
  (*World)[1] = Get_Map(Y,X);
  if (((Dir == 1 || Dir == 3 || Dir == 7 || Dir == 9) &&
       (Player_Move == '2' || Player_Move == '8' ||
	Player_Move == '3' || Player_Move == '1')) ||
      (Dir == 2 || Dir == 8)) {
    (*World)[0] = Get_Map(Y, X - 1);
    (*World)[2] = Get_Map(Y, X + 1);
  } else {
    (*World)[0] = Get_Map(Y - 1, X);
    (*World)[2] = Get_Map(Y + 1, X);
  }
}

char Poss_Dirs(char Ch) {
  int Orig_Ch,Temp_Ch,
  x_init,y_init,
  i,j,Count;
  char gm;

  Count = 0;
  Orig_Ch = Ch;
  switch (Orig_Ch - '0') {
  case 1:
    x_init = 1;
    y_init = -1;
    break;

  case 7:
    x_init = 1;
    y_init = 1;
    break;

  case 9:
    x_init = -1;
    y_init = 1;
    break;

  default:
    x_init = -1;
    y_init = -1;
  }
  /* With Player.Loc */

  i = 2 * y_init;
  do {
    i -= y_init;
    if (((Player.Loc.y + i) >= Y_Orig) && ((Player.Loc.y + i) <= S_Max_Y)) {
      j = 2 * x_init;
      do {
	j -= x_init;
	if (((Player.Loc.x + j) >= X_Orig) && ((Player.Loc.x + j) <= S_Max_X)) {
	  gm = Get_Map(Player.Loc.y + i, Player.Loc.x + j);
	  if (! (gm == ' ' || gm == '-' ||
		 gm == '|' || gm == '^')) {
	    Temp_Ch = abs(i) + abs(j);
	    gm = Get_Map(Player.Loc.y + i, Player.Loc.x + j);
	    if (((Temp_Ch != 0) && (Temp_Ch != 2)) ||
		(! (gm == '#' || gm == '+'))) {
	      Temp_Ch = (5 + (i * (-3)) + j) + '0';
	      if (((Temp_Ch - '0') + (Orig_Ch - '0')) != 10)
		Ch = Temp_Ch;
	      Count++;
	    }
	  }
	}
      } while (j != - x_init);
    }
  } while (i != - y_init);

  if (Count == 2) {
    Set_World(&Old_World, Player.Loc.x, Player.Loc.y, Ch);
    Valid_Command = true;
    return Ch;
  } else
    return '0';
} /* Poss_Dirs */

void Same_View(int Y, int X, char Ch) {
  int I;
  View_Array New_World;

  Set_World(&New_World, X, Y, Ch);
  I = 0;
  while (I < 3) {
    if (Old_World[I] == '&')	/* first step */
      Old_World[I] = New_World[I];
    else if ((Old_World[I] != New_World[I]) &&
	     (! (New_World[I] == ' ' || New_World[I] == '-' ||
		 New_World[I] == '.' || New_World[I] == '|'))) { /* empty */
      if (New_World[I] == 'M') {
	if (logfp)
	  fprintf(logfp, "Same_View: (%d,%d) %s\n", X, Y, (F_temp ? "F" : "S"));
	F_temp = false;
      }
      Bl_Old_World();
      Valid_Command = false;
      if (New_World[I] == '!') /* Objects... */
	Dont_Turn = true;
      I = 3;
    } else
      Old_World[I] = New_World[I];
    I++;
  }
  if (logfp)
    fprintf(logfp, "Same_View: %c%c%c %s\n",
	    New_World[0], New_World[1], New_World[2], (F_temp ? "F" : "S"));
} /* Same_View */

bool In_Bounds(int Y, int X) {
  return((Y >= Y_Orig) && (Y <= S_Max_Y) &&
	 (X >= X_Orig) && (X <= S_Max_X));
}

void Movement(char Ch) {
  int T,U,
  I,J;
  bool Dummy;
  Mon_Ptr M;
  char gm;

  I = Ch - '0';			/* #71 XXX this is the cool math */
  if (I > 6) {
    J = I - 8;
    I = -1;
  } else if (I < 4) {
    J = I - 2;
    I = 1;
  } else {
    J = I - 5;
    I = 0;
  }
  /* With Player.Loc */

  T = Player.Loc.y + I;	     /* and all the rest Of the T's and U's */
  U = Player.Loc.x + J;
  if (In_Bounds(T, U)) {
    gm = Get_Map(T, U);
    if (! (gm == '-' || gm == '|' || gm == ' ' || gm == 'M')) {
      if (Player.Stuck)
	Give_stuck_message();
      else if ((! F_temp) || (World.S_World[U][T] != '^')) {
	World.Mon[Player.Loc.x][Player.Loc.y] = EMPTY;
	Player.Prev = Player.Loc;
	Player.Loc.y = T;
	Player.Loc.x = U;
	Moved = true;		/* HACK */
	World.Mon[Player.Loc.x][Player.Loc.y] = '@';
	Player_Takes_Step();
	if (F_temp)
	  Same_View(Player.Loc.y, Player.Loc.x, Ch);
	else {
	  Bl_Old_World();
	  Valid_Command = false;
	}
      } else
	Valid_Command = false;
      gm = World.Obj[Player.Loc.x][Player.Loc.y];
      if (gm == '?' || gm == '*' || gm == '!' || gm == '/' || gm == '[' ||
	  gm == ')' || gm == '&' || gm == '=' || gm == '$') {
	Get_Treasure(Player.Loc.x, Player.Loc.y);
	Valid_Command = false;
      }
      if (Trap_at(Player.Loc.x, Player.Loc.y)) { /* #62 */
	Step_on_trap(Player.Loc.x, Player.Loc.y);
	Valid_Command = false;
      }
    } else {			/* hit a wall, end of hallway, or monster */
      Bl_Old_World();
      Valid_Command = false;
      gm = Get_Map(T, U);
      if (gm == '^') {
	Do_Done = false;
	Valid_Command = false;
	F_temp = false;
      }
      if (gm == 'M') {
	if (logfp)
	  fprintf(logfp, "Movement: (%d,%d) %s\n", T, U,
		  (Valid_Command ? "valid" : "not"));
	Do_Done = true;
	M = Find_Mon(World.Monsters, U, T);
	if (! F_temp) {
	  Moved = true;
	  Dummy = Attack(U,T,Player.Cur_Wep);
	} else if (M)
	  if (M->Index == m_mimic) {
	    Moved = true;
	    Dummy = Attack(U,T,Player.Cur_Wep);
	  } else
	    Do_Done = false;
	else
	  Do_Done = false;
	F_temp = false;
	Fast = false;
      }
    }
  } else {			/* If not In_Bounds */
    Do_Done = false;
    Valid_Command = false;
  }
  /* With Player.Loc */
} /* Movement */

void Move_Player(char Ch) {
  if (Fast)
    F_temp = true;
  Movement(Ch);
  if (Do_Done) {
    if (Valid_Command)
      Player_Move = Ch;
    if ((! Valid_Command) && F_temp) {
      Ch = Poss_Dirs(Ch);
      if (Dont_Turn || (Ch == '0')) {
	F_temp = false;
	Dont_Turn = false;
      } else if (Ch != '0') {
	Has_Turned = !Has_Turned;
	Player_Move = Ch;
	Do_Done = ((! Has_Turned) || /* optimal turning */
		   (World.S_World[Player.Prev.x][Player.Prev.y] == '+'));
      }
    }
  } else if (F_temp)
    F_temp = false; /* must be false If invalid */
}

char Move_Char(char Ch) {
  bool Maybe_Fast;

  Maybe_Fast = false;
  if (isupper(Ch)) {
    Maybe_Fast = true;
    Ch = tolower(Ch);
  }
  switch (Ch) {
  case 'k': Ch = '8'; break;	/* N */
  case 'j': Ch = '2'; break;	/* S */
  case 'l': Ch = '6'; break;	/* E */
  case 'h': Ch = '4'; break;	/* W */
  case 'u': Ch = '9'; break;	/* NE */
  case 'y': Ch = '7'; break;	/* NW */
  case 'n': Ch = '3'; break;	/* SE */
  case 'b': Ch = '1'; break;	/* SW */
  default:
    if (Maybe_Fast) {
      Maybe_Fast = false;	/* nothing */
      Ch = toupper(Ch);
    }
  }
  F_temp = F_temp || Maybe_Fast;
  return Ch;
} /* Move_Char */

void Ctrl_t() {
  Long_string status;
  long tickspersec;
  time_t now, elapsed;
  struct tm *timep;
  struct tms currun;

  tickspersec = sysconf(_SC_CLK_TCK);
  now = time(NULL);
  timep = localtime(&now);
  elapsed = now - Inidat;
  if (elapsed <= 0)
    elapsed = 1;		/* prevent divide by zero */
  times(&currun);

  sprintf(status,
	  "ROGUE %d.%d(%d) %02d:%02d, Elapsed %02d:%02d:%02d, Usage: %02ldu %02lds",
	  Rogue_Version, Rogue_Update, Rogue_Edit,
	  timep->tm_hour, timep->tm_min,
	  (int)(elapsed / 3600),
	  (int)((elapsed / 60) % 60),
	  (int)(elapsed % 60),
	  (currun.tms_utime - Inirun.tms_utime) / tickspersec,
	  (currun.tms_stime - Inirun.tms_stime) / tickspersec);
  Echo(status);
}

void Do_Player() {
  int Ch;
  bool Bogus;
  Hand_Type Hand;

  Dont_Turn = ! Switches.Turn_swi;
  Moved = false;		/* HACK...COUGH */
  Has_Turned = false;
  do {
    Do_Done = true;
    if (Valid_Command)
      Ch = Player_Move;
    else
      Ch = Comand();
    Ch = Move_Char(Ch);
    if (! (Empty_Echo || Valid_Command)) {
      Clear_Echo();
      Empty_Echo = true;
    }
    if (Player.Confused_count > 0)
      if (isdigit(Ch) && Ch != '5')
	do {
	  Ch = Die(9) + '0';
	} while (Ch == '5');
    switch (Ch) {
    case '1':
    case '2':
    case '3':
    case '4':
    case '6':
    case '7':
    case '8':
    case '9':
      if (Player.Eaten_count > 0) { /* next line */
	Valid_Command = false;
	Bogus = Attack(Player.Loc.x, Player.Loc.y, Player.Cur_Wep);
      } /* PURPLE GERM stuff */
      else {
	Move_Player(Ch);
	Do_Done = Moved && Do_Done; /* Thrice dying hack */
      }
      break;

    case 'f':
    case 'F':
    case '5': Toggle_Fast(); break;

    case '.':
    case ' ': break;		/* do nothing! */

    case 'd':
    case 'D': Do_Done = Drop(); break;
    case 'e':
    case 'E': Do_Done = Eat_Food(); break;
    case 'q': Do_Done = Quaff_potion(); break;
    case 'r': Do_Done = Read_scroll(); break;
    case 'T': Do_Done = Take_off_armor(); break;
    case 't': Do_Done = Throw(); break;
    case 'W': Do_Done = Wear_armor(); break;
    case 'w': Do_Done = Wield_weapon(); break;
    case 'P': Do_Done = Put_on_ring(); break;
    case 'R': Do_Done = Remove_Ring(); break;
    case 'z':
    case 'Z': Do_Done = Zap_wand(); break;

    case 'i':
      /* Bogus */
      Ch = Inventory(Player.Obj_List, All_T, false); /* #65 */
      Do_Done = false;
      break;

    case 'I':
      Slow_Inventory(Player.Obj_List);
      Do_Done = false;
      break;

    case '%':			/* #71 */
    case '>': Do_Done = Down_Stairs(); break;
    case '^': Do_Done = Trap_Identify(); break;
    case 'C': Do_Done = Call_obj(); break;
    case 'Q': Do_Done = Stop(true); break;
#if 0
    case 'S': Save_The_Game(); break;
#endif

    case 'o':
    case 'O':
      Set_options();
      Do_Done = false;
      break;

    case 's': Search(Player.Loc.x, Player.Loc.y); break;
    case 'V':			/* #71 */
    case 'v':
      Disp_Version();		/* #50 */
      Do_Done = false;
      break;
    case '?':
      Help();
      Do_Done = false;
      break;
    case '/':
      What_symbol();
      Do_Done = false;
      break;
    default:
      Do_Done = false;
      switch (Ch) {
      case CHLFD: Do_Done = false; break;
      case CHFFD: Restore_screen(); break; /* ^L */
#if 0
      case CHCTW: Whois(); break; /* ^W */
#endif
      case CHCTT:  /* ^T */
	Empty_Echo = true;
	Ctrl_t();		/* #60 */
	Empty_Echo = false;
	break;

      case CHCTR: Echo(""); break; /* ^R */

      case CHTAB:		/* ^I */

	endwin();
	refresh();

	break;

      case CHCTC: Do_Done = Stop(false); break; /* ^C */

      default:
	flushinp();
	Echo("Invalid command");
	/*	Redisplay(); */
	Valid_Command = false;
	F_temp = false;
	Do_Done = false;
      } /* Case Ord(ch) */
    } /* Case Ch */

    /* If in fast mode and jumpswitch is on then display as soon as
       movement is invalid. */
    if ((! Valid_Command) && (isdigit(Ch) && Ch != '5') &&
	Switches.Jump_swi)
      Update_Screen();
    else if (!(Moved || Valid_Command || F_temp || Do_Done)) { /* #71 */
      Redisplay();		/* #71 */
      if (logfp)
	fprintf(logfp, "Do_Player: did not move\n");
    }
  } while (! Do_Done);
  for (Hand = Left_H; Hand <= Right_H; ++Hand)
    if (Player.Cur_Ring[Hand]) {
      if (Player.Cur_Ring[Hand]->Index == r_teleport) {
	if (Die(50) == 1) {
	  Teleportation();
	  Valid_Command = false; /* #71 stop running if teleported */
	}
      } else if (Player.Cur_Ring[Hand]->Index == r_search)
	if (Search(Player.Loc.x, Player.Loc.y))	/* #71 stop running if found */
	  Valid_Command = false;
    }
} /* Do_Player */

/* The higher the Adj the greater the chance of saving */
bool Save_vs_poison(int Adj) {
  if (Die(20) == 1)
    return false;
  else
    return((Die(20) + Adj) >= (14 - Player.Level));
} /* Save_vs_poison */

/* *************************************************************
 * Monster movement routines: were internal to Move_monsters() *
 ***************************************************************/

void Giant_Ant_Special() {
  if (! Save_vs_poison(0)) {
    if (Player.DX <= 1) {
      Dead = true;		/* They lose! */
      Killer = 'A';
      if (Player.Blind_count)
	Echo("You have been totally paralyzed");
      else if (Switches.Terse_swi)
	Echo("The ant has paralyzed you");
      else
	Echo("The ant paralyzes you, and drags you away to be fed to the Queen");
    } else {
      Player.DX--;
      Change_stats |= S_Top;
      if (Player.Blind_count)
	if (Switches.Terse_swi)
	  Echo("You have been stung");
      else
	Echo("You are stung and your joints become stiff");
      else if (Switches.Terse_swi)
	Echo("The ant has stung you");
      else
	Echo("The ant\'s stinger penetrates your skin and your joints become stiff");
    }
  }
} /* Giant_Ant_Special */

void Wraith_Special() {
  if ((! Save_vs_poison(-2)) && (! Has_on_ring(r_sustain))) {
    if (Player.ST <= 1) {
      Dead = true; /* They lose! */
      Killer = 'W';
      if (! (Switches.Terse_swi || Player.Blind_count))
	Echo("You feel the wraith drain the last of your body\'s warmth away");
      Echo("You have become a wraith");
      if (! Switches.Terse_swi)
	Echo("And, thus, have lost all desire to find the Amulet of Yendor");
    } else {
      if (! (Switches.Terse_swi || Player.Blind_count))
	Echo("As the wraith touches you, you feel your body grow cold");
      else
	Echo("You feel cold");
      Player.ST--;
      Change_stats |= S_Top;
    }
  }
} /* Wraith_Special */

void Vampire_Special() {
  int t;

  if (! Save_vs_poison(+2)) {	/* Give them a chance... */
    if (Player.Level == 1) {
      Dead = true;		/* They lose! */
      Killer = 'V';
      if (! (Switches.Terse_swi || Player.Blind_count))
	Echo("You scream in anguish as the vampire drains your remaining energy");
      Echo("You have become a vampire");
      if (! Switches.Terse_swi)
	Echo("And, thus, have lost all desire to find the Amulet of Yendor");
    } else {
      if (Player.Blind_count)
	Echo("You feel fangs sink into your shoulder");
      else if (Switches.Terse_swi)
	Echo("The vampire sucks your blood");
      else
	Echo("You feel the vampire\'s fangs sink into your shoulder");
      /* With Player */
      Player.Level--;
      Player.XP = (Two_to_the(Player.Level - 1) * 10) - 1;
      t = min(Die(10), Die(10));
      Player.HP -= t;
      Player.Max_HP -= t;
    }
    Change_stats |= S_Bottom;
  }
} /* Vampire_Special */

void Intellect_Devourer_Special() {

  if (! Save_vs_poison(Player.IQ - 14)) {
    if (Switches.Terse_swi || Player.Blind_count)
      Echo("You feel tormented");
    else
      Echo("You feel tormented as the intellect devourer\'s ego-whip strikes");
    if (Die(10) == 1)
      Player.IQ -= 2;
    else
      Player.IQ--;
    Change_stats |= S_Top;
    if (Player.IQ < 1) {
      Dead = true;		/* They lose! */
      Killer = 'i';
      if (! (Switches.Terse_swi || Player.Blind_count))
	Echo("The intellect devourer has ego-whipped your mind into froth!");
      Echo("You become a raving idiot!");
      if (! Switches.Terse_swi)
	Echo("And, thus, have lost all desire to find the Amulet of Yendor");
    }
  }
} /* Intellect_Devourer_Special */

void Umber_Hulk_Special() {
  if (! (Save_vs_poison(0) || Player.Blind_count)) {
    if (Switches.Terse_swi)
      Echo("You are confused");
    else
      Echo("The gaze of the umber hulk has confused you");
    if (Player.IQ < 7)
      Player.Confused_count += 30;
    else
      Player.Confused_count += 15;
  }
} /* Umber_Hulk_Special */

void Rust_monster_special() {
  if (Player.Cur_Arm)
    if (! Save_vs_poison(Player.Cur_Arm->Plus_Hit + 1)) {
      if (Player.Cur_Arm->Index == a_leather) {
	if (! (Switches.Terse_swi || Player.Blind_count)) {
	  Echo("The rust monster does not affect your leather armor");
	  Empty_Echo = true;
	}
      } else if (Player.AC < 10 && !Has_on_ring(r_protect)) {
	if (Switches.Terse_swi)
	  Echo("Your armor weakens");
	else
	  Echo("Your armor appears to have weakened!  Oh my!");
	Player.Cur_Arm->Plus_Hit--;
	Figure_Ac();
      }
    }
} /* Rust_monster_special */

void Leprechaun_special(Mon_Ptr *M) { /* #70 */
  if (Player.Gold && ! Save_vs_poison(Player.DX - 15)) { /* #71 have any? */
    Echo("Your purse feels lighter");
    Player.Gold = max(Player.Gold - Die(300), 0);
    if (Die(10) <= 2)
      Player.Gold = max(Player.Gold - Die(300), 0);
    Change_stats |= S_Bottom;
    Del_Mon(M);
  }
} /* Leprechaun_Special */

void Nymph_special(Mon_Ptr *M) { /* #70 */
  Obj_Ptr Stolen;
  char Ch;
  Hand_Type Hand;

  if (! Save_vs_poison(0)) {
    Stolen = Pick_Random_Object(&Ch);
    if (Stolen) {
      Stolen = Take_from_pack(&Ch, &Player.Obj_List, All_T, true, false);
      /* With Player*/
      if (Stolen == Player.Cur_Arm) {
	Player.Cur_Arm = NULL;
	Figure_Ac();
      } else if (Stolen == Player.Cur_Wep)
	Player.Cur_Wep = NULL;
      else
	for (Hand = Left_H; Hand <= Right_H; ++Hand)
	  if (Stolen == Player.Cur_Ring[Hand]) {
	    Player.Cur_Ring[Hand] = NULL;
	    Take_It_Off(Stolen);
	  }
      Echo_Init();
      strcat(F, "She stole ");
      Write_obj_name(F, Stolen, Not_Another);
      if (Stolen->Obj_Typ == Amulet_T)
	Player.Has_amulet = false;
      Del_Mon(M);
      Echo(Echo_Str);		/* #71 */
    }
  }
}

void Purple_worm_special(Mon_Ptr M) { /* Man, is this mean! */
  if (! Save_vs_poison(0)) {
    if (Switches.Terse_swi || Player.Blind_count)
      Echo("It swallows you...Gulp!");
    else
      Echo("Everything goes dark as the purple worm swallows you whole");
    Player.Eaten_count = 6;	/* six turns til death */
    Player.Blind_count = max(1, Player.Blind_count); /* #71 darkroom */
    World.Mon[Player.Loc.x][Player.Loc.y] = EMPTY;
    Player.Prev = Player.Loc;
    Player.Loc = M->Loc;
    Player_Disappears();
    World.Seeable[M->Loc.x][M->Loc.y] = true;
    Monster[m_purple].Ac = 9;
  }
}

void Floating_eye_special() {
  if (Player.Fixed_count == 0 && ! Player.Blind_count) {
    if (! Save_vs_poison(2)) {	/* a break for low-level people */
      if (Switches.Terse_swi)
	Echo("You are transfixed");
      else
	Echo("You are transfixed by the gaze of the floating eye");
      Player.Fixed_count = Die(5) + 5;
    }
  }
} /* Floating_eye_special */

void Mimic_Special() {
  Player.Stuck = true;
} /* Mimic_Special */

void Violet_fungi_special() {
  Player.Stuck = true;
} /* Violet_fungi_special */

void Blindheim_Special() {
  if (! (Save_vs_poison(0) || Player.Blind_count)) {
    Player.Blind_count = Die(10) + 10;
    if (Switches.Terse_swi)
      Echo("You are blinded");
    else
      Echo("You are blinded by the gaze of the blindheim");
  }
} /* Blindheim_special */

void Crypt_Thing_Special() {
  if (! Save_vs_poison(-1)) {
    Teleportation();
    if (! Player.Blind_count) {
      if (Switches.Terse_swi)
	Echo("You are teleported");
      else
	Echo("The crypt thing teleports you away");
    }
  }
} /* Crypt thing special */

void Homonculous_Special() {
  if (! (Save_vs_poison(4) || Player.Blind_count)) /* a break for low-level people */
    if (Player.Sleep_count == 0) {
      Player.Sleep_count += Die(10);
      if (Switches.Terse_swi)
	Echo("You sleep");
      else
	Echo("The homonculus puts you to sleep");
    }
}

void Phantom_Stalker_Special(Mon_Ptr M) {
  if (Die(5) > 4) {		/* what the hell */
    Polymorph(&M);
    M->Paralyzed_count = 1;	/* give the player one step */
  }
} /* Phantom_Stalker_Special */

void Revenant_Special() {
  if (Player.Paralyzed_count == 0 && ! Player.Blind_count)
    if (! Save_vs_poison(-1)) {
      Player.Paralyzed_count = Die(8);
      if (Switches.Terse_swi)
	Echo("You are scared stiff");
      else
	Echo("The revenant has paralyzed you with terror");
    }
} /* Revenant_Special */

void Sandman_Special(Mon_Ptr *M) { /* #70 */
  if (! Save_vs_poison(-4))
    if (Player.Sleep_count == 0) {
      if (Die(10) < 4) {
	if (Die(10) < 5)
	  Del_Mon(M);
	Player.Sleep_count = Die(8);
	if (Player.Blind_count || Switches.Terse_swi)
	  Echo("You fall asleep");
	else
	  Echo("The sandman puts you to sleep");
      }
    }
} /* Sandman_Special */

void Umpleby_Special() {
  int T;

  T = Die(40);
  if (T <= 10) {
    Echo_Init();
    Player.HP -= T;
    if (Switches.Terse_swi || Player.Blind_count)
      strcat(F, "You are zapped");
    else
      strcat(F, "The umpleby zaps you with electricity");
    if (Kill_Player())
      Killer = 'u';
    else
      Change_stats |= S_Bottom;
    Echo(Echo_Str);
  }
} /* Umpleby_Special */

void Hurt_Player(Mon_Ptr *M) {	/* #710 */
  int I, T, Adj, M_Max;

  if (Switches.Flush_swi)	/* Flush TYPE ahead IF needed */
    flushinp();
  Valid_Command = false;
  F_temp = false;
  Fast = false;
  Adj = 0;
  /* with player do */ /* figure adjustments to armor class */

  if (Player.DX >= 15)
    Adj = -(Player.DX - 14);
  else if (Player.DX <= 6)
    Adj = (7 - Player.DX);
  if (Has_on_ring(r_invis))
    Adj -= 1;			/* Was 2 */
  if ((*M)->Index == m_gith)	/* Githyanki''s silver sword */
    Adj += 3;
  else if ((*M)->Index == m_death)	/* Death Knight two-handed sword? */
    Adj += 4;

  /* normal attacks */
  if (Monster[(*M)->Index].Special != 2) { /* Monster has a Normal */
    if (Die(20) >= (Monster[(*M)->Index].Th0 - (Player.AC + Adj))) {
      T = 0;
      for (I = 1; I <= Monster[(*M)->Index].Num; ++I)
	T += Die(Monster[(*M)->Index].Dam);
      if (T > 0 && Player.HP > 0) {
	Echo_Init();
	/* With Monster[(*M)->Index] */
	if (Player.Blind_count)
	  strcat(F, "It");
	else
	  sprintf(F, "The %s", Monster[(*M)->Index].Long_Name);
	M_Max = (T * (Player.Level + 6)) / Player.Max_HP;
	switch (Die(2)) {
	case 1:
	  switch (M_Max) {
	  case 0: strcat(F, " grazes you"); break;
	  case 1: strcat(F, " scratches you"); break;
	  case 2: strcat(F, " beats on your face"); break;
	  case 3: strcat(F, " really puts it to you"); break;
	  case 4: strcat(F, " maims you horribly"); break;
	  default: strcat(F, " rapes you severely"); break;
	  }
	  break;
	case 2:
	  switch (M_Max) {
	  case 0: strcat(F, " slimes you"); break;
	  case 1: strcat(F, " nicks you"); break;
	  case 2: strcat(F, " strikes a decent blow"); break;
	  case 3: strcat(F, " hurts you bad"); break;
	  case 4: strcat(F, " horms you"); break;
	  default: strcat(F, " wounds you grievously"); break;
	  }
	}
	Player.HP -= T;
	if (Kill_Player())
	  Killer = Monster[(*M)->Index].Name;
	else
	  Change_stats |= S_Bottom;
	Echo(Echo_Str);
      }
    } else if (Player.HP > 0) { /* The monster misses its normal attack */
      Echo_Init();
      /* With Monster[(*M)->Index] */
      if (Player.Blind_count)
	strcat(F, "It missed");
      else
	sprintf(F, "The %s missed", Monster[(*M)->Index].Long_Name);
      Echo(Echo_Str);
      T = 0;
    }
  }
  /* Handle special attacks */

  if (Player.HP > 0) 		/* don''t do specials if he is dead */
    if ((Monster[(*M)->Index].Special == 2) ||
	((Monster[(*M)->Index].Special == 3) && (T > 0)))
      switch ((*M)->Index) {	/* Monster gets his special */
      case m_ant     : Giant_Ant_Special();		break;
      case m_eye     : Floating_eye_special();		break;
      case m_fungi   : Violet_fungi_special();		break;
      case m_lep     : Leprechaun_special(M);		break;
      case m_int     : Intellect_Devourer_Special();	break;
      case m_mimic   : Mimic_Special();			break;
      case m_nymph   : Nymph_special(M);		break;
      case m_purple  : Purple_worm_special(*M);		break;
      case m_rust    : Rust_monster_special();		break;
      case m_umber   : Umber_Hulk_Special();		break;
      case m_vampire : Vampire_Special();		break;
      case m_wraith  : Wraith_Special();		break;
      case m_blind   : Blindheim_Special();		break;
      case m_crypt   : Crypt_Thing_Special();		break;
      case m_homon   : Homonculous_Special();		break;
      case m_phantom : Phantom_Stalker_Special(*M);	break;
      case m_revenant: Revenant_Special();		break;
      case m_sand    : Sandman_Special(M);		break;
      case m_umpleby : Umpleby_Special();		break;
      default        : ;
      }
} /* Hurt_Player */

void Mon_Move(Mon_Ptr M, int Nx, int Ny) { /* #70 New fn */

  World.Mon[M->Loc.x][M->Loc.y] = EMPTY;
  /* But only tell the display routines if we need to */
  if (! World.Seen[M->Loc.x][M->Loc.y])
    World.Seeable[M->Loc.x][M->Loc.y] = false;
  else /* #71 if (World.S_World[M->Loc.x][M->Loc.y] == '#') */
    if (Player.SeeMon_count > 0)
      World.Seeable[M->Loc.x][M->Loc.y] = false;
  M->Loc.x = Nx;		/* And towards new location */
  M->Loc.y = Ny;
  if (Player.SeeMon_count > 0)
    World.Seeable[Nx][Ny] = true;
  World.Mon[Nx][Ny] = Monster[M->Index].Name;
} /* #70 End of New fn */

int Distance(int Nx, int Ny, int Ox, int Oy) { /* #70 */
 return (Nx - Ox) * (Nx - Ox) + (Ny - Oy) * (Ny - Oy);
}

typedef struct {
  int Tx;
  int Ty;
  int Dist;
  bool Towards;
  bool Move_at_all;
} Towards_Player_Rec, *TP_Ptr;

/* Move_One_Towards was internal to Towards_Player() */
/* #70 add this fn */
void Move_One_Towards(Mon_Ptr M, TP_Ptr Tp, int Px, int Py) {
  int I,J,Dx,Dy,Ndist;

  Tp->Move_at_all = false;
  Tp->Tx = M->Loc.x;
  Tp->Ty = M->Loc.y;
  Tp->Dist = Distance(Tp->Tx, Tp->Ty, Px, Py);
  for (I = -1; I <= 1; ++I)
    for (J = -1; J <= 1; ++J) {
      Dx = M->Loc.x + I;
      Dy = M->Loc.y + J;
      if (Can_move_to(Dx, Dy)) {
	Ndist = Distance(Dx, Dy, Px, Py);
	if ((Ndist <= Tp->Dist) == Tp->Towards) {
	  Tp->Tx = Dx;
	  Tp->Ty = Dy;
	  Tp->Dist = Ndist;
	  Tp->Move_at_all = true;
	}
      }
    }
}

/* Move_One_Away was internal to Towards_Player() */
/* #70 add this fn */
void Move_One_Away(Mon_Ptr M, TP_Ptr Tp, int Px, int Py) {
  int I,J,Dx,Dy,Ndist;

  Tp->Move_at_all = false;
  Tp->Tx = M->Loc.x;
  Tp->Ty = M->Loc.y;
  Tp->Dist = Distance(Tp->Tx, Tp->Ty, Px, Py);
  for (I = -1; I <= 1; ++I)
    for (J = -1; J <= 1; ++J) {
      Dx = M->Loc.x + I;
      Dy = M->Loc.y + J;
      if (Can_move_to(Dx, Dy)) {
	Ndist = Distance(Dx, Dy, Px, Py);
	if ((Ndist >= Tp->Dist) == Tp->Towards) {
	  Tp->Tx = Dx;
	  Tp->Ty = Dy;
	  Tp->Dist = Ndist;
	  Tp->Move_at_all = true;
	}
      }
    }
}

void Random_Move(Mon_Ptr M) {
  int I, J, Tx, Ty;
  int X_Disp[3], Y_Disp[3];
  bool Found;

  if ((M->Loc.x != Player.Loc.x || M->Loc.y != Player.Loc.y)) {
    X_Disp[0] = Die(3) - 2;
    do {
      X_Disp[1] = Die(3) - 2;
    } while (X_Disp[0] == X_Disp[1]);
    X_Disp[2] = -(X_Disp[0] + X_Disp[1]);
    Y_Disp[0] = Die(3) - 2;
    do {
      Y_Disp[1] = Die(3) - 2;
    } while (Y_Disp[0] == Y_Disp[1]);
    Y_Disp[2] = -(Y_Disp[0] + Y_Disp[1]);
    I = 0;
    Found = false;
    do {
      Tx = M->Loc.x + X_Disp[I];
      J = 0;
      do {
	Ty = M->Loc.y + Y_Disp[J];
	if (Ty != M->Loc.x || Ty != M->Loc.y)
	  Found = Can_move_to(Tx,Ty);
	J++;
      } while (J != 2 && !Found); /* I know this is weird. */
      I++;
    } while (I != 2 && !Found); /* this too. */
    if (Found)
      Mon_Move(M, Tx, Ty);	/* #70 */
  }
} /* Random_Move */

void Towards_Player(Mon_Ptr M, bool Towards) { /* #64 */
  int Dx,Dy,I,Ndist,Room; /* #70 */
  bool Found_Door;
  Towards_Player_Rec Tp;
  Long_string str;

  Tp.Towards = Towards;
  Tp.Move_at_all = false;

  if (M->Loc.x == Player.Loc.x && M->Loc.y == Player.Loc.y)
    return;			/* #71 Pascal can't do this! */

  Room = World.Room_array[M->Loc.x][M->Loc.y];
  if (Room < 0) {		/* in hallway */
    Echo_Init();
/*	    Write(f,'Hall: '); */
    if (isOkDir(M->Last_Dir) &&
	Distance(M->Loc.x, M->Loc.y,
		 Player.Loc.x, Player.Loc.y) > 10) { /* #71 */
      Translate_Direction(M->Last_Dir, &Dx, &Dy);
      sprintf(F, "Hall: moving %c prevDir %c == (%d,%d)",
	      Monster[M->Index].Name, M->Last_Dir, Dx, Dy);
      Move_One_Away(M, &Tp, M->Loc.x - Dx * 2, M->Loc.y - Dy * 2); /* was +,+ */
/*		If Not Tp.Move_at_all
		{
		  Towards = Not Towards;
		  Move_Mon_One(M->Loc.X - Dx,M->Loc.X - Dy);
		  Towards = Not Towards
		} */
      if (Tp.Move_at_all) {
	if (World.Room_array[Tp.Tx][Tp.Ty] < 0)
	  M->Last_Dir = Delta_Dir[Tp.Tx - M->Loc.x + 1][Tp.Ty - M->Loc.y + 1];
	sprintf(str, " actual %c (%d,%d)",
		M->Last_Dir, Tp.Tx - M->Loc.x, Tp.Ty - M->Loc.y);
	strcat(F, str);
	Mon_Move(M, Tp.Tx, Tp.Ty);
      }
      else
	M->Last_Dir = '5';
/*		Echo(S) */
      if (logfp)
	fprintf(logfp, "%s\n", Echo_Str);
    } else { /* haven''t picked a direction yet */
      Move_One_Towards(M, &Tp, Player.Loc.x, Player.Loc.y); /* #70 */
      if (Tp.Move_at_all) {
	M->Last_Dir = Delta_Dir[Tp.Tx - M->Loc.x + 1][Tp.Ty - M->Loc.y + 1];
	Mon_Move(M, Tp.Tx, Tp.Ty); /* #70 add this stuff */
      } else {
	Move_One_Away(M, &Tp, Player.Loc.x, Player.Loc.y);
	if (Tp.Move_at_all) {
	  M->Last_Dir = Delta_Dir[Tp.Tx - M->Loc.x + 1][Tp.Ty - M->Loc.y + 1];
	  /* With M^ */
	  sprintf(F, "Hall: moving %c from (%d,%d) to (%d,%d) delta %c(%d,%d)",
		  Monster[M->Index].Name, M->Loc.x, M->Loc.y,
		  Tp.Tx, Tp.Ty, M->Last_Dir,
		  Tp.Tx - M->Loc.x, Tp.Ty - M->Loc.y);
	  Mon_Move(M, Tp.Tx, Tp.Ty);
	} else {
	  M->Last_Dir = '5';	/* #71 */
	  Random_Move(M);	/* #71 */
	}
      }
    }
/*	    Echo(s) */
    if (logfp)
      fprintf(logfp, "%s\n", Echo_Str);
  }  /* in hallway */

  else if (World.Room_array[Player.Loc.x][Player.Loc.y] == Room) {
    /* in same room */
    Move_One_Towards(M, &Tp, Player.Loc.x, Player.Loc.y); /* #70 */
    M->Last_Dir = '5';
    if (Tp.Move_at_all) {
      if (logfp)
	fprintf(logfp, "Room: moving %c from (%d,%d) to (%d,%d) delta %c(%d,%d)\n",
		Monster[M->Index].Name, M->Loc.x, M->Loc.y,
		Tp.Tx, Tp.Ty, M->Last_Dir,
		Tp.Tx - M->Loc.x, Tp.Ty - M->Loc.y);
      Mon_Move(M, Tp.Tx, Tp.Ty); /* #70 add this stuff */
    } else {
      Random_Move(M);		/* #71 */
    }
  } /* in same room */

  else {			/* in a different room */
    Tp.Dist = INT_MAX;
    I = 0;
    Found_Door = false;
    while (I < Max_Doors) {
      Tp.Move_at_all = false;
      /* With World.Rooms[Room] */
      Dx = World.Rooms[Room].Doors[I].Abs_loc.x;
      Dy = World.Rooms[Room].Doors[I].Abs_loc.y;
      if (World.S_World[Dx][Dy] == '+') {
	if (Dx == M->Loc.x && Dy == M->Loc.y) {
	  if (isOkDir(M->Last_Dir)) {
	    Translate_Direction(M->Last_Dir, &Dx, &Dy);
	    Move_One_Towards(M, &Tp, M->Loc.x + Dx * 2, M->Loc.y + Dy * 2);
	  }
	  if (Tp.Move_at_all)
	    I = Max_Doors + 1; /* Exit Loop */
	  else {
	    Move_One_Towards(M, &Tp, Player.Loc.x, Player.Loc.y);
	    if (Tp.Move_at_all) {
	      Tp.Tx = Player.Loc.x;
	      Tp.Ty = Player.Loc.y;
	      I = Max_Doors + 1; /* Exit Loop */
	    }
	  }
	} else {
	  Ndist = Distance(Dx, Dy, Player.Loc.x, Player.Loc.y);
	  if ((Ndist <= Tp.Dist) == Tp.Towards) {
	    Tp.Tx = Dx;
	    Tp.Ty = Dy;
	    Tp.Dist = Ndist;
	    Tp.Move_at_all = true;
	  }
	}
      }
      I++;
      if (Tp.Move_at_all)
	Found_Door = true;
    }
    if (Found_Door)
      Move_One_Towards(M, &Tp, Tp.Tx, Tp.Ty);
    if (Tp.Move_at_all) {
      M->Last_Dir = Delta_Dir[Tp.Tx - M->Loc.x + 1][Tp.Ty - M->Loc.y + 1];
      if (logfp)
	fprintf(logfp, "Diff Room: moving %c from (%d,%d) to (%d,%d) delta %c(%d,%d)\n",
		Monster[M->Index].Name, M->Loc.x, M->Loc.y,
		Tp.Tx, Tp.Ty, M->Last_Dir,
		Tp.Tx - M->Loc.x, Tp.Ty - M->Loc.y);
      Mon_Move(M, Tp.Tx, Tp.Ty);
      if (World.S_World[M->Loc.x][M->Loc.y] == '+') {
	M->Last_Dir = '5';
	if (logfp)
	  fprintf(logfp, "Reached door %c\n", Monster[M->Index].Name);
      }
    }
  } /* #70 in a different room */ /* #70 End of add */
} /* Towards_Player */

bool Can_Attack(Loc_Type L) {
  return((abs(L.x - Player.Loc.x) <= 1) &&
	 (abs(L.y - Player.Loc.y) <= 1) &&
	 (Player.Eaten_count == 0));
} /* Can_Attack */

void Move_monsters(Mon_Ptr M) {
  bool M_changed_speed,P_changed_speed,Go_again;
  Mon_Ptr NextM;		/* #70 */

  P_changed_speed = false;
  /* With Player */
  if (Player.Speed_count != 0) {
    if (Player.Speed_count < 0) {
      Player.Speed_count = (-Player.Speed_count) + 6 + Die(4);
      P_changed_speed = true;
    } else {
      Player.Speed_count--;
      if (Player.Speed_count == 0) {
	Player.Speed = 2;
	Echo("You feel normal again");
	P_changed_speed = true;
      }
    }
  }
  while (M) {
    /* With M^ */
    NextM = M->Next;		/* #70 */
    M_changed_speed = false;
    if (M->Speed_count != 0) {
      if (M->Speed_count < 0) {
	M->Speed_count = (-M->Speed_count) + 6 + Die(4);
	M_changed_speed = true;
      } else {
	M->Speed_count--;
	if (M->Speed_count == 0) {
	  M->Speed = 2;
	  M_changed_speed = true;
	}
      }
    }
    if (P_changed_speed || M_changed_speed) {
      if (Player.Speed == M->Speed)
	M->Who_first = 0;
      else if (Player.Speed < M->Speed)
	M->Who_first = -2;
      else
	M->Who_first = 2;
    }
    if (M->Who_first == 2)
      M->Who_first = 1;
    else
      do {
	if (M->Who_first != 0) {
	  if (M->Who_first == 1)
	    M->Who_first = 2;
	  else if (M->Who_first == -2)
	    M->Who_first = -1;
	  else
	    M->Who_first = -2;
	}
	Go_again = (M->Who_first == -1);
	if (M->Awake) {
	  if (M->Paralyzed_count > 0)
	    M->Paralyzed_count--;
	  else if (M->Index == m_crypt ||
		   M->Index == m_fungi ||
		   M->Index == m_mimic) {
	    if (M->Confused_count > 0) {
	      M->Confused_count--;
	      if (Die(8) == 1 && Can_Attack(M->Loc))
		Hurt_Player(&M);
	    } else {
	      if (Can_Attack(M->Loc))
		Hurt_Player(&M);
	    }
	  } else if (M->Confused_count > 0) {
	    Random_Move(M);
	    M->Confused_count--;
	  } else if (Scare_count > 0) {
	    Scare_count--;
	    Towards_Player(M, false);
	  } else if (Has_on_ring(r_invis) && (Die(10) > 7))
	    Random_Move(M);
	  else if (Can_Attack(M->Loc)) {
	    if ((M->Index == m_blind && Player.Blind_count && Die(5) == 1))
	      Random_Move(M);
	    else if ((M->Index == m_bat ||
		      M->Index == m_invis ||
		      M->Index == m_phantom) &&
		     Die(5) == 1)
	      Random_Move(M);
	    else
	      Hurt_Player(&M);
	  } else
	    Towards_Player(M, true);
	} /* #70 If Awake */
	if (M == NULL || Dead)	/* #70 */
	  Go_again = false;	/* #60 */
      } while (Go_again);
    M = NextM;			/* #70 */
  }
} /* Move_monsters */

#if 0
Procedure Create_file (Name : Long_string; Prot : String8) {
  Filename : Long_string;
  Overwrite : Boolean;
  I,J : Integer;

  Filename = Name;
  I = 80;
  While (Ord(Name[I]) == 0) Do I = I - 1;
  Overwrite = true;
  Write(tty,'Creating ');
  JSYS(76B;-1:Filename); /* PSOUT */
  Writeln(tty);
  Reset(F,Filename,'/D/F/O/I',[14]); /* no jobwide logical names */
  If Erstat(F) == 0
    {
      Writeln(tty,'File already exists; retaining old version.');
      Overwrite = false
    }
  Close(F);
  For J = 1 to 8
    Filename[I+J] = Prot[J];
  If Overwrite
    {
      Rewrite(F,Filename,'/D/F/O',[14]); /* no jobwide logical names */
      If Erstat(F) != 0 Then /* any errors? */
	Writeln(tty,'I/O error when creating file, file not created.');
      Close(F)
    }
} /* Create_file */

Procedure Perhaps_Save {
  I, J : Integer;
  Ch : Char;

  For J = Real_Y_Orig to Real_Max_Y
    {
      World.Lines[J] = true;
      For I = Real_X_Orig to Real_Max_X
	World.Screen[j,i] = ' '
    }
  Change_Stats = [];
  Scr_Text(3,'A large cloud of green smoke appears in front of you.  It clears away');
  Scr_Text(4,'to reveal a tall wizard, clothed in grey.  He fixes you with a steely');
  Scr_Text(5,'glare and declares, "The average of load is too high."  With that he');
  Scr_Text(6,'makes a single pass over you with his hands, and everything around you');
  Scr_Text(7,'fades away into a grey nothingness.');
  Redisplay;
  Empty_Echo = false;
  Echo("Would you like to save your game so far?");
  Move_To_Echo();
  do {
    Ch = Comand();
    If (Ch in ['n','N']) Then /* #59 */
      {
	Empty_Echo = true;
	Echo("Are you sure?");
	Move_To_Echo();
	Repeat
	  Ch = Comand()
	Until (Ch In ['y','Y','n','N']);
	If (Ch in ['y','Y'])
	  Ch = 'N'
	Else
	  {
	    Ch = ' ';
	    Empty_Echo = true;
	    Echo("Would you like to save your game so far?");
	    Move_To_Echo();
	  }
      }
  } Until (Ch In ['y','Y','n','N']);
  If (Ch In ['y','Y'])
    Save_Game
  Else
    {
      Quit_game = true;
      Killer = ' ';
      Want_scores = false;
    }
} /* Perhaps_Save */
#endif

void Center(char *strP, char *centerP) {
  int I,Len;

  Len = (25 - strlen(centerP)) / 2;
  for (I = 0; I < Len; ++I)
    strP[I] = SPACE;
  strP[Len] = '\0';
  strcat(strP, centerP);
} /* Center */

void Bury_Player() {		/* #66 */
  Name_string Pname,Monstr1,Monstr2,Goldstr;
  Long_string Killstr,tmp;
  String5 An;
  int I,J;

  Center(Pname, Player.Name);
  Monstr1[0] = '\0';
  Monstr2[0] = '\0';
  Goldstr[0] = '\0';
  if (Player.Gold > 0) {
    sprintf(tmp, "Score: %d g.p.", Player.Gold);
    Center(Goldstr, tmp);
  }
  Write_Killer(Killstr, Killer);
  I = strlen(Killstr);
  if (I > 24) {			/* #71 was 25 */
    An[0] = Killstr[11];     /* #67 evil stuff, I know, but it works */
    An[1] = Killstr[12];      /* isn''t that what they always says? */
    An[2] = '\0';
    if (!strcmp(An, "an"))
      J = 14;
    else if (!strcmp(An, "a "))
      J = 13;
    else
      J = 11;
    strncpy(tmp, &Killstr[J], 25); /* #71 bogus */
    tmp[26] = '\0';
    Center(Monstr2, tmp);
    Killstr[--J] = '\0';
  }
  strncpy(tmp, &Killstr[1], 25); /* #71 completely bogus */
  Center(Monstr1, tmp);

  clear();
  StartText();
  AddText("            -----------------------");
  AddText("           /         REST          \\");
  AddText("          /           IN            \\");
  AddText("         /           PEACE           \\");
  AddText("         |             *             |\"");
  sprintf(tmp, "         | %-25s |\"", Pname);
  AddText(tmp);
  AddText("         |             *             |\"");
  sprintf(tmp, "         | %-25s |\"", Monstr1);
  AddText(tmp);
  sprintf(tmp, "         | %-25s |\"", Monstr2);
  AddText(tmp);
  sprintf(tmp, "         | %-25s |\"", Goldstr);
  AddText(tmp);
  AddText("________)\\\\_//)/)\\|//|(_\\\\|)(/_)//\\|()//_________");

  Player_Move = (Wait_For_Space(true) ? Space : CHDEL);
} /* Bury_Player */

int Ring_Usage(Obj_Ptr P) {
  if (P)
    switch (P->Index) {
    case r_invis:
    case r_regen: return 1;
    case r_digest: return -1;
    case r_vampiric:
    case r_search:
      if (Die(5) == 5)
	return 1;
    }
  return 0;
} /* Ring_Usage */

Q_Reason Play_The_Game() {	/* #55 */
  Mon_Ptr P;
  bool Can_Move;
  int Last_Food;
  Hand_Type Hand;
  Mon_Ptr New_Mon;		/* #55 */

  do {
    /* See if he awakes from a hunger faint */
    Can_Move = true;
    if (Player.Faint_count > 0) {
      Player.Faint_count--;
      if (Player.Faint_count == 0 && Player.Sleep_count == 0)
	Echo("You wake up");
      else
	Can_Move = false;
    }
    /* See if he is no longer paralyzed */
    if (Player.Paralyzed_count > 0) {
      Player.Paralyzed_count--;
      if (Player.Paralyzed_count == 0)
	Echo("You can move again");
      else
	Can_Move = false;
    }
    /* See if he wakes up from a sleep */
    if (Player.Sleep_count > 0) {
      Player.Sleep_count--;
      if (Player.Sleep_count == 0 && Player.Faint_count == 0)
	Echo("You wake up");
      else
	Can_Move = false;
    }
    /* See if he is un-transfixed */
    if (Player.Fixed_count > 0) {
      Player.Fixed_count--;
      if (Player.Fixed_count == 0)
	Echo("You can move again");
      else
	Can_Move = false;
    }
    /* See if he gets out of a beartrap */
    if (Player.Trapped_count > 0)
      if (Can_Move) {
	Player.Trapped_count--;
	if (Player.Trapped_count == 0) {
	  if (Switches.Terse_swi)
	    Echo("You free yourself");
	  else
	    Echo("You pry yourself from the jaws of the beartrap");
	} else
	  Can_Move = false;
      }
    if (Can_Move)
      Do_Player();

    /* Handle Detect_Monsters */
    if (Player.SeeMon_count > 0) {
      Player.SeeMon_count--;
      if (Player.SeeMon_count == 0) {
	P = World.Monsters;
	while (P) {
	  World.Seeable[P->Loc.x][P->Loc.y] = false;
	  P = P->Next;
	}
	Player_Appears();
      }
    }
    /* Handle confusion */
    if (Player.Confused_count > 0) {
      Player.Confused_count--;
      if (Player.Confused_count == 0)
	Echo("You feel less confused now");
    }
    /* Handle blindness */
    if (Player.Blind_count > 0) {
      Player.Blind_count--;
      if (Player.Blind_count == 0) {
	if (Player.Eaten_count)
	  Player.Blind_count = 1; /* #71 what a hack */
	else
	  No_more_blindness();
      }
    }
    /* Handle see invisibility */
    if (Player.Invis_count > 0)
      Player.Invis_count--;

    /* Generate new monsters */
    /* With World */
    if (World.Num_mons < World.Max_mons)
      if (Die(100) == 1) {
	Gen_monster(World.Level, World.Room_array[Player.Loc.x][Player.Loc.y],
		    &New_Mon, true);
	Place_Monster(New_Mon);
      }

    Last_Food = Player.Last_meal;
    Player.Last_meal += Player.Speed +
      Ring_Usage(Player.Cur_Ring[Left_H]) +
      Ring_Usage(Player.Cur_Ring[Right_H]);

    if (Player.Last_meal >= Hungry_Meal && Last_Food < Hungry_Meal) {
      Change_stats |= S_Bottom;
      Echo("You are getting hungry");
    } else if (Player.Last_meal >= Weak_Meal && Last_Food < Weak_Meal) {
      Change_stats |= S_Bottom;
      Echo("You are beginning to feel light-headed");
    } else if (Player.Last_meal >= Fainting_Meal &&
	       Player.Faint_count == 0)
      if (Die(7) == 1) {
	Valid_Command = false;
	F_temp = false;
	Player.Faint_count = Die(4) + 5;
	Change_stats |= S_Bottom;
	if (! Switches.Terse_swi)
	  Echo("You have passed out from hunger!");
	else
	  Echo("You faint");
      }

    /* Does the player get healed? */
    /* With Player Do */
    if (Player.Trapped_count == 0) /* #57 optimize slightly */
      if (Player.Paralyzed_count == 0)
	if (Player.Fixed_count == 0) {
	  Player.Heal_count++;
	  if (Player.Level < 13) { /* #68 */
	    for (Hand = Left_H; Hand <= Right_H; ++Hand)
	      if (Player.Cur_Ring[Hand])
		if (Player.Cur_Ring[Hand]->Index == r_regen)
		  Player.Heal_count += (13 - Player.Level);
	    while (Player.Heal_count >= (13 - Player.Level)) {
	      Player.Heal_count -= (13 - Player.Level);
	      if (Player.HP < Player.Max_HP) {
		Player.HP++;
		Change_stats |= S_Bottom;
	      }
	    }
	  }
	}

    if (Player.Eaten_count > 0) {
      Player.HP -= Player.HP / Player.Eaten_count;
      Player.Eaten_count--;
      if (Player.Eaten_count == 0 || Player.HP <= 0) {
	Dead = true;		/* They lose! */
	Killer = 'P';
	if (! Switches.Terse_swi)
	  Echo("The purple worm has digested you");
	else
	  Echo("You are digested");
	if (! Switches.Terse_swi)
	  Echo("And, thus, you have lost all desire to find the Amulet of Yendor");
      } else
	Change_stats |= S_Bottom;
    }

#if 0
    if (Change_stats && !Valid_Command) {
      /*      if (Game_Check) */
      If Not_Staffer
	    Perhaps_Save
      }
#endif
    if (! (Dead || Quit_game)) {
      Update_Screen();		/* Show what the player did */
      Move_monsters(World.Monsters); /* Move the icky-bobs */
      if (! Dead)
	Update_Screen();	/* Show what THEY did */
    }
  } while (! (Dead || Quit_game));
  if (Dead) {
    Echo("[Press space to continue, delete to stop] "); /* #66 */
    Move_To_Echo();
    do {
      Player_Move = Comand();
    } while (Player_Move != ' ' &&
	     Player_Move != '0' &&
	     Player_Move != CHDEL);
  }
  if (Quit_game) {
    if (Saved)
      return Saved_R;
    else
      return Quit_R;
  } else if (Killer == '$')	/* #66 */
    return Winner_R;
  else if (Killer != ' ') {
    Player.Gold -= (Player.Gold / 20);
    return Died_R;
  }
  return Quit_R;		/* #71 ??? */
} /* Play_The_Game */

#if 0
Procedure Do_setup { /* #62 Many changes to this procedure */
  More : Boolean;

  Init_staffy('ROGUE',Bug_Add,Files); /* #62 */
  Create_file(Files.Score^,';P776060');
  Reset(F,Files.Score^,'/d/f/o/i');
  Close(F); /* to make reference date non-zero */
  Create_file(Files.Names^,';P776060');
  Create_file(Files.Log^,';P776464');
  Create_File(Files.Message^,';P774040'); /* #57 */
  With Files
    {
      Fix_String(Log^);
      Fix_String(Message^);
      Fix_String(Names^);
      Fix_String(Score^)
    }
  Writeln(tty,'Saving as ROGUE.EXE');
  Setup = false;
  Save_self(Rogue_version,Rogue_Update,Rogue_edit) /* #50 */
} /* Do_Setup */
#endif

void First_Screen() {	/* #57 changed a lot */

#if 0
  Displayed = Not_Staffer;
  If Displayed
    {
      Type_Version;
      Writeln(tty);
      Writeln(tty,'WARNING!  ECL ROGUE is an extremely time-consuming game to run.');
      Writeln(tty,'          If you are low on funds, you should not play.');
      Writeln(tty,'          Please have consideration for those trying to do work.');
      Writeln(tty);
    }
  Reset(F,Files.Message^,'/D/F/O',[14]);
  If (Erstat(F) == 0B)
    If Not EOF(F)
      {
	If Not Displayed
	  {
	    Type_Version;
	    Writeln(tty);
	  }
	While Not EOF(F)
	  {
	    Readln(F,Line:Len);
	    Writeln(tty,Line:Len);
	  }
	Displayed = true;
      }
  Reset(F,'Rogue.Scores','/D/F/O/I',[14]);
  If (Erstat(F) != 0)
    {
      If Not Displayed
	Type_Version;
      Displayed = true;
    }
  If Displayed
    Writeln(tty);
  If Displayed
    {
      Write(tty,'Report ECL ROGUE bugs via mail to ');
      JSYS(76B;-1:Bug_Add); /* PSOUT */
      Writeln(tty,'.');
      Writeln(tty,'Be specific about the errors, and save the game if possible.');
      DCA(1,24);
      Write(tty,'[Type anything to continue]');
      Ch = Comand();
      Cls;
    }
#endif

  Empty_Echo = true;
  Echo_Init();
  StartText();
  sprintf(F, "Just a moment while I dig the dungeon, %s", Player.Name);
  AddText(Echo_Str);
  refresh();
  Second_Init();		/* #63 */
  New_Place_Player();
  Player_Appears();
  /* Empty_Echo = true; ??? */
  Update_Screen();
  Echo("Welcome to ECL Rogue -- type \"?\" for help");
} /* First_Screen */

/* The MAIN Begin */
int main(int argc, char *argv[]) {
  bool rstat = false;

  if (argc == 2 && !strcmp(argv[1], "-s")) {
    rstat = true;
  } else if (argc > 1) {
    fprintf(stderr, "usage: rogue [-s]\n");
    exit(1);
  }

#if 0
  If Setup
    Do_Setup;
  Else If Not Virgin
    Writeln(tty,'?ROGUE: May not be restarted');
  Else If NoPlay Then /* #47 can he play? */
    {
      Writeln(tty,'?ROGUE: The ROGUE-Master has denied you access.');
      Writeln(tty,'        Contact the ROGUE-Master for further obfuscation.');
    }
  Else If (Game_Check && Not Staffy) Then /* #57 */
    {
      Writeln(tty,'I''m terribly sorry, but the Dungeon of Doom is closed.');
      Writeln(tty,'Only wizards are permitted within the dungeon right now.');
      Writeln(tty,'Try again when there are fewer lusers on the system.');
    }
  Else;				/* la */
#endif

  /* begin to play */

  First_Init();		/* #63 */
  Rdinit();

  if (rstat) {
    Player.Gold = -1;

    Show_Scores(rstat);

    refresh();
    echo();
    nocbreak();
    endwin();

    exit(0);
  }

#if 0
  If Name_check
	Begin /* This is the game portion */
	  LogIni;
	  Cls;
	  Not_Staffer = Not Staffy;
	  If Rescan(R_file_name) Then /* #63 */
	    If Restore_Game
	      Reason = Saved_R
	    Else
	      Reason = Quit_R
	  Else
	    Reason = Died_R;
	  If (Reason != Quit_R)
	    {
	      If (Reason == Died_R)
		/* #71 these brackets are bogus */
		}
#endif
	  First_Screen();	/* #63 */
	  Reason = Play_The_Game(); /* #55 */
	  clear();
#if 0
	  Logplayer(Files.Log^,Reason); /* #49,#55 */
#endif
	  if ((Player_Move != CHDEL && Switches.Tomb_swi &&
	       Reason == Died_R))
	    Bury_Player();	/* #66 */

	  if ((! Saved) && Want_scores)
	    Show_Scores(false);
#if 0
  Else
    {
	    DeInterrupts
	      } /* This is the game portion */
      Else
	{
	  Deinterrupts; /* #63 */
	  Writeln(tty,'Your name is already in use.  Please choose another.');
	}
      Restty; /* #49 Put in right place */
} /* begin to play */
#endif

  refresh();
  echo();
/*  noraw(); */
nocbreak();
  endwin();
  if (logfp)
    fclose(logfp);
  exit(0);
} /* of the greatest achievement of Western Civilization */
