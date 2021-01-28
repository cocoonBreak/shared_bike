#include <stdio.h>
#include "common/iniconfig.h"
#include "common/logger.h"

int main(int argc, char **argv)
{
	if(argc != 3){
		printf("Please input shbk <config file path> <log file config>!\n");
		return -1;
	}
	
	if(!logger::get_instance().init(std::string(argv[2]))){
		fprintf(stderr, "init log module failed.\n");
		return -2;
	}
	
	Iniconfig iniconf;
	if(!iniconf.loadfile(argv[1])){
		LOG_ERROR("log %s failed.", argv[1]);
		return -3;
	}
	
	const st_env_config &st_conf = iniconf.getconfig();
	LOG_INFO("[datebase] ip: %s port: %d user: %s pwd: %s name: %s  [server] port:%d\n", st_conf.db_ip.c_str(), st_conf.db_port, \
			st_conf.db_user.c_str(), st_conf.db_pwd.c_str(), st_conf.db_name.c_str(), st_conf.svr_port);

	return 0;
}
