使用18.04LTS搭建4412开发环境步骤说明

1、安装vm tools一共三步
sudo apt-get install
sudo apt-get update
sudo apt install net-tools
2、安装gcc等编译环境
sudo apt-get install gcc
3、安装arm编译环境
/usr/local/arm/arm-2009q3/bin
sudo apt-get install vim
sudo vim /etc/profile
export PATH=/usr/local/arm/arm-2009q3/bin:$PATH
sudo vim ~/.bashrc//命令窗口每次启动都会执行，方便更新环境变量
Ubuntu 上配置环境变量后切换到root下环境变量无效 的解决方法。
原因：非root  和 root 下，环境变量的配置文件不同。
非root下，配置文件为：~/.bashrc  ，配置后执行更新： source ~/.bashrc
root下，配置文件为：/etc/profile  ，配置后执行更新：  source /etc/profile
解决：打开 ~/.bashrc ，把里面相应的配置变量（环境路径），复制到  /etc/profile ，然后更新即可。
但还有一个问题，关闭终端后，下次打开又无效了。解决方法：
解决方法：打开 gedit /root/.bashrc   ，在文件的末尾添加：
source /etc/profile
然后执行更新：source /root/.bashrc
4、当环境搭建好了后不能直接编译通过
执行 sudo apt-get install libc6:i386后编译通过


5、搭建busybox
apt install make
apt install make-guile
sudo apt-get install gcc
使用make menuconfig出现错误后
sudo apt-get install libncurses5-dev

6、解决busybox make报错问题
可以在/交叉编译工具链路径//arm-none-linux-gnueabi/libc/usr/include/mtd/mtd-abi.h文件中末尾的
enum mtd_file_modes {
MTD_MODE_NORMAL = MTD_OTP_OFF,
MTD_MODE_OTP_FACTORY = MTD_OTP_FACTORY,
MTD_MODE_OTP_USER = MTD_OTP_USER,
MTD_MODE_RAW,
};
修改为
enum mtd_file_modes {
MTD_MODE_NORMAL = MTD_OTP_OFF,
MTD_MODE_OTP_FACTORY = MTD_OTP_FACTORY,
MTD_MODE_OTP_USER = MTD_OTP_USER,
MTD_MODE_RAW,
MTD_FILE_MODE_RAW,
};
BLKSECDISCARD在/usr/include/linux/fs.h中定义，方法如上所述，将/usr/include/linux/fs.h拷贝到busybox的include文件中，然后修改blkdiscard.c中头文件包含：
修改：#include <linux/fs.h>为#include "fs.h"

  CC      util-linux/volume_id/xfs.o
  AR      util-linux/volume_id/lib.a
  LINK    busybox_unstripped
Trying libraries: crypt m
 Library crypt is not needed, excluding it
 Library m is needed, can't exclude it (yet)
Final link with: m
libbusybox: 0_lib/libbusybox.so.1.27.2
  DOC     busybox.pod
  DOC     BusyBox.txt
  DOC     busybox.1
  DOC     BusyBox.html

7、生成最小系统时需要安装的库
sudo apt-get install libstdc++6
sudo apt-get install lib32stdc++6






 
