#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <map>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/map.hpp>

//��Ϣ����
class basic_info {

	/*���캯�����鹹����*/
public:
	basic_info() = default;
	basic_info(const std::string &pa_creatorid, const std::string &pa_content,const std::string &pa_creatorname) :
		 creatorid(pa_creatorid), content(pa_content), creatorname(pa_creatorname)
	{
		time(&createtime);
		id =  std::to_string(createtime)+ pa_creatorid;

	}
	basic_info(const std::string &pa_id,const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname ,const std::time_t pa_createtime) : id(pa_id), createtime(pa_createtime),
		creatorid(pa_creatorid), content(pa_content), creatorname(pa_creatorname){}
	virtual ~basic_info() = default;


	/*�ⲿ����*/
public:
	//��ӡ���Ի����ݵĴ��麯��
	virtual void PrintProperty()const = 0;
	//��ӡ����
	std::string GetContent() const { return content; }
	//��info�л�ȡ����id
	std::string GetId() const { return id; }
	//ȡֵ
	time_t GetTime() const { return createtime; }
	//ȡֵ
	std::string GetCId() const { return creatorid; }


	/*���л����*/
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & id;
		ar & creatorid;
		ar & content;
		ar & creatorname;
		ar & createtime;
	}


	/*˽�����ݳ�Ա*/
private:
	std::string id;
	std::string creatorid;
	std::string content;


	/*�������ݳ�Ա��Ϊ���������PrintProperty�����ܷ���*/
protected:
	std::string creatorname;
	std::time_t createtime;

};









//�ش���
class answ_info : public basic_info {

	//���캯�����鹹����
public:
	answ_info() = default;
	answ_info(const std::string &pa_creatorid, const std::string pa_content, std::string pa_creatorname, std::string pa_belong) :
		basic_info(pa_creatorid, pa_content, pa_creatorname), praisednum(0), qusbelong(pa_belong) {}
	answ_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_belong, const int &pa_praised) :
		basic_info(pa_id,pa_creatorid, pa_content, pa_creatorname, pa_createtime), praisednum(pa_praised), qusbelong(pa_belong) {}
	~answ_info() = default;


	//�ⲿ����
public:
	//��ӡ�������Ե��麯��
	virtual void PrintProperty() const;
	//�ش�������һ
	bool GetPraised();
	//ȡ��ֵ
	int repra() { return praisednum; }
	


	//���л����
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<basic_info>(*this); //
		ar & praisednum;
		ar & qusbelong;
	}


	//˽�г�Ա����
private:
	int praisednum;
	std::string qusbelong;

};





//������
class ques_info : public basic_info {

	//���캯�����鹹����
public:
	ques_info() = default;
	ques_info( const std::string &pa_creatorid,const std::string pa_content, const std::string pa_creatorname
		, const std::string &pa_title) :
		basic_info(pa_creatorid,  pa_content, pa_creatorname), title(pa_title) {}
	ques_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_titile,const  std::map<std::string, answ_info> &pa_answers) :
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
	std::string GetTitle() const { return title;}
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



