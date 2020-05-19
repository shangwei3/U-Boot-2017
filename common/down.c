#include <common.h>  
#include <command.h>  
#include <fastboot.h>

#if defined(CONFIG_CMD_DOWN)

int write_chunk(char* data, unsigned int sector, unsigned int sector_size) {
        char run_cmd[64];
        int err ;
        ext4_printf("write raw data in %d size %d \n", sector, sector_size);
        sprintf(run_cmd,"mmc write  0x%x 0x%x 0x%x",(int)data, sector, sector_size);
        err = run_command(run_cmd, 0);
        return (1-err); //mj
}

void do_down (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])   
{
    char run_cmd[64] = {"mmc write 0x40007000 460  3000"};
    char run_cmd_tftp[64] = {"tftpboot 0x40007000  uImage"};
    int err ;
    printf("    argc:%d argv[0]:%s argv[1]:%s\n\n",argc,argv[0],argv[1]);

    if (argc < 2) {
        printf("     Please input the parameters correctly\n");
        printf("     For example down kernel w \n");
        return CMD_RET_USAGE;
    }

	char *open_emmc[2]	= { "open","   "};
	char *close_emmc[2]  = { "close","	 "};
	if (strncmp(argv[1], "boot", sizeof(argv[1])) == 0) {
		printf("starting down u-boot ...\n");

		err = run_command("tftpboot  0x40007000 u-boot-iTOP-4412.bin", 0);
	
		//tftp_down();
		printf("open emmc\n");
		do_mmc_dev(NULL,0,2,open_emmc);//open emmc
		
        err = run_command("mmc write 0x40007000 0    40e", 0);
		printf("close emmc\n");
		do_mmc_dev(NULL,0,2,close_emmc);//close emmc
		return 0;
	}
	
	if (strncmp(argv[1], "kernel", sizeof(argv[1])) == 0) {
		printf("starting down u-boot ...\n");
	    err = run_command("tftpboot  0x40007000 uImage", 0);
	    err = run_command("mmc write 0x40007000 460  3000", 0);
		return 0;
	}

	if (strncmp(argv[1], "dtb", sizeof(argv[1])) == 0) {
		printf("starting down u-boot ...\n");
        err = run_command("tftpboot  0x40007000 exynos4412-itop-elite.dtb", 0);
        err = run_command("mmc write 0x40007000 3460 a0", 0);
		return 0;
	}

	if (strncmp(argv[1], "image", sizeof(argv[1])) == 0) {
		printf("starting down image ...\n");
        err = run_command("tftpboot  0x40007000 system.img", 0);
        err = run_command("mmc write 0x40007000 aeed a000", 0);
		return 0;
	}

    return (1-err); //mj
    printf("this is my down image !\n");

}  


U_BOOT_CMD(
	down, 2, 0, do_down,
	"down command\n\n",
	"<down image command!\n>\n"
	"    - down image of tftp"
);
#endif
