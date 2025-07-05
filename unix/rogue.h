/* rogue.h */

#ifndef ROGUE_H
#define ROGUE_H 1

/* Constant declarations for ROGUE.

   Gary Craig/Jay Skeer/John Relph/Oscar Erickson, December 1982 */

/* monster index constants */
typedef enum E_Monster {
  m_ant,	m_bat,		m_centaur,
  m_dragon,	m_eye,		m_fungi,
  m_gnoll,	m_hob,		m_invis,
  m_jackal,	m_kobold,	m_lep,
  m_mimic,	m_nymph,	m_orc,
  m_purple,	m_quasit,	m_rust,
  m_snake,	m_troll,	m_umber,
  m_vampire,	m_wraith,	m_xorn,
  m_yeti,	m_zombie,

  m_almiraj,	m_blind,	m_crypt,
  m_death,	m_ettin,	m_flind,
  m_gith,	m_homon,	m_int,
  m_juiblex,	m_kill,		m_larva,
  m_minotaur,	m_norker,	m_owlbear,
  m_phantom,	m_quaggoth,	m_revenant,
  m_sand,	m_tira,		m_umpleby,
  m_vodyanoi,	m_werewolf,	m_xvart,
  m_yulgrin,	m_zallige,

  Max_Monster } E_Monster;	/* Upper and Lower case monsters! */

/* Object index constants */
typedef enum E_Potion {
  p_gold_det,	p_mon_det,	p_magic_det,
  p_reg_str,	p_reg_int,	p_reg_dex,
  p_poison,	p_feeble,	p_fumble,
  p_incr_str,	p_incr_int,	p_inc_dex,
  p_skill,	p_healing,	p_ex_healing,
  p_invis,	p_haste,	p_slow,
  p_blind,	p_confuse,	p_confuse_mon,
  p_sleep,	p_paralysis,	p_nothing,
  p_sustenance, /* #54 */
  Max_Potion } E_Potion;

typedef enum E_Scroll {
  s_armor,	s_weapon,	s_curse,
  s_mapping,	s_identify,	s_genocide,
  s_scare,	s_nothing,	s_teleport,
  s_summon,	s_light,	s_hold,
  Max_Scroll } E_Scroll;

typedef enum E_Wand {
  w_drain,	w_fire,		w_lightning,
  w_cold,	w_light,	w_poly,
  w_tele_to,	w_tele_away,	w_missile,
  w_nothing,	w_striking,	w_slow,
  w_haste,	w_cancel,	w_alchemy,
  w_wonder,	w_paralyze,	w_curing,
  w_search,	w_blunder,
  Max_Wand } E_Wand;		/* #36 */

typedef enum E_Armor {
  a_leather,	a_stud,		a_ring,
  a_scale,	a_chain,	a_splint,
  a_banded,	a_plate,
  Max_Armor } E_Armor;

typedef enum E_Ring {
  r_regen,	r_digest,	r_sustain,
  r_protect,	r_dex,		r_str,
  r_int,	r_see_inv,	r_teleport,
  r_stealth,	r_aggra,	r_search,
  r_incr_dam,	r_resur,	r_vampiric,
  r_invis,	r_decode,
  Max_Ring } E_Ring;

typedef enum E_Weapon {
  wp_two_sword,	wp_long_sword,	wp_dagger,
  wp_sling,	wp_rocks,	wp_crossbow,
  wp_bolts,	wp_bow,		wp_arrows,
  wp_mace,	wp_sil_sword,	wp_sil_arrows,
  Max_Weapon } E_Weapon;

/* Sum of Max_Potion,Max_Scroll,Max_Wand,
   Max_Ring,Max_Weapon,Max_Armor,and
   1 for gold, 2 for food */
#define Max_Treasure (Max_Potion + Max_Scroll + Max_Wand + Max_Ring + Max_Weapon + Max_Armor + 1 + 2)

