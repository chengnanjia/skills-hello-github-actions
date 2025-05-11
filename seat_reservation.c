#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 定义 图书馆管理员 结构体
struct Admin {
    char username[15]; // 用户名
    char password[15]; // 密码
};

// 定义全局 图书馆管理员 数组
struct Admin adminList[100];
int adminCount = 0; // 图书馆管理员计数

// 定义 学生 结构体
struct Student {
    char username[15]; // 用户名
    char password[15]; // 密码
    char name[15];     // 名称
    char numb[18];     // 编号
    char tele[16];     // 电话
    char gender[8];    // 性别
};

// 定义全局 学生 数组
struct Student studentList[100];
int studentCount = 0; // 学生计数

// 定义 座位 结构体
struct Seat {
    char numb[18]; // 座位编号
};

// 定义全局 座位 数组
struct Seat seatList[100];
int seatCount = 0; // 座位计数

// 定义 预约位置 结构体
struct Pre {
    char student[15]; // 学生
    char seat[15];    // 位置编号
};

// 定义全局 预约位置 数组
struct Pre preList[100];
int preCount = 0; // 预约位置计数

// 图书馆管理员相关函数声明
void readAdmin();
void writeAdmin();
void addAdmin();
void delAdmin();
int delAdminByIndex(int index);
void modAdmin();
void findAdmin(int all);
void sortAdmin();
void exchangeAdmin(int i, int j);
int getOneAdmin(const char *name, char *s);
void modAdminInfo();

// 学生相关函数声明
void readStudent();
void writeStudent();
void addStudent();
void delStudent();
int delStudentByIndex(int index);
void modStudent();
void findStudent(int all);
void sortStudent();
void exchangeStudent(int i, int j);
int getOneStudent(const char *name, char *s);
void modStudentInfo();

// 座位相关函数声明
void readSeat();
void writeSeat();
void addSeat();
void delSeat();
int delSeatByIndex(int index);
void modSeat();
void findSeat(int all);
void sortSeat();
void exchangeSeat(int i, int j);
int getOneSeat(const char *name, char *s);

// 预约位置相关函数声明
void readPre();
void writePre();
void addPre();
void delPre();
int delPreByIndex(int index);
void modPre();
void findPre(int all);
void sortPre();
void exchangePre(int i, int j);

// 菜单相关函数声明
void login();
void regist();
void menuAdmin();
void menuStudent();

// 全局变量
struct Admin loginAdmin;
struct Student loginStudent;
int loginStatus = 0; // 登录状态: 0 未登录

// 主函数
int main() {
    // 读取数据
    readAdmin();
    readStudent();
    readSeat();
    readPre();

    while (1) {
        printf("*---------------------------------------------*\n");
        printf("*------------1:登陆\n");
        printf("*------------2:注册\n");
        printf("*---------------------------------------------*\n");
        printf("请输入选择：");

        int logout = 0; // 返回上一级标志
        int select = 0;
        scanf("%d", &select);

        if (select != 2) {
            login();
        } else {
            regist();
        }

        int choice;
        if (loginStatus == 1) {
            while (logout == 0) {
                menuAdmin();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        findAdmin(0); // 查找图书馆管理员
                        break;
                    case 2:
                        sortAdmin(); // 排序图书馆管理员
                        break;
                    case 3:
                        addStudent(); // 添加学生
                        break;
                    case 4:
                        findStudent(1); // 查找学生
                        delStudent();   // 删除学生
                        break;
                    case 5:
                        findStudent(1); // 查找学生
                        modStudent();   // 修改学生
                        break;
                    case 6:
                        findStudent(0); // 查找学生
                        break;
                    case 7:
                        sortStudent(); // 排序学生
                        break;
                    case 8:
                        addSeat(); // 添加座位
                        break;
                    case 9:
                        findSeat(1); // 查找座位
                        delSeat();   // 删除座位
                        break;
                    case 10:
                        findSeat(1); // 查找座位
                        modSeat();   // 修改座位
                        break;
                    case 11:
                        findSeat(0); // 查找座位
                        break;
                    case 12:
                        sortSeat(); // 排序座位
                        break;
                    case 13:
                        addPre(); // 添加预约位置
                        break;
                    case 14:
                        findPre(1); // 查找预约位置
                        delPre();   // 删除预约位置
                        break;
                    case 15:
                        findPre(0); // 查找预约位置
                        break;
                    case 16:
                        sortPre(); // 排序预约位置
                        break;
                    case 0:
                        printf("\n\n\n\t\t\t感谢使用\n\n\n");
                        exit(0);
                    case -1:
                        printf("\n");
                        logout = 1;
                        loginStatus = 0;
                        break;
                    case -2:
                        modAdminInfo(); // 修改个人信息
                        break;
                    default:
                        getchar();
                        printf("\n\n\n\t提示:没有这个选项！请重新输入!\n\n\n\n");
                        system("pause");
                        break;
                }
            }
        }

        if (loginStatus == 2) {
            while (logout == 0) {
                menuStudent();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        findStudent(0); // 查找学生
                        break;
                    case 2:
                        sortStudent(); // 排序学生
                        break;
                    case 3:
                        findSeat(0); // 查找座位
                        break;
                    case 4:
                        sortSeat(); // 排序座位
                        break;
                    case 5:
                        addPre(); // 添加预约位置
                        break;
                    case 6:
                        findPre(1); // 查找预约位置
                        delPre();   // 删除预约位置
                        break;
                    case 7:
                        findPre(0); // 查找预约位置
                        break;
                    case 8:
                        sortPre(); // 排序预约位置
                        break;
                    case 0:
                        printf("\n\n\n\t\t\t感谢使用\n\n\n");
                        exit(0);
                    case -1:
                        printf("\n");
                        logout = 1;
                        loginStatus = 0;
                        break;
                    case -2:
                        modStudentInfo(); // 修改个人信息
                        break;
                    default:
                        getchar();
                        printf("\n\n\n\t提示:没有这个选项！请重新输入!\n\n\n\n");
                        system("pause");
                        break;
                }
            }
        }
    }

    return 0;
}
void login() {
    int i;
    while (loginStatus == 0) {
        char username[20], password[20];
        printf("请输入账号：");
        scanf("%s", username);
        printf("请输入密码：");
        scanf("%s", password);

        // 图书馆管理员登录
        if (loginStatus == 0) {
            for (i = 0; i < adminCount; i++) {
                if (strcmp(adminList[i].username, username) == 0 && strcmp(adminList[i].password, password) == 0) {
                    loginAdmin = adminList[i];
                    loginStatus = 1;
                    break;
                }
            }
        }

        // 学生登录
        if (loginStatus == 0) {
            for (i = 0; i < studentCount; i++) {
                if (strcmp(studentList[i].username, username) == 0 && strcmp(studentList[i].password, password) == 0) {
                    loginStudent = studentList[i];
                    loginStatus = 2;
                    break;
                }
            }
        }

        // 判断登录情况
        if (loginStatus == 0) {
            printf("\n用户名密码错误请重新登录!\n\n");
        } else {
            printf("\n登录成功!\n\n");
        }
    }
}

