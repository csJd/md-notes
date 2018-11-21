# 双系统（Windows + Ubuntu）安装指北

## 0 准备材料
* [U 盘（8G↑)](https://item.jd.com/5723649.html)
* [Windows 10 ISO](https://www.microsoft.com/zh-cn/software-download/windows10ISO)
* [Ubuntu Desktop LTS 版 ISO](https://www.ubuntu.com/download/desktop)
* [Rufus Portable 版](https://rufus.ie/zh_CN.html)
* [WEPE Win10PE 64 位版](http://www.wepe.com.cn/download.html)


## 1 在 U 盘安装 WEPE
 * 运行「WEPE」，选择安装到 U 盘，选项默认
 * 将下载的 ISO 文件和 rufus 复制到 U 盘


## 2 格式化硬盘
 * 重启按 **F12** 键选择从 U 盘启动（选择带 UEFI 的 U 盘启动项）
 * 打开桌面上的「分区助手」，点击上方「快速分区」，磁盘类型**一定选择 GPT** ，上方分区数目建议不超过 3 ，其中第一个分区将用于 Windows 系统 的 C 盘，卷标设置为「OS」；其中最后一个分区空间将用于 Ubuntu 的安装，卷标设置为「Ubuntu」；其余分区将用于 Windows 系统的普通分区，卷标设置为「Data」
      
      建议分区方案（SDD 表示固态硬盘，HDD 表示机械硬盘，REST 表示该磁盘剩余空间）:

      | 硬盘类型 | OS | Data | Ubuntu | 分区数目 |
      | ---| --- | --- | --- | --- |
      | SSD(256G↑) | 80G | 100G | REST¹ | 3 |
      | SSD(128G) + HDD | 60G(SSD) | REST²(SSD) + REST²(HDD) | 200G(HDD)| 4 |
      | SSD(256G↑) + HDD | 80G(SSD) | 100G(SSD) + REST³(HDD) | REST³(SSD) + 200G(HDD)| 5 |

 * 删除卷标为「Ubuntu」的分区，空出其空间不要与其他分区合并，此空间将用于 Ubuntu 的安装


## 3 安装 Windows 10
 * 将 U 盘中的 Windows 10 ISO 文件复制到硬盘中卷标为「Data」的分区，弹出并**拔掉** U 盘
 * 打开桌面上的 「Windows 安装器」，Windows 安装文件的文件夹选择刚复制的 ISO 文件，安装磁盘的位置选择卷标为「OS」的分区，版本选择「Windows 10 专业版」
 * 点击开始安装，进度条走完后手动重启，完成 Windows 安装步骤


## 4 安装 Ubuntu
 * 在安装好的 Windows 中使用 rufus 将 Ubuntu 镜像写入 U 盘
 * 重启按 **F12** 选择从 U 盘启动，选择 「安装 Ubuntu」
 * 「安装类型」处选择「其他选项」
 * 在空闲分区处点击下方加号依次创建 `swap`[8G], `/`[50G 或 REST³(SSD)], `/home`[REST]
 * 点击下方「现在安装」完成 Ubuntu 安装步骤

