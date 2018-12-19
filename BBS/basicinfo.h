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
	basic_info(const std::string &pa_creatorid, const std::string &pa_content, const std::string &pa_creatorname) :
		creatorid(pa_creatorid), content(pa_content), creatorname(pa_creatorname)
	{
		time(&createtime);
		id = std::to_string(createtime) + pa_creatorid;

	}
	basic_info(const std::string &pa_id, const std::string &pa_creatorid, const std::string &pa_content
		, const std::string &pa_creatorname, const std::time_t pa_createtime) : id(pa_id), createtime(pa_createtime),
		creatorid(pa_creatorid), content(pa_content), creatorname(pa_creatorname) {}
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

