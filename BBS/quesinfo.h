#pragma once
#include "answerinfo.h"


//问题类
class ques_info : public basic_info {

	//构造函数和虚构函数
public:
	ques_info() = default;
	ques_info(const std::string &pa_creatorid, const std::string pa_content, const std::string pa_creatorname
		, const std::string &pa_title) :
		basic_info(pa_creatorid, pa_content, pa_creatorname), title(pa_title) {}
	ques_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_titile, const  std::map<std::string, answ_info> &pa_answers) :
		basic_info(pa_id, pa_creatorid, pa_content, pa_creatorname, pa_createtime), title(pa_titile), answers(pa_answers) {}
	~ques_info() = default;


	//外部函数
public:
	//打印特殊属性
	virtual void PrintProperty() const;
	//添加答案操作
	bool AddAnswer(answ_info  &ans);
	//赞同答案操作
	bool PraiseAnswer(const std::string &ansid);
	//打印答案操作
	void PrintAnswers() const;
	//取值
	std::string GetTitle() const { return title; }
	//取值
	std::map<std::string, answ_info> GetAns() const { return answers; }




	//序列化相关
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<basic_info>(*this);
		ar & title;
		ar & answers;
	}


	//私有成员变量
private:
	std::string title;
	std::map<std::string, answ_info> answers;

};
