struct date {   // 定义日期结构体类型
    int year;        // 年      取值范围：正整数
    int month;       // 月      取值范围：1～12之间的整数
    int day;         // 日      取值范围：1～31之间的整数，注意不同月份的取值限制
};

typedef struct {        // 定义学生结构体类型
    char num[10];          // 学号    主码        注意：学号长度<10，学号不能重号
    char name[15];         // 姓名                注意：姓名长度<15
    char sex;              // 性别                取值范围：M--男，F--女
    struct date birthday;    // 出生日期             注意：出生日期要合理
    char phone[15];        // 电话号码            注意：电话号码长度<15
    float paysum;      // 已缴费总额                          派生属性，通过汇总计算更新
    int counts;        // 已修课程门数                         派生属性，通过汇总计算更新
    int credits;        // 已获得学分   成绩及格才能获得学分    派生属性，通过汇总计算更新
    float aver;        // 已获学分课程加权平均分               派生属性，通过汇总计算更新
} StudentTab;

typedef struct {           // 定义课程结构体类型
    char coursenum[10];     // 课程代码   主码      注意：课程代码长度<10，课程代码不能重号
    char coursename[20];    // 课程名称             注意：课程名称长度<20
    int credit;             //  课程学分             取值范围：2～6之间的整数
    int coursehour;         //  课程学时             取值范围：正整数
    char teachername[12];   // 任课教师姓名          注意：姓名长度<15
} CourseTab;

typedef struct {    // 定义成绩结构体类型       注意：“学号+课程代码”为主码，不能重号
    char num[10];          // 学号        主码/外码     注意：必须是学生表中存在的学号
    char coursenum[10];     // 课程代码    主码/外码     注意：必须是课程表中存在的课程代码
    int normalscore;         // 平时成绩                  取值范围：0～100之间的整数
    int testscore;            // 期末考试成绩      取值范围：0～100之间的整数
    int score;               // 总评成绩          取值范围：0～100之间的整数，平时占20%
} ScoreTab;

typedef struct {          //  定义学生索引结构体类型
    char num[10];          // 索引码：学号
    long offset;            // 索引码值所对应学生记录在学生文件中的位移量
} StudentIdxTab;

typedef struct {          //  定义课程索引结构体类型
    char coursenum[10];    // 索引码：课程代码
    long offset;            // 索引码值所对应课程记录在课程文件中的位移量
} CourseIdxTab;

typedef struct {          //  定义成绩索引结构体类型
    char num1[10];           // 第1索引码：学号或课程代码
    char num2[10];          // 第2索引码：课程代码或学号
    long offset;             // 索引码值所对应成绩记录在成绩文件中的位移量
} ScoreIdxTab;


// 声明函数原型
void InitFile(void);
void InputData(void);
void ModiFile(void);
void FindRec(void);
void TabShow(void);
void StatRepo(void);
void AutoComp(void);
void Sort(void);
void BuildIdx(void);
