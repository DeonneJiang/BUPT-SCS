#include "answerinfo.h"

//回答类函数定义
bool answ_info::GetPraised()
{
	praisednum++;
	return true;
}

void answ_info::PrintProperty() const
{
	time_t t = createtime;
	char buf[26];
	ctime_s(buf, 26, &t);
	std::string ti(buf);
	ti.pop_back();
	std::cout << GetId() << "\t" << ti << "\t" << creatorname << "\t" << praisednum << "\t" << GetContent() << std::endl;
}