void regist() {
    int flag = 0; // 注册状态 0 失败，1 成功
    while (flag == 0) {
        printf("*---------------------------------------------*\n");
        printf("*------------0:返回 \n");
        printf("*------------1:注册图书馆管理员 \n");
        printf("*------------2:注册学生 \n");
        printf("*---------------------------------------------*\n");
        printf("请输入选择：");
        int select = 0;
        scanf("%d", &select);

        if (select == 0) {
            flag = 1; // 返回
        } else {
            char username[20], password[20];
            printf("请输入账号：");
            scanf("%s", username);
            printf("请输入密码：");
            scanf("%s", password);

            if (select == 1) { // 注册图书馆管理员
                if (getOneAdmin("username", username) >= 0) { // 根据用户名查找用户是否存在
                    printf("\n用户名已存在!\n\n");
                } else { // 不存在则成功注册并填写剩余属性
                    strcpy(adminList[adminCount].username, username);
                    strcpy(adminList[adminCount].password, password);
                    loginAdmin = adminList[adminCount];
                    adminCount++;
                    loginStatus = 1;
                    writeAdmin();
                    flag = 1;
                }
            }

            if (select == 2) { // 注册学生
                if (getOneStudent("username", username) >= 0) { // 根据用户名查找用户是否存在
                    printf("\n用户名已存在!\n\n");
                } else { // 不存在则成功注册并填写剩余属性
                    strcpy(studentList[studentCount].username, username);
                    strcpy(studentList[studentCount].password, password);
                    printf("请输入名称：");
                    scanf("%s", studentList[studentCount].name);
                    printf("请输入编号：");
                    scanf("%s", studentList[studentCount].numb);
                    printf("请输入电话：");
                    scanf("%s", studentList[studentCount].tele);
                    printf("请输入性别：");
                    scanf("%s", studentList[studentCount].gender);
                    loginStudent = studentList[studentCount];
                    studentCount++;
                    loginStatus = 2;
                    writeStudent();
                    flag = 1;
                }
            }

            if (flag == 1) {
                printf("注册成功\n\n");
            } else {
                printf("注册失败！\n\n");
            }
        }
    }
}

void modAdminInfo() {
    printf("\n====您的个人信息如下====\n");
    printf("用户名：%s\n", loginAdmin.username);
    printf("密码：%s\n", loginAdmin.password);
    printf("==========================\n");
    printf("1,修改个人信息\n");
    printf("2,返回上一级\n");
    printf("请选择：");
    int n, i;
    scanf("%d", &n);
    if (n == 1) {
        for (i = 0; i < adminCount; i++) {
            if (strcmp(adminList[i].username, loginAdmin.username) == 0) {
                printf("请输入密码：");
                scanf("%s", loginAdmin.password);
                adminList[i] = loginAdmin;
                writeAdmin();
                printf("修改成功！\n");
                break;
            }
        }
    }
}
// 图书馆管理员 是否存在判断
int getOneAdmin(const char *name, char *s) {
    int res = -1, i;
    for (i = 0; i < adminCount; i++) {
        if (strcmp(name, "username") == 0 && strcmp(s, adminList[i].username) == 0) {
            res = i;
            break;
        }
    }
    return res;
}

