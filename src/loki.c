#include "load.h"
#include "util.h"
#include "db_eathena.h"
#include "db_rathena.h"
#include "db_hercules.h"
#include "db_resources.h"
int main(int argc, char * argv[]) {
	/* test loading all the databases */
	load_rathena_database(NULL);
	load_eathena_database(NULL);
	load_hercules_database(NULL);
	load_resource_database(NULL);
	return 0;
}