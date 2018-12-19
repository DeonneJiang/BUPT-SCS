#include "user.h"

bool user::AskQues(const std::string &title, const std::string &content, std::map<std::string, ques_info> &info_database)
{
	ques_info ques(id, content, name, title);
	info_database.insert(std::map<std::string, ques_info>::value_type(ques.GetId(), ques));
	asklist.push_back(ques.GetId());
	return true;
}

bool user::Answer(const std::string &content, ques_info ques)
{
	answ_info answ(id, content, name, ques.GetId());
	ques.AddAnswer(answ);
	anslist.push_back(answ.GetId());
	return true;
}

bool user::Praise(ques_info &ques, const std::string &asnid)
{
	ques.PraiseAnswer(asnid);
	pralist.push_back(asnid);
	return true;
}

bool user::LogIn(const std::string &pass)
{
	if (pass == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string user::GetUserName() const
{
	return name;
}

void user::PrintFoUsList()
{
	for (auto value : focususerlist)
	{
		std::cout << value << std::endl;
	}
}

bool user::AddFoUs(const std::string &fid)
{
	focususerlist.push_back(fid);
	return true;
}

void user:: Search(const std::string &questitle, const std::map<std::string, ques_info> &info_database, std::vector<ques_info> &queslist)
{

	for (auto iter = info_database.begin(); iter != info_database.end(); iter++)
	{
		if ((iter->second.GetTitle()).find(questitle, 0) != std::string::npos)
		{
			queslist.push_back((iter->second));
		}
	}

}

void user::Search(time_t starttime, time_t endtime, const std::map<std::string, ques_info> &info_database, std::vector<ques_info> &queslist)
{
	for (auto iter = info_database.begin(); iter != info_database.end(); iter++)
	{
		if (starttime <= iter->second.GetTime() && iter->second.GetTime() <= endtime)
		{
			queslist.push_back((iter->second));
		}
	}
}

void user::SearchUserDetail(const std::string &suid, std::vector<ques_info> &queslist, std::vector<answ_info> &answlist, const std::map<std::string, ques_info> &info_database)
{
	for (auto iter = info_database.begin(); iter != info_database.end(); iter++)
	{
		if ( iter->second.GetCId() == suid )
		{
			queslist.push_back((iter->second));
		}

		std::map<std::string, answ_info> ansdata = iter->second.GetAns();
		for (auto iter1 = ansdata.begin(); iter1 != ansdata.end(); iter1++)
		{
			if (iter1->second.GetCId() == suid)
			{
				answlist.push_back(iter1->second);
			}
		}


	}
}