#include "quesinfo.h"

//问题类函数定义
void ques_info::PrintProperty() const
{
	time_t t = createtime;
	char buf[26];
	ctime_s(buf, 26, &t);
	std::string ti(buf);
	ti.pop_back();
	std::cout << GetId() << "\t" << ti << "\t" << creatorname << "\t" << title << std::endl;
}
bool ques_info::AddAnswer(answ_info  &ans)
{
	answers.insert(std::map<std::string, answ_info>::value_type(ans.GetId(), ans));
	return true;
}
bool ques_info::PraiseAnswer(const std::string &ansid)
{
	auto iter = answers.find(ansid);
	iter->second.GetPraised();
	return true;
}

void ques_info::PrintAnswers() const
{
	for (auto v : answers)
	{
		v.second.PrintProperty();
	}
}