/*
 *   file: conv.c
 *   date: 11/12/2014
 *   auth: trickyloki3
 * github: https://github.com/trickyloki3
 *  email: tricky.loki3@gmail.com
 */
#include "api.h"
#include "db.h"
#include "load.h"
#include "util.h"
#include "script.h"

int main(int argc, char * argv[]) {
	if(argc >= 2) {
		if(ncs_strcmp("all",argv[1]) == 0)
			global_mode = (ncs_strcmp(argv[1],"rathena") == 0) ? RATHENA : 
						  (((ncs_strcmp(argv[1],"eathena") == 0) ? EATHENA : 
						  ((ncs_strcmp(argv[1],"hercules") == 0) ? HERCULES : -1)));
		else
			global_mode = 0x7;

		if(global_mode != RATHENA || global_mode != EATHENA || global_mode != HERCULES || global_mode != 0x7)
			exit_abt("invalid database type; only 'eathena', 'rathena', 'hercules', or 'all' is supported.");

		struct lt_db_t * db = init_db("athena.db");
		if(global_mode & EATHENA) {
				load_db_t * db5 = load("eadb/mob_db.txt", trim_numeric, load_general, ea_mob_load);
				load_db_t * db8 = load("eadb/skill_db.txt", trim_numeric, load_general, skill_load);
				load_db_t * db11 = load("eadb/produce_db.txt", trim_numeric, load_general, produce_load);
				load_db_t * db14 = load("eadb/mercenary_db.txt", trim_numeric, load_general, merc_load);
				load_db_t * db17 = load("eadb/pet_db.txt", trim_numeric, load_general, pet_load);
				load_db_t * db20 = load("eadb/item_db.txt", trim_numeric, load_general, ea_item_load);
				load_db_t * db22 = load("eadb/const.txt", trim_general, load_general, const_load);
				ea_load_mob(db, db->ea_mob_insert, db5->db, db5->size);
				load_skill(db, db->ea_skill_insert, db8->db, db8->size);
				load_prod(db, db->ea_prod_insert, db11->db, db11->size);
				load_merc(db, db->ea_merc_insert, db14->db, db14->size);
				load_pet(db, db->ea_pet_insert, db17->db, db17->size);
				load_ea_item(db, db20->db, db20->size);
				load_const(db, db->ea_const_insert, db22->db, db22->size);
				db5->dealloc(db5->db, db5->size);
				db8->dealloc(db8->db, db8->size);
				db11->dealloc(db11->db, db11->size);
				db14->dealloc(db14->db, db14->size);
				db17->dealloc(db17->db, db17->size);
				db20->dealloc(db20->db, db20->size);
				db22->dealloc(db22->db, db22->size);
				free(db5);
				free(db8);
				free(db11);
				free(db14);
				free(db17);
				free(db20);
				free(db22);
		}
		if(global_mode & RATHENA) {
			load_db_t * db6 = load("radb/mob_db.txt", trim_numeric, load_general, mob_load);
			load_db_t * db9 = load("radb/skill_db.txt", trim_numeric, load_general, ra_skill_load);
			load_db_t * db12 = load("radb/produce_db.txt", trim_numeric, load_general, ra_produce_load);
			load_db_t * db15 = load("radb/mercenary_db.txt", trim_numeric, load_general, merc_load);
			load_db_t * db18 = load("radb/pet_db.txt", trim_numeric, load_general, pet_load);
			load_db_t * db21 = load("radb/item_db.txt", trim_numeric, load_general, ra_item_load);
			load_db_t * db23 = load("radb/const.txt", trim_general, load_general, const_load);
			load_mob(db, db->ra_mob_insert, db6->db, db6->size);
			ra_load_skill(db, db->ra_skill_insert, db9->db, db9->size);
			ra_load_prod(db, db->ra_prod_insert, db12->db, db12->size);
			load_merc(db, db->ra_merc_insert, db15->db, db15->size);
			load_pet(db, db->ra_pet_insert, db18->db, db18->size);
			load_ra_item(db, db21->db, db21->size);
			load_const(db, db->ra_const_insert, db23->db, db23->size);
			db6->dealloc(db6->db, db6->size);
			db9->dealloc(db9->db, db9->size);
			db12->dealloc(db12->db, db12->size);
			db15->dealloc(db15->db, db15->size);
			db18->dealloc(db18->db, db18->size);
			db21->dealloc(db21->db, db21->size);
			db23->dealloc(db23->db, db23->size);
			free(db6);
			free(db9);
			free(db12);
			free(db15);
			free(db18);
			free(db21);
			free(db23);
		}
		if(global_mode & HERCULES) {
			load_db_t * db7 = load("hedb/mob_db.txt", trim_numeric, load_general, mob_load);
			load_db_t * db10 = load("hedb/skill_db.txt", trim_numeric, load_general, skill_load);
			load_db_t * db13 = load("hedb/produce_db.txt", trim_numeric, load_general, produce_load);
			load_db_t * db16 = load("hedb/mercenary_db.txt", trim_numeric, load_general, merc_load);
			load_db_t * db19 = load("hedb/pet_db.txt", trim_numeric, load_general, pet_load);
			load_db_t * db24 = load("hedb/const.txt", trim_general, load_general, const_load);
			load_mob(db, db->he_mob_insert, db7->db, db7->size);
			load_skill(db, db->he_skill_insert, db10->db, db10->size);
			load_prod(db, db->he_prod_insert, db13->db, db13->size);
			load_merc(db, db->he_merc_insert, db16->db, db16->size);
			load_pet(db, db->he_pet_insert, db19->db, db19->size);
			load_const(db, db->he_const_insert, db24->db, db24->size);
			db7->dealloc(db7->db, db7->size);
			db10->dealloc(db10->db, db10->size);
			db13->dealloc(db13->db, db13->size);
			db16->dealloc(db16->db, db16->size);
			db19->dealloc(db19->db, db19->size);
			db24->dealloc(db24->db, db24->size);
			free(db7);
			free(db10);
			free(db13);
			free(db16);
			free(db19);
			free(db24);
		}

		/* load compiler databases */
		load_db_t * db1 = load("res/item_bonus.txt", trim_alpha, load_general, bonus_load);
		load_db_t * db2 = load("res/status_db.txt", trim_numeric, load_general, status_load);
		load_db_t * db3 = load("res/var_db.txt", trim_numeric, load_general, var_load);
		load_db_t * db4 = load("res/block_db.txt", trim_numeric, load_general, block_load);
		load_bonus(db, db->bonus_insert, db1->db, db1->size);
		load_status(db, db->status_insert, db2->db, db2->size);
		load_var(db, db->var_insert, db3->db, db3->size);
		load_block(db, db->block_insert, db4->db, db4->size);
		db1->dealloc(db1->db, db1->size);
		db2->dealloc(db2->db, db2->size);
		db3->dealloc(db3->db, db3->size);
		db4->dealloc(db4->db, db4->size);
		free(db1);
		free(db2);
		free(db3);
		free(db4);
		deit_db(db);
	} else {
		exit_buf("syntax '%s [eathena | rathena | hercules | all]'", argv[0]);
	}
	exit(EXIT_SUCCESS);
}