// 图书馆管理员 读入文件
void readAdmin() {
    FILE *fp = NULL;
    if ((fp = fopen("Admin.txt", "r")) == NULL) { // 读打开
        return;
    }
    int i = 0;
    // 从文件读取数据
    while (fscanf(fp, "%s%s", adminList[i].username, adminList[i].password) != EOF) {
        i++;
    }
    // 记录总数
    adminCount = i;
    fclose(fp);
}

// 图书馆管理员 写入文件
void writeAdmin() {
    FILE *fp = NULL;
    int i;
    fp = fopen("Admin.txt", "w+");
    for (i = 0; i < adminCount; i++) {
        fprintf(fp, "%s %s\n", adminList[i].username, adminList[i].password);
    }
    fclose(fp);
}

// 图书馆管理员 添加记录
void addAdmin() {
    char selectYNFlag = 'y';
    while (selectYNFlag == 'y' || selectYNFlag == 'Y') {
        printf("\n请输入用户名:");
        char username[15];
        scanf("%s", username);
        strcpy(adminList[adminCount].username, username);

        // 检索 Admin 不重复
        int getOneAdminusername = getOneAdmin("username", adminList[adminCount].username);
        if (getOneAdminusername >= 0) { // 检索不为空
            printf("用户名已存在！\n");
            break;
        }

        printf("请输入密码：");
        char password[15];
        scanf("%s", password);
        strcpy(adminList[adminCount].password, password);

        // adminCount 是全局变量
        adminCount++;
        printf("\n是否继续录入?(y/n)");
        getchar();
        scanf("%c", &selectYNFlag);
    }
    writeAdmin();
    printf("\n*****************************\n");
    printf("录入完成\n");
    printf("*****************************\n");
}

// 图书馆管理员 删除
void delAdmin() {
    printf("请输入您要删除的 图书馆管理员 序号(输入-1退出):");
    int index;
    scanf("%d", &index);

    if (index >= 0) {
        int res = delAdminByIndex(index);
        if (res) {
            printf("删除成功！\n\n");
            writeAdmin();
        } else {
            printf("删除失败！\n\n");
        }
    }
}

// 图书馆管理员 根据下标删除
int delAdminByIndex(int index) {
    if (index >= adminCount || index < 0) {
        return 0;
    }
    // 开始删除！
    int i;
    for (i = index; i < adminCount - 1; i++) {
        // 元素全部往前移一位。
        adminList[i] = adminList[i + 1];
    }
    // 最后令栈的长度减一
    adminCount = adminCount - 1;
    return 1;
}

// 图书馆管理员 修改
void modAdmin() {
    printf("请输入您要修改的图书馆管理员 序号(输入-1退出):");
    int indexOfMod = -1;
    scanf("%d", &indexOfMod);
    if (indexOfMod >= 0 && indexOfMod < adminCount) {
        // 开始修改
        printf("请输入密码：");
        char password[15];
        scanf("%s", password);

        // 输入完毕，赋值
        strcpy(adminList[indexOfMod].password, password);
        printf("修改成功！\n");
        writeAdmin();
    } else {
        printf("输入错误！\n");
    }
}

// 图书馆管理员 查找 如果 all=1:查询全部 否则按条件查询
void findAdmin(int all) {
    int select = 0;
    char conCharArr[40];
    while (1) {
        printf("\n%-5s%-15s%-15s\n\n", "序号", "用户名", "密码");
        if (adminCount > 0) {
            // 用于统计信息所用
            int count = 0, i;
            for (i = 0; i < adminCount; i++) {
                if (select == 0 || (select == 1 && strstr(adminList[i].username, conCharArr))) { // 根据用户名模糊查询
                    printf("%-5d%-15s%-15s\n\n", i, adminList[i].username, adminList[i].password);
                    // 用于统计信息所用
                    count++;
                }
            }
            printf("共%d条结果\n", count);
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("\n");
        } else {
            printf("\n【无记录!】\n\n");
        }
        // 如果参数 all 为 1，则表示列出所有就退出
        if (all == 1) break;
        // 进入过滤。
        printf("【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n");
        printf("0:退出\n");
        printf("1:按 用户名 筛选\n");
        printf("请输入选择：");
        scanf("%d", &select);
        if (select > 0) {
            if (select == 1) {
                printf("请输入筛选条件：");
                scanf("%s", conCharArr);
            }
        } else {
            break;
        }
    }
    readAdmin(); // 重新读取数据。
}