#define Mon_lo_offset 65
#define Mon_hi_offset 71

typedef enum Trap {
  t_arrow,	t_bear,		t_door,
  t_dart,	t_teleport,
  Max_Trap } Trap;

/* last_constant = 0.0. */

/* 1/Chance of a Cell Being Devoid of room */
#define Chance_Of_No_Room 9
#define Maze_Max_X 3
#define Maze_Max_Y 3
#define Max_Room (Maze_Max_X * Maze_Max_Y)
#define Max_Room_X 24
#define Max_Room_Y 5
#define Min_Room_X 2
#define Min_Room_Y 2
#define Max_Cell_X 26
#define Max_Cell_Y 7

#define Y_Orig_1 0
#define X_Orig_1 0
#define Y_Orig 1
#define X_Orig 1
#define S_Max_X 79
#define S_Max_Y 22
#define S_Max_X_1 80
#define S_Max_Y_1 23

#define Echo_Y 0
#define Echo_X 0
#define Status_Y 22
#define Status_X 0

/* Sum of all the numbers in the chance field of the treasure array */
int Max_Chance;

/* #6 Number of "funny" scroll words */
/* #71 int Max_Word; */

/* The maximum number Of objects player can carry */
#define Max_Item 23

/* turns before fainting */
#define Fainting_Meal 2750

/* turns before feeling weak */
#define Weak_Meal 2600

/* turns before being hungry */
#define Hungry_Meal 2000

/* also, check everywhere this constant is */
#define Not_Another FALSE

/* #54 just For const''s sake */
#define Name_Len 30
/* If this length is changed, many things in extern.mac will change too */

#define Space ' '
#define Spaces '                                                                                '
/* TYPES */

/* #55,#2 */
typedef enum Q_Reason { Quit_R, Saved_R, Died_R, Winner_R } Q_Reason;

typedef char View_Array[3];

typedef char Name_string[Name_Len + 1];

typedef struct Name_rec {
  Name_string Nam;
  int Num;
  struct Name_rec *Next;
} Name_rec, *Nam_ptr; /* #63 */

#define LONG_LEN 80
typedef char Long_string[LONG_LEN];
typedef char String5[5];
typedef char String8[8];

typedef struct Loc_Type {
  int x,y;
} Loc_Type;

typedef enum Obj_Class_Type {
  Amulet_T, Food_T, Ring_T, Wand_T, Scroll_T,
  Potion_T, Armor_T, Weapon_T, Gold_T, All_T } Obj_Class_Type;

typedef enum Action_Type {
  Eat_A, Put_On_A, Zap_A, Read_A, Quaff_A, Wear_A,
  Wield_A, Drop_A, Identify_A, Call_A, Throw_A } Action_Type;

#define S_Top		(1 << 0)
#define S_Bottom	(1 << 1)

typedef struct Monster_Typ {
  int Index;
  int HP;
  bool Awake;
  int Paralyzed_count;
  int Confused_count;
  Loc_Type Loc;
  struct Monster_Typ *Next;
  int Speed;
  int Speed_count;
  int Who_first;
  char Last_Dir;
} Monster_Typ, *Mon_Ptr;

typedef struct Trap_Typ {
  Loc_Type Loc;
  int Chance;
  int Kind;
  struct Trap_Typ *Next;
} Trap_Typ, *Trap_Ptr;

typedef struct Obj_Typ {
  Obj_Class_Type Obj_Typ;
  Loc_Type Loc;
  int Quan;
  int Index;
  int Plus_Hit;
  int Plus_Dam;
  bool Know_magic;
  bool Cursed;
  struct Obj_Typ *Next;
} Obj_Typ, *Obj_Ptr;

typedef struct Treasures {
  int Chance;
  Obj_Class_Type Typ;
  int Index;
} Treasures;

