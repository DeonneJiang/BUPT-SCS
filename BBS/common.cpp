#include "common.h"

//���ļ���ȡ���ݺ���
bool ReadInfoFroDatabase(std::map<std::string, user> &user_Database, std::map<std::string, ques_info> &ques_Database)
{
	std::ifstream ifs1("UD");
	if (!ifs1)
	{
		throw "��UserDatabase�ļ�ʧ��";
	}
	else
	{
		boost::archive::text_iarchive ia1(ifs1);
		ia1 >> user_Database;
		ifs1.close();

		std::ifstream ifs2("QD");
		if (!ifs2)
		{
			throw "��QuestionDatabase�ļ�ʧ��";
		}
		else
		{
			boost::archive::text_iarchive ia2(ifs2);
			ia2 >> ques_Database;
			ifs2.close();
		}

	}

	return true;
}

//���ļ�д�����ݺ���
bool WriteInfoToDatabase(const std::map<std::string, user> &user_Database, const std::map<std::string, ques_info> &ques_Database)
{
	std::ofstream ofs1("UD");
	boost::archive::text_oarchive oa1(ofs1);
	oa1 << user_Database;
	ofs1.close();

	std::ofstream ofs2("QD");
	boost::archive::text_oarchive oa2(ofs2);
	oa2 << ques_Database;
	ofs2.close();

	return true;
}


//����������������
std::ostream& operator<<(std::ostream& out, const answ_info &ansinfo)
{
	time_t t = ansinfo.GetTime();
	char buf[26];
	ctime_s(buf, 26, &t);
	std::string ti(buf);
	ti.pop_back();
	out << ansinfo.GetId() << "\t" << ti << "\t" << ansinfo.GetCId() << "\t" << ansinfo.GetContent() << std::endl;
	return out;
}


//����������������
std::ostream& operator<<(std::ostream& out, const ques_info &queinfo)
{
	time_t t = queinfo.GetTime();
	char buf[26];
	ctime_s(buf, 26, &t);
	std::string ti(buf);
	ti.pop_back();
	out << queinfo.GetId() << "\t" << ti << "\t" << queinfo.GetCId() << "\t" << queinfo.GetTitle() << std::endl;
	return out;
}