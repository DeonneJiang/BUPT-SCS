#pragma once
#include "answerinfo.h"


//������
class ques_info : public basic_info {

	//���캯�����鹹����
public:
	ques_info() = default;
	ques_info(const std::string &pa_creatorid, const std::string pa_content, const std::string pa_creatorname
		, const std::string &pa_title) :
		basic_info(pa_creatorid, pa_content, pa_creatorname), title(pa_title) {}
	ques_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_titile, const  std::map<std::string, answ_info> &pa_answers) :
		basic_info(pa_id, pa_creatorid, pa_content, pa_creatorname, pa_createtime), title(pa_titile), answers(pa_answers) {}
	~ques_info() = default;


	//�ⲿ����
public:
	//��ӡ��������
	virtual void PrintProperty() const;
	//��Ӵ𰸲���
	bool AddAnswer(answ_info  &ans);
	//��ͬ�𰸲���
	bool PraiseAnswer(const std::string &ansid);
	//��ӡ�𰸲���
	void PrintAnswers() const;
	//ȡֵ
	std::string GetTitle() const { return title; }
	//ȡֵ
	std::map<std::string, answ_info> GetAns() const { return answers; }




	//���л����
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<basic_info>(*this);
		ar & title;
		ar & answers;
	}


	//˽�г�Ա����
private:
	std::string title;
	std::map<std::string, answ_info> answers;

};