typedef struct Monsters {
  char *Long_Name;		/* #71 Name_string */
  char Name;
  int Hit_Dice;
  int Ac;
  int Th0;
  int Dam;
  int Num;
  char Special;			/* 1..3 */
  int Min_Level;
  int Max_Level;
  int Sleep;
  bool Large;
  int Xpval;
  /* 1's bit = normal, 2's = special */
} Monsters;

typedef struct Potions {
  char *Name;			/* #71 Name_string */
  bool Id;
  bool Called;
  Name_string Desc;
} Potions;

typedef struct Scrolls {
  char *Name;			/* #71 Name_string */
  bool Id;
  bool Called;
  bool Can_ID;
  Name_string Desc;
} Scrolls;

typedef struct Wands {
  char *Name;			/* #71 Name_string */
  bool Id;
  bool Called;
  int Dam;
  int Num;
  bool Is_wand;
  Name_string Desc;
} Wands;

typedef struct Rings {
  char *Name;			/* #71 Name_string */
  bool Id;
  bool Called;
  Name_string Desc;
} Rings;

typedef struct Armors {
  char *Name;			/* #71 Name_string */
  int Ac;
} Armors;

typedef struct Weapons {
  char *Name;			/* #71 Name_string */
  int S_Dam;
  int S_Num;
  int L_Dam;
  int L_Num;
} Weapons;

/* #71 typedef char Descriptions[11]; */

typedef enum Hand_Type { Left_H, Right_H } Hand_Type; /* #49 */

typedef struct Player_Record {
  Obj_Ptr Obj_List;
  Obj_Ptr Cur_Wep;
  Obj_Ptr Cur_Arm;
  Obj_Ptr Cur_Ring[2];		/* Hand_Type #49 */
  int Gold;
  int XP;
  int Level;
  int HP;
  Name_string Name;
  int Max_HP;
  int ST;
  int Max_ST;
  int DX;
  int Max_DX;
  int IQ;
  int Max_IQ;
  int AC;
  int Died_count;
  int SeeMon_count;
  int Faint_count;
  int Confused_count;
  int Blind_count;		/* cannot see */
  int Paralyzed_count;
  int Sleep_count;
  int Trapped_count;
  int Fixed_count;
  int Invis_count;		/* can see invisible things */
  int Last_meal;
  int Heal_count;
  int Eaten_count;
  bool Stuck;
  bool Will_confuse;
  bool Has_amulet;
  int Speed;
  int Speed_count;
  Loc_Type Prev;
  Loc_Type Loc;
} Player_Record;

typedef struct Score_rec {
  int User;
  int Score;
  String5 Day;
  char Killer;
  int Level;
} Score_rec;

typedef Score_rec Score_array[10];

typedef struct Personal_rec {
  int Score;
  Long_string Rest;
} Personal_rec;

typedef Personal_rec Personals[10];

      /* Door numbering system: */
      /* up			*/
      /*      ---1---		*/
      /*      |     |		*/
      /*      4     2		*/
      /*      |     |		*/
      /* down ---3---		*/

typedef enum {
  Door_Up = 0, Door_Right, Door_Down, Door_Left, Max_Doors
} Door_Number;

typedef struct Door_Type {
  Loc_Type Abs_loc;
  int Secret;
} Door_Type;

typedef struct Room_Type {
  int Max_X;
  int Max_Y;
  int Abs_X;
  int Abs_Y;
  bool Light;
  bool Existent;
  bool Seen;
  Door_Type Doors[Max_Doors];
} Room_Type;

/*
  Screen_Array = Array [X_Orig_1..S_Max_X_1,Y_Orig_1..S_Max_Y_1] of Char;
  Bool_Array = Array [X_Orig_1..S_Max_X_1,Y_Orig_1..S_Max_Y_1] of Boolean;
*/

typedef char Screen_Array[S_Max_X_1][S_Max_Y_1];
typedef bool Bool_Array[S_Max_X_1][S_Max_Y_1];

