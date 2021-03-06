#pragma once
#include <string>
#include <ctime>
#include <iostream>
#include <map>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/map.hpp>

//信息基类
class basic_info {

	/*构造函数和虚构函数*/
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


	/*外部函数*/
public:
	//打印个性化数据的纯虚函数
	virtual void PrintProperty()const = 0;
	//打印内容
	std::string GetContent() const { return content; }
	//从info中获取数据id
	std::string GetId() const { return id; }
	//取值
	time_t GetTime() const { return createtime; }
	//取值
	std::string GetCId() const { return creatorid; }


	/*序列化相关*/
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


	/*私有数据成员*/
private:
	std::string id;
	std::string creatorid;
	std::string content;


	/*保护数据成员，为了让子类的PrintProperty函数能访问*/
protected:
	std::string creatorname;
	std::time_t createtime;

};









//回答类
class answ_info : public basic_info {

	//构造函数和虚构函数
public:
	answ_info() = default;
	answ_info(const std::string &pa_creatorid, const std::string pa_content, std::string pa_creatorname, std::string pa_belong) :
		basic_info(pa_creatorid, pa_content, pa_creatorname), praisednum(0), qusbelong(pa_belong) {}
	answ_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_belong, const int &pa_praised) :
		basic_info(pa_id,pa_creatorid, pa_content, pa_creatorname, pa_createtime), praisednum(pa_praised), qusbelong(pa_belong) {}
	~answ_info() = default;


	//外部函数
public:
	//打印特殊属性的虚函数
	virtual void PrintProperty() const;
	//回答被赞数加一
	bool GetPraised();
	//取得值
	int repra() { return praisednum; }
	


	//序列化相关
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<basic_info>(*this); //
		ar & praisednum;
		ar & qusbelong;
	}


	//私有成员变量
private:
	int praisednum;
	std::string qusbelong;

};





//问题类
class ques_info : public basic_info {

	//构造函数和虚构函数
public:
	ques_info() = default;
	ques_info( const std::string &pa_creatorid,const std::string pa_content, const std::string pa_creatorname
		, const std::string &pa_title) :
		basic_info(pa_creatorid,  pa_content, pa_creatorname), title(pa_title) {}
	ques_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_titile,const  std::map<std::string, answ_info> &pa_answers) :
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
	std::string GetTitle() const { return title;}
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



