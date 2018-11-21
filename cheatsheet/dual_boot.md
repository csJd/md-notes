# 双系统（Windows + Ubuntu）安装指北

>  以下操作会清空所有磁盘的所有数据，请提前备份需要的数据。**所有未提及到的选项请都保持默认选项**

</br>

## 0 准备材料
* [U 盘（8G↑)](https://item.jd.com/5723649.html)
* [Windows 10 ISO](https://www.microsoft.com/zh-cn/software-download/windows10ISO)
* [Ubuntu Desktop LTS 版 ISO](https://www.ubuntu.com/download/desktop)
* [Rufus Portable 版](https://rufus.ie/zh_CN.html)
* [WEPE Win10PE 64 位版](http://www.wepe.com.cn/download.html)
</br></br>

## 1 在 U 盘安装 WEPE
 * 运行「WEPE」，选择安装到 U 盘，选项默认
 * 将下载的 ISO 文件和 rufus 复制到 U 盘
</br></br>

## 2 格式化硬盘
 * 重启按 **F12** 键，选择带 「UEFI」的 U 盘启动项
 * 打开桌面上的「分区助手」，点击上方「快速分区」，磁盘类型**一定选择 GPT** ，上方分区数目建议不超过 3 ，其中第一个分区将用于 Windows 系统 的 C 盘，卷标设置为「**OS**」；其中最后一个分区空间将用于 Ubuntu 系统的安装，卷标设置为「**Ubuntu**」；其余分区将用于 Windows 系统的普通分区，卷标设置建议为「Data」、「Apps」之类，自己开心就好
      
      建议分区方案（SSD 表示固态硬盘，HDD 表示机械硬盘，REST 表示该磁盘剩余空间）:

      | 硬盘类型 | OS | Apps | Data | Ubuntu | 分区数目 |
      | ---| --- | --- | --- | --- | --- |
      | 仅 HDD | 100G | / | REST¹ | 200G | 3 |
      | 仅 SSD(256G↑) | 80G | / | 100G | REST¹ | 3 |
      | SSD(128G) + HDD | 80G(SSD) | REST²(SSD) | REST²(HDD) | 200G(HDD)| 4 |
      | SSD(256G↑) + HDD | 100G(SSD) | 100G(SSD) | REST³(HDD) | REST³(SSD) + 200G(HDD)| 5 |

 * 完成分区后，鼠标右键点击卷标为「Ubuntu」的分区，点击**删除分区**，保持其空间为「未分配」，这些空间将用于 Ubuntu 的安装
</br></br>

## 3 安装 Windows 10
 * 将 U 盘中的 Windows 10 ISO 文件和 rufus 复制到硬盘中卷标**不为 OS **的分区，弹出并**拔掉** U 盘
 * 打开桌面上的 「Windows 安装器」，Windows 安装文件的文件夹选择刚复制的 ISO 文件，安装磁盘的位置选择卷标为「OS」的分区，引导驱动器选择处**保持默认**，版本选择「Windows 10 专业版」
 * 点击开始安装，进度条走完后手动重启，按提示完成 Windows 安装步骤
 * 进入系统后，桌面空白处点击鼠标右键，选择「个性化 | 主题 | 桌面图标设置」可添加「计算机」图标到桌面
</br></br>

## 4 安装 Ubuntu
 * 在 Windows 系统中运行之前复制到硬盘的 「rufus」，「设备」处选择 U 盘，点击「选择」处，选择 Ubuntu 的 ISO 文件，其余选项默认，点击「开始」将 Ubuntu ISO 文件写入 U 盘
 * 重启按 **F12** 键，选择带 「UEFI」的 U 盘启动项，选择 「安装 Ubuntu」
 * 「安装类型」处选择「其他选项」
 * 选中空闲设备，点击下方加号依次创建 `swap`[8G]，`/`[50G 或 REST³(SSD)]，`/home`[REST]
 * 点击下方「现在安装」，按提示完成 Ubuntu 安装步骤