// 图书馆管理员 排序
void sortAdmin() {
    int select, i, j;
    printf("1:按 用户名 排序\n");
    printf("2:按 密码 排序\n");
    printf("请输入选择：");
    scanf("%d", &select);
    for (i = adminCount - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if ((select == 1 && strcmp(adminList[j].username, adminList[j + 1].username) > 0) ||
                (select == 2 && strcmp(adminList[j].password, adminList[j + 1].password) > 0)) {
                exchangeAdmin(j, j + 1);
            }
        }
    }
    findAdmin(1);
    writeAdmin();
}

// 图书馆管理员 交换
void exchangeAdmin(int i, int j) {
    struct Admin admin = adminList[i];
    adminList[i] = adminList[j];
    adminList[j] = admin;
}

void modStudentInfo (){
    printf("\n====您的个人信息如下====\n");
    printf("用户名：%s\n",loginStudent.username);
    printf("密码：%s\n",loginStudent.password);
    printf("名称：%s\n",loginStudent.name);
    printf("编号：%s\n",loginStudent.numb);
    printf("电话：%s\n",loginStudent.tele);
    printf("性别：%s\n",loginStudent.gender);
    printf("==========================\n1,修改个人信息\n2,返回上一级\n请选择:");
    int n,i;
    scanf("%d",&n);
    if (n == 1) {
        for( i = 0;i < studentCount ; i++){
            if(strcmp(studentList [i].username,loginStudent .username)==0){
                printf("请输入密码 :"); scanf("%s",loginStudent.password);
                printf("请输入名称 :"); scanf("%s",loginStudent.name);
                printf("请输入编号 :"); scanf("%s",loginStudent.numb);
                printf("请输入电话 :"); scanf("%s",loginStudent.tele);
                printf("请输入性别 :"); scanf("%s",loginStudent.gender);
                studentList [ i ] = loginStudent;
                writeStudent ();
                printf("修改成功！\n");
                break;
            }
        }
    }
}
//学生 是否存在判断
int getOneStudent (const char *name,char *s){
    int res = -1,i;
    for( i = 0;i < studentCount ;i++){
        if( strcmp(name,"username")==0 && strcmp(s, studentList [i]. username )==0){
            res = i;
            break;
        }
        if( strcmp(name,"name")==0 && strcmp(s, studentList [i]. name )==0){
            res = i;
            break;
        }
        if( strcmp(name,"numb")==0 && strcmp(s, studentList [i]. numb )==0){
            res = i;
            break;
        }
                                                    
    }
    return res;
}
//学生 读入文件
void readStudent (){
    FILE *fp = NULL;
    if (NULL == (fp = fopen("Student.txt", "r")))//读打开
    {
        return;
    }
    int i=0;
    //从文件读取数据
    while (fscanf(fp, "%s%s%s%s%s%s",studentList[i].username  ,studentList[i].password  ,studentList[i].name  ,studentList[i].numb  ,studentList[i].tele  ,studentList[i].gender) != EOF)//读取
    {
        i++;
    }
    //记录总数
    studentCount = i;
    fclose(fp);
}
//学生 写入文件
void writeStudent (){
    FILE *fp = NULL;
    int i;
    fp = fopen("Student.txt", "w+");
    for( i = 0;i< studentCount ;i++){
        fprintf(fp,"%s %s %s %s %s %s\n",studentList[i].username  ,studentList[i].password  ,studentList[i].name  ,studentList[i].numb  ,studentList[i].tele  ,studentList[i].gender);
    }
    fclose(fp);
}
    //学生 添加记录
void addStudent (){
	char selectYNFlag = 'y';
	while(selectYNFlag == 'y' || selectYNFlag == 'Y' ){
        printf("\n");
        printf("请输入用户名 :");
        char username[15];
        scanf("%s",username);
        strcpy(studentList [ studentCount ] . username,username);
//检索Student 不重复
        int getOneStudentusername = getOneStudent ("username",studentList [ studentCount ] . username);
        if( getOneStudentusername >=0){
            //检索不为空
            printf("用户名已存在！\n");
            break;
		}
        printf("请输入密码 :");
        char password[15];
        scanf("%s",password);
        strcpy(studentList [ studentCount ] . password,password);
        printf("请输入名称 :");
        char name[15];
        scanf("%s",name);
        strcpy(studentList [ studentCount ] . name,name);
        //检索Student 不重复
        int getOneStudentname = getOneStudent ("name",studentList [ studentCount ] . name);
        if( getOneStudentname >=0){
            //检索不为空
			printf("名称已存在！\n");
            break;
		}
        printf("请输入编号 :");
        char numb[18];
        scanf("%s",numb);
        strcpy(studentList [ studentCount ] . numb,numb);
		//检索Student 不重复
		int getOneStudentnumb = getOneStudent ("numb",studentList [ studentCount ] . numb);
		if( getOneStudentnumb >=0){//检索不为空
			printf("编号已存在！\n");
            break;
		}
        printf("请输入电话 :");
        char tele[16];
        scanf("%s",tele);
        strcpy(studentList [ studentCount ] . tele,tele);
        printf("请输入性别 :");
        char gender[8];
        scanf("%s",gender);
        strcpy(studentList [ studentCount ] . gender,gender);
		//studentCount 是全局变量
		studentCount ++;
		printf("\n是否继续录入?(y/n)");
        getchar();
        scanf("%c",&selectYNFlag);
    }
	writeStudent ( );
	printf("\n*****************************\n");
    printf("录入完成\n");
    printf("*****************************\n");
}
//学生 删除
void delStudent (){
	printf("请输入您要删除的 学生 序号(输入-1退出):");
    int index;
	scanf("%d",&index);
    
	if(index >= 0){
		int res = delStudentByIndex (index);
		if(res){
            printf("删除成功！\n\n");
            writeStudent ();
		}else{
			printf("删除失败！\n\n");
        }
	}
 
}
//学生 根据下标删除
int delStudentByIndex (int index){
	if(index >= studentCount || index < 0){
		return 0;
	}
	//开始删除！
	int i;
	for(i = index; i < studentCount - 1 ; i++){
		//元素全部往前移一位。
		studentList [i] = studentList [i+1];
	}
	//最后令栈的长度减一
	studentCount = studentCount - 1;
	return 1;
}

