#pragma once
#include "user.h"
#include <fstream>

//从文件读取数据函数
bool ReadInfoFroDatabase(std::map<std::string, user> &user_Database, std::map<std::string, ques_info> &ques_Database);


//向文件写入数据函数
bool WriteInfoToDatabase(const std::map<std::string, user> &user_Database, const std::map<std::string, ques_info> &ques_Database);


//输入输出运算符重载
std::ostream& operator<<(std::ostream& out, const answ_info &ansinfo);


//输入输出运算符重载
std::ostream& operator<<(std::ostream& out, const ques_info &queinfo);
