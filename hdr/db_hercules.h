/*
 *   file: db_hercules.h
 *   date: 03/01/2015
 *   auth: trickyloki3
 * github: https://github.com/trickyloki3
 *  email: tricky.loki3@gmail.com
 */
#ifndef DB_HERCULES_H
#define DB_HERCULES_H
 	#include "load.h"
 	#include "util.h"
 	#include "setting.h"
 	#include "libconfig.h"
 	#include "sqlite3.h"

 	/* hercules database type definitions 
	 * -----------------------------------------
	 * type name 	- 	type reference
	 * -----------------------------------------
	 * item_he 			- 	hercules item database
	 * mob_he 			- 	hercules mob database 
	 * skill_he 		- 	hercules skill database 
	 * produce_he		- 	hercules produce database
	 * mercenary_he 	-	hercules mecenary database
	 * pet_he			-	hercules pet database
	 * const_he 		- 	hercules constant database
	 */

 	/* database record counts */
 	#define MOB_HE_FIELD_COUNT				57
	#define SKILL_HE_FIELD_COUNT 			17
	#define MERCENARY_HE_FIELD_COUNT		26
	#define PET_HE_FIELD_COUNT				22

	/* constant to index equip array */
	#define EQUIP_MIN					0
	#define EQUIP_MAX					1
	#define EQUIP_TOTAL					2

	/* constant to index trade array */
	#define TRADE_OVERRIDE 				0
	#define TRADE_NODROP				1
	#define TRADE_NOTRADE				2
	#define TRADE_PARTNEROVERRIDE		3
	#define TRADE_NOSELLTONPC			4
	#define TRADE_NOCART				5
	#define TRADE_NOSTORAGE 			6
	#define TRADE_NOGSTORAGE			7
	#define TRADE_NOMAIL				8
	#define TRADE_NOAUCTION				9
	#define TRADE_TOTAL					10

	/* constant to index nouse array */
	#define NOUSE_OVERRIDE				0
	#define NOUSE_SITTING				1
	#define NOUSE_TOTAL					2

	/* constant to index stack array */
	#define STACK_AMOUNT				0
	#define STACK_TYPE					1
	#define STACK_TOTAL					2

	typedef struct {
		int id;
		char aegis[MAX_NAME_SIZE];
		char name[MAX_NAME_SIZE];
		int type;
		int buy;
		int sell;
		int weight;
		int atk;
		int matk;
		int def;
		int range;
		int slots;
		int job;
		int upper;
		int gender;
		int loc;
		int weaponlv;
		int equiplv[EQUIP_TOTAL];
		int refine;
		int view;
		int bindonequip;
		int buyingstore;
		int delay;
		int trade[TRADE_TOTAL];
		int nouse[NOUSE_TOTAL];
		int stack[STACK_TOTAL];
		int sprite;
		char script[MAX_SCRIPT_SIZE];
		char onequipscript[MAX_SCRIPT_SIZE];
		char onunequipscript[MAX_SCRIPT_SIZE];
	} item_he;

	typedef struct {
		int id;
		char sprite[MAX_NAME_SIZE];
		char kro[MAX_NAME_SIZE];
		char iro[MAX_NAME_SIZE];
		int lv;
		int hp;
		int sp;
		int exp;
		int jexp;
		int range;
		int atk1;
		int atk2;
		int def;
		int mdef;
		int str;
		int agi;
		int vit;
		int intr;
		int dex;
		int luk;
		int range2;
		int range3;
		int scale;
		int race;
		int element;
		int mode;
		int speed;
		int adelay;
		int amotion;
		int dmotion;
		int mexp;
		int mvp1id;
		int mvp1per;
		int mvp2id;
		int mvp2per;
		int mvp3id;
		int mvp3per;
		int drop1id;
		int drop1per;
		int drop2id;
		int drop2per;
		int drop3id;
		int drop3per;
		int drop4id;
		int drop4per;
		int drop5id;
		int drop5per;
		int drop6id;
		int drop6per;
		int drop7id;
		int drop7per;
		int drop8id;
		int drop8per;
		int drop9id;
		int drop9per;
		int dropcardid;
		int dropcardper;
	} mob_he;

	typedef struct {
		int id;
		varlist range;
		int hit;
		int inf;
		varlist element;
		int nk;
		varlist splash;
		int maxlv;
		varlist hit_amount;
		char cast_cancel[MAX_NAME_SIZE];		/* 'yes' or 'no' string */
		int cast_def_reduce_rate;
		int inf2;
		varlist maxcount;
		char type[MAX_NAME_SIZE];				/* 'none', 'weapon', 'magic', 'misc' */
		varlist blow_count;
		char name[MAX_NAME_SIZE];
		char desc[MAX_NAME_SIZE];
	} skill_he;

	typedef struct  {
		int item_id;
		int item_lv;
		int skill_id;
		int skill_lv;
		int item_id_req[MAX_INGREDIENT];
		int item_amount_req[MAX_INGREDIENT];
		int ingredient_count;
	} produce_he;

	typedef struct {
		int id;
		char sprite[MAX_NAME_SIZE];
		char name[MAX_NAME_SIZE];
		int lv;
		int hp;
		int sp;
		int range1;
		int atk1;
		int atk2;
		int def;
		int mdef;
		int str;
		int agi;
		int vit;
		int intr;
		int dex;
		int luk;
		int range2;
		int range3;
		int scale;
		int race;
		int element;
		int speed;
		int adelay;
		int amotion;
		int dmotion;
	} mercenary_he;

	typedef struct {
		int mob_id;
		char name[MAX_NAME_SIZE];
		char jname[MAX_NAME_SIZE];
		int lure_id;
		int egg_id;
		int equip_id;
		int food_id;
		int fullness;
		int hungry_delay;
		int r_hungry;
		int r_full;
		int intimate;
		int die;
		int capture;
		int speed;
		int s_performance;
		int talk_convert;
		int attack_rate;
		int defence_attack_rate;
		int change_target_rate;
		char pet_script[MAX_SCRIPT_SIZE];
		char loyal_script[MAX_SCRIPT_SIZE];
	} pet_he;

	typedef struct {
		char name[MAX_NAME_SIZE];
		int value;
		int type;
	} const_he;

	/* hercules shares the same database format as eathena and rathena
	 * but who knows what they'll change completely, better keep separate */
	int load_he_item(const char * file_name, native_t * native);

	/* hercules native database loading */
	extern native_config_t load_he_native[HERCULES_DB_COUNT];
	int mob_he_load(void * db, int row, int col, char * val);
	int skill_he_load(void * db, int row, int col, char * val);
	int produce_he_load(void * db, int row, int col, char * val);
	int mercenary_he_load(void * db, int row, int col, char * val);
	int pet_he_load(void * db, int row, int col, char * val);
	int const_he_load(void * db, int row, int col, char * val);

	/* hercules auxiliary */
	int load_hercules_database(const char * hercules_path);

	/* hercules sqlite3 database interface */
	#define hercules_database_sql 	"DROP TABLE IF EXISTS item_he;"																\
									"DROP TABLE IF EXISTS mob_he;"																\
									"DROP TABLE IF EXISTS skill_he;"															\
									"DROP TABLE IF EXISTS produce_he;"															\
									"DROP TABLE IF EXISTS mercenary_he;"														\
									"DROP TABLE IF EXISTS pet_he;"																\
									"DROP TABLE IF EXISTS const_he;"															\
									""																							\
									"CREATE TABLE IF NOT EXISTS item_he(" 														\
									"Id INTEGER PRIMARY KEY, AegisName TEXT, Name TEXT, Type INTEGER, "							\
									"Buy INTEGER, Sell INTEGER, Weight INTEGER, Atk INTEGER, Matk INTEGER, " 					\
									"Def INTEGER, Range INTEGER, Slots INTEGER, Job INTEGER, Upper INTEGER, " 					\
									"Gender INTEGER, Loc INTEGER, WeaponLv INTEGER, EquipLvMin INTEGER, " 						\
									"EquipLvMax INTEGER, Refine INTEGER, View INTEGER, BindOnEquip INTEGER, " 					\
									"BuyingStore INTEGER, Delay INTEGER, override INTEGER, nodrop INTEGER, " 					\
									"notrade INTEGER, partneroverride INTEGER, noselltonpc INTEGER, " 							\
									"nocart INTEGER, nostorage INTEGER, nogstorage INTEGER, nomail INTEGER, " 					\
									"noauction INTEGER, ltoverride INTEGER, sitting INTEGER, StackAmount INTEGER, " 			\
									"StackType INTEGER, Sprite Integer, Script TEXT, OnEquipScript TEXT, " 						\
									"OnUnequipScript TEXT);" 																	\
									""																							\
									"CREATE TABLE IF NOT EXISTS mob_he(" 														\
									"id INTEGER PRIMARY KEY, sprite TEXT, kro TEXT, iro TEXT, " 								\
									"lv INTEGER, hp INTEGER, sp INTEGER, exp INTEGER, jexp INTEGER, " 							\
									"range INTEGER, atk1 INTEGER, atk2 INTEGER, def INTEGER, mdef INTEGER, " 					\
									"str INTEGER, agi INTEGER, vit INTEGER, intr INTEGER, dex INTEGER, " 						\
									"luk INTEGER, range2 INTEGER, range3 INTEGER, scale INTEGER, race INTEGER, " 				\
									"element INTEGER, mode INTEGER, speed INTEGER, adelay INTEGER, amotion INTEGER, " 			\
									"dmotion INTEGER, mexp INTEGER, mvp1id INTEGER, mvp1per INTEGER, " 							\
									"mvp2id INTEGER, mvp2per INTEGER, mvp3id INTEGER, mvp3per INTEGER, drop1id INTEGER, " 		\
									"drop1per INTEGER, drop2id INTEGER, drop2per INTEGER, drop3id INTEGER, drop3per INTEGER, " 	\
									"drop4id INTEGER, drop4per INTEGER, drop5id INTEGER, drop5per INTEGER, drop6id INTEGER, " 	\
									"drop6per INTEGER, drop7id INTEGER, drop7per INTEGER, drop8id INTEGER, drop8per INTEGER, " 	\
									"drop9id INTEGER, drop9per INTEGER, dropcardid INTEGER, dropcardper INTEGER); "				\
									""																							\
									"CREATE TABLE IF NOT EXISTS skill_he(" 														\
									"id INTEGER PRIMARY KEY, range TEXT, hit INTEGER, inf INTEGER, " 							\
									"element TEXT, nk INTEGER, splash TEXT, max INTEGER, hit_amount INTEGER, " 					\
									"cast_cancel TEXT, cast_def_reduce_rate INTEGER, inf2 INTEGER, " 							\
									"maxcount TEXT, type TEXT, blow_count TEXT, name TEXT, desc TEXT);"							\
									""																							\
									"CREATE TABLE IF NOT EXISTS produce_he(" 													\
									"item_id INTEGER PRIMARY KEY, item_lv INTEGER, " 											\
									"req_skill INTEGER, req_skill_lv INTEGER, material TEXT, amount TEXT);"						\
									""																							\
									"CREATE TABLE IF NOT EXISTS mercenary_he(" 													\
									"id INTEGER PRIMARY KEY, sprite TEXT, name TEXT, " 											\
									"lv INTEGER, hp INTEGER, sp INTEGER, range1 INTEGER, " 										\
									"atk1 INTEGER, atk2 INTEGER, def INTEGER, mdef INTEGER, " 									\
									"str INTEGER, agi INTEGER, vit INTEGER, intr INTEGER, " 									\
									"dex INTEGER, luk INTEGER, range2 INTEGER, range3 INTEGER, " 								\
									"scale INTEGER, race INTEGER, element INTEGER, speed INTEGER, " 							\
									"adelay INTEGER, amotion INTEGER, dmotion INTEGER);"										\
									""																							\
									"CREATE TABLE IF NOT EXISTS pet_he(" 														\
									"mob_id INTEGER PRIMARY KEY, pet_name TEXT, pet_jname TEXT, " 								\
									"lure_id INTEGER, egg_id INTEGER, equip_id INTEGER, " 										\
									"food_id INTEGER, fullness INTEGER, hungry_delay INTEGER, " 								\
									"r_hungry INTEGER, r_full INTEGER, intimate INTEGER, " 										\
									"die INTEGER, capture INTEGER, speed INTEGER, " 											\
									"s_performance INTEGER, talk_convert INTEGER, attack_rate INTEGER, " 						\
									"defence_attack_rate INTEGER, change_target_rate INTEGER, pet_script TEXT, " 				\
									"loyal_script TEXT);"																		\
									""																							\
									"CREATE TABLE IF NOT EXISTS const_he(name TEXT, value INTEGER, type INTEGER);"				


	#define item_he_insert 			"INSERT INTO item_he(" 																		\
									"Id, AegisName, Name, Type, Buy, Sell, Weight, Atk, Matk," 									\
									"Def, Range, Slots, Job, Upper, Gender, Loc, WeaponLv, " 									\
									"EquipLvMin, EquipLvMax, Refine, View, BindOnEquip, " 										\
									"BuyingStore, Delay, override, nodrop, notrade, partneroverride, " 							\
									"noselltonpc, nocart, nostorage, nogstorage, nomail, noauction, " 							\
									"ltoverride, sitting, StackAmount, StackType, Sprite, Script, " 							\
									"OnEquipScript, OnUnequipScript) VALUES(" 													\
									"$Id, $AegisName, $Name, $Type, $Buy, $Sell, $Weight, $Atk, $Matk," 						\
									"$Def, $Range, $Slots, $Job, $Upper, $Gender, $Loc, $WeaponLv, " 							\
									"$EquipLvMin, $EquipLvMax, $Refine, $View, $BindOnEquip, " 									\
									"$BuyingStore, $Delay, $override, $nodrop, $notrade, $partneroverride, " 					\
									"$noselltonpc, $nocart, $nostorage, $nogstorage, $nomail, $noauction, " 					\
									"$ltoverride, $sitting, $StackAmount, $StackType, $Sprite, $Script, " 						\
									"$OnEquipScript, $OnUnequipScript);"
	#define mob_he_insert 			"INSERT INTO mob_he VALUES(" 																\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?);"
	#define skill_he_insert 		"INSERT INTO skill_he VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"
	#define produce_he_insert 		"INSERT INTO produce_he VALUES(?, ?, ?, ?, ?, ?);"
	#define mercenary_he_insert 	"INSERT INTO mercenary_he VALUES(" 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 													\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"
	#define pet_he_insert 			"INSERT INTO pet_he VALUES(" 																\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?," 															\
									"?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);" 
	#define const_he_insert			"INSERT INTO const_he VALUES(?, ?, ?);"

	typedef struct db_he_t {
		sqlite3 * db;
		sqlite3_stmt * item_he_sql_insert;
		sqlite3_stmt * mob_he_sql_insert;
		sqlite3_stmt * skill_he_sql_insert;
		sqlite3_stmt * produce_he_sql_insert;
		sqlite3_stmt * mercenary_he_sql_insert;
		sqlite3_stmt * pet_he_sql_insert;
		sqlite3_stmt * const_he_sql_insert;
	} db_he_t;

	/* database loading depends on the path of the database */
	int default_hercules_database(void);
	int create_hercules_database(db_he_t * db, const char * path);
	int finalize_hercules_database(db_he_t * db);
	int item_he_sql_load(db_he_t * db, const char * path);
	int mob_he_sql_load(db_he_t * db, const char * path);
	int skill_he_sql_load(db_he_t * db, const char * path);
	int produce_he_sql_load(db_he_t * db, const char * path);
	int mercenary_he_sql_load(db_he_t * db, const char * path);
	int pet_he_sql_load(db_he_t * db, const char * path);
	int const_he_sql_load(db_he_t * db, const char * path);
#endif