//学生 修改
void modStudent (){
	printf("请输入您要修改的学生 序号(输入-1退出):");
    int indexOfMod = -1;
	scanf("%d",&indexOfMod);
    if(indexOfMod >= 0 && indexOfMod < studentCount ){
		//开始修改
		printf("请输入密码 :");
        char password[15];
		scanf("%s",password);
        printf("请输入名称 :");
        char name[15];
        scanf("%s",name);

        if(strcmp(studentList [indexOfMod] . name,name) != 0 && getOneStudent ("name",name)>=0){
            //检索不为空
			printf("名称 已存在！\n");
            return;
		}
        printf("请输入电话 :");
        char tele[16];
		scanf("%s",tele);
        printf("请输入性别 :");
        char gender[8];
		scanf("%s",gender);
        
        //输入完毕，赋值
		strcpy(studentList [ indexOfMod ] . password,password);
		strcpy(studentList [ indexOfMod ] . name,name);
		strcpy(studentList [ indexOfMod ] . tele,tele);
		strcpy(studentList [ indexOfMod ] . gender,gender);
		printf("修改成功！\n");
        writeStudent ();
	}else{
		printf("输入错误！\n");
    }
 
}
//学生 查找 如果all=1:查询全部 否则按条件查询
void findStudent (int all){
	int select = 0;
	char conCharArr[40];
	double conNum1,conNum2;
	while(1){
		printf("\n%-5s%-15s%-15s%-15s%-18s%-16s%-8s\n\n","序号" ,"用户名","密码","名称","编号","电话","性别" );
        if( studentCount > 0 ){
			//用于统计信息所用
			int count = 0,i;
            for (i = 0;i <  studentCount ; i++)
			{
                if(select == 0|| select == 1 && strstr(studentList [i]. username,conCharArr)//根据用户名,模糊查询
            || select == 2 && strstr(studentList [i]. name,conCharArr) //根据名称,模糊查询
            || select == 3 && strstr(studentList [i]. numb,conCharArr) //根据编号,模糊查询
            || select == 4 && strstr(studentList [i]. gender,conCharArr) //根据性别,模糊查询
                 ){
           printf("%-5d%-15s%-15s%-15s%-18s%-16s%-8s \n\n",i,studentList [i] . username
            ,studentList [i] . password,studentList [i] . name
            ,studentList [i] . numb,studentList [i] . tele
            ,studentList [i] . gender);
            //用于统计信息所用
              count++;
				}
                else{
					delStudentByIndex(i--);//删掉
				}
			}
			printf("共%d条结果\n",count);
            printf("-----------------------------------------------------------------------------------------------------\n");    																																																			            printf("\n");    		}else{
			printf("\n【无记录!】\n\n");
        }
		//如果参数all为1，则表示列出所有就退出
		if(all == 1)break;
		//进入过滤。
		printf("【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n");
        printf("0:退出\n");
        printf("1:按 用户名 筛选\n");
        printf("2:按 名称 筛选\n");printf("3:按 编号 筛选\n");
        printf("4:按 性别 筛选\n");
        printf("请输入选择：");
        scanf("%d",&select);
    	if(select>0){
			if(0  ||select==1 ||select==2 ||select==3 ||select==4 ){
                printf("请输入筛选条件：");
                scanf("%s",conCharArr);
    			}else if(0 ){
				    printf("请输入筛选范围m,n,用空格隔开(m ≤X ≤n):");
                    scanf("%lf",&conNum1);
                    scanf("%lf",&conNum2);
    			}
		}else{
			break;
		}
	}
	readStudent();//从新读取数据。
}

