#include "api.h"

struct lt_db_t * init_db(const char * filename) {
	int status = 0;
	sqlite3 * db;
	
	struct lt_db_t * lt_db = calloc(1, sizeof(struct lt_db_t));	

	/* create the sqlite3 database */
	status = sqlite3_open_v2(filename, &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
	if(status != SQLITE_OK) exit_abt(sqlite3_errmsg(db));

	/* debugging purposes */
	/*sqlite3_trace(db, trace_db, NULL);*/

	/* item tables */
	sqlite3_exec(db, he_item_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_item_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ea_item_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_item_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_item_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_item_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, he_item_ins, strlen(he_item_ins) + 1, &lt_db->he_item_insert, NULL);
	sqlite3_prepare_v2(db, ea_item_ins, strlen(ea_item_ins) + 1, &lt_db->ea_item_insert, NULL);
	sqlite3_prepare_v2(db, ra_item_ins, strlen(ra_item_ins) + 1, &lt_db->ra_item_insert, NULL);
	assert(lt_db->he_item_insert != NULL);
	assert(lt_db->ea_item_insert != NULL);
	assert(lt_db->ra_item_insert != NULL);

	/* pet tables */
	sqlite3_exec(db, ea_pet_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_pet_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_pet_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_pet_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_pet_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_pet_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, ea_pet_ins, strlen(ea_pet_ins) + 1, &lt_db->ea_pet_insert, NULL);
	sqlite3_prepare_v2(db, ra_pet_ins, strlen(ra_pet_ins) + 1, &lt_db->ra_pet_insert, NULL);
	sqlite3_prepare_v2(db, he_pet_ins, strlen(he_pet_ins) + 1, &lt_db->he_pet_insert, NULL);
	assert(lt_db->ea_pet_insert != NULL);
	assert(lt_db->ra_pet_insert != NULL);
	assert(lt_db->he_pet_insert != NULL);

	/* merc table */
	sqlite3_exec(db, ea_merc_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_merc_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_merc_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_merc_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_merc_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_merc_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, ea_merc_ins, strlen(ea_merc_ins) + 1, &lt_db->ea_merc_insert, NULL);
	sqlite3_prepare_v2(db, ra_merc_ins, strlen(ra_merc_ins) + 1, &lt_db->ra_merc_insert, NULL);
	sqlite3_prepare_v2(db, he_merc_ins, strlen(he_merc_ins) + 1, &lt_db->he_merc_insert, NULL);
	assert(lt_db->ea_merc_insert != NULL);
	assert(lt_db->ra_merc_insert != NULL);
	assert(lt_db->he_merc_insert != NULL);

	/* produce table */
	sqlite3_exec(db, ea_prod_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_prod_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_prod_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_prod_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_prod_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_prod_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, ea_prod_ins, strlen(ea_prod_ins) + 1, &lt_db->ea_prod_insert, NULL);
	sqlite3_prepare_v2(db, ra_prod_ins, strlen(ra_prod_ins) + 1, &lt_db->ra_prod_insert, NULL);
	sqlite3_prepare_v2(db, he_prod_ins, strlen(he_prod_ins) + 1, &lt_db->he_prod_insert, NULL);
	assert(lt_db->ea_prod_insert != NULL);
	assert(lt_db->ra_prod_insert != NULL);
	assert(lt_db->he_prod_insert != NULL);

	/* skill table */
	sqlite3_exec(db, ea_skill_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_skill_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_skill_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_skill_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_skill_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_skill_tbl, NULL, NULL, NULL);	
	sqlite3_prepare_v2(db, ea_skill_ins, strlen(ea_skill_ins) + 1, &lt_db->ea_skill_insert, NULL);
	sqlite3_prepare_v2(db, ra_skill_ins, strlen(ra_skill_ins) + 1, &lt_db->ra_skill_insert, NULL);
	sqlite3_prepare_v2(db, he_skill_ins, strlen(he_skill_ins) + 1, &lt_db->he_skill_insert, NULL);
	assert(lt_db->ea_skill_insert != NULL);
	assert(lt_db->ra_skill_insert != NULL);
	assert(lt_db->he_skill_insert != NULL);

	/* mob table */
	sqlite3_exec(db, ea_mob_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_mob_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_mob_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_mob_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_mob_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_mob_tbl, NULL, NULL, NULL);	
	sqlite3_prepare_v2(db, ea_mob_ins, strlen(ea_mob_ins) + 1, &lt_db->ea_mob_insert, NULL);
	sqlite3_prepare_v2(db, ra_mob_ins, strlen(ra_mob_ins) + 1, &lt_db->ra_mob_insert, NULL);
	sqlite3_prepare_v2(db, he_mob_ins, strlen(he_mob_ins) + 1, &lt_db->he_mob_insert, NULL);
	assert(lt_db->ea_mob_insert != NULL);
	assert(lt_db->ra_mob_insert != NULL);
	assert(lt_db->he_mob_insert != NULL);

	/* block table */
	sqlite3_exec(db, itm_block_des, NULL, NULL, NULL);
	sqlite3_exec(db, itm_block_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, itm_block_ins, strlen(itm_block_ins) + 1, &lt_db->block_insert, NULL);
	assert(lt_db->block_insert != NULL);

	/* var table */
	sqlite3_exec(db, itm_var_des, NULL, NULL, NULL);
	sqlite3_exec(db, itm_var_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, itm_var_ins, strlen(itm_var_ins) + 1, &lt_db->var_insert, NULL);
	assert(lt_db->var_insert != NULL);

	/* status table */
	sqlite3_exec(db, itm_status_des, NULL, NULL, NULL);
	sqlite3_exec(db, itm_status_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, itm_status_ins, strlen(itm_status_ins) + 1, &lt_db->status_insert, NULL);
	assert(lt_db->status_insert != NULL);

	/* bonus table */
	sqlite3_exec(db, itm_bonus_des, NULL, NULL, NULL);
	sqlite3_exec(db, itm_bonus_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, itm_bonus_ins, strlen(itm_bonus_ins) + 1, &lt_db->bonus_insert, NULL);
	assert(lt_db->bonus_insert != NULL);

	/* const table */
	sqlite3_exec(db, ea_const_des, NULL, NULL, NULL);
	sqlite3_exec(db, ea_const_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, ra_const_des, NULL, NULL, NULL);
	sqlite3_exec(db, ra_const_tbl, NULL, NULL, NULL);
	sqlite3_exec(db, he_const_des, NULL, NULL, NULL);
	sqlite3_exec(db, he_const_tbl, NULL, NULL, NULL);
	sqlite3_prepare_v2(db, ea_const_ins, strlen(ea_const_ins) + 1, &lt_db->ea_const_insert, NULL);
	sqlite3_prepare_v2(db, ra_const_ins, strlen(ra_const_ins) + 1, &lt_db->ra_const_insert, NULL);
	sqlite3_prepare_v2(db, he_const_ins, strlen(he_const_ins) + 1, &lt_db->he_const_insert, NULL);
	assert(lt_db->ea_const_insert != NULL);	
	assert(lt_db->ra_const_insert != NULL);	
	assert(lt_db->he_const_insert != NULL);	

	lt_db->db = db;
	return lt_db;
}

void deit_db(struct lt_db_t * db) {
	sqlite3_finalize(db->he_item_insert);
	sqlite3_finalize(db->ea_item_insert);
	sqlite3_finalize(db->ra_item_insert);
	sqlite3_finalize(db->ea_pet_insert);
	sqlite3_finalize(db->ra_pet_insert);
	sqlite3_finalize(db->he_pet_insert);
	sqlite3_finalize(db->ea_merc_insert);
	sqlite3_finalize(db->ra_merc_insert);
	sqlite3_finalize(db->he_merc_insert);
	sqlite3_finalize(db->ea_prod_insert);
	sqlite3_finalize(db->ra_prod_insert);
	sqlite3_finalize(db->he_prod_insert);
	sqlite3_finalize(db->ea_skill_insert);
	sqlite3_finalize(db->ra_skill_insert);
	sqlite3_finalize(db->he_skill_insert);
	sqlite3_finalize(db->ea_mob_insert);
	sqlite3_finalize(db->ra_mob_insert);
	sqlite3_finalize(db->he_mob_insert);
	sqlite3_finalize(db->block_insert);
	sqlite3_finalize(db->var_insert);
	sqlite3_finalize(db->status_insert);
	sqlite3_finalize(db->bonus_insert);
	sqlite3_finalize(db->ea_const_insert);
	sqlite3_finalize(db->ra_const_insert);
	sqlite3_finalize(db->he_const_insert);
	sqlite3_close_v2(db->db);
	free(db);
}

void trace_db(void * bundle_data, const char * sql_stmt) {
	fprintf(stderr, "trace_db; %s\n", sql_stmt);
}

void load_ea_item(struct lt_db_t * sql, ea_item_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(sql->ea_item_insert);
		sqlite3_bind_int(sql->ea_item_insert, 1, db[i].id);
		sqlite3_bind_text(sql->ea_item_insert, 2, db[i].aegis, strlen(db[i].aegis), SQLITE_STATIC);
		sqlite3_bind_text(sql->ea_item_insert, 3, db[i].eathena, strlen(db[i].eathena), SQLITE_STATIC);
		sqlite3_bind_int(sql->ea_item_insert, 4, db[i].type);
		sqlite3_bind_int(sql->ea_item_insert, 5, db[i].buy);
		sqlite3_bind_int(sql->ea_item_insert, 6, db[i].sell);
		sqlite3_bind_int(sql->ea_item_insert, 7, db[i].weight);
		sqlite3_bind_int(sql->ea_item_insert, 8, db[i].atk);
		sqlite3_bind_int(sql->ea_item_insert, 9, db[i].def);
		sqlite3_bind_int(sql->ea_item_insert, 10, db[i].range);
		sqlite3_bind_int(sql->ea_item_insert, 11, db[i].slots);
		sqlite3_bind_int(sql->ea_item_insert, 12, db[i].job);
		sqlite3_bind_int(sql->ea_item_insert, 13, db[i].upper);
		sqlite3_bind_int(sql->ea_item_insert, 14, db[i].gender);
		sqlite3_bind_int(sql->ea_item_insert, 15, db[i].loc);
		sqlite3_bind_int(sql->ea_item_insert, 16, db[i].wlv);
		sqlite3_bind_int(sql->ea_item_insert, 17, db[i].elv);
		sqlite3_bind_int(sql->ea_item_insert, 18, db[i].refineable);
		sqlite3_bind_int(sql->ea_item_insert, 19, db[i].view);
		sqlite3_bind_text(sql->ea_item_insert, 20, db[i].script, strlen(db[i].script), SQLITE_STATIC);
		sqlite3_bind_text(sql->ea_item_insert, 21, db[i].onequip, strlen(db[i].onequip), SQLITE_STATIC);
		sqlite3_bind_text(sql->ea_item_insert, 22, db[i].onunequip, strlen(db[i].onunequip), SQLITE_STATIC);
		sqlite3_step(sql->ea_item_insert);
		if(ret != SQLITE_OK) fprintf(stderr, "item_id: %d failed\n", db[i].id);
		sqlite3_reset(sql->ea_item_insert);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_ra_item(struct lt_db_t * sql, ra_item_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(sql->ra_item_insert);
		sqlite3_bind_int(sql->ra_item_insert, 1, db[i].id);
		sqlite3_bind_text(sql->ra_item_insert, 2, db[i].aegis, strlen(db[i].aegis), SQLITE_STATIC);
		sqlite3_bind_text(sql->ra_item_insert, 3, db[i].eathena, strlen(db[i].eathena), SQLITE_STATIC);
		sqlite3_bind_int(sql->ra_item_insert, 4, db[i].type);
		sqlite3_bind_int(sql->ra_item_insert, 5, db[i].buy);
		sqlite3_bind_int(sql->ra_item_insert, 6, db[i].sell);
		sqlite3_bind_int(sql->ra_item_insert, 7, db[i].weight);
		sqlite3_bind_int(sql->ra_item_insert, 8, db[i].matk);
		sqlite3_bind_int(sql->ra_item_insert, 9, db[i].atk);
		sqlite3_bind_int(sql->ra_item_insert, 10, db[i].def);
		sqlite3_bind_int(sql->ra_item_insert, 11, db[i].range);
		sqlite3_bind_int(sql->ra_item_insert, 12, db[i].slots);
		sqlite3_bind_int(sql->ra_item_insert, 13, db[i].job);
		sqlite3_bind_int(sql->ra_item_insert, 14, db[i].upper);
		sqlite3_bind_int(sql->ra_item_insert, 15, db[i].gender);
		sqlite3_bind_int(sql->ra_item_insert, 16, db[i].loc);
		sqlite3_bind_int(sql->ra_item_insert, 17, db[i].wlv);
		sqlite3_bind_int(sql->ra_item_insert, 18, db[i].elv);
		sqlite3_bind_int(sql->ra_item_insert, 19, db[i].refineable);
		sqlite3_bind_int(sql->ra_item_insert, 20, db[i].view);
		sqlite3_bind_text(sql->ra_item_insert, 21, db[i].script, strlen(db[i].script), SQLITE_STATIC);
		sqlite3_bind_text(sql->ra_item_insert, 22, db[i].onequip, strlen(db[i].onequip), SQLITE_STATIC);
		sqlite3_bind_text(sql->ra_item_insert, 23, db[i].onunequip, strlen(db[i].onunequip), SQLITE_STATIC);
		sqlite3_step(sql->ra_item_insert);
		if(ret != SQLITE_OK) fprintf(stderr, "item_id: %d failed\n", db[i].id);
		sqlite3_reset(sql->ra_item_insert);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_pet(struct lt_db_t * sql, sqlite3_stmt * ins, pet_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].mob_id);
		sqlite3_bind_text(ins, 2, db[i].pet_name, strlen(db[i].pet_name), SQLITE_STATIC);
		sqlite3_bind_text(ins, 3, db[i].pet_name, strlen(db[i].pet_name), SQLITE_STATIC);
		sqlite3_bind_int(ins, 4, db[i].lure_id);
		sqlite3_bind_int(ins, 5, db[i].egg_id);
		sqlite3_bind_int(ins, 6, db[i].equip_id);
		sqlite3_bind_int(ins, 7, db[i].food_id);
		sqlite3_bind_int(ins, 8, db[i].fullness);
		sqlite3_bind_int(ins, 9, db[i].hungry_delay);
		sqlite3_bind_int(ins, 10, db[i].r_hungry);
		sqlite3_bind_int(ins, 11, db[i].r_full);
		sqlite3_bind_int(ins, 12, db[i].intimate);
		sqlite3_bind_int(ins, 13, db[i].die);
		sqlite3_bind_int(ins, 14, db[i].capture);
		sqlite3_bind_int(ins, 15, db[i].hungry_delay);
		sqlite3_bind_int(ins, 16, db[i].food_id);
		sqlite3_bind_int(ins, 17, db[i].fullness);
		sqlite3_bind_int(ins, 18, db[i].speed);
		sqlite3_bind_int(ins, 19, db[i].s_performance);
		sqlite3_bind_int(ins, 20, db[i].talk_convert);
		sqlite3_bind_int(ins, 21, db[i].attack_rate);
		sqlite3_bind_int(ins, 22, db[i].defence_attack_rate);
		sqlite3_bind_int(ins, 23, db[i].change_target_rate);
		sqlite3_bind_text(ins, 24, db[i].pet_script, strlen(db[i].pet_script), SQLITE_STATIC);
		sqlite3_bind_text(ins, 25, db[i].loyal_script, strlen(db[i].loyal_script), SQLITE_STATIC);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "pet_id: %d failed\n", db[i].mob_id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_merc(struct lt_db_t * sql, sqlite3_stmt * ins, merc_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_text(ins, 2, db[i].sprite, strlen(db[i].sprite), SQLITE_STATIC);
		sqlite3_bind_text(ins, 3, db[i].name, strlen(db[i].name), SQLITE_STATIC);
		sqlite3_bind_int(ins, 4, db[i].lv);
		sqlite3_bind_int(ins, 5, db[i].hp);
		sqlite3_bind_int(ins, 6, db[i].sp);
		sqlite3_bind_int(ins, 7, db[i].range1);
		sqlite3_bind_int(ins, 8, db[i].atk1);
		sqlite3_bind_int(ins, 9, db[i].atk2);
		sqlite3_bind_int(ins, 10, db[i].def);
		sqlite3_bind_int(ins, 11, db[i].mdef);
		sqlite3_bind_int(ins, 12, db[i].str);
		sqlite3_bind_int(ins, 13, db[i].agi);
		sqlite3_bind_int(ins, 14, db[i].vit);
		sqlite3_bind_int(ins, 15, db[i].intr);
		sqlite3_bind_int(ins, 16, db[i].dex);
		sqlite3_bind_int(ins, 17, db[i].luk);
		sqlite3_bind_int(ins, 18, db[i].range2);
		sqlite3_bind_int(ins, 19, db[i].range3);
		sqlite3_bind_int(ins, 20, db[i].scale);
		sqlite3_bind_int(ins, 21, db[i].race);
		sqlite3_bind_int(ins, 22, db[i].element);
		sqlite3_bind_int(ins, 23, db[i].speed);
		sqlite3_bind_int(ins, 24, db[i].adelay);
		sqlite3_bind_int(ins, 25, db[i].amotion);
		sqlite3_bind_int(ins, 26, db[i].dmotion);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "merc_id: %d failed\n", db[i].id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_prod(struct lt_db_t * sql, sqlite3_stmt * ins, produce_t * db, int size) {
	int i = 0;
	int ret = 0;
	char buf[4096];
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].item_id);
		sqlite3_bind_int(ins, 2, db[i].item_lv);
		sqlite3_bind_int(ins, 3, db[i].req_skill);
		sqlite3_bind_int(ins, 4, db[i].req_skill_lv);
		array_to_string(buf, db[i].material);
		sqlite3_bind_text(ins, 5, buf, strlen(buf), SQLITE_TRANSIENT);
		array_to_string_cnt(buf, db[i].amount, array_field_cnt(buf));
		sqlite3_bind_text(ins, 6, buf, strlen(buf), SQLITE_TRANSIENT);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "prod_id: %d failed\n", db[i].item_id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void ra_load_prod(struct lt_db_t * sql, sqlite3_stmt * ins, ra_produce_t * db, int size) {
	int i = 0;
	int ret = 0;
	char buf[4096];
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_int(ins, 2, db[i].item_id);
		sqlite3_bind_int(ins, 3, db[i].item_lv);
		sqlite3_bind_int(ins, 4, db[i].req_skill);
		sqlite3_bind_int(ins, 5, db[i].req_skill_lv);
		array_to_string(buf, db[i].material);
		sqlite3_bind_text(ins, 6, buf, strlen(buf), SQLITE_TRANSIENT);
		array_to_string_cnt(buf, db[i].amount, array_field_cnt(buf));
		sqlite3_bind_text(ins, 7, buf, strlen(buf), SQLITE_TRANSIENT);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "prod_id: %d failed\n", db[i].item_id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void ea_load_mob(struct lt_db_t * sql, sqlite3_stmt * ins, ea_mob_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_text(ins, 2, db[i].sprite, strlen(db[i].sprite), SQLITE_STATIC);
		sqlite3_bind_text(ins, 3, db[i].kro, strlen(db[i].kro), SQLITE_STATIC);
		sqlite3_bind_text(ins, 4, db[i].iro, strlen(db[i].iro), SQLITE_STATIC);
		sqlite3_bind_int(ins, 5, db[i].lv);
		sqlite3_bind_int(ins, 6, db[i].hp);
		sqlite3_bind_int(ins, 7, db[i].sp);
		sqlite3_bind_int(ins, 8, db[i].exp);
		sqlite3_bind_int(ins, 9, db[i].jexp);
		sqlite3_bind_int(ins, 10, db[i].range);
		sqlite3_bind_int(ins, 11, db[i].atk1);
		sqlite3_bind_int(ins, 12, db[i].atk2);
		sqlite3_bind_int(ins, 13, db[i].def);
		sqlite3_bind_int(ins, 14, db[i].mdef);
		sqlite3_bind_int(ins, 15, db[i].str);
		sqlite3_bind_int(ins, 16, db[i].agi);
		sqlite3_bind_int(ins, 17, db[i].vit);
		sqlite3_bind_int(ins, 18, db[i].intr);
		sqlite3_bind_int(ins, 19, db[i].dex);
		sqlite3_bind_int(ins, 20, db[i].luk);
		sqlite3_bind_int(ins, 21, db[i].range2);
		sqlite3_bind_int(ins, 22, db[i].range3);
		sqlite3_bind_int(ins, 23, db[i].scale);
		sqlite3_bind_int(ins, 24, db[i].race);
		sqlite3_bind_int(ins, 25, db[i].element);
		sqlite3_bind_int(ins, 26, db[i].mode);
		sqlite3_bind_int(ins, 27, db[i].speed);
		sqlite3_bind_int(ins, 28, db[i].adelay);
		sqlite3_bind_int(ins, 29, db[i].amotion);
		sqlite3_bind_int(ins, 30, db[i].dmotion);
		sqlite3_bind_int(ins, 31, db[i].mexp);
		sqlite3_bind_int(ins, 32, db[i].expper);
		sqlite3_bind_int(ins, 33, db[i].mvp1id);
		sqlite3_bind_int(ins, 34, db[i].mvp1per);
		sqlite3_bind_int(ins, 35, db[i].mvp2id);
		sqlite3_bind_int(ins, 36, db[i].mvp2per);
		sqlite3_bind_int(ins, 37, db[i].mvp3id);
		sqlite3_bind_int(ins, 38, db[i].mvp3per);
		sqlite3_bind_int(ins, 39, db[i].drop1id);
		sqlite3_bind_int(ins, 40, db[i].drop1per);
		sqlite3_bind_int(ins, 41, db[i].drop2id);
		sqlite3_bind_int(ins, 42, db[i].drop2per);
		sqlite3_bind_int(ins, 43, db[i].drop3id);
		sqlite3_bind_int(ins, 44, db[i].drop3per);
		sqlite3_bind_int(ins, 45, db[i].drop4id);
		sqlite3_bind_int(ins, 46, db[i].drop4per);
		sqlite3_bind_int(ins, 47, db[i].drop5id);
		sqlite3_bind_int(ins, 48, db[i].drop5per);
		sqlite3_bind_int(ins, 49, db[i].drop6id);
		sqlite3_bind_int(ins, 50, db[i].drop6per);
		sqlite3_bind_int(ins, 51, db[i].drop7id);
		sqlite3_bind_int(ins, 52, db[i].drop7per);
		sqlite3_bind_int(ins, 53, db[i].drop8id);
		sqlite3_bind_int(ins, 54, db[i].drop8per);
		sqlite3_bind_int(ins, 55, db[i].drop9id);
		sqlite3_bind_int(ins, 56, db[i].drop9per);
		sqlite3_bind_int(ins, 57, db[i].dropcardid);
		sqlite3_bind_int(ins, 58, db[i].dropcardper);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "mob_id: %d failed\n", db[i].id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_mob(struct lt_db_t * sql, sqlite3_stmt * ins, mob_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_text(ins, 2, db[i].sprite, strlen(db[i].sprite), SQLITE_STATIC);
		sqlite3_bind_text(ins, 3, db[i].kro, strlen(db[i].kro), SQLITE_STATIC);
		sqlite3_bind_text(ins, 4, db[i].iro, strlen(db[i].iro), SQLITE_STATIC);
		sqlite3_bind_int(ins, 5, db[i].lv);
		sqlite3_bind_int(ins, 6, db[i].hp);
		sqlite3_bind_int(ins, 7, db[i].sp);
		sqlite3_bind_int(ins, 8, db[i].exp);
		sqlite3_bind_int(ins, 9, db[i].jexp);
		sqlite3_bind_int(ins, 10, db[i].range);
		sqlite3_bind_int(ins, 11, db[i].atk1);
		sqlite3_bind_int(ins, 12, db[i].atk2);
		sqlite3_bind_int(ins, 13, db[i].def);
		sqlite3_bind_int(ins, 14, db[i].mdef);
		sqlite3_bind_int(ins, 15, db[i].str);
		sqlite3_bind_int(ins, 16, db[i].agi);
		sqlite3_bind_int(ins, 17, db[i].vit);
		sqlite3_bind_int(ins, 18, db[i].intr);
		sqlite3_bind_int(ins, 19, db[i].dex);
		sqlite3_bind_int(ins, 20, db[i].luk);
		sqlite3_bind_int(ins, 21, db[i].range2);
		sqlite3_bind_int(ins, 22, db[i].range3);
		sqlite3_bind_int(ins, 23, db[i].scale);
		sqlite3_bind_int(ins, 24, db[i].race);
		sqlite3_bind_int(ins, 25, db[i].element);
		sqlite3_bind_int(ins, 26, db[i].mode);
		sqlite3_bind_int(ins, 27, db[i].speed);
		sqlite3_bind_int(ins, 28, db[i].adelay);
		sqlite3_bind_int(ins, 29, db[i].amotion);
		sqlite3_bind_int(ins, 30, db[i].dmotion);
		sqlite3_bind_int(ins, 31, db[i].mexp);
		sqlite3_bind_int(ins, 32, db[i].mvp1id);
		sqlite3_bind_int(ins, 33, db[i].mvp1per);
		sqlite3_bind_int(ins, 34, db[i].mvp2id);
		sqlite3_bind_int(ins, 35, db[i].mvp2per);
		sqlite3_bind_int(ins, 36, db[i].mvp3id);
		sqlite3_bind_int(ins, 37, db[i].mvp3per);
		sqlite3_bind_int(ins, 38, db[i].drop1id);
		sqlite3_bind_int(ins, 39, db[i].drop1per);
		sqlite3_bind_int(ins, 40, db[i].drop2id);
		sqlite3_bind_int(ins, 41, db[i].drop2per);
		sqlite3_bind_int(ins, 42, db[i].drop3id);
		sqlite3_bind_int(ins, 43, db[i].drop3per);
		sqlite3_bind_int(ins, 44, db[i].drop4id);
		sqlite3_bind_int(ins, 45, db[i].drop4per);
		sqlite3_bind_int(ins, 46, db[i].drop5id);
		sqlite3_bind_int(ins, 47, db[i].drop5per);
		sqlite3_bind_int(ins, 48, db[i].drop6id);
		sqlite3_bind_int(ins, 49, db[i].drop6per);
		sqlite3_bind_int(ins, 50, db[i].drop7id);
		sqlite3_bind_int(ins, 51, db[i].drop7per);
		sqlite3_bind_int(ins, 52, db[i].drop8id);
		sqlite3_bind_int(ins, 53, db[i].drop8per);
		sqlite3_bind_int(ins, 54, db[i].drop9id);
		sqlite3_bind_int(ins, 55, db[i].drop9per);
		sqlite3_bind_int(ins, 56, db[i].dropcardid);
		sqlite3_bind_int(ins, 57, db[i].dropcardper);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "mob_id: %d failed\n", db[i].id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_skill(struct lt_db_t * sql, sqlite3_stmt * ins, skill_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_text(ins, 2, db[i].range, strlen(db[i].range), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].hit);
		sqlite3_bind_int(ins, 4, db[i].inf);
		sqlite3_bind_text(ins, 5, db[i].element, strlen(db[i].element), SQLITE_STATIC);
		sqlite3_bind_int(ins, 6, db[i].nk);
		sqlite3_bind_text(ins, 7, db[i].splash, strlen(db[i].splash), SQLITE_STATIC);
		sqlite3_bind_int(ins, 8, db[i].max);
		sqlite3_bind_text(ins, 9, db[i].hit_amount, strlen(db[i].hit_amount), SQLITE_STATIC);
		sqlite3_bind_text(ins, 10, db[i].cast_cancel, strlen(db[i].cast_cancel), SQLITE_STATIC);
		sqlite3_bind_int(ins, 11, db[i].cast_def_reduce_rate);
		sqlite3_bind_int(ins, 12, db[i].inf2);
		sqlite3_bind_text(ins, 13, db[i].maxcount, strlen(db[i].maxcount), SQLITE_STATIC);
		sqlite3_bind_text(ins, 14, db[i].type, strlen(db[i].type), SQLITE_STATIC);
		sqlite3_bind_text(ins, 15, db[i].blow_count, strlen(db[i].blow_count), SQLITE_STATIC);
		sqlite3_bind_text(ins, 16, db[i].name, strlen(db[i].name), SQLITE_STATIC);
		sqlite3_bind_text(ins, 17, db[i].desc, strlen(db[i].desc), SQLITE_STATIC);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "skill_id: %d failed\n", db[i].id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void ra_load_skill(struct lt_db_t * sql, sqlite3_stmt * ins, ra_skill_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].id);
		sqlite3_bind_text(ins, 2, db[i].range, strlen(db[i].range), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].hit);
		sqlite3_bind_int(ins, 4, db[i].inf);
		sqlite3_bind_text(ins, 5, db[i].element, strlen(db[i].element), SQLITE_STATIC);
		sqlite3_bind_int(ins, 6, db[i].nk);
		sqlite3_bind_text(ins, 7, db[i].splash, strlen(db[i].splash), SQLITE_STATIC);
		sqlite3_bind_int(ins, 8, db[i].max);
		sqlite3_bind_text(ins, 9, db[i].hit_amount, strlen(db[i].hit_amount), SQLITE_STATIC);
		sqlite3_bind_text(ins, 10, db[i].cast_cancel, strlen(db[i].cast_cancel), SQLITE_STATIC);
		sqlite3_bind_int(ins, 11, db[i].cast_def_reduce_rate);
		sqlite3_bind_int(ins, 12, db[i].inf2);
		sqlite3_bind_text(ins, 13, db[i].maxcount, strlen(db[i].maxcount), SQLITE_STATIC);
		sqlite3_bind_text(ins, 14, db[i].type, strlen(db[i].type), SQLITE_STATIC);
		sqlite3_bind_text(ins, 15, db[i].blow_count, strlen(db[i].blow_count), SQLITE_STATIC);
		sqlite3_bind_int(ins, 16, db[i].inf3);
		sqlite3_bind_text(ins, 17, db[i].name, strlen(db[i].name), SQLITE_STATIC);
		sqlite3_bind_text(ins, 18, db[i].desc, strlen(db[i].desc), SQLITE_STATIC);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "ra_skill_id: %d failed\n", db[i].id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_block(struct lt_db_t * sql, sqlite3_stmt * ins, block_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].bk_id);
		sqlite3_bind_text(ins, 2, db[i].bk_kywd, strlen(db[i].bk_kywd), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].bk_flag);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "block_id: %d failed\n", db[i].bk_id);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_var(struct lt_db_t * sql, sqlite3_stmt * ins, var_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].tag);
		sqlite3_bind_text(ins, 2, db[i].id, strlen(db[i].id), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].type);
		sqlite3_bind_int(ins, 4, db[i].vflag);
		sqlite3_bind_int(ins, 5, db[i].fflag);
		sqlite3_bind_int(ins, 6, db[i].min);
		sqlite3_bind_int(ins, 7, db[i].max);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "var_id: %d failed\n", db[i].tag);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_status(struct lt_db_t * sql, sqlite3_stmt * ins, status_t * db, int size) {
	int i = 0;
	int ret = 0;
	char buf[4096];
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_int(ins, 1, db[i].scid);
		sqlite3_bind_text(ins, 2, db[i].scstr, strlen(db[i].scstr), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].type);
		if(db[i].scfmt != NULL)
			sqlite3_bind_text(ins, 4, db[i].scfmt, strlen(db[i].scfmt), SQLITE_STATIC);
		if(db[i].scend != NULL)
			sqlite3_bind_text(ins, 5, db[i].scend, strlen(db[i].scend), SQLITE_STATIC);
		sqlite3_bind_int(ins, 6, db[i].vcnt);
		array_to_string_cnt(buf, db[i].vmod, 4);
		sqlite3_bind_text(ins, 7, buf, strlen(buf), SQLITE_TRANSIENT);
		array_to_string_cnt(buf, db[i].voff, 4);
		sqlite3_bind_text(ins, 8, buf, strlen(buf), SQLITE_TRANSIENT);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "status_id: %d failed\n", db[i].scid);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_bonus(struct lt_db_t * sql, sqlite3_stmt * ins, bonus_t * db, int size) {
	int i = 0;
	int ret = 0;
	char buf[4096];
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_text(ins, 1, db[i].pref, strlen(db[i].pref), SQLITE_STATIC);
		sqlite3_bind_text(ins, 2, db[i].buff, strlen(db[i].buff), SQLITE_STATIC);
		sqlite3_bind_int(ins, 3, db[i].attr);
		sqlite3_bind_text(ins, 4, db[i].desc, strlen(db[i].desc), SQLITE_STATIC);
		array_to_string_cnt(buf, db[i].type, db[i].type_cnt);
		sqlite3_bind_text(ins, 7, buf, strlen(buf), SQLITE_TRANSIENT);
		sqlite3_bind_int(ins, 3, db[i].type_cnt);
		array_to_string_cnt(buf, db[i].order, db[i].order_cnt);
		sqlite3_bind_text(ins, 7, buf, strlen(buf), SQLITE_TRANSIENT);
		sqlite3_bind_int(ins, 3, db[i].order_cnt);
		
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "bonus: %s failed\n", db[i].buff);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

