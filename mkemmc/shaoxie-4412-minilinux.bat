echo ITOP…’–¥

fastboot.exe flash bootloader u-boot-iTOP-4412.bin
:fastboot.exe flash kernel zImage
:fastboot.exe flash ramdisk ramdisk-uboot.img
:fastboot.exe flash system system.img

:fastboot.exe flash kernel uImage
:fastboot.exe flash dtb exynos4412-itop-elite.dtb
:fastboot.exe flash system system.img
fastboot.exe -w
fastboot.exe reboot