//学生 排序
void sortStudent (){
	int select,i,j;
	printf("1:按 用户名 排序\n");
    printf("2:按 密码 排序\n");
    printf("3:按 名称 排序\n");
    printf("4:按 编号 排序\n");
    printf("5:按 电话 排序\n");
    printf("6:按 性别 排序\n");
    printf("请输入选择：");
    scanf("%d",&select);
    for( i = studentCount -1;i>0;i--){
		for( j = 0;j < i;j++){
			if(	0|| select == 1 && strcmp(studentList [j]. username , studentList [j+1]. username)>0
					|| select == 2 && strcmp(studentList [j]. password , studentList [j+1]. password)>0
					|| select == 3 && strcmp(studentList [j]. name , studentList [j+1]. name)>0
					|| select == 4 && strcmp(studentList [j]. numb , studentList [j+1]. numb)>0
					|| select == 5 && strcmp(studentList [j]. tele , studentList [j+1]. tele)>0
					| select == 6 && strcmp(studentList [j]. gender , studentList [j+1]. gender)>0){
				exchangeStudent (j,j+1);
			}
		}
	}
	findStudent (1);
	writeStudent ();
}
//学生 交换
void exchangeStudent (int i,int j){
	struct Student student = studentList [i];
	studentList [i] = studentList  [j];
	studentList [j] = student ;
}
//座位 是否存在判断
int getOneSeat (const char *name,char *s){
	int res = -1,i;
	for( i = 0;i < seatCount ;i++){
		if( strcmp(name,"numb")==0 && strcmp(s, seatList [i]. numb )==0){
			res = i;
			break;
		}
	}
	return res;
}
//座位 读入文件
void readSeat (){
	FILE *fp = NULL;
	if (NULL == (fp = fopen("Seat.txt", "r")))//读打开
	{
		return;
	}
	int i=0;
	//从文件读取数据
	while (fscanf(fp, "%s",seatList[i].numb ) != EOF)//读取
	{
		i++;
	}
	//记录总数
	seatCount = i;
	fclose(fp);
}
	//座位 写入文件
void writeSeat (){
	FILE *fp = NULL;
	int i;
	fp = fopen("Seat.txt", "w+");
	for( i = 0;i< seatCount ;i++){
		fprintf(fp,"%s\n",seatList[i].numb );
	}
	fclose(fp);
}
	//座位 添加记录
void addSeat (){
	char selectYNFlag = 'y';
	while(selectYNFlag == 'y' || selectYNFlag == 'Y' ){
	    printf("\n");
        printf("请输入座位编号 :");
        char numb[18];
        scanf("%s",numb);
        strcpy(seatList [ seatCount ] . numb,numb);
		//检索Seat 不重复
		int getOneSeatnumb = getOneSeat ("numb",seatList [ seatCount ] . numb);
		if( getOneSeatnumb >=0){//检索不为空
			printf("座位编号已存在！\n");
            break;
		}
		//seatCount 是全局变量
		seatCount ++;
		printf("\n是否继续录入?(y/n)");
        getchar();
		scanf("%c",&selectYNFlag);
    }
	writeSeat ( );
    printf("\n*****************************\n");
    printf("录入完成\n");
    printf("*****************************\n");
}
//座位 删除
void delSeat (){
	printf("请输入您要删除的 座位 序号(输入-1退出):");
    int index;
	scanf("%d",&index);
    
	if(index >= 0){
		int res = delSeatByIndex (index);
		if(res){
            printf("删除成功！\n\n");
            writeSeat ();
		}else{
            printf("删除失败！\n\n");
        }
	}
 
}
//座位 根据下标删除
int delSeatByIndex (int index){
	if(index >= seatCount || index < 0){
		return 0;
	}
	//开始删除！
	int i;
	for(i = index; i < seatCount - 1 ; i++){
		//元素全部往前移一位。
		seatList [i] = seatList [i+1];
	}
	//最后令栈的长度减一
	seatCount = seatCount - 1;
	return 1;
}

