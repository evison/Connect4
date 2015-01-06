1. Please do set the UI project as the active project.
2. If you use 64 bit system, please right click "Solution Resource Manager" -> UI, choose
	Property -> Build -> Target Platform, and set as x86.
	
----------------------------
Some tricks for dll debugging:

1. include the following head files:
#include <conio.h>
#include <atlstr.h>

2. Allocate a console before printing (you need only to do this for once):
AllocConsole();

3. Call _cprintf() method for printing:
e.g.
int a = 1;
_cprintf("a = %d\n", a);

----------------------------

Note: Printing is rather time-consuming, in order to avoid time-out, you should comment out
the printing codes in your final version for submitting.


******************************************************************************************


1.务必将UI设为启动项目
2.使用64位系统的同学，请在"解决方案资源管理器"->UI上点右键->选择"属性"->生成->目标平台 中设置为 x86

----------------------------
dll通过打印调试的方法：

1.包含头文件：
#include <conio.h>
#include <atlstr.h>

2.打印之前分配窗口(只需调用一次)：
AllocConsole();

3.调用_cprintf()进行打印：
e.g.
int a = 1;
_cprintf("a = %d\n", a);

----------------------------

注意：打印操作相当费时，为了避免超时，最终提交的代码版本中尽量注释掉打印操作。