typedef struct World_Rec {
  Mon_Ptr Monsters;
  Obj_Ptr Objs;
  Trap_Ptr Traps;
  int Level;
  int Num_mons;
  int Max_mons;
  Room_Type Rooms[Max_Room];
  Screen_Array S_World;
  Screen_Array Mon;
  Screen_Array Obj;
  int Room_array[S_Max_X_1][S_Max_Y_1];
  Bool_Array Seeable;
  Bool_Array Seen;
} World_Rec;

typedef struct Maze_Cell { 	/* Packed Record? */
  bool U;
  bool Up;
  bool Dn;
  bool Rt;
  bool Lt;
} Maze_Cell;

typedef Maze_Cell Maze_Array[5][5];

/* must be declared this way: don''t change! */
typedef struct Switch_record {
  bool Ask_swi;
  bool Flush_swi;
  bool Jump_swi;
  bool Slow_swi;
  bool Terse_swi;
  bool Turn_swi;
  bool Tomb_swi;		/* #2 */
} Switch_record;

typedef struct FName_Rec {	/* #62 */
  Long_string *Log;
  Long_string *Message;
  Long_string *Names;
  Long_string *Score;
} FName_Rec;

/*
  Fudge_Type = Packed Record Case Boolean Of
		 True : (Int : Integer);
		 False: (Boo : Packed Array[0..35] Of Boolean)
	       End;
*/

/* VARIABLES */

FName_Rec Files;		/* #62 */
World_Rec World;
Player_Record Player;
Name_string Fruit_name;
Name_string Save_file;
Name_string R_File_Name;
/* Bool_Array False_array; */
/*  F : Text; */
/*  Nm : File of Name_rec; */

Long_string Echo_Str;
char *F;

int TextLine;

#if 0
Long_string Nulls;
Long_string Bug_add; /* #57 */
#endif
#define Bug_add "bug-rogue@idiot-dog.com"

Long_string Last_echo[5];

int Amulet_level;
int Seed;
int Blank_message;
int Scare_count;
int Echo_index;
int Echo_point;
int Echo_Pos_X; /* #50 */

char Ctrl_L;
char Killer;
char Player_Move;
char Last_Item;

#if 0
  Wait_chars,OkDirs,Okmons,Resp_chars : Set Of Char; /* #55 */
#endif

bool Okmons[128];		/* simple ASCII truth table */

/* Array[-1..1,-1..1] of Char */

bool Empty_Echo;
bool Want_scores;
bool F_temp;
bool Fast;
bool Dont_Turn;
bool Valid_Command;
bool Do_Done;
bool Moved;
bool Has_Turned;
bool Dead;
bool Quit_game;
bool Saved;
bool Not_Staffer;

Q_Reason Reason;

unsigned int Change_stats;

bool O_Used_list[Max_Room];
bool M_Used_list[Max_Room];

Maze_Array Ct;
Switch_record Switches = {
  true,				/* Ask */
  true,				/* Flush */
  false,			/* Jump */
  false,			/* Slow */
  false,			/* Terse */
  true,				/* Turn */
  true };			/* Tomb */

#define CHNUL '\0'		/* NULL */
#define CHCTC 03		/* C-C */
#define CHBEL 07		/* bell */
#define CHBSP 010		/* backspace */
#define CHTAB 011		/* tab */
#define CHLFD 012		/* LF */
#define CHFFD 014		/* formfeed */
#define CHEOL 015		/* CR */
#define CHCTR 022		/* C-R */
#define CHCTT 024		/* C-T */
#define CHCTU 025		/* C-U */
#define CHCTW 027		/* C-W */
#define CHCTZ 032		/* C-Z */
#define CHESC 033		/* escape */
#define CHDEL 0177		/* delete */

#define SPACE ' '
#define EMPTY '\0'

#define BKSP { getyx(stdscr, iy, ix); if (ix > 0) move(iy, --ix); }

#endif