//座位 修改
void modSeat (){
    printf("请输入您要修改的座位 序号(输入-1退出):");
    int indexOfMod = -1;
	scanf("%d",&indexOfMod);
    if(indexOfMod >= 0 && indexOfMod < seatCount ){
		//开始修改
		//输入完毕，赋值
		printf("修改成功！\n");
        writeSeat ();
	}else{
        printf("输入错误！\n");
    }
 
}
//座位 查找 如果all=1:查询全部 否则按条件查询
void findSeat (int all){
	int select = 0;
	char conCharArr[40];
	double conNum1,conNum2;
	while(1){
		printf("\n%-5s%-18s\n\n","序号" ,"座位编号" );
        if( seatCount > 0 ){
			//用于统计信息所用
			int count = 0,i;
			for (i = 0;i <  seatCount ; i++)
			{
                //根据座位编号,模糊查询
				if(select == 0|| select == 1 && strstr(seatList [i]. numb,conCharArr)){
                    printf("%-5d%-18s \n\n",i,seatList [i] . numb);
					//用于统计信息所用
					count++;
				}else{
					delSeatByIndex(i--);//删掉
				}
			}
			printf("共%d条结果\n",count);
            printf("-----------------------------------------------------------------------------------------------------\n");    																            printf("\n");    		}else{
			 printf("\n【无记录!】\n\n");
        }
		//如果参数all为1，则表示列出所有就退出
		if(all == 1)break;
		//进入过滤。
		printf("【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n");
        printf("0:退出\n");
        printf("1:按 座位编号 筛选\n");
        printf("请输入选择：");
        scanf("%d",&select);
    	if(select>0){
			if(0 || select==1 ){
				printf("请输入筛选条件：");
                scanf("%s",conCharArr);
    			}else if(0){
				    printf("请输入筛选范围m,n,用空格隔开(m ≤X ≤n):");
                    scanf("%lf",&conNum1);
                    scanf("%lf",&conNum2);
    			}
		}else{
			break;
		}
	}
	readSeat();//从新读取数据。
}
//座位 排序
void sortSeat (){
	int select,i,j;
	printf("1:按 座位编号 排序\n");
    printf("请输入选择：");
    scanf("%d",&select);
    for( i = seatCount -1;i>0;i--){
		for( j = 0;j < i;j++){
			if(	0|| select == 1 && strcmp(seatList [j]. numb , seatList [j+1]. numb)>0){
				exchangeSeat (j,j+1);
			}
		}
	}
	findSeat (1);
	writeSeat ();
}

//座位 交换
void exchangeSeat (int i,int j){
	struct Seat seat = seatList [i];
	seatList [i] = seatList  [j];
	seatList [j] = seat ;
}
//预约位置 读入文件
void readPre (){
	FILE *fp = NULL;
	if (NULL == (fp = fopen("Pre.txt", "r")))//读打开
	{
		return;
	}
	int i=0;
	//从文件读取数据
	while (fscanf(fp, "%s%s",preList[i].student  ,preList[i].seat) != EOF)//读取
	{
		i++;
	}
	//记录总数
	preCount = i;
	fclose(fp);
}
//预约位置 写入文件
void writePre (){
	FILE *fp = NULL;
	int i;
	fp = fopen("Pre.txt", "w+");
	for( i = 0;i< preCount ;i++){
		fprintf(fp,"%s %s\n",preList[i].student  ,preList[i].seat);
	}
	fclose(fp);
}
//预约位置 添加记录
void addPre (){
	char selectYNFlag = 'y';
	while(selectYNFlag == 'y' || selectYNFlag == 'Y' ){
	    printf("\n");
        if(loginStatus==2){
			strcpy(preList [ preCount ] . student,loginStudent .name);
		}else{
			printf("请输入学生 :");
            char student[15];
            scanf("%s",student);
    		strcpy(preList [ preCount ] . student,student);
			//检索Pre 是否存在
			int getOneStudentFrn =getOneStudent ("name",preList [ preCount ] . student);
			if(getOneStudentFrn ==-1){//检索不为空
				printf("学生不存在！\n");
                break;
			}
		}
        printf("请输入位置编号 :");
        char seat[15];
        scanf("%s",seat);
        strcpy(preList [ preCount ] . seat,seat);
		//检索Pre 是否存在
		int getOneSeatFrn =getOneSeat ("numb",preList [ preCount ] . seat);
		if(getOneSeatFrn ==-1){//检索不为空
			printf("位置编号不存在！\n");
            break;
		}
		//preCount 是全局变量
		preCount ++;
		printf("\n是否继续录入?(y/n)");
        getchar();
		scanf("%c",&selectYNFlag);
    	}
	writePre ( );
	printf("\n*****************************\n");
    printf("录入完成\n");
    printf("*****************************\n");
}
                
