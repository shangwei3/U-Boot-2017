#!/bin/bash

cd ../

if [ ! -f .config ]
then
	make itop4412_defconfig
fi

make -j8 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-

cp u-boot.bin ./mkuboot/
echo "copy u-boot.bin done."

cd spl/
if [ ! -f itop4412-spl.bin ] ; then
	echo "notice: not found itop4412-spl.bin !"
	exit 0
else
	echo "copying itop4412-spl.bin..."
fi

cp itop4412-spl.bin ../mkuboot/
echo "copy u-boot-spl.bin done."
pwd 
cd ../mkuboot
echo cat u-boot-iTOP-4412.bin
cat E4412_N.bl1.bin itop4412-spl.bin env.bin u-boot.bin > u-boot-iTOP-4412.bin
echo cp u-boot-iTOP-4412.bin
cp u-boot-iTOP-4412.bin ../../../ftp/ 
echo "build success !!!"
