#!/bin/bash

cd ../

if [ ! -f .config ]
then
	make itop4412_defconfig
fi

make -j8

pwd
cp u-boot.bin mkemmc/
echo "copy u-boot.bin done."


pwd
cd mkemmc/
cp ../spl/itop4412-spl.bin  ./
cp ../spl/u-boot-spl.bin  ./
echo "fusing u-boot-iTOP-4412.bin......"

################ for sd MMC boot ##################
#cat E4412_N.bl1.bin itop4412-spl.bin env.bin u-boot.bin > u-boot-iTOP-4412.bin
################# for eMMC boot ####################
echo "cat E4412_N.bl1.bin itop4412-spl.bin u-boot.bin > u-boot-iTOP-4412.bin"
cat E4412_N.bl1.bin itop4412-spl.bin u-boot.bin > u-boot-iTOP-4412.bin
####################################################

echo CP U-Boot 

cp u-boot-iTOP-4412.bin ~/ftp/

echo "build success !!!"