//预约位置 删除
void delPre (){
	printf("请输入您要删除的 预约位置 序号(输入-1退出):");
    int index;
	scanf("%d",&index);
    
	if(index >= 0){
		int res = delPreByIndex (index);
		if(res){
			printf("删除成功！\n\n");
            writePre ();
		}else{
			printf("删除失败！\n\n");
        }
	}
 
}
//预约位置 根据下标删除
int delPreByIndex (int index){
	if(index >= preCount || index < 0){
		return 0;
	}
	//开始删除！
	int i;
	for(i = index; i < preCount - 1 ; i++){
		//元素全部往前移一位。
		preList [i] = preList [i+1];
	}
	//最后令栈的长度减一
	preCount = preCount - 1;
	return 1;
}
//预约位置 修改
void modPre (){
	printf("请输入您要修改的预约位置 序号(输入-1退出):");
    int indexOfMod = -1;
	scanf("%d",&indexOfMod);
    if(indexOfMod >= 0 && indexOfMod < preCount ){
        //开始修改
        if(loginStatus==2){
            strcpy(preList [ indexOfMod ] . student, loginStudent.name);
        } else {
            printf("请输入学生 :");
            char student[15];
            scanf("%s", student);

            if(getOneStudent("name", student) == -1) { // 检索不为空
                printf("学生 不存在！\n");
                return;
            }
            printf("请输入位置编号 :");
            char seat[15];
            scanf("%s", seat);

            if(getOneSeat("numb", seat) == -1) { // 检索不为空
                printf("位置编号 不存在！\n");
                return;
            }
            // 输入完毕，赋值
            strcpy(preList [ indexOfMod ] . seat, seat);
            printf("修改成功！\n");
            writePre();
        }
    }else{
        printf("输入错误！");
    }
}
//预约位置 查找 如果all=1:查询全部 否则按条件查询
void findPre (int all){
	int select = 0;
	char conCharArr[40];
	double conNum1,conNum2;
	while(1){
		printf("\n%-5s%-15s%-15s\n\n","序号" ,"学生","位置编号" );
        if( preCount > 0 ){
			//用于统计信息所用
			int count = 0,i;
			for (i = 0;i <  preCount ; i++)
			{
				if(select==0|| select == 1 && strstr(preList [i]. student,conCharArr) //根据学生,模糊查询
							|| select == 2 && strstr(preList [i]. seat,conCharArr) //根据位置编号,模糊查询
					){
					if(0//学生 只能查看和自己相关的预约位置
						|| loginStatus == 2 && strcmp(preList [i] . student,loginStudent . name)!=0
						){
						delPreByIndex(i--);//删掉
						continue;
					}
					printf("%-5d%-15s%-15s \n\n",i,preList [i] . student,preList [i] . seat);
					//用于统计信息所用
					count++;
				}else{
					delPreByIndex(i--);//删掉
				}
			}
			printf("共%d条结果\n",count);
            printf("-----------------------------------------------------------------------------------------------------\n");    																							            printf("\n");    		}else{
			printf("\n【无记录!】\n\n");    		}
		    //如果参数all为1，则表示列出所有就退出
		    if(all == 1)break;
		    //进入过滤。
		    printf("【筛选器：你可以在以上结果的基础上，进行以下条件筛选】\n");
            printf("0:退出\n");
            printf("1:按 学生 筛选\n");
            printf("2:按 位置编号 筛选\n");
            printf("请输入选择：");
            scanf("%d",&select);
    		if(select>0){
			if(0||select==1 ||select==2 ){
				printf("请输入筛选条件：");
                scanf("%s",conCharArr);
    		}else if(0){
				printf("请输入筛选范围m,n,用空格隔开(m ≤X ≤n):");
                scanf("%lf",&conNum1);
                scanf("%lf",&conNum2);
    		}
		}else{
			break;
		}
	}
	readPre();//从新读取数据。
}

//预约位置 排序
void sortPre (){
	int select,i,j;
	printf("1:按 学生 排序\n");
    printf("2:按 位置编号 排序\n");
    printf("请输入选择：");
    scanf("%d",&select);
    for( i = preCount -1;i>0;i--){
		for( j = 0;j < i;j++){
			if(0||select == 1 && strcmp(preList [j]. student , preList [j+1]. student)>0
				|| select == 2 && strcmp(preList [j]. seat , preList [j+1]. seat)>0){
                    exchangePre (j,j+1);
			}
		}
	}
	findPre (1);
	writePre ();
}

//预约位置 交换
void exchangePre (int i,int j){
	struct Pre pre = preList [i];
	preList [i] = preList  [j];
	preList [j] = pre ;
}

void menuAdmin (){
    //菜单
    printf("*------------------主菜单---------------------*\n");   
    printf("*-------------1 :查找图书管管理员\n");   
    printf("*-------------2 :排序图书管管理员\n");
    printf("*-------------3 :添加学生\n"); 
    printf("*-------------4 :删除学生\n");
    printf("*-------------5 :修改学生\n");
    printf("*-------------6 :查找学生\n");
    printf("*-------------7 :排序学生\n");
    printf("*-------------8 :添加座位\n");
    printf("*-------------9 :删除座位\n");
    printf("*-------------10 :修改座位\n");
    printf("*-------------11 :查找座位\n");
    printf("*-------------12 :排序座位\n");
    printf("*-------------13 :添加预约位置\n");
    printf("*-------------14 :删除预约位置\n");
    printf("*-------------15 :查找预约位置\n");
    printf("*-------------16 :排序预约位置\n");
    printf("*-------------0:退出\n");
    printf("*------------(-1):登出\n");
    printf("*------------(-2):我的\n");
    printf("*---------------------------------------------*\n");
    printf("请输入选择：");                          
}

void menuStudent (){
    printf("*------------------主菜单---------------------*\n");
    printf("*-------------1 :查找学生\n");
    printf("*-------------2 :排序学生\n");
    printf("*-------------3 :查找座位\n");
    printf("*-------------4 :排序座位\n");
    printf("*-------------5 :添加预约位置\n");
    printf("*-------------6 :删除预约位置\n");
    printf("*-------------7 :查找预约位置\n");
    printf("*-------------8 :排序预约位置\n");
    printf("*-------------0:退出\n");
    printf("*------------(-1):登出\n");
    printf("*------------(-2):我的\n");
     printf("*---------------------------------------------*\n");
     printf("请输入选择：");
}