void load_const(struct lt_db_t * sql, sqlite3_stmt * ins, const_t * db, int size) {
	int i = 0;
	int ret = 0;
	sqlite3_exec(sql->db, "BEGIN IMMEDIATE TRANSACTION;", NULL, NULL, NULL);
	for(i = 0; i < size; i++) {
		sqlite3_clear_bindings(ins);
		sqlite3_bind_text(ins, 1, db[i].name, strlen(db[i].name), SQLITE_STATIC);
		sqlite3_bind_int(ins, 2, db[i].value);
		sqlite3_bind_int(ins, 3, db[i].type);
		sqlite3_step(ins);
		if(ret != SQLITE_OK) fprintf(stderr, "status: %s failed\n", db[i].name);
		sqlite3_reset(ins);
	}
	sqlite3_exec(sql->db, "COMMIT TRANSACTION;", NULL, NULL, NULL);
}

char * array_to_string(char * buffer, int * array) {
	int offset = 0;
	for(int i = 0; array[i] > 0; i++)
		offset += sprintf(buffer + offset, "%d%s", array[i], (array[i + 1] > 0) ? ":" : "");
	buffer[offset] = '\0';
	return buffer;
}

char * array_to_string_cnt(char * buffer, int * array, int size) {
	int offset = 0;
	for(int i = 0; i < size; i++)
		offset += sprintf(buffer + offset, "%d%s", array[i], (i + 1 < size) ? ":" : "");
	buffer[offset] = '\0';
	return buffer;
}

int array_field_cnt(char * buf) {
	int i = 0;
	int cnt = 0;
	int len = strlen(buf);
	for(i = 0; i < len; i++)
		if(buf[i] == ':') cnt++;
	return cnt;

}