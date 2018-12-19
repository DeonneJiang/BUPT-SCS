#pragma once
#include "user.h"
#include <fstream>

//���ļ���ȡ���ݺ���
bool ReadInfoFroDatabase(std::map<std::string, user> &user_Database, std::map<std::string, ques_info> &ques_Database);


//���ļ�д�����ݺ���
bool WriteInfoToDatabase(const std::map<std::string, user> &user_Database, const std::map<std::string, ques_info> &ques_Database);


//����������������
std::ostream& operator<<(std::ostream& out, const answ_info &ansinfo);


//����������������
std::ostream& operator<<(std::ostream& out, const ques_info &queinfo);
