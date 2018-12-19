#pragma once
#include "basicinfo.h"

//回答类
class answ_info : public basic_info {

	//构造函数和虚构函数
public:
	answ_info() = default;
	answ_info(const std::string &pa_creatorid, const std::string pa_content, std::string pa_creatorname, std::string pa_belong) :
		basic_info(pa_creatorid, pa_content, pa_creatorname), praisednum(0), qusbelong(pa_belong) {}
	answ_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t &pa_createtime, const std::string &pa_belong, const int &pa_praised) :
		basic_info(pa_id, pa_creatorid, pa_content, pa_creatorname, pa_createtime), praisednum(pa_praised), qusbelong(pa_belong) {}
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
