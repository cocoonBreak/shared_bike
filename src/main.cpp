#include <stdio.h>
#include "common/iniconfig.h"

int main(int argc, char **argv)
{
	if(argc != 2){
		printf("Please input shbk <config file path>!\n");
		return -1;
	}
	
	Iniconfig iniconf;
	if(iniconf.loadfile(argv[1])){
		const st_env_config &st_conf = iniconf.getconfig();
		printf("db_ip: %s\n", st_conf.db_ip.c_str());
		printf("db_port: %d\n", st_conf.db_port);
		printf("db_user: %s\n", st_conf.db_user.c_str());
		printf("db_pwd: %s\n", st_conf.db_pwd.c_str());
		printf("db_name: %s\n", st_conf.db_name.c_str());
		printf("svr_port: %d\n", st_conf.svr_port);
	}
	
	return 0